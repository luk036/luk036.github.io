title: Timing (Introduction)
class: animation-fade
layout: true

<!-- This slide will serve as the base layout for all your slides -->
.bottom-bar[
  {{title}}
]

---

class: impact

# {{title}}

## Wai-Shing Luk

---

## Why Useful-Skew Design?

- Imagine in a high-speed railway system, it is requested that
  the departure times of trains in any stations have to be the same,
  what do you think? 🤔

- Currently, most of our digital chips is working like this,
  it is called *zero-skew design*.

- People knew the problem decades ago. They used time-borrowing to cure.

- Useful-skew design systematically fixes the problem.

---

## The Myth of Useful-skew Design

- The myth: clock trees are more difficult to build in useful-skew design
  than in zero-skew design.

- People tried to "fix" the problem by proposing *multi-domain*
  clock skew scheduling, making the problem more complicated.

- The truth:
  - the placement algorithm still assumes zero-skew design.
  - The timing criticality changes radically after performing 
    clock skew scheduling. Placer needs to acknowledge this.
  - Clock tree synthesis can't fix the placement problem.

- The flow issue is out of our scope.

---

## Algorithmic point of view

- Given timing constraints: setup- and hold-time constraints.
- Objective: minimizing the clock period or maximizing the critical slack.
- Find the arrival time of each register that satisfies the constraints.
- Can be formulated as linear programming.

---

## Network Parametric Potential Formulation

- The clock is run periodically. Thus, we are not interested in the
  absolute arrive time, but the differences among them.
- Ends up with Network potential problem: dual of network flow.
- Utilize network locality.
- Usually faster than LP. 👍
- More importantly, it returns the most critical cycle. 👍👍👍👍

---

## Howard's algorithm

- The problem has a feasible solution if and only if all cycles are positive.
- In other words, if there exists a negative cycle, the problem is infeasible.
- Binary search to obtain the optimal clock period.
- Clock period and slack are monotonic to the feasible regions
  - The smaller the clock period, the smaller the feasible regions.
- Howard's algorithm: cycle-cancelation.
  - Policy graph for efficient negative-cycle-finding.
  - Return the most critical cycle.
  - Require monotonicity + linearity. 👎👎👎
  - Only handle one parameter. 👎👎👎

---

## Ellipsoid method

- Negative-cycle-finding as a separation oracle.
- Handle multiple parameters. ✨✨✨✨
  - Allow convex + one monotone
- Also return the most critical cycle (how???).

---

## Latch-based design

- Beside setup- and hold-time constraints, there are also propagation constraints.
- Recurrence relation.
- Railway system.
- Maximum mean cycle problem.
- Parameters: Clock period, pulse-width (not monotone)

---

## Latch vs. Flip-Flop

.col-6[

Latch:

- Level sensitive
- Timing analysis is difficult
- Lack of STA tools
- For low-power, high-speed design

]
.col-6[

Flip-Flop:

- Edge triggered
- Timing analysis is "easy"
- STA tools are available.
- Very common in any synchronous design.

]

<https://en.wikipedia.org/wiki/Flip-flop_(electronics)>

---

class: impact

Q & A
=======
