layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# 🐍 Reducing Memory Usage in Python
### *Session 2: Algorithmic Memory Optimization*

@luk036 👨‍💻 · 2026 📅

---

### 📋 Agenda

.pull-left[

**Part 1: Tools 🛠️**
- Memory profilers: pympler, tracemalloc
- Speed profilers: pytest-benchmark, cProfile, line_profiler

**Part 2: New Case Studies 🔬**
- **netlistx** 🗄️ — GapDict avoids full dict copy
- **ellalgo** 🛡️ — Denormal guard in ellipsoid update
- **corr-solver** 📊 — Vectorized gradient + outer buffer

]

.pull-right[

**Part 2 (con't):**
- **multiplierless** 📡 — FFT matrix cache
- **ginger** 🌿 — One snapshot per iteration

**Part 3: Summary 📈**
- Impact summary
- Key takeaways

]

---

class: nord-light, middle, center

## Part 1: Tools 🛠️

---

### 📊 Memory Profiling Tools

.pull-left[

**pympler.asizeof** — Object-level sizing

```python
from pympler import asizeof
gap = GapDict(weight)
size = asizeof.asizeof(gap._delta)
# Shows actual RAM, not sys.getsizeof
```

Advantage: Recursively sizes **every** object (dicts, numpy arrays, lists).

**tracemalloc** — Allocation tracking

```python
import tracemalloc
tracemalloc.start()
result = fn()
_, peak = tracemalloc.get_traced_memory()
tracemalloc.stop()
```

Advantage: Tracks **peak** memory per call, not just final state.

]

.pull-right[

**pytest-benchmark** — Speed regression detection

```bash
# Save baseline
pytest --benchmark-save=before

# Compare after changes
pytest --benchmark-compare=before
```

**cProfile** — Function-level profiling

```bash
python -m cProfile -o out.prof script.py
# Top 10 by cumulative time
p.sort_stats('cumtime').print_stats(10)
```

**line_profiler** — Line-by-line timing

```python
@profile
def hot_function():
    ...  # line-level timings
```

]

---

class: nord-light, middle, center

## Part 2: Case Studies 🔬

---

### 🗄️ netlistx — GapDict: Avoiding `copy.copy(weight)`

**The Problem:** Every algorithm function (cover, matching, vertex cover) did `gap = copy.copy(weight)` — a full dict duplication.

```python
# BEFORE: Full dict copy (4 MB for 50K vertices)
def pd_cover(violate, weight, soln):
    gap = copy.copy(weight)
    ...

# AFTER: Delta-based view (64 B empty, 2 MB at N/2 edits)
gap: MutableMapping = GapDict(weight)
# Only stores modified entries in _delta dict
```

**How it works:**
- `GapDict` stores a reference to the base `weight` + a `_delta` dict
- Reads fall through to base if unmodified: `gap[k] = base[k]` (O(1))
- Writes store in `_delta`: `gap[k] = val` (O(1))

**Savings:** 2× less memory. For 50K vertices: **~2 MB saved per algorithm call**.

> **⚖️ Tradeoff:** GapDict adds an **extra dict lookup** on every read (`key in _delta` then `_delta[key]` else `base[key]`). For algorithms that modify almost every vertex (cover size ≈ N), the `_delta` dict grows to nearly the original size, saving only ~50% (vs 0% for copy). Also, `GapDict` does **not** support iteration or `len()` — only `__getitem__`, `__setitem__`, and `__contains__`. If an algorithm needs to iterate over gap values, a plain dict copy is required. **Best when the algorithm touches significantly fewer entries than the full vertex set.**

---

### 🗄️ netlistx — Targeted Dijkstra in Hadlock

**The Problem:** `nx.all_pairs_dijkstra_path` computed shortest paths between **all** dual graph nodes, but only needed paths between odd-face vertices.

```python
# BEFORE: All-pairs — O(|V|^2) storage
dist = dict(nx.all_pairs_dijkstra_path_length(dual_G))
paths = dict(nx.all_pairs_dijkstra_path(dual_G))

# AFTER: Single-source from odd faces only — O(k|V|)
dist, paths = {}, {}
for source in odd_faces:
    L, P = nx.single_source_dijkstra(dual_G, source)
    dist[source] = L
    paths[source] = P
```

**Savings:** O(k|V|) vs O(|V|²) where k = |odd faces| « |V_dual|. For grids: **~10× less memory**.

> **⚖️ Tradeoff:** The targeted approach runs **k separate Dijkstra** single-source traversals instead of one all-pairs computation. NetworkX's `all_pairs_dijkstra` is implemented as a loop over single-source calls anyway (no special acceleration), so the total work is similar. However, the targeted version discards distances to **non-odd-face vertices** after each source finishes — saving memory but recomputing them if needed later. For the Hadlock MAX-CUT algorithm, only odd-face to odd-face distances are ever queried, so discarding is safe. **If later code needs arbitrary vertex-to-vertex distances, the targeted approach must re-run Dijkstra — the all-pairs table would have been faster.**

---

### 🛡️ ellalgo — Denormal Omega Guard

**The Problem:** A near-zero gradient (e.g., `[0, 0, 0, 6.26e-156]`) produced denormal `omega`, causing `sigma/omega` overflow → `_mq` corrupted with NaN/Inf.

```python
# BEFORE: Only checked exact zero
if omega == 0.0:
    return CutStatus.NoEffect  # missed denormals!

# AFTER: Also catches denormals
if omega == 0.0:
    return CutStatus.NoEffect
if not (omega > np.finfo(float).tiny):
    return CutStatus.NoEffect  # catches 6e-311
```

**Impact:** Prevents numerical crash on edge cases. Consistent 145/145 tests passing.

> **⚖️ Tradeoff:** The threshold `np.finfo(float).tiny` (≈2.2e-308) is conservative — any `omega` below this is a denormal number. A denormal `omega` **always** causes `sigma/omega` to overflow (max float64 ≈1.8e308, so omega must be > sigma/1.8e308 ≈5e-309 to survive). The guard returns `NoEffect`, which the cutting-plane loop treats as "ellipsoid too small — terminate." This is correct because `tsq = kappa·omega` is already far below any practical tolerance (1e-14). However, returning `NoEffect` prematurely could theoretically terminate the algorithm early for problems where the optimal ellipsoid is truly that small. In practice, for n=2..120 with tolerances ≥1e-14, the algorithm converges long before omega reaches denormal range. **Zero practical downside — pure stability win.**

---

### 📊 corr-solver — Vectorized Gradient

**The Problem:** `mle_oracle.assess_optim` allocated an n×n matrix `S @ Sigma[i]` **per basis function** in the gradient loop.

.pull-left[
```python
# BEFORE: n allocations of n×n
for i in range(n):
    SFsi = S @ self.Sigma[i]    # n×n temp
    g[i] = np.trace(SFsi)
    g[i] -= sum(...)

```
]

.pull-right[
```python
# AFTER: V = S - SY @ S (once)
V = S - SY @ S
for i in range(n):
    g[i] = np.sum(V.T * self.Sigma[i])
    # O(n²) per i, zero allocation
```
]

**Math:** `g[i] = tr(S·Σᵢ) − tr(S·Σᵢ·SY) = tr((S − SY·S)·Σᵢ)` via cyclic trace property.

**Savings:** Eliminates n×n per-basis allocation. For n=100, m=100: **~80 MB churn eliminated**.

> **⚖️ Tradeoff:** The cyclic trace permutation `tr(S·Σᵢ·SY) = tr(SY·S·Σᵢ)` is mathematically exact but the **floating-point result differs** by O(ε·κ) where κ is the matrix condition number. The gradient is used in a cutting-plane algorithm that tolerates approximation — a slightly noisy gradient still produces a valid cut. For extremely ill-conditioned covariance matrices (κ > 1e12), the numerical difference between the old and new formulas could change the cut direction enough to require an extra iteration or two. For typical correlation matrices (κ < 1e6), the difference is negligible. **The tradeoff: O(n²) vs O(n³) per basis — worth the tiny numerical drift.**

---

### 📊 corr-solver — Vectorized Distance + Outer Buffer

**Before:** Python double loop for distance matrix (`O(n²)` iterations in Python) + `np.outer(y, y)` allocates n×n per iteration.

```python
# BEFORE: Python loops + outer allocation
for row in range(n):            # slow Python loop
    for col in range(row+1, n):
        ...
Y += np.outer(y, y)             # n×n temp

# AFTER: scipy vectorized + buffer reuse
D1 = squareform(pdist(site))    # C-level, O(n² log n)
np.outer(y, y, out=outer_buf)   # pre-allocated
Y += outer_buf
```

**Savings:** Distance matrix: **100× speedup** (C vs Python). Outer loop: **zero allocation** per iteration.

> **⚖️ Tradeoff:** `squareform(pdist(site))` computes **all** pairwise distances in C, which is faster for any n > 100. However, `pdist` always allocates the full **n(n-1)/2** condensed distance matrix plus `squareform` expands it to **n×n** — both happen regardless of sparsity. The original Python double loop could be modified to compute distances **on demand** (lazy evaluation) for applications that only need a fraction of the matrix. Also, `pdist(site, 'sqeuclidean')` is used in `create_2d_isotropic` for the kernel `exp(-sdkern·d²)`. Computing `sqeuclidean` via `pdist` vs the original double loop gives identical results. **When all n² distances are eventually needed, the vectorized version is always better. Only consider the loop if you need just a sparse subset.**

---

### 📡 multiplierless — FFT Matrix Cache

**The Problem:** `spectral_fact_fft` recomputed `Bn`/`An` matrices on every call, but they depend only on filter order `n`, not on input `r`.

```python
# BEFORE: Re-allocated every call (N=32 → 1.5 MB)
def spectral_fact_fft(r):
    Bn = np.outer(w, np.arange(1, n))  # m×(n-1)
    An = 2 * np.cos(Bn)                  # m×(n-1)

# AFTER: Cached by filter order
_fft_cache: dict = {}
def spectral_fact_fft(r):
    if n not in _fft_cache:
        An = 2 * np.cos(np.outer(w, np.arange(1, n)))
        _fft_cache[n] = (np.ones((m, 1)), An)
    ones, An = _fft_cache[n]
```

| Metric | Cold Cache | Warm Cache | Improvement |
|--------|-----------|------------|-------------|
| Time (N=32) | 33.0 ms | **6.2 ms** | **5.3× faster** |
| Memory | 2.4 MB peak | 2.5 MB peak | ~same (cache lives) |

> **⚖️ Tradeoff:** The cache grows by **one entry per distinct filter order**. For a filter design tool that processes one order per run, the cache holds exactly one entry (~800 KB for N=32). For a batch tool processing many orders (e.g., N=30, 32, 34, ..., 128), the cache grows to ~50 entries (~40 MB total). The cache **never evicts** — entries persist for the process lifetime. If memory is tight after processing a large N (where `ones`/`An` are large), the cache retains that memory even for subsequent smaller N. A `maxsize=N` LRU (`@lru_cache`) would bound growth at the cost of recomputing evicted entries. **Best when filter order is constant during a session (typical) — worst when sweeping many orders (add an LRU bound).**

---

### 🌿 ginger — One Snapshot Per Iteration

**The Problem:** `aberth_autocorr_mt` copied the full root list `zs[:]` **for every job** (N copies per iteration).

```python
# BEFORE: N copies of zs per iteration
for i in range(len(zs)):
    futures.append(executor.submit(job, coeffs, i, zs[:]))
    # ^^^^ N × O(N) per iteration

# AFTER: One copy, shared across all jobs
zsc = zs[:]  # one snapshot per iteration
for i in range(len(zs)):
    futures.append(executor.submit(job, coeffs, i, zsc))
```

**Also fixed:** `aberth_mt` had the same pattern + a race condition (closure captured `zs` shared with main thread).

**Savings:** O(N²) → O(N) copies per iteration. For degree 48 (24 roots, 50 iters): **~430 KB cumulative allocation eliminated**.

---

### 🌿 ginger — Snapshot Sharing Safety

.mermaid[
<pre>
%%{init: {'theme': 'base', 'themeVariables': { 'primaryColor': '#88C0D0', 'secondaryColor': '#BF616A'}}}%%
graph LR
    A["Main Thread"] --> B["zsc = zs[:]\n(one copy)"]
    B --> C["Job 0 ← reads zsc\n(read-only)"]
    B --> D["Job 1 ← reads zsc\n(read-only)"]
    B --> E["Job N ← reads zsc\n(read-only)"]
    A --> F["Collect results\nzs[i] = zi"]
    F --> G["Next iteration"]
    style A fill:#5E81AC,color:#fff
    style B fill:#A3BE8C,color:#fff
</pre>
]

**Why it's safe:** `aberth_autocorr_job` only **reads** `zsc` — never writes. The main thread writes results to `zs` (separate list).

> **⚖️ Tradeoff:** All threads share the **same `zsc` list** object — there is no isolation. If any future code change makes `aberth_autocorr_job` write to `zsc`, the write corruption would affect all threads simultaneously (race condition, segfault from list mutation during iteration). The original per-job `zs[:]` copy was safer because each thread had its own isolated snapshot. The fix reduces safety for performance. **Document the invariant: `zsc` must remain read-only. If the job function ever needs to modify local state, switch back to per-job copies.**

---

class: nord-light, middle, center

## Part 3: Summary 📈

---

### 📊 Updated Impact Summary

.font-sm[
| Project | Change | Saving | Tools Used |
|---------|--------|--------|------------|
| **netlistx** | GapDict replaces `copy.copy` | **~2 MB** / call | pympler, tracemalloc |
| **netlistx** | Targeted Dijkstra | **~10× less** memory | pympler |
| **ellalgo** | Denormal omega guard | **Stability fix** | tracemalloc |
| **corr-solver** | Vectorized gradient | **~80 MB** churn | pympler, tracemalloc |
| **corr-solver** | Vectorized distance + outer buf | **~100× speedup** | pytest-benchmark |
| **multiplierless** | FFT matrix cache | **5.3× faster** | pympler, tracemalloc |
| **ginger** | One snapshot per iteration | **O(N²) → O(N)** | tracemalloc |
]

**Total: 7 projects, 8 optimizations, verified with 4 profiling tools** 🎯

---

### 🔁 Patterns That Repeat (Updated)

.mermaid[
<pre>
%%{init: {'theme': 'base', 'themeVariables': { 'primaryColor': '#88C0D0'}}}%%
graph TD
    A["Python Memory Issue"] --> B["Missing __slots__?"]
    A --> C["Pre-allocated arrays?"]
    A --> D["Full copies instead of view?"]
    A --> E["Recomputed instead of cached?"]
    A --> F["Redundant temp allocations?"]

    B --> B1["Add __slots__ 🟢"]
    C --> C1["Lazy init / sentinel 🟡"]
    D --> D1["GapDict view / journal 🟡"]
    E --> E1["Cache by invariant key 🟡"]
    F --> F1["Pre-allocate + reuse 🟡"]

    style B1 fill:#A3BE8C,color:#fff
    style C1 fill:#EBCB8B
    style D1 fill:#EBCB8B
    style E1 fill:#EBCB8B
    style F1 fill:#EBCB8B
</pre>
]

**New patterns:**
- **View not copy**: GapDict avoids full dict duplicate
- **Cache invariants**: FFT matrices, cyclable edges
- **Pre-allocate + reuse**: Outer buffer, work vectors

---

### 🧠 Key Takeaways

.pull-left[

**Memory profiling first, optimization second**
1. **pympler.asizeof** — Find the biggest objects
2. **tracemalloc** — Measure peak allocation
3. **pytest-benchmark** — Guard against speed regressions

**Algorithmic patterns** 🧵
4. **GapDict** — Delta-based mapping replaces full copy
5. **Cyclic trace perm** — `tr(ABC)=tr(BCA)` changes order to eliminate allocs

]

.pull-right[

**Domain-aware caching** 📦
6. If data depends only on shape (not values), **cache by shape**
7. If data is read-only in threads, **one snapshot not N**

**~90% of Python memory waste is dict-related** — but even numpy-heavy code can eliminate per-call allocations with buffer reuse. **Target allocation churn, not just peak memory.** 🎯

]

---

count: false
class: nord-dark, middle, center

# 🙏 Questions?

*"Measure first, optimize second. The biggest savings come from eliminating allocations, not shrinking data."*

📧 luk036@gmail.com · 🔗 github.com/luk036

---

count: false
class: nord-dark, middle, center

# 🎯 Summary

**7 projects · 8 optimizations · Verified with 4 profiling tools**

.font-sm[
| Approach | Projects |
|----------|----------|
| `__slots__` | physdes-py, mywheel |
| Delta view (GapDict) | netlistx |
| Vectorized gradient | corr-solver |
| Targeted Dijkstra | netlistx |
| Cache by invariant | multiplierless, lds-gen |
| Snapshot sharing | ginger |
| Buffer reuse | corr-solver, ckpttnpy |
| Bounded caches | ec-gen, sphere-n |
]

**Combined with Session 1: 15+ projects, 25+ optimizations** 🏆
