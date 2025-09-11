layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Coarse-Grained Reconfigurable Arrays (CGRAs): Architecture, Compilation, and Challenges 🏗️💻

@luk036 👨‍💻

2025-05-08 📅

---

## Credit 🙏

*   **Title:** Coarse-Grained Reconfigurable Arrays (CGRAs): Architecture, Compilation, and Challenges 🏗️💻
*   **Presenters:** 👥 Zhaoying Li, Dhananjaya Wijerathne, and Tulika Mitra (Based on source authors)
*   **Affiliation:** 🏫 National University of Singapore, Singapore
*   **Source:** 📚 Excerpts from "Handbook of Computer Architecture"
*   **Target Audience:** 🎓 Potentially computer architecture students, researchers, or engineers interested in spatial accelerators.
*   **Estimated Time:** ⏳ 42 minutes

---

## Introduction - What is a CGRA? ❓

*   A **promising class of spatial accelerator** 🚀
*   Offers **high performance, energy efficiency, and flexibility** ⚡💎
*   **Bridges the gap** 🌉 between efficient but inflexible domain-specific accelerators (ASICs) and flexible but inefficient general-purpose processors
*   Essentially an **array of word-level processing elements (PEs)** 🔢 connected via on-chip interconnect
*   Both **PEs and interconnect are reconfigurable per cycle** 🔄, driven by on-chip configuration memory
*   **Compiler maps compute-intensive loop kernels** 🗺️ onto the CGRA in a spatio-temporal fashion
*   Goal: **Hardware-like efficiency with software-like programmability** ⚙️💻

---

## Why CGRAs? The Performance Gap

*   **General-Purpose Processors (CPUs):**
    *   Unlimited flexibility, can execute any application ♾️
    *   **Low performance and energy efficiency** 🐢 due to overheads (fetching, decoding, dependencies) and difficulty extracting parallelism from sequential streams
    *   Performance growth limited by **power wall, ILP wall, and memory wall** 🧱 after decades of innovation (Moore's Law, Dennard Scaling, micro-architecture)
*   **Domain-Specific Accelerators (ASICs):**
    *   High performance and energy efficiency for specific tasks (DNNs, image processing, crypto) 🏎️
    *   **Zero flexibility** 🔒 – tied to one task or domain
    *   Feasible only for **ubiquitous tasks** 🌍
    *   Prevalent in modern SoCs (e.g., Apple A8) 📱
*   **Reconfigurable Computing (including CGRAs):**
    *   A **compromise** ⚖️ between the two extremes
    *   ASIC-like efficiency while maintaining flexibility through **software programmability** 💾

---

## CGRAs vs. FPGAs ⚔️

*   **Field-Programmable Gate Arrays (FPGAs):**
    *   Array of configurable logic blocks (computation) and programmable routing resources (interconnect) 🧩
    *   **Fine bit-level granularity** of reconfiguration 🔍
    *   Higher cost in **area (20-35x ASIC), power (10x dynamic power), and delay (3-4x slower)** 🐌 compared to ASICs
    *   Reconfiguration can take a longer time interval ⏳
*   **CGRAs:**
    *   **Coarse-grained functional units** (word-level) 📏
    *   **Per-cycle reconfigurability** 🔄
    *   Achieve **higher performance and lower power** ⚡ compared to FPGAs
    *   Leverage **temporal configuration dimension** (per-cycle) allowing smaller spatial dimensions via time-multiplexing ⏱️
    *   Smaller chip area, thus **lower power** (especially leakage) 💡

---

## CGRA: Basic Components 🧱

*   **Core elements:** Set of Processing Elements (PEs) and an on-chip network 🌐
*   **Per-cycle reconfiguration:** Both PE operations and network routing 🔄
*   **Classic 4x4 CGRA example:** (Refers to Fig 1 in source)
    *   **PEs:** Capable of arithmetic, logic, memory operations 🧮
        *   Includes Functional Unit (FU), small Register File (RF), crossbar switches, and Configuration Memory 💾
        *   Each FU can have ALUs or other units ⚙️
    *   **On-chip network:** Connects PEs 🛣️
    *   **On-chip Data Memory (SPM):** Feeds data to the PE array 🍽️
        *   Data transfer with off-chip memory via DMA 🚚
    *   **Configuration Memory:** Stores per-cycle directives for PE modules (ALU, switches, RF ports) 🗂️

---

## CGRA: Configuration and Execution ⚙️

*   PEs read configurations from memory each cycle 📖
*   **Sequence of configurations** for a limited number of cycles is stored on-chip 🗃️
*   At runtime, this sequence is **repeated cyclically** 🔁
*   CGRA fabric configured in **spatial** (PE count) and **temporal** (configuration sequence length) domains 📐⏱️
*   New configuration sequences can be loaded from external storage (with delay) ⏳
*   High performance from **parallelism** of many PEs 🤝
*   Improved energy efficiency from **simple architecture** faithfully following pre-planned computation/routing by compiler 📝

---

## CGRA: Variations 🔀

*   **Homogeneous vs. Heterogeneous CGRAs:**
    *   **Homogeneous:** All PEs have the same functionality ⚖️
    *   **Heterogeneous:** PEs can have different functionalities 🎭
        *   Useful for specific domains (e.g., MAC for ML) 🤖
        *   Specialized PEs can be costly (area/power) 💰
        *   Heterogeneity often in **memory access** (boundary PEs access SPM) 🧠
        *   Other examples: SFUs for FP32 alongside integer PEs 🔢
        *   Design space exploration frameworks exist for heterogeneous CGRAs (e.g., REVAMP) 🛠️

---

## CGRA: Spatial CGRA 🗺️

*   A special case with **only one configuration word** 1️⃣
*   Area, power, and cycle time reduction (no reconfiguration delay) ⏬
*   More energy-efficient than traditional CGRAs 💡
*   **Lacks the temporal dimension** advantage ⏳
*   Essentially reduces to an FPGA but with coarse-grained units 🧱
*   Limited configuration memory may require **loop partitioning and reloading** for large kernels 🔄

---

## CGRA: On-Chip Network 🌐

*   Connects PEs for data routing 🛣️
*   **Neighbor-to-neighbor (N2N):** Most common, PE connected to neighbors, reaches in one cycle ↔️
    *   Routing distant PEs requires intermediate PEs and multiple cycles 🐢
    *   Simple, but **limited interconnection**, requires great compilation effort
    *   Int. PEs routing transient data cannot compute in the same cycle 🚫
*   **Advanced Network (HyCUBE):**
    *   Single-cycle **multiple-hop connections** create larger virtual neighborhood 🚀
    *   Special **bypass network** allows int. PEs to forward data without consuming it 🎯
    *   Reduces routing delay, improves compilation time & kernel run time ⏱️
    *   Int. PEs in bypass path **can continue executing operations**
    *   Trade-off: Increasing hops per cycle reduces max clock frequency
*   **Scalability for larger CGRAs:** Tiled architectures with higher bandwidth between blocks (e.g., Plasticine) 🧩

---

## CGRA: Memory Hierarchy 🧠

*   Two main types of memory:
    *   **Data Memory:** Input, output, intermediate data
    *   **Configuration Memory:** Configuration directives ⚙️
*   **On-chip Data Memory:**
    *   Typically **multi-bank Scratchpad Memory (SPM)** 🏦
    *   **Fully software-controlled** (compiler manages data movement) 💾
    *   More power-efficient than caches ⚡
    *   Multi-bank increases **data throughput** (parallel access) 🚀
    *   Limited read/write ports per bank 🚪
    *   Often **boundary PEs** have access to banks (Refers to Fig 4 in source) 🏗️
    *   Some architectures use shared RFs between PEs for communication 💬
*   **Configuration Memory (Context/Instruction Memory):**
    *   Holds per-cycle directives for PEs and switches 🗂️
    *   Repeated sequence for accelerating loop kernels 🔁
    *   Loaded before execution ⏳
    *   Can be centralized (global) or decentralized (local per PE) 🌍
    *   PEs execute in lockstep, sharing a program counter 🔢

---

## CGRA: CPU Interface 💻

*   CGRAs are **coupled with a host processor** to execute complete applications 🤝
*   Host CPU responsibilities: non-loop code, CGRA configuration, DMA data transfers 🏗️
*   **Tightly coupled:** CGRA part of main CPU (e.g., ADRES) 🔗
    *   Cannot execute code in parallel on CPU/CGRA 🚫
*   **Loosely coupled:** CGRA is an independent accelerator (e.g., MorphoSys) (Refers to Fig 4 in source) 🪁
    *   Offers more design flexibility 🎮
    *   CPU and CGRA can execute in parallel ⏱️
    *   Higher data transfer overheads

---

## Compilation for CGRAs: The Goal 🎯

*   **Input:** A loop from an application, a CGRA architecture 📥
*   **Output:** Configurations for a fixed number of cycles (the mapping) 📤
*   **Objective:** **Maximize throughput** 🚀
*   Loop represented as a **Dataflow Graph (DFG)**
    *   Nodes = operations, Edges = dependencies ↔️
    *   Exposes computations and data flow 🌊
*   Mapping involves finding **spatio-temporal coordinates** for computations and **routing data dependencies** 🗺️

---

## Compilation for CGRAs: Modulo Scheduling ⏱️

*   A key technique for mapping loop kernels 🔑
*   A **software pipelining technique** 🌀
*   Exploits **instruction-level parallelism (ILP) among loop iterations** 🔄
*   Pipelining consecutive iterations provides more parallelism and improves resource utilization 📈
*   **Mapping has three parts:** (Refers to Fig 5c in source)
    *   **Prologue:** Executed once at start 🏁
    *   **Steady-state kernel:** Repeated, includes operations from one or more iterations 🔁
    *   **Epilogue:** Executed once at end 🏁
*   **Initiation Interval (II):** Schedule length of the steady-state kernel 📏
    *   Number of cycles between initiating consecutive loop iterations 🔢
    *   Dominates execution time for loops with many iterations ⏳
    *   Mapping example shows II=2 (Fig 5c) 2️⃣

---

## Compilation for CGRAs: Minimum II

*   The mapper calculates the **Minimum Initial Interval (MII)** 🧮
*   MII is the **maximum** of:
    *   **Resource-minimal II:** Depends on number of PEs and DFG nodes (Cannot be less than ceil(DFG nodes / PEs))
    *   **Recurrence-minimal II:** Determined by dependencies across loop iterations (e.g., `a[i] = a[i-1] * b[i]`) 🔄
*   Mapping algorithm starts with II = max(Resource MII, Recurrence MII) and increases II if scheduling fails 📈

---

## Compilation for CGRAs: Modulo Routing Resource Graph (MRRG)

*   Proposed by Mei et al. (2003b) 📜
*   Represents **resources and routing for a time-extended CGRA** ⏱️🏗️
*   A directed graph **G_II** for a given II ↔️
*   **Nodes:** Tuple (resource, cycle), where resource is a CGRA component (PE port, network, ALU, etc.) and cycle is time (0 to II-1) ⏳
*   **Edges:** Connection from resource m at cycle t to resource n at cycle t+1 ➡️
*   **Wrapped-around edges:** From cycle II-1 back to cycle 0, representing the cyclical nature of configurations (Refers to Fig 6 in source) 🔄
*   In modulo scheduling, occupying a node (resource, t) implies occupying (resource, t + k*II) for k>0 🔢

---

## CGRA Mapping Approaches Overview 🗺️

*   Three broad classes:
    1.  **Heuristic Approaches:** Customized solutions, meta-heuristics 🔍
    2.  **Mathematical Optimization Techniques:** Formal methods ➗
    3.  **Graph-Theory-Inspired Techniques:** Transform problem into graph formalisms

---

## Heuristic Approaches: Simulated Annealing 🔥

*   Problem-independent meta-heuristic ❄️
*   Used in **DRESC compiler** (Mei et al., 2003b) 🛠️
*   Starts with an initial schedule (satisfying dependencies, possibly resource overuse) 🏁
*   Iteratively reduces resource overuse via **simulated annealing** ♨️
*   Explores different **placement and routing** options 🗺️
*   **Cost function:** Based on total routing cost and resource consumption 💰
*   Can have **long convergence time** for large DFGs ⏳
*   Extensions handle register allocation (e.g., De Sutter et al., 2008; meeting graph)
*   Other works aimed at better cost functions (Hatanaka & Bagherzadeh, 2007; CGRA-ME, Chin et al., 2017) 🎯

---

## Heuristic Approaches: Edge-Centric Modulo Scheduling ↔️

*   Contrast to node-centric scheduling (DRESC) (Refers to Fig 7 in source)
*   **Primary objective: Routing efficiency** rather than operation assignment 🎯
*   **Node-centric:** Places operations first based on heuristic routing cost, then routes edges (Fig 7b) 📍
*   **Edge-centric (EMS):** Routing function contains placement 🗺️
    *   Placement decision made when routing information is discovered 🔍
    *   Picks an edge from a mapped node, starts routing 🛣️
    *   Router searches for empty slot for target operation, temporarily places it, recursively routes other edges (Fig 7c) 🔄
*   Can find solutions **faster** and achieve **better quality** than node-centric ⚡
*   **Greedy nature:** Optimizes for a single edge, can fall into local minima
*   Requires efficient heuristics for assigning priorities 🏆

---

## Heuristic Approaches: Schedule, Place, and Route (SPR) 🗓️📍🛣️

*   A mature mapping tool (Friedman et al., 2009) 🛠️
*   Combines **VLIW-style scheduler** and **FPGA placement/routing algorithms** 🤝
*   Three steps:
    1.  **Scheduling:** Ordering operations in time (Uses Iterative Modulo Scheduling (IMS)) ⏱️
    2.  **Placement:** Assigning operations to FUs (Uses Simulated Annealing, inspired by VPR) 📍
    3.  **Routing:** Mapping data signals using wires/registers (Uses PathFinder and QuickRoute) 🛣️
*   Extends IMS for CGRAs to support configurable interconnects and rescheduling with feedback 🔄
*   Adapts FPGA algorithms (VPR, PathFinder) for CGRA specifics (resource multiplexing, fixed frequency) ⚙️

---

## Heuristic Approaches: List Scheduling 📝

*   Adapted in Bansal et al. (2003) 🛠️
*   **Priority-based heuristic:** Maps data-dependent operations onto spatially close PEs 📍
*   Maintains PE list (topology traversal order) and operation list (scheduling priority, e.g., longest dependency path) 🏆
*   Maps highest priority operation to next available PE if valid route exists ✅
*   **Cycle-by-cycle scheduling:** Schedules on each PE, increments cycle when PE list exhausted ⏱️
*   **Limitation:** Does **not produce software pipelined schedules**, unable to exploit inter-iteration parallelism 🔄

---

## Heuristic Approaches: Evolutionary Algorithm 🧬

*   Fast heuristic using a quantum-inspired evolutionary algorithm ⚛️
*   Uses list scheduling result as starting point 🏁
*   **Q-Bit encoding:** Compactly represents potential mappings, enables fast exploration 🔍
*   Fitness function: Performance (inverse of total latency) ⏱️
*   Limited evaluation on small kernels/CGRAs

---

## Heuristic Approaches: Machine Learning 🤖

*   **RLMap (Liu et al., 2018):** Reinforcement learning 🎮
    *   CGRA mapping as an RL agent problem 🤖
    *   Mapping state = image, action = swap operations on neighbor PEs
    *   Reward function based on cost (interconnect power, PE utilization)
*   **DFGNet (Yin et al., 2017a):** Convolutional Neural Network 🧠
    *   Dual-input NN for DFG (adjacency matrix) and CGRA state (matrix)
    *   Translates mapping to image-based classification 🖼️
    *   **Issue:** Difficulty obtaining abundant training data
*   **LISA (Li et al., 2022):** Graph Neural Network
    *   **Portable framework** for diverse CGRAs 🎒
    *   GNN analyzes DFG to derive mapping labels (e.g., routing resource required, mapping distance) 🏷️
    *   Provides a **global view** 🌍
    *   For new accelerators, GNN retrained to adapt labels 🔄

---

## Math. Optimization Techniques ➗

*   Formal methods for CGRA mapping 📐
*   **Integer Linear Programming (ILP):**
    *   Formalizes mapping as an ILP problem (Ahn et al., 2006; Chin & Anderson, 2018) 📜
    *   ILP formulation includes all requirements and constraints (from DFG and MRRG) 📝
    *   **Highly portable** (CGRA-ME project) 🎒
    *   **Scalability is a huge issue** – only applicable to very simple kernels
    *   Effectiveness for all architectural features is unclear ❓
*   **Boolean Satisfiability (SAT) Solvers:**
    *   Application mapping approach used by Wave Computing for their DPU
    *   Automatically compile dataflow graphs onto a huge CGRA (16,000 PEs)
    *   Innovative application of SAT to solve complex, irregular optimization
    *   Produces **high-quality results** comparable to hand-written assembly
    *   Efficiently utilizes PEs with rich features 💎
    *   Requires **custom algorithms** for scalability and robustness 🛠️
    *   Constraint-based approach also used for Silicon Hive 🐝

---

## Graph-Theory-Inspired Techniques

*   Transform the CGRA mapping problem into **well-known graph-theoretic formulations** ↔️
*   Leverage existing techniques to solve 🛠️
*   Concepts used: Subgraph homeomorphism, Graph epimorphism, Graph minor, Compatibility graph, Graph drawing ✏️

---

## Graph Theory Definitions (For context) 📚

*   **Directed Graph G = (V, E):** Set of vertices V and edges E ↔️
*   **Graph Isomorphism:** Bijective function f: V -> V' such that edges are preserved. Graphs look the same. (Refers to Fig 8) 🔄
*   **Graph Subdivision:** Replacing an edge (u, v) with two edges (u, w) and (w, v) by adding a new vertex w. (Refers to Fig 9) ✂️
*   **Graph Homeomorphism:** Two graphs are homeomorphic if an isomorphism exists between their subdivisions. (Refers to Fig 10) 🏠
*   **Induced Subgraph:** Subgraph formed by a subset of vertices U and all edges from the original graph connecting vertices within U. 🧩

---

## Graph-Theory: Subgraph Homeomorphism 🏠

*   **Definition:** Homeomorphism from an induced subgraph G↓U of G to G' 📖
*   Mapping DFG (G) to MRRG (H_II): Map DFG nodes to MRRG nodes (PEs at certain times) ⏱️
*   DFG edge (u, v) maps to a **path** from f(u) to f(v) in MRRG 🛣️
*   This matches subgraph homeomorphism: the path in MRRG is a "subdivision" of the DFG edge (Refers to Fig 11) ✂️
    *   Routing nodes (R) are added via edge subdivision (Fig 11c) ➕
*   Adopted in Tuhin & Norvell (2008), Alle et al. (2008), Brenner et al. (2009) 📜
*   **Limitation:** Requires edge mappings (paths) to be **node disjoint** (except endpoints) or edge disjoint 🚫
    *   Excludes sharing routing nodes (multi-net), potentially wasting routing resources 💸

---

## Graph-Theory: Graph Epimorphism

*   Based on **Graph Homomorphism:** Function f: V -> V' such that (u,v) in E => (f(u),f(v)) in E'. Maps adjacent vertices to adjacent vertices. Can be from bigger to smaller graph. ↔️
*   **Graph Epimorphism:** Surjective function f: V -> V' (both vertices and edges)
    *   Adjacent vertices in G map to adjacent vertices in G' ↔️
    *   For every edge in G', there's a corresponding edge in G 🔗
*   **EPIMap (Hamzeh et al., 2012):** Formalizes CGRA mapping as epimorphism + **recomputation** 🛠️
    *   **Recomputation:** Same operation can be performed on multiple PEs for better routing 🔄
    *   DFG G is morphed into G' (adding routing/recomputation nodes) ➕
    *   Finds **maximal common subgraph (MCS)** between G' and MRRG H 🔍
    *   If MCS isomorphic to G', valid mapping found ✅
*   Can generate **better scheduling results** compared to EMS (e.g., Fig 12 shows II=2 with recomputation vs. II=3 without) (Refers to Fig 12) 📈

---

## Graph-Theory: Graph Minor

*   **Definition:** Undirected graph G is a minor of G' if G is isomorphic to a graph obtained by edge contractions on a subgraph of G' ✂️
    *   **Edge contraction:** Removes edge, merges connecting vertices 🔗
    *   Adapted for directed graphs for CGRA mapping (Chen & Mitra, 2014) ↔️
*   Test if DFG is a minor of MRRG ✅
*   Edges to be contracted represent routing paths in MRRG 🛣️
*   Mapping algorithm inspired by tree search 🌳
*   **Naturally allows for route sharing**, unlike subgraph homeomorphism (Refers to Fig 13) 🤝
    *   Fig 13 shows reduced routing nodes (shared) compared to homeomorphism ➖

---

## Graph-Theory: Compatibility Graph

*   REGIMap, Hamzeh et al., 2013
*   Formulation for mapping + using registers to minimize II ⏱️
*   Partitions problem: scheduling + integrated placement/register allocation 🧩
*   **Compatibility graph:** Subgraph of DFG x MRRG product ✖️
*   Vertices = (operation, resource) pair (possible mapping pairs) ↔️
*   Edges = compatibility of two mapping pairs 🤝
*   Mapping problem reduced to finding the **largest clique** in the compatibility graph under register constraints 🔍
*   Uses an efficient constructive heuristic 🛠️

---

## Graph-Theory: Graph Drawing

*   SPKM, Yoon et al., 2009
*   Adopts split and push technique (Di Battista et al., 1998) for planar graph drawing ✏️
*   Focuses on **spatial mappings** 🗺️
*   Starts with all DFG nodes in one group (represents one PE) 1️⃣
*   Group is split, nodes pushed to new group ➗
*   Splitting continues until each group has one node (one-to-one mapping to planar CGRA graph) 🎯

---

## Compilation: Table Summary (Optional - for detail) 📋

*   Show Table 1 from the source
*   Lists notable works using graph theory concepts:
    *   Alle et al. (Homeomorphism, Greedy, DFG substructures) 🏠
    *   EpiMap (Epimorphism, Heuristic, Recomputation)
    *   Graph Minor (Graph Minor, Tree search, Route sharing)
    *   RegiMap (Compatibility graph, Max clique, Route sharing/Recomputation) 🤝
    *   SPKM (Graph Drawing, Split and push, Heterogeneous support) ✏️

---

# Other Compilation-Related Issues

---

## Data Access Challenges 🧠

*   Previous computation mapping often ignores **data placement and CPU-CGRA communication** 🚫
*   Assumptions often made: data already in local memory, all PEs access all data memories (infinite bandwidth) ♾️
*   **Reality:**
    *   CGRA local memory (SPM) is **non-uniform access**
    *   Only a **subset of PEs access memory banks** with limited ports (Refers to Fig 14 in source) 🚪
    *   Memory limitations can cause **overall performance degradation** despite high compute utilization
*   Compiler must be **memory-aware** 🧠
    *   Mapping needs awareness of data placement to correctly place load/store operations 📍
    *   Data placement and CGRA mapping are **interdependent** ↔️
    *   Host CPU manages data movement via DMA based on compiler's data placement 🏗️

---

## Memory-Aware Compilation 🧠

*   **Goals:**
    *   Place data without under-utilizing banks 🏦
    *   Consider limited PE-memory connections 🔗
    *   Prevent memory access conflicts ⚔️
    *   Maximize data reuse 🔄

---

## Memory-Aware Compilation 🧠

*   Approaches:
    *   Kim et al. (2010) heuristic: Considers memory params, minimizes duplicate arrays, balances bank utilization, balances computation/transfer time ⚖️
    *   Resolving access conflicts:
        *   Can be solved by **data duplication** or **hardware queues** (higher cost) 💰
        *   Better: Compiler **partitions data** into banks to avoid conflicts 🧩
        *   Kim et al. (2010) maps operations/data to avoid conflicts, uses array clustering and conflict-free scheduling 🎯
        *   Yin et al. (2016a, 2017b) propose conflict-free mapping, joint modulo scheduling and memory partitioning 🧩
        *   Wang et al. (2013): Memory partitioning scheme for multi-dimensional arrays using linear transformation 📐
    *   Memory as a routing resource (Yin et al., 2015): Routing some dependencies through memory can improve performance, divides mapping into subproblems 🧩

---

## Memory Address Generation 🏠

*   Significant portion of loop kernel instructions (20-80%) for address generation
*   **Overhead** in CGRA ⚖️
*   Solution: **Offload address generation** to specialized units 🚀
*   Advocacy for **decoupled access-execute CGRAs**: Memory address generation separated from main computation execution ↔️
    *   Nowatzki et al. (2017): Stream-dataflow, complex memory hierarchy, stream-based interface 🌊
    *   Wijerathne et al. (2019): Software and hardware support for conflict-free access ✅

---

## Nested Loop Mapping 🔄

*   Most approaches focus on single innermost loops 1️⃣
*   Motivation to map **beyond innermost loop**:
    *   More parallelism available 🤝
    *   Avoids host CPU overheads from multiple invocations for imperfect nested loops (pipeline filling/draining, initialization) ⏳

---

## Nested Loop Mapping Approaches 🗺️

*   **Polyhedral-Model-Based (Liu et al., 2013):**
    *   Robust framework for loop transformation 🏗️
    *   Maps innermost two loops 2️⃣
    *   Transforms 2D nested loops to parallelogram iteration domain 📐
    *   Tiles parallelogram, maps operators in each tile to CGRA 🧩
    *   Objective: Reduce execution time by determining tile parameters (uses genetic algorithm) 🧬
*   **Loop Flattening Based (Lee et al., 2014):**
    *   Converts imperfect nests into a single nested loop for single invocation 1️⃣
    *   Overhead: Increased code size 📈
    *   Combines **loop fission** with flattening ✂️
    *   Introduces specialized PE operations: nested iterators, extended accumulator, periodic store ⚙️

---

## Nested Loop Mapping Approaches 🗺️

*   **Systolic-Mapping-Based (HiMap, Wijerathne et al., 2021a,b):**
    *   Hierarchical mapping for **regular multi-dimensional kernels**
    *   Uses systolic mapping as intermediate abstraction 🏗️
    *   Iteration mapped to virtual PE cluster based on space-time matrix ⏱️
    *   Maps operations in each iteration to physical PEs 🏗️
    *   Generates detailed mapping for **unique iterations**, replicates for final mapping 🔄
    *   Fast and scalable for regular kernels ⚡

---

## Nested Loop Mapping under Limited Config Memory 💾

*   Configuration memory size is a constraint 📏
*   Mapping two innermost loops can be limited (Lee et al., 2014 vs. Yin et al., 2016b) 2️⃣
*   Architectural improvements: **Configuration memory as a cache** (Cao et al., 2017; Jafri et al., 2015) 💾
    *   Stores most recently accessed loop nests 🔄
    *   Dynamic caching improves performance by accelerating more segments and minimizing data transfer ⚡
*   **DNestMap (Karunaratne et al., 2018):**
    *   Partitioning and mapping tool 🛠️
    *   Extracts most beneficial code segments from deeply nested loops 🔍
    *   Statically caches them via **spatio-temporal partitioning** ⏱️

---

## Application-Level Mapping 📱

*   An application has multiple kernels (sequential, single loop, nested loops, combinations) 🔄
*   CGRAs can accelerate various kernels by reconfiguring 🔄
*   ASICs target specific kernels, FPGAs map spatially (limited by area, slow reconfiguration for frequent changes) 🐢
*   **CGRA advantage:** Spatio-temporal mapping allows frequent configuration changes per cycle ⏱️
*   **Partitioning between CPU and CGRA:**
    *   Some kernels benefit more from CGRA than others ⚖️
    *   Limited on-chip memory may require main memory for intermediate data 💾
    *   Lee et al. (2015): Profiles kernels, uses **ILP to select kernels** for CGRA vs. CPU ➗
    *   Maximizes CGRA utilization, reduces data transfer 📈
    *   Work focused on small CGRA, didn't explore concurrent kernel execution 🔄

---

## Synchronous Dataflow (SDF) 🌊

*   **SDF:** A suitable representation for application-level mapping 🗺️
*   Has **actors** that consume/produce **tokens** (Refers to Fig 15 in source) 🎭
*   Actor can be sequential code, loop, loop nest, etc. 🔄
*   Needs a **schedule to orchestrate actors** and balance execution while satisfying dependencies ⏱️
    *   Bounded-buffer schedules (e.g., A(BC2)2, AB2C4)
*   **Spatial vs. Spatio-temporal mapping for SDF:** (Refers to Fig 16 in source)
    *   FPGA maps actors spatially, occupying regions throughout (Fig 16a) - hard to balance execution with spatial-only ⚖️
    *   CGRA spatio-temporal mapping provides a **3D space** for scheduling (Fig 16b) - more flexibility 🎮
*   **ChordMap (Li et al., 2021):**
    *   Maps SDF onto CGRA for high throughput 🚀
    *   Uses **divide-and-conquer** to partition SDF and CGRA ✂️
    *   Maps sub-SDFs onto sub-CGRAs iteratively 🔄
    *   Exploits parallelism: inside actors (ILP), among actors/instances, pipeline parallelism among sub-SDFs 🤝

---

## Handling Control Flow 🎛️

*   **Statically scheduled CGRAs:** Rely on **predication** for loops with complex control flow 📝
    *   Translates control flow to dataflow instructions ↔️
    *   Maps both paths of a branch ↔️
    *   Only instructions from taken path execute ✅
    *   Leads to **resource underutilization** (static allocation of unused resources)
*   **4D-CGRA (Karunaratne et al., 2019):**
    *   New execution paradigm for control divergence 🔀
    *   **Semi-triggered execution model:** Hybrid of sequential and triggered ⚡
    *   Compiler places multiple **shards** (portion of a basic block) from mutually exclusive paths on a PE 🧩
    *   Triggers a **specific shard at runtime** ⏱️

---

## Scalable CGRA Mapping 📈

*   **Scalability challenge:** Most approaches fail to generate high-quality mappings in acceptable time for larger CGRAs and complex kernels ⏳
    *   Placement and routing become difficult 🗺️
    *   Many mappers evaluated only on small benchmarks/CGRAs (Refers to Table 2 in source)
    *   SPR (Friedman et al., 2009) is one of the more scalable evaluated on larger kernels/CGRA 🏗️
*   **Panorama (Wijerathne et al., 2022b):**
    *   Fast and scalable mapper for complex DFGs onto larger CGRAs ⚡
    *   **Divide-and-conquer approach** ✂️
    *   Portable solution, can combine with low-level mappers 🎒
    *   **High-level mapping:** Finds DFG node clusters, maps clusters to CGRA PE clusters 🧩
    *   High-level mapping guides lower-level mapping, reduces complexity
*   **HiMap:** Also fast and scalable, but specialized for regular, highly parallel kernels (as discussed earlier) ⚡
*   Similar multi-level parallelism exploration seen in FPGAs 🏗️

---

## Conclusion 🏁

*   **CGRAs:** Emerging general-purpose spatial accelerators 🚀
*   Deliver **high performance, energy efficiency, and flexibility** across application domains ⚡
*   Significant architectural and compilation innovations over two decades have helped realize their potential 🕰️💡
*   Compilation is **key** due to the flexibility and need for spatio-temporal mapping 🔑🗺️
*   Various mapping approaches exist (heuristics, formal methods, graph theory, ML) with different trade-offs in quality, time, and scalability 🔄📊

---

## Future Work and Challenges 🌟

*   Remaining challenges and opportunities:
    *   **Scalability** for more complex applications 📈
    *   Improved **Memory management** 💾
    *   Runtime power management (not detailed in these excerpts) 🔋
    *   Specializations for important and emerging application domains 🏗️📈
*   Active area of research and industry interest 📚🔬

---

count: false
class: nord-dark, middle, center

.pull-left[

# Q&A 🎤

] .pull-right[

![Discussion](figs/questions-and-answers.svg)

]
