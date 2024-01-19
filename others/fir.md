# FIR filter with canonical signed digit multiplier

- Low-power low-cost
- Fine-grain digital design (ASIC/FPGA)
- Tailor-made design
- Input: specification of filter performance requirement
- Output: verilog file

---

- Continuous filter coefficients:
- via convex optimization + 1 spectral factorization

---

- Discrete filter coefficients (canonical signed digit)
- mostly via MILP

Convexity is the key!!!

Ellipsoid method + N spectral factorizations:
- parallel cut (tight constraints)
- one square-root per iteration

Spectral factorization:
- polynomial root finding
- Aberth/Bairstow's: concurrent
- Leja ordering

Common Sub-expression elimination/sharing
- ILP
- code optimization
- common substrings
   https://www.geeksforgeeks.org/longest-repeating-and-non-overlapping-substring
