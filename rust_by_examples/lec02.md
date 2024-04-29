layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Lecture 2: Basic Data Types, Function, and Class

---

## Define function in Python

```python
# file: low_discr_seq.py

def vdc(k, base = 2):
    vdc = 0.
    denom = 1.
    while k != 0:
        denom *= base
        rem = k % base
        k //= base  # integer div
        vdc += rem / denom
    return vdc


if __name__ == '__main__':
    for k in range(1, 11):
        print("{}", vdc(k, 2))
```

---

## C++ equivalence

```cpp
auto vdc(unsigned k, unsigned base=2) -> {
    auto vdc = 0.0, denom = 1.0;
    while (k != 0) {
        denom *= base;
        const auto rem = k % base;
        k /= base;
        vdc += rem / denom;
    }
    return vdc;
}

int main() {
    for (auto k=1U; k != 11U; ++k)
       fmt::print("{}\n", vdc(k, 2));
}
```

---

## Rust 🦀 equivalence

```rust
fn vdc(mut k: u32, base: u32) -> f64 {
    let mut vdc = 0.0;
    let mut denom = 1.0;
    while k != 0 {
        denom *= base as f64;
        let rem = k % base;
        k /= base;
        vdc += (rem as f64) / denom;
    }
    vdc  // <- note!
}

fn main() {
    for k in 1..11 {
        println!("{}", vdc(k, 2));
    }
}
```

---

## Type checking in Python with MyPy

```python
# Check with mypy:
#  $ pip install mypy
#  $ mypy low_discr_seq.py

def vdc(k: int, base: int = 2) -> float:
    vdc = 0.
    denom = 1.
    while k != 0:
        denom *= base
        rem = k % base
        k /= base  # Oop!!! error!!!
        vdc += rem / denom
    return vdc

```

---

## Vdcorput (Python 🐍)

```python
class Vdcorput:
    def __init__(self, base: int = 2):
        """Constructor"""
        self._base: int = base
        self._count: int = 0

    def __call__(self) -> float:
        """make object callable"""
        self._count += 1
        return vdc(self._count, self._base)


if __name__ == '__main__':
    vdc = Vdcorput(3)
    for _ in range(10):
        print(vdc())
```

---

## Vdcorput (C++)

```cpp
class Vdcorput {
  private:
    unsigned _base, _count;

  public:
    explicit Vdcorput(unsigned base = 2)
        : _base{base} , _count{0} { }

    auto operator()() -> double {
        return vdc(++this->_count, this->_base); }
};
int main() {
    auto vdc = Vdcorput(3);
    for (auto i=0U; i != 10; ++i)
        fmt::print("{}\n", vdc());
}
```

---

## Circle (Python 🐍)

```python
from math import pi, sin, cos, sqrt
from typing import List

twoPI = 2 * pi

class Circle:
    def __init__(self, base: int = 2):
        self._vdc = Vdcorput(base)

    def __call__(self) -> List[float]:
        theta = twoPI * self._vdc()
        return [sin(theta), cos(theta)]
```

Return a list

---

## Circle (C++)

```cpp
using namespace std;
static const auto twoPI = 2 * acos(-1.);

class Circle {
    ...

    // Compilers will optimize the return
    // value so that no copying is needed
    auto operator()() -> vector<double> {
	    const auto theta = this->_vdc() * twoPI;
        return {sin(theta), cos(theta)};
    }
};
```

---

## Halton (Python 🐍)

```python
from typing import List

class Halton:
    """Generate Halton sequence"""

    def __init__(self, base: List[int]):
        self._vdc0 = Vdcorput(base[0])
        self._vdc1 = Vdcorput(base[1])

    def __call__(self) -> List[float]:
        return [self._vdc0(), self._vdc1()]

    def reseed(self, seed: int):
        self._vdc0.reseed(seed)
        self._vdc1.reseed(seed)
```

---

## Halton (C++)

```cpp
class Halton {
  private:
    Vdcorput _vdc0, _vdc1;

  public:
    explicit Halton(const unsigned* base)
        : _vdc0(base[0]), _vdc1(base[1]) { }

    auto operator()() -> vector<double> {
        return {this->_vdc0(), this->_vdc1()}; }

    auto reseed(unsigned seed) {
        this->_vdc0.reseed(seed);
        this->_vdc1.reseed(seed);
    } // why not const?
};
```

---

## Sphere (Python 🐍)

```python
class Sphere:
    def __init__(self, base: List[int]):
        self._vdc = Vdcorput(base[0])
        self._cirgen = Circle(base[1])

    def __call__(self) -> List[float]:
        cphi = 2 * self._vdc() - 1
        sphi = sqrt(1 - cphi * cphi)
        C = self._cirgen()
        return [sphi * C[0], sphi * C[1], cphi]

    def reseed(self, seed: int):
        self._cirgen.reseed(seed)
        self._vdc.reseed(seed)
```

---

## Sphere (C++)

```cpp
class Sphere {
  private:
    Vdcorput _vdc;
    Circle _cirgen;

  public:
    explicit Sphere(const unsigned* base)
        : _vdc(base[0]), _cirgen(base[1]) {}

    auto operator()() -> vector<double> {
        const auto cphi = 2 * this->_vdc() - 1;
        const auto sphi = sqrt(1 - cphi*cphi);
        const auto C = this->_cirgen();
        return {sphi * C[0], sphi * C[1], cphi};
    }
};
```

---

## Find roots (Python 🐍)

```python
from math import sqrt
from typing import Optional, Tuple

def find_roots(a: float, b: float, c: float) -> Optional[Tuple[float, float]]:
    assert a != 0.
    b /= a
    c /= a
    hb = b / 2.
    d = hb * hb - c
    if d < 0.: return None
    x1 = -hb + (sqrt(d) if hb < 0. else -sqrt(d))
    x2 = c / x1
    return x1, x2
```

---

## Find roots (C++)

```cpp
#include <optional>
...
template <typename T>
auto find_roots(const T& a, T b, T c) -> optional<pair<T, T>> {
    assert(a != 0.);
    b /= a;
    c /= a;
    auto hb = b / 2.;
    auto d = hb * hb - c;
    if (d < 0.) return {}; // C++17
    auto x1 = -hb + (hb < 0. ? sqrt(d) : -sqrt(d));
    auto x2 = c / x1;
    return { { x1, x2 } };
}
```

---

## Conclusion

- Python changes the way I write C++.
- Type-checking is your friend.
- Const is useful. But don't over-constraint the callers.
- Prefer composition rather than inheritance.

---

## Source code

Python:

$ wget https://github.com/luk036/pylds/blob/master/src/pylds/low_discr_seq.py

C++:

$ wget https://github.com/luk036/low_discr_seq/blob/master/lib/include/lds/low_discr_seq.hpp

---

class: nord-dark, center, middle

# 🙋 Q & A
