layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Network Optimization

@luk036 👨‍💻

---

## 📚 Overview

This section covers network optimization algorithms and their implementations. Topics include graph algorithms, minimum cycle ratio problems, negative cycle detection, and discrete exterior calculus. The content provides both theoretical foundations and practical Python implementations through the `digraphx` package.

---

## 🎯 Topics

### 1. Network Optimization Fundamentals

| Topic                          | Description                          |
| ------------------------------ | ------------------------------------ |
| [Quick Start](quickstart.html) | Introduction to network optimization |

**Key Concepts:**

- **Directed Graphs**: Modeling networks, circuits, workflows
- **Shortest Path**: Finding optimal routes
- **Negative Cycle Detection**: Identifying problematic cycles
- **Minimum Cycle Ratio**: Finding most efficient cycles

---

### 2. Graph Algorithms: `digraphx` Package

| Topic                                    | Description                                |
| ---------------------------------------- | ------------------------------------------ |
| [digraphx Package](digraphx-remark.html) | Python package for directed graph analysis |

**Package Features:**

- **Negative Cycle Finding (NCF)**: Detect cycles with negative total weight
- **Minimum Cycle Ratio (MCR)**: Find cycle with smallest weight/time ratio
- **Parametric Network Problems**: Variable edge weights
- **Lightweight Graph Structure**: `tiny_digraph`

> 📖 GitHub: [luk036/digraphx](https://github.com/luk036/digraphx)

---

### 3. Discrete Exterior Calculus (DEC)

| Topic                                         | Description                      |
| --------------------------------------------- | -------------------------------- |
| [Discrete Exterior Calculus](dec-remark.html) | Geometry-preserving computations |

**Key Concepts:**

- **Differential Forms**: k-forms (0: scalar, 1: line, 2: surface, 3: volume)
- **Simplicial Meshes**: Triangulated geometry
- **Exterior Derivative (d)**: Discrete differentiation
- **Hodge Star**: Duality between forms
- **Structure Preservation**: Geometric and physical properties

> 📖 See: [dec.md](dec.md)

---

### 4. Advanced Topics

| Topic                                     | Description                             |
| ----------------------------------------- | --------------------------------------- |
| [Network Optimization AI](netoptim-ai.md) | AI applications in network optimization |
| [Intro to Network Optimization](intro.md) | Fundamental concepts                    |

**Topics:**

- Parametric shortest path
- Cycle ratio optimization
- Clock skew scheduling

---

## 📦 Package: digraphx

### Negative Cycle Finding

```python
from digraphx import NegCycleFinder

# Create graph with edge weights
graph = {
    'A': [('B', -1), ('C', 4)],
    'B': [('C', 2), ('D', 2)],
    'C': [('D', -3)],
    'D': [('A', 1)]
}

finder = NegCycleFinder(graph)
cycles = finder.find_negative_cycles()
```

---

### Minimum Cycle Ratio

```python
from digraphx import MinCycleRatioSolver

# Edge attributes: cost and time
graph = {
    0: [(1, {'cost': 1, 'time': 2}), (2, {'cost': 2, 'time': 1})],
    1: [(0, {'cost': 1, 'time': 1}), (2, {'cost': 1, 'time': 2})],
    2: [(0, {'cost': 3, 'time': 1}), (1, {'cost': 2, 'time': 1})]
}

solver = MinCycleRatioSolver(graph)
ratio, cycle = solver.solve()
```

---

## 🗂️ File Structure

```
net_optim/
├── README.md                 # This file
├── quickstart.html          # Quick start guide
├── digraphx-remark.html     # Package slides
├── digraphx.md             # Documentation
├── dec-remark.html         # DEC slides
├── dec.md                  # Notes
├── intro.md                # Introduction
├── lec07a.md              # Lecture notes
├── netoptim-ai.md         # AI applications
├── netoptim-slides-ai.md  # AI slides
├── notes_ai.md            # AI notes
├── netoptim-diagrams.md   # Diagrams
└── mindmap.md             # Concept map
```

---

## 📖 Key References

### Algorithms

| Reference           | Description                          |
| ------------------- | ------------------------------------ |
| Karp (1967)         | Minimum mean cycle algorithm         |
| Howard (1960)       | Policy iteration for negative cycles |
| Bellman-Ford (1958) | Shortest path with negatives         |

---

count: false
class: nord-dark, middle, center

# Q&A 🎤
