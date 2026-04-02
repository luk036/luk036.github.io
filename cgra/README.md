layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Hardware Acceleration 🚀💻

@luk036 👨‍💻

---

## 📚 Overview

This section covers hardware acceleration techniques for high-performance and energy-efficient computing. Topics include Coarse-Grained Reconfigurable Arrays (CGRAs), approximate computing for neural networks, LLVM/MLIR compiler infrastructure, and FPGA-based acceleration.

---

## 🎯 Topics

### 1. Coarse-Grained Reconfigurable Arrays

| Topic                                 | Description                      |
| ------------------------------------- | -------------------------------- |
| [CGRA Architecture](CGRA-remark.html) | Spatial accelerator architecture |

**Key Concepts:**

- **Bridging ASICs and CPUs**: Hardware-like efficiency with software-like flexibility
- **Word-level Processing Elements (PEs)**: Connected via on-chip network
- **Per-cycle reconfiguration**: Both PE operations and routing are reconfigurable

> 📖 See: [CGRA.md](CGRA.md)

---

### 2. Approximate Multipliers for Neural Computing

| Topic                                      | Description                       |
| ------------------------------------------ | --------------------------------- |
| [Approximate Multipliers](AxM-remark.html) | Energy-efficient neural computing |

**Motivation:**

- Neural networks are error-tolerant
- Approximate multipliers save energy
- Trade-off between accuracy and efficiency

**Techniques:**

- Voltage overscaling
- Simplified multiplication units
- Accuracy-configurable designs

---

### 3. Compiler Infrastructure: LLVM & MLIR

| Topic                              | Description                                |
| ---------------------------------- | ------------------------------------------ |
| [LLVM IR & MLIR](MLIR-remark.html) | Intermediate representations for compilers |

**Key Concepts:**

- **LLVM IR**: Strongly typed, well-documented IR
  - `@` for globals/functions
  - `%` for local registers
  - `iN` for integers
- **MLIR**: Multi-Level IR for domain-specific optimization

> 📖 See: [MLIR.md](MLIR.md)

---

### 4. FPGA Acceleration

| Topic                         | Description                            |
| ----------------------------- | -------------------------------------- |
| [FPGA Overview](FPGA.md)      | Field-programmable gate arrays         |
| [FPGA-EDA Tools](FPGA-EDA.md) | Electronic design automation for FPGAs |

**Key Concepts:**

- Configurable logic blocks
- Programmable routing
- Trade-off between flexibility and efficiency

**Tools:**

- HDL synthesis
- Place and route
- Timing analysis

---

### 5. Advanced Topics

| Topic                                                                          | Description               |
| ------------------------------------------------------------------------------ | ------------------------- |
| [Hardware Approximation](Hardware Approximation.md)                            | Approximation techniques  |
| [Digital Design](advanced_digital.md)                                          | Advanced digital circuits |
| [Non-negative Matrix Factorization](Nonnegative Matrix and Tensor Factoriz.md) | Low-rank approximations   |

---

## 📦 Tools & Frameworks

### Compilers

- **LLVM/Clang**: C/C++ compiler
- **MLIR**: Multi-level IR framework

### Design Tools

- **Verilog/VHDL**: HDL for FPGA design
- **Vivado**: Xilinx FPGA toolchain

---

## 🗂️ File Structure

```
cgra/
├── README.md                 # This file
├── CGRA-remark.html          # CGRA slides
├── CGRA.md                   # Notes
├── AxM-remark.html           # Approximate multipliers
├── Approximate Multiplier Design Challeng.md
├── MLIR-remark.html          # LLVM/MLIR slides
├── MLIR.md                   # Notes
├── coffe2-remark.html        # Coffe 2
├── coffe2.md                 # Documentation
├── FPGA.md                  # FPGA notes
├── FPGA-EDA.md              # EDA tools
├── Hardware Approximation.md # Approximation
├── advanced_digital.md       # Digital design
├── Nonnegative Matrix and Tensor Factoriz.md
└── acm2018.md               # ACM 2018 paper
```

---

## 📖 Key References

### Books & Papers

- "Handbook of Computer Architecture" - CGRAs
- LLVM Documentation (llvm.org/docs)
- MLIR Documentation (mlir.llvm.org)

---

count: false
class: nord-dark, middle, center

# Q&A 🎤
