title: Timing
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

class: middle, left

# Timing is first priority......

---

class: middle, left

# Timing is first priority (没有之一)

---

## Industry's Day-to-day Issue

--

I need to ship the product before Christmas...

--

...but I still have 100 timing issues to fix 😖.

--

That is why modern P&R tools are all timing-driven.

---

Q. Don't concern anymore area, delay, and power? 🤔

--

A. Probably still concern but...

--

...after timing issues are OK...

--

...please.🙏🙏🙏🙏

---

## How to perform timing-driven P&R?

Well...

- step 1: Look for the most timing-critical path.
- step 2: Physically place cells on the path as close to each other as possible.
- step 3: Repeat steps 1-2 for the next timing-critical path.

--

Know what...

- After that, you will get a clearer picture of the timing, or congestion, or whatever (probably you don't need Machine Learning to predict them).
- Now, repeat the whole process again...

---

class: left

Q. Boring?

--

A. Yes...

--

Q. It works?

--

A. It works very well. I know it.

--

Q. How about those algorithms I learned? Analytic, force-directed, conjugate gradient...etc.?

--

A. Forget them from now on 😔

--

maybe.

---

## People are now focusing on...

- Useful skew design (vs. zero-skew design)
- Latch-based design (vs. flip-flop based design)

---

## Timing-critical

- One million dollar question: What "timing-critical" really means?
  (you can't invest a timing-driven placement without knowing what "timing-critical" is, right?)

--

- Well, 
  - In zero-skew design, it means a path.
  - In useful-skew design, it means a feedback cycle.
  - In latch-based design, it is difficult to explain at this moment. But I will be back on this issue later.

---

## What is "Timing violation"?

- Understanding from application engineers' perspective (zero-skew design):
  - There are setup- and hold-time violations.
  - You run an STA tool. If all reported slacks are positive, you are done.
    If some of them are negative, you are dead. Simple.
- Useful-skew design:
  - If all reported slack sum on **any cycle** are positive,
    timing violation can be fixed using clock skew scheduling.
    If some of them are negative, you are dead.
- Latch-based design:
  - Beside setup- and hold-time constraints, there are also propagation constraints.

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
