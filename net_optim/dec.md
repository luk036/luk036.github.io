layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# **Discrete Exterior Calculus**

@luk036 👨‍💻

2025-06-01 📅

---

### 📐 Discrete Exterior Calculus (DEC) ✨

.mermaid[

<pre>

graph LR
    A[Continuous Exterior Calculus] -->|Discretize| B[DEC]
    B --> C[Simplicial Meshes]
    B --> D[Differential Forms]
    B --> E[Structure Preservation]
    style A fill:#f9f,stroke:#333
    style B fill:#bbf,stroke:#333
    style C fill:#f96,stroke:#333
    style D fill:#6f9,stroke:#333
    style E fill:#9cf,stroke:#333
</pre>

]

- **What is DEC?** 🤔💡
- A framework for computational modeling. ⚙️
- Based on differential forms and simplicial meshes. 📊
- Extends continuous exterior calculus to a discrete setting. 🔄
- Goal: Preserve geometric and physical structure in numerical simulations. 🎯

---

### 🌌 Exterior Calculus Basics 🔍

.mermaid[

<pre>

pie
    title Differential Forms
    "0-form (Scalar)" : 30
    "1-form (Line Integral)" : 30
    "2-form (Surface Integral)" : 20
    "3-form (Volume Integral)" : 20
</pre>

]

- Exterior calculus deals with **differential forms (k-forms)**. 📜
- They are related to quantities integrated over geometric objects. 📏
  - **0-form:** Like a scalar function (e.g., elevation at a point). 📍
  - **1-form:** Like a quantity integrated along a curve (e.g., elevation _gain_ along a path). 🛤️
- Closely related to vector calculus operations. 🔄
  - Exterior derivative of a 1-form looks like the curl of a vector field. 🌪️

---

### 🤖 DEC on Simplicial Complexes 🏗️

.mermaid[

<pre>

graph TD
    V[Vertex - 0-form] -->|d0| E[Edge - 1-form]
    E -->|d1| F[Face - 2-form]
    F -->|d2| V3[Volume - 3-form]
    style V fill:#f9f,stroke:#333
    style E fill:#6f9,stroke:#333
    style F fill:#f96,stroke:#333
    style V3 fill:#9cf,stroke:#333
</pre>

]

- DEC operates on **simplicial complexes** (meshes) and their associated **dual meshes**. 🔲
- A **discrete k-form** represents the integral of a continuous k-form over a k-dimensional mesh object (primal or dual). 📊
  - Discrete **0-form**: Scalar value at a **vertex**. ⚫
  - Discrete **1-form**: Value associated with an **edge** (integral along an edge). ➖
  - Discrete **2-form** (in 2D): Value associated with a **triangle**. 🔺
  - Discrete variables require specifying an **orientation** for each mesh element, just like elevation gain needs direction (+151m vs -151m). 🔄
- Discrete differential forms are stored with both a number and the specified orientation. 🔢

---

### ✨ The Core Trio: d, ★, ∧

.mermaid[

<pre>

flowchart LR
    A[d: Exterior Derivative] --> B[Generalizes differentiation]
    C[★: Hodge Star] --> D[Maps primal to dual]
    E[∧: Wedge Product] --> F[Multiplies forms]
    style A fill:#f9f,stroke:#333
    style C fill:#6f9,stroke:#333
    style E fill:#f96,stroke:#333
</pre>

]

- **Exterior Derivative (d)**: Generalizes differentiation. Maps k-forms to (k+1)-forms. 🔄
  - `d0` maps values on vertices (0-forms) to values on edges (1-forms). ↗️
  - Requires taking orientation into account. 🔄
  - In continuous calculus, `d` on 1-forms looks like curl. 🌪️
  - A defining property: `d` applied twice is zero (`dp+1dp = 0`). ❌
- **Hodge Star Operator (★)**: 💫🌟 Relates k-forms to (N-k)-forms in N dimensions. Incorporates metric information. Often transfers forms between primal and dual complexes. A Delaunay Hodge star exists. ⭐
- **Wedge Product (∧)**: 🌱✖️ Multiplies forms. The discrete definition involves integration. For instance, a 1-form wedge a 0-form results in a 1-form. ➗

---

### 👍 Advantages for Computation 🚀

.mermaid[

<pre>

mindmap
  root((DEC Advantages))
    Structure Preservation
      Homological Structure
      Inviscid Invariants
    Geometric Flexibility
      Curved Surfaces
      Arbitrary Manifolds
    Numerical Stability
      Accurate Results
      Long-term Behavior
</pre>

]

- **Structure Preservation** 🏛️🔒: DEC discretizations aim to preserve the physical and mathematical properties (structure) of continuous systems.
  - Proven successful at preserving the **homological structure** of a surface. 🧬
  - Can lead to "structure-preserving algorithms". ✅
  - Helps preserve **inviscid invariants** over extended periods. ⏳
- **Geometric Flexibility** 🌐🌀: Works over **surface simplicial meshes** and on **arbitrary curved surfaces/manifolds**. Tested on flows past cylinders on spherical surfaces, double periodic shear layers on a plane, and harmonic waves on rotating spheres. 🌍
- Leads to numerically stable and accurate results for various problems. 📊

---

### 🖼️ Shaping the Digital World 💻

.mermaid[

<pre>

graph LR
    DEC --> A[Poisson Equations]
    DEC --> B[Mesh Smoothing]
    DEC --> C[Surface Parameterization]
    DEC --> D[Vector Fields]
    DEC --> E[Shortest Paths]
    DEC --> F[Elasticity]
    style DEC fill:#bbf,stroke:#333
    style A fill:#f9f,stroke:#333
    style B fill:#6f9,stroke:#333
    style C fill:#f96,stroke:#333
    style D fill:#9cf,stroke:#333
    style E fill:#c9f,stroke:#333
    style F fill:#fc9,stroke:#333
</pre>

]

- A flexible and efficient framework for digital geometry processing. 🛠️
- Applications include:
  - Solving the **scalar Poisson equation** (`∆u = f`) on meshes. Involves building a sparse matrix for the Laplacian. 🔢
  - Implicit **mean curvature flow** for mesh smoothing. 🌀
  - Surface **parameterization** (e.g., conformal mapping). Can compute via the first non-trivial eigenvector of conformal energy. 🗺️
  - **Vector field** decomposition (Helmholtz-Hodge) and design (using discrete connections and parallel transport). 🌪️
  - Computing **shortest paths** or geodesic distance (by solving Poisson or integrating heat flow). 🛣️
  - Improving **mesh quality**. 🔧
  - Simulating mechanical phenomena like **elastic bodies**. 🏋️

---

### 🌊 Simulating Flows 💧🌀

.mermaid[

<pre>

flowchart TB
    NS[Navier-Stokes] --> DEC
    DEC --> Cylinder[Flow Past Cylinders]
    DEC --> Airfoil[Flow Past Airfoils]
    DEC --> Vortices[Taylor-Green Vortices]
    DEC --> Shear[Shear Layers]
    DEC --> Sphere[Rotating Spheres]
    style NS fill:#bbf,stroke:#333
    style DEC fill:#9cf,stroke:#333
</pre>

]

- Used for discretizing the **incompressible Navier–Stokes equations** over surface simplicial meshes. 📜
- Uses a **primitive variable DEC formulation** with velocity as a one-form (often dual) and pressure as a zero-form (often dual). This choice means velocity integrals along dual edges correspond to mass flux across primal edges. ⚡
- Tested on various benchmarks:
  - Flow past stationary and rotating **circular cylinders** (flat and on spherical surfaces). Results like drag/lift coefficients and Strouhal number show good agreement with literature. 🌀
  - Flow past **airfoils**. ✈️
  - **Taylor–Green vortices**. Used for error convergence studies. 🔄
  - Double periodic **shear layer**. Used to show kinetic energy conservation and convergence. ⚡
  - Motion of harmonic waves and flows on **rotating spheres**. Can preserve stationary states and inviscid invariants. 🌍

---

### 🔬 Beyond Geometry & Fluids 🧪🌐

.mermaid[

<pre>

pie
    title DEC Applications
    "Geometry Processing" : 35
    "Fluid Dynamics" : 25
    "Electromagnetics" : 15
    "Elasticity" : 15
    "Computer Vision" : 10
</pre>

]

- Applicable to **variational problems** in computer vision and graphics. 👁️🎨
- Connections to **geometric mechanics** and discrete connections. ⚙️
- Mentions of related use in:
  - Computer Vision (e.g., template matching). 👁️
  - Computational Modeling. 🧮
  - Darcy flow. 💧
  - Elasticity. 🏋️
  - Electromagnetic problems. ⚡
- **Active Research Area** 🤔🔍: Developing a complete discrete calculus where _all_ continuous operators (d, ∧, ★, Lie derivative (ℒ_X), interior product (iα), etc.) work well together in the discrete setting. 🏗️

---

### 💻 Putting it into Practice 🖥️🔧

.mermaid[

<pre>

graph LR
    Theory[DEC Theory] -->|Implementation| Code
    Code --> Cpp[C++ Framework]
    Code --> Python[PyDEC]
    Code --> Convergence[Convergence Analysis]
    style Theory fill:#bbf,stroke:#333
    style Code fill:#9cf,stroke:#333
    style Cpp fill:#f9f,stroke:#333
    style Python fill:#6f9,stroke:#333
    style Convergence fill:#f96,stroke:#333
</pre>

]

- Discrete operators (like the discrete Laplacian or exterior derivative matrices) are often implemented as **sparse matrices**. 🔢
- Implementation examples and libraries exist:
  - A supplementary C++ framework is available. 📦
  - **PyDEC** is a Python library for DEC on simplicial and cubical complexes of any dimension, implementing discrete exterior derivative (as coboundary), Delaunay Hodge star, and Whitney forms. 🐍
- **Convergence**:
  - Rigorous convergence analysis for the scalar Poisson problem on arbitrary domains has been established. ✅
  - Numerical tests show convergence. For Taylor-Green vortices, the velocity _flux_ error shows second-order convergence on structured meshes and better than first-order on unstructured meshes. Interpolated velocity error is slightly better than first-order. 📈
  - The kinetic energy relative error converges in a second-order fashion with mesh size for the double periodic shear layer case. ⚡

---

count: false
class: nord-dark, middle, center

# Q&A 🎤
