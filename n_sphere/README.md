layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Low Discrepancy Sampling on Hyperspheres ⚽

@luk036 👨‍💻

[![codecov](https://codecov.io/gh/luk036/sphere-n/branch/main/graph/badge.svg?token=EIv4D8NlYj)](https://codecov.io/gh/luk036/sphere-n)
[![Documentation Status](https://readthedocs.org/projects/sphere-n/badge/?version=latest)](https://sphere-n.readthedocs.io/en/latest/?badge=latest)

---

## 📚 Overview

This section covers methods for generating low-discrepancy sequences (LDS) on n-dimensional spheres. It addresses the problem of uniformly sampling points on hyperspheres, which is important for numerical integration, optimization, simulation, and various engineering applications.

---

## 🎯 Topics

### 1. Low Discrepancy Sequences

| Topic                                                   | Description            |
| ------------------------------------------------------- | ---------------------- |
| [Low Discrepancy Sampling on Hyperspheres](slides.html) | Theory and methodology |
| [lds-gen Package](lds-gen-remark.html)                  | Python implementation  |

**Key Properties:**

-   **Uniformity**: More evenly distributed than random sampling
-   **Determinism**: Reproducible sequence of points
-   **Incrementality**: Can efficiently add new points to existing sequence

---

### 2. Algorithms

| Method                 | Description                       |
| ---------------------- | --------------------------------- |
| Van der Corput         | 1D LDS using digit reversal       |
| Halton Sequence        | nD extension using multiple bases |
| Hopf Coordinate        | Spherical coordinate-based        |
| Cylindrical Coordinate | Cylindrical projection method     |

---

### 3. Hypersphere Sampling

| Topic | Description                                 |
| ----- | ------------------------------------------- |
| S¹    | Unit circle                                 |
| S²    | Unit sphere (3D)                            |
| S³    | Unit 3-sphere (4D, used for SO(3) rotation) |
| Sⁿ    | n-dimensional sphere                        |

**Key Challenges:**

-   Higher dimensions require efficient algorithms
-   Need to maintain uniformity
-   Must be incrementable

---

## 🗂️ File Structure

```text
n_sphere/
├── README.md            # This file
├── slides.html          # Theory slides
├── slides.md           # Notes
├── lds-gen-remark.html  # Python package slides
├── lds-gen.md           # Package documentation
└── figs/                # Figures
```

---

## 📦 Packages

### `lds-gen` - LDS Generator

```python
from ldsgen import VdCorput, Halton

# Van der Corput (1D)
vgen = VdCorput(base=2)
vgen.reseed(0)
print(vgen.pop())  # 0.5

# Halton (nD)
hgen = Halton(bases=[2, 3])
print(hgen.pop())  # [0.5, 0.333...]
```

### `sphere-n` - N-Sphere Sampling

> GitHub: [luk036/sphere-n](https://github.com/luk036/sphere-n)
> Docs: [sphere-n.readthedocs.io](https://sphere-n.readthedocs.io/)

---

## 📖 Key References

### Papers

-   Yershova et al. (2010), "Generating Uniform Incremental Grids on SO(3) Using the Hopf Fibration"
-   Utkovski et al. (2006), "Construction of Spherical Coding for MIMO Systems"
-   Mandic et al. (2011), "Filter Bank Design for Multivariate Empirical Mode Decomposition"

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
