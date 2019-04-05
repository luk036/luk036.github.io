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

- Imagine in a high-speed railway system, it is request that
  the departure times of trains in any stations has to be the same,
  what do you think?

- Currently, most of our digital chips is working like this,
  it is called *zero-skew design*.

- People knew the problem decades ago. They used time-borrowing to cure.

- Useful-skew design systematically fixes the problem.

---

## The Myth of Useful-skew design

- The myth: clock trees are more difficult to build in useful-skew design
  than in zero-skew design.

- People tried to "fix" the problem by proposing *multi-domian*
  clock skew scheduling, making the problem more complicated.

- The truth:
  - the placement algorithm still assume zero-skew design.
  - The timing criticality changes radically after performaning 
    clock skew scheduling. Placer needs to acknowledge this.
  - Clock tree synthesis can't fix the placement problem.

- The flow issue is out of our scope.

---

## Algorithmatic point of view

- Given timing constraints: setup- and hold-time constraints.
- Objective: minimizing clock period or maximizing slack.
- Find the arrive time of each register that satisfies the contraints.
- Can be formulated as a linear programming.

---

## Network Parametric Potential Formulation

- Clock is run periodically. Thus, we are not interested in the
  absolute arrive time, but the different among them.
- Ends up with Network potential problem: dual of network flow.
- Utilize network locality
- Usually faster than LP
- More importantly, it returns a cycle that most critical.

---

## Howard's algorithm

- The problem has a feasible solution if and only if all cycles are positive.
- In other words, if there exists a negative cycle, the problem is infeasible.
- Binary search to obtain the optimal clock period.
- Clock period and slack are monotonic to the the feasible regions
  - The smaller the clock perioid, the smaller the feasible regions.
- Howard's algorithm: cycle-cancelation.
  - Policy graph for efficient negative-cycle-finding
  - Require monotonicity.
  - Only handle single parameter
- Generalized Howard's algorithm

---

## Ellipsoid method

- Negative-cycle-finding as an separation oracle.
- Handle multi-parameter. (allow one monotone + others convex)
- also return the most critical cycle (how???).

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
