layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Timing

👨🏻‍🏫 @luk036

📅 2021-11-17

---

class: middle, left

# ⏳ Timing is the first priority......

---

class: middle, left

# ⏳ Timing is the first priority (没有之一)

---

## Industry's Daily Issue

--

I need to ship the product before Christmas...

--

...but I still have 100 more timing issues to fix 😖.

--

That's why modern P&R tools are all timing-driven.

---

Q. Stop focusing on area, delay, and power? 🤔

--

A. Probably still concerned, but...

--

...after the timing issue is not a problem...

--

...🙏🙏🙏🙏

---

## How to perform timing-driven P&R?

Well...

- Step 1: Look for the most timing-critical path.
- Step 2: Place cells on the path as close to each other as possible.
- Step 3: Repeat Steps 1-2 for the next timing-critical path.

--

Know what...

- After that, you'll have a clearer picture of the timing, or congestion, or whatever (probably you don't need machine learning 🤖 to predict them).
- Now, repeat the whole process again...

---

class: left

Q. Boring?

--

A. Yes...

--

Q. Does it work?

--

A. It works very well. I know it.

--

Q. How about those algorithms I learned? Analytic, force-directed, conjugate gradient...etc.?

--

A. Forget about them from now on 😔

--

maybe.

---

## People are now focusing on...

- Useful skew design (vs. zero-skew design)
- Latch-based design (vs. flip-flop based design)

---

## Timing-critical

- One million dollar question: What does "timing-critical" really mean?
  (you can't invest in a timing-driven placement without knowing what "timing-critical" is, right?)

--

- Well,
  - In a zero-skew design, it means a path.
  - In a useful-skew design, it means a feedback cycle.
  - In a latch-based design, it is difficult to explain at this moment. But I will be back to that later.

---

## What is "Timing violation"?

- Understanding from the application engineers' perspective (zero-skew design):
  - There are setup- and hold-time violations.
  - You run an STA tool. If all the reported slacks are positive, you are done.
  - If some of them are negative, you are dead. Simple.
- Useful-skew design:
  - If all reported slack sums in **any cycle** are positive, timing violation can be fixed using clock skew scheduling.
  - If some of them are negative, you are dead.
- Latch-based design:
  - In addition to the setup- and hold-time constraints, there are propagation constraints.

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

class: nord-dark, middle, center

# 🙋 Q & A️
