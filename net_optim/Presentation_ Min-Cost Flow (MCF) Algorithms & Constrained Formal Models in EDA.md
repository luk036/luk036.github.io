# Presentation: Min\-Cost Flow \(MCF\) Algorithms \& Constrained Formal Models in EDA

## 📌 Agenda

1. **Background \&amp; EDA Application Scenarios**

2. **Base Formal MCF Mathematical Model**

3. **Full Set of Practical EDA Additional Constraints**

4. **Core Dichotomy: Continuous vs Discrete MCF in EDA**

5. **Specialized MCF Models \(Routing / PDN / Steiner Tree\)**

6. **Industrial Solving Paradigm \& Complexity**

7. **Conclusion \& Key Takeaways**

---

## 1\. 🎯 Background: MCF in EDA

### 1\.1 What is Min\-Cost Flow \(MCF\)?

Minimum Cost Flow is a classic**network convex optimization** problem: route flow from sources to sinks under capacity limits, while minimizing total routing cost\.

It is the **unified mathematical backbone** of modern EDA physical implementation, replacing greedy heuristics with global optimal optimization\.

### 1\.2 🛠️ Core EDA Application Scenarios

- **Global / Detailed Routing**: Congestion optimization \& track allocation

- **Steiner Tree Construction**: Multi\-pin net minimal\-wire routing

- **PDN Power Grid Optimization**: IR\-drop \& electromigration \(EM\) mitigation

- **Cell Placement**: Bipartite assignment for minimal wirelength

- **Clock Tree Synthesis \(CTS\)**: Skew \& power optimization

- **Layer Assignment \& Via Minimization**: DRC\-compliant layer routing

- **High\-Level Synthesis \(HLS\)**: Hardware resource scheduling \& allocation

---

## 2\. 📐 Base Formal MCF Network Model

### 2\.1 Graph Definition

Define a directed flow graph for all EDA physical problems:

$\color{#2E86AB}{G = (V, E)}$

- **Node set \\\(V\\\)**: Routing grid points, pins, PDN vertices, placement sites

- **Edge set \\\(E\\\)**: Wire segments, vias, power grid branches

### 2\.2 Edge \& Node Parameters

For each edge $e\in E$:

- $\color{#A23B72}{c_e \in \mathbb{R}_{\ge0}}$: Edge capacity \(max tracks / max current\)

- $\color{#F18F01}{w_e \in \mathbb{R}}$: Unit edge cost \(wirelength, via, delay, resistance\)

- $\color{#C73E1D}{f_e}$: Flow variable \(core optimization variable\)

For each node $v\in V$:

$\color{#39A78E}{b(v)}$: Supply/demand value \(source: \\\(\+\\\), sink: \\\(\-\\\)\)

Mass conservation: $\sum_{v} b(v) = 0$

### 2\.3 Standard Base MCF Formulation

**Objective \(Min Total Cost\)**

$\min \quad \color{#2E86AB}{\sum_{e\in E} w_e f_e}$

**Hard Base Constraints**

$
    \begin{cases}
    \color{#A23B72}{0 \le f_e \le c_e}, & \forall e\in E \quad (\text{Capacity Bound})\\
    \color{#39A78E}{\sum_{\delta^+ (v)} f_e - \sum_{\delta^- (v)} f_e = b(v)}, & \forall v\in V \quad (\text{Flow Conservation})
    \end{cases}
    $

---

## 3\. 🧩 Full Constrained MCF Model \(EDA Practical Extra Constraints\)

The base model is idealized; **industrial EDA requires 9 categories of additional hard/soft constraints**

### 3\.1 Timing Constraints \(Critical Nets\)

Limit maximum delay/wirelength for timing\-critical nets $\mathcal{T}$:

$\color{#E63946}{\sum_{e\in E} w_{e,k} f_{e,k} \le W_k^{\max}, \quad \forall k\in\mathcal{T}}$

### 3\.2 Regional Congestion Capping

Tighten capacity for congested bins/edges:

$\color{#7209B7}{\sum_k f_{e,k} \le \hat c_e \le c_e, \quad \forall e\in E_{\text{congest}}}$

### 3\.3 DRC Spacing \& Net Isolation

Noisy \& sensitive signal net isolation \(analog/mixed\-signal\):

$\color{#F72585}{f_{e,k_1} + f_{e,k_2} \le 1}$

Prohibit simultaneous usage of the same edge by interference\-prone net pairs\.

### 3\.4 Layer Assignment Constraints

Layer capacity limit \+ forbidden layer routing:

$\color{#4361EE}{\sum_{e\in E_l}\sum_k f_{e,k} \le C_l^{\text{layer}}}, \quad \text{Per metal layer}$

$\color{#4361EE}{f_{e,k}=0}, \quad \text{Net }k \text{ forbidden on layer }l$

### 3\.5 Via Budget Constraints

Per\-net \& global via upper bound:

$\color{#06D6A0}{\sum_{e\in E_{\text{via}}} f_{e,k} \le V_k^{\max}, \quad \forall k}$

### 3\.6 Pre\-Routed Fixed Path Constraints

Preserve manual/pre\-routed nets:

$\color{#FF9F1C}{f_{e,k}=1, \quad \forall e\in P_k}$

$P_k$: Predefined routing path edges for net \\\(k\\\)

### 3\.7 PDN IR\-Drop \& EM Constraints

Power grid maximum voltage drop limit:

$\color{#1D3557}{r_e \cdot f_e \le \Delta V_e^{\max}, \quad \forall e}$

### 3\.8 Convex Congestion Penalty \(Soft Constraint\)

Industrial quadratic congestion\-aware objective:

$\min \sum_{k,e}w_{e,k}f_{e,k} + \color{#B71C1C}{\sum_e \lambda_e \left(\sum_k f_{e,k}\right)^2}$

---

## 4\. ⚖️ Core Dichotomy: Continuous vs Discrete MCF

**The most critical theoretical distinction for EDA**

### 4\.1 Continuous MCF \(LP Relaxation\)

**Variable Domain**:

$\color{#277DA1}{f_{e,k} \in \mathbb{R}_{\ge 0}}$

**Properties**:

- Pure Linear Program \(LP\), **polynomial\-time solvable**

- Allows fractional track occupation \(global routing approximation\)

- **Industrial default solver** for full\-chip routing

- Single\-commodity MCF has integral optimal solution \(totally unimodular property\)

### 4\.2 Discrete / Integer MCF \(ILP Exact Model\)

**Variable Domain**:

$\color{#E01E35}{f_{e,k} \in \{0,1\},\quad g_e = \sum_k f_{e,k} \in \mathbb{Z}}$

**Core Definition**:

- Each net **either occupies a track entirely or not** \(no fractional occupation\)

- $g_e$: Discrete integer number of nets on edge $e$

- $0 \le g_e \le c_e,\ c_e\in\mathbb{N}$: Discrete track capacity limit

**Properties**:

- Integer Linear Program \(ILP\), **NP\-hard**

- Exact physical model for detailed routing track assignment

- Cannot be solved for full\-chip large\-scale designs

- Only applicable for local small\-region routing refinement

### 4\.3 Critical EDA Rule of Thumb

|MCF Type|Mathematical Type|Scenario|Solvability|
|---|---|---|---|
|Continuous|LP \(Convex\)|Full\-chip Global Routing, PDN Analysis|Polynomial, fast|
|Discrete|ILP \(Non\-convex\)|Detailed Track Assignment, Local DRC Fix|NP\-hard, approximate only|

---

## 5\. 🧱 Specialized MCF Models for Key EDA Problems

### 5\.1 Single\-Commodity MCF: Steiner Tree \(Single Net\)

**Scenario**: Multi\-pin net minimal wire routing

**Model Features**:

- Single flow commodity: one driver source, multiple sinks

- Unlimited edge capacity $c_e \to \infty$

- **Key Theorem**: Continuous LP solution = integer optimal solution \(totally unimodular matrix\)

$\color{#22577A}{\min \sum w_e f_e,\quad \nabla\cdot f = b(v)}$

### 5\.2 Multi\-Commodity MCF: Global Routing \(All Nets\)

**Scenario**: Full\-chip congestion\-aware multi\-net routing

**Model Features**:

- Each net = independent commodity

- Shared edge capacity couples all commodities

- Fractional LP relaxation used in industry

$\color{#3A0CA3}{\min \sum_{k,e} w_{e,k}f_{e,k},\quad \sum_k f_{e,k} \le c_e}$

### 5\.3 Convex Continuous MCF: PDN IR/EM Optimization

**Scenario**: Power grid current distribution optimization

**Model Features**:

- Pure continuous flow \(electric current\)

- Quadratic convex cost for power loss minimization

- Hard IR\-drop \& EM current constraints

$\color{#001233}{\min \sum r_e f_e^2,\quad r_e f_e \le \Delta V_{\max}}$

---

## 6\. ⚙️ Industrial Solving Paradigm \& Complexity

### 6\.1 Why Not Exact Discrete MCF?

- Full\-chip EDA contains $10^5 \sim 10^6$ edges/nets

- Integer MCMCF is NP\-hard, computationally infeasible

- Discrete track constraints bring exponential complexity

### 6\.2 Industry Standard Pipeline

1. **Continuous LP Relaxation**: Solve global congestion \& wirelength optimization

2. **Lagrangian Decomposition**: Decouple multi\-commodity coupling constraints

3. **Greedy Rounding**: Convert fractional flow to discrete track assignment

4. **Local Integer Repair**: Fix DRC/congestion violations locally

### 6\.3 Complexity Summary

- **Single\-commodity MCF**: \\\(O\(E\\sqrt\{V\}\\log U\)\\\) \(polynomial\)

- **Multi\-commodity Continuous MCF**: Polynomial via LP solver

- **Multi\-commodity Discrete MCF**: NP\-hard \(intractable at scale\)

---

## 7\. ✅ Conclusion \& Key Takeaways

### 7\.1 Core Summary

- MCF provides a **unified mathematical framework** for nearly all EDA physical design problems

- EDA MCF has two strictly separated forms: **continuous LP** for global optimization, **discrete ILP** for local precise routing

- Practical EDA models integrate 8\+ types of engineering constraints beyond basic MCF

- Industrial tools rely on **relaxation \+ decomposition \+ rounding** to balance accuracy and speed

### 7\.2 Key Theoretical Insights

- Single\-commodity MCF enjoys integral solution property, no discretization error

- Multi\-commodity routing is the bottleneck, requiring continuous approximation

- PDN optimization is purely continuous convex MCF, solvable to global optimum

### 7\.3 Application Value

MCF algorithms replace traditional greedy EDA heuristics with **constrained global optimization**, significantly improving chip congestion, timing, power and DRC compliance for advanced process nodes \(7nm/3nm\)\.

> （注：部分内容可能由 AI 生成）
