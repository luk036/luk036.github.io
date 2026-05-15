layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Statistics and Machine Learning

@luk036 👨‍💻

---

## 📚 Overview

This section covers topics in statistics and machine learning, focusing on practical implementations. It includes Bayesian Optimization for sample-efficient global optimization and Reinforcement Learning for sequential decision-making.

---

.mermaid[

<pre>
graph LR
    A[Statistics & ML] --> B[Bayesian Optimization]
    A --> C[Reinforcement Learning]
    B --> D[Gaussian Process]
    B --> E[Acquisition Function]
    C --> F[Agent-Environment]
    C --> G[Policy Gradient]
    style A fill:#4caf50
    style B fill:#2196f3
    style C fill:#ff9800
    style D fill:#9c27b0
    style E fill:#9c27b0
    style F fill:#f44336
    style G fill:#f44336
</pre>

]

---

### 1. Bayesian Optimization

| Topic                                   | Description                                                   |
| --------------------------------------- | ------------------------------------------------------------- |
| [Bayesian Optimization](BO-remark.html) | Sample-efficient global optimization using Gaussian Processes |

**Libraries:**

- **GPyTorch**: GP implementation on PyTorch (GPU acceleration, auto-diff)
- **BoTorch**: Bayesian optimization built on GPyTorch
- **scikit-optimize**: Simple interface with `gp_minimize`

> 📖 See: [BO.md](BO.md) for detailed notes

---

### 2. Reinforcement Learning

| Topic                                    | Description                                             |
| ---------------------------------------- | ------------------------------------------------------- |
| [Reinforcement Learning](RL-remark.html) | Learning through trial and error with rewards/penalties |

**Applications:**

- Game playing (AlphaGo, TD-Gammon)
- Robotics control
- Autonomous vehicles

> 📖 See: [RL-diagram.md](RL-diagram.md) for detailed notes

---

## 🧮 Core Concepts

### Bayesian Optimization Workflow

```
1. Initialize: Build initial dataset (random or Sobol sequences)
2. Loop until convergence:
   a. Update Surrogate Model: Fit GP to all observed data
   b. Optimize Acquisition: Find x that maximizes acquisition function
   c. Probe Environment: Evaluate true objective at x
   d. Augment Dataset: Add new observation
```

### Reinforcement Learning Framework

```
Agent ←→ Environment
   │
   ├─► Action (a_t)
   │
   ├─► Reward (r_t)
   │
   └─► New State (s_{t+1})
```

---

.mermaid[

<pre>
flowchart LR
    subgraph BO[Bayesian Optimization]
        B1[Surrogate Model] --> B2[Acquisition Function]
        B2 --> B3[Evaluate Objective]
        B3 --> B1
    end
    subgraph RL[Reinforcement Learning]
        R1[Agent] -->|Action| R2[Environment]
        R2 -->|Reward| R1
        R2 -->|State| R1
    end
    style BO fill:#2196f3
    style RL fill:#ff9800
    style B1 fill:#4caf50
    style B2 fill:#9c27b0
    style B3 fill:#f44336
    style R1 fill:#4caf50
    style R2 fill:#f44336
</pre>

]

---

## 📖 Key References

### Bayesian Optimization

- **Textbook**: Boyd & Vandenberghe, _Convex Optimization_
- **Papers**:
  - Mockus (1978), "Bayesian approach to global optimization"
  - Frazier (2018), "A Tutorial on Bayesian Optimization"

### Reinforcement Learning

- **Textbooks**:
  - Sutton & Barto, _Reinforcement Learning_ (1998)
  - Mitchell, _Machine Learning_ (1997)
- **Key Papers**:
  - Watkins (1989), "Q-learning"
  - Silver et al. (2016), "Mastering the game of Go with deep neural networks and tree search"

---

## 🗂️ File Structure

```
statistics/
├── README.md            # This file
├── index.html           # Slide viewer (loads README.md)
├── BO.md                # Bayesian Optimization detailed notes
├── RL-diagram.md        # Reinforcement Learning notes
├── BO-remark.html       # BO slides
└── RL-remark.html       # RL slides
```

---

.mermaid[

<pre>
graph TD
    T[Textbooks] --> P[Papers]
    P --> I[Implementations]
    T --> F[Fundamentals]
    P --> A[Algorithms]
    I --> C[Code]
    style T fill:#4caf50
    style P fill:#2196f3
    style I fill:#ff9800
    style F fill:#9c27b0
    style A fill:#9c27b0
    style C fill:#f44336
</pre>

]

---

count: false
class: nord-dark, middle, center

# Q&A 🎤
