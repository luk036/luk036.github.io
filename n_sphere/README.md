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

.mermaid[

<pre>
graph LR
    A["Low Discrepancy\nSequences"] --> B["Algorithms"]
    B --> C["Hypersphere\nSampling"]
    C --> D["Applications"]

    style A fill:#4caf50
    style B fill:#ff9800
    style C fill:#2196f3
    style D fill:#9c27b0
</pre>

]

---

### 1. Low Discrepancy Sequences

| Topic                                                   | Description            |
| ------------------------------------------------------- | ---------------------- |
| [Low Discrepancy Sampling on Hyperspheres](slides.html) | Theory and methodology |
| [lds-gen Package](lds-gen-remark.html)                  | Python implementation  |

**Key Properties:**

- **Uniformity**: More evenly distributed than random sampling
- **Determinism**: Reproducible sequence of points
- **Incrementality**: Can efficiently add new points to existing sequence

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

.pull-left[

| Topic | Description           |
| ----- | --------------------- |
| S¹    | Unit circle           |
| S²    | Unit sphere (3D)      |
| S³    | Unit 3-sphere (4D)    |
| Sⁿ    | n-dimensional sphere  |
]
.pull-right[
.mermaid[
<pre>
graph TD
    S1["S¹\nUnit Circle"] --> S2["S²\nUnit Sphere"]
    S2 --> S3["S³\nUnit 3-Sphere"]
    S3 --> Sn["Sⁿ\nn-Sphere"]
    S1 --> M1["Van der Corput"]
    S2 --> M2["Halton\nSequence"]
    S3 --> M3["Hopf\nCoordinate"]

    style S1 fill:#4caf50
    style S2 fill:#ff9800
    style S3 fill:#2196f3
    style Sn fill:#9c27b0
    style M1 fill:#4caf50
    style M2 fill:#ff9800
    style M3 fill:#2196f3
</pre>
]
]

**Key Challenges:**

- Higher dimensions require efficient algorithms
- Need to maintain uniformity
- Must be incrementable

---

## 🗂️ File Structure

```text
n_sphere/
├── figs/                # Figures
├── index.html           # Slide viewer (loads README.md)
├── lds-gen-remark.html  # Python package slides
├── lds-gen.md           # Package documentation
├── README.md            # This file
├── slides.html          # Theory slides
└── slides.md            # Notes
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

---

### `sphere-n` - N-Sphere Sampling

> GitHub: [luk036/sphere-n](https://github.com/luk036/sphere-n)
> Docs: [sphere-n.readthedocs.io](https://sphere-n.readthedocs.io/)

.mermaid[

<pre>
graph LR
    VC["VdCorput\n(base 2)"] --> H["Halton\nSequence"]
    H --> C["Cylindrical\nCoordinate"]
    H --> HF["Hopf\nCoordinate"]
    C --> S1["S¹"]
    C --> S2["S²"]
    HF --> S3["S³\n(SO(3))"]
    HF --> Sn["Sⁿ"]

    style VC fill:#4caf50
    style H fill:#ff9800
    style C fill:#2196f3
    style HF fill:#9c27b0
    style S1 fill:#4caf50
    style S2 fill:#ff9800
    style S3 fill:#2196f3
    style Sn fill:#9c27b0
</pre>

]

---

## 📖 Key References

### Papers

- Yershova et al. (2010), "Generating Uniform Incremental Grids on SO(3) Using the Hopf Fibration"
- Utkovski et al. (2006), "Construction of Spherical Coding for MIMO Systems"
- Mandic et al. (2011), "Filter Bank Design for Multivariate Empirical Mode Decomposition"

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
