layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Advanced Topics in VLSI Physical Design Automation

@luk036 👨‍💻

---

## 📚 Course Overview

This course covers advanced algorithms and techniques in VLSI Physical Design Automation — from partitioning and geometric computing to placement, routing, clock tree synthesis, and timing closure. The content emphasizes **algorithmic foundations**, **practical implementations** (Python/C++), and **modern challenges** at advanced process nodes.

---

## 🏫 Lectures

### Part I: Foundations

| #   | Topic                | Materials                                                                |
| --- | -------------------- | ------------------------------------------------------------------------ |
| 1   | Circuit Partitioning | [FM, multi-level](ckpttn.html), [ckpttnpy package](ckpttnpy-remark.html) |
| 2   | Rectilinear Geometry | [Shapes & metrics](recti.html), [Voronoi diagrams](rpolygon-slides.html) |
| 3   | Geometric Toolkit    | [physdes package](physdes-remark.html) — Point, Rect, Segment, Interval  |

---

### Part II: Placement

| #   | Topic                       | Materials                                                            |
| --- | --------------------------- | -------------------------------------------------------------------- |
| 4   | Analytical Global Placement | [Min-max fairness](minmax-placement.html), [methods](placement.html) |
| 5   | Fairness-Centric Placement  | [Howard's algorithm & bipartite matching](nnsplace-remark.html)      |
| 6   | FPGA Packing                | [Block packing algorithms](packing.html)                             |

---

### Part III: Routing

| #   | Topic                 | Materials                                                 |
| --- | --------------------- | --------------------------------------------------------- |
| 7   | Global Routing        | [With keepouts & 3D extension](global_router-slides.html) |
| 8   | Steiner Tree & Forest | [Primal-dual Steiner forest](steiner-forest-slides.html)  |
| 9   | FPGA Routing          | [Architecture-specific routing](FPGA-routing-remark.html) |

---

### Part IV: Clocking & Timing

| #   | Topic                          | Materials                                                                                      |
| --- | ------------------------------ | ---------------------------------------------------------------------------------------------- |
| 10  | Deferred Merge Embedding (DME) | [Prescribed-skew clock tree](dme_algorithm-slides.html)                                        |
| 11  | Useful Skew Design Flow        | [Clock skew scheduling](../algo4dfm/index.html), [delay padding](../algo4dfm/delay_padding.md) |
| 12  | Timing Closure                 | [Slides](timing-closure-remark.html) — STA, setup/hold, ECO                                    |

---

### Part V: Advanced Topics

| #   | Topic                          | Materials                                                               |
| --- | ------------------------------ | ----------------------------------------------------------------------- |
| 13  | Netlist & Graph Algorithms     | [netlistx package](netlistx-remark.html) — covering, matching           |
| 14  | Design for Manufacturing (DFM) | [See algo4dfm](../algo4dfm/index.html) — OPC, PSM, layout decomposition |

---

## 🎯 Key Topics

### 1. Circuit Partitioning

-   **Bi-partition vs K-way**: Split netlist into 2 or K balanced parts
-   **FM Algorithm**: Local search with bucket sort and LIFO gain updates
-   **Multi-level Extension**: Coarsen → partition → uncoarsen with refinement
-   **Primal-Dual Clustering**: Minimum maximal matching for hypergraph coarsening

> 📖 See: [ckpttn.md](ckpttn.md), [ckpttnpy.md](ckpttnpy.md)

---

### 2. Rectilinear Geometry & Computational Geometry

-   **Manhattan Metric**: $L_1$ distance for VLSI layouts
-   **Rectilinear Polygons**: Representation via origin + vectors
-   **Operations**: Area, orientation, convex hull, point inclusion, decomposition
-   **Rectilinear Voronoi Diagram**: $L_\infty$ metric, plane sweep

> 📖 See: [recti.md](recti.md), [rpolygon-slides.html](rpolygon-slides.html)

---

### 3. Global Placement

-   **HPWL Objective**: Half-perimeter wire length minimization
-   **Smooth Approximation**: Quadratic (conjugate gradient) or log-sum-exp
-   **Min-Max Fairness**: Minimize worst wire length instead of total
-   **Proportional Fairness**: Weighted cost allocation
-   **Challenge**: Congestion from underestimating wire length for nets with $n > 3$ pins

> 📖 See: [minmax-placement.md](minmax-placement.md)

---

### 4. Global Routing & Steiner Routing

-   **Global vs Detailed Routing**: Coarse path assignment then exact wire layout
-   **Steiner Tree**: Minimum rectilinear Steiner tree for multi-pin nets
-   **Steiner Forest**: Connect terminal pairs with 2-approximation (primal-dual + union-find)
-   **Keepout Avoidance**: Obstacle-aware routing
-   **3D Extension**: Multi-layer routing with via minimization

> 📖 See: [steiner-forest-slides.md](steiner-forest-slides.md), [global_router-slides.md](global_router-slides.md)

---

### 5. Clock Tree Synthesis (CTS)

-   **Zero-skew vs Prescribed-skew**: Traditional vs optimization-based approaches
-   **DME Algorithm**: Deferred-merge embedding for minimum wirelength
-   **Delay Models**: Linear vs Elmore delay comparison
-   **Elongation Handling**: Boundary conditions for feasible embedding

> 📖 See: [dme_algorithm-slides.html](dme_algorithm-slides.html)

---

### 6. Timing Closure

-   **Static Timing Analysis (STA)**: Setup/hold constraints, critical paths
-   **Useful Skew**: Intentional clock skew to improve timing slack
-   **Clock Skew Scheduling**: LP-based approach for feasible skew range
-   **Delay Padding**: Insert buffers to fix hold violations

> 📖 See: [timing-closure-remark.html](timing-closure-remark.html), [algo4dfm CSS](../algo4dfm/css_under_pv.html)

---

### 7. Domain-Specific Design Rules

-   **Integer Coordinates**: Big integers, avoid floating point, watch for overflow
-   **Rectilinear Assumption**: Geometry is rectilinear unless specified (45° abstract lines OK)
-   **Scale Realities**: $10^9$ objects, $\le 100$ polygon vertices, $\le 20$ metal layers
-   **Simplicity Principle**: Algorithms should be simple (not necessarily easy)
-   **C++ idioms**: No virtual functions unless needed; `unique_ptr` over `shared_ptr`

> 📖 See: [topics.md](topics.md)

---

## 📦 Key Packages

| Package    | Language   | Description                                 | Repo                                                      |
| ---------- | ---------- | ------------------------------------------- | --------------------------------------------------------- |
| `ckpttnpy` | Python     | Circuit partitioning (FM, multi-level)      | [luk036/ckpttnpy](https://github.com/luk036/ckpttnpy)     |
| `physdes`  | Python/C++ | Geometric operations (Point, Rect, Polygon) | [luk036/physdes-py](https://github.com/luk036/physdes-py) |
| `netlistx` | Python     | Netlist/graph algorithms                    | [luk036/netlistx](https://github.com/luk036/netlistx)     |
| `ellalgo`  | Python     | Ellipsoid method, cutting-plane             | [luk036/ellalgo](https://github.com/luk036/ellalgo)       |

---

## 🛠️ Software Tools

-   **ckpttnpy**: Multi-level hypergraph partitioning
-   **physdes-py**: Rectilinear geometry, Steiner routing, DME, global router
-   **netlistx**: Graph algorithms for netlists (covering, matching)
-   **NetworkX**: Python graph library for algorithm prototyping
-   **CVXPY**: Convex optimization for timing and placement

---

## 📖 Recommended Reading

### Textbooks

-   Naveed Sherwani, _Algorithms for VLSI Physical Design Automation_. Springer, 1999.
-   Andrew B. Kahng et al., _VLSI Physical Design: From Graph Partitioning to Timing Closure_. Springer, 2011.
-   Sadiq M. Sait & Habib Youssef, _VLSI Physical Design Automation: Theory and Practice_. World Scientific, 1999.

### Key Papers

-   Fiduccia & Mattheyses, "A Linear-Time Heuristic for Improving Network Partitions". DAC, 1982.
-   Cong et al., "DME: A General Methodology for Clock Tree Routing". IEEE TCAD, 1992.
-   Agarwal et al., "A Primal-Dual Algorithm for the Steiner Forest Problem". 2015.

---

## 🗂️ File Structure

```text
phys_des/
├── README.md                    # This file (course overview)
├── index.html                   # Slide viewer (loads README.md)
├── ckpttn.html                  # Lecture 1: Circuit partitioning
├── ckpttnpy-remark.html         # Lecture 1: ckpttnpy package
├── recti.html                   # Lecture 2: Rectilinear shapes
├── rpolygon-slides.html         # Lecture 2: Polygon algorithms
├── physdes-remark.html          # Lecture 3: Geometric toolkit
├── placement.html               # Lecture 4: Placement concepts
├── minmax-placement.html        # Lecture 4: Global placement
├── nnsplace-remark.html         # Lecture 5: Fairness-centric placement
├── packing.html                 # Lecture 6: FPGA packing
├── global_router-slides.html    # Lecture 7: Global routing
├── steiner-forest-slides.html   # Lecture 8: Steiner forest
├── FPGA-routing-remark.html     # Lecture 9: FPGA routing
├── dme_algorithm-slides.html    # Lecture 10: DME clock tree
├── timing-closure-remark.html   # Lecture 12: Timing closure
├── netlistx-remark.html         # Lecture 13: Netlist algorithms
├── pad-course-slides.html       # Lecture 14: Pad-ring planning
├── pda-slides.md                # Introductory PDA slides
├── topics.md                    # Topic definitions & domain rules
├── global_routing.md            # Routing notes
├── notes_ai.md                  # AI notes
└── figs/                        # Figures directory
```

---

## 🎓 Learning Objectives

By the end of this course, you will be able to:

1. **Apply multi-level partitioning** algorithms to large-scale netlists
2. **Implement rectilinear geometric operations** for VLSI layouts
3. **Design fairness-centric placement** algorithms with provable guarantees
4. **Construct Steiner trees and forests** with approximation algorithms
5. **Build global routers** with obstacle avoidance and 3D extension
6. **Implement Deferred-Merge Embedding** for clock tree synthesis
7. **Analyze timing constraints** and apply useful skew optimization
8. **Integrate DFM awareness** into the physical design flow

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
