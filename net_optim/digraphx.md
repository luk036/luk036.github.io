layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Understanding the `digraphx` Package 🔀

@luk036 👨‍💻

2025-05-16 📅

---

## 📦 What is Digraphx?

*   A Python package for analyzing **directed graphs**
*   Provides solvers for specific graph problems 🧩
*   Designed for applications like analyzing electrical circuits ⚡ and communication networks 🌐
*   Includes modules for Negative Cycle Finding 🔄, Minimum Cycle Ratio ⚖️, and Parametric Network problems 📈
*   Also includes a lightweight graph data structure (`tiny_digraph`) 🪶

---

## 🕵️‍♀️ Negative Cycle Finding (NCF)

*   Module: `digraphx.neg_cycle` and `digraphx.neg_cycle_q` 🔍
*   **Goal:** Find **negative cycles** in a directed graph where the sum of edge weights is less than zero ⚠️
*   Useful in various applications, such as detecting arbitrage opportunities in currency exchange markets 💱
*   Input: A directed graph with edge weights ➡️
*   Output: A list of cycles (if any negative cycles are found) 🔄

---

## 🧠 NCF Algorithms

*   The code uses two main algorithms:
    *   **Bellman-Ford algorithm** ⏳ A shortest path algorithm that can find single source shortest paths in graphs with negative edge weights. Runs in O(V*E) time.
    *   **Howard's Policy Iteration algorithm** 🔁 An algorithm based on the Bellman-Ford algorithm and Howard's policy improvement. Runs in O(V*E*V') time in the worst case.
*   The `NegCycleFinder` class implements this 🛠️
*   The core logic involves repeatedly relaxing edges and checking for negative cycles 🔄
*   A negative cycle detection is done by checking if a node's distance can still be improved after V-1 relaxations (Bellman-Ford) or during policy iteration (Howard) 🚨

---

## 🔧 NCF Key Components

*   `NegCycleFinder`: The main class for finding negative cycles 🕵️‍♂️
*   `howard(...)`: Implements Howard's algorithm logic for finding negative cycles 🔍
*   `is_negative(handle, dist, get_weight)`: Checks if a cycle is negative by comparing distances between nodes and edge weights ⚖️
*   `relax(dist, pred, get_weight)`: Updates the distance and predecessor dictionaries based on current distances and edge weights 🔄

---

## 📉 Minimum Cycle Ratio (MCR)

*   Module: `digraphx.min_cycle_ratio`
*   **Goal:** Find the cycle in a directed graph with the **smallest ratio of total edge weights to the number of edges** ⚖️
*   Often referred to as finding the "most efficient" or "tightest" cycles 🎯
*   Input: A directed graph represented as a mapping of nodes to their neighbors and edge attributes. Edges are expected to have "cost" and "time" attributes ⏱️💰
*   Output: A tuple containing the **minimum cycle ratio** (a number) and the **cycle itself** (a sequence of edges) 🔢

---

## 📊 MCR Algorithm

*   Uses a **parametric approach** 📈
*   Defines a `CycleRatioAPI` class that calculates distance based on a given ratio and edge information 🧮
*   The main solver `MinCycleRatioSolver` combines this `CycleRatioAPI` with a `MaxParametricSolver` 🤖
*   Starts with an initial ratio and distance mapping for each node 🏁
*   **Iteratively refines the minimum cycle ratio** 🔄
*   The algorithm works by repeatedly adjusting the ratio and recalculating distances 🔧
*   It looks for edges where the sum of distance around the cycle is negative, indicating a better ratio can be found 🔍
*   Continues until no such cycle is found, which means the minimum cycle ratio is determined 🎯

---

## 🧩 MCR Key Components

*   `CycleRatioAPI`: Abstract base class for defining how distance is calculated based on ratio and edge attributes 📐
*   `distance(ratio, edge)`: Calculates distance. Parameters: `ratio` (type `Ratio`), `edge` (type `Edge`). Returns `Ratio` 📏
*   `zero_cancel(cycle)`: Checks if a cycle represents a zero cancellation based on the calculated distance. Parameters: `cycle` (type `List[Edge]`). Returns `Ratio` ❌
*   Important aspect: The code can work with both function-based and floating-point attribute calculation for flexibility 🧘

---

## 📈 Parametric Network Problems

*   Module: `digraphx.min_parametric_q` and `digraphx.parametric`
*   **Goal:** Solve a specific type of **network optimization problem** called "minimum parametric problem". Find the smallest possible value for a parameter (called 'ratio') that satisfies certain conditions in a graph structure 🎯
*   Input: A graph, an initial set of distances, and a starting ratio 🏁
*   Output: The **minimum ratio** and a cycle corresponding to this ratio 🔄
*   Similar to the MCR problem, which is a specific instance of a parametric problem 🔄

---

## 🔄 Parametric Solver Algorithm

*   The `MaxParametricSolver` class implements the main logic 🧠
*   It uses an iterative approach 🔁
*   Key idea: It uses a **Negative Cycle Finder (NCF)** to detect cycles that could potentially improve the ratio 🔍
*   Algorithm steps:
    1.  Start with an initial ratio and distance estimates 🏁
    2.  Use NCF to find cycles in the graph where the distance is negative 🔄
    3.  If a negative cycle is found, calculate a new ratio for that cycle 🆕
    4.  If the new ratio is smaller than the current best, update the best ratio and remember the cycle 💾
    5.  Repeat steps 2-4 until no better ratio can be found 🛑
*   The core relies on the **continuous updating of the ratio** based on cycles found 🔄

---

## 🛠️ Parametric Key Components

*   `ParametricAPI`: An abstract base class defining the interface for calculating distances and handling cycles in the parametric context 📜
*   `distance(ratio, edge)`: Calculates the distance between a given ratio and edge 📏
*   `zero_cancel(cycle)`: Determines if a cycle represents a zero cancellation ❌
*   `MinParametricSolver`: Solves the problem min s.t. dist[v] - dist[u] <= distance(e, r) for all edges 🎯

---

## 💡 TinyDigraph

*   Module: `digraphx.tiny_digraph` 🪶
*   A **lightweight and memory-efficient** custom data structure for representing directed graphs 🏗️
*   Designed particularly for cases where performance and memory efficiency are important ⚡
*   Achieves efficiency by subclassing from `DiGraphAdapter` and using a custom `MapAdapter` dictionary structure for storing node and edge information 🗃️
*   Provides basic methods to initialize the graph, add nodes, add edges, and iterate through graph elements 🔄

---

## 🗺️ Module Relationships

*   The **Parametric** module provides a general framework for solving parametric network problems
*   The **Minimum Cycle Ratio** module is a specific implementation of the Parametric approach, specialized for the cycle ratio definition ⚖️
*   Both Parametric and Minimum Cycle Ratio solvers heavily rely on the **Negative Cycle Finding (NCF)** functionality to guide their iterative process 🔄
*   The **Tiny Digraph** module provides a potential data structure for representing the graphs used by these solvers efficiently 🏗️

---

## 🏁 Summary

*   `digraphx` offers tools for complex directed graph analysis 🧰
*   **Minimum Cycle Ratio**: Finds the most efficient cycles (cost/time ratio) ⚖️
*   **Negative Cycles**: Detects cycles with negative total weight, useful for arbitrage 💰
*   **Parametric Optimization**: Solves general problems involving finding an optimal parameter value based on graph structure
*   Algorithms like Bellman-Ford ⏳, Howard's Policy Iteration 🔁, and iterative NCF are core to the solvers 🧠
*   A custom `TinyDigraph` data structure is available for efficient graph representation 🪶

**GitHub** 🐙: [digraphx](https://github.com/luk036/digraphx) 🔗

---

count: false
class: nord-dark, middle, center

# Q&A 🎤
