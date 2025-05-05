layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

## ♒︎ Multiplierless FIR Filter Automatic Design Tool

👨🏻‍🏫 @luk036
<https://github.com/luk036/multiplierless>

---

## 🎬 Introduction

- Input: specification
- Output: filter coefficients (or a Verilog file)
- Method: Convex optimization via Spectral factorization

- Convexity is the key!!! ✨🚀
- Convex optimization:
  - 🫒 Ellipsoid method + parallel cuts (`luk036/ellalgo`)
- Spectral factorization:
  - FFT (`luk036/multiplierless`)
  - Polynomial root-finding (`luk036/bairstow`)
    - Auto-correlation function
    - Parallel Bairstow's method
    - Aberth's method
    - Leja ordering ???

---

## Multiplier-less FIR Filter Design

- low-cost 💰, low-power 🔋
- Convexity is the key!!! ✨🚀
- Discrete version of 🫒 Ellipsoid method (`luk036/ellalgo`)
- Canonical Signed Digit (CSD) (`luk036/csd-py`)
- input: + number of non-zeros (nnz)
- output: filter coefficients in CSD form
  - Common sub-expression extraction/elimination 🔲
  - a Verilog file

---

## Possible contributions 🤏

- Write more test cases
- Write documentation
- Verilog implementation
- C++ Porting
- Code Clean-up

---

class: nord-dark, center, middle

# 🙋 Q & A
