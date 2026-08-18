layout: true
class: typo, typo-selection

---

class: nord-dark, middle, center

# Lecture 2e: Algorithmic Paradigms

@luk036 👨‍💻 · 2026 📅

---

## Overview 📋

-   Greedy approach
-   Mathematical programming
-   Primal-dual algorithm
-   Randomized method
-   Dynamic programming
-   Local search
-   Simulated annealing
-   Books and online resource

---

### Algorithm Paradigms Flowchart

.mermaid[
<pre>
graph TD
    A[Algorithmic Paradigms] --> B[Greedy Approach]
    A --> C[Mathematical Programming]
    A --> D[Primal-Dual Algorithm]
    A --> E[Randomized Method]
    A --> F[Dynamic Programming]
    A --> G[Local Search]
    A --> H[Simulated Annealing]
    style A fill:#2196f3,color:#fff
    style B fill:#4caf50,color:#fff
    style C fill:#ff9800,color:#fff
    style D fill:#9c27b0,color:#fff
    style E fill:#f44336,color:#fff
    style F fill:#2196f3,color:#fff
    style G fill:#4caf50,color:#fff
    style H fill:#ff9800,color:#fff
</pre>
]

---

### 🤑 Greedy Approach

-   Excellent for Minimum Spanning Tree (MST) and Channel Routing
  Problem
  -   Obtain optimal solution
-   Not bad for Knapsack problem
  -   At least half of optimal solution
-   Very bad for Feedback Arc Removal problem
  -   Even worse than a naïve method: randomly remove edges when
    traversing a graph, then reverses the set if $|{\color{lime}E'}|$ is greater
    than 0.5$|{\color{lime}E}|$.
-   Question: Any theory to predict the performance?

---

### Knapsack 🎒 Problem

.pull-left[

-   A thief considers taking ${\color{brown}b}$ pounds of loot 💰. The loot is in the
  form of ${\color{coral}n}$ items, each with weight ${\color{brown}a}_i$ and value ${\color{brown}p}_i$. Any
  amount of an item can be put in the knapsack as long as the weight
  limit ${\color{brown}b}$ is not exceeded

] .pull-right[

![knapsack](lec02.files/knapsack.png)

]

---

### 🤑 Greedy Approach

-   Take as much of the item with the highest value per pound
  (${\color{brown}p}_i$/${\color{brown}a}_i$) as you can. If you run out of that item, take from the
  next highest (${\color{brown}p}_i$/${\color{brown}a}_i$) item. Continue until knapsack is full.

---

### Program 1: Greedy Knapsack

-   **Input**: Set of ${\color{coral}n}$ items, for each ${\color{green}x}_i \in {\color{salmon}X}$, values ${\color{brown}p}_i$,
  ${\color{brown}a}_i$, positive integer ${\color{brown}b}$;
-   **Output**: Subset ${\color{salmon}Y} \subset {\color{salmon}X}$ such that $\sum {\color{brown}a}_i \leq {\color{brown}b}$;
-   Sort ${\color{salmon}X}$ in non-increasing order with respect to the ratio
  ${\color{brown}p}_i$/${\color{brown}a}_i$;
-   Let ($x_1$, $x_2$, ..., $x_n$) be the sorted sequence
-   ${\color{salmon}Y}$ := $0$;
-   **for** $i$:=1 **to** ${\color{coral}n}$ **do**
  -   **if** ${\color{brown}b} \geq {\color{brown}a}_i$ **do**
    -   ${\color{salmon}Y}$ := ${\color{salmon}Y} \cup \{ {\color{green}x}_i \}$;
    -   ${\color{brown}b}$ := ${\color{brown}b} - {\color{brown}a}_i$;
-   **return** ${\color{salmon}Y}$

---

### C++ code 🅒

```{.cpp}
template <class InputIt, typename T, typename F1, typename F2>
InputIt greedy_knapsack(InputIt first, InputIt last,
                        const T& b, F1&& price, F2&& weight)
{
    using Item = typename InputIt::value_type;
    std::sort(first, last, [&](const Item& i1, const Item& i2) {
        return weight(i1) * price(i2) < weight(i2) * price(i1);
    });
    T init(0);
    InputIt it = std::find_if(first, last, [&](Item& i) {
        return (init += weight(i)) > b;
    });
    return it;
}
```

-   Test program can be found in <http://ideone.com/9ZK6ol>.

---

### Can the thief do better?

-   Theorem 1. Let m<sub>H</sub>(${\color{green}x}$) =
  max(${\color{brown}p}$<sub>max</sub>, m<sub>GR</sub>(${\color{green}x}$)),
  where ${\color{brown}p}$<sub>max</sub> is the maximum profit
  of an item 💍 in ${\color{green}x}$. Then m<sub>H</sub>(${\color{green}x}$) satisfies the
  following inequality: m(${\color{green}x}$)/m<sub>H</sub>(${\color{green}x}$) < 2. (p.42)
  (m(${\color{green}x}$) is the optimal solution)

-   As a consequence of the above theorem, a simple modification of
  Program 1 allows us to obtain a provably better algorithm.

-   HW: Implement the algorithm using C++ Template technique and
  iterators (generic programming style)

---

### Linear Programming Relaxation

-   Formulate a problem as an integer linear program.

-   By relaxing the integrality constraints we obtain a new linear
  program, whose optimal solution can be found in polynomial time.

-   This solution, in some cases, can be used to obtain a feasible
  solution for the original integer linear program, by "rounding" the
  values of the variables that do not satisfy the integrality
  constraints.

---

### Weighted Vertex Cover

-   Given a weighted graph $G=({\color{salmon}V}, {\color{lime}E})$, Minimum Weighted Vertex Cover
  (MWVC) can be formulated as the following integer program
  ILP<sub>VC</sub>($G$):

-   Minimize $\sum_{vi \in {\color{salmon}V} } {\color{coral}c}_i {\color{green}x}_i$

-   Subject to ${\color{green}x}_i + {\color{green}x}_j \geq 1$ for all $({\color{brown}v}_i, {\color{brown}v}_j) \in {\color{lime}E}$

-   ${\color{green}x}_i \in \{0, 1\}$ for all ${\color{brown}v}_i \in {\color{salmon}V}$

---

### Program 2.6 Rounding WVC

-   **Input** Graph $G=({\color{salmon}V}, {\color{lime}E})$ with non-negative vertex weights;
-   **Output** Vertex cover ${\color{salmon}V'}$ of $G$;
-   Let ILP<sub>VC</sub> be the linear integer
  programming formulation of the problem;
-   Let LP<sub>VC</sub> be the problem obtained
  from ILP<sub>VC</sub> by relaxing the
  integrality constraints;
-   Let ${\color{green}x}(G^*)$ be the optimal solution for
  LP<sub>VC</sub>;
-   ${\color{salmon}V'}$ := \{${\color{brown}v} \mid {\color{green}x}_v(G^*) \geq 0.5$\};
-   **return** ${\color{salmon}V'}$

---

### Linear Programming

-   Theorem 2.15. Given a graph $G$ with non-negative vertex weights,
  Program 2.6 finds a feasible solution of MWVC with value
  m<sub>LP</sub>($G$) such that
  m<sub>LP</sub>($G$)/m($G^*$) $\leq 2$.

-   Problem: need to solve the LP optimally.

---

### ☯ Primal-dual WVC

-   **Input** Graph $G = ({\color{salmon}V}, {\color{lime}E})$ with non-negative vertex weights;
-   **Output** Vertex cover ${\color{salmon}V'}$ of $G$;
-   Let DLP<sub>VC</sub> be the dual of the LP
  relaxation of ILP<sub>VC</sub>;
-   **for** each dual variable ${\color{firebrick}y}$ of
  DLP<sub>VC</sub> **do** ${\color{firebrick}y} := 0$;
-   ${\color{salmon}V'} := 0$;
-   **while** ${\color{salmon}V'}$ is not a vertex cover **do**
  -   Let $({\color{brown}v}_i, {\color{brown}v}_j)$ be an edge not covered by ${\color{salmon}V'}$;
  -   Increase ${\color{firebrick}y}_{ij}$ until a constraint of
    DLP<sub>VC</sub> becomes tight;
  -   **if** sum$({\color{firebrick}y}_{ij} | (i, j) \in {\color{lime}E} )$ is tight **then**
    -   ${\color{salmon}V'} := {\color{salmon}V'} \cup \{ {\color{brown}v}_i\}$ (\* the i-th dual constraint is
      tight \*)
  -   **else**
    -   ${\color{salmon}V'} := {\color{salmon}V'} \cup \{ {\color{brown}v}_j\}$ (\* the j-th dual constraint is
      tight \*)
-   **return** ${\color{salmon}V'}$

---

### ☯ Primal-dual WVC

-   Theorem 2.16. Given a graph $G$ with non-negative weights, Program
  2.7 finds a feasible solution of MWVC such that
  $m_\text{PD}(G)/m(G^*) \leq 2$. (p. 69)

-   Much faster than Program 2.6 (only take linear time) because we
  don't need to solve the LP optimally.

-   Bonus: Sum of dual variables ${\color{firebrick}y}_{ij}$ gives the lower bound of the
  optimal solution.

---

### Program - Random WVC

-   **Input** Graph $G= ({\color{salmon}V}, {\color{lime}E})$, weight function ${\color{coral}w}: {\color{salmon}V} \mapsto N$;
-   **Output** Vertex cover ${\color{salmon}U}$;
-   ${\color{salmon}U}$ := $\emptyset$;
-   **while** ${\color{lime}E}$ is not empty **do**
  -   Select an edge ${\color{lime}e} = ({\color{brown}v},{\color{brown}t}) \in {\color{lime}E}$;
  -   Randomly choose ${\color{green}x}$ from $\{ {\color{brown}v},{\color{brown}t}\}$ with Pr$\{ {\color{green}x}={\color{brown}v}\}$ =
    ${\color{coral}w}({\color{brown}t}) / ({\color{coral}w}({\color{brown}v}) + {\color{coral}w}({\color{brown}t}))$;
  -   ${\color{salmon}U}$ := ${\color{salmon}U} \cup \{ {\color{green}x}\}$;
  -   ${\color{lime}E}$ := ${\color{lime}E} - \{ {\color{lime}e} \mid {\color{green}x} \text{ is an endpoint of } {\color{lime}e}\}$
-   **return** ${\color{salmon}U}$

---

### 🎲 Randomized Algorithms

-   In many cases, a randomized algorithm is either simpler or faster
  (or both) than a deterministic algorithm.

-   However, it does not guarantee that the algorithm always finds a
  good approximation solution.

-   Theorem 5.1. The expect measure of the solution returned by the
  previous algorithm satisfied the following inequality:

    $$E[m_\text{RWVC}({\color{green}x})] \leq 2 m^*({\color{green}x})$$

-   HW: Implement MWVC solvers using all the above methods. Also extend
  all the methods to handle hypergraph

---

### Dynamic Programming (I)

-   One passenger wants to go from city A to city H through the
  _shortest path_ according to the map on the right, where number of
  indicate distance between corresponding cities.

-   Reference: Pablo Pedregal, _Introduction to Optimization_, chapter
  5.8, Springer, 2003

---

### Dynamic Programming (II)

-   Proposition 5.24 (Fundamental property of dynamic programming)
  -   If $S({\color{coral}t}_j, {\color{green}x})$ denotes the optimal cost from $({\color{coral}t}_0, {\color{green}x})$ to
    $({\color{coral}t}_j, {\color{green}x})$
  -   then we must have S(${\color{coral}t}_{j+1}$, ${\color{green}y}$) =
    min<sub>j</sub> \[S(${\color{coral}t}_j$, ${\color{green}x}$) +
    c($j$,${\color{green}x}$,${\color{green}y}$)\]

---

### Dynamic Programming (III)

-   According to Proposition 5.24, we must proceed successively to
  determine S(${\color{coral}t}_j, {\color{green}x}$) for each ${\color{green}x}$ in
  A<sub>j</sub> to end with S(${\color{coral}t}_n, {\color{green}x}_n$). In the
  proposed example, we have four stages ${\color{coral}t}_0$, ${\color{coral}t}_1$, ${\color{coral}t}_2$, ${\color{coral}t}_3$
  with associated sets of feasible states

  -   A<sub>0</sub> = {A},
    A<sub>1</sub> = {B, C, D},
    A<sub>2</sub> = {E,F,G},
    A<sub>3</sub> = {H}

-   For each city in A<sub>1</sub>, there is a unique
  path from A, so that it must be optimal, and

  -   S(${\color{coral}t}_1$, B) = 7, S(${\color{coral}t}_1$, C) = 4, S(${\color{coral}t}_1$, D) = 1.

-   For each city in A<sub>2</sub>, we determine the
  optimal cost based on the fundamental property of dynamic
  programming,

  -   S(${\color{coral}t}_{j+1}$, ${\color{green}y}$) = min<sub>j</sub> \[S(${\color{coral}t}_j$,
    ${\color{green}x}$) + c($j$,${\color{green}x}$,${\color{green}y}$)\]

---

### Local Search

-   **Input**: Instance ${\color{green}x}$;
-   **Output**: Solution ${\color{green}s}$
-   ${\color{green}s}$ := initial feasible solution ${\color{green}s}_0$;
-   (\* $\mathcal{N}$ denotes the neighborhood function \*)
-   **repeat**
  -   Select any ${\color{green}s}' \in \mathcal{N}({\color{green}x}, {\color{green}s})$ not yet considered;
  -   **if** $m({\color{green}x},{\color{green}s}')$ < $m({\color{green}x}, {\color{green}s})$ **then**
    -   ${\color{green}s}$ := ${\color{green}s}'$;
-   **until** all solutions in $\mathcal{N}({\color{green}x}, {\color{green}s})$ have been
  visited;
-   **return** ${\color{green}s}$;

---

### Simulated Annealing

-   **Input**: Instance ${\color{green}x}$;
-   **Output**: Solution ${\color{green}s}$
-   ${\color{coral}τ}$ := ${\color{coral}t}$;
-   ${\color{green}s}$ := initial feasible solution ${\color{green}s}_0$;
-   **repeat**
  -   **for** $l$ times **do**
    -   Select any unvisited ${\color{green}s}' \in \mathcal{N}({\color{green}x}, {\color{green}s})$
    -   **if** ($m({\color{green}x}, {\color{green}s}')$ < $m({\color{green}x}, {\color{green}s})$)
    -   ${\color{green}s}$ := ${\color{green}s}'$;
    -   **else**
    -   ${\color{coral}δ}$ := $m({\color{green}x}, {\color{green}s}') - m({\color{green}x}, {\color{green}s})$;
    -   ${\color{green}s}$ := ${\color{green}s}'$ with probability exp($-{\color{coral}δ}/{\color{coral}t}$);
  -   ${\color{coral}τ}$ := ${\color{coral}r} \cdot {\color{coral}τ}$; (\* update of temperature \*)
-   **until** FROZEN;
-   **return** ${\color{green}s}$;

---

### Other Heuristic Methods

-   🧗 Hill Climbing
  -   Reference: _Hill Climbing_ by R. A. Sutton and A. G. Barto, MIT Press, 1983
-   🐜 Ant Colony Optimization (ACO)
  -   Reference: _Ant Colony Optimization_, D. E. Kirkpatrick, C.
    Storn, Journal of Global Optimization, 1992
-   🧬 Genetic Algorithm (GA)
  -   Reference: _Genetic Algorithms_, M. Mitchell, McGraw Hill, 1989
-   🙅 Tabu Search (TS)
  -   Reference: _Tabu search_, Kirkpatrick, Storn, 1983
-   Variable Neighborhood Descent (VND)
  -   Reference: _Variable neighborhood descent_, Kirkpatrick, Storn, 1983

---

## 📚 Books and Online Resources

-   G. Ausiello et al. Complexity and Approximation: Combinatorial
  Optimization Problems and Their Approximability Properties.
  Springer, 1999. (O224 C737)

-   M. R. Garey and D. S. Johnson. Computers and Intractability: A Guide
  to the Theory of NP-completeness. Freeman, 1979.

-   Pablo Pedregal. Introduction to Optimization. Springer, 2003 (O224
  P371)

---

count: false
class: nord-dark, middle, center

.pull-left[

# Q&A 🎤

] .pull-right[

![image](figs/questions-and-answers.svg)

]
