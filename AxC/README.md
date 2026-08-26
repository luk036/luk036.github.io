layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Approximate Computing 🚀💻

@luk036 👨‍💻 · 2026 📅

---

### 📋 Agenda

.pull-left[

**Arithmetic** 📊
- Survey
- Multiplierless

**CSD** 📐
- csdigit
- CSD Theory

]
.pull-right[

**Filters** 🔄
- FIR/IIR
- Root Finding

]

---

## 📚 Overview

This section covers Approximate Computing (AxC), a paradigm for designing energy-efficient circuits and systems. Topics include approximate arithmetic circuits, multiplierless designs, and digital filter implementations. The content bridges theoretical approaches with practical Python implementations.

---

### Topics Flow

.mermaid[

<pre>
graph TD
  AA[Approximate<br/>Arithmetic] --> ML[Multiplierless<br/>Designs]
  ML --> CSD[Canonical<br/>Signed Digit]
  CSD --> DF[Digital<br/>Filters]
  DF --> RF[Root<br/>Finding]
  style AA fill:#c8e6c9,stroke:#2e7d32,stroke-width:3px
  style ML fill:#fff3e0,stroke:#e65100,stroke-width:3px
  style CSD fill:#e3f2fd,stroke:#1565c0,stroke-width:3px
  style DF fill:#f3e5f5,stroke:#7b1fa2,stroke-width:3px
  style RF fill:#ffcdd2,stroke:#c62828,stroke-width:3px
</pre>

]

---

### 1. Approximate Arithmetic Circuits

| Topic                                                        | Description                            |
| ------------------------------------------------------------ | -------------------------------------- |
| [Approximate Arithmetic Circuits: A Survey](AxC-remark.html) | Comprehensive survey of AxC techniques |

> 📖 See: [AxC.md](AxC.md)

---

### 2. Multiplierless Designs

| Topic                                                 | Description                        |
| ----------------------------------------------------- | ---------------------------------- |
| [Multiplierless Designs](multiplier-free-remark.html) | Hardware-efficient implementations |

**Key Concepts:**

- Replace multiplication with **shifts + additions/subtractions**
- Example: `y = 5x` → `y = (x << 2) + x`
- Reduces area, power, can increase speed

**Applications:**

- FIR/IIR filters
- DCT, DFT, DWT transforms
- Filter banks

> 📖 See: [multiplier-free.md](multiplier-free.md)

---

### 3. Canonical Signed Digit (CSD)

| Topic                                                  | Description                                |
| ------------------------------------------------------ | ------------------------------------------ |
| [csdigit Package](csdigit-remark.html)                 | Python package for CSD conversion          |
| [CSD Optimization: C++ & Python](csd-remark.html)      | Performance optimization (C++ fixes, ports) |
| [CSD Multiplier: Shift-Add Synthesis](csd_multiplier-remark.html) | LCSRe-based optimization for FIR filters   |

**What is CSD?**

- Number representation using only `0`, `+`, `-`
- Facilitates sharing in multiplierless designs
- Reduces switching activity

**Package Features:**

- Convert decimal → CSD and back
- Find longest repeated substring
- CLI utilities

> 📖 See: [csdigit.md](csdigit.md)
> 📖 GitHub: [luk036/csdigit](https://github.com/luk036/csdigit)

---

### 4. Digital Filters

| Topic                                                   | Description                                   |
| ------------------------------------------------------- | --------------------------------------------- |
| [Multiplierless FIR Design](multiplierless-remark.html) | FIR filter implementation without multipliers |
| [Multiplierless FIR: Py→Rust→C++](multiplierless-py-rs-cpp-remark.html) | Cross-language performance comparison       |
| [Digital Filters: FIR & IIR](FIR-IIR-remark.html)       | Design and implementation                     |
| [Direct-Form vs Transpose-Form FIR](direct-transpose-remark.html) | Multiplierless filter architecture comparison |

**Filter Design Flow:**

1. Specify frequency domain requirements
2. Determine number of coefficients and word lengths
3. Optimize for bounded integer coefficients
4. Generate adder circuits for MCM

**Parameters:**

- Coefficient word length
- Filter order
- Adder cost (number of additions)
- Adder depth

---

### 5. Polynomial Root Finding

| Topic                                | Description              |
| ------------------------------------ | ------------------------ |
| [ginger Package](ginger-remark.html) | Finding polynomial roots |
| [ginger-cpp: Root Finding & Reconstruction](ginger-cpp-remark.html) | C++ root-finding & reconstruction |
| [Spectral Factorization](spectral_fact-remark.html) | FFT vs root-finding |
| [Root Finding: Py→Rust→C++](py-rs-cpp-ginger-remark.html) | Cross-language root-finding performance |

---

## 📦 Packages

### `csdigit` - Canonical Signed Digit

```python
from csdigit import to_csd, from_csd

# Convert to CSD
csd = to_csd(28.5, places=4)
print(csd)  # "+00-00.+0"

# Convert back
decimal = from_csd(csd)
print(decimal)  # 28.5
```

### `multiplierless` - FIR Filter Design

```python
# Design multiplierless FIR filter
# See: multiplierless.md
```

---

### Package Relationships

.mermaid[

<pre>
graph LR
  csdigit[csdigit<br/>CSD Conversion] <--> ml[multiplierless<br/>FIR Filter]
  ml <--> ginger[ginger<br/>Root Finding]
  style csdigit fill:#c8e6c9,stroke:#2e7d32,stroke-width:3px
  style ml fill:#fff3e0,stroke:#e65100,stroke-width:3px
  style ginger fill:#e3f2fd,stroke:#1565c0,stroke-width:3px
</pre>

]

---

## 🗂️ File Structure

```text
AxC/
├── README.md                              # Course overview (this file)
├── index.html                             # Slide viewer (loads README.md)
│
├── ### Remark.js HTML Slides (*-remark.html)
├── AxC-remark.html                        # Approximate Arithmetic Circuits Survey
├── csd-remark.html                        # CSD Optimization: C++ & Python
├── csd_multiplier-remark.html             # CSD Multiplier: Shift-Add Synthesis
├── csdigit-remark.html                    # csdigit Python Package
├── direct-transpose-remark.html           # Direct-Form vs Transpose-Form FIR
├── FIR-IIR-remark.html                    # Digital Filters: FIR & IIR
├── ginger-remark.html                     # ginger Polynomial Root Finding Package
├── ginger-cpp-remark.html                 # ginger-cpp Root Finding & Reconstruction
├── multiplier-free-remark.html            # Multiplierless Designs
├── multiplierless-remark.html             # Multiplierless FIR Filter Design
├── multiplierless-py-rs-cpp-remark.html   # Multiplierless FIR: Py→Rust→C++
├── py-rs-cpp-ginger-remark.html           # Root Finding: Py→Rust→C++
├── spectral_fact-remark.html              # Spectral Factorization
│
├── ### Remark.js Markdown Sources (loaded via sourceUrl)
├── AxC.md                                 # Source for AxC-remark.html
├── csdigit.md                             # Source for csdigit-remark.html
├── FIR-IIR.md                             # Source for FIR-IIR-remark.html
├── ginger.md                              # Source for ginger-remark.html
├── multiplier-free.md                     # Source for multiplier-free-remark.html
├── multiplierless.md                      # Source for multiplierless-remark.html
│
├── ### Content Notes & Reference
├── csd.md                                 # CSD theory notes
│
└── ### Other
    └── (figures, additional assets)
```

---

## 📖 Key References

### Survey Papers

- "Approximate Arithmetic Circuits: A Survey, Characterization, and Recent Applications" (IEEE, 2020)

### Key Algorithms

| Algorithm                        | Purpose                    |
| -------------------------------- | -------------------------- |
| Mitchell's Logarithm             | Approximate multiplication |
| Goldschmidt                      | Division approximation     |
| Common Subexpression Elimination | Multiplier sharing         |
| CORDIC                           | Trigonometric computation  |

---

### Algorithm Classification

.mermaid[

<pre>
graph TD
  Algorithms[AxC Algorithms] --> Mitchell[Mitchell's<br/>Logarithm]
  Algorithms --> Goldschmidt[Goldschmidt<br/>Division]
  Algorithms --> CSE[CSE<br/>Elimination]
  Algorithms --> CORDIC[CORDIC<br/>Trigonometric]
  style Mitchell fill:#c8e6c9,stroke:#2e7d32,stroke-width:3px
  style Goldschmidt fill:#fff3e0,stroke:#e65100,stroke-width:3px
  style CSE fill:#e3f2fd,stroke:#1565c0,stroke-width:3px
  style CORDIC fill:#f3e5f5,stroke:#7b1fa2,stroke-width:3px
</pre>

]

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
