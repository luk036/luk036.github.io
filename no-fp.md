# Integer/Fraction Arithemetic

## @luk036

---

## Why?

- Consume less engery

- Avoid rounding errors (problems in many graphic applications)

- Hardware that does not have enough resource, such as FPGA

- However, many algorithms still work only on real numbers (such as the ellipsoid method)
  - Orthogonality (inner product)

---

## How?

- Floating point arithemetic -> integer/fraction arithemetic
  (gmp, mpq, luk036/fractions (header only)

- Canonical signed digit
  (luk036/pycsd, luk036/csd-cpp)

- Euclidean geometry -> projective geometry (non-oriented)
  (luk036/projgeom-cpp)

- Euclidean distance -> Manhattan distance
  (luk036/physdes-cpp)

---

## How?

- Conventional Calculus -> Discrete Calculus

- Network flow optimization
  (luk036/netoptim, luk036/netoptim-cpp)

- Cholesky factorization -> LDLT factorization (avoid square-root, division???)

- Low discrepency sequence (Halton)
