layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Understanding the `ellalgo` Package

@luk036 👨‍💻

2025-05-14 📅

---

## ✨ Introduction to the `ellalgo` Package

- Solving Optimization Problems Efficiently ⚡
- Focus on Cutting Plane Methods & Ellipsoid Method ✂️
- A Toolkit for Feasibility & Optimization 🧰

---

### 🤔 What Problem Does `ellalgo` Solve?

-   Finding **optimal** or **feasible** solutions within a given search space 🔍
-   Handles various types of problems:
  -   Feasibility problems ✅
  -   Optimization problems (continuous and discrete) 📈
-   Designed to be **flexible** and **work with different problem types** 🧩
-   Provides a foundation for **solving different varieties of optimization problems** 🏗️

---

### 🎈 The Ellipsoid Method Foundation

- The `ellalgo` package is built upon the concepts of the **Ellipsoid Method** 🏗️
- A key component is representing the search space as an **ellipsoid**
- The algorithm iteratively refines this search space 🔄
- Starts with an initial point and asks an oracle for feedback 🗣️
- Based on the feedback (a "cut"), the ellipsoid (search space) is updated ✂️
- The goal is to shrink the search space to converge towards a solution 🎯

---

### 🔄 Ellipsoid Method Iterations

.mermaid[

<pre>
graph TD
    A[Initial Ellipsoid] --> B[Query Oracle at xc]
    B --> C{Cut feedback?}
    C -->|Feasible| D[Solution Found]
    C -->|Cut provided| E[Update Ellipsoid]
    E --> F{Space &gt; tol?}
    F -->|Yes| B
    F -->|No| G[No Solution]

    style A fill:#ff9800
    style B fill:#2196f3
    style C fill:#f44336
    style D fill:#4caf50
    style E fill:#9c27b0
    style F fill:#f44336
    style G fill:#f44336
</pre>

]

---

### 🥚 The `Ell` Class: Your Search Space

-   The `ellalgo` module defines a class `Ell` 🏗️
-   It represents an **ellipsoidal search space** 🔍
-   Purpose: Providing methods for **updating and manipulating** an ellipsoid 🛠️
-   Initialized with:
  -   `val`: Initial shape (a number or a list of numbers) 🔢
  -   `xc`: Initial position 📍
-   The class doesn't provide calculation results directly, but modifies the ellipsoid based on results 🔄

---

### 🧮 Ellipsoid Calculations: `EllCalc`

- The `ellalgo.ell_calc` module provides classes like `EllCalc` and `EllCalcCore` ➗
- These are designed to perform **calculations related to ellipsoids** 🧮
- Specifically used to calculate **how to adjust or "cut"** an ellipsoid based on inputs ✂️
- Handle the **dimension `n`** of the problem space 📏
- Involve mathematical calculations using inputs like 'beta', 'tau', and 'tsq' αβγ

---

### 🔪 Updating the Ellipsoid with Cuts

-   The algorithm updates the ellipsoid based on "cuts" provided by the oracle ✂️
-   The `Ell` class provides methods to apply these cuts:
  -   `update_bias_cut`: Implements a **deep cut** ⚔️
  -   `update_central_cut`: Implements a **central cut** ✂️
  -   `update_q`: Another method to update the ellipsoid 🔄
-   These update methods are part of the `SearchSpace` interface that `Ell` implements 📜

---

### 🧙 Oracles: The Problem's Feedback

-   Oracles are a **crucial component** in the cutting plane method 🗝️
-   They act as the **problem-specific interface** 🤖
-   The algorithm presents a point (`x`) to the oracle 🎯
-   The oracle provides **feedback** on that point:
  -   Is the point feasible? ✔️
  -   Is the point optimal (for optimization problems)? 🏆
  -   Provides a "**cut**" - information used to update the search space (the ellipsoid) ✂️
-   This feedback guides the algorithm in refining the search 🔍

---

### 🕵️‍♀️ Different Oracles for Different Needs

-   The package defines abstract Oracle types:
  -   `OracleBS`: For **binary search** assessment. Assesses if a `gamma` value is "good" 🔍
  -   `OracleFeas`: A **feasibility oracle**. Determines if a given input is feasible and provides a cut ✅
  -   `OracleOptim`: An **optimization oracle**. Assesses feasibility and objective function value for continuous problems, provides a cut 📈
  -   `OracleOptimQ`: An **optimization oracle for discrete problems**. Assesses feasibility/objective for discrete problems, provides a cut 🔢
  -   `SearchSpace`/`SearchSpaceQ`: Abstract interfaces defining the contract for search space objects (like `Ell`) 📜

---

### ⚙️ Putting It Together: The Algorithms

-   The `ellalgo.cutting_plane` module implements various cutting plane algorithms ⚙️
-   Examples:
  -   `cutting_plane_feas`: For solving **feasibility** problems ✅
  -   `cutting_plane_optim`: For solving **continuous optimization** problems 📈
  -   `cutting_plane_optim_q`: For solving **discrete optimization** problems 🔢
  -   `bsearch`: Implements a **binary search** over a search space 🔍
-   These algorithms use an `Ell` object (or similar `SearchSpace`) and the relevant Oracle to find a solution 🎯
-   The package also includes `conjugate_gradient` for solving linear systems Ax=b ➗

---

### ⚙️ Cutting-plane Algorithm Flow

.mermaid[

<pre>
graph TD
    A[Start] --> B[Get center xc]
    B --> C[Assess feasibility at xc]
    C --> D{Feasible?}
    D -->|Yes| E[Return solution]
    D -->|No| F[Get cutting plane]
    F --> G[Update search space]
    G --> H{Space shrinking?}
    H -->|Yes| B
    H -->|No| I[Terminate: no solution]

    style A fill:#ff9800
    style B fill:#2196f3
    style C fill:#4caf50
    style D fill:#f44336
    style E fill:#4caf50
    style F fill:#9c27b0
    style G fill:#2196f3
    style H fill:#f44336
    style I fill:#f44336
</pre>

]

---

### 📦 Package Structure & Submodules

-   The `ellalgo` package is organized into subpackages and submodules 🗂️
-   Specific problem types have dedicated oracle implementations listed as submodules:
  -   `ellalgo.oracles.ldlt_mgr_module`: Related to LDLT factorization 🧮
  -   `ellalgo.oracles.lmi0_oracle`: For Linear Matrix Inequality (LMI) problems
  -   `ellalgo.oracles.lowpass_oracle`: For lowpass filter design 🎛️
  -   `ellalgo.oracles.profit_oracle`: For profit maximization problems 💰
  -   `ellalgo.oracles.profitrb_oracle`: Another profit-related oracle 💸
-   These show how the abstract Oracle concept is applied to specific mathematical or engineering problems 🛠️

---

### 🏗️ ellalgo Architecture Overview

.mermaid[

<pre>
graph LR
    subgraph Algorithm
        A1[cutting_plane_feas]
        A2[cutting_plane_optim]
        A3[bsearch]
    end
    subgraph SearchSpace
        S1[Ell class]
        S2[update_bias_cut]
        S3[update_central_cut]
    end
    subgraph Oracle
        O1[OracleFeas]
        O2[OracleOptim]
        O3[OracleOptimQ]
    end
    A1 --> S1
    A1 --> O1
    A2 --> S1
    A2 --> O2
    A3 --> O1

    style A1 fill:#ff9800
    style A2 fill:#ff9800
    style A3 fill:#ff9800
    style S1 fill:#2196f3
    style S2 fill:#2196f3
    style S3 fill:#2196f3
    style O1 fill:#4caf50
    style O2 fill:#4caf50
    style O3 fill:#4caf50
</pre>

]

---

### 🎉 Conclusion & Next Steps

- `ellalgo` provides a **flexible and efficient** way to implement and manipulate ellipsoidal search spaces 🎯
- It's a crucial component in implementing **cutting plane techniques** for optimization ✂️
- Encapsulates complex mathematics for easier use 🧮
- More details can be found in the referenced documentation 📚

**GitHub** 🐙: [ellalgo](https://github.com/luk036/ellalgo) 🔗

---

count: false
class: nord-dark, middle, center

.pull-left[

## Q&A 🎤

] .pull-right[

![Discussion](figs/questions-and-answers.svg)

]
