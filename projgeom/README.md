layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Geometry, Algebra, and Computation

@luk036 👨‍💻

[![Documentation Status](https://readthedocs.org/projects/projgeom-py/badge/?version=latest)](https://projgeom-py.readthedocs.io/en/latest/?badge=latest)
[![codecov](https://codecov.io/gh/luk036/projgeom-py/branch/main/graph/badge.svg?token=6lpjUzPavX)](https://codecov.io/gh/luk036/projgeom-py)

---

## 📚 Overview

This section covers geometry from multiple perspectives: classical Euclidean geometry, projective geometry, Cayley-Klein geometries, and rational trigonometry. It provides both theoretical foundations and practical implementations through the `projgeom` Python package.

---

### Geometry Topics Overview

.mermaid[

<pre>
graph LR
    PG[Projective Geometry] --> CKG[Cayley-Klein Geometry]
    CKG --> RT[Rational Trigonometry]
    RT --> QS[Quadrance &amp; Spread]

    style PG fill:#4caf50
    style CKG fill:#2196f3
    style RT fill:#ff9800
    style QS fill:#9c27b0
</pre>

]

---

### 1. Projective Geometry

| Topic                                          | Description                                         |
| ---------------------------------------------- | --------------------------------------------------- |
| [Projective Geometry](01proj_geom-remark.html) | Foundations of projective plane, incidence, duality |
| [Projective Line](05proj_line-remark.html)     | 1D projective geometry                              |

**Key Concepts:**

- **Points and Lines**: Basic elements of the projective plane
- **Incidence**: Whether a point lies on a line
- **Duality**: Points and lines are interchangeable
- **Cross Ratio**: Invariant under projective transformations

> 📖 See: [01proj_geom.md](01proj_geom.md)

---

### 2. Cayley-Klein Geometry

| Topic                                          | Description                                                |
| ---------------------------------------------- | ---------------------------------------------------------- |
| [Cayley-Klein Geometry](02ck_geom-remark.html) | Unified view of Euclidean, Elliptic, Hyperbolic geometries |

**Key Concepts:**

- **Absolute Conic**: Defines the metric type
- **Klein's Model**: Hyperbolic geometry in the unit disk
- **Poincaré Model**: Alternative hyperbolic representation
- **Transformations**: Preserving the absolute

---

### 3. Rational Trigonometry

| Topic                                         | Description                                   |
| --------------------------------------------- | --------------------------------------------- |
| [Rational Trigonometry](rat_trig-remark.html) | Trigonometry without transcendental functions |

**Key Concepts (Wildberger's approach):**

- **Quadrance**: Squared distance (replaces length)
- **Spread**: Squared ratio (replaces angle)
- **Rational arithmetic**: No sin/cos needed

**Advantage**: All calculations use rational numbers, avoiding floating-point errors.

> 📖 See: [rat_trig.md](rat_trig.md), [03RT.md](03RT.md)

---

### 4. The `projgeom` Package

| Topic                                    | Description           |
| ---------------------------------------- | --------------------- |
| [projgeom Package](projgeom-remark.html) | Python implementation |

**Purpose**: Compute with projective geometry and related geometries.

> 📖 Docs: [projgeom-py.readthedocs.io](https://projgeom-py.readthedocs.io/)
> 📖 GitHub: [luk036/projgeom-py](https://github.com/luk036/projgeom-py)

---

## 🧮 Core Concepts

### Why Projective Geometry?

1. **Unified Framework**: All conics are equivalent under projection
2. **No Special Cases**: Parallel lines meet at infinity
3. **Computationally Stable**: Integer arithmetic possible with rational coordinates

> **Tip**: Don't use machine guns to hunt rabbits. Choose the right measurement for the task.

---

### 📦 Package: projgeom

```python
from projgeom import ProjectivePlane, Point, Line

# Create points and lines
p = Point(1, 2, 1)  # homogeneous coordinates
l = Line(1, -1, 0)  # ax + by + c = 0

# Check incidence
p.incident(l)  # True/False

# Find meet (intersection)
l1 = Line(1, 0, 0)
l2 = Line(0, 1, 0)
p = l1.meet(l2)  # Point at infinity for parallel lines
```

---

### 🗂️ File Structure

```text
projgeom/
├── README.md                 # This file
├── 01proj_geom-remark.html  # Projective Geometry slides
├── 01proj_geom.md           # Notes
├── 02ck_geom-remark.html   # Cayley-Klein slides
├── 03RT.md                 # Rational Trig notes
├── rat_trig-remark.html    # Rational Trig slides
├── 05proj_line-remark.html # Projective Line
├── 05proj_line.md          # Notes
├── projgeom-remark.html    # Package slides
├── projgeom.md             # Package documentation
└── figs/                   # Figures
```

---

## 📖 Key References

### Textbooks

- Norman Wildberger, _Divine Proportions: Rational Trigonometry to Universal Geometry_ (2005)
- John Stillwell, _The Four Pillars of Geometry_
- David C. Lay, _Linear Algebra and Its Applications_

### Key Papers

- Wildberger, N. "A Rational Approach to Geometry"
- Coxeter, H.S.M. _Projective Geometry_

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
