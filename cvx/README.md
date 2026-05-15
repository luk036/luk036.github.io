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

## 🧩 Topics Flow

.mermaid[

<pre>
graph TD
    A[Convex Optimization] --> B[Fundamentals]
    A --> C[Geometric Prog.]
    A --> D[Ellipsoid Method]
    A --> E[Applications]
    B --> B1[Convex Sets/Functions]
    B --> B2[KKT Conditions]
    C --> C1[Posynomials]
    D --> D1[Cutting-plane]
    D --> D2[Ellipsoid]
    E --> E1[Filter Design]
    E --> E2[Circuit Sizing]

    style A fill:#4caf50
    style B fill:#2196f3
    style C fill:#ff9800
    style D fill:#9c27b0
    style E fill:#f44336
    style B1 fill:#2196f3
    style B2 fill:#2196f3
    style C1 fill:#ff9800
    style D1 fill:#9c27b0
    style D2 fill:#9c27b0
    style E1 fill:#f44336
    style E2 fill:#f44336
</pre>

]

---

### 1. Convex Optimization Fundamentals

| Topic                                                      | Description                                                  |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| [Introduction to Convex Optimization](cvxprog-remark.html) | Basic concepts, convex functions/sets, KKT conditions, CVXPY |
| [Convexify the Non-convex's](convexify-remark.html)        | Techniques to convert non-convex problems to convex          |
| [Quasi-convex Programming](quasicvx-remark.html)           | Problems where objective is quasi-convex                     |
| [Alternating Minimization](alternating-remark.html)        | Optimization technique for certain classes of problems       |

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
| [Cutting-plane Method and Its Amazing Oracles](cutting_plane.html)    | Separation oracle, robust convex optimization  |
| [Ellipsoid Method Revisited](ellipsoid.html)                          | Detailed notes on ellipsoid method             |
| [Understanding the ellalgo Package](ellalgo-remark.html)              | Python implementation of ellipsoid method      |
| [LDLT factorization](LDLT.html)                                       | Efficient matrix factorization                 |
| [Preconditioned Krylov subspace methods](krylov-remark.html)          | Linear system solvers                          |

---

### 5. Filter Design Applications

| Topic                                        | Description                                                           |
| -------------------------------------------- | --------------------------------------------------------------------- |
| [Multiplierless FIR Filter Design](fir.html) | Spectral factorization, CSD representation, discrete ellipsoid method |

---

## 📦 Package: ellalgo

The `ellalgo` package implements cutting-plane methods with a clean separation between:

- **SearchSpace**: The ellipsoid representation (`Ell` class)
- **Oracle**: Problem-specific feedback providing cuts
- **Algorithm**: Generic cutting-plane algorithms

> 📖 GitHub: [luk036/ellalgo](https://github.com/luk036/ellalgo)

---

## 🏗️ ellalgo Architecture

.mermaid[

<pre>
graph LR
    A[Algorithm] --> B[SearchSpace]
    A --> C[Oracle]
    B --> D[Ell class]
    B --> E[update_bias_cut]
    B --> F[update_central_cut]
    C --> G[OracleFeas]
    C --> H[OracleOptim]

    style A fill:#ff9800
    style B fill:#2196f3
    style C fill:#4caf50
    style D fill:#2196f3
    style E fill:#2196f3
    style F fill:#2196f3
    style G fill:#4caf50
    style H fill:#4caf50
</pre>

]

---

## 📖 Key References

### Textbooks

- Boyd, S., & Vandenberghe, L. (2004). _Convex Optimization_. Cambridge University Press.
- Bertsimas, D., & Tsitsiklis, J. (1997). _Introduction to Linear Optimization_.

### Key Papers

- Hershenson, M. D., Boyd, S. P., & Lee, T. H. (2001). "Optimal design of a CMOS op-amp via geometric programming." IEEE TCAD.
- Goodman, J. W. (1997). "Spectral factorization for FIR filter design via convex optimization."

---

## 🗂️ File Structure

```text
cvx/
├── alternating-remark.html # Alternating minimization
├── convexify-remark.html   # Convexification techniques
├── cvx_pwl_fit.html        # Piecewise-linear fitting
├── cvxfit-remark.html      # B-spline fitting
├── cvxprog-remark.html     # Intro to Convex Optimization
├── cutting_plane.html      # Cutting-plane method (Part 2)
├── ellalgo-diagrams.md     # ellalgo package diagrams
├── ellalgo-remark.html     # ellalgo package
├── ellipsoid.html          # Ellipsoid method revisited (notes)
├── ellipsoid.md            # Detailed notes
├── ellipsoid_slides.html   # Ellipsoid method (Part 1)
├── fir.html                # Multiplierless FIR filter design
├── geomprog-remark.html    # Geometric Programming
├── index.html              # Slide viewer (loads README.md)
├── krylov-remark.html      # Krylov methods
├── LDLT.html               # LDLT factorization
├── lmi.html                # Linear Matrix Inequalities
├── quasicvx-remark.html    # Quasi-convex programming
└── README.md               # This file
```

---

## 🗂️ Optimization Methods

.mermaid[
<pre>
graph TD
    A[Optimization Methods] --> B[Convex]
    A --> C[Quasi-convex]
    A --> D[Non-convex]
    B --> B1[LP / QP / SDP]
    C --> C1[Bisection]
    C --> C2[Cutting-plane]
    D --> D1[Relaxation]
    D --> D2[Alternating Min.]

    style A fill:#f44336
    style B fill:#4caf50
    style C fill:#ff9800
    style D fill:#9c27b0
    style B1 fill:#4caf50
    style C1 fill:#ff9800
    style C2 fill:#ff9800
    style D1 fill:#9c27b0
    style D2 fill:#9c27b0
</pre>
]

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
