# Lecture 2c: Introduction to Convex Programming

@luk036 👨‍💻 · 2026 📅

## 📝 Abstract

This lecture provides an introduction to the convex programming and covers various aspects of optimization. The lecture begins with an overview of optimization, including linear and nonlinear programming, duality and convexity, and approximation techniques. It then delves into more specific topics within continuous optimization, such as linear programming problems and their standard form, transformations to standard form, and the duality of linear programming problems. The lecture also touches on nonlinear programming, discussing the standard form of an NLPP (nonlinear programming problem) and the necessary conditions of optimality known as the Karush-Kuhn-Tucker (KKT) conditions. Convexity is another important concept explored in the document, with explanations on the definition of convex functions and their properties. The lecture also discusses the duality of convex optimization problems and their usefulness in computation. Finally, the document briefly mentions various unconstrained optimization techniques, descent methods, and approximation methods under constraints.

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
  $$\min\{ {\color{coral} c}^\mathsf{T} {\color{green} x} \mid {\color{coral} A} {\color{green} x} = {\color{coral} b}, {\color{green} x} \ge 0\}.$$
-   The ingredients of LPP are:
  -   An ${\color{coral} m} \times {\color{coral} n}$ matrix ${\color{coral} A}$, with ${\color{coral} n} > {\color{coral} m}$
  -   A vector ${\color{coral} b} \in \mathbb{R}^{\color{coral} m}$
  -   A vector ${\color{coral} c} \in \mathbb{R}^{\color{coral} n}$

### 📚 Example

$$
\begin{array}{lll}
  \text{minimize} & 0.4 {\color{green} x_1} + 3.4 {\color{green} x_2} - 3.4 {\color{green} x_3} \\
  \text{subject to} & 0.5 {\color{green} x_1} + 0.5 {\color{green} x_2} & = 3.5 \\
  & 0.3 {\color{green} x_1} - 0.8 {\color{green} x_2} + 8.4 {\color{green} x_2} & = 4.5 \\
  & {\color{green} x_1}, {\color{green} x_2}, {\color{green} x_3} \ge 0
\end{array}
$$

### Transformations to Standard Form

-   Theorem: Any LPP can be transformed into the standard form.
-   Variables not restricted in sign:
  -   Decompose ${\color{green} x}$ to two new variables
    ${\color{green} x} = {\color{green} x_1} - {\color{green} x_2}, {\color{green} x_1}, {\color{green} x_2} \geq 0$
-   Transforming inequalities into equalities:
  -   By putting slack variable ${\color{firebrick} y} = {\color{coral} b} - {\color{coral} A} {\color{green} x} \geq 0$
  -   Set ${\color{green} x'} = ({\color{green} x}, {\color{firebrick} y}), {\color{coral} A'} = ({\color{coral} A}, 1)$
-   Transforming a max into a min
  -   max(expression) = min($-$expression);

### Duality of LPP

-   If the primal problem of the LPP:
  $\min\{ {\color{coral} c}^\mathsf{T} {\color{green} x} \mid {\color{coral} A} {\color{green} x} \ge {\color{coral} b}, {\color{green} x} \ge 0\}$.
-   Its dual is:
  $\max\{ {\color{firebrick} y}^\mathsf{T} {\color{coral} b} \mid {\color{coral} A}^\mathsf{T} {\color{firebrick} y} \leq {\color{coral} c}, {\color{firebrick} y} \ge 0\}$.
-   If the primal problem is:
  $\min\{ {\color{coral} c}^\mathsf{T} {\color{green} x} \mid {\color{coral} A} {\color{green} x} = {\color{coral} b}, {\color{green} x} \ge 0\}$.
-   Its dual is: $\max\{ {\color{firebrick} y}^\mathsf{T} {\color{coral} b} \mid {\color{coral} A}^\mathsf{T} {\color{firebrick} y} \leq {\color{coral} c}\}$.

### Nonlinear Programming

-   The standard form of an NLPP is
  $$\min\{f({\color{green} x}) \mid g({\color{green} x}) \leq 0, h({\color{green} x})=0 \}.$$
-   Necessary conditions of optimality, Karush- Kuhn-Tucker (KKT)
  conditions:
  -   $\nabla f({\color{green} x}) + {\color{firebrick} \mu} \nabla g({\color{green} x}) + {\color{firebrick} \lambda} \nabla h({\color{green} x}) = 0$,
  -   ${\color{firebrick} \mu} g({\color{green} x}) = 0$,
  -   ${\color{firebrick} \mu} \geq 0, g({\color{green} x}) \leq 0, h({\color{green} x}) = 0$

### Convexity

-   A function $f$: ${\color{salmon} K} \subseteq \mathbb{R}^{\color{coral} n} \mapsto R$ is convex
  if ${\color{salmon} K}$ is a convex set and
  $f({\color{green} y}) \ge f({\color{green} x}) + \nabla f({\color{green} x}) ({\color{green} y} - {\color{green} x}), \; {\color{green} y},{\color{green} x} \in {\color{salmon} K}$.

-   **Theorem**: Assume that $f$ and $g$ are convex differentiable
  functions. If the pair $({\color{green} x}, m)$ satisfies the KKT conditions above,
  ${\color{green} x}$ is an optimal solution of the problem. If in addition, $f$ is
  strictly convex, ${\color{green} x}$ is the only solution of the problem.

## (Local minimum = global minimum)

### Duality and Convexity

-   Dual is the NLPP: $$\max\{\theta({\color{firebrick} \mu}, {\color{firebrick} \lambda}) \mid {\color{firebrick} \mu} \geq 0\},$$
  where
  $\theta({\color{firebrick} \mu}, {\color{firebrick} \lambda}) = \inf_{\color{green} x} [ f({\color{green} x}) + {\color{firebrick} \mu} g({\color{green} x}) + {\color{firebrick} \lambda} h({\color{green} x}) ]$

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

Transform:
$$0.3 \leq {\color{red} \sqrt{x} } \leq 0.4$$
into:
$$0.09 \leq {\color{green} x} \leq 0.16 \, .$$

👉 Note that $\sqrt{\cdot}$ are **monotonic** **concave** functions in $(0, +\infty)$.

Generalization:

-   Consider $|H({\color{coral} \omega})|^2$ (power) instead of $|H({\color{coral} \omega})|$ (magnitude).
-   square root -> Spectral factorization

#### Change of curvature: square

Transform:
$${\color{red} x^2 } + {\color{red} y^2 } \geq 0.16, \quad \text{(non-convex)}$$
into:
$${\color{green} x'} + {\color{green} y'} \geq 0.16, \quad {\color{green} x'}, {\color{green} y'} \geq 0$$
Then:
$${\color{red} x}_\text{opt} = \pm\sqrt{{\color{green} x'}_\text{opt} }, \quad {\color{red} y}_\text{opt} = \pm\sqrt{{\color{green} y'}_\text{opt} }.$$

#### Change of curvature: sine

Transform:
$${\color{red} \sin^2{x} } \leq 0.4, \quad 0 \leq {\color{red} x} \leq \pi/2$$
into:
$${\color{green} y} \leq 0.4, \quad 0 \leq {\color{green} y} \leq 1$$
Then:
$${\color{red} x}_\text{opt} = \sin^{-1}(\sqrt{{\color{green} y}_\text{opt} }).$$

👉 Note that $\sin(\cdot)$ are monotonic concave functions in $(0, \pi/2)$.

#### Change of curvature: log

Transform:
$$\pi \leq {\color{red} x / y} \leq \phi$$
into:
$$\pi' \leq {\color{green} x' - y'} \leq \phi'$$
where ${\color{green} z'} = \log({\color{red} z})$.

Then:
$${\color{red} z}_\text{opt} = \exp({\color{green} z'}_\text{opt}).$$

Generalization:

-   Geometric programming

#### Change of curvature: inverse

Transform:
$${\color{red} \log(x) + \frac{c}{x} } \leq 0.3, \; {\color{red} x} > 0$$
into:
$${\color{green} -\log(y) + c \cdot y } \leq 0.3, \; {\color{green} y} > 0 \, .$$

Then:
$${\color{red} x}_\text{opt} = {\color{green} y}^{-1}_\text{opt}.$$

👉 Note that $\sqrt{\cdot}$, $\log(\cdot)$, and $(\cdot)^{-1}$ are monotonic functions.

#### Generalize to matrix inequalities

Transform:
$${\color{red} \log(\det X) + \text{Tr}(X^{-1} C)} \leq 0.3, \; {\color{red} X} \succ 0$$
into:
$${\color{green} -\log(\det Y) + \text{Tr}(Y \cdot C)} \leq 0.3, \; {\color{green} Y} \succ 0$$

Then:
$${\color{red} X}_\text{opt} = {\color{green} Y}^{-1}_\text{opt}.$$

#### Change of variables

Transform:
$$(a + b \cdot {\color{red} y}) x \leq 0, \; x > 0$$

into:
$$a \cdot x + b \cdot {\color{green} z} \leq 0, \; x > 0$$
where ${\color{green} z} = {\color{red} y} x$.

Then:
$${\color{red} y}_\text{opt} = {\color{green} z}_\text{opt} x^{-1}_\text{opt}$$

#### Generalize to matrix inequalities

Transform:
$$(A + B {\color{red} Y}) X + X (A + B {\color{red} Y})^T \prec 0, \; X \succ 0$$

into:
$$A X + X A^T + B {\color{green} Z} + {\color{green} Z}^T B^T \prec 0, \; X \succ 0$$
where ${\color{green} Z} = {\color{red} Y} X$.

Then:
$${\color{red} Y}_\text{opt} = {\color{green} Z}_\text{opt} X^{-1}_\text{opt}$$

#### Some operations that preserve convexity

-   $-f$ is concave if and only if $f$ is convex.
-   Nonnegative weighted sums:
  -   if ${\color{coral} w}_1, \ldots, {\color{coral} w}_n \ge 0$ and $f_1, \ldots, f_n$ are all convex, then so is ${\color{coral} w}_1 f_1 + \cdots + {\color{coral} w}_n f_n.$ In particular, the sum of two convex functions is convex.
-   Composition:
  -   If $f$ and $g$ are convex functions and $g$ is non-decreasing over a univariate domain, then $h({\color{green} x}) = g(f({\color{green} x}))$ is convex. As an example, if $f$ is convex, then so is $e^{f({\color{green} x})},$ because $e^{{\color{green} x}}$ is convex and monotonically increasing.
  -   If $f$ is concave and $g$ is convex and non-increasing over a univariate domain, then $h({\color{green} x}) = g(f({\color{green} x}))$ is convex.
  -   Convexity is invariant under affine maps.

#### Other thoughts

-   Minimizing any quasi-convex function subject to convex constraints can easily be
  transformed into a convex programming.
-   Replace a non-convex constraint with a sufficient condition
  (such as its lower bound). Less optimal.
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

1. **Input**: a starting point ${\color{green} x} \in$ dom $f$
2. **Output**: ${\color{green} x}^*$
3. **repeat**
    1. Determine a descent direction ${\color{green} p}$.
    2. Line search. Choose a step size ${\color{coral} \alpha} > 0$.
    3. Update. ${\color{green} x} := {\color{green} x} + {\color{coral} \alpha} {\color{green} p}$
4. **until** stopping criterion satisfied.

#### Some Common Descent Directions

-   Gradient descent: ${\color{green} p} = -\nabla f({\color{green} x})^\mathsf{T}$
-   Steepest descent:
  -   $\triangle {\color{green} x}_{nsd} = \argmin\{\nabla f({\color{green} x})^\mathsf{T} {\color{green} v} \mid \|{\color{green} v}\|=1 \}$
  -   $\triangle {\color{green} x}$ = $\|\nabla f({\color{green} x})\| \triangle {\color{green} x}_{nsd}$
    (un-normalized)
-   Newton's method:
  -   ${\color{green} p} = -\nabla^2 f({\color{green} x})^{-1} \nabla f({\color{green} x})$
-   Conjugate gradient method:
  -   ${\color{green} p}$ is "orthogonal" to all previous ${\color{green} p}$'s
-   Stochastic subgradient method:
  -   ${\color{green} p}$ is calculated from a set of sample data (instead of using all data)
-   Network flow problems:
  -   ${\color{green} p}$ is given by a "negative cycle" (or "negative cut").

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

## Non-Parametric Spatial Correlation Estimation

### Abstract

This lecture discusses non-parametric spatial correlation estimation and its importance in analyzing the variability in semiconductor devices. The intra-die variation in these devices can exhibit spatially correlated patterns, which require accurate statistical analysis during the design stage. Anisotropic models are used to allow for variations in gate length, which exhibit stronger correlation in the horizontal ↔️ direction than the vertical ↕️ direction. Non-parametric approaches make sense for correlation functions, as earlier studies that used parametric forms were limited by the assumptions made about the correlation function. This lecture goes on to describe random fields and the properties of correlation functions before diving into problem formulation and solutions using maximum likelihood estimation and least squares estimation.

#### Overview 📋

-   Motivation:
  -   Why is spatial correlation important?
  -   Why anisotropic models?
  -   Why do non-parametric approaches make sense?
-   Problem Formulation
-   Non-parametric estimation
  -   Least squares estimation
  -   Maximum Likelihood estimation
-   Numerical experiment
-   Conclusion

#### Why Spatial Correlation?

-   As the minimum feature size of semiconductor devices continues to shrink,
  -   Process variations are inevitable. It is desirable to develop more accurate statistical analysis during the design stage.
-   Intra-die variation exceeds inter-die variation
  -   Becomes dominant over total process variation
  -   Often exhibits spatially correlated patterns.
-   Applications:
  -   Statistical timing analysis -> Clock Skew Scheduling
  -   Power/leakage minimization

#### Why Anisotropic Model?

-   Isotropic assumption assumes that the correlation depends only on the distance between two random variables. It was made to simplify the computation.
-   Certain variations, such variations in gate length, exhibit significantly stronger correlation in the horizontal ↔️ direction than in the vertical ↕️ direction.

#### Why Non-Parametric Approaches?

-   In earlier studies, the parametric form of the correlation function was simple, such as an exponential, Gaussian or Matérn function:
-   Pros: guaranteed to be **positive definite**.
-   Cons:
  -   non-convex; may be stuck in a local minimum
  -   The actual correlation function may not necessarily be of this form.
  -   isotropic model

#### Related research 🔬🧪

-   Piecewise linearization method (imprecise, not positive definite)
-   Parametric method (non-convex, too smooth, isotropic)
  -   Exponential function
  -   Gaussian function
  -   Matérn function
-   Non-parametric method
  -   Polynomial fitting
  -   B-spline

#### Random Field

-   Random field is an indexed family of random variables denote as
  $\{{\color{green}\tilde{z}}(s): s \in {\color{salmon} D}\}$, where ${\color{salmon} D} \subseteq \mathrm{R}^{\color{coral} d}$
-   Covariance $C(s_i, s_j)$ = $\text{cov}({\color{green}\tilde{z}}(s_i),{\color{green}\tilde{z}}(s_j))$ =
  $\mathrm{E}[({\color{green}\tilde{z}}(s_i) - \mathrm{E}[{\color{green}\tilde{z}}(s_i)]) ({\color{green}\tilde{z}}(s_j) - \mathrm{E}[{\color{green}\tilde{z}}(s_j)])]$
-   Correlation
  $R(s_i, s_j) = C(s_i, s_j)/\sqrt{C(s_i, s_i) C(s_j, s_j)}$
-   The field is stationary, or homogeneous, if the distribution is
  unchanged when the point set is translated.
-   The field is isotropic if the distribution is invariant under any
  rotation.
-   In HIF, let ${\color{coral} d} = \| s_i - s_j \|_2$:
  -   $C(s_i, s_j) = C({\color{coral} d})$
  -   $R(s_i, s_j) = C({\color{coral} d})/C(0) = {\color{coral} \sigma^2} \rho({\color{coral} d})$

#### Properties of Correlation Function

-   Even function, i.e. $\rho({\color{coral} \vec{h}}) = \rho(-{\color{coral} \vec{h}}) \implies$ its Fourier transform
  is real.
-   Positive definiteness (PD) $\implies$ its Fourier transform is positive
  (Bochner's theorem).
-   Monotonicity: correlations are decreasing against ${\color{coral} h}$ 🤔
-   Nonnegativeness: no negative correlation 🤔
-   Discontinuity at the origin: nugget effect.

The nugget effect refers to the discontinuity at the origin in the correlation function of spatially correlated patterns. It indicates the presence of a small, non-zero correlation value between points that are very close to each other. In other words, it represents the variance component that cannot be explained by spatial correlation and is attributed to purely random variation.

#### Problem Formulation

-   Intra-die variation
  ${\color{green}\tilde{z}} = {\color{green}z}_{det} + {\color{green}\tilde{z}}_{cor} + {\color{green}\tilde{z}}_{rnd}$
  -   ${\color{green}z}_{det}$: deterministic component
  -   ${\color{green}\tilde{z}}_{cor}$: correlated random component
  -   ${\color{green}\tilde{z}}_{rnd}$: purely random component
-   Given ${\color{coral} M}$ samples $({\color{green}z}_1, {\color{green}z}_2, \ldots, {\color{green}z}_M) \in \mathbb{R}^{\color{coral} n}$.
-   Measured covariance matrix ${\color{coral} Y}$:
  -   ${\color{coral} Y} = (1/{\color{coral} M}) \sum_{i=1}^{\color{coral} M} {\color{green}z}_i {\color{green}z}_i^\mathsf{T}$ (unlikely PD)
-   In MATLAB, simply call `cov(Zs',1)` to obtain ${\color{coral} Y}$.
-   In Python, simple call `np.cov(Zs, bias=True)` to obtain ${\color{coral} Y}$.

#### Nearest PD Matrix Problem

-   Given ${\color{coral} Y}$. Find a nearest matrix ${\color{green} \Sigma}$ that is positive definite.

  $$
  \begin{array}{ll}
      \text{minimize}   & \| {\color{green} \Sigma} - {\color{coral} Y} \|_F \\
      \text{subject to} & {\color{green} \Sigma} \succeq 0
    \end{array}
  $$

    where $\| {\color{green} \Sigma} - {\color{coral} Y} \|_F$ denotes the Frobenius norm, $A \succeq 0$ denotes $A$ is positive semidefinite.

-   👉 Note:
  1. the problem is convex 😃
  2. the problem can be solved easily using CVX 😃

#### Maximum Likelihood Estimation

-   Maximum likelihood estimation (MLE):
  $$
  \begin{array}{ll}
        \text{maximize} & \log \det {\color{green} \Sigma}^{-1} - \mathrm{Tr}({\color{green} \Sigma}^{-1}{\color{coral} Y}) \\
        \text{subject to} & {\color{green} \Sigma} \succeq 0
  \end{array}
  $$
  where $\mathrm{Tr}(A)$ denotes the trace of $A$.
-   👉 Note: 1st term is concave 😭, 2nd term is convex

#### Maximum Likelihood Estimation (cont'd)

-   Having ${\color{green} S} = {\color{green} \Sigma}^{-1}$, the problem becomes convex 😃:
  $$
  \begin{array}{ll}
      \text{minimize} & -\log \det {\color{green} S} + \mathrm{Tr}({\color{green} S} {\color{coral} Y}) \\
      \text{subject to} & {\color{green} S} \succeq 0
    \end{array}
  $$
-   👉 Note: the problem can be solved easily using MATLAB with the CVX
  package, or using Python with the cvxpy package.

#### Matlab Code of CVX

```matlab
function Sig = log_mle_solver(Y);
ndim = size(Y,1);
cvx_quiet(false);
cvx_begin sdp
    variable S(ndim, ndim) symmetric
    maximize(log_det(S) - trace(S*Y))
    subject to
         S >= 0;
cvx_end
Sig = inv(S);
```

#### 🐍 Python Code

```python
from cvxpy import *
from scipy import linalg

def mle_corr_mtx(Y):
  ndim = len(Y)
  S = Semidef(ndim)
  prob = Problem(Maximize(log_det(S) - trace(S*Y)))
  prob.solve()
  if prob.status != OPTIMAL:
      raise Exception('CVXPY Error')
  return linalg.inv(S.value)
```

#### Correlation Function (I)

-   Let $\rho({\color{coral} h}) = \sum_i^{\color{coral} m} {\color{green}p}_i \Psi_i({\color{coral} h})$, where
  -   ${\color{green}p}_i$'s are the unknown coefficients to be fitted
  -   $\Psi_i$'s are a family of basis functions.
-   Let $\{{\color{coral}F_k}\}_{i,j} =\Psi_k( \| s_i - s_j \|_2)$.

-   The covariance matrix $\Omega(p)$ can be recast as:
  $$\Omega({\color{green}p}) = {\color{green}p}_1 {\color{coral}F_1} + \cdots + {\color{green}p}_m {\color{coral}F_m}$$

-   Note 1: affine transformation preserved convexity

-   Note 2: inverse of matrix unfortunately **cannot** be expressed in
  convex form.

#### Correlation Function (II)

-   Choice of $\Psi_i({\color{coral} h})$:
  -   Polynomial $P_i({\color{coral} h})$:
    -   Easy to understand 👍
    -   No guarantee of monotonicity; unstable for higher-order polynomials.
  -   B-spline function $B_i({\color{coral} h})$
    -   Shapes are easier to control 👍
    -   No guarantee of positive definite 👎

#### Correlation Function (III)

-   To ensure that the resulting function is PD, additional constraints can be imposed according to Bochner's theorem, e.g.:
  -   real(FFT($\{\Psi_i({\color{coral} h_k})\}$)) $\geq 0$

Bochner's theorem states that a continuous function is a valid covariance function if and only if its Fourier transform is a non-negative measure. In other words, a function can be a valid covariance function if and only if its Fourier transform is positive definite. This theorem is important in spatial statistics because it provides a way to check whether a given covariance function is valid or not.

#### Non-Parametric Estimation

-   Least squares estimation

  $$
  \begin{array}{ll}
    \min_{{\color{green}\kappa}, {\color{green}p}}   & \| \Omega({\color{green}p}) + {\color{green}\kappa} I - {\color{coral} Y} \|_F \\
    \text{s.t.} & \Omega({\color{green}p}) \succeq 0, {\color{green}\kappa} \geq 0
  \end{array}
  $$

    👉 Note: convex problem 😃

-   Maximum likelihood estimation (MLE):
  $$
  \begin{array}{ll}
    \min_{{\color{green}\kappa}, {\color{green}p}} & \log \det (\Omega({\color{green}p}) + {\color{green}\kappa} I) + \mathrm{Tr}((\Omega({\color{green}p}) + {\color{green}\kappa} I)^{-1}{\color{coral} Y}) \\
    \text{s.t.} & \Omega({\color{green}p}) \succeq 0, {\color{green}\kappa} \geq 0
  \end{array}
  $$
  👉 Note:
  -   The 1st term is concave 😭, the 2nd term is convex
  -   However, the problem is **geodesically convex**.
  -   If enough samples are available, then ${\color{coral} Y} \succeq 0$. Furthermore, the
    MLE is a convex problem in
    ${\color{coral} Y} \preceq \Omega({\color{green}p}) + {\color{green}\kappa} I \preceq 2{\color{coral} Y}$

#### Isotopic Case I

.pull-left[

![img](lec03b.files/data2d01.svg)

: Data Sample

] .pull-right[

![img](lec03b.files/corr_nonpar01.svg)

: Least Square Result

]

#### Isotopic Case II

.pull-left[

![img](lec03b.files/data2d.svg)

: Data Sample

] .pull-right[

![img](lec03b.files/corr_nonpar.svg)

: Least Square Result

]

#### 🥚 Convex Concave Procedure

-   Let ${\color{green} \Sigma} = \Omega + {\color{green}\kappa} I$. Log-likelihood function is:
  -   $\log \det {\color{green} \Sigma}^{-1} - \mathrm{Tr}({\color{green} \Sigma}^{-1}{\color{coral} Y})$
-   Convexify the first term using the fact:
  -   $\log \det {\color{green} \Sigma}^{-1} \geq \log \det {\color{green} \Sigma}_0^{-1} + \mathrm{Tr}({\color{green} \Sigma}_0^{-1} ({\color{green} \Sigma} - {\color{green} \Sigma}_0))$
  -   minimize:
    $-\log \det {\color{green} \Sigma}_0^{-1} + \mathrm{Tr}({\color{green} \Sigma}_0^{-1} ({\color{green} \Sigma} - {\color{green} \Sigma}_0)) + \mathrm{Tr}({\color{green} \Sigma}^{-1}{\color{coral} Y})$
-   At each iteration ${\color{coral} k}$, the following convex problem is solved:
  $$
  \begin{array}{ll}
      \min & \mathrm{Tr}({\color{green} \Sigma}_k^{-1} ({\color{green} \Sigma} - {\color{green} \Sigma}_k)) + \mathrm{Tr}({\color{green} S}{\color{coral} Y}) \\
      \text{s.t.} & \left(
      \begin{array}{cc}
    {\color{green} \Sigma} & I_n \\
     I_n & {\color{green} S}
      \end{array}
    \right)
          \succeq 0, {\color{green}\kappa} \geq 0
    \end{array}
  $$
  👉 Note: Convergence to an optimal solution is not guaranteed, but is practically good.

#### MATLAB Code

```matlab
% Geometric anisotropic parameters
alpha = 2;     % scaling factor
theta = pi/3;  % angle
Sc = [1   0; 0   alpha];
R = [sin(theta) cos(theta); -cos(theta) sin(theta)];
T = Sc*R;
Sig = ones(n,n);
for i=1:n-1,
   for j=i+1:n,
     dt = s(j,:)' - s(i,:)';
     d = T*dt;  % become isotropic after the location transformation
     Sig(i,j) = exp(-0.5*(d'*d)/(sdkern*sdkern)/2);
     Sig(j,i) = Sig(i,j);
   end
end
```

#### Anisotopic Data

![img](lec03b.files/aniso_data.svg)

#### Isotropic Result

![img](lec03b.files/iso2d.svg)

#### Anisotropic Result

![img](lec03b.files/exp2da.svg)

#### 🔮 Furue Work

-   Porting MATLAB code to Python 🐍
-   Real data, not computer generated data
-   Barycentric B-spline.
-   Sampling method optimization.
