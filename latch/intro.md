layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Timing (Introduction)

## @luk036

---

## Why Useful-Skew Design?

- Imagine a high-speed railway system in which people are asked to the departure time of trains in any stations must be the same from station to station. What do you think? 🤔

- This is how most of our digital chips works today. It's called *zero-skew design*.

- People have known about this problem for decades. They used *time-borrowing* to cure it.

- Useful-skew design systematically solves this problem.

---

## The Myth of the Useful-Skew Design

- Myth: clock trees are harder to build in a useful-skew design than in zero-skew design.

- People tried to "solve" the problem by proposing *multi-domain* clock skew scheduling, making the problem more complicated.

- The truth:
  - The placement algorithm is still predicated on a zero-skew design.
  - The timing criticality changes radically after performing clock skew scheduling. Placer needs to acknowledge this.
  - Clock tree synthesis cannot solve the placement problem.

- Flow issues are out of our scope.

---

## Algorithmic point of view

- Given timing constraints: setup- and hold-time constraints.
- Goal: minimize the clock period or maximize the critical slack.
- Find the arrival time of each register that satisfies the constraints.
- Can be formulated as a linear programming.

---

## Network Parametric Potential Formulation

- The clock is run periodically. Thus, we are not interested in the absolute arrive time, but the differences among them.
- Ends up with Network potential problem: dual of network flow.
- Utilize network locality.
- Usually faster than LP. 👍
- More importantly, it returns the most critical cycle. 👍👍👍👍

---

## Howard's algorithm

- The problem has a feasible solution if and only if all cycles are positive.
- In other words, if there is a negative cycle, the problem is infeasible.
- A binary search is perform to obtain the optimal clock period.
- The clock period and slack are monotonic to the feasible region
- The smaller the clock period, the smaller the feasible regions.
- Howard's algorithm: cycle-cancellation.
  - *Policy graph* for efficient negative cycle finding.
  - Return the most critical cycle.
  - Require monotonicity + linearity. 👎👎👎
  - Handle only one parameter. 👎👎👎

---

## Ellipsoid method

- Negative cycle finding as a separation oracle.
- Handles multiple parameters. ✨✨✨✨
  - Allow convex + one monotone
- Also return the most critical cycle (how???).

---

## Latch-based design

- In additional to setup- and hold-time constraints, there are propagation constraints.
- Recurrence relationships.
- Railway system.
- Maximum mean cycle problem.
- Parameters: Clock period, pulse-width (not monotonic)

---

## Latch vs. Flip-Flop

.pull-left[

Latch:

- Level sensitive
- Timing analysis is difficult
- Lack of STA tools
- For low-power, high-speed designs

]
.pull-right[

Flip-Flop:

- Edge triggered
- Timing analysis is "simple"
- STA tools are available.
- Very common in any synchronous design.

]

<https://en.wikipedia.org/wiki/Flip-flop_(electronics)>

---

class: nord-dark, middle, center

Q & A 🗣️️
========
