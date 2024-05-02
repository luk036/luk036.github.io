class: middle, center

# Basic Python Programming

Wai-Shing Luk

2017-06-23

---

## Why Python?

- Python is easier to learn than C++.

- Python is open source, a lot of libraries and tools.

- Great for statistical analysis, machine learning 🤖.

---

## ✨ Features

- Interpreted Language

- Modulized.

- Object-oriented

- Self-test

---

## Modulize

```python
from fractions import *
import numpy as np

def x_ratio(A, B, l, m):
    dAl = np.dot(A, l)
    dAm = np.dot(A, m)
    dBl = np.dot(B, l)
    dBm = np.dot(B, m)
    if isinstance(dAl, int):
        return Fraction(dAl, dAm) / Fraction(dBl, dBm)
    else:
        return dAl * dBm / (dAm * dBl)
```

---

## Object-oriented

```python
class pg_point(np.ndarray):
    def __new__(cls, inputarr):
        obj = np.asarray(inputarr).view(cls)
        return obj

    def __eq__(self, other):
        if type(other) is type(self):
            return (np.cross(self, other) == 0).all()
        return False

    def incident(self, l):
        return not self.dot(l)

    def __mul__(self, other):
        ''' meet '''
        l = np.cross(self, other)
        return pg_line(l)
```

---

## Self-test

```python
if __name__ == "__main__":
    p = pg_point([1-2j, 3-1j, 2+1j])
    q = pg_point([-2+1j, 1-3j, -1-1j])
    assert p.incident(p*q)
```
