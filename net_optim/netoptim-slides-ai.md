# Network Optimization: A Quick Start ⚡️

## Introduction 👋

-   Network optimization uses mathematical techniques to solve problems modeled on networks or graphs.
-   It's a **vital field** with many applications.
-   Goals include:
  -   Exploring the **locality and associativity** of a network.
  -   Solving **discrete optimization problems optimally** (e.g., matching/assignment).
  -   Gaining insight into the **most critical parts** of the network (critical cut/cycle).
-   This presentation provides a quick guide to the algorithms and concepts.

---

### Network Fundamentals: Building Blocks 🏗️

-   A network (or graph) is a collection of finite-dimensional vector spaces with **nodes** (${\color{salmon}V}$) and **edges** (${\color{lime}E}$).
  -   ${\color{salmon}V} = \{ {\color{brown}v_1}, \ldots, {\color{brown}v_N} \}$, $|{\color{salmon}V}| = N$
  -   ${\color{lime}E} = \{ {\color{darkgreen}e_1}, \ldots, {\color{darkgreen}e_M} \}$, $|{\color{lime}E}| = M$
-   Key requirements: boundary of each edge is union of nodes; intersection of two edges is empty or a boundary node.
-   This definition allows **self-loops and multi-edges**.
-   The graph structure encodes **neighborhood information**.

---

### Network Fundamentals: Orientation 🧭

**Orientation:** Edges have orientation defining a source ($s$) and target ($t$) node.

-   Note: Orientation $\ne$ Direction.
-   Coherent orientations are the same.

---

### Network Fundamentals: Representation 📝

-   **Node-edge Incidence Matrix (${\color{blue}A^T}$)**: An $N \times M$ matrix.
  $$ {\color{green}A}(i, j) = \begin{cases} +1 & \text{if } {\color{darkgreen}e_j} \text{ is coherent with } {\color{brown}v_i} \\ -1 & \text{if } {\color{darkgreen}e_j} \text{ is not coherent with } {\color{brown}v_i} \\ 0 & \text{otherwise} \end{cases} $$
    Example Matrix:
    $$ {\color{blue}A^T} = \begin{bmatrix} 0 & -1 & 1 & 0 & 0 \\ -1 & 1 & 0 & -1 & -1 \\ -1 & 0 & -1 & 0 & 1 \end{bmatrix} $$
  -   This matrix captures node-edge relationships and orientation.
-   **Adjacency List:** Most efficient for practical implementation.

---

### Network Fundamentals: Abstract Concepts 🧠

-   **Chain (${\color{green}\tau}$)**: An edge/node tuple assigning coefficients. Can be an oriented indicator vector.
-   **Discrete Boundary Operator (${\color{blue}\partial} = {\color{blue}A^T}$)**.
-   **Cycle**: A chain ${\color{green}\tau}$ in the null-space of ${\color{blue}\partial}$, ${\color{blue}A^T} {\color{green}\tau} = 0$.
-   **Boundary**: A chain ${\color{green}\beta}$ in the range of ${\color{blue}\partial}$, ${\color{green}\beta} = {\color{blue}A^T} {\color{green}\tau}$.
-   **Co-boundary Operator (${\color{green}d} = {\color{green}A}$)**. Also called the differential operator.
-   Null-space of ${\color{green}A}$ relates to the number of graph components.

---

### Flow and Potential: Dual Perspectives 🤝

-   Two central, often **dual**, concepts describe network state.

-   **Flow (${\color{green}x}$), Current:** Quantity moving through edges.

  -   Key property: **Sum of ${\color{green}x}_{ij}$ around a node is zero** (conservation).
  -   **Divergence:** $div \ {\color{green}x} = {\color{blue}A^T} {\color{green}x}$.
  -   A vector ${\color{green}x}$ is a **flow** if $\sum div \ {\color{green}x} = 0$ (sources/sinks).
  -   A network is a **circulation** if $div \ {\color{green}x} = 0$ (no sources/sinks).

      ```mermaid
    graph LR
      A((v1)) -- x12 --> B((v2))
      A -- x13 --> C((v3))
      B -- x24 --> D((v4))
      C -- x34 --> D
      D -- x45 --> E((v5))

      subgraph Conservation at D
      direction LR
      B --> D
      C --> D
      D --> E
      end

      %% Caption: Flow conservation at a node. Sum of incoming flow equals sum of outgoing flow.
      ```

---

-   **Potential (${\color{firebrick}u}$), Voltage:** Scalar values associated with nodes.

  -   **Tension (${\color{blue}y}$)**: Difference in potential across an edge.
  -   ${\color{blue}y} = {\color{green}A}{\color{firebrick}u}$. Tension is a differential of potential.
  -   Key property: **Sum of ${\color{blue}y}_{ij}$ around a cycle is zero**.

      ```mermaid
    graph LR
      A((v1)) -- y12 --> B((v2))
      B -- y24 --> D((v4))
      D -- y43 --> C((v3))
      C -- y31 --> A
      %% Cycle A -> B -> D -> C -> A. Sum of tensions y12 + y24 + y43 + y31 = 0.
      ```

-   **Duality & Theorems:**

  -   **Tellegen's Theorem:** Flow and tension are **bi-orthogonal** (isomorphic).
    -   $0 = [{\color{blue}A^T} {\color{green}x}, {\color{firebrick}u}] = ({\color{blue}A^T} {\color{green}x})^T {\color{firebrick}u} = {\color{green}x}^T ({\color{green}A}{\color{firebrick}u}) = {\color{green}x}^T {\color{blue}y}$.
  -   **Discrete Stokes' Theorem:** ${\color{purple}[} {\color{green}\tau}, {\color{green}A}{\color{firebrick}\omega}{\color{purple}]} = {\color{purple}[} {\color{blue}A^T} {\color{green}\tau}, {\color{firebrick}\omega}{\color{purple}]}$. Relates integration over surface to boundary.
  -   **Fundamental Theorem of Calculus (discrete):** $[{\color{blue}A^T} {\color{green}\tau_1}, {\color{firebrick}c^0}] = [{\color{green}A} {\color{green}\tau_1}, {\color{firebrick}c^0}]$.

-   **Path & Cut:**

  -   **Path (${\color{lime}P}$)**: Edge sequence. Path indicator vector ${\color{green}\tau}$.
    -   Total tension on ${\color{lime}P}$ = total potential difference on boundary of ${\color{lime}P}$: ${\color{blue}y}^T {\color{green}\tau} = {\color{firebrick}u}^T ({\color{blue}\partial} {\color{lime}P})$.
  -   **Cut (${\color{steelblue}Q}$)**: Edge set separating two node sets ${\color{salmon}S}, {\color{salmon}S}'$. Cut indicator vector ${\color{blue}q} = {\color{green}A}{\color{firebrick}c}$.
    -   Total divergence of flow on ${\color{salmon}S}$ = total flow across ${\color{steelblue}Q}$: $(div \ {\color{green}x})^T {\color{firebrick}c} = {\color{green}x}^T {\color{blue}q}$.

      ```mermaid
    graph LR
      A((S)) -- Cut Q --> B((S'))
      A --> C
      D --> B
      C -- Cut Q --> D
      %% Caption: A cut Q separating node set S from S'.
      ```

-   **Critical Structures:** Finding **negative cycles** and **negative cuts** is crucial for many algorithms.

---

### Feasibility Problems: Can a Solution Exist? 🤔

-   Ask if a solution exists satisfying constraints.

### Feasible Flow Problem 🌊

-   Find a flow ${\color{green}x}$ subject to:
  -   **Capacity constraints:** ${\color{green}c^-} \le {\color{green}x} \le {\color{green}c^+}$.
  -   **Balance constraints:** ${\color{blue}A^T} {\color{green}x} = {\color{firebrick}b}$ (${\color{firebrick}b}$ is supply/demand, ${\color{firebrick}b}({\color{salmon}V})=0$ for circulation).
-   Solved using the **Painted network algorithm**.
  -   **Feasibility Condition:** A feasible solution exists iff ${\color{firebrick}b}({\color{salmon}S}) \le {\color{green}c^+}({\color{steelblue}Q})$ for all cuts ${\color{steelblue}Q} = [{\color{salmon}S}, {\color{salmon}S}']$.
  -   Proof sketch (if-part): If ${\color{green}x}$ feasible, for cut ${\color{blue}q}={\color{green}A}{\color{firebrick}k}$, ${\color{blue}q}^T {\color{green}x} \le {\color{green}c^+}({\color{steelblue}Q})$. Since ${\color{blue}q}^T {\color{green}x} = ({\color{green}A}{\color{firebrick}k})^T {\color{green}x} = {\color{firebrick}k}^T ({\color{blue}A^T} {\color{green}x}) = {\color{firebrick}k}^T {\color{firebrick}b} = {\color{firebrick}b}({\color{salmon}S})$, then ${\color{firebrick}b}({\color{salmon}S}) \le {\color{green}c^+}({\color{steelblue}Q})$.
  -   The "only-if" part is constructive (an algorithm finds solution).
-   If infeasible, algorithm returns a **"negative cut"**.
-   Bounds ${\color{green}c^-}, {\color{green}c^+}$ can be $\pm\infty$ or zero. Most tools require ${\color{green}c^-}=0$ for positive flow.
-   Can be reduced to an elementary problem by splitting edges.

    ```mermaid
    graph LR
      i((i)) -- [c-, c+] --> j((j))

      subgraph "Modified (Split Edge)"
      direction LR
      i((i)) -- [0, c+] --> k((k))
      k -- [0, c+ - c-] --> j((j))
      end
      %% Caption: Converting edge constraint [c-, c+] to elementary [0, c] by splitting.
    ```

-   Example: **Genome-scale reaction networks** (A is stoichiometric matrix S, x is reaction rates, ${\color{green}c^-}/{\color{green}c^+}$ bounds).

### Feasible Potential Problem ⚡️

-   Find node potentials ${\color{firebrick}u}$ subject to:
  -   **Tension constraints:** ${\color{blue}d^-} \le {\color{blue}y} \le {\color{blue}d^+}$.
  -   **Potential definition:** ${\color{green}A}{\color{firebrick}u} = {\color{blue}y}$.
-   Solved using the **Bellman-Ford algorithm**. Finds shortest paths, detects negative cycles.

    ```python

## Basic Bellman-Ford Algorithm Structure

  function BellmanFord(vertices, edges, source):
      initialize distances u[], predecessors pred[]
      u[source] = 0, others = inf
      pred[source] = null

      repeat size(vertices) - 1 times:
          for each edge (i, j) with weight d[i,j]:
              relax edge: if u[i] + d[i,j] < u[j]:
                  u[j] = u[i] + d[i,j]
                  pred[j] = i

      check for negative-weight cycles:
      for each edge (i, j) with weight d[i,j]:
          if u[i] + d[i,j] < u[j]:
              return "Graph contains a negative-weight cycle"

      return u[], pred[]
    ```

  -   **Feasibility Condition:** A feasible solution exists iff ${\color{blue}d^+}({\color{lime}P}) \ge 0$ for all cycles ${\color{lime}P}$.
  -   Proof sketch (if-part): If ${\color{firebrick}u}$ feasible, for path indicator ${\color{green}\tau}$ of cycle ${\color{lime}P}$, ${\color{green}\tau}^T {\color{blue}y} \le {\color{blue}d^+}({\color{lime}P})$. Since ${\color{green}\tau}^T {\color{blue}y} = {\color{green}\tau}^T ({\color{green}A}{\color{firebrick}u}) = ({\color{blue}A^T} {\color{green}\tau})^T {\color{firebrick}u} = ({\color{blue}\partial} {\color{lime}P})^T {\color{firebrick}u}$, and for a cycle ${\color{blue}\partial} {\color{lime}P} = 0$, we get $0 \le {\color{blue}d^+}({\color{lime}P})$.
-   If infeasible, algorithm returns a **"negative cycle"**.
-   Bounds ${\color{blue}d^-}, {\color{blue}d^+}$ can be $\pm\infty$ or zero.
-   Can be reduced to an elementary problem by adding reverse edges.

-   Example: **Clock skew scheduling**.
  -   Goal: Assign arrival time ${\color{firebrick}u_i}$ to registers to satisfy setup/hold constraints.
  -   ${\color{firebrick}u}$: arrival time, ${\color{blue}y}$: clock skew (${\color{firebrick}u_i} - {\color{firebrick}u_j}$).
  -   Constraints: ${\color{blue}d^-} \le {\color{blue}y} \le {\color{blue}d^+}$.
  -   Finding a **negative cycle** indicates a timing violation that cannot be fixed by adjusting potentials (arrival times).
-   Example: **Delay padding + clock skew scheduling**.
  -   Goal: Insert delay $p$ to satisfy timing.
  -   Formulation: Find $p, {\color{firebrick}u}$ s.t. ${\color{blue}y} \le {\color{blue}d}+p$, ${\color{green}A}{\color{firebrick}u}={\color{blue}y}$, $p \ge 0$.
  -   Can be reduced to feasible potential problem.
  -   A **negative cycle** indicates timing cannot be fixed by _only_ this technique.

---

### Optimal Problems: Finding the Best Solution ✨

-   Find the best solution according to an objective function.

#### Min-cost Flow Problem (MCFP) 💰🌊

-   Find feasible flow ${\color{green}x}$ minimizing a linear cost function.

  -   **Minimize** ${\color{blue}d}^T {\color{green}x} + p$
  -   Subject to: ${\color{green}c^-} \le {\color{green}x} \le {\color{green}c^+}$ and ${\color{blue}A^T} {\color{green}x} = {\color{firebrick}b}$.
  -   Elementary form: $0 \le {\color{green}x} \le {\color{green}c}$ and ${\color{blue}A^T} {\color{green}x} = {\color{firebrick}b}, {\color{firebrick}b}({\color{salmon}V})=0$.

-   Algorithms:

  -   **Successive shortest path algorithm**.
  -   **Cycle cancellation method**: Iteratively add minimal flows according to a **negative cycle of the residual network**.

-   **Primal Method for MCFP:** Based on Descent Method.
  1. Start with a feasible flow ${\color{green}x^*}$.
  2. Find a **negative cycle** ${\color{green}p}$ in graph $G({\color{green}x})$. (Using Bellman-Ford).
  3. Choose step size $\alpha$ (ensures feasibility).
  4. Update flow: ${\color{green}x} := {\color{green}x} + \alpha {\color{green}p}$.
  5. Repeat until no negative cycle found.
  -   Choosing ${\color{green}p}$ as a negative cycle ensures cost ${\color{blue}d}^T {\color{green}x}$ decreases.
  -   If $\alpha$ is unbounded, the problem is unbounded.
  -   Heap or other structures can find negative cycles efficiently.

#### Min-cost Potential Problem (MCPP) 💰⚡️

-   The **dual** of MCFP.
-   Maximize an objective related to potentials and tension bounds.
  -   **Maximize** ${\color{firebrick}b}^T {\color{firebrick}u} - ({\color{green}c}^T {\color{blue}y} + q)$
  -   Subject to: ${\color{blue}d^-} \le {\color{blue}y} \le {\color{blue}d^+}$ and ${\color{green}A}{\color{firebrick}u} = {\color{blue}y}$.
  -   Elementary form: ${\color{blue}y} \le {\color{blue}d}$ and ${\color{green}A}{\color{firebrick}u} = {\color{blue}y}$.
-   Method involves finding **negative cuts**.
  1. Start with a feasible potential ${\color{firebrick}u^*}$.
  2. Find a **negative cut** ${\color{firebrick}q}$ in graph $G({\color{firebrick}u})$.
  3. Update potential: ${\color{firebrick}u} := {\color{firebrick}u} + \beta {\color{firebrick}q}$.
  4. Repeat until no negative cut found.
  -   For linear problems (network simplex), ${\color{firebrick}q}$ is chosen from a spanning tree.
  -   Step size $\beta$ makes one constraint tight.
-   Algorithms for MCFP and MCPP can often solve the dual problem.

#### Special Cases 🎁

-   **Max-flow problem:** Maximize flow source-sink.
  -   Algorithms: **Ford-Fulkerson** (augmented path), **Pre-flow Push-Relabel** (dual method). May be better solved by dual method.
-   **Matching problems:** Edge capacities are.
  -   With bounds: **Edmond's blossom algorithm**.
  -   Bipartite Maximum Cardinality Matching: **Hopcroft-Karp algorithm**.

---

#### Parametric Problems: Optimizing Over a Parameter 🎛️

-   Optimize a parameter subject to constraints.

#### Parametric Potential Problem (PPP) ⚡️🎛️

-   Consider parameter ${\color{royalblue}\beta}$, maximize ${\color{royalblue}\beta}$ subject to:
  -   ${\color{blue}y} \le {\color{olive}d}({\color{royalblue}\beta})$ and ${\color{green}A}{\color{firebrick}u} = {\color{blue}y}$.
  -   ${\color{olive}d}({\color{royalblue}\beta})$ is a monotonic decreasing function.
-   If ${\color{olive}d}({\color{royalblue}\beta}) = m - s{\color{royalblue}\beta}$ (linear, $s \ge 0$) -> **minimum cost-to-time ratio problem**.
-   If $s$ is constant -> **minimum mean cycle problem**.

-   Algorithms for linear ${\color{olive}d}({\color{royalblue}\beta})$:
  -   **Howard's algorithm** (cycle cancellation): "Best guess" for single-parameter PPP.
  -   **Lawler's algorithm** (binary search).
  -   **Young's algorithm** (path based).
  -   **Burns' algorithm** (path based).
  -   Several **hybrid methods**.
  -   Applicable to clock period optimization problem (s is 0 or 1).
-   For **multi-parameter problems**: **ellipsoid method**.

#### Examples of PPP 🕰️

-   **Optimal clock period scheduling**.
-   **Slack maximization**.
-   **Yield-driven clock skew scheduling** (Gaussian, non-Gaussian).
-   **Yield-driven delay padding**: Insert delay with parametric costs.

    ```mermaid
    graph LR
      i((i)) -- "CP-4 - σ*β" --> j((j))
      j -- "1.5 - σ*β" --> i
      %% Caption: Delay insertion with parametric costs related to beta.
    ```

-   **Multi-domain clock skew scheduling** (non-linear ${\color{royalblue}\sigma} {\color{olive}d}({\color{royalblue}\beta})$).

-   Feasibility problems often subproblems in parametric algorithms, solved many times.
-   Data structures (Fibonacci heaps, spanning trees) improve efficiency for finding negative cycles.

---

#### General Tools, Algorithms, & Guidelines 🛠️

-   **Libraries:**
  -   **Python's networkx**. Requires special handling for multi-edges.
  -   **C++'s Boost Graph Library (BGL)**.
-   **General Methods:**

  -   **Descent Method:** Iterative improvement.
  -   Finding **negative cycles** (primal, flow) and **negative cuts** (dual, potential).
  -   **Bellman-Ford** for negative cycles.
  -   Principle applies to **nonlinear problems**.
  -   Transform cost function to non-negative (reverse orientation).
  -   Piece-wise linear convex cost reducible to linear.

-   **Guidelines for Average Users:**
  -   Look for **specialized algorithms** (e.g., Hopcroft-Karp for Bipartite Matching).
  -   **Avoid infinite costs**; delete/reformulate the problem.
-   **Guidelines for Algorithm Developers:**
  -   Make "negative cycles" as **orthogonal** as possible.
  -   **Reuse previous solutions** as starting points.

---

#### Why Study Network Optimization? 🤔👍👎

-   **Why?**

  -   Algorithms are **available** (libraries!).
  -   Explore **locality and associativity**.
  -   Solve **discrete problems optimally**.
  -   Insight into **critical parts** (cuts/cycles).

-   **Why not?**
  -   The theory can be **hard to understand**.
  -   Some algorithms can be **hard to understand** (e.g., requiring reverse flows).
  -   There are **too many algorithms** - wise selection needed.

---

#### Conclusion ✅

-   Network optimization builds on network fundamentals, duality of flow/potential.
-   Addresses Feasibility (existence) and Optimal (best solution) problems.
-   Parametric problems extend optimization over parameters.
-   A core concept across many algorithms is finding **negative cycles** (primal, flow) and **negative cuts** (dual, potential).
-   Powerful tools and libraries are available, but the field requires careful study and selection.

---

#### Q&A 🗣️❓

-   Thank you! Ready for your questions.
