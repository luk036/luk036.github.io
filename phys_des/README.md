layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Physical Design Automation

@luk036 👨‍💻

---

## 📚 Overview

This section covers algorithms and tools for VLSI Physical Design Automation. Topics include circuit partitioning, placement, routing, and geometric operations. The content includes both theoretical approaches and practical Python implementations.

---

### 1. Circuit Partitioning

| Topic                                            | Description                                    |
| ------------------------------------------------ | ---------------------------------------------- |
| [Generic Circuit Partitioning](ckpttn.html)      | Multi-level partitioning, FM algorithm         |
| [ckpttnpy: Python Package](ckpttnpy-remark.html) | Python implementation for circuit partitioning |

**Key Concepts:**

-   **Bi-partition vs K-way partitioning**: Split circuit into 2 or K parts
-   **FM Algorithm**: Local search with bucket sort and LIFO
-   **Multi-level extension**: Coarse-grain hypergraph approximation
-   **Primal-dual clustering**: Minimum maximal matching for clustering

> 📖 See: [ckpttn.md](ckpttn.md), [ckpttnpy.md](ckpttnpy.md)

---

### 2. Geometric Operations

| Topic                                  | Description                         |
| -------------------------------------- | ----------------------------------- |
| [Rectilinear Shape](recti.html)        | L-shapes, orthogonal shapes in VLSI |
| [physdes Package](physdes-remark.html) | Toolkit for 2D geometric operations |

**Key Concepts:**

-   **Generic Programming**: Support multiple data types (int, float)
-   **Primitive Types**: Point, Rectangle, Vertical/Horizontal Segment
-   **Operations**: overlap, contain, intersection, min_dist
-   **Interval Operations**: lb/ub bounds, length, intersect_with

> 📖 See: [recti.md](recti.md), [physdes.md](physdes.md)

---

### 3. Netlist & Graph Algorithms

| Topic                                    | Description                       |
| ---------------------------------------- | --------------------------------- |
| [netlistx Package](netlistx-remark.html) | Netlist manipulation and analysis |

**Key Concepts:**

-   **Graphs & Hypergraphs**: Circuit representation
-   **NetworkX integration**: Python graph library
-   **Covering problems**: Minimal vertex/edge covers
-   **Matching problems**: Primal-dual approximation algorithms

> 📖 See: [netlistx.md](netlistx.md)

---

### 4. Placement

| Topic                                     | Description                        |
| ----------------------------------------- | ---------------------------------- |
| [Global Placement](minmax-placement.html) | Analytical placement with fairness |
| [Packing (FPGA)](packing.html)            | FPGA block packing                 |

**Key Concepts:**

-   **HPWL (Half-Perimeter Wire Length)**: Traditional objective
-   **Smooth approximation**: Quadratic (conjugate gradient) or log-sum-exp
-   **Min-max fairness**: Minimize worst wire length instead of total
-   **Proportional fairness**: Weighted costs

**Challenge**: Congestion problems from underestimating wire length for nets with n > 3 pins

> 📖 See: [minmax-placement.md](minmax-placement.md), [packing.md](packing.md)

---

### 5. Routing (Planned)

| Topic                 | Status                                            |
| --------------------- | ------------------------------------------------- |
| Global Routing        | Covered in [global_routing.md](global_routing.md) |
| Clock-Tree Synthesis  | -                                                 |
| Clock Skew Scheduling | See [algo4dfm](../algo4dfm/index.html)            |

---

## 🗂️ File Structure

```text
phys_des/
├── README.md                 # This file
├── ckpttn.html               # Circuit partitioning
├── ckpttnpy-remark.html      # ckpttnpy package
├── recti.html                # Rectilinear shapes
├── physdes-remark.html       # Geometric toolkit
├── netlistx-remark.html      # Netlist package
├── packing.html              # FPGA packing
├── minmax-placement.html     # Global placement
├── global_routing.md         # Routing notes
├── nnsplace.md               # Neural network placement
├── ckpttn.md                 # Partitioning details
├── ckpttnpy.md               # Package details
├── recti.md                  # Shapes details
├── physdes.md                # Toolkit details
└── netlistx.md               # Netlist details
```

---

## 📦 Key Packages

| Package    | Language | Description              | Repo                                                  |
| ---------- | -------- | ------------------------ | ----------------------------------------------------- |
| `ckpttnpy` | Python   | Circuit partitioning     | [luk036/ckpttnpy](https://github.com/luk036/ckpttnpy) |
| `physdes`  | Multi    | Geometric operations     | [luk036/physdes-\*](https://github.com/luk036)        |
| `netlistx` | Python   | Netlist/graph algorithms | [luk036/netlistx](https://github.com/luk036/netlistx) |

---

## 📖 Key References

-   **Textbooks**:

  -   Carlavala, _Physical Design Automation of VLSI Systems_
  -   Kahng et al., _VLSI Physical Design: From Graph Partitioning to Timing Closure_

-   **Algorithms**:
  -   FM ( Fiduccia-Mattheyses) algorithm for partitioning
  -   Multi-level partitioning approaches

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
