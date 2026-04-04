Rust's Mission: Replace C, Not C++ 🎯

EDA

Logic synthesis

- Discrete Mathematics
  group theory

- Boolean "Algebra"?

Traditional "And-Or" Logic:

f(x, y, z) = (¬x ∧ y ∧ z) ∨ (x ∧ y ∧ ¬z) ∨ (x ∧ ¬y ∧ z)

Polynomial Representation (over GF(2)):

f(x, y, z) = 1 + x + z + x _y + y_ z + (1 + x) _y_ (1 + z)
where
\*: AND
+: XOR

Clock skew scheduling

- skew(i, j) = ti - tj
- Network parametric algorithms
