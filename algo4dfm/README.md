layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# 《可制造性设计算法》(Algorithms for Design-for-Manufacturability)

@luk036 👨‍💻 · 2026 📅

---

### 📋 Agenda

.pull-left[

**Foundations** 🧠
- DFM Intro
- Software Dev
- Statistics
- Convex Opt

**Core Algorithms** 🔄
- Ellipsoid
- Cutting-plane
- Clock Skew
- Network Flow

]
.pull-right[

**Advanced** 🔬
- PSM
- Layout Decomp

]

---

## 📚 Course Overview

This course covers algorithmic approaches to Design-for-Manufacturability (DFM) in VLSI chips. Topics include complexity theory, optimization paradigms, clock skew scheduling under process variations, lithography-friendly design, and layout decomposition algorithms.

---

## 🏫 Lectures

### Part I: Foundations

| #   | Topic                    | Materials                                                                                                                 |
| --- | ------------------------ | ------------------------------------------------------------------------------------------------------------------------- |
| 0   | Course Overview          | [slides](lec00-remark.html)                                                                                               |
| 1   | DFM Introduction         | [slides](lec01-remark.html), [video](https://www.bilibili.com/video/BV1b7421f7gA/)                                        |
| 2   | Software Development     | [slides](swdevflow.html), [tips](swdevtips.html), [modern C++](lec02a-remark.html), [AI programming](ai-programming.html) |
| 3   | Statistics & Correlation | [3a](lec03a-remark.html), [3b](lec03b-remark.html), [book](https://link.springer.com/book/10.1007/978-1-4842-9063-7)      |
| 4   | Convex Optimization      | [slides](lec02c-remark.html), [GP](gp.pdf), [video](https://www.bilibili.com/video/BV1Mz4y1V7T6/)                         |

---

### Part II: Core Algorithms

| #   | Topic                 | Materials                                                                                                                        |
| --- | --------------------- | -------------------------------------------------------------------------------------------------------------------------------- |
| 5   | Ellipsoid Method      | [slides](lec04-remark.html), [4a: Robust GP](lec04a-remark.html), [4b: Affine](lec04b-remark.html), [4c: AA](lec04c-remark.html) |
| 6   | Cutting-plane Method  | [oracles](lec06a-remark.html), [revisited](lec06b-remark.html)                                                                   |
| 7   | Clock Skew Scheduling | [CSS under PV](css_under_pv.html), [GEV](GEV.pdf), [unimodal](unimodal.html), [delay padding](delay_padding-remark.html)         |
| 8   | Network Flow          | [useful skew](useful_skew.pdf), [netflow+cvxopt](netflow+cvxopt.html), [RVI](rvi-remark.html)                                    |
| 9   | Complexity Theory     | [NP-completeness](complexity.html), [paradigms](algorithm-remark.html), [MAX-k-CUT](max-k-cut.html)                              |

---

### Part III: Advanced Topics

| #   | Topic                | Materials                                                           |
| --- | -------------------- | ------------------------------------------------------------------- |
| 10  | Phase Shifting Mask  | [slides](lec08-remark.html), [primal-dual](primal_dual.html)        |
| 11  | Layout Decomposition | [slides](lec09-remark.html), [multiple patterning](opensource.html) |
| 12  | 1D Layout Design     | [network flow](netflow+cvxopt.html)                                 |

---

## 🎯 Key Topics

### 1. Design for Manufacturability (DFM)

- **Challenges at sub-10nm nodes**: Process variations, lithography limitations, design rule complexity
- **Lithography-friendly design**: OPC, double patterning, EUV
- **Yield optimization**: CMP-aware fill, critical area analysis, via optimization

> 📖 See: [dfm4dummies.md](dfm4dummies.md)

---

### 2. Complexity Theory & Algorithmic Paradigms

- **NP-complete problems**: Vertex cover, TSP, Steiner tree
- **Approximation classes**: PTAS, FPTAS, APX
- **Algorithm design techniques**:
- Greedy (MST, Knapsack)
- Linear Programming + Rounding
- Primal-dual methods
- Randomized algorithms
- Dynamic programming
- Local search & Simulated annealing

> 📖 See: [complexity.md](complexity.md), [algorithm.md](algorithm.md)

---

### 3. Clock Skew Scheduling Under Process Variations

- **Zero skew vs Useful skew**: Traditional vs optimization-based approaches
- **Timing constraints**: Setup/hold time, feasible skew region (FSR)
- **Yield-driven scheduling**: EVEN, PROP, C-PROP methods
- **Statistical approaches**: Gaussian, log-normal, GEV distributions
- **Parametric shortest path algorithms**: Lawler's, Howard's methods

> 📖 See: [lec05.md](lec05.md), [css_under_pv.md](css_under_pv.md)

---

### 4. Phase Shifting Mask (PSM)

- **Phase conflict graph**: Construction via plane sweeping
- **Phase assignment problem**: NP-hard in general, polynomial for planar graphs
- **Algorithms**:
- Greedy (max spanning tree)
- Planar graph approach (Hadlock's algorithm using dual graph + minimum perfect matching)
- MAX-CUT reformulation

> 📖 See: [lec08.md](lec08.md)

---

### 5. Network Optimization

- **Useful skew scheduling**: Minimum cost-to-time ratio cycle
- **Convex optimization**: CVXPY applications
- **Network flow + convex opt**: Combined approaches

---

## 📖 Recommended Reading

### Textbooks

- G. Ausiello et al. _Complexity and Approximation: Combinatorial Optimization Problems and Their Approximability Properties_. Springer, 1999.
- M. R. Garey & D. S. Johnson. _Computers and Intractability: A Guide to the Theory of NP-completeness_. Freeman, 1979.
- Pablo Pedregal. _Introduction to Optimization_. Springer, 2003.

### Key Papers

- Jeng-Liang Tsai et al. "Yield-Driven, False-Path-Aware Clock Skew Scheduling". IEEE Design & Test of Computers, 2005.
- Hadlock, F. "A Finding of the Minimum Set of Missing Edges in a Bipartite Graph". 1975.

---

## 🛠️ Software Tools

- **CVXPY**: Python convex optimization
- **LEDA**: Algorithm library for graph problems
- **Bellman-Ford**: Negative cycle detection
- **Karp's algorithm**: Minimum mean cycle

---

## 📊 Course Contents (Detailed)

```text
algo4dfm/
├── README.md                # This file
├── index.html               # Slide viewer
├── lec00-remark.html        # Course Overview
├── lec01-remark.html        # DFM Introduction
├── lec02a-remark.html       # Modern C++
├── lec02c-remark.html       # Convex Optimization
├── lec03a-remark.html       # Statistics
├── lec03b-remark.html       # Non-parametric Correlation
├── lec04-remark.html        # Ellipsoid Method
├── lec04a-remark.html       # Robust Analog Sizing
├── lec04b-remark.html       # Robust Geometric Programming
├── lec04c-remark.html       # Affine Arithmetic
├── lec05a-remark.html       # Clock Skew Scheduling (1)
├── lec05b-remark.html       # Clock Skew Scheduling (2)
├── lec06a-remark.html       # Cutting-plane Method
├── lec06b-remark.html       # Ellipsoid Method Revisited
├── lec08-remark.html        # Phase Shifting Mask
├── lec09-remark.html        # Layout Decomposition
├── complexity.html          # Complexity Theory
├── complexity-remark.html   # Complexity Theory (alt)
├── algorithm-remark.html    # Algorithmic Paradigms
├── max-k-cut.html          # MAX-k-CUT Problem
├── swdevflow.html          # Software Development Flow
├── swdevtips.html          # Software Development Tips
├── ai-programming.html     # AI Programming
├── netflow+cvxopt.html     # Network Flow + CVX
├── css_under_pv.html       # CSS Under Process Variations
├── unimodal.html           # Unimodal Delay Models
├── delay_padding.md        # Multi-Corner Delay Padding (source)
├── delay_padding-remark.html # Multi-Corner Delay Padding (slides)
├── rvi-remark.html         # Redundant Via Insertion
├── opensource.html         # EDA Open Source
├── primal_dual.html        # Primal-Dual Method
├── dfm4dummies.md          # DFM Basics
├── gp.pdf                  # Gaussian Process
├── GEV.pdf                 # Generalized Extreme Value
├── useful_skew.pdf         # Useful Skew Scheduling
└── figs/                   # Figures
```

---

## 🎓 Learning Objectives

By the end of this course, you will be able to:

1. **Analyze computational complexity** of EDA problems
2. **Apply appropriate algorithmic paradigms** to different problem types
3. **Implement clock skew scheduling** for yield optimization
4. **Solve phase assignment** for lithography-friendly designs
5. **Use convex optimization** for VLSI design automation

---

### Course Structure 🗺️

.mermaid[

<pre>
graph TD
    subgraph "Foundations"
        F1("Lec 0: Overview")
        F2("Lec 1: DFM Intro")
        F3("Lec 2: Software Dev")
        F4("Lec 3: Statistics")
        F5("Lec 4: Convex Opt")
    end
    subgraph "Core Algorithms"
        C1("Lec 5: Ellipsoid")
        C2("Lec 6: Cutting-plane")
        C3("Lec 7: Clock Skew")
        C4("Lec 8: Network Flow")
        C5("Lec 9: Complexity")
    end
    subgraph "Advanced Topics"
        A1("Lec 10: PSM")
        A2("Lec 11: Layout Decomp")
        A3("Lec 12: 1D Layout")
    end
    F5 --> C1
    C3 --> A1
    C4 --> A2
    style F5 fill:#4caf50
    style C1 fill:#2196f3
    style C3 fill:#ff9800
    style C4 fill:#ff9800
    style A1 fill:#9c27b0
    style A2 fill:#9c27b0
</pre>

]

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
