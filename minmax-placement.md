layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Some thoughts on global placement (confidential)

## @luk036

2021-10-23

---

## Who should be blamed for the congestion problem?

- The chicken-and-egg dilemma
- A simple fact that has been ignored for 50 years? 
- And why is it possible?

---

## A1. There are not enough wiring resource.

- Apparently not! Some too much, some too little.
- It must be the placer's problem.

---

## A2. The squared objective is to blame

- To smoothing the objective function.
- We all know that, don't we?
- No! The original objective function has since been used.

---

## A3. HPWL is to blame

- Half-perimeter wirelenght is underestimated when n > 3
- We all know that, don't we?
- No! some compensation factor has since been used.
- Moreover, congestion map, actual wirelength model has been tried.
- Gradually, algorithm experts replaced the electronic engineering experts

---

## What did 孔子 say?

- "不患寡而患不均"
- "不均" means "unfair", not "unevenness"
- Cantonese: "均真"
- A simple fact: as long as the objective is the total wirelength, the problem will not go away.
- Why didn't I think of this sooner?
- Well, because those "answers" have been provided for years.
- By the way, who still cares about the total-wirelength now in industry?

---

## Achieving fairness while reducing total wirelength

- Min-max fairness： minimize the worst wire-length
- Bonus: Min-max is usually (if not always) easier to solve than total-sum.
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
    - Total sum objective: min-cost flow problem
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
