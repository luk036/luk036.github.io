layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Low-Discrepancy Sequences & Spherical Point Generation in Python 🐍

@luk036 👨‍💻 · 2026 📅

---

### ✨ Introduction: What are Low-Discrepancy Sequences? 🤔

- **Low-Discrepancy Sequences (LDS)** are not random numbers, but rather sequences designed to be **well-distributed** 📊.
- They aim to fill a space more uniformly than pseudo-random number generators 🎲.
- This uniformity is useful in various applications:
- **Sampling** 🔍
- **Optimization** ⚙️
- **Numerical integration** ∫
- Particularly useful in **Monte Carlo simulations** 🎰

.mermaid[

<pre>
graph LR
    subgraph "Random Sampling"
        R1[Points] --> R2[Clustered / Uneven]
    end
    subgraph "LDS"
        L1[Points] --> L2[Uniform / Well-distributed]
    end
    R2 --> C[Monte Carlo\nSimulations]
    L2 --> C

    style R1 fill:#ff9800
    style R2 fill:#f44336
    style L1 fill:#ff9800
    style L2 fill:#4caf50
    style C fill:#2196f3
</pre>

]

---

### 🧩 The `lds-gen` Package 📦

- The `lds-gen` package is a Python tool specifically for generating **low-discrepancy sequences**.
- It provides classes for different types of LDS 🏗️.
- The main types implemented are:
- **van der Corput sequence** (1D) 1️⃣
- **Halton sequence** (nD) 🧮
- Other generators like **Circle** ⭕, **Sphere** 🌐, **3-Sphere** 🔮, and **n-dimensional Halton** are also available.

.mermaid[

<pre>
graph TD
    LDS[lds-gen Package] --> VDC[VdCorput\n1D LDS]
    LDS --> HAL[Halton\nnD LDS]
    LDS --> CIR[Circle\nS¹ Generator]
    LDS --> SPH[Sphere\nS² Generator]
    LDS --> SP3[Sphere3\nS³ Generator]

    style LDS fill:#9c27b0
    style VDC fill:#4caf50
    style HAL fill:#4caf50
    style CIR fill:#2196f3
    style SPH fill:#2196f3
    style SP3 fill:#2196f3
</pre>

]

---

### `lds-gen`: van der Corput Sequence 🔢

- The **van der Corput sequence** is a 1-dimensional LDS 📏.
- It's based on reversing the digits of the natural number sequence in a given base 🔄.
- _Example:_ In base 2, 1 is 1 (binary 1), reverse is 1. 2 is 10, reverse is 01 (decimal 0.5). 3 is 11, reverse is 11 (decimal 0.75). 4 is 100, reverse is 001 (decimal 0.125).

.mermaid[

<pre>
flowchart LR
    N["Natural Number\nk = 4"] --> B["Binary\n100"]
    B --> R["Reversed\n001"]
    R --> D["Decimal\n0.125"]

    style N fill:#ff9800
    style B fill:#4caf50
    style R fill:#2196f3
    style D fill:#2196f3
</pre>

]

- The package provides the **`VdCorput` class** and the core **`vdc_i` function** ⚙️.
- `vdc_i` takes a number `k` and a `base` (default 2) and converts `k` from base 10 to a decimal number using the specified base 🔢.
- The `VdCorput` class wraps `vdc_i` and keeps track of the current count 🧮.

---

### `lds-gen`: Halton Sequence 🌐

- The **Halton sequence** extends the van der Corput idea to multiple dimensions 🚀.
- It generates **nD points** by combining `n` van der Corput sequences, each using a **different base** 🏗️.
- Commonly generates **2D points** using two different bases 2️⃣.
- The source mentions an **n-dimensional Halton generator** specifically.

---

### `lds-gen`: Core Functionality ⚙️

- Generators typically take **base numbers** or sequences of bases as input 📥.
- They produce **floating-point numbers** or lists of floating-point numbers 📊.
- **`pop()` method:** Used to generate the **next point** in the sequence ⏭️.
- It increments an internal counter and calculates the next value ➕.
- For multi-dimensional sequences (like Halton), `pop()` returns a list of floats 📋.
- **`reseed()` method:** Allows **resetting the state** of the sequence generator to a specific starting point, determined by a `seed` parameter. Useful for reproducibility 🔄.

---

### `lds-gen`: Example (van der Corput) 💡

```python
>>> vgen = VdCorput(base=2) # Initialize base 2 generator
>>> vgen.reseed(0) # Reset to start from k=0
>>> for _ in range(10):
...     print(vgen.pop())
0.5
0.25
0.75
0.125
0.625
0.375
0.875
0.0625
0.5625
0.3125
```

_Example output from source_ 📋

---

### 🌍 The `sphere-n` Package 📦

- The `sphere-n` package is designed to generate points on the **surface of spheres** in different dimensions 🎯.
- It's useful for mathematicians 🧮, scientists 🔬, and computer graphics programmers 🎮.
- The goal is to create **well-distributed** points on the spherical surface ⚖️.
- Uses LDS generators (like van der Corput) and applies mathematical transformations ➗.

---

### `sphere_n`: Modules & Methods 🧰

- **`sphere_n.cylind_n` module:** Generates points using **cylindrical mapping** 🗺️.
- Combines a van der Corput generator with cosine/sine values and the Pythagorean identity 📐.
- **`sphere_n.sphere_n` module:** Generates points on spheres using spherical mapping 🌐.
- Includes generators for 2D (Circle) ⭕, 3D, and higher dimensions.
- Uses a combination of van der Corput sequences and trigonometric functions 📈.
- Both modules/generators provide:
- **`pop()` method:** Returns the **next point** on the sphere as a list of floats ⏭️.
- **`reseed()` method:** **Resets the generator** to a specific seed 🔄.

---

### `sphere_n`: Example (3-Sphere) 💡

```python
>>> sgen = Sphere3(base=) # Initialize 3-Sphere generator with bases
>>> sgen.reseed(0) # Reset with seed 0
>>> print(sgen.pop())
[0.4809684718998214, 0.6031153874276115, -0.5785681518302232, 0.2649326520763179, 6.1232...]
```

_Example output from source. Note: Output is a list of coordinates on the 3-sphere._

---

### `sphere_n`: Performance ⚡

- The package uses a **caching mechanism** (`@cache decorator`) to improve performance 🚀.
- This avoids repeating expensive calculations for functions that are called multiple times with the same arguments 🔄.

---

### 🎯 Conclusion 🏁

- The `lds-gen` and `sphere-n` packages provide powerful tools for generating **well-distributed points** 🎯.
- `lds-gen` focuses on generating **low-discrepancy sequences** in various dimensions 📊.
- `sphere-n` specializes in generating points **uniformly on the surface of spheres** 🌐.
- These tools are valuable for improving the efficiency and accuracy of numerical methods in fields like simulations and analysis 🔍.

.mermaid[

<pre>
flowchart LR
    LDS[LDS Generators] --> TRANS[Spherical\nTransform]
    TRANS --> S1[S¹\nCircle]
    TRANS --> S2[S²\nSphere]
    TRANS --> S3[S³\n3-Sphere]
    TRANS --> SN[Sⁿ\nn-Sphere]

    style LDS fill:#ff9800
    style TRANS fill:#9c27b0
    style S1 fill:#4caf50
    style S2 fill:#4caf50
    style S3 fill:#2196f3
    style SN fill:#2196f3
</pre>

]

**GitHub** 🐙: [lds-gen](https://github.com/luk036/lds-gen), [sphere-n](https://github.com/luk036/sphere-n) 🔗

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
