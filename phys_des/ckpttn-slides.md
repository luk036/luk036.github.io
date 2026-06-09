# 🔀 Hypergraph Partitioning Showdown

Comparing **ckpttn-cpp**, **hMetis**, and **KaHyPar**

@luk036 👨‍💻 · 2026 📅

---

class: middle

.right[

> "Divide and Conquer. Partition your hypergraph, partition your problems." 🧠

— Ancient Algorithmic Wisdom 📜
]

---

## 📋 Agenda

- 🎯 **Why Hypergraph Partitioning?**
- 📦 **Package Overviews & Installation**
- 🖥️ **CLI Usage Comparison**
- ⚠️ **Warning Display Behavior**
- 🧪 **Experimental Results**
- 📊 **Summary & Recommendations**

---

class: nord-light, middle, center

## 🎯 Why Hypergraph Partitioning?

---

### What is Hypergraph Partitioning? 🤔

A hypergraph $H = (V, \mathcal{E})$ where each hyperedge $e \in \mathcal{E}$ connects **two or more** vertices.

**Goal**: Partition $V$ into $k$ roughly equal parts while minimizing cut hyperedges.

$$ \min \sum_{e \in \mathcal{E}} w(e) \cdot \mathbb{1}[\text{e is cut}] $$

**Subject to**: $\forall i: \frac{\sum_{v \in V_i} m(v)}{\sum_{v \in V} m(v)} \leq \frac{1}{k} + \epsilon$

where $\epsilon$ is the **imbalance factor** ⚖️

---

### Applications 🔬

.mermaid[

<pre>
graph TD
    A[Hypergraph Partitioning] --> B[VLSI Design]
    A --> C["EDA\n (Electronic Design)"]
    A --> D[Parallel Computing]
    A --> E[Machine Learning]
    B --> B1[Circuit Partitioning]
    B --> B2[Floorplanning]
    C --> C1[FPGA Partitioning]
    D --> D1[Load Balancing]
    D --> D2[Sparse Matrix]
    E --> E1[GNN Training]
    E --> E2[Graph Clustering]

    style A fill:#f44336
    style B fill:#4caf50
    style C fill:#2196f3
    style D fill:#ff9800
    style E fill:#9c27b0
    style B1 fill:#4caf50
    style B2 fill:#4caf50
    style C1 fill:#2196f3
    style D1 fill:#ff9800
    style D2 fill:#ff9800
    style E1 fill:#9c27b0
    style E2 fill:#9c27b0
</pre>

]

---

### The Balance Constraint ⚖️

**Perfect balance**: $W_{\text{total}} / k$ per part

**Allowed imbalance**: $\epsilon$ controls the trade-off:

| $\epsilon$ | Interpretation | Strictness |
|:----------:|---------------|:----------:|
| 0.01 | 1% imbalance allowed | 🔴 Very strict |
| 0.05 | 5% imbalance allowed | 🟡 Moderate |
| 0.10 | 10% imbalance allowed | 🟢 Relaxed |
| 0.50 | 50% imbalance allowed | ⚪ Almost free |

**Key equation**: Each block weight $W_i$ must satisfy:

$$ (1 - \epsilon) \cdot \frac{W_{\text{total}}}{k} \leq W_i \leq (1 + \epsilon) \cdot \frac{W_{\text{total}}}{k} $$

---

class: nord-light, middle, center

## 📦 Package Overviews

---

### Package Comparison Table 📊

| Feature | **ckpttn-cpp** | **hMetis** | **KaHyPar** |
|:--------|:--------------:|:----------:|:-----------:|
| Language | C++20 🚀 | C (1998) 🦕 | C++17 🚀 |
| License | MIT ✅ | Research 🔬 | MIT ✅ |
| Algorithm | FM + Multi-level | FM + Multi-level | FM + Multi-level |
| k-way | ✅ Yes | ✅ Yes | ✅ Yes |
| Vertex Weights | ✅ Yes | ✅ Yes | ✅ Yes |
| Multi-threaded | ➖ Partial | ❌ No | ✅ Yes (mt) |
| Active Dev | ✅ Active | ❌ Abandoned | ✅ Active |
| Warning on Imbalance | ✅ **Yes** | ❌ No | ⚠️ Partial |

---

### Installation: ckpttn-cpp 🚀

Built from source with CMake:

```bash
# Clone & Build
git clone https://github.com/luk036/ckpttn-cpp.git
cmake -S . -B build
cmake --build build

# CLI binary at:
./build/standalone/Debug/CkPttn.exe
```

Dependencies managed via **CPM.cmake**:
- XNetwork, NetlistX, MyWheel
- Microsoft GSL, doctest, fmt, spdlog

> 👍 **Easy setup**, modern CMake, integrates with existing C++ projects

---

### Installation: hMetis 💀

hMetis **v1.5.3** (last release: **1998**!) ⏳

```bash
# Windows (ancient 32-bit binary)
# Download from: karypis.github.io/glaros/files/sw/hmetis/
hmetis-1.5.3-WIN32.zip
  ├── hmetis.exe     # Recursive bisection
  ├── khmetis.exe    # K-way partitioning
  ├── shmetis.exe    # Spectral bisection
  └── libhmetis.lib  # Static library

# Linux (32-bit, needs lib32-glibc)
curl -L "https://karypis.github.io/glaros/files/sw/hmetis/hmetis-1.5-linux.tar.gz"
```

> 👎 **Abandoned**, no 64-bit builds, requires 32-bit compat layers

---

### Installation: KaHyPar 🏆

Available via pip (Linux/macOS) or source build:

```bash
# Python package (Linux/macOS only)
pip install kahypar        # Sequential version
pip install mtkahypar      # Multi-threaded version

# Windows: Source build via MSYS2
pacman -S make mingw-w64-x86_64-cmake mingw-w64-x86_64-gcc tbb
git clone https://github.com/kahypar/mt-kahypar.git
cmake -B build --preset=default
make MtKaHyPar -j
```

Pre-built Debian packages available for Linux:
```bash
# Install deb package
dpkg -i mtkahypar_1.6.1_amd64.deb
```

> 👍 Actively maintained, Python bindings, multi-threaded, **but** no Windows wheels

---

class: nord-light, middle, center

## 🖥️ CLI Usage Comparison

---

### CLI: ckpttn-cpp 🚀

```bash
# Basic usage (positional args)
CkPttn.exe circuit.hgr 2 0.05

# With verbose output
CkPttn.exe circuit.hgr 2 0.05 --verbose

# Multi-start with threads
CkPttn.exe circuit.hgr 4 0.03 -t 8 -v

# Arguments
#   <hypergraph_file>  : Input (.hgr / .json)
#   <k>               : Number of parts (default: 2)
#   <epsilon>         : Imbalance factor (default: 0.05)
```

**Options**: `--preset`, `--objective`, `--mode`, `--seed`, `--fixed`

Supports **hMetis format**, JSON, Yosys JSON — with **vertex weights** ✅

---

### CLI: hMetis 🦕

```bash
# ALL arguments required (no defaults!)
hmetis.exe circuit.hgr <k> <UBfactor> <Nruns> <CType> <RType> <VCycle> <Reconst> <dbglvl>

# Example
hmetis.exe circuit.hgr 2 5 1 1 1 0 0 0

# Arguments (must provide all!):
#   k        : Number of parts
#   UBfactor : Imbalance (5 = 5%)
#   Nruns    : Iterations
#   CType    : 1=HFC, 2=FC, 3=GFC, 4=HEDGE, 5=EDGE
#   RType    : 1=FM, 2=1WayFM, 3=EEFM
#   VCycle   : 0=No, 1=@End, 2=ForMin, 3=All
#   Reconst  : 0 or 1
#   dbglvl   : Debug level
```

> 👎 **No defaults**, requires 9+ positional args, zero documentation

---

### CLI: KaHyPar 🏆

```bash
# Clean, modern argument parsing
mtkahypar -h circuit.hgr -k 2 -e 0.05 -o cut -p quality

# With verbose output
mtkahypar -h circuit.hgr -k 2 -e 0.05 -o cut -p default --verbose

# Write partition file
mtkahypar -h circuit.hgr -k 2 -e 0.05 -o cut -w --partition-output-folder ./out

# Arguments
#   -h, --hypergraph   : Input file
#   -k, --blocks       : Number of blocks
#   -e, --epsilon      : Imbalance parameter
#   -o, --objective    : cut / km1 / soed / steiner_tree
#   -p, --preset-type  : default / quality / highest_quality / deterministic
```

> 👍 **Modern CLI**, named arguments, good documentation, **but** requires `--objective` (no default)

---

class: nord-light, middle, center

## ⚠️ Warning Display Behavior

---

### The Test Case 🧪

```
3 5 10          ← 3 nets, 5 vertices, format 10 (vertex weights)
1 2 3           ← Net 0 connects v1, v2, v3
1 4 5           ← Net 1 connects v1, v4, v5
2 3 5           ← Net 2 connects v2, v3, v5
10000000        ← Vertex 0 weight = 10,000,000 (huge!)
1               ← Vertex 1 weight = 1
1               ← Vertex 2 weight = 1
1               ← Vertex 3 weight = 1
1               ← Vertex 4 weight = 1
```

**Total weight**: 10,000,004  |  **Ideal balance**: 5,000,002 per part

With $\epsilon = 0.0000001$ (0.00001%): each part must have weight $\ge 1$

The huge vertex (10M) **cannot** be split → imbalance **guaranteed**!

---

### ckpttn-cpp: Warning Behavior ✅

```
$ CkPttn.exe test_balance.hgr 2 0.5 --verbose

Reading hypergraph from test_balance.hgr...
Hypergraph: 5 vertices, 3 nets
K=2, epsilon=0.5, preset=default
Running partitioning (preset: default, mode: recursive)...
Partitioning cost: 2


Warning: final partition does not satisfy the balance constraint
```

| Part | Weight | Max Allowed | Status |
|:----:|:------:|:-----------:|:------:|
| 0 | 4 | ~5,000,002 | ❌ Violated |
| 1 | 10,000,000 | ~5,000,002 | ❌ Violated |

> 🟢 **Explicit warning** in final output — impossible to miss

---

### hMetis: Warning Behavior ❌

```
$ hmetis.exe test_balance_hmetis.hgr 2 1 1 1 1 0 0 0


HMETIS 1.5.3  Copyright 1998, Regents of the University of Minnesota

HyperGraph Information -----------------------------------------------------
 Name: test_balance_hmetis.hgr, #Vtxs: 5, #Hedges: 3, #Parts: 2, UBfactor: 0.01
 Options: HFC, FM, Reconst-False, No V-cycles, No Fixed Vertices

Recursive Partitioning... --------------------------------------------------

 --------------------------------------------------------------------------
  Summary for the 2-way partition:
                Hyperedge Cut:        2
      Sum of External Degrees:        4
                  Scaled Cost: 1.00e-001
                   Absorption:      2.00

      Partition Sizes & External Degrees:
10000000[   2]      4[   2]           ← 10M vs 4, imbalance = 99.96%
                                        ⚠️ NO WARNING
```

| Part | Weight | UBfactor 1% | Warning? |
|:----:|:------:|:-----------:|:--------:|
| 0 | 10,000,000 | ~5,050,000 | 🔴 None! |
| 1 | 4 | ~5,050,000 | 🔴 None! |

> 🔴 **No warning at all** — silently returns imbalanced result

---

### KaHyPar: Warning Behavior ⚠️

```
$ mtkahypar -h test_balance.hgr -k 2 -e 0.0000001 -o cut --verbose

...
Local Search Results:
** Partition is imbalanced (Current Imbalance: 0.999999) **
Part weights: (violations in red)
|block 0| = 1  w(0) = 10000000  max(0) = 5000002    ← RED
|block 1| = 4  w(1) = 4         max(1) = 5000002    ← RED
** Start rebalancing! **
** Rebalancer improves solution quality by 0 **
...

*****************************************************************************
*                          Partitioning Result                              *
*****************************************************************************
Objectives:
  Imbalance            = 0.999999
  Has Empty Blocks     = false
...
```

| Part | Weight | Max Allowed | Warning? |
|:----:|:------:|:-----------:|:--------:|
| 0 | 10,000,000 | 5,000,002 | 🟡 In Local Search only |
| 1 | 4 | 5,000,002 | 🟡 Not in Final Result |

> 🟡 **Intermediate warning** but **final result** just shows `Imbalance = 0.999999`

---

### Comparison Summary ⚠️

| Tool | Intermediate Warning | **Final Output** | User Visibility |
|:----:|:-------------------:|:----------------:|:---------------:|
| **ckpttn** | N/A | ✅ **Explicit text** | 🟢 Clear |
| **hMetis** | ❌ None | ❌ **None** | 🔴 Missed |
| **KaHyPar** | 🟡 "Partition is imbalanced" | ⚠️ Raw data only | 🟡 Confusing |

**Key insight**: Only **ckpttn-cpp** provides an explicit warning message in the **final** output that clearly states the balance constraint is violated.

---

### Why Warnings Matter for Scientific Research 🧪

> "If you just need an answer no matter correct or not, I can give you a program that runs within **0.000001 seconds**!" ⚡

**The "Instant Answer" Fallacy**:

```python
def partition(hypergraph, k, epsilon):
    return [0] * len(hypergraph)   # All vertices in part 0 — done in 1µs!
```

✅ Fast? Yes.  
✅ Gives an answer? Yes.  
❌ **Valid? No.** The balance constraint is trivially violated.

---

### The Scientific Integrity Problem 🔬

**Without warnings**, these tools are indistinguishable:

```
Tool A (1µs):   0 0 0 0 0    ← all in one part, balance violated ❌
Tool B (5ms):   0 0 1 1 0    ← balanced, legitimate result ✅
```

**Silent failure** in scientific computing leads to:

| Problem | Consequence |
|:--------|:-----------|
| 🎭 **False confidence** | User assumes result is valid |
| 🔁 **Non-reproducible** | Different runs give different quality |
| 📉 **Invalid benchmarks** | Published results may be meaningless |
| 🧪 **Wrong conclusions** | Downstream research built on bad data |

**The warning transforms an opaque answer into accountable science.** 🛡️

---

### The Reproducibility Crisis 🆘

.mermaid[

<pre>
flowchart LR
    A[Silent Tool] --> B["Imbalanced\n Result"]
    B --> C[User Trusts ✅]
    C --> D[Published Paper 📄]
    D --> E[Others Try to\n Reproduce 🤔]
    E --> F["Can't Reproduce ❌\n Waste of Time"]
    
    A2[Tool with Warning] --> B2["Imbalanced\n Result + ⚠️"]
    B2 --> C2[User Investigates 🔍]
    C2 --> D2[Fix Parameters 🔧]
    D2 --> E2[Valid Result ✅]
    E2 --> F2[Reproducible Science 🏆]
    
    style A fill:#f44336
    style B fill:#f44336
    style C fill:#f44336
    style D fill:#f44336
    style E fill:#f44336
    style F fill:#f44336
    
    style A2 fill:#4caf50
    style B2 fill:#4caf50
    style C2 fill:#4caf50
    style D2 fill:#ff9800
    style E2 fill:#4caf50
    style F2 fill:#4caf50
</pre>

]

A warning turns a **silent failure** into an **actionable signal**. Without it, researchers waste months chasing results that were invalid from the start. ⏳

---

### The "Rigorous Answer" Contract 📜

A partitioner should guarantee:

$$ \text{output} = \begin{cases}
\text{valid partition}, & \text{if } \exists \text{ feasible solution} \\
\text{best-effort} + \color{red}{\text{⚠️ warning}}, & \text{otherwise}
\end{cases} $$

**Without warning**:

$$ \text{user assumes: } \text{output} \implies \text{valid} $$

**With warning**:

$$ \text{output} + \color{red}{\text{⚠️ warning}} \implies \text{"check your constraints!"} $$

This is the **difference between science and guesswork**. 🎯

---

### Confusing Downstream Auto-Tuning 🤖

**Reinforcement Learning** for parameter tuning relies on **reward signals**:

$$ \text{Reward} = f(\text{cut}, \text{imbalance}, \text{runtime}) $$

A silent imbalanced result looks **identical** to a valid one:

```
State → Agent → Action (ε) → Partitioner → Result → Reward
                                              │
        Silent failure:   cut=2, imbalance=0.999999  →  ❌ looks OK to RL
        Valid result:     cut=2, imbalance=0.000000  →  ✅ actually OK
```

**The RL agent cannot distinguish** between:
- 🟢 "Good partition with low cut" (valid)
- 🔴 "Bad partition because constraint was violated" (invalid)

---

### RL Tuning Gone Wrong 🎰

.mermaid[

<pre>
flowchart TD
    subgraph "Without Warning ⚠️"
        A1[RL Agent] -->|tune ε| B1[Silent Partitioner]
        B1 -->|cut=2| C1[Reward: high!]
        C1 --> A1
        B1 -.->|imbalance hidden| D1[Agent thinks ε=0.5 is great]
        D1 -.-> A1
    end
    
    subgraph "With Warning ✅"
        A2[RL Agent] -->|tune ε| B2[Honest Partitioner]
        B2 -->|cut=2 + ⚠️| C2[Reward: penalized!]
        C2 --> A2
        B2 -->|imbalance reported| D2[Agent learns ε is too strict]
        D2 --> A2
    end
    
    style A1 fill:#f44336
    style B1 fill:#f44336
    style C1 fill:#f44336
    style D1 fill:#f44336
    
    style A2 fill:#4caf50
    style B2 fill:#4caf50
    style C2 fill:#4caf50
    style D2 fill:#ff9800
</pre>

]

**Without warnings**, the RL agent learns the **wrong policy** — it thinks tight constraints give good cuts because it doesn't know the constraints were silently violated. The agent converges to a useless configuration. 🎰

---

### Auto-Tuning: Key Equations 📊

**RL objective with silent failure**:

$$ \pi^* = \arg\max_\pi \mathbb{E}_{\tau \sim \pi} \left[ \sum_t R_t \right] $$

where the reward $R_t$ is **contaminated**:

$$ R_t = \underbrace{R_{\text{cut}}}_{\text{low!}} - \underbrace{\lambda \cdot \mathbb{1}[\text{balanced}]}_{\text{always 0 if hidden!}} $$

The agent greedily drives $\epsilon \to 0$, thinking tighter constraints always improve quality — when in reality, it's just **ignoring broken results**.

**With explicit warnings**, the reward becomes:

$$ R_t = R_{\text{cut}} - \lambda \cdot \text{⚠️}_t $$

Now the agent learns that $\epsilon$ too low → warning → penalty → **not useful**. 🎯

---

### Real-World Impact 🌍

| Scenario | Silent Tool | Tool with Warning |
|:---------|:-----------:|:-----------------:|
| 🧪 **Researcher** | Publishes invalid benchmark 📄❌ | Catches issue, fixes ε 🔧 |
| 🤖 **RL Tuning** | Learns wrong policy, wastes GPU months 🎰 | Learns valid parameter region 🎯 |
| 🏭 **Production** | Silent quality degradation 📉 | Alert → rollback 🔔 |
| 📚 **Reproducibility** | "Works on my machine" 🤷 | Clear failure signal 📡 |

> **Bottom line**: A warning is not just a nice-to-have — it's **essential infrastructure** for any research pipeline that uses partitioning as a building block. Without it, every downstream result is suspect. 🕵️

---

class: nord-light, middle, center

## 🧪 Experimental Results

---

### Test Setup 🔬

**Hardware**: WSL2 (Ubuntu 22.04) on Windows 11

**Test hypergraph**:

$$|V| = 5, \quad |\mathcal{E}| = 3, \quad \text{weights} = [10^7, 1, 1, 1, 1]$$

**Metric**: Does the tool warn when balance constraint is violated?

| Tool | Version | Epsilon / UBfactor | Result |
|:----:|:-------:|:------------------:|:------:|
| ckpttn | v1.0 | $\epsilon = 0.5$ | ✅ Warning |
| hMetis | 1.5.3 (1998) | UBfactor = 1% | ❌ Silent |
| KaHyPar | 1.6.1 | $\epsilon = 10^{-7}$ | ⚠️ Imbalance shown |

---

### Mermaid: Decision Flow 🔀

.mermaid[

<pre>
flowchart TD
    A[Run Partitioner] --> B{Balance\nSatisfied?}
    B -->|Yes| C["✅ Return Result"]
    B -->|No| D{Which Tool?}
    
    D -->|ckpttn-cpp| E["⚠️ Explicit Warning\nin Final Output"]
    D -->|hMetis| F["❌ Silent Return\nNo Indication"]
    D -->|KaHyPar| G["📊 Imbalance Value\nin Final Stats"]
    
    E --> H["User takes action\n(fix weights / relax ε)"]
    F --> I["User assumes OK ❌"]
    G --> J["User must interpret\nraw numbers"]
    
    style A fill:#4caf50
    style B fill:#ff9800
    style C fill:#4caf50
    style D fill:#f44336
    style E fill:#4caf50
    style F fill:#f44336
    style G fill:#ff9800
    style H fill:#4caf50
    style I fill:#f44336
    style J fill:#ff9800
</pre>

]

---

### Code Quality & Maintainability 📊

| Aspect | **ckpttn-cpp** | **hMetis** | **KaHyPar** |
|:-------|:--------------:|:----------:|:-----------:|
| Language | C++20 🌟 | C89 🦕 | C++17 🌟 |
| Build System | CMake ✅ | Makefile | CMake ✅ |
| Tests | doctest ✅ | None ❌ | Extensive ✅ |
| Documentation | Doxygen ✅ | Manual (PDF) | Doxygen ✅ |
| CI/CD | GitHub Actions ✅ | None ❌ | GitHub Actions ✅ |
| Code Coverage | codecov ✅ | None ❌ | codecov ✅ |
| Active Issues | Tracked ✅ | None ❌ | Tracked ✅ |

---

class: nord-light, middle, center

## 📊 Summary & Recommendations

---

### Summary 📝

.mermaid[

<pre>
graph LR
    subgraph "Hypergraph Partitioning Tools"
        A[ckpttn-cpp] --> A1[Modern C++20]
        A --> A2[Explicit Warnings ✅]
        A --> A3[Active Development]
        
        B[hMetis] --> B1[Ancient Codebase]
        B --> B2[Silent Failures ❌]
        B --> B3[Abandoned]
        
        C[KaHyPar] --> C1[High Quality]
        C --> C2[Partial Warnings ⚠️]
        C --> C3[Active, Python Bindings]
    end
    
    style A fill:#4caf50
    style A1 fill:#4caf50
    style A2 fill:#4caf50
    style A3 fill:#4caf50
    
    style B fill:#f44336
    style B1 fill:#f44336
    style B2 fill:#f44336
    style B3 fill:#f44336
    
    style C fill:#ff9800
    style C1 fill:#ff9800
    style C2 fill:#ff9800
    style C3 fill:#ff9800
</pre>

]

---

### Recommendations 🎯

| Scenario | Recommended Tool | Rationale |
|:---------|:---------------:|:----------|
| 🆕 **New project** | **ckpttn-cpp** | Modern C++, explicit warnings, MIT license |
| 🔬 **Research / Benchmark** | **KaHyPar** | Highest quality, Python bindings, multi-threaded |
| 📚 **Legacy / Compatibility** | **hMetis** | Only for reproducing old results |
| 🚦 **Need balance warnings** | **ckpttn-cpp** | **Only tool** with explicit final-output warning |

**Bottom line**: ckpttn-cpp is the **only tool** that explicitly warns users when the balance constraint is violated in the final output. For quality-sensitive partitioning, use KaHyPar. For new development with safety checks, use ckpttn-cpp.

---

### What We Learned 📖

1. 🧮 **Hypergraph partitioning** is critical for VLSI, EDA, ML, and parallel computing
2. ⚖️ **Balance constraints** define the quality-vs-feasibility trade-off
3. 🔍 **Warning behavior varies wildly** across tools — from silent (hMetis) to explicit (ckpttn)
4. 🚀 **ckpttn-cpp** now has the **best warning behavior** — a clear message in the final output
5. 🏆 **KaHyPar** offers the highest quality but doesn't explicitly warn
6. 💀 **hMetis** is functionally abandoned and silently returns bad results

---

count: false
class: nord-dark, middle, center

## 🔗 References

- ckpttn-cpp: [github.com/luk036/ckpttn-cpp](https://github.com/luk036/ckpttn-cpp)
- KaHyPar: [github.com/kahypar/kahypar](https://github.com/kahypar/kahypar)
- hMetis: [karypis.github.io](https://karypis.github.io/glaros/software/metis/overview.html)
- Fiduccia & Mattheyses (1982). "A Linear-Time Heuristic for Improving Network Partitions"

---

count: false
class: nord-dark, middle, center

## Q&A 🎤

## 🙏 Thank You!
