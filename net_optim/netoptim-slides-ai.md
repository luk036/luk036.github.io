# Network Optimization: A Quick Start ⚡️

## Introduction 👋

*   Network optimization uses mathematical techniques to solve problems modeled on networks or graphs.
*   It's a **vital field** with many applications.
*   Goals include:
    *   Exploring the **locality and associativity** of a network.
    *   Solving **discrete optimization problems optimally** (e.g., matching/assignment).
    *   Gaining insight into the **most critical parts** of the network (critical cut/cycle).
*   This presentation provides a quick guide to the algorithms and concepts.

---

## Network Fundamentals: Building Blocks 🏗️

*   A network (or graph) is a collection of finite-dimensional vector spaces with **nodes** (${\color{salmon}V}$) and **edges** (${\color{lime}E}$).
    *   $V = \{v_1, \ldots, v_N\}$, $|{\color{salmon}V}| = N$
    *   ${\color{lime}E} = \{e_1, \ldots, e_M\}$, $|{\color{lime}E}| = M$
*   Key requirements: boundary of each edge is union of nodes; intersection of two edges is empty or a boundary node.
*   This definition allows **self-loops and multi-edges**.
*   The graph structure encodes **neighborhood information**.

---

## Network Fundamentals: Orientation 🧭
**Orientation:** Edges have orientation defining a source ($s$) and target ($t$) node.
*   Note: Orientation $\ne$ Direction.
*   Coherent orientations are the same.

---

## Network Fundamentals: Representation 📝
*   **Node-edge Incidence Matrix ($A^T$)**: An $N \times M$ matrix.
    $$ A(i, j) = \begin{cases} +1 & \text{if } e_j \text{ is coherent with } v_i \\ -1 & \text{if } e_j \text{ is not coherent with } v_i \\ 0 & \text{otherwise} \end{cases} $$
    Example Matrix:
    $$ A^T = \begin{bmatrix} 0 & -1 & 1 & 0 & 0 \\ -1 & 1 & 0 & -1 & -1 \\ -1 & 0 & -1 & 0 & 1 \end{bmatrix} $$
    *   This matrix captures node-edge relationships and orientation.
*   **Adjacency List:** Most efficient for practical implementation.

---

## Network Fundamentals: Abstract Concepts 🧠
*   **Chain ($\tau$)**: An edge/node tuple assigning coefficients. Can be an oriented indicator vector.
*   **Discrete Boundary Operator ($\partial = A^T$)**.
*   **Cycle**: A chain $\tau$ in the null-space of $\partial$, $A^T \tau = 0$.
*   **Boundary**: A chain $\beta$ in the range of $\partial$, $\beta = A^T \tau$.
*   **Co-boundary Operator ($d = A$)**. Also called the differential operator.
*   Null-space of $A$ relates to the number of graph components.

---

## Flow and Potential: Dual Perspectives 🤝

*   Two central, often **dual**, concepts describe network state.

*   **Flow ($x$), Current:** Quantity moving through edges.
    *   Key property: **Sum of $x_{ij}$ around a node is zero** (conservation).
    *   **Divergence:** $div \ x = A^T x$.
    *   A vector $x$ is a **flow** if $\sum div \ x = 0$ (sources/sinks).
    *   A network is a **circulation** if $div \ x = 0$ (no sources/sinks).

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

*   **Potential ($u$), Voltage:** Scalar values associated with nodes.
    *   **Tension ($y$)**: Difference in potential across an edge.
    *   $y = Au$. Tension is a differential of potential.
    *   Key property: **Sum of $y_{ij}$ around a cycle is zero**.

    ```mermaid
    graph LR
        A((v1)) -- y12 --> B((v2))
        B -- y24 --> D((v4))
        D -- y43 --> C((v3))
        C -- y31 --> A
        %% Cycle A -> B -> D -> C -> A. Sum of tensions y12 + y24 + y43 + y31 = 0.
    ```

*   **Duality & Theorems:**
    *   **Tellegen's Theorem:** Flow and tension are **bi-orthogonal** (isomorphic).
        *   $0 = [A^T x, u] = (A^T x)^T u = x^T (Au) = x^T y$.
    *   **Discrete Stokes' Theorem:** $[\tau, A \omega] = [A^T \tau, \omega]$. Relates integration over surface to boundary.
    *   **Fundamental Theorem of Calculus (discrete):** $[A^T \tau_1, c^0] = [A \tau_1, c^0]$.

*   **Path & Cut:**
    *   **Path ($P$)**: Edge sequence. Path indicator vector $\tau$.
        *   Total tension on $P$ = total potential difference on boundary of $P$: $y^T \tau = u^T (\partial P)$.
    *   **Cut ($Q$)**: Edge set separating two node sets $S, S'$. Cut indicator vector $q = Ac$.
        *   Total divergence of flow on $S$ = total flow across $Q$: $(div \ x)^T c = x^T q$.

    ```mermaid
    graph LR
        A((S)) -- Cut Q --> B((S'))
        A --> C
        D --> B
        C -- Cut Q --> D
        %% Caption: A cut Q separating node set S from S'.
    ```

*   **Critical Structures:** Finding **negative cycles** and **negative cuts** is crucial for many algorithms.

---

## Feasibility Problems: Can a Solution Exist? 🤔

*   Ask if a solution exists satisfying constraints.

### Feasible Flow Problem 🌊

*   Find a flow $x$ subject to:
    *   **Capacity constraints:** $c^- \le x \le c^+$.
    *   **Balance constraints:** $A^T x = b$ ($b$ is supply/demand, $b(V)=0$ for circulation).
*   Solved using the **Painted network algorithm**.
*   **Feasibility Condition:** A feasible solution exists iff $b(S) \le c^+(Q)$ for all cuts $Q = [S, S']$.
    *   Proof sketch (if-part): If $x$ feasible, for cut $q=Ak$, $q^T x \le c^+(Q)$. Since $q^T x = (Ak)^T x = k^T (A^T x) = k^T b = b(S)$, then $b(S) \le c^+(Q)$.
    *   The "only-if" part is constructive (an algorithm finds solution).
*   If infeasible, algorithm returns a **"negative cut"**.
*   Bounds $c^-, c^+$ can be $\pm\infty$ or zero. Most tools require $c^-=0$ for positive flow.
*   Can be reduced to an elementary problem by splitting edges.

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

*   Example: **Genome-scale reaction networks** (A is stoichiometric matrix S, x is reaction rates, $c^-$/c$^+$ bounds).

### Feasible Potential Problem ⚡️

*   Find node potentials $u$ subject to:
    *   **Tension constraints:** $d^- \le y \le d^+$.
    *   **Potential definition:** $Au = y$.
*   Solved using the **Bellman-Ford algorithm**. Finds shortest paths, detects negative cycles.

    ```python
    # Basic Bellman-Ford Algorithm Structure
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
*   **Feasibility Condition:** A feasible solution exists iff $d^+(P) \ge 0$ for all cycles $P$.
    *   Proof sketch (if-part): If $u$ feasible, for path indicator $\tau$ of cycle $P$, $\tau^T y \le d^+(P)$. Since $\tau^T y = \tau^T (Au) = (A^T \tau)^T u = (\partial P)^T u$, and for a cycle $\partial P = 0$, we get $0 \le d^+(P)$.
*   If infeasible, algorithm returns a **"negative cycle"**.
*   Bounds $d^-, d^+$ can be $\pm\infty$ or zero.
*   Can be reduced to an elementary problem by adding reverse edges.

*   Example: **Clock skew scheduling**.
    *   Goal: Assign arrival time $u_i$ to registers to satisfy setup/hold constraints.
    *   $u$: arrival time, $y$: clock skew ($u_i - u_j$).
    *   Constraints: $d^- \le y \le d^+$.
    *   Finding a **negative cycle** indicates a timing violation that cannot be fixed by adjusting potentials (arrival times).
*   Example: **Delay padding + clock skew scheduling**.
    *   Goal: Insert delay $p$ to satisfy timing.
    *   Formulation: Find $p, u$ s.t. $y \le d+p$, $Au=y$, $p \ge 0$.
    *   Can be reduced to feasible potential problem.
    *   A **negative cycle** indicates timing cannot be fixed by *only* this technique.

---

## Optimal Problems: Finding the Best Solution ✨

*   Find the best solution according to an objective function.

### Min-cost Flow Problem (MCFP) 💰🌊

*   Find feasible flow $x$ minimizing a linear cost function.
    *   **Minimize** $d^T x + p$
    *   Subject to: $c^- \le x \le c^+$ and $A^T x = b$.
    *   Elementary form: $0 \le x \le c$ and $A^T x = b, b(V)=0$.

*   Algorithms:
    *   **Successive shortest path algorithm**.
    *   **Cycle cancellation method**: Iteratively add minimal flows according to a **negative cycle of the residual network**.

*   **Primal Method for MCFP:** Based on Descent Method.
    1.  Start with a feasible flow $x^*$.
    2.  Find a **negative cycle** $p$ in graph $G(x)$. (Using Bellman-Ford).
    3.  Choose step size $\alpha$ (ensures feasibility).
    4.  Update flow: $x := x + \alpha p$.
    5.  Repeat until no negative cycle found.
    *   Choosing $p$ as a negative cycle ensures cost $d^T x$ decreases.
    *   If $\alpha$ is unbounded, the problem is unbounded.
    *   Heap or other structures can find negative cycles efficiently.

### Min-cost Potential Problem (MCPP) 💰⚡️

*   The **dual** of MCFP.
*   Maximize an objective related to potentials and tension bounds.
    *   **Maximize** $b^T u - (c^T y + q)$
    *   Subject to: $d^- \le y \le d^+$ and $Au = y$.
    *   Elementary form: $y \le d$ and $Au = y$.
*   Method involves finding **negative cuts**.
    1.  Start with a feasible potential $u^*$.
    2.  Find a **negative cut** $q$ in graph $G(u)$.
    3.  Update potential: $u := u + \beta q$.
    4.  Repeat until no negative cut found.
    *   For linear problems (network simplex), $q$ is chosen from a spanning tree.
    *   Step size $\beta$ makes one constraint tight.
*   Algorithms for MCFP and MCPP can often solve the dual problem.

### Special Cases 🎁

*   **Max-flow problem:** Maximize flow source-sink.
    *   Algorithms: **Ford-Fulkerson** (augmented path), **Pre-flow Push-Relabel** (dual method). May be better solved by dual method.
*   **Matching problems:** Edge capacities are.
    *   With bounds: **Edmond's blossom algorithm**.
    *   Bipartite Maximum Cardinality Matching: **Hopcroft-Karp algorithm**.

---

## Parametric Problems: Optimizing Over a Parameter 🎛️

*   Optimize a parameter subject to constraints.

### Parametric Potential Problem (PPP) ⚡️🎛️

*   Consider parameter $\beta$, maximize $\beta$ subject to:
    *   $y \le d(\beta)$ and $Au = y$.
    *   $d(\beta)$ is a monotonic decreasing function.
*   If $d(\beta) = m - s\beta$ (linear, $s \ge 0$) -> **minimum cost-to-time ratio problem**.
*   If $s$ is constant -> **minimum mean cycle problem**.

*   Algorithms for linear $d(\beta)$:
    *   **Howard's algorithm** (cycle cancellation): "Best guess" for single-parameter PPP.
    *   **Lawler's algorithm** (binary search).
    *   **Young's algorithm** (path based).
    *   **Burns' algorithm** (path based).
    *   Several **hybrid methods**.
    *   Applicable to clock period optimization problem (s is 0 or 1).
*   For **multi-parameter problems**: **ellipsoid method**.

### Examples of PPP 🕰️

*   **Optimal clock period scheduling**.
*   **Slack maximization**.
*   **Yield-driven clock skew scheduling** (Gaussian, non-Gaussian).
*   **Yield-driven delay padding**: Insert delay with parametric costs.

    ```mermaid
    graph LR
        i((i)) -- "CP-4 - σ*β" --> j((j))
        j -- "1.5 - σ*β" --> i
        %% Caption: Delay insertion with parametric costs related to beta.
    ```

*   **Multi-domain clock skew scheduling** (non-linear $\sigma d(\beta)$).

*   Feasibility problems often subproblems in parametric algorithms, solved many times.
*   Data structures (Fibonacci heaps, spanning trees) improve efficiency for finding negative cycles.

---

## General Tools, Algorithms, & Guidelines 🛠️

*   **Libraries:**
    *   **Python's networkx**. Requires special handling for multi-edges.
    *   **C++'s Boost Graph Library (BGL)**.
*   **General Methods:**
    *   **Descent Method:** Iterative improvement.
    *   Finding **negative cycles** (primal, flow) and **negative cuts** (dual, potential).
    *   **Bellman-Ford** for negative cycles.
    *   Principle applies to **nonlinear problems**.
    *   Transform cost function to non-negative (reverse orientation).
    *   Piece-wise linear convex cost reducible to linear.

*   **Guidelines for Average Users:**
    *   Look for **specialized algorithms** (e.g., Hopcroft-Karp for Bipartite Matching).
    *   **Avoid infinite costs**; delete/reformulate the problem.
*   **Guidelines for Algorithm Developers:**
    *   Make "negative cycles" as **orthogonal** as possible.
    *   **Reuse previous solutions** as starting points.

---

## Why Study Network Optimization? 🤔👍👎

*   **Why?**
    *   Algorithms are **available** (libraries!).
    *   Explore **locality and associativity**.
    *   Solve **discrete problems optimally**.
    *   Insight into **critical parts** (cuts/cycles).

*   **Why not?**
    *   The theory can be **hard to understand**.
    *   Some algorithms can be **hard to understand** (e.g., requiring reverse flows).
    *   There are **too many algorithms** - wise selection needed.

---

## Conclusion ✅

*   Network optimization builds on network fundamentals, duality of flow/potential.
*   Addresses Feasibility (existence) and Optimal (best solution) problems.
*   Parametric problems extend optimization over parameters.
*   A core concept across many algorithms is finding **negative cycles** (primal, flow) and **negative cuts** (dual, potential).
*   Powerful tools and libraries are available, but the field requires careful study and selection.

---

## Q&A 🗣️❓

*   Thank you! Ready for your questions.
