layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Generic Circuit Partitioning

@luk036 👨‍💻

2021-6-15 📅

---

## Overview

- Fundamental EDA problem
- Bi-partition vs. K-way partitioning
- Basic strategy: local search
  - Explore circuit locality 🏘️
- FM algorithm:
  - Single Move => easy stuck to local minimum.
  - Integer cost => bucket sort.
- Multi-level extension:
  - Both cost and constraints are additive, implies
  - Coarse-grain hypergraph a good approximation of the fine-grain ancsentor

---

## Data structures

- adjacence list
  - Container-of-container
    - vector-of-vector
    - vector-of-hashset

---

## Three choices of restore optimal solution

1. Snapshot
2. Re-apply
3. Roll-back

---

class: center, middle

# Questions
