
# Gemini-CLI/iflow is a Double-edged Sword

---

### Double-edged sword

- Increase 100% of productivity
- or, destroy your project 100% faster

---

### Safety Nets

- Version control (GitHub)
  git revert bcad2e
- Unit testing

---

### Do: fix errors or warnings

- E.g. fix warnings/errors produced by:
  - cmake --build build --config Release
  - xmake test
  - ruff check
  - tox -e docs
  - cargo clippy
  - mypy src
  - mypy --disallow-untyped-defs tests/

---

### Do: improve the quality of software

For example:

- Add unit/stress tests in test/source/, and then use "xmake test" to verify.
- Add documentation tests to the comments in src/, and then use "cargo test --doc" to verify.
- Add type annotations in src/, and then use "mypy src" to verify.
- Add const-qualifier whenever appropriate, and then use "cmake --build build --config Debug" to verify.
- Add constexpr whenever appropriate, and then use "cmake --build build --config Debug" to verify.
- Add "this->" to the member variables and member functions whenever appropriate, and then use "cmake --build build" to verify.

---

### Don't:

- Work on a unstable environment
  - Network error
  - Not enough disk space
- Implement a novel idea
