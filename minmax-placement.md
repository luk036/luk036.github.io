layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Some thoughts on global placement 💡

## @luk036

2021-10-23

---

## Who should be blamed for the congestion problem?

--

A1. The squared objective is to blame

--

But the original objective function has since been used.

--

A2. HPWL wirelength model is to blame

--

But some compensation factor (e.g. Rent's rule) has since been used.
Moreover, congestion map, more accurate wirelength models has been tried.

--

A simple fact that has been ignored for 50 years? 🤔

---

## What did 孔子 say?

- "不患寡而患不均"
- "不均" means "unfair", not "unevenness"
- Cantonese: "均真"
- **As long as the objective is to minimize the total wirelength, the problem will not go away.**
- By the way, who still cares about the total-wirelength now in industry?

---

## How to achieve fairness while reducing total wirelength

- Min-max fairness： minimize the worst wire-length (LP)
- Min-max is usually (if not always) easier to solve than total-sum.
- Note: Total squared-sum problem can be solved extremely fast by the conjugate gradient method.
- Aware of proportional fairness: weighted cost
- Related paper:
    A. Kahng, S. Mantik and I. L. Markov, Min-Max Placement For Large-Scale Timing Optimization, ISPD'03. (minimize the worst delay path)

---

## Separate x- and y-directions. Why?

![](R-C.jpeg)

---

![](download.jpeg)

---

## Separable Optimization

- 1D Placement can be formulated as a network flow (dual) problem
    - Total-sum objective: min-cost flow problem
    - Min-Max objective: parametric network flow problem
    - Advantage:
        - Faster than LP
        - Allow discrete solution
    - Disadvantage:
        - Difficult to impose additional constraints.
- 2D, 3D: alternating directions

---

## Other issues related to FPGAs

- Cost of bending

---

class: nord-dark, middle, center

Q & A 🗣️️
========
