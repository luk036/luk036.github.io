layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# 🗺️ luk036.github.io

### Educational Content on Algorithms, VLSI Design, and Programming

@luk036 👨‍💻 · 2026 📅

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/8f6a673d3177482b9b1d7b77995f0844)](https://app.codacy.com/app/luk036/luk036.github.io?utm_source=github.com&utm_medium=referral&utm_content=luk036/luk036.github.io&utm_campaign=badger)

---

### 📋 Agenda

.pull-left[

**Part 1: Overview** 🎯
- Site Structure & Navigation
- Technology Stack

**Part 2: Mathematics & Theory** 🧠
- Convex Optimization
- N-Sphere Sampling
- Geometry & Quorum Systems

**Part 3: VLSI & Hardware** 🔌
- Physical Design
- DFM Algorithms
- Approximate Computing
- Hardware Acceleration

]
.pull-right[

**Part 4: Programming & Tools** 💻
- Modern C++
- Network Optimization
- Rust & Beyond

**Part 5: Featured Topics** 🌟
- In-Depth Highlights

**Part 6: Packages & Navigation** 📦
- Key Packages
- Running Slides Locally

]

---

class: nord-light, middle, center

## Part 1: Overview 🎯

---

### 🌐 Site Overview

A **static educational website** hosted on GitHub Pages, covering three pillars:

.pull-left[
**🔬 Mathematics & Algorithms**
- Convex optimization, ellipsoid method
- N-sphere sampling, LDS sequences
- Projective geometry, quorum systems
- Bayesian statistics and ML

**💻 VLSI & Hardware Design**
- Physical design automation
- DFM algorithms, clock skew
- Approximate computing, CSD
- CGRA, FPGA, LLVM/MLIR
]
.pull-right[
**🛠️ Programming & Tools**
- Modern C++ (17/20 features, patterns)
- Network optimization algorithms
- Python → Rust migration
- Documentation generation
- Git/CI workflows

**By the numbers:**
- 📁 **18 topic directories**
- 📄 **100+ Remark.js slide decks**
- 📐 **KaTeX** math rendering
- 🧩 **Mermaid** diagrams
]

---

### 🏗️ Technology Stack

.pull-left[
.mermaid[
<pre>
graph LR
    A[Markdown\nContent] --> B[Remark.js\nSlide Engine]
    B --> C[HTML5 Slides]
    D[KaTeX\nMath] --> B
    E[Mermaid\nDiagrams] --> B
    F[Nord Theme\nCSS] --> C
    G[GitHub Pages] --> C
    style A fill:#4caf50
    style B fill:#2196f3
    style C fill:#ff9800
    style D fill:#9c27b0
    style E fill:#f44336
    style F fill:#00bcd4
    style G fill:#607d8b
</pre>
]
]
.pull-right[
- **Remark.js** — JavaScript slide engine rendering Markdown → HTML slides
- **KaTeX** — Fast $\LaTeX$ math rendering with `ignoredTags` for code blocks
- **Mermaid** — Flowcharts, architecture diagrams, state machines
- **Nord Theme** — Dark/light slide themes with consistent typography
]

---

### 📁 Directory Structure

Content is organized into self-contained topic directories:

```text
luk036.github.io/
├── cvx/              # Convex optimization & ellipsoid method
├── phys_des/         # VLSI physical design automation
├── algo4dfm/         # DFM algorithms & complexity theory
├── AxC/              # Approximate computing & CSD
├── cgra/             # CGRA, FPGA, LLVM/MLIR, HDL
├── proglang/         # Modern C++, Git/CI, docs, tools
├── net_optim/        # Graph algorithms & network flow
├── n_sphere/         # Low discrepancy sequences
├── cqs/              # Cyclic quorum systems
├── projgeom/         # Projective geometry
├── statistics/       # Bayesian optimization, RL
├── latch/            # Latch-based timing
├── rust_by_examples/ # Python → Rust migration
├── fun/              # Foundations (metric spaces, algebra)
├── flows/            # Development workflows
└── idea/             # Working notes, experiments
```

Each directory contains `index.html` + `README.md` (slide deck) + `*-remark.html` files.

---

class: nord-light, middle, center

## Part 2: Mathematics & Theory 🧠

---

### 🔬 Mathematics & Theory

.font-sm.mb-xb[
| Topic | Directory | Description |
|-------|-----------|-------------|
| **Convex Optimization** | [`cvx/`](cvx/index.html) | CVXPY, KKT conditions, geometric programming, quasi-convex, LMI, ellipsoid method, cutting-plane, Krylov methods |
| **N-Sphere Sampling** | [`n_sphere/`](n_sphere/index.html) | Low discrepancy sequences (van der Corput, Halton), spherical point generation, CORDIC implementation |
| **Projective Geometry** | [`projgeom/`](projgeom/index.html) | Cayley-Klein geometries, rational trigonometry, Python implementation |
| **Cyclic Quorum Systems** | [`cqs/`](cqs/index.html) | Difference covers, necklace generation, distributed systems |
| **Statistics & ML** | [`statistics/`](statistics/index.html) | Bayesian optimization, Gaussian processes, reinforcement learning |
]

---

### 📐 Convex Optimization (cvx/)

.pull-left[
**Core Topics:**
- Convex programming fundamentals
- Geometric programming (posynomials)
- Quasi-convex programming (bisection)
- Linear Matrix Inequalities (LMI)
- Convex piecewise-linear fitting

**Packages:**
- `ellalgo` — Ellipsoid method, cutting-plane
- `cvxpy` — Python convex optimization
]
.pull-right[
**Key Algorithms:**
- Ellipsoid method with deep/central/parallel cuts
- Cutting-plane with separation oracles
- Geometric program → convex transformations
- Spectral factorization for FIR filters
- Primal-dual interior point methods

**Applications:** EDA, filter design, circuit sizing
]

---

### 🌐 N-Sphere Sampling (n_sphere/)

Low discrepancy sequences for generating points on spheres:

$$ \text{VdC}_b(n) = \sum_i d[i] \cdot b^{-i-1} $$

.pull-left[
**Sphere&lt;2,3&gt;** (unit 2-sphere in 3D):
- VdC₂ → cos ϕ, VdC₃ → θ
- CORDIC-free sqrt computation
- Hardware-friendly architecture
]
.pull-right[
**Sphere3([7,2,3])** (unit 3-sphere in 4D):
- VdC₇ → F₂⁻¹ LUT → CORDIC
- Spherical coordinates in 4D
- LDS hardware generators
]

Used in: quasi-Monte Carlo, particle filters, hardware test generation.

---

class: nord-light, middle, center

## Part 3: VLSI & Hardware 🔌

---

### 💻 VLSI & Hardware Design

| Topic | Directory | Description |
|-------|-----------|-------------|
| **Physical Design** | [`phys_des/`](phys_des/index.html) | Circuit partitioning, placement, routing, clock tree synthesis, timing closure |
| **DFM Algorithms** | [`algo4dfm/`](algo4dfm/index.html) | Complexity theory, clock skew under PV, PSM, layout decomposition, delay padding |
| **Approximate Computing** | [`AxC/`](AxC/index.html) | Approximate arithmetic, CSD representation, multiplierless FIR/IIR filters |
| **Hardware Acceleration** | [`cgra/`](cgra/index.html) | CGRA architecture, FPGA, LLVM/MLIR, HDL generators, Yosys synthesis |
| **Latch-Based Timing** | [`latch/`](latch/index.html) | Useful skew, max-plus algebra, timing optimization |

---

### 🏭 Physical Design (phys_des/)

.pull-left[
**Foundations:**
- Circuit partitioning (FM, multi-level)
- Rectilinear geometry toolkit
- `physdes` C++/Python package

**Placement & Routing:**
- Global placement (min-max fairness)
- Steiner forest (2-approximation PD-SF)
- FPGA routing, global routing with keepouts
]
.pull-right[
**Clocking & Timing:**
- DME algorithm for clock trees
- Arena-based tree with `NodeIdx`
- Linear vs Elmore delay models
- Timing closure (STA, setup/hold, ECO)
- Useful skew optimization

**Packages:** `ckpttnpy`, `physdes`, `netlistx`
]

---

### 🛡️ DFM Algorithms (algo4dfm/)

.mermaid[
<pre>
graph LR
    subgraph "Part I: Foundations"
        F1["DFM Introduction"]
        F2["Software Dev & Tools"]
        F3["Statistics & Correlation"]
        F4["Convex Optimization"]
    end
    subgraph "Part II: Core Algorithms"
        C1["Ellipsoid Method"]
        C2["Cutting-plane Method"]
        C3["Clock Skew Scheduling"]
        C4["Network Flow"]
        C5["Complexity Theory"]
    end
    subgraph "Part III: Advanced"
        A1["Phase Shifting Mask"]
        A2["Layout Decomposition"]
        A3["1D Layout Design"]
    end
</pre>
]

Key topics: NP-completeness in EDA, yield-driven clock skew (EVEN, PROP, C-PROP), Hadlock's algorithm for planar MAX-CUT, delay padding via dual decomposition.

---

### ⚡ Approximate Computing (AxC/)

.pull-left[
**Approximate Arithmetic:**
- Survey of AxC techniques
- Approximate multipliers for neural nets
- Error tolerance analysis

**Canonical Signed Digit (CSD):**
- `csdigit` Python package
- CSD multiplier synthesis (LCSRe)
- Shift-add optimization
]
.pull-right[
**Digital Filters:**
- Multiplierless FIR/IIR design
- Direct-form vs transpose-form
- Discrete optimization vs quantize-after

**Root Finding:**
- `ginger` package
- Polynomial root finding & reconstruction
- Leja ordering for numerical stability
]

---

### 🚀 Hardware Acceleration (cgra/)

.font-sm.mb-xs[
| Topic | Description |
|-------|-------------|
| **CGRA** | Coarse-grained reconfigurable arrays — architecture, compilation, challenges |
| **FPGA** | Principles, progression, COFFE2 modeling |
| **Compilers** | LLVM IR, MLIR multi-level infrastructure |
| **HDL Generators** | LDS hardware with CORDIC, van der Corput → unit sphere |
| **Synthesis** | Yosys flatten mode, hierarchical vs flat ABC |
| **Approx Multipliers** | Energy-efficient neural computing |
| **Digital Design** | Advanced digital system design |
]

---

class: nord-light, middle, center

## Part 4: Programming & Tools 💻

---

### 🛠️ Programming & Tools

| Topic | Directory | Description |
|-------|-----------|-------------|
| **Programming Language** | [`proglang/`](proglang/index.html) | Modern C++17/20, design patterns, Git/CI workflows, documentation generation, code quality, video processing, xTensor |
| **Network Optimization** | [`net_optim/`](net_optim/index.html) | Graph algorithms, NCF, MCR, parametric SP, vertex cover (exact→GPU), TSP, DEC, Hadlock |
| **Rust Migration** | [`rust_by_examples/`](rust_by_examples/index.html) | Python → Rust migration guide, ownership, traits |
| **Fundamentals** | [`fun/`](fun/index.html) | Metric spaces, vector spaces, Boolean algebra |
| **Workflows** | [`flows/`](flows/index.html) | Development workflows, LaTeX, remote working |

---

### 🖥️ Programming Languages (proglang/)

.pull-left[
**C++ Features:**
- C++17/20 (concepts, ranges, coroutines)
- Design patterns (Strategy, Visitor, CRTP)
- Performance tips (move semantics, inlining)
- Header-only → source-based refactoring

**Documentation:**
- Doxygen + KaTeX for equations
- Sphinx + matplotlib for figures
- Cross-language docs (C++/Python)
]
.pull-right[
**Tools & Quality:**
- Git/GitHub CLI workflows
- CI automation (GitHub Actions)
- Common mistakes and lessons learned
- AI-assisted code validation
- Remove duplicate code patterns

**Cross-Language:**
- Python ⇄ C++ type systems
- Rust vs C++ comparison
- Cocotb HDL verification
- Video processing (FFmpeg)
- xTensor multi-dim arrays
]

---

### 🌐 Network Optimization (net_optim/)

.pull-left[
**Core Algorithms:**
- Negative Cycle Finding (NCF) — Bellman-Ford, Howard
- Minimum Cycle Ratio (MCR) — Karp's algorithm
- Parametric shortest paths
- Discrete Exterior Calculus (DEC)

**Approximations:**
- Christofides TSP (3/2-approximation)
- Primal-dual for covering problems
- Hadlock's planar MAX-CUT
]
.pull-right[
**Vertex Cover Suite:**
- Exact algorithms
- Randomized GPU (CUDA, cudarc)
- Python → C++ → Rust ports
- CUDA and Rust GPU implementations

**Package:** `digraphx` — Python graph algorithms
]

---

### 🦀 Rust & Beyond

- **Rust Migration Guide** — Python → Rust: ownership, borrowing, traits, patterns
- **Porting physdes** — C++ → Rust: geometry library with DME, Steiner routing, arena trees
- **Porting netlistx** — Python → Rust: EDA algorithms for covering, matching, graphs
- **Rust Ellipsoid** — Trait-based generic cutting-plane algorithms
- **GPU Vertex Cover (Rust)** — cudarc port for GPU-accelerated randomized algorithms

---

class: nord-light, middle, center

## Part 5: Featured Topics 🌟

---

### 🎯 Convex Optimization

.pull-left[
- Introduction to CVXPY
- Quasi-convex programming via bisection
- Ellipsoid method and amazing oracles
- Geometric programming transformations
- Linear Matrix Inequalities (LMI)
- Convex fitting using B-splines
]
.pull-right[
**Key files:** `cvxprog-remark.html`, `quasicvx-remark.html`, `geomprog-remark.html`, `ellipsoid-remark.html`, `ellalgo-remark.html`

> 📖 See: [`cvx/`](cvx/index.html)
]

---

### 🎯 Physical Design Automation

.pull-left[
- Circuit partitioning (FM, multi-level, Gray code)
- Rectilinear geometry toolkit
- Global placement (min-max fairness)
- Steiner forest (2-approximation PD-SF)
- DME clock tree synthesis
- Timing closure (STA, ECO)
]
.pull-right[
**Key files:** `ckpttn-remark.html`, `nnsplace-remark.html`, `steiner-forest-remark.html`, `dme_algorithm-remark.html`, `timing-closure-remark.html`

> 📖 See: [`phys_des/`](phys_des/index.html)
]

---

### 🎯 DFM & Clock Skew

.pull-left[
- Complexity theory & NP-completeness in EDA
- Clock skew scheduling under process variations
- Useful skew optimization
- Multi-corner delay padding via dual decomposition
- Phase shifting mask algorithms
- Layout decomposition for multiple patterning
]
.pull-right[
**Key files:** `lec05a-remark.html`, `lec05b-remark.html`, `delay_padding-remark.html`, `lec08-remark.html`, `lec09-remark.html`

> 📖 See: [`algo4dfm/`](algo4dfm/index.html)
]

---

### 🎯 Approximate Computing & CSD

.pull-left[
- Survey of approximate arithmetic circuits
- Approximate multipliers for neural computing
- Canonical Signed Digit (CSD) representation
- CSD multiplier: shift-add with LCSRe
- Multiplierless FIR filter design
- FIR vs IIR filter comparison
]
.pull-right[
**Key files:** `csd-remark.html`, `csd_multiplier-remark.html`, `csdigit-remark.html`, `multiplierless-remark.html`, `FIR-IIR-remark.html`

> 📖 See: [`AxC/`](AxC/index.html)
]

---

class: nord-light, middle, center

## Part 6: Packages & Navigation 📦

---

### 📦 Key Packages

| Package | Language | Description | Repo |
|---------|----------|-------------|------|
| `ellalgo` | Python | Ellipsoid method, cutting-plane, oracles | [luk036/ellalgo](https://github.com/luk036/ellalgo) |
| `digraphx` | Python | Graph algorithms, NCF, MCR, parametric SP | [luk036/digraphx](https://github.com/luk036/digraphx) |
| `ckpttnpy` | Python | Multi-level hypergraph partitioning (FM) | [luk036/ckpttnpy](https://github.com/luk036/ckpttnpy) |
| `physdes` | Python/C++ | Geometric operations, DME, Steiner routing | [luk036/physdes-py](https://github.com/luk036/physdes-py) |
| `netlistx` | Python | Covering, matching, independent set | [luk036/netlistx](https://github.com/luk036/netlistx) |
| `csdigit` | Python | Canonical signed digit conversion | [luk036/csdigit](https://github.com/luk036/csdigit) |
| `projgeom` | Python | Projective geometry, Cayley-Klein | [luk036/projgeom-py](https://github.com/luk036/projgeom-py) |

---

### 🔗 Package Relationships

.mermaid[
<pre>
graph LR
    ellalgo[ellalgo\nCutting-Plane] --> digraphx[digraphx\nGraph Algorithms]
    digraphx --> ckpttnpy[ckpttnpy\nPartitioning]
    ckpttnpy --> physdes[physdes\nGeometry]
    physdes --> netlistx[netlistx\nNetlist]
    csdigit[csdigit\nCSD] --> multiplierless[multiplierless\nFIR Filters]

    style ellalgo fill:#4caf50
    style digraphx fill:#2196f3
    style ckpttnpy fill:#ff9800
    style physdes fill:#9c27b0
    style netlistx fill:#f44336
    style csdigit fill:#00bcd4
    style multiplierless fill:#ff5722
</pre>
]

---

### 🖥️ Running Slides Locally

Since slides use Remark.js with `sourceUrl` to load Markdown:

```bash
# Recommended: Python HTTP server
cd luk036.github.io
python -m http.server 8000
# Open: http://localhost:8000
```

⚠️ Opening `index.html` directly via `file://` won't work for slides that load external `.md` files (CORS restriction). Self-contained `*-remark.html` files work via `file://`.

---

### 🧭 Navigating the Site

.pull-left[
**Starting points by topic:**

.font-sm.mb-xs[
| Topic | Start Here |
|-------|------------|
| Convex Opt | `cvx/cvxprog-remark.html` |
| N-Sphere | `n_sphere/` |
| Physical Design | `phys_des/README.md` |
| DFM | `algo4dfm/lec00-remark.html` |
| Approx Computing | `AxC/AxC-remark.html` |
| CGRA/FPGA | `cgra/CGRA-remark.html` |
| Programming | `proglang/README.md` |
| Network Opt | `net_optim/quickstart.html` |
]
]
.pull-right[
**Slide naming conventions:**

- `*-remark.html` — Self-contained slides (inline pattern, works via `file://`)
- `*-slides.md` — External source markdown (loaded via `sourceUrl`)
- `README.md` — Course overview (also Remark.js slides)

**All slide decks follow:** flatten-remark.html reference style with Agenda, consistent CSS/script ordering, KaTeX callback pattern, and proper slide annotations.
]

---

count: false
class: nord-dark, middle, center

# 🙋 Questions?

### Explore the site at [luk036.github.io](https://luk036.github.io) 🚀

Feel free to explore any topic above. Each directory contains Remark.js slide decks, code examples, and additional resources.

Slides built with Remark.js 🎉 | KaTeX | Mermaid | Nord Theme
