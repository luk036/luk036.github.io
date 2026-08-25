layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Combinatorial Optimization

@luk036 👨‍💻 · 2026 📅

---

### 📋 Agenda

.pull-left[

**Complexity** 🧠
- Complexity Theory
- Approximation Classes

**TSP** 🚗
- Christofides Algorithm

]

.pull-right[

**Vertex Cover** 🎯
- Exact & GPU Algorithms
- Primal-Dual Covering

**Advanced** 🔬
- Planar MAX-CUT
- Type Systems

]

---

## 📚 Overview

This section covers combinatorial optimization problems and their approximation algorithms — from NP-completeness and approximation classes to the Traveling Salesman Problem, vertex cover, and planar MAX-CUT. The content spans theory and cross-language implementations (Python, C++, Rust).

---

### 1. Complexity Theory & Approximations

| Topic                                          | Description                                     |
| ---------------------------------------------- | ----------------------------------------------- |
| [Complexity Theory](complexity-remark.html)    | Lecture 2d: NP-completeness and paradigms       |
| [Combinatorial Optimization](combinatorial-optimization-remark.html) | Approximation algorithms overview |

> 📖 See: [complexity.md](complexity.md)

---

### 2. Traveling Salesman Problem

| Topic                                          | Description                                     |
| ---------------------------------------------- | ----------------------------------------------- |
| [Christofides Algorithm](christofides_tsp-remark.html) | 3/2-approximation for metric TSP          |

> 📖 See: [slides_christofides_tsp.md](slides_christofides_tsp.md)

---

### 3. Vertex Cover & Covering Problems

| Topic                                          | Description                                     |
| ---------------------------------------------- | ----------------------------------------------- |
| [Vertex Cover Algorithms](vertex-cover-remark.html) | From exact to GPU-accelerated             |
| [Covering via Primal-Dual](pd_cover-remark.html) | Primal-dual framework with reverse-delete |
| [GPU Vertex Cover (C++)](netlistx-cpp-gpu-remark.html) | CUDA port of randomized vertex cover |
| [GPU Vertex Cover (Rust)](netlistx-rust-gpu-remark.html) | Rust port of randomized vertex cover |
| [Porting netlistx to Rust](netlistx-rust-remark.html) | EDA algorithms in systems programming |

---

### 4. Planar MAX-CUT

| Topic                                          | Description                                     |
| ---------------------------------------------- | ----------------------------------------------- |
| [Hadlock's Algorithm](hadlock-remark.html)     | Hamiltonian cycles in grid graphs               |

---

### 5. Cross-Language Topics

| Topic                                          | Description                                     |
| ---------------------------------------------- | ----------------------------------------------- |
| [Python ⇄ C++ Types](../proglang/py-cpp-remark.html)       | A tale of two type systems                      |

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
