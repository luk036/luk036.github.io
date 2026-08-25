# Lecture 2c: Introduction to Convex Programming

## 📝 Abstract

This lecture provides an introduction to the convex programming and
covers various aspects of optimization. The lecture begins with an
overview of optimization, including linear and nonlinear programming,
duality and convexity, and approximation techniques. It then delves into
more specific topics within continuous optimization, such as linear
programming problems and their standard form, transformations to
standard form, and the duality of linear programming problems. The
lecture also touches on nonlinear programming, discussing the standard
form of an NLPP (nonlinear programming problem) and the necessary
conditions of optimality known as the Karush-Kuhn-Tucker (KKT)
conditions. Convexity is another important concept explored in the
document, with explanations on the definition of convex functions and
their properties. The lecture also discusses the duality of convex
optimization problems and their usefulness in computation. Finally, the
document briefly mentions various unconstrained optimization techniques,
descent methods, and approximation methods under constraints.

### Overview 📋

-   Introduction
-   Linear programming
-   Nonlinear programming
-   Duality and Convexity
-   Approximation techniques
-   Convex Optimization
-   Books and online resources.

### Classification of Optimizations

-   Continuous
  -   Linear vs Non-linear
  -   Convex vs Non-convex
-   Discrete
  -   Polynomial time Solvable
  -   NP-hard
    -   Approximatable
    -   Non-approximatable
-   Mixed

### Continuous Optimization 🔧

![classification](lec02.files/class.svg)

### Linear Programming Problem

-   An LPP in standard form is:
  $$\min\{ {\color{royalblue}c}^\mathsf{T} {\color{green}x} \mid {\color{royalblue}A} {\color{green}x} = {\color{royalblue}b}, {\color{green}x} \ge 0\}.$$
-   The ingredients of LPP are:
  -   An ${\color{royalblue}m} \times {\color{royalblue}n}$ matrix ${\color{royalblue}A}$, with ${\color{royalblue}n} > {\color{royalblue}m}$
  -   A vector ${\color{royalblue}b} \in \mathbb{R}^{\color{royalblue}m}$
  -   A vector ${\color{royalblue}c} \in \mathbb{R}^{\color{royalblue}n}$

### 📚 Example

$$
\begin{array}{lll}
  \text{minimize} & 0.4 {\color{green}x_1} + 3.4 {\color{green}x_2} - 3.4 {\color{green}x_3} \\
  \text{subject to} & 0.5 {\color{green}x_1} + 0.5 {\color{green}x_2} & = 3.5 \\
  & 0.3 {\color{green}x_1} - 0.8 {\color{green}x_2} + 8.4 {\color{green}x_2} & = 4.5 \\
  & {\color{green}x_1}, {\color{green}x_2}, {\color{green}x_3} \ge 0
\end{array}
$$

### Transformations to Standard Form

-   Theorem: Any LPP can be transformed into the standard form.
-   Variables not restricted in sign:
  -   Decompose ${\color{green}x}$ to two new variables
    ${\color{green}x} = {\color{green}x_1} - {\color{green}x_2}, {\color{green}x_1}, {\color{green}x_2} \geq 0$
-   Transforming inequalities into equalities:
  -   By putting slack variable ${\color{firebrick}y} = {\color{royalblue}b} - {\color{royalblue}A} {\color{green}x} \geq 0$
  -   Set ${\color{green}x'} = ({\color{green}x}, {\color{firebrick}y}), {\color{royalblue}A'} = ({\color{royalblue}A}, 1)$
-   Transforming a max into a min
  -   max(expression) = min($-$expression);

### Duality of LPP

-   If the primal problem of the LPP:
  $\min\{ {\color{royalblue}c}^\mathsf{T} {\color{green}x} \mid {\color{royalblue}A} {\color{green}x} \ge {\color{royalblue}b}, {\color{green}x} \ge 0\}$.
-   Its dual is:
  $\max\{ {\color{firebrick}y}^\mathsf{T} {\color{royalblue}b} \mid {\color{royalblue}A}^\mathsf{T} {\color{firebrick}y} \leq {\color{royalblue}c}, {\color{firebrick}y} \ge 0\}$.
-   If the primal problem is:
  $\min\{ {\color{royalblue}c}^\mathsf{T} {\color{green}x} \mid {\color{royalblue}A} {\color{green}x} = {\color{royalblue}b}, {\color{green}x} \ge 0\}$.
-   Its dual is: $\max\{ {\color{firebrick}y}^\mathsf{T} {\color{royalblue}b} \mid {\color{royalblue}A}^\mathsf{T} {\color{firebrick}y} \leq {\color{royalblue}c}\}$.

### Nonlinear Programming

-   The standard form of an NLPP is
  $$\min\{f({\color{green}x}) \mid g({\color{green}x}) \leq 0, h({\color{green}x})=0 \}.$$
-   Necessary conditions of optimality, Karush- Kuhn-Tucker (KKT)
  conditions:

  -   Gradient Condition: ∇f(x) + µ∇g(x) + λ∇h(x) = 0, where ∇f(x),
    ∇g(x), and ∇h(x) are the gradients of the objective function,
    inequality constraints, and equality constraints, respectively.
    This condition states that the sum of the directional
    derivatives of the objective function and the constraints must
    be zero at the optimal solution.

  -   Complementary Slackness Condition: µg(x) = 0, where µ is a
    Lagrange multiplier associated with the inequality constraints.
    This condition implies that either the constraint is inactive
    (g(x) ≤ 0) or its corresponding Lagrange multiplier is zero.

  -   Feasibility Condition: µ ≥ 0, g(x) ≤ 0, h(x) = 0. This condition
    ensures that the inequality and equality constraints are
    satisfied at the optimal solution.

### What is the significance of the KKT conditions mentioned?

The significance of the KKT conditions lies in their ability to provide
necessary conditions for a solution to be optimal in nonlinear
programming problems. By satisfying these conditions, a point can be
determined as a possible optimal solution. Moreover, if the objective
function is strictly convex, and the KKT conditions are satisfied, then
the solution obtained is the unique optimal solution. In essence, the
KKT conditions serve as a powerful mathematical tool for analyzing and
solving optimization problems.

### Convexity

-   A function $f$: ${\color{salmon}K} \subseteq \mathbb{R}^{\color{royalblue}n} \mapsto R$ is convex if
  ${\color{salmon}K}$ is a convex set and
  $f({\color{green}y}) \ge f({\color{green}x}) + \nabla f({\color{green}x}) ({\color{green}y} - {\color{green}x}), \; {\color{green}y},{\color{green}x} \in {\color{salmon}K}$.

-   **Theorem**: Assume that $f$ and $g$ are convex differentiable
  functions. If the pair $({\color{green}x}, {\color{royalblue}m})$ satisfies the KKT conditions above,
  ${\color{green}x}$ is an optimal solution of the problem. If in addition, $f$ is
  strictly convex, ${\color{green}x}$ is the only solution of the problem.

## (Local minimum = global minimum)

### Duality and Convexity

-   Dual is the NLPP: $$\max\{\theta({\color{firebrick}\mu}, {\color{firebrick}\lambda}) \mid {\color{firebrick}\mu} \geq 0\},$$
  where
  $\theta({\color{firebrick}\mu}, {\color{firebrick}\lambda}) = \inf_{\color{green}x} [ f({\color{green}x}) + {\color{firebrick}\mu} g({\color{green}x}) + {\color{firebrick}\lambda} h({\color{green}x}) ]$

-   Dual problem is always convex.

-   Useful for computing the lower/upper bound 🔽🔼.

### Applications

-   Statistics
-   Filter design
-   Power control
-   Machine learning
  -   SVM classifier
  -   logistic regression

class: nord-light, middle, center

## Convexify the non-convex's

### Change of curvature: square

Transform: $$0.3 \leq {\color{red} \sqrt{x} } \leq 0.4$$ into:
$$0.09 \leq {\color{green} x} \leq 0.16 \, .$$

👉 Note that $\sqrt{\cdot}$ are **monotonic** **concave** functions in
$(0, +\infty)$.

Generalization:

-   Consider $|H({\color{royalblue}\omega})|^2$ (power) instead of $|H({\color{royalblue}\omega})|$ (magnitude).
-   square root -> Spectral factorization

#### Change of curvature: square

Transform:
$${\color{red} x^2 } + {\color{red} y^2 } \geq 0.16, \quad \text{(non-convex)}$$
into:
$${\color{green} x'} + {\color{green} y'} \geq 0.16, \quad {\color{green} x'}, {\color{green} y'} \geq 0$$
Then:
$${\color{red} x}_\text{opt} = \pm\sqrt{ {\color{green} x'}_\text{opt} }, \quad {\color{red} y}_\text{opt} = \pm\sqrt{ {\color{green} y'}_\text{opt} }.$$

#### Change of curvature: sine

Transform:
$${\color{red} \sin^2{x} } \leq 0.4, \quad 0 \leq {\color{red} x} \leq \pi/2$$ into:
$${\color{green} y} \leq 0.4, \quad 0 \leq {\color{green} y} \leq 1$$ Then:
$${\color{red} x}_\text{opt} = \sin^{-1}(\sqrt{ {\color{green} y}_\text{opt} }).$$

👉 Note that $\sin(\cdot)$ are monotonic concave functions in
$(0, \pi/2)$.

#### Change of curvature: log

Transform: $$\pi \leq {\color{red} x / y} \leq \phi$$ into:
$$\pi' \leq {\color{green} x' - y'} \leq \phi'$$ where ${\color{green} z'} = \log({\color{red} z})$.

Then: $${\color{red} z}_\text{opt} = \exp({\color{green} z'}_\text{opt}).$$

Generalization: - Geometric programming

#### Change of curvature: inverse

Transform: $${\color{red} \log(x) + \frac{c}{x} } \leq 0.3, \; {\color{red} x} > 0$$
into: $${\color{green} -\log(y) + c \cdot y } \leq 0.3, \; {\color{green} y} > 0 \, .$$

Then: $${\color{red} x}_\text{opt} = {\color{green} y}^{-1}_\text{opt}.$$

👉 Note that $\sqrt{\cdot}$, $\log(\cdot)$, and $(\cdot)^{-1}$ are
monotonic functions.

#### Generalize to matrix inequalities

Transform:
$${\color{red} \log(\det X) + \text{Tr}(X^{-1} C)} \leq 0.3, \; {\color{red} X} \succ 0$$
into:
$${\color{green} -\log(\det Y) + \text{Tr}(Y \cdot C)} \leq 0.3, \; {\color{green} Y} \succ 0$$

Then: $${\color{red} X}_\text{opt} = {\color{green} Y}^{-1}_\text{opt}.$$

#### Change of variables

Transform: $$({\color{royalblue}a} + {\color{royalblue}b} \cdot {\color{red} y}) {\color{green}x} \leq 0, \; {\color{green}x} > 0$$

into: $${\color{royalblue}a} \cdot {\color{green}x} + {\color{royalblue}b} \cdot {\color{green} z} \leq 0, \; {\color{green}x} > 0$$ where
${\color{green} z} = {\color{red} y} {\color{green}x}$.

Then: $${\color{red} y}_\text{opt} = {\color{green} z}_\text{opt} {\color{green}x}^{-1}_\text{opt}$$

#### Generalize to matrix inequalities

Transform:
$$({\color{royalblue}A} + {\color{royalblue}B} {\color{red} Y}) {\color{green}X} + {\color{green}X} ({\color{royalblue}A} + {\color{royalblue}B} {\color{red} Y})^T \prec 0, \; {\color{green}X} \succ 0$$

into:
$${\color{royalblue}A} {\color{green}X} + {\color{green}X} {\color{royalblue}A}^T + {\color{royalblue}B} {\color{green} Z} + {\color{green} Z}^T {\color{royalblue}B}^T \prec 0, \; {\color{green}X} \succ 0$$
where ${\color{green} Z} = {\color{red} Y} {\color{green}X}$.

Then: $${\color{red} Y}_\text{opt} = {\color{green} Z}_\text{opt} {\color{green}X}^{-1}_\text{opt}$$

#### Some operations that preserve convexity

-   $-f$ is concave if and only if $f$ is convex.
-   Nonnegative weighted sums:
  -   if ${\color{royalblue}w}_1, \ldots, {\color{royalblue}w}_n \ge 0$ and $f_1, \ldots, f_n$ are all
    convex, then so is ${\color{royalblue}w}_1 f_1 + \cdots + {\color{royalblue}w}_n f_n.$ In particular,
    the sum of two convex functions is convex.
-   Composition:
  -   If $f$ and $g$ are convex functions and $g$ is non-decreasing
    over a univariate domain, then $h({\color{green}x}) = g(f({\color{green}x}))$ is convex. As an
    example, if $f$ is convex, then so is $e^{f({\color{green}x})},$ because $e^{ {\color{green}x} }$
    is convex and monotonically increasing.
  -   If $f$ is concave and $g$ is convex and non-increasing over a
    univariate domain, then $h({\color{green}x}) = g(f({\color{green}x}))$ is convex.
  -   Convexity is invariant under affine maps.

#### Other thoughts

-   Minimizing any quasi-convex function subject to convex constraints
  can easily be transformed into a convex programming.
-   Replace a non-convex constraint with a sufficient condition (such as
  its lower bound). Less optimal.
-   Relaxation + heuristic
-   Decomposition

#### Unconstraint Techniques

-   Line search methods
-   Fixed or variable step size
-   Interpolation
-   Golden section method
-   Fibonacci's method
-   Gradient methods
-   Steepest descent
-   Quasi-Newton methods
-   Conjugate Gradient methods

#### General Descent Method

1. **Input**: a starting point ${\color{green}x} \in$ dom $f$
2. **Output**: ${\color{green}x}^*$
3. **repeat**
    1. Determine a descent direction ${\color{green}p}$.
    2. Line search. Choose a step size ${\color{royalblue}\alpha} > 0$.
    3. Update. ${\color{green}x} := {\color{green}x} + {\color{royalblue}\alpha} {\color{green}p}$
4. **until** stopping criterion satisfied.

#### Some Common Descent Directions

-   Gradient descent: ${\color{green}p} = -\nabla f({\color{green}x})^\mathsf{T}$
-   Steepest descent:
  -   $\triangle {\color{green}x}_{nsd} = \argmin\{\nabla f({\color{green}x})^\mathsf{T} {\color{green}v} \mid \|{\color{green}v}\|=1 \}$
  -   $\triangle {\color{green}x}$ = $\|\nabla f({\color{green}x})\| \triangle {\color{green}x}_{nsd}$
    (un-normalized)
-   Newton's method:
  -   ${\color{green}p} = -\nabla^2 f({\color{green}x})^{-1} \nabla f({\color{green}x})$
-   Conjugate gradient method:
  -   ${\color{green}p}$ is "orthogonal" to all previous ${\color{green}p}$'s
-   Stochastic subgradient method:
  -   ${\color{green}p}$ is calculated from a set of sample data (instead of using
    all data)
-   Network flow problems:
  -   ${\color{green}p}$ is given by a "negative cycle" (or "negative cut").

#### Approximation Under Constraints

-   Penalization and barriers
-   Dual method
-   Interior Point method
-   Augmented Lagrangian method

#### 📚 Books and Online Resources

-   Pablo Pedregal. Introduction to Optimization, Springer. 2003 (O224
  P371)
-   Stephen Boyd and Lieven Vandenberghe, Convex Optimization, Dec. 2002
-   Mittlemann, H. D. and Spellucci, P. Decision Tree for Optimization
  Software, 2003

## Lecture 2d: Complexity Theory

@luk036 👨‍💻 · 2026 📅

### Overview 📋

-   Complexity theory

-   NP-completeness.

-   Approximation classes

-   Books and online resources.

#### Complexity Theory

-   Big O-notation: O(${\color{royalblue}N}$), O(${\color{royalblue}N}\log {\color{royalblue}N}$), O(${\color{royalblue}N}^2$), O(${\color{royalblue}N}!$) ...

-   Interest in discrete problems in which ${\color{royalblue}N}$ is large.

-   Indeed, ${\color{royalblue}N}$ could be very large (multi-million) in EDA problems,
  except:

  -   Pins of a signal net (usually < 200)
  -   Vertices of polygon shapes (usually < 100)
  -   Number of routing layers (usually < 10)

-   Many Physical Design problems are geometrically related. Complexity
  (either time or space) could be reduced by exploiting properties
  such as locality, symmetry, planarity, or triangle inequality.

#### NP-completeness

-   Many EDA problems are in fact NP-hard.

-   Whereas, some NP-complete problems admit good approximations with
  guarantee performance ratio (_pseudo-polynomial_). E.g. bin-packing
  problem and knapsack problem.

-   Whereas, some NP-complete problems (e.g. SAT) are intrinsically not
  "approximatable" unless P=NP.

-   See the book "Complexity and Approximation: Combinatorial
  Optimization Problems and Their Approximability Properties" for more
  details.

#### Approximation Classes

-   NPO-hard

-   APX-hard

-   PTAS: polynomial-time approximation scheme

-   FPTAS: Fully PTAS (pseudo-polynomial)

    P < FPTAS < PTAS < APX < NPO

#### E.g. Minimum Vertex Cover

-   Instance: Graph $G$ = (${\color{salmon}V}$, ${\color{lime}E}$)

-   Solution: A vertex cover for $G$, i.e., a subset ${\color{salmon}V'}$ such that, for
  each edge $({\color{brown}u}, {\color{brown}v}) \in {\color{lime}E}$, at least one of ${\color{brown}u}$ and ${\color{brown}v}$ belongs to
  ${\color{salmon}V'}$

-   Measure: Cardinality of the vertex cover, i.e. $|{\color{salmon}V'}|$

-   Bad News: APX-complete.

-   Comment: Admits a PTAS for _planar_ graphs \[Baker, 1994\]. The
  generalization to ${\color{royalblue}k}$-hypergraphs, for ${\color{royalblue}k}>1$, is approximable within
  ${\color{royalblue}k}$ \[Bar-Yehuda and Even, 1981\] and \[Hochbaum, 1982a\]. (HW:
  Implement the algorithms.)

-   Garey and Johnson: GT

#### Minimum Maximal Matching

-   Instance: Graph $G$ = (${\color{salmon}V}$, ${\color{lime}E}$).

-   Solution: A maximal matching ${\color{lime}E'}$, i.e., a subset ${\color{lime}E'}$ such that no
  two edges in ${\color{lime}E'}$ shares a common endpoint and every edge in
  ${\color{lime}E} - {\color{lime}E'}$ shares a common endpoint with some edge in ${\color{lime}E'}$.

-   Measure: Cardinality of the matching, i.e. $|{\color{lime}E'}|$.

-   Bad News: APX-complete \[Yannakakis and Gavril, 1980\]

-   Comment: Transformation from Minimum Vertex Cover (HW: Implement the
  algorithm)

-   Garey and Johnson: GT10

#### Minimum Steiner Tree

-   Instance: Complete graph $G$ = (${\color{salmon}V}$, ${\color{lime}E}$), a metric given by edge
  weights ${\color{royalblue}s}: {\color{lime}E} \mapsto N$ and a subset ${\color{salmon}S} \subset {\color{salmon}V}$ of required
  vertices.

-   Solution: A Steiner tree, i.e., a sub-tree of $G$ that includes all
  the vertices in ${\color{salmon}S}$.

-   Measure: The sum of the weights of the edges in the sub-tree.

-   Bad News: APX-complete.

-   Garey and Johnson: ND12

#### Minimum Geometric Steiner Tree

-   Instance: Set ${\color{salmon}P} \subset Z \times Z$ of points in the plane.

-   Solution: A finite set of Steiner points, i.e.,
  ${\color{salmon}Q} \subset Z \times Z$

-   Good News: Admits a PTAS \[Arora, 1996\]

-   Comment: Admits a PTAS for any _geometric space_ of constant
  dimension ${\color{royalblue}d}$, e.g. in the rectilinear metric \[Arora, 1997\].

-   Garey and Johnson: ND13

#### Traveling Salesman 🧳🕴

-   Instance: Set ${\color{salmon}C}$ of ${\color{royalblue}m}$ cities, distances ${\color{royalblue}d(c_i, c_j)} \in N$ for
  each pair of cities ${\color{brown}c_i}, {\color{brown}c_j} \in {\color{salmon}C}$.

-   Solution: A tour of ${\color{salmon}C}$, i.e., a permutation
  $\pi : [1..{\color{royalblue}m}] \mapsto [1..{\color{royalblue}m}]$.

-   Measure: The length of the tour.

![TSP](lec02.files/TSP.jpg)

#### Traveling Salesman 🧳🕴

-   Bad News: NPO-complete

-   Comment: The corresponding maximization problem (finding the tour of
  maximum length) is approximable within 7/5 if the distance function
  is _symmetric_ and 63/38 if it is asymmetric \[Kosaraju, Park, and
  Stein, 1994\]

-   Garey and Johnson: ND22

#### Minimum _Metric_ TSP

-   Instance: Set ${\color{salmon}C}$ of ${\color{royalblue}m}$ cities, distances ${\color{royalblue}d(c_i, c_j)} \in N$
  satisfying the _triangle inequality_
  (i.e. ${\color{royalblue}d(a, b)} + {\color{royalblue}d(b, c)} \geq {\color{royalblue}d(a, c)}$)

-   Solution: A permutation $\pi : [1..{\color{royalblue}m}] \mapsto [1..{\color{royalblue}m}]$.

-   Measure: The length of the tour.

-   Good news: Approximable within 3/2 \[Christofides 76\]

-   Bad News: APX-complete.

-   Comment: A variation in which vertices can be revisited and the goal
  is to minimize the sum of the latencies of all vertices, where the
  latency of a vertex ${\color{brown}c}$ is the length of the tour from the starting
  point to ${\color{brown}c}$, is approximable within 29 and is APX-complete

#### Minimum Geometric TSP

-   Instance: Set ${\color{salmon}C} \subset Z \times Z$ of ${\color{royalblue}m}$ points in the plane.

-   Solution: A tour of ${\color{salmon}C}$, i.e., a permutation
  $\pi : [1..{\color{royalblue}m}] \mapsto [1..{\color{royalblue}m}]$.

-   Measure: The length of the tour, where the distance is the
  discretized Euclidean length.

-   Good news: Admits a PTAS \[Arora, 1996\]

-   Comment: In $\mathbb{R}^{\color{royalblue}m}$ the problem is APX-complete for any $l_p$
  metric \[Trevisan, 1997\].

-   Garey and Johnson: ND23

#### Application - Punching Machine

![TSP](lec02.files/TSP2.jpg)

#### Summary

-   Some problems are intrinsically hard -- even good approximation does
  not exist unless P=NP (NPO-complete). In such cases, heuristic
  methods are used (see the \[next lecture\]).

-   "Better" algorithm could be obtained by exploiting more problem's
  properties: locality, symmetry, sparsity, planarity, convexity,
  monotonity, ... etc.

#### 📚 Books and Online Resources

-   G. Ausiello et al. Complexity and Approximation: Combinatorial
  Optimization Problems and Their Approximability Properties.
  Springer, 1999. (O224 C737)

-   M. R. Garey and D. S. Johnson. Computers and Intractability: A Guide
  to the Theory of NP-completeness. Freeman, 1979.

## Lecture 2e: Algorithmic Paradigms

@luk036 👨‍💻 · 2026 📅

### Overview 📋

-   Greedy approach
-   Mathematical programming
-   Primal-dual algorithm
-   Randomized method
-   Dynamic programming
-   Local search
-   Simulated annealing
-   Books and online resource

#### Greedy Approach

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

#### Knapsack Problem 💰

.pull-left[

-   A thief 🦹 considers taking ${\color{brown}b}$ pounds of loot 💰. The loot is in the
  form of ${\color{royalblue}n}$ items, each with weight ${\color{brown}a}_i$ and value ${\color{brown}p}_i$. Any
  amount of an item can be put in the knapsack as long as the weight
  limit ${\color{brown}b}$ is not exceeded

] .pull-right[

![knapsack](lec02.files/knapsack.png)

]

#### Greedy Approach

-   Take as much of the item with the highest value per pound
  (${\color{brown}p}_i$/${\color{brown}a}_i$) as you can. If you run out of that item, take from the
  next highest (${\color{brown}p}_i$/${\color{brown}a}_i$) item. Continue until knapsack is full.

#### Program 1: Greedy Knapsack

-   **Input**: Set of ${\color{royalblue}n}$ items, for each ${\color{green}x}_i \in {\color{salmon}X}$, values ${\color{brown}p}_i$,
  ${\color{brown}a}_i$, positive integer ${\color{brown}b}$;
-   **Output**: Subset ${\color{salmon}Y} \subset {\color{salmon}X}$ such that $\sum {\color{brown}a}_i \leq {\color{brown}b}$;
-   Sort ${\color{salmon}X}$ in non-increasing order with respect to the ratio
  ${\color{brown}p}_i$/${\color{brown}a}_i$;
-   Let ($x_1$, $x_2$, ..., $x_n$) be the sorted sequence
-   ${\color{salmon}Y}$ := $0$;
-   **for** $i$:=1 **to** ${\color{royalblue}n}$ **do**
  -   **if** ${\color{brown}b} \geq {\color{brown}a}_i$ **do**
    -   ${\color{salmon}Y}$ := ${\color{salmon}Y} \cup \{ {\color{green}x}_i \}$;
    -   ${\color{brown}b}$ := ${\color{brown}b} - {\color{brown}a}_i$;
-   **return** ${\color{salmon}Y}$

#### C++ code

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

#### Can the thief do better?

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

#### Linear Programming Relaxation

-   Formulate a problem as an integer linear program.

-   By relaxing the integrality constraints we obtain a new linear
  program, whose optimal solution can be found in polynomial time.

-   This solution, in some cases, can be used to obtain a feasible
  solution for the original integer linear program, by "rounding" the
  values of the variables that do not satisfy the integrality
  constraints.

#### Weighted Vertex Cover

-   Given a weighted graph $G=({\color{salmon}V}, {\color{lime}E})$, Minimum Weighted Vertex Cover
  (MWVC) can be formulated as the following integer program
  ILP<sub>VC</sub>($G$):

-   Minimize $\sum_{vi \in {\color{salmon}V} } {\color{royalblue}c}_i {\color{green}x}_i$

-   Subject to ${\color{green}x}_i + {\color{green}x}_j \geq 1$ for all $({\color{brown}v}_i, {\color{brown}v}_j) \in {\color{lime}E}$

-   ${\color{green}x}_i \in \{0, 1\}$ for all ${\color{brown}v}_i \in {\color{salmon}V}$

#### Program 2.6 Rounding WVC

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

#### Linear Programming

-   Theorem 2.15. Given a graph $G$ with non-negative vertex weights,
  Program 2.6 finds a feasible solution of MWVC with value
  m<sub>LP</sub>($G$) such that
  m<sub>LP</sub>($G$)/m($G^*$) $\leq 2$.

-   Problem: need to solve the LP optimally.

#### ☯ Primal-dual WVC

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

#### ☯ Primal-dual WVC

-   Theorem 2.16. Given a graph $G$ with non-negative weights, Program
  2.7 finds a feasible solution of MWVC such that
  $m_\text{PD}(G)/m(G^*) \leq 2$. (p. 69)

-   Much faster than Program 2.6 (only take linear time) because we
  don't need to solve the LP optimally.

-   Bonus: Sum of dual variables ${\color{firebrick}y}_{ij}$ gives the lower bound of the
  optimal solution.

#### Program - Random WVC

-   **Input** Graph $G= ({\color{salmon}V}, {\color{lime}E})$, weight function ${\color{royalblue}w}: {\color{salmon}V} \mapsto N$;
-   **Output** Vertex cover ${\color{salmon}U}$;
-   ${\color{salmon}U}$ := $\emptyset$;
-   **while** ${\color{lime}E}$ is not empty **do**
  -   Select an edge ${\color{lime}e} = ({\color{brown}v},{\color{brown}t}) \in {\color{lime}E}$;
  -   Randomly choose ${\color{green}x}$ from $\{ {\color{brown}v},{\color{brown}t}\}$ with Pr$\{ {\color{green}x}={\color{brown}v}\}$ =
    ${\color{royalblue}w}({\color{brown}t}) / ({\color{royalblue}w}({\color{brown}v}) + {\color{royalblue}w}({\color{brown}t}))$;
  -   ${\color{salmon}U}$ := ${\color{salmon}U} \cup \{ {\color{green}x}\}$;
  -   ${\color{lime}E}$ := ${\color{lime}E} - \{ {\color{lime}e} \mid {\color{green}x} \text{ is an endpoint of } {\color{lime}e}\}$
-   **return** ${\color{salmon}U}$

#### Randomized Algorithms

-   In many cases, a randomized algorithm is either simpler or faster
  (or both) than a deterministic algorithm.

-   However, it does not guarantee that the algorithm always finds a
  good approximation solution.

-   Theorem 5.1. The expect measure of the solution returned by the
  previous algorithm satisfied the following inequality:

    $$E[m_\text{RWVC}({\color{green}x})] \leq 2 m^*({\color{green}x})$$

-   HW: Implement MWVC solvers using all the above methods. Also extend
  all the methods to handle hypergraph

#### Dynamic Programming (I)

-   One passenger wants to go from city A to city H through the
  _shortest path_ according to the map on the right, where number of
  indicate distance between corresponding cities.

-   Reference: Pablo Pedregal, _Introduction to Optimization_, chapter
  5.8, Springer, 2003

#### Dynamic Programming (II)

-   Proposition 5.24 (Fundamental property of dynamic programming)
  -   If $S({\color{royalblue}t}_j, {\color{green}x})$ denotes the optimal cost from $({\color{royalblue}t}_0, {\color{green}x})$ to
    $({\color{royalblue}t}_j, {\color{green}x})$
  -   then we must have S(${\color{royalblue}t}_{j+1}$, ${\color{green}y}$) =
    min<sub>j</sub> \[S(${\color{royalblue}t}_j$, ${\color{green}x}$) +
    c($j$,${\color{green}x}$,${\color{green}y}$)\]

#### Dynamic Programming (III)

-   According to Proposition 5.24, we must proceed successively to
  determine S(${\color{royalblue}t}_j, {\color{green}x}$) for each ${\color{green}x}$ in
  A<sub>j</sub> to end with S(${\color{royalblue}t}_n, {\color{green}x}_n$). In the
  proposed example, we have four stages ${\color{royalblue}t}_0$, ${\color{royalblue}t}_1$, ${\color{royalblue}t}_2$, ${\color{royalblue}t}_3$
  with associated sets of feasible states

  -   A<sub>0</sub> = {A},
    A<sub>1</sub> = {B, C, D},
    A<sub>2</sub> = {E,F,G},
    A<sub>3</sub> = {H}

-   For each city in A<sub>1</sub>, there is a unique
  path from A, so that it must be optimal, and

  -   S(${\color{royalblue}t}_1$, B) = 7, S(${\color{royalblue}t}_1$, C) = 4, S(${\color{royalblue}t}_1$, D) = 1.

-   For each city in A<sub>2</sub>, we determine the
  optimal cost based on the fundamental property of dynamic
  programming,

  -   S(${\color{royalblue}t}_{j+1}$, ${\color{green}y}$) = min<sub>j</sub> \[S(${\color{royalblue}t}_j$,
    ${\color{green}x}$) + c($j$,${\color{green}x}$,${\color{green}y}$)\]

#### Local Search

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

#### Simulated Annealing

-   **Input**: Instance ${\color{green}x}$;
-   **Output**: Solution ${\color{green}s}$
-   ${\color{royalblue}τ}$ := ${\color{royalblue}t}$;
-   ${\color{green}s}$ := initial feasible solution ${\color{green}s}_0$;
-   **repeat**
  -   **for** $l$ times **do**
    -   Select any unvisited ${\color{green}s}' \in \mathcal{N}({\color{green}x}, {\color{green}s})$
    -   **if** ($m({\color{green}x}, {\color{green}s}')$ < $m({\color{green}x}, {\color{green}s})$)
    -   ${\color{green}s}$ := ${\color{green}s}'$;
    -   **else**
    -   ${\color{royalblue}δ}$ := $m({\color{green}x}, {\color{green}s}') - m({\color{green}x}, {\color{green}s})$;
    -   ${\color{green}s}$ := ${\color{green}s}'$ with probability exp($-{\color{royalblue}δ}/{\color{royalblue}t}$);
  -   ${\color{royalblue}τ}$ := ${\color{royalblue}r} \cdot {\color{royalblue}τ}$; (\* update of temperature \*)
-   **until** FROZEN;
-   **return** ${\color{green}s}$;

#### 📚 Books and Online Resources

-   G. Ausiello et al. Complexity and Approximation: Combinatorial
  Optimization Problems and Their Approximability Properties.
  Springer, 1999. (O224 C737)

-   M. R. Garey and D. S. Johnson. Computers and Intractability: A Guide
  to the Theory of NP-completeness. Freeman, 1979.

-   Pablo Pedregal. Introduction to Optimization. Springer, 2003 (O224
  P371)
