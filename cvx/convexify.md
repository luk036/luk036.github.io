layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Convexify the Non-convex's

@luk036

2024-08-07

---

## 📝 Abstract

Convexifying a non-convex function through change of variables and transformations is a powerful technique in optimization. This process involves transforming the original problem into a new problem where the objective function and constraints become convex. Here are some common strategies for achieving this.

---

## Example: Convexifying a Simple Non-Convex Function

Consider the non-convex function:
$$f(x) = x^4 - 4x^2 + 4$$

**Transformation:**
Let $y = x^2$. The problem becomes:
$$f(y) = y^2 - 4y + 4$$

**Post-proccessing:**
$$x\_\text{opt} = \pm\sqrt{y\_\text{opt} }$$

---

## Change of curvature: square

**Original Problem:**
$${\color{red} x^2 } + {\color{red} y^2 } \geq 0.16 \quad \text{(non-convex)}$$

**Transformation:**
Let $x' = x^2$, $y' = y^2$. The problem becomes:
$${\color{green} x'} + {\color{green} y'} \geq 0.16, \quad x', y' \geq 0$$

**Post-proccessing:**
$$x\_\text{opt} = \pm\sqrt{x'\_\text{opt} }, \quad y\_\text{opt} = \pm\sqrt{y'\_\text{opt} }.$$

---

## Change of curvature: sine

**Original Problem:**
$${\color{red} \sin{x} } \leq 0.4, \quad 0 \leq x \leq \pi/2$$

**Transformation:**
$${\color{green} y} \leq 0.4, \quad 0 \leq y \leq 1$$

**Post-proccessing:**
$$x\_\text{opt} = \sin^{-1}(y\_\text{opt}).$$

👉 Note that $\sin(\cdot)$ are monotonic concave functions in $(0, \pi/2)$.

---

## Change of curvature: square

**Original Problem:**
$$0.3 \leq {\color{red} \sqrt{x} } \leq 0.4$$

**Transformation:**
$$0.09 \leq {\color{green} x} \leq 0.16 \, .$$

👉 Note that $\sqrt{\cdot}$ are **monotonic** **concave** functions in $(0, +\infty)$.

**Generalization:**

- Consider $|H(\omega)|^2$ (power) instead of $|H(\omega)|$ (magnitude).
- Square root → Spectral factorization

---

## Logarithmic Transformation

**Original Problem:**

$$\pi \leq {\color{red} x / y} \leq \phi, \; x > 0, y > 0$$

**Transformation:**
Let $z' = \log(z)$. The problem becomes:

$$\pi' \leq {\color{green} x' - y'} \leq \phi'$$

**Post-proccessing:**

$$z\_\text{opt} = \exp(z'\_\text{opt}).$$

**Generalization:**

- Geometric programming

---

## Reciprocal Transformation

**Original Problem:**
$${\color{red} \log(x)} + 0.4 \leq 0, \; x > 0$$

**Transformation:**
Let $y = 1 / x$. The problem becomes:
$${\color{green} -\log(y)} + 0.4 \leq 0, \; y > 0 \, .$$

**Post-proccessing:**
$$x\_\text{opt} = y^{-1}\_\text{opt}.$$

👉 Note that $\sqrt{\cdot}$, $\log(\cdot)$, and $(\cdot)^{-1}$ are monotonic functions.

---

## Generalize to Matrix Inequalities

**Original Problem:**

$${\color{red} \log(\det X)} + \text{Tr}(X^{-1} C) \leq 0.3, \; X \succ 0$$

**Transformation:**
Let $Y = X^{-1}$. The problem becomes:
$${\color{green} -\log(\det Y)} + \text{Tr}(Y \cdot C) \leq 0.3, \; Y \succ 0$$

**Post-proccessing:**
$$X\_\text{opt} = Y^{-1}\_\text{opt}.$$

---

## Exponential Transformation

### Example: Exponential Utility Functions

For problems involving exponential utility functions, an exponential transformation can be useful.

**Original Problem:**
$$\text{minimize} \quad -\exp(f(x))$$

**Transformation:**
Let $y = \exp(f(x))$. The problem becomes:
$$\text{minimize} \quad -y \quad \text{subject to} \quad y = \exp(f(x))$$

This can help in transforming the problem into a convex form.

---

## Change of Variables

### Example: Power Transformation

For certain power functions, a change of variables can help.

**Original Problem:**
$$\text{minimize} \quad f(x) = x^p \quad \text{for} \quad p < 1$$

**Transformation:**
Let $y = x^p$. The problem becomes:
$$\text{minimize} \quad y \quad \text{subject to} \quad y = x^p$$

This can help in transforming the problem into a convex form.

---

## Perspective Transformation 🤔

### Example: Perspective Function

For certain functions, applying a perspective transformation can help.

**Original Problem:**
$$\text{minimize} \quad \frac{f(x)}{t}$$

**Transformation:**
Let $y = \frac{x}{t}$. The problem becomes:
$$\text{minimize} \quad f(y) \quad \text{subject to} \quad t = 1$$

This can help in transforming the problem into a convex form.

---

## Change of variables

**Original Problem:**
$$(a +  b \cdot {\color{red} y}) x \leq 0, \; x > 0$$

**Transformation:**
Let $z = y \cdot x$. The problem becomes:
$$a \cdot x + b \cdot {\color{green} z} \leq 0, \; x > 0$$

**Post-proccessing:**
$$y\_\text{opt} = z\_\text{opt} x^{-1}\_\text{opt}$$

---

## Generalize to matrix inequalities

**Original Problem:**
$$(A + B \cdot {\color{red} Y}) X + X (A + B \cdot {\color{red} Y})^T  \prec 0, \; X \succ 0$$

**Transformation:**
Let $Z = Y \cdot X$. The problem becomes:
$$A \cdot X + X \cdot A^T + B \cdot {\color{green} Z} + {\color{green} Z}^T \cdot B^T \prec 0, \; X \succ 0$$

**Post-proccessing:**
$$Y\_\text{opt} = Z\_\text{opt} X^{-1}\_\text{opt}$$

---

## Other thoughts

- Minimizing any quasi-convex function subject to convex constraints can easily be
  transformed into a convex programming.
- Alternating minimization
- Replace a non-convex constraint with a sufficient condition
  (such as its lower bound). Less optimal.
- Relaxation + heuristic
- Decomposition

---

## Conclusion

Convexifying a non-convex function through change of variables and transformations is a powerful technique in optimization. By applying appropriate transformations, many non-convex problems can be converted into convex problems, allowing the use of efficient convex optimization algorithms to find global optima. The choice of transformation depends on the specific structure of the original problem and requires careful analysis to ensure that the transformed problem retains the essential characteristics of the original problem.

---

class: nord-dark, middle, center

# 🙋 Q & A
