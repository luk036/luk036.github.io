layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

## FPGA Routing: A Deep Dive

@luk036 👨‍💻

2025-05-28 📅

---

## 🎯 Introduction - What is FPGA Routing? 🤔

*   **The Goal:** Connect the logic blocks placed on an FPGA. 🔌
*   **Why it Matters:** ⚡
    *   Most FPGA area is dedicated to interconnect. 🏗️
    *   Interconnection delays are often greater than logic delays. ⏳
    *   Efficient routing is **critical** for circuit performance (speed) and area. 🚀
*   **It's Complex!** Routing is an **NP-complete problem** 🤯, meaning there's no known polynomial-time algorithm to solve it optimally.
*   The problem is also highly **architecture dependent**. 🏛️

---

## ⚙️ Routing in the FPGA CAD Flow 🔄

*   Routing is the **final major step** before implementation. ✅
*   The overall process from RTL description: 📜
    1.  **Logic Optimization:** Minimize Boolean equations for area/delay. ✂️
    2.  **Technology Mapping:** Transform equations into FPGA logic blocks (optimizing area/delay). 🗺️
    3.  **Placement:** Assign specific locations for logic blocks, aiming to minimize total interconnect length. 📍
    4.  **Routing:** Connect logic blocks using available FPGA routing resources. 🛣️

---

## 🗺️ FPGA Architecture Overview (Xilinx Island Style) 🏝️

*   A 2D array of **Configurable Logic Blocks (CLBs)**. 🔲
*   **Routing Channels:** Horizontal and vertical channels between CLB rows/columns. ↔️↕️
*   **Routing Resources:** (Clock net usually has dedicated routing) ⏰
    1.  **Connection Boxes (C boxes):** Connect channel wires to CLB pins. 🔗
        *   **Flexibility (Fc):** Number of wires a pin can connect to. 🧘
        *   **Topology:** Switch pattern affects connections. 🕸️
    2.  **Switch Boxes (S boxes):** Allow wires to switch between channels (vertical/horizontal). 🔀
        *   **Flexibility (Fs):** Number of other segments a segment entering can connect to. 🎭
        *   **Topology:** Crucial for routability even with same Fs. 🗝️
        *   **Types:** Planar/Subset (same domain) vs. **Wilton** (any domain, greater flexibility). 🌐

---

## 🛣️ FPGA Architecture Overview (Wire Types) 🧵

*   Different wire lengths for different connection needs: 📏
    3.  **Single-length lines:** Short connections, span one CLB. 📍
    4.  **Double-length lines:** Moderately long connections, span two CLBs, lower delay. 📏
    5.  **Long lines:** Connecting several CLBs with low skew, suitable for clocks/globals (though clock has dedicated). ⏱️
*   Increasing flexibility (Fc, Fs, wires per channel) makes routing trivial but **wastes area** and **increases delay** due to more interconnect transistors. 💸
*   Router must work within **fixed resources**, managing congestion and potentially requiring placement changes if unroutable after iterations. 🚧
*   **Routability detection** is desirable to avoid long unroutable iterations. 🔍

---

## 📚 Academic FPGA Model vs. Commercial 🏫 vs 🏢

*   Academic research often uses a **simplified island style model**. 🎓
*   **Reasons:** Based on Xilinx's dominant market share, while other major players (Altera, Actel) use different approaches. 🏆
*   **Academic Model Simplifications:** ✂️
    *   Logic blocks: 4 inputs, 1 output, all alike (Commercial: 3-7 inputs, ≥2 outputs). 🔢
    *   C box: Pass transistors allowing **input pin doglegs** (Commercial: Multiplexers, no doglegs). 🐕
    *   Wire segments: Span only one logic block before terminating (Commercial: Double/Long wires to speed connections and avoid C/S box congestion). 🚀

---

## 🧠 Routing Problem Phases 🧩

*   Routing is typically divided using **divide and conquer**. ✂️
*   **Two Phases:** 🔢
    1.  **Global Routing:** Balances channel densities, finds coarse path through channels. 🌍
        *   Breaks multi-terminal nets into two-terminal sets. ✂️
        *   Considers multiple routes, chooses least congested channel path.
        *   Tracks channel usage to avoid congestion. 📊
        *   Optimized by rip up and re-route. ♻️
    2.  **Detailed Routing:** Assigns specific wiring segments (wires, C/S boxes) within the global route's channels. 🔍
        *   Constructs a directed graph of routing resources. 🕸️
        *   Searches for paths, often using **Dijkstra's algorithm** variant. 🛣️
        *   Uses a cost function considering wire usage, distance (Manhattan metric, often relaxed). 💰
*   **Mixed Routing:** Some algorithms combine phases for higher integration, but less scalable for large circuits. 🤝

---

## 🤖 Detailed Routing (Maze) 🧩

*   **Maze Router:** 🏰
    *   Based on **wavefront expansion**. 🌊
    *   Finds shortest path between two points, avoiding used resources. 🎯
    *   Iterative process with rip up and re-route to handle congestion. ♻️
    *   **Drawback:** Net ordering dependent. Doesn't consider future nets, a chosen path might block subsequent routes. ⚠️

---

## 🤖 Detailed Routing (A\*) 🧩

*   **A\* Search Routing:** 🌟
    *   Maze routing is a special case of A\*. 🎓
    *   Allows tuning the search between: 🎛️
        *   **Breadth-First Search (BFS):** Exhaustive, finds best path, can be slow. 🐢
        *   **Depth-First Search (DFS):** Faster, may not find minimum cost path. 🐇
    *   Uses a cost function: `fi = (1 − α) × (fi−1 + ci) + α × di`. 📊
        *   `fi-1`: previous path cost. ⏮️
        *   `ci`: node cost (current usage, penalizes occupied nodes). ⚖️
        *   `di`: estimated cost to destination. 🎯
        *   `α`: scaling factor (0=BFS, 1=DFS). 🎚️
*   **Domain Negotiation:** (For planar/subset S boxes) Prioritize routing in less congested track domains based on initial ranking. Modifies cost: `fi = (1 − α) × (fi−1 + ci) + α × di + rd` (`rd` is domain rank). 🏆

---

## 🤖 Detailed Routing (Pathfinder)

*   **Pathfinder:** 🛣️
    *   Based on the Maze router but routes all connections allowing **resource overuse** initially. 💦
    *   Iteratively **rips up and re-routes** all nets. ♻️
    *   Cost function penalizes overuse and "history" (past usage). 📜
    *   Cost function: `fi = (1 + hn*hfac) × (1 + pn*pfac) + bn,n+1`. 📊
        *   `bn,n+1`: bend penalty. ↩️
        *   `pn`: present usage cost. 💰
        *   `hn`: history (previous usage). 📜
        *   `hfac`, `pfac`: weighting factors. ⚖️
    *   Process continues until no overuse exists. 🛑
    *   **Minimizes net ordering problem** compared to Maze. 👍

---

## ✨ State of the Art - VPR (Versatile Place and Route) 🏆

*   A versatile **academic router**. 🎓
*   Can route island style and row-based FPGAs, allowing configurable architecture details (switch boxes, wire lengths, doglegs). 🛠️
*   Can perform global routing or **combined global-detailed routing**. 🌐🔍
*   Combined router can modify global assignment if detailed routing is difficult. 🔄
*   Based on a modified **Pathfinder algorithm**. 🧭
*   Two main "flavors" targeting different objectives: 🍦
    1.  **Routability-driven:** Primary goal is successful routing with **minimum track count**. Uses a modified cost model heavily penalizing congestion. 🚧
    2.  **Timing-driven:** Objective is to increase **circuit speed**. Adds Elmore delay model to cost, routes time-critical nets first. Allows slightly higher track counts for faster results. ⚡

---

## ✨ VPR (Continued) - Wavefront Expansion 🌊

*   Modification for multi-output nets in maze wavefront. 🔄
*   Global route breaks n-terminal nets into n-1 two-terminal nets. ✂️
*   Normal Maze: Empties wavefront after reaching each terminal. 🚮
*   **VPR Modification:** Adds reached terminals to the wavefront with cost 0 and continues expansion. ➕
*   Allows subsequent terminals of the same net to be reached **much faster**. ⚡

---

## ✨ State of the Art - ROAD (Order-Impervious Optimal Detailed Router) 🛣️

*   Based on the **Bump and Refit (B&R)** paradigm instead of rip-out and reroute. 🔄
*   **Idea:** Modify already routed nets when a conflict is found. 💡
*   Routes nets one by one; if a conflict occurs and no alternative track exists, conflicting tracks are "bumped" (unrouted). ⚠️
*   Bumped segments are "refitted"; one may not fit, causing it to be routed elsewhere, possibly bumping other tracks. 🎳
*   This propagates bumps until a vacant resource or spare area is found. 🔍
*   Uses **depth-first search** for bump propagation; can be time-consuming. ⏳
*   Claims to be independent of net order because bumping effectively reverses prior decisions. 🔄

---

## ✨ ROAD (Continued) 🚀

*   Three major enhancements to speed up the B&R search space: 🏎️
    1.  **Learning-based search space pruning:** Records unsuccessful bumps; avoids re-attempting isomorphic failed searches. 📝
    2.  **Clique-based search space pruning:** Detects cliques of nets; prunes DFS branches if bumping a net would exceed available tracks needed for the clique. 👥
    3.  **Lookahead transition cost functions:** Estimates which track transitions for a bumped net are most likely to succeed, reducing backtracking. Considers factors like total wirelength and flexibility of bumped nets. 🔮
*   These enhancements prune suboptimal or futile searches **without affecting routing quality**. ✂️
*   Speeded up basic B&R by **604 times**, making it feasible for complete detailed routing. ⚡
*   If unroutable, ROAD can **add one track** to the channel to find minimum track solution for the placement. ➕

---

## ✨ SAT-Based 🔍

*   Transforms the routing problem into a **Boolean function**. ➗
*   **Two main virtues:** ✨
    1.  All paths for all nets are considered **simultaneously** as a set of equations. 🤝
    2.  The Boolean function is satisfiable **IF AND ONLY IF** the design is routable for the given placement/global route. **Formal unroutability detection** is possible if no satisfying assignment exists. 🚫
*   Takes global router assignments as input. 📥
*   Produces two types of constraints: 📜
    *   **Connectivity Constraints:** Ensure continuous path for each net. 🔗
    *   **Exclusivity Constraints:** Ensure nets don't share the same track. 🚷
*   Constraints are transformed into **Conjunctive Normal Form (CNF) clauses**.
*   A Boolean SAT solver (like GRASP) attempts to find a satisfying assignment (1s and 0s for track variables). 🔎
*   Unlike BDDs, which can be memory-unmanageable without good variable ordering (an NP-complete problem), SAT solvers like GRASP use conflict analysis to prune the search space, trading memory for search time. ⚖️

---

## 📊 Comparison - Unroutability Detection 🚫

*   How well do they detect if a design *cannot* be routed? 🤔
    *   **SAT:** Can **formally prove** unroutability by showing the Boolean function is unsatisfiable. However, this can take a long time as it requires exhaustive search. Heavily relies on the initial global assignment. 🔍
    *   **VPR:** Uses a **heuristic** approach. Stops searching after a fixed number of iterations (e.g., 30) and assumes unroutable. Its ability to modify the global assignment can help it find solutions SAT deems unroutable based on the fixed global route. ⏱️
    *   **ROAD:** Not primarily focused on detection. If it fails to route, it **adds a track** and tries again to find the minimum track solution. ➕
*   **Classification:** SAT (Formal Prove) > VPR (Heuristic) > ROAD (None). 🥇🥈🥉

---

## ⏱️ Comparison - Running Time ⏳

*   How fast are these routers? 🏎️
    *   **ROAD:** Generally the fastest. Enhancements make it ~2x faster than VPR routability-driven. ⚡
    *   **VPR Timing-driven:** 2-10x faster than VPR routability-driven. Often faster than ROAD (1-5x). 🚀
    *   **VPR Routability-driven:** Slower than ROAD and VPR timing-driven. 🐢
    *   **SAT:** Often the slowest. Benchmarks suggest it can be significantly slower than VPR and ROAD, though hardware differences make direct comparison tricky. Fair comparisons suggest SAT and VPR routability-driven might have similar running times. 🐌
*   **Classification:** VPR timing-driven > ROAD > VPR routability-driven > SAT. 🥇🥈🥉🏅

---

## 📏 Comparison - Minimum Track Count 📊

*   How efficiently do they use routing resources (minimum wires per channel)?
    *   **VPR Routability-driven:** Designed for this objective, achieves minimum track count on benchmarks. 🎯
    *   **ROAD:** Also achieves the same minimum track count as VPR routability-driven. Its search-based pruning and not adding tracks unless mandatory helps it find the minimum. 🔍
    *   **VPR Timing-driven:** Requires ~5% more tracks than ROAD/VPR routability-driven (trade-off for speed). ⚖️
    *   **SAT:** Doesn't have a cost function for optimality ("flat" search). Requires ~25% more tracks than ROAD. 📈
*   **Classification:** VPR routability-driven = ROAD > VPR timing-driven > SAT. 🥇=🥇 > 🥈 > 🥉

---

## 💾 Comparison - Memory Utilization & Circuit Speed 🧠⚡

*   **Memory Utilization:** Generally correlates with running time. 📊
    *   **VPR Timing-driven:** Least memory requirements (fastest). 🚀
    *   **ROAD:** Second least memory (faster than VPR routability-driven). 🏎️
    *   **VPR Routability-driven:** Third highest memory. 🐢
    *   **SAT:** Highest memory requirements due to simultaneous constraint solving. 🐘
    *   **Classification:** VPR timing-driven < ROAD < VPR routability-driven < SAT. 🥇<🥈<🥉<🏅
*   **Circuit Speed:** Directly targeted by the algorithm. ⚡
    *   **VPR Timing-driven:** The only router specifically designed to optimize for circuit speed (minimize delay). 🏆
    *   **Others (VPR Routability-driven, ROAD, SAT):** Show slower performance and higher delays. 🐢

---

## 🌟 Summary & Conclusion 📝

*   FPGA routing is a **complex problem** despite fixed resources, requiring satisfaction of multiple constraints. 🤯
*   Detail routing is harder than global routing, deeply considering architecture. 🏗️
*   The **Maze algorithm** is a historical base, improved by A\* and Pathfinder. 🏰
*   **VPR** is a state-of-the-art Pathfinder-based tool with variants for routability or timing. 🏆
*   **ROAD** uses the **Bump & Refit** paradigm, overcoming net ordering with enhancements, good trade-off. 🔄
*   **SAT** transforms routing to **Boolean satisfiability**, offering formal unroutability proof but typically slower and higher memory. 🔍

---

## 💡 Future & Ongoing Research 🔮

*   Other approaches exist (e.g., Just In Time routing, Steiner graphs for performance). 🛠️
*   Different approaches offer different perspectives and can refine or be combined with existing algorithms. 🤝
*   As architectures evolve and logic density increases, routing resources become more constrained, keeping FPGA routing an **active research topic**. 🔥
*   More research needed for SAT approach, perhaps adding cost metrics to improve speed/track count. 📈

---

class: nord-dark, middle, center

## Q & A 🎤
