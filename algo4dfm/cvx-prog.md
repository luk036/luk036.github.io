layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Lecture 2c: Introduction to Convex Programming

.pull-left[

## @luk036

2023-09-27

] .pull-right[

![image](figs/dfm.svg)

]

---

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

---

## 🗺️ Overview

- Introduction
- Linear programming
- Nonlinear programming
- Duality and Convexity
- Approximation techniques
- Convex Optimization
- Books and online resources.

---

## Classification of Optimizations

- Continuous
  - Linear vs Non-linear
  - Convex vs Non-convex
- Discrete
  - Polynomial time Solvable
  - NP-hard
    - Approximatable
    - Non-approximatable
- Mixed

---

## Continuous Optimization

![classification](lec02.files/class.svg)

---

## Linear Programming Problem

- An LPP in standard form is:
  $$\min\{ c^\mathsf{T} x \mid A x = b, x \ge 0\}.$$
- The ingredients of LPP are:
  - An $m \times n$ matrix $A$, with $n > m$
  - A vector $b \in \mathbb{R}^m$
  - A vector $c \in \mathbb{R}^n$

---

## Example

$$
\begin{array}{lll}
  \text{minimize} & 0.4 x_1 + 3.4 x_2 - 3.4 x_3 \\
  \text{subject to} & 0.5 x_1 + 0.5 x_2  & = 3.5 \\
  & 0.3 x_1 - 0.8 x_2 + 8.4 x_2 & = 4.5 \\
  & x_1, x_2, x_3 \ge 0
\end{array}
$$

---

## Transformations to Standard Form

- Theorem: Any LPP can be transformed into the standard form.
- Variables not restricted in sign:
  - Decompose $x$ to two new variables
    $x = x_1 - x_2, x_1, x_2 \geq 0$
- Transforming inequalities into equalities:
  - By putting slack variable $y = b - A x \geq 0$
  - Set $x' = (x, y), A' = (A, 1)$
- Transforming a max into a min
  - max(expression) = min($-$expression);

---

## Duality of LPP

- If the primal problem of the LPP:
  $\min\{ c^\mathsf{T} x \mid A x \ge b, x \ge 0\}$.
- Its dual is:
  $\max\{ y^\mathsf{T} b \mid A^\mathsf{T} y \leq c, y \ge 0\}$.
- If the primal problem is:
  $\min\{ c^\mathsf{T} x \mid A x = b, x \ge 0\}$.
- Its dual is: $\max\{ y^\mathsf{T} b \mid A^\mathsf{T} y \leq c\}$.

---

## Nonlinear Programming

- The standard form of an NLPP is
  $$\min\{f(x) \mid g(x) \leq 0, h(x)=0 \}.$$
- Necessary conditions of optimality, Karush- Kuhn-Tucker (KKT)
  conditions:

  - Gradient Condition: ∇f(x) + µ∇g(x) + λ∇h(x) = 0, where ∇f(x),
    ∇g(x), and ∇h(x) are the gradients of the objective function,
    inequality constraints, and equality constraints, respectively.
    This condition states that the sum of the directional
    derivatives of the objective function and the constraints must
    be zero at the optimal solution.

  - Complementary Slackness Condition: µg(x) = 0, where µ is a
    Lagrange multiplier associated with the inequality constraints.
    This condition implies that either the constraint is inactive
    (g(x) ≤ 0) or its corresponding Lagrange multiplier is zero.

  - Feasibility Condition: µ ≥ 0, g(x) ≤ 0, h(x) = 0. This condition
    ensures that the inequality and equality constraints are
    satisfied at the optimal solution.

---

## What is the significance of the KKT conditions mentioned?

The significance of the KKT conditions lies in their ability to provide
necessary conditions for a solution to be optimal in nonlinear
programming problems. By satisfying these conditions, a point can be
determined as a possible optimal solution. Moreover, if the objective
function is strictly convex, and the KKT conditions are satisfied, then
the solution obtained is the unique optimal solution. In essence, the
KKT conditions serve as a powerful mathematical tool for analyzing and
solving optimization problems.

---

## Convexity

- A function $f$: $K \subseteq \mathbb{R}^n \mapsto R$ is convex if
  $K$ is a convex set and
  $f(y) \ge f(x) + \nabla f(x) (y - x), \; y,x \in K$.

- **Theorem**: Assume that $f$ and $g$ are convex differentiable
  functions. If the pair $(x, m)$ satisfies the KKT conditions above,
  $x$ is an optimal solution of the problem. If in addition, $f$ is
  strictly convex, $x$ is the only solution of the problem.

  **(Local minimum = global minimum)**

---

## Duality and Convexity

- Dual is the NLPP: $$\max\{\theta(\mu, \lambda) \mid \mu \geq 0\},$$
  where
  $\theta(\mu, \lambda) = \inf_x [ f(x) + \mu g(x) + \lambda h(x) ]$

- Dual problem is always convex.

- Useful for computing the lower/upper bound.

---

## Applications

- Statistics
- Filter design
- Power control
- Machine learning
  - SVM classifier
  - logistic regression

---

class: nord-light, middle, center

# Convexify the non-convex's

---

## Change of curvature: square

Transform: $$0.3 \leq {\color{red} \sqrt{x} } \leq 0.4$$ into:
$$0.09 \leq {\color{green} x} \leq 0.16 \, .$$

👉 Note that $\sqrt{\cdot}$ are **monotonic** **concave** functions in
$(0, +\infty)$.

Generalization:

- Consider $|H(\omega)|^2$ (power) instead of $|H(\omega)|$ (magnitude).
- square root -> Spectral factorization

---

## Change of curvature: square

Transform:
$${\color{red} x^2 } + {\color{red} y^2 } \geq 0.16, \quad \text{(non-convex)}$$
into:
$${\color{green} x'} + {\color{green} y'} \geq 0.16, \quad x', y' \geq 0$$
Then:
$$x_\text{opt} = \pm\sqrt{x'_\text{opt} }, \quad y_\text{opt} = \pm\sqrt{y'_\text{opt} }.$$

---

## Change of curvature: sine

Transform:
$${\color{red} \sin^2{x} } \leq 0.4, \quad 0 \leq x \leq \pi/2$$ into:
$${\color{green} y} \leq 0.4, \quad 0 \leq y \leq 1$$ Then:
$$x_\text{opt} = \sin^{-1}(\sqrt{y_\text{opt} }).$$

👉 Note that $\sin(\cdot)$ are monotonic concave functions in
$(0, \pi/2)$.

---

## Change of curvature: log

Transform: $$\pi \leq {\color{red} x / y} \leq \phi$$ into:
$$\pi' \leq {\color{green} x' - y'} \leq \phi'$$ where $z' = \log(z)$.

Then: $$z_\text{opt} = \exp(z'_\text{opt}).$$

Generalization: - Geometric programming

---

## Change of curvature: inverse

Transform: $${\color{red} \log(x) + \frac{c}{x} } \leq 0.3, \; x > 0$$
into: $${\color{green} -\log(y) + c \cdot y } \leq 0.3, \; y > 0 \, .$$

Then: $$x_\text{opt} = y^{-1}_\text{opt}.$$

👉 Note that $\sqrt{\cdot}$, $\log(\cdot)$, and $(\cdot)^{-1}$ are
monotonic functions.

---

## Generalize to matrix inequalities

Transform:
$${\color{red} \log(\det X) + \text{Tr}(X^{-1} C)} \leq 0.3, \; X \succ 0$$
into:
$${\color{green} -\log(\det Y) + \text{Tr}(Y \cdot C)} \leq 0.3, \; Y \succ 0$$

Then: $$X_\text{opt} = Y^{-1}_\text{opt}.$$

---

## Change of variables

Transform: $$(a +  b \cdot {\color{red} y}) x \leq 0, \; x > 0$$

into: $$a \cdot x + b \cdot {\color{green} z} \leq 0, \; x > 0$$ where
$z = y x$.

Then: $$y_\text{opt} = z_\text{opt} x^{-1}_\text{opt}$$

---

## Generalize to matrix inequalities

Transform:
$$(A + B {\color{red} Y}) X + X (A + B {\color{red} Y})^T  \prec 0, \; X \succ 0$$

into:
$$A X + X A^T + B {\color{green} Z} + {\color{green} Z}^T B^T \prec 0, \; X \succ 0$$
where $Z = Y X$.

Then: $$Y_\text{opt} = Z_\text{opt} X^{-1}_\text{opt}$$

---

## Some operations that preserve convexity

- $-f$ is concave if and only if $f$ is convex.
- Nonnegative weighted sums:
  - if $w_1, \ldots, w_n \ge 0$ and $f_1, \ldots, f_n$ are all
    convex, then so is $w_1 f_1 + \cdots + w_n f_n.$ In particular,
    the sum of two convex functions is convex.
- Composition:
  - If $f$ and $g$ are convex functions and $g$ is non-decreasing
    over a univariate domain, then $h(x) = g(f(x))$ is convex. As an
    example, if $f$ is convex, then so is $e^{f(x)},$ because $e^x$
    is convex and monotonically increasing.
  - If $f$ is concave and $g$ is convex and non-increasing over a
    univariate domain, then $h(x) = g(f(x))$ is convex.
  - Convexity is invariant under affine maps.

---

## Other thoughts

- Minimizing any quasi-convex function subject to convex constraints
  can easily be transformed into a convex programming.
- Replace a non-convex constraint with a sufficient condition (such as
  its lower bound). Less optimal.
- Relaxation + heuristic
- Decomposition

---

## Unconstraint Techniques

- Line search methods
- Fixed or variable step size
- Interpolation
- Golden section method
- Fibonacci's method
- Gradient methods
- Steepest descent
- Quasi-Newton methods
- Conjugate Gradient methods

---

## General Descent Method

1.  **Input**: a starting point $x \in$ dom $f$
2.  **Output**: $x^*$
3.  **repeat**
    1.  Determine a descent direction $p$.
    2.  Line search. Choose a step size $\alpha > 0$.
    3.  Update. $x := x + \alpha p$
4.  **until** stopping criterion satisfied.

---

## Some Common Descent Directions

- Gradient descent: $p = -\nabla f(x)^\mathsf{T}$
- Steepest descent:
  - $\triangle x_{nsd}$ =
    argmin$\{\nabla f(x)^\mathsf{T} v \mid \|v\|=1 \}$
  - $\triangle x$ = $\|\nabla f(x)\| \triangle x_{nsd}$
    (un-normalized)
- Newton's method:
  - $p = -\nabla^2 f(x)^{-1} \nabla f(x)$
- Conjugate gradient method:
  - $p$ is "orthogonal" to all previous $p$'s
- Stochastic subgradient method:
  - $p$ is calculated from a set of sample data (instead of using
    all data)
- Network flow problems:
  - $p$ is given by a "negative cycle" (or "negative cut").

---

## Approximation Under Constraints

- Penalization and barriers
- Dual method
- Interior Point method
- Augmented Lagrangian method

---

## 📚 Books and Online Resources

- Pablo Pedregal. Introduction to Optimization, Springer. 2003 (O224
  P371)
- Stephen Boyd and Lieven Vandenberghe, Convex Optimization, Dec. 2002
- Mittlemann, H. D. and Spellucci, P. Decision Tree for Optimization
  Software, World Wide Web, http://plato.la.asu.edu/guide.html, 2003

---

class: nord-dark, middle, center

.pull-left[

# Q & A 🙋️

] .pull-right[

![image](figs/questions-and-answers.svg)

]
