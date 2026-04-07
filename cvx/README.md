layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Mathematical Algorithms (Convex Optimization)

@luk036 👨‍💻

---

## 📚 Overview

This section covers mathematical algorithms with a focus on convex optimization and its applications in engineering, particularly Electronic Design Automation (EDA). Topics range from foundational concepts to advanced methods like the ellipsoid method.

---


### 1. Convex Optimization Fundamentals

| Topic                                                      | Description                                                  |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| [Introduction to Convex Optimization](cvxprog-remark.html) | Basic concepts, convex functions/sets, KKT conditions, CVXPY |
| [Convexify the Non-convex's](convexify.html)               | Techniques to convert non-convex problems to convex          |
| [Quasi-convex Programming](quasicvx.html)                  | Problems where objective is quasi-convex                     |
| [Alternating Minimization](alternating.html)               | Optimization technique for certain classes of problems       |

---

### 2. Geometric Programming

| Topic                                         | Description                              |
| --------------------------------------------- | ---------------------------------------- |
| [Geometric Programming](geomprog-remark.html) | Posynomial functions, GP transformations |

> **Key Applications**: Transistor sizing, wire sizing, power distribution

---

### 3. Advanced Topics

| Topic                                               | Description                               |
| --------------------------------------------------- | ----------------------------------------- |
| [Linear Matrix Inequalities](lmi.html)              | LMI formulation, semidefinite programming |
| [Convex Piecewise-Linear Fitting](cvx_pwl_fit.html) | PWL approximation                         |
| [Convex Fitting using B-spline](cvxfit-remark.html) | Spline-based curve fitting                |

---

### 4. The Ellipsoid Method

| Topic                                                                 | Description                                    |
| --------------------------------------------------------------------- | ---------------------------------------------- |
| [The Ellipsoid Method and Its Amazing Oracles](ellipsoid_slides.html) | Historical context, deep/central/parallel cuts |
| [Understanding the ellalgo Package](ellalgo-remark.html)              | Python implementation of ellipsoid method      |
| [LDLT factorization](LDLT.html)                                       | Efficient matrix factorization                 |
| [Preconditioned Krylov subspace methods](krylov-remark.html)          | Linear system solvers                          |

---

## 📦 Package: ellalgo

The `ellalgo` package implements cutting-plane methods with a clean separation between:

-   **SearchSpace**: The ellipsoid representation (`Ell` class)
-   **Oracle**: Problem-specific feedback providing cuts
-   **Algorithm**: Generic cutting-plane algorithms

> 📖 GitHub: [luk036/ellalgo](https://github.com/luk036/ellalgo)

---

## 📖 Key References

### Textbooks

-   Boyd, S., & Vandenberghe, L. (2004). _Convex Optimization_. Cambridge University Press.
-   Bertsimas, D., & Tsitsiklis, J. (1997). _Introduction to Linear Optimization_.

### Key Papers

-   Hershenson, M. D., Boyd, S. P., & Lee, T. H. (2001). "Optimal design of a CMOS op-amp via geometric programming." IEEE TCAD.
-   Goodman, J. W. (1997). "Spectral factorization for FIR filter design via convex optimization."

---

## 🗂️ File Structure

```text
cvx/
├── cvxprog-remark.html   # Intro to Convex Optimization
├── convexify.html        # Convexification techniques
├── quasicvx.html         # Quasi-convex programming
├── alternating.html      # Alternating minimization
├── geomprog-remark.html  # Geometric Programming
├── lmi.html              # Linear Matrix Inequalities
├── cvx_pwl_fit.html      # Piecewise-linear fitting
├── cvxfit-remark.html    # B-spline fitting
├── ellipsoid_slides.html # Ellipsoid method
├── ellalgo-remark.html   # ellalgo package
├── LDLT.html             # LDLT factorization
├── krylov-remark.html    # Krylov methods
└── ellipsoid.md          # Detailed notes
```

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
