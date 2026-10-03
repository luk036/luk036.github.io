# Undefined Behavior (UB)

- UB is a necessary evil
  - makes compiler optimization possible
    (compare with "don't care" in logic minimization)
- Signed integer overflow is UB
- Unsigned integer overflow is well-defined
  - Wraps around to zero
- Arithmetic: use signed integers
- Array indexing: use unsigned integers
- Validation tool
