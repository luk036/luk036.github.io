layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Approximate Computing 🚀💻

@luk036 👨‍💻 · 2026 📅

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
  style AA fill:#4caf50
  style ML fill:#ff9800
  style CSD fill:#2196f3
  style DF fill:#9c27b0
  style RF fill:#f44336
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

| Topic                                  | Description                       |
| -------------------------------------- | --------------------------------- |
| [csdigit Package](csdigit-remark.html) | Python package for CSD conversion |

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
| [Digital Filters: FIR & IIR](FIR-IIR-remark.html)       | Design and implementation                     |

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
  style csdigit fill:#4caf50
  style ml fill:#ff9800
  style ginger fill:#2196f3
</pre>

]

---

## 🗂️ File Structure

```text
AxC/
├── README.md                 # This file
├── AxC-remark.html          # Survey slides
├── AxC.md                   # Survey notes
├── index.html               # Slide viewer
├── multiplier-free-remark.html # Multiplierless slides
├── multiplier-free.md       # Notes
├── csdigit-remark.html       # Package slides
├── csdigit.md               # Documentation
├── csd.md                   # CSD theory
├── csd-remark.html          # CSD theory slides
├── multiplierless-remark.html # FIR design slides
├── multiplierless.md        # Notes
├── ginger-remark.html       # Root finding slides
├── ginger.md                # Documentation
├── FIR-IIR-remark.html     # Filter slides
└── FIR-IIR.md               # Notes
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
  style Mitchell fill:#4caf50
  style Goldschmidt fill:#ff9800
  style CSE fill:#2196f3
  style CORDIC fill:#9c27b0
</pre>

]

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
