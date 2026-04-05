layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Cyclic Quorum Systems and Combinatorics

@luk036 👨‍💻

---

## 📚 Overview

This section covers cyclic quorum systems (CQS), difference covers, and related combinatorial structures. Topics include necklace generation, bracelet algorithms, and applications in distributed computing and string algorithms.

---

## 🎯 Topics

### 1. Cyclic Quorum Systems

| Topic                                    | Description                                                 |
| ---------------------------------------- | ----------------------------------------------------------- |
| [Cyclic Quorum Systems](cqs-remark.html) | CQS fundamentals, rotation closure, quorum construction     |
| [CQS-Pair for WSN](coding-remark.html)   | Energy-efficient scheduling with heterogeneous requirements |

> **Key Applications**: Distributed mutual exclusion, wireless sensor networks, data replication

---

### 2. Difference Covers

| Topic                                          | Description                                  |
| ---------------------------------------------- | -------------------------------------------- |
| [Finding Difference Covers](fixed-remark.html) | Exhaustive search and reinforcement learning |

> **Applications**: Suffix array construction, coding theory, cryptography

---

### 3. Combinatorial Generation

| Topic                                               | Description                               |
| --------------------------------------------------- | ----------------------------------------- |
| [Necklaces and Lyndon Words](necklaces-remark.html) | Burnside's lemma, Chen-Fox-Lyndon theorem |
| [Fixed Density Bracelets](fixed-remark.html)        | CAT algorithms for bracelet generation    |

> **Key Concepts**: De Bruijn sequences, ranking/unranking algorithms

---

## 📖 Key References

### Papers

-   Karim, S., Alamgir, Z., & Husnine, S. M. (2014). "Generating fixed density bracelets of arbitrary base." International Journal of Computer Mathematics, 91(3), 434-446.
-   Sawada, J. (2001). "Generating bracelets in constant amortized time." SIAM J. Comput.
-   Ruskey, F., & Sawada, J. (1999). "An efficient algorithm for generating necklaces of fixed density." SIAM J. Comput.

### Books

-   Golin, M. J. (2005). "A First Course in Combinatorial Mathematics."
-   Bertsimas, D., & Tsitsiklis, J. (1997). "Introduction to Linear Optimization."

---

## 🗂️ File Structure

```text
cqs/
├── README.md                 # This file
├── slides.html               # Overview slides
├── cqs-slides.md            # CQS slides source
├── cqs-remark.html          # CQS rendered
├── coding.md                # Difference covers source
├── coding-remark.html       # Difference covers rendered
├── necklaces.md             # Necklaces source
├── necklaces-remark.html    # Necklaces rendered
├── fixed.md                 # Fixed density bracelets source
└── fixed-remark.html        # Fixed density rendered
```

---

## 📦 Related Packages

> 📖 GitHub: [luk036/cyclic_quorum](https://github.com/luk036/cyclic_quorum)

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
