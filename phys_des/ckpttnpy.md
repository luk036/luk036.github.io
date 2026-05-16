layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# 🐍 ckpttnpy: A Python Package for Circuit Partitioning 📊✨

@luk036 👨‍💻 · 2026 📅

---

## 🎬 Introduction

- **❓ What is ckpttnpy?**
- A 🐍 Python package for **(hyper)graph partitioning** 🧩🔀.
- Specifically designed for partitioning graphs or circuits into different parts while **minimizing connections** between them 🔗✂️.
- **🎯 Problem Solved:**
- Finds the best way to split a graph into two (bipartitioning) or multiple parts (k-way partitioning) ✂️➗.
- Crucial in applications like 🖥️ circuit design and 🏭 manufacturing 🔌💡.
- Also useful in 🌐 network analysis and 🗜️ data compression 📉.
- **⚙️ Core Algorithm:**
- Often based on the **Fiduccia-Mattheyses (FM)** partitioning algorithm 🔄📈.
- Supports multi-level partitioning (ML) for larger problems 🏗️🔍.

---

### Hypergraph Partitioning Concept

.mermaid[

<pre>
graph TD
    subgraph "Partition A"
        A1[Vertex A1]
        A2[Vertex A2]
        A3[Vertex A3]
    end
    subgraph "Partition B"
        B1[Vertex B1]
        B2[Vertex B2]
    end
    A1 ---|cut| B1
    A2 ---|cut| B2
    A3 --- A2
    B1 --- B2
    style A1 fill:#2196f3
    style A2 fill:#2196f3
    style A3 fill:#2196f3
    style B1 fill:#ff9800
    style B2 fill:#ff9800
</pre>

]

---

### 📚 Key Concepts 🧠

- **📊 Graphs:**
- 🎯 Vertices (nodes) and edges (connections).
- **🕸️ Hypergraphs:**
- A generalization where an edge can connect more than two vertices (called a net) 🔌🌐.
- ckpttnpy primarily works with hypergraphs.
- Represents connections between module pins in electronic circuits 🔋🔗.
- **⚖️ Circuit Partitioning:**
- Dividing the vertices of a graph or hypergraph into disjoint sets (partitions).
- 🎯 Goal: Minimize the number of connections cut between partitions while satisfying constraints ✂️📏.
- Often involves balancing the size or weight of partitions ⚖️🔢.

---

### 🧠 Core Algorithms

- **🔄 Fiduccia-Mattheyses Algorithm:**
- An iterative improvement algorithm for graph partitioning.
- Starts with an initial partition.
- Repeatedly moves vertices between partitions to improve a metric (gain).
- **📈 Gain:**
- Represents the **change in cut connections** (or total cost) when a vertex is moved.
- 📉 Positive gain means improvement (fewer cuts).
- **🪣 Gain Bucket:**
- A data structure (often a list or dictionary) that stores vertices based on their current gain.
- Allows quick selection of the vertex with the highest gain to move.

---

- **🔄 Key Steps (Simplified):**
- 1️⃣ Initialize gains for all vertices.
- 2️⃣ Put vertices into gain buckets.
- 3️⃣ Repeatedly select the **best unlocked vertex** (highest gain) from the gain bucket.
- 4️⃣ Move the selected vertex.
- 5️⃣ Update the gains of affected neighbors.
- 6️⃣ 🔒 Lock the moved vertex (cannot be moved again in this pass).
- 7️⃣ Keep track of the best partition found during the pass.
- 8️⃣ After all vertices are moved or no beneficial moves are possible, restore the best partition state.
- 9️⃣ Repeat passes until no further improvement is made.

---

### FM Algorithm Flow

.mermaid[
<pre>
graph LR
    INIT[Initialize Gains] --> BUCKET[Gain Buckets]
    BUCKET --> SELECT[Select Best Unlocked Vertex]
    SELECT --> MOVE[Move Vertex]
    MOVE --> UPDATE[Update Neighbor Gains]
    UPDATE --> LOCK[Lock Vertex]
    LOCK --> CHECK{"All vertices moved\n or no improvement?"}
    CHECK -->|No| SELECT
    CHECK -->|Yes| RESTORE[Restore Best Partition]
    RESTORE --> PASS{Further improvement?}
    PASS -->|Yes| INIT
    PASS -->|No| DONE[Done]
    style INIT fill:#4caf50
    style BUCKET fill:#2196f3
    style SELECT fill:#ff9800
    style MOVE fill:#f44336
    style UPDATE fill:#2196f3
    style LOCK fill:#9c27b0
    style CHECK fill:#f44336
    style RESTORE fill:#ff9800
    style PASS fill:#f44336
    style DONE fill:#4caf50
</pre>
]

---

### ⚖️ Managing Gains 📊🔢

- **`ckpttnpy.FMBIgainCalc`:**
- Calculates the **bipartition gain** in the Fiduccia-Mattheyses algorithm.
- Used for partitioning into **two** parts.
- Handles different types of nets (connections): 2️⃣-pin, 3️⃣-pin, and general nets.
- Calculates gain for moving a vertex based on how the move affects connections.
- Uses simple arithmetic operations (➕ adding/➖ subtracting weights) to calculate gains.
- Methods include `init` (reinitialize data/cost), `update_move_2pin_net`, `update_move_3pin_net`, `update_move_general_net`.

---

- **`ckpttnpy.FMWayGainCalc`:**
- Calculates gain values for **k-way partitioning** in the FM algorithm.
- Used for partitioning into **more than two** parts.
- Similar to FMBIgainCalc, it handles different net types (2-pin, 3-pin, general) and updates gains based on move effects.
- Methods include `init`, `update_move_2pin_net`, `update_move_3pin_net`, `update_move_general_net`, `update_move_init`.

---

### 🛠️ Managing the Process 🔄🔧

- **`ckpttnpy.FMBIgainMgr`:**
- Designed to **manage gains** in graph bipartitioning.
- Uses the gain bucket data structure.
- Keeps track of "gains" associated with moving vertices.
- Supports selecting the best vertex to move, locking vertices, and modifying keys in the gain bucket.
- Implements the logic flow for repeatedly selecting and moving vertices.
- Methods include `init` (setup buckets, calculate initial gain), `lock`, `lock_all`, `modify_key`, `update_move_v`.

---

- **`ckpttnpy.FMWayGainMgr`:**
- Designed to **manage gains** in k-way partitioning.
- Takes a `GainCalc` object, hypergraph, and number of partitions as input.
- Provides methods to initialize, update, and manage gains for partitions.
- Uses gain buckets for each partition.
- Supports locking cells, selecting best moves, and updating gain values.
- Methods include `init`, `lock`, `lock_all`, `modify_key`, `update_move_v`.

---

### ⚠️ Handling Constraints ⚖️🔒

- **Constraint Management:** Ensures the partitioning process adheres to specific rules.
- Common constraints include maintaining balance between partition weights.
- **`ckpttnpy.FMConstMgr`:**
- Manages **constraints** in a graph partitioning algorithm.
- Specifically handles constraints like balancing weight differences between parts.
- Tracks weight differences and updates them after moves.
- Calculates the lower bound for the weight difference.
- Uses a `LegalCheck` enum to describe move outcomes (e.g., `Satisfied`, `GetBetter`, `NotSatisfied`).
- Methods include `init` (set up initial differences), `check_constraints` (check if a move is legal).

---

- **`ckpttnpy.FMWayConstMgr`:**
- Manages constraints in a **k-way partitioning** algorithm.
- Designed to manage constraints such as unbalancing limits or module weights.
- Determines if a proposed move is "legal".
- Reports the status of the move (`LegalCheck.AllSatisfied`, `LegalCheck.Satisfied`, `LegalCheck.NotSatisfied`).
- Supports selecting the partition with the smallest current weight difference from the ideal.
- Methods include `init`, `check_legal`.

---

### 💾 Partition State Management

- **`ckpttnpy.FMPartMgr`:**
- Manages **taking snapshots** of partition states and **restoring** them.
- Useful for saving the current state during optimization.
- Allows reverting to a previous, potentially better, state.
- Supports different partition data structures (dictionaries, lists).
- Methods: `take_snapshot` (creates a copy of the current partition) and `restore_part_info` (updates partition attributes from a snapshot).

---

- **`ckpttnpy.PartMgrBase`:**
- A **base class** providing a foundation for managing partitions.
- Designed for Fiduccia-Mattheyses partitioning algorithms.
- Takes gain manager, constraint manager, and possibly a constructor manager as inputs.
- Initializes the process, sets up total cost and constraint validator.
- Includes core optimization logic: iteratively selecting and moving vertices, checking legality, and tracking the best solution.
- Uses abstract methods for `take_snapshot` and `restore_part_info`, which are implemented by subclasses like `FMPartMgr`.
- Includes methods like `legalize` (perform legalization process), `optimize` (iteratively improve partition).

---

### ✨ Multi-Level Partitioning

- **`ckpttnpy.MLPartMgr`:**
- Manages **multi-level partitioning**.
- A technique to solve large problems by breaking them into smaller, more manageable parts.
- Often used in conjunction with FM algorithms (MLFM).
- **Multi-Level Approach (Simplified):**
- 1️⃣ **Coarsening:** Successively contracts the hypergraph into smaller versions.
- 2️⃣ **Initial Partitioning:** Partitions the smallest (coarsest) hypergraph.
- 3️⃣ **Uncoarsening/Refinement:** Projects the partition back to larger hypergraphs, refining the partition at each level using a local optimization (like FM).

---

### Multi-Level Partitioning Flow

.mermaid[

<pre>
graph TD
    H0[Original Hypergraph G0] --> C1[Coarsen G1]
    C1 --> C2[Coarsen G2]
    C2 --> Ck[Coarsest Gk]
    Ck --> IP[Initial Partition]
    IP --> U1[Uncoarsen + Refine Gk-1]
    U1 --> U2[Uncoarsen + Refine Gk-2]
    U2 --> U0[Final Partition G0]
    style H0 fill:#2196f3
    style C1 fill:#4caf50
    style C2 fill:#4caf50
    style Ck fill:#4caf50
    style IP fill:#ff9800
    style U1 fill:#9c27b0
    style U2 fill:#9c27b0
    style U0 fill:#f44336
</pre>

]

---

- **Components Used:**
- Uses helper classes like `GainCalc`, `GainMgr`, `ConstrMgr`, `PartMgr` to manage gains, constraints, and partition states at each level.
- **`run_FMPartition` function:** Performs an FM partitioning algorithm on a hypergraph based on module weights and balancing constraints. Returns the value of the `legalcheck`.

---

### 🏗️ Hierarchical Netlists 🔌🌐

- **`ckpttnpy.HierNetlist`:**
- Designed to manage a **hierarchical electronic circuit netlist**.
- A netlist describes how components in a circuit are connected.
- Hierarchical structures handle nested or grouped components.
- **Functionality:**
- Stores additional information about the netlist structure.
- Tracks clusters (groups of components), weights of nets (importance/strength), and mapping between levels.
- Provides methods for performing operations on the netlist.
- **Included Functionality:**
- Calculating the degree/connections of a component.
- Finding the maximum degree.
- Projecting partitions between different levels of the hierarchy.
- Retrieving net weights.
- Methods include `get_degree`, `get_max_degree`, `get_net_weight`, `projection_down`, `projection_up`.

---

### 🤝 Clustering/Minimum Cover 🧩

- **`ckpttnpy.min_cover`:**
- Implements a **clustering algorithm** for graph contraction.
- Used in circuit design and optimization.
- Main purpose is to simplify a complex graph (or hypergraph) by **grouping together connected nodes (called modules) into clusters**.
- This process helps reduce the complexity of the network while maintaining its essential structure.
- **Algorithm Steps (Simplified):**
- 1️⃣ Find a maximum matching in the graph.
- 2️⃣ Pair nodes based on the matching.
- 3️⃣ Construct new clustered nodes representing the pairs.
- 4️⃣ Update connections and weights.
- 5️⃣ Repeat until the graph is sufficiently simplified.
- Methods like `construct_bipartite_graph` and `construct_subgraph` are used in this process.

---

### Clustering / Minimum Cover Flow

.mermaid[

<pre>
graph TD
    G[Original Graph] --> MATCH[Find Maximum Matching]
    MATCH --> PAIR[Pair Connected Nodes]
    PAIR --> CLUSTER[Construct Clustered Nodes]
    CLUSTER --> UPDATE[Update Connections & Weights]
    UPDATE --> SIMPLE{Simplified enough?}
    SIMPLE -->|No| MATCH
    SIMPLE -->|Yes| DONE[Coarsened Graph]
    style G fill:#2196f3
    style MATCH fill:#4caf50
    style PAIR fill:#ff9800
    style CLUSTER fill:#9c27b0
    style UPDATE fill:#2196f3
    style SIMPLE fill:#f44336
    style DONE fill:#4caf50
</pre>

]

---

### ✨ Summary and Applications

- ckpttnpy provides a **flexible framework** for solving graph/hypergraph partitioning problems.
- Supports both **binary and k-way partitioning**.
- Offers specific components for:
- Calculating and managing gains (`*GainCalc`, `*GainMgr`).
- Handling constraints (`*ConstMgr`).
- Managing partition states (`FMPartMgr`, `PartMgrBase`).
- Implementing multi-level approaches (`MLPartMgr`).
- Representing hierarchical structures (`HierNetlist`).
- Clustering (`min_cover`).
- **Applications:**
- **Circuit Design and Layout:** Minimizing connections is key for manufacturability and performance.
- **Network Analysis:** Partitioning networks efficiently.

**GitHub** 🐙: [ckpttnpy](https://github.com/luk036/ckpttnpy) 🔗

---

class: nord-dark, middle, center

## Q&A 🎤
