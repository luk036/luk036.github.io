layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Convexify the non-convex's

@luk036

2021-02-02

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

class: nord-dark, middle, center

# 🙋 Q & A
