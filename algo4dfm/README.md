layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# 《可制造性设计算法》(Algorithms for Design-for-Manufacturability)

@luk036 👨‍💻

---

## 📚 Course Overview

This course covers algorithmic approaches to Design-for-Manufacturability (DFM) in VLSI chips. Topics include complexity theory, optimization paradigms, clock skew scheduling under process variations, lithography-friendly design, and layout decomposition algorithms.

---

## 🏫 Lectures

### Part I: Foundations

| #   | Topic                    | Materials                                                                                         |
| --- | ------------------------ | ------------------------------------------------------------------------------------------------- |
| 0   | Course Overview          | [slides](lec00-remark.html)                                                                       |
| 1   | DFM Introduction         | [slides](lec01-remark.html), [video](https://www.bilibili.com/video/BV1b7421f7gA/)                |
| 2   | Software Development     | [slides](swdevflow.html), [AI programming](ai-programming.html)                                   |
| 3   | Statistics & Correlation | [slides](lec03a-remark.html), [book](https://link.springer.com/book/10.1007/978-1-4842-9063-7)    |
| 4   | Convex Optimization      | [slides](lec02c-remark.html), [GP](gp.pdf), [video](https://www.bilibili.com/video/BV1Mz4y1V7T6/) |

---

### Part II: Core Algorithms

| #   | Topic                 | Materials                                                             |
| --- | --------------------- | --------------------------------------------------------------------- |
| 5   | Ellipsoid Method      | [slides](lec04-remark.html)                                           |
| 6   | Clock Skew Scheduling | [CSS under PV](css_under_pv.html), [GEV](GEV.pdf)                     |
| 7   | Network Flow          | [useful skew](useful_skew.pdf), [netflow+cvxopt](netflow+cvxopt.html) |
| 8   | Complexity Theory     | [NP-completeness](complexity-remark.html), [paradigms](algorithm.md)  |

---

### Part III: Advanced Topics

| #   | Topic                | Materials                                                    |
| --- | -------------------- | ------------------------------------------------------------ |
| 9   | Phase Shifting Mask  | [slides](lec08-remark.html), [primal-dual](primal_dual.html) |
| 10  | Layout Decomposition | [slides](lec09-remark.html)                                  |
| 11  | Multiple Patterning  | Lithography decomposition                                    |
| 12  | 1D Layout Design     | Network flow applications                                    |

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

```
algo4dfm/
├── README.md                # This file
├── index.html               # Slide viewer
├── lec01-remark.html        # DFM Introduction
├── lec03a-remark.html       # Statistics
├── lec02c-remark.html       # Convex Optimization
├── lec04-remark.html        # Ellipsoid Method
├── lec05.md                 # Clock Skew Scheduling
├── css_under_pv.md          # Yield-driven CSS
├── lec08-remark.html        # Phase Shifting Mask
├── complexity-remark.html   # Complexity Theory
├── algorithm.md             # Algorithmic Paradigms
├── swdevflow.html           # Software Development
├── ai-programming.html      # AI Programming
├── netflow+cvxopt.html      # Network Flow + CVX
├── dfm4dummies.md           # DFM Basics
├── gp.pdf                   # Gaussian Process
├── GEV.pdf                  # Generalized Extreme Value
├── useful_skew.pdf          # Useful Skew Scheduling
└── figs/                    # Figures
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

count: false
class: nord-dark, middle, center

# Q&A 🎤
