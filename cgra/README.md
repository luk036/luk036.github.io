layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Hardware Acceleration 🚀💻

@luk036 👨‍💻 · 2026 📅

---

### 📋 Agenda

.pull-left[

**CGRA & FPGA** 🏗
- CGRA
- FPGA

**Compilers & HDL** 💻
- LLVM/MLIR
- LDS HDL
- Yosys

]
.pull-right[

**Advanced** 🔬
- Approx Mult
- Digital Design

]

---

## 📚 Overview

This section covers hardware acceleration techniques for high-performance and energy-efficient computing. Topics include Coarse-Grained Reconfigurable Arrays (CGRAs), approximate computing for neural networks, LLVM/MLIR compiler infrastructure, and FPGA-based acceleration.

---

### 1. Coarse-Grained Reconfigurable Arrays

| Topic                                 | Description                      |
| ------------------------------------- | -------------------------------- |
| [CGRA Architecture](CGRA-remark.html) | Spatial accelerator architecture |

**Key Concepts:**

-   **Bridging ASICs and CPUs**: Hardware-like efficiency with software-like flexibility
-   **Word-level Processing Elements (PEs)**: Connected via on-chip network
-   **Per-cycle reconfiguration**: Both PE operations and routing are reconfigurable

> 📖 See: [CGRA.md](CGRA.md)

---

### 2. Approximate Multipliers for Neural Computing

| Topic                                      | Description                       |
| ------------------------------------------ | --------------------------------- |
| [Approximate Multipliers](AxM-remark.html) | Energy-efficient neural computing |

**Motivation:**

-   Neural networks are error-tolerant
-   Approximate multipliers save energy
-   Trade-off between accuracy and efficiency

**Techniques:**

-   Voltage overscaling
-   Simplified multiplication units
-   Accuracy-configurable designs

---

### 3. Compiler Infrastructure: LLVM & MLIR

| Topic                              | Description                                |
| ---------------------------------- | ------------------------------------------ |
| [LLVM IR & MLIR](MLIR-remark.html) | Intermediate representations for compilers |

**Key Concepts:**

-   **LLVM IR**: Strongly typed, well-documented IR
  -   `@` for globals/functions
  -   `%` for local registers
  -   `iN` for integers
-   **MLIR**: Multi-Level IR for domain-specific optimization

> 📖 See: [MLIR.md](MLIR.md)

---

### 4. FPGA Acceleration

| Topic                             | Description                            |
| --------------------------------- | -------------------------------------- |
| [FPGA Overview](FPGA-remark.html) | Field-programmable gate arrays         |
| [FPGA-EDA Tools](FPGA-EDA.html)   | Electronic design automation for FPGAs |

**Key Concepts:**

-   Configurable logic blocks
-   Programmable routing
-   Trade-off between flexibility and efficiency

**Tools:**

-   HDL synthesis
-   Place and route
-   Timing analysis

---

### 5. HDL & Synthesis

| Topic                                                           | Description                                  |
| --------------------------------------------------------------- | -------------------------------------------- |
| [LDS HDL Hardware Generators](lds-hdl-remark.html)             | Low Discrepancy Sequence HDL generation      |
| [Flatten Mode in Yosys](flatten-remark.html)                    | Yosys synthesis case study                   |

---

### 6. Advanced Topics

| Topic                                                                          | Description               |
| ------------------------------------------------------------------------------ | ------------------------- |
| [Hardware Approximation](Hardware Approximation.md)                            | Approximation techniques  |
| [Digital Design](advanced_digital.md)                                          | Advanced digital circuits |
| [Spectral Factorization](spectral_fact-remark.html)                            | FFT vs root-finding       |
| [Polynomial Root Finding](ginger-remark.html)                                  | ginger package            |
| [Non-negative Matrix Factorization](Nonnegative Matrix and Tensor Factoriz.md) | Low-rank approximations   |

---

## 📦 Tools & Frameworks

### Compilers

-   **LLVM/Clang**: C/C++ compiler
-   **MLIR**: Multi-level IR framework

### Design Tools

-   **Verilog/VHDL**: HDL for FPGA design
-   **Vivado**: Xilinx FPGA toolchain

---

## 🗂️ File Structure

```text
cgra/
├── README.md                              # Course overview (this file)
├── index.html                             # Slide viewer (loads README.md)
│
├── ### Remark.js HTML Slides
├── advanced_digital-remark.html           # Advanced Digital Design
├── AxM-remark.html                        # Approximate Multipliers
├── CGRA-remark.html                       # CGRA Architecture
├── coffe2-remark.html                     # COFFE2
├── flatten-remark.html                    # Flatten Mode in Yosys
├── FPGA-remark.html                       # FPGA Overview
├── ginger-remark.html                     # Polynomial Root Finding
├── lds-hdl-remark.html                    # LDS HDL Hardware Generators
├── MLIR-remark.html                       # LLVM IR & MLIR
├── spectral_fact-remark.html              # Spectral Factorization
│
├── ### Remark.js Markdown Sources
├── CGRA.md                                # Source for CGRA-remark.html
├── coffe2.md                              # Source for coffe2-remark.html
├── MLIR.md                                # Source for MLIR-remark.html
├── advanced_digital.md                    # Digital design notes
├── FPGA.md                                # FPGA notes
│
├── ### Content Notes & Reference
├── FPGA-EDA.md                            # EDA tools for FPGAs
├── Hardware Approximation.md              # Approximation techniques
├── Approximate Multiplier Design Challeng.md  # Approx multiplier
├── Nonnegative Matrix and Tensor Factoriz.md   # Matrix factorization
├── acm2018.md                             # ACM 2018 paper
├── Deep Neural Network for Non-Negative Matrix Factorization towards Low Rank Approximation.md
│
└── ### Assets
    └── (figures, additional assets)
```

---

## 📖 Key References

### Books & Papers

-   "Handbook of Computer Architecture" - CGRAs
-   LLVM Documentation (llvm.org/docs)
-   MLIR Documentation (mlir.llvm.org)

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
