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

.mermaid[

<pre>
graph LR
    A(("Network\n Fundamentals")) --> B(("Graph Algorithms\n (digraphx)"))
    B --> C(("Discrete Exterior\n Calculus"))
    B --> E(("Graph Algorithms\n II"))
    C --> D(("Advanced\n Topics"))
    E --> D
    style A fill:#ff9800
    style B fill:#2196f3
    style C fill:#9c27b0
    style D fill:#4caf50
    style E fill:#2196f3
</pre>

]

---

### 1. Network Optimization Fundamentals

| Topic                          | Description                          |
| ------------------------------ | ------------------------------------ |
| [Quick Start](quickstart.html) | Introduction to network optimization |

**Key Concepts:**

- **Directed Graphs**: Modeling networks, circuits, workflows
- **Shortest Path**: Finding optimal routes
- **Negative Cycle Detection**: Identifying problematic cycles
- **Minimum Cycle Ratio**: Finding most efficient cycles

.mermaid[

<pre>
graph LR
    A("Graph\n Modeling") --> B("Cycle\n Detection")
    B --> C{"Negative\n Cycle?"}
    C -->|"Yes"| D("Min Cycle\n Ratio")
    C -->|"No"| E("Shortest\n Path")
    D --> F("Optimization")
    E --> F
    style A fill:#ff9800
    style B fill:#2196f3
    style C fill:#f44336
    style D fill:#4caf50
    style E fill:#4caf50
    style F fill:#9c27b0
</pre>

]

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

.mermaid[

<pre>
graph LR
    subgraph NCF["Negative Cycle Finding"]
        A1("Cycle\n Detection")
    end
    subgraph MCR["Minimum Cycle Ratio"]
        B1("Ratio\n Optimization")
    end
    subgraph Parametric["Parametric Problems"]
        C1("Variable\n Weights")
    end
    A1 --> B1
    B1 --> C1
    style A1 fill:#2196f3
    style B1 fill:#4caf50
    style C1 fill:#9c27b0
    style NCF fill:#e3f2fd
    style MCR fill:#e8f5e9
    style Parametric fill:#f3e5f5
</pre>

]

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

### 5. Graph Algorithms II

| Topic                                            | Description                       |
| ------------------------------------------------ | --------------------------------- |
| [Christofides TSP](christofides_tsp-remark.html) | 3/2-approximation for Metric TSP  |
| [Hadlock Algorithm](hadlock-remark.html)         | Hamiltonian cycles in grid graphs |

---

### 6. Advanced Topics

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

```text
net_optim/
├── christofides_tsp-remark.html # Christofides TSP slides
├── dec-remark.html             # DEC slides
├── dec.md                      # Notes
├── digraphx-remark.html        # Package slides
├── digraphx.md                # Documentation
├── hadlock-remark.html         # Hadlock algorithm slides
├── index.html                  # Slide viewer (loads README.md)
├── intro.md                    # Introduction
├── lec07a.md                  # Lecture notes
├── mindmap.md                 # Concept map
├── netoptim-ai.md             # AI applications
├── netoptim-diagrams.md       # Diagrams
├── netoptim-slides-ai.md      # AI slides
├── notes_ai.md                # AI notes
├── quickstart.html            # Quick start guide
├── README.md                  # This file
├── slides_christofides_tsp.md # Christofides TSP source markdown
└── slides.css                 # Slide styles
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

## Q&A 🎤
