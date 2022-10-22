# integer/fraction arithmetic

@luk036

---

## Why?

- Consumes less energy

- Avoid rounding errors (a problem in many graphics applications)

- Hardware without sufficient resources, e.g. FPGAs

- However, many algorithms still work only on real numbers (e.g. ellipsoid methods)
  - Orthogonality (inner product)

---

## How?

- Floating point arithmetic -> integer/fraction arithmetic
  (gmp, mpq, luk036/fraction ( header only )

- Canonical signed numbers
  (luk036/pycsd, luk036/csd-cpp)

- Euclidean geometry -> projective geometry ( non-oriented )
  (luk036/projgeom-cpp)

- Euclidean distance -> Manhattan distance
  (luk036/physdes-cpp)

---

## How?

- Conventional Calculus -> Discrete Calculus

- Network flow optimization
  (luk036/netoptim, luk036/netoptim-cpp)

- Cholesky factorization -> LDLT factorization (avoid square roots, division????)

- Low discrepancy sequence (Halton)
