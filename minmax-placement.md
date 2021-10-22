layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Some thoughts about Global placement (confidential)

## @luk036

2021-10-22

---

## Who should be blamed for the congestion problem?

- chicken-egg arguments
- A simple fact has been ignored for 50 years? 
- And why it is possible?

---

## A1. Not enough routing resource.

- Obviously not! Some has too much, some has too little.
- Must be placer's problem.

---

## A2. Squared objective to blame

- In order to smooth-out the objective function.
- Everyone knew it, didn't it?
- No! Afterwards, original objective function had been used.
- "Convex non-smooth function"

---

## A3. HPWL to blame

- Half-perimeter wire-lenght
- Under-estimated when n > 3
- Everyone knew it, didn't it?
- No! Afterwards, compensation factor had been used.
- Congestion map, actual routing model...
- Gradually, algorithmic experts replaces the engineering experts

---

## What 孔子 said?

- "不患寡而患不均"
- "不均" means "unfair", not "uneven distribution"
- Cantonese: "均真"
- A simple fact: whenever the objective is total-wirelength, the problem will not go away.
- Why I couldn't think of it eariler? Because the "answers" have been provided for years. 
- By the way, who's care the total-wirelength now?

---

## Fairness while reducing total-wirelength

- Min-max fairness： minimize the worst wire-length
- Bonus: Min-max is usually (if not always) easier to solve than total-sum.
- Aware of Proportional Fairness
- Related paper: 
      A. Kahng, S. Mantik and I. L. Markov, Min-Max Placement For Large-Scale
      Timing Optimization, ISPD'03.

---

## Separate x- and y-direction. Why?

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
    - Disvantage:
        - Difficult to impose additional constraints.
- 2D, 3D: alternating direction

---

## Other concerns with FPGA

- Cost of bending

---

class: nord-dark, middle, center

Q & A 🗣️️
========
