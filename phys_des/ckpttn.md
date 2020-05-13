
class: middle, center

# Generic Circuit Partitioning

Wai-Shing Luk

2019-03-07

---

## Overview

- Fundamental EDA problem
- Bi-partition vs. K-way partitioning
- Basic strategy: local search
  - Explore circuit locality
- FM algorithm:
  - Single Move => easy stuck to local minimum.
  - Integer cost => bucket sort.
- Multi-level extension:
  - Both cost and constraints are additive, implies
  - Coarse-grain hypergraph a good approximation of the fine-grain ancsentor

---

## Features of our code

- Implemented in both Python and Modern C++
- Use standard library as possible, e.g. networkx
- Educational, yet very fast.

---

## Data structures

- adjacence list
  - Container-of-container
    - vector-of-vector
    - vector-of-hashset

---

## Performance issues

- 3-pin nets, 2-pin nets
- Round Robin
- Sentinel

---

## Three choices of restore optimal solution

1. Snapshot
2. Re-apply
3. Roll-back

---

class: center, middle

# Questions

