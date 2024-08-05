layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Convexify the Non-convex's

@luk036

2024-08-05

---

## Abstract

Convexifying a non-convex function through change of variables and transformations is a powerful technique in optimization. This process involves transforming the original problem into a new problem where the objective function and constraints become convex. Here are some common strategies for achieving this.

---

### Logarithmic Transformation

#### Example: Geometric Programming

Geometric programming problems often involve posynomials, which are sums of monomials. A typical posynomial is non-convex, but applying a logarithmic transformation can convexify it.

**Original Problem:**

$$
\text{minimize} \quad f(x) = \sum_{i=1}^{n} c_i \prod_{j=1}^{m} x_j^{a_{ij} }
$$

**Transformation:**
Let $y_j = \log(x_j)$ for all $j$. The problem becomes:

$$
\text{minimize} \quad \log(f(x)) = \log \left( \sum_{i=1}^{n} c_i \exp \left( \sum_{j=1}^{m} a_{ij} y_j \right) \right)
$$

This transformed problem is convex in $y_j$.

---

### Reciprocal Transformation

#### Example: Convexifying Rational Functions

For a rational function where the numerator is convex and the denominator is affine, a reciprocal transformation can help.

**Original Problem:**
$$\text{minimize} \quad \frac{f(x)}{g(x)}$$

**Transformation:**
Let $y = \frac{1}{g(x)}$. The problem becomes:
$$\text{minimize} \quad f(x) y \quad \text{subject to} \quad g(x) y = 1$$

This can transform the problem into a convex form, depending on the specific functions $f(x)$ and $g(x)$.

---

### Exponential Transformation

#### Example: Exponential Utility Functions

For problems involving exponential utility functions, an exponential transformation can be useful.

**Original Problem:**
$$\text{minimize} \quad -\exp(f(x))$$

**Transformation:**
Let $y = \exp(f(x))$. The problem becomes:
$$\text{minimize} \quad -y \quad \text{subject to} \quad y = \exp(f(x))$$

This can help in transforming the problem into a convex form.

---

### Change of Variables

#### Example: Power Transformation

For certain power functions, a change of variables can help.

**Original Problem:**
$$\text{minimize} \quad f(x) = x^p \quad \text{for} \quad p < 1$$

**Transformation:**
Let $y = x^p$. The problem becomes:
$$\text{minimize} \quad y \quad \text{subject to} \quad y = x^p$$

This can help in transforming the problem into a convex form.

---

### Perspective Transformation

#### Example: Perspective Function

For certain functions, applying a perspective transformation can help.

**Original Problem:**
$$\text{minimize} \quad \frac{f(x)}{t}$$

**Transformation:**
Let $y = \frac{x}{t}$. The problem becomes:
$$\text{minimize} \quad f(y) \quad \text{subject to} \quad t = 1$$

This can help in transforming the problem into a convex form.

---

### Example: Convexifying a Simple Non-Convex Function

Consider the non-convex function:
$$f(x) = x^4 - 4x^2 + 4$$

**Transformation:**
Let $y = x^2$. The problem becomes:
$$f(y) = y^2 - 4y + 4$$

This is a convex quadratic function in $y$.

---

## Change of curvature: square

Transform:
$$0.3 \leq {\color{red} \sqrt{x} } \leq 0.4$$
into:
$$0.09 \leq {\color{green} x} \leq 0.16 \, .$$

👉 Note that $\sqrt{\cdot}$ are **monotonic** **concave** functions in $(0, +\infty)$.

Generalization:

- Consider $|H(\omega)|^2$ (power) instead of $|H(\omega)|$ (magnitude).
- Square root → Spectral factorization

---

## Change of curvature: square

Transform:
$${\color{red} x^2 } + {\color{red} y^2 } \geq 0.16 \quad \text{(non-convex)}$$
into:
$${\color{green} x'} + {\color{green} y'} \geq 0.16, \quad x', y' \geq 0$$
Then:
$$x\_\text{opt} = \pm\sqrt{x'\_\text{opt} }, \quad y\_\text{opt} = \pm\sqrt{y'\_\text{opt} }.$$

---

## Change of curvature: sine

Transform:
$${\color{red} \sin{x} } \leq 0.4, \quad 0 \leq x \leq \pi/2$$
into:
$${\color{green} y} \leq 0.4, \quad 0 \leq y \leq 1$$
Then:
$$x\_\text{opt} = \sin^{-1}(y\_\text{opt}).$$

👉 Note that $\sin(\cdot)$ are monotonic concave functions in $(0, \pi/2)$.

---

## Change of curvature: log

Transform:
$$\pi \leq {\color{red} x / y} \leq \phi, \; x > 0, y > 0$$
into:
$$\pi' \leq {\color{green} x' - y'} \leq \phi',$$
where $z' = \log(z)$.

Then:
$$z\_\text{opt} = \exp(z'\_\text{opt}).$$

Generalization:

- Geometric programming

---

## Change of curvature: inverse

Transform:
$${\color{red} \log(x)} + 0.4 \leq 0, \; x > 0$$
into:
$${\color{green} -\log(y)} + 0.4 \leq 0, \; y > 0 \, .$$

Then:
$$x\_\text{opt} = y^{-1}\_\text{opt}.$$

👉 Note that $\sqrt{\cdot}$, $\log(\cdot)$, and $(\cdot)^{-1}$ are monotonic functions.

---

## Generalize to matrix inequalities

Transform:
$${\color{red} \log(\det X)} + \text{Tr}(X^{-1} C) \leq 0.3, \; X \succ 0$$
into:
$${\color{green} -\log(\det Y)} + \text{Tr}(Y C) \leq 0.3, \; Y \succ 0$$

Then:
$$X\_\text{opt} = Y^{-1}\_\text{opt}.$$

---

## Change of variables

Transform:
$$(a +  b {\color{red} y}) x \leq 0, \; x > 0$$

into:
$$a x + b {\color{green} z} \leq 0, \; x > 0$$
where $z = y x$.

Then:
$$y\_\text{opt} = z\_\text{opt} x^{-1}\_\text{opt}$$

---

## Generalize to matrix inequalities

Transform:
$$(A + B {\color{red} Y}) X + X (A + B {\color{red} Y})^T  \prec 0, \; X \succ 0$$

into:
$$A X + X A^T + B {\color{green} Z} + {\color{green} Z}^T B^T \prec 0, \; X \succ 0,$$
where $Z = Y X$.

Then:
$$Y\_\text{opt} = Z\_\text{opt} X^{-1}\_\text{opt}$$

---

## Other thoughts

- Minimizing any quasi-convex function subject to convex constraints can easily be
  transformed into a convex programming.
- Replace a non-convex constraint with a sufficient condition
  (such as its lower bound). Less optimal.
- Relaxation + heuristic
- Decomposition

---

### Conclusion

Convexifying a non-convex function through change of variables and transformations is a powerful technique in optimization. By applying appropriate transformations, many non-convex problems can be converted into convex problems, allowing the use of efficient convex optimization algorithms to find global optima. The choice of transformation depends on the specific structure of the original problem and requires careful analysis to ensure that the transformed problem retains the essential characteristics of the original problem.

---

class: nord-dark, middle, center

# 🙋 Q & A
