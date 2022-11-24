layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Generic Circuit Partitioning

@luk036

2021-6-15

---

## Overview

- Fundamental EDA problem???
- Bi-partition vs. K-way partitioning
- Basic strategy: local search
  - Explore circuit locality
  - Incremental cost
- FM algorithm:
  - Single Move => easy stuck to local minimum.
  - Integer cost => bucket sort.
  - Last-in-first-out (LIFO)
- Multi-level extension:
  - Both cost and constraints are additive, implies
  - Coarse-grain hyper-graph a good approximation of the fine-grain ancestor

---

## ✨ Features of ckpttn{py,cpp}

- Special handling for 2-pin nets and 3-pin nets
- Primal-dual Minimum maximal matching for clustering
- Sentinel
- Up to 255 partitions

---

## Data structures

- adjacency list
  - Container of container
    - vector of vector
    - vector of hash-set

---

## Choices of restore optimal solution

1. Snapshot
2. Re-apply
3. Roll-back

---

## Trade-off

- Early stop, or not
- Ignore high-fanout nets, or not
- Legalization vs. optimization

---

class: nord-dark, center, middle

# Q & A 🙋
