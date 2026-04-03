layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Latch-Based Timing Design

@luk036 👨‍💻

---

## 📚 Overview

This section covers latch-based timing design and its relationship to max-plus algebra. Topics include timing-driven place-and-route, useful skew design, and the mathematics behind synchronous digital systems.

---

## 🎯 Topics

### 1. Timing Fundamentals

| Topic                              | Description                                            |
| ---------------------------------- | ------------------------------------------------------ |
| [Timing Introduction](timing.html) | Why timing is critical, timing-driven P&R              |
| [Latch vs. Flip-Flop](intro.html)  | Level-sensitive vs. edge-triggered, timing constraints |

> **Key Concepts**: Setup time, hold time, clock skew, propagation delay

---

### 2. Useful Skew Design

| Topic                          | Description                              |
| ------------------------------ | ---------------------------------------- |
| [Timing Analysis](latch.html)  | Network parametric potential formulation |
| [Quick Start](quickstart.html) | Max-plus algebra, eigenvalue problem     |

> **Algorithms**: Howard's method, Ellipsoid method

---

### 3. Max-Plus Algebra

| Topic                               | Description                           |
| ----------------------------------- | ------------------------------------- |
| [Max-Plus Algebra](quickstart.html) | Tropical semiring, eigen-problem      |
| [Timing Graph](timing_graph.dot)    | Timing constraint graph visualization |

> **Applications**: Railroad scheduling, synchronous circuit analysis

---

## 📖 Key References

### Books

- Gaubert, S. & McErlain, S. (2015). _Max Plus at Work: Modeling and Analysis of Synchronized Systems_. Princeton University Press.
- Baccelli, F., Cohen, G., Olsder, G. J., & Quadrat, J.-P. (1992). _Synchronization and Linearity_. Wiley.

### Papers

- S. H. Huang, "Power Optimization of Sequential Circuits Based on Clock-Phase Scheduling and Operand Transformation," 1999.

---

## 🗂️ File Structure

```
latch/
├── README.md                 # This file
├── intro.html                # Latch vs. Flip-Flop
├── timing.html               # Timing fundamentals
├── timing.md                 # Timing notes
├── latch.html                # Useful skew design
├── quickstart.html           # Max-plus algebra
├── quickstart.md            # Quick start guide
├── timing_graph.dot         # Timing graph visualization
├── timing_graph.svg         # SVG version
├── timing_graph.pdf         # PDF version
└── refs/                    # Reference papers
    ├── tau99slides.pdf
    ├── semirings.pdf
    └── max-plus/            # Max Plus at Work chapters
```

---

count: false
class: nord-dark, middle, center

# Q&A 🎤
