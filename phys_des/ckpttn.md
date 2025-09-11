layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Multi-level Circuit Partitioning ✂️

@luk036 👨‍💻

<https://github.com/luk036/ckpttnpy>

---

## Overview 📋

- Fundamental EDA problem
- Bi-partition vs. K-way partitioning
- Basic strategy: local search
  - Explore circuit locality 🏘️
  - Incremental cost
- FM algorithm:
  - Single Move => easy stuck to local minimum.
  - Integer cost => bucket sort.
  - Last-in-first-out (LIFO)
- Multi-level extension:
  - Both cost and constraints are additive, implies
  - Coarse-grain hypergraph a good approximation of the fine-grain ancestor

---

## ✨ Features

- Try to keep it simple but not simpler
- Special handling for 2-pin nets and 3-pin nets
- Primal-dual minimum maximal matching for clustering
- Apply exhaustive search on top level 🔲

---

## Choices of restore optimal solution

1. Snapshot 📸
2. Re-apply 🔄
3. Roll-back 🔙

---

## Trade-off ⚖️

- Early stop, or not
- Ignore high-fanout nets, or not
- Legalization vs. optimization

---

## Possible contribution 🤏

- Testing
- Porting to C++
- Documentation
- Try Roll-back strategy

---

class: nord-dark, center, middle

# Q&A 🎤
