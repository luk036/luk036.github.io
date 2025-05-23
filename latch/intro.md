layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# ⏳ Timing (Introduction)

@luk036 👨‍💻

---

## Why is Useful-Skew design necessary?

- Imagine a high-speed rail system in which people are required to have the same train departure time at any stations. What do you think? 🤔

- This is the way most of our digital chips work today. It's called _zero-skew design_.

- People have known about this problem for decades. They used _time-borrowing_ to solve this problem.

- Useful-skew design is a systematic way to perform timing-borrowing.

---

## The Myth of Useful-Skew design

- Myth: clock trees are more difficult to build in useful skew design than in zero-skew design.

- People have tried to "solve" this problem by proposing _multi-domain_ clock skew scheduling ⏳ to further complicate the problem.

- The truth is:

  - The placement algorithm is still predicated on a zero-skew design.
  - The timing criticality changes radically after performing clock skew scheduling. Placer needs to recognize this.
  - Clock tree synthesis cannot solve the placement problem.

- The flow issue is out of our scope.

---

## Algorithm's view

- Given timing constraints: setup- and hold-time constraints.
- Goal: minimize clock period or maximize critical slack.
- Find the arrival time of each register that satisfies the constraints.
- Can be formulated as a linear programming.

---

## Network Parametric Potential Formulation

- The clock is run periodically. Thus, we are not interested in the absolute arrive time, but in the differences between them.
- Ends up with the network potential problem: dual of network flow.
- Exploits network locality.
- Usually faster than LP. 👍
- More importantly, it returns the most critical cycle. 👍👍👍👍

---

## Howard's algorithm

- The problem has a feasible solution precisely when all the cycles are positive.
- In other words, if there is a negative cycle, the problem is infeasible.
- A binary search is performed to obtain the optimal clock period.
- The clock period and slack are monotonic with respect to the feasible region
- The smaller the clock period, the smaller the feasible regions.
- Howard's algorithm: cycle-cancellation.
  - _Policy graph_ for efficient negative cycle finding.
  - Returns the most critical cycle.
  - Requires monotonicity + linearity. 👎👎👎
  - Handles only one parameter. 👎👎👎

---

## 👁️ Ellipsoid method

- Negative cycle finding as a separation oracle.
- Handles multiple parameters. ✨✨✨✨
  - Allows convex + one monotone best-so-far value
- Also return the most critical cycle (how ? ? ? ?).

---

## Latch-based design

- In additional to the setup- and hold-time constraints, there are propagation constraints.
- Recurrence relationships.
- Railroad system.
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
- Timing analysis is "easy"
- STA tools are available.
- Very common in any synchronous design.

]

<https://en.wikipedia.org/wiki/Flip-flop_(electronics)>

---

class: nord-dark, middle, center

# Q & A️ 🙋
