layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Lecture 5: : Lambda function and algorithms

---

## min()/max() in python

```python
from .recti import point
# find the bottom-most and top-most points
lst = [(-2, 2), (0, -1), (-5, 1), (-2, 4),
       (0, -4), (-4, 3), (-6, -2), (5, 1)]
lst = [point(x, y) for x, y in lst]
botmost = min(lst, key=lambda a: (a.y, a.x))
topmost = max(lst, key=lambda a: (a.y, a.x))
```

---

## min()/max() in C++

```cpp
#include <algorithm>
#include <vector>
#include "recti.hpp"

// find the bottom-most and top-most points
auto lst = std::vector<point<int>> 
   { {-2, 2}, {0, -1}, {-5, 1}, {-2, 4},
    {0, -4}, {-4, 3}, {-6, -2}, {5, 1} };
auto up = [](const auto& a, const auto& b) {
    return std::tie(a.y(), a.x()) < std::tie(b.y(), b.x());
};
auto first = lst.begin();
auto last = lst.end();
auto botmost = *std::min_element(first, last, up);
auto topmost = *std::max_element(first, last, up);
```

---

## partition() in python:

```python
from itertools import filterfalse, tee

def partition(pred, iterable):
    # partition(is_odd, range(10)) -->  1 9 3 5 7 and 0 2 8 4 6 
    t1, t2 = tee(iterable)
    return filter(pred, t1), filterfalse(pred, t2)

[lst1, lst2] = partition(lambda a: a.x < botmost.x, lst)
```

---

## partition() in C++

```cpp
#include <vector>
auto first = lst.begin();
auto last = lst.end();
auto right = [&](const auto& a) { return a.x() < botmost.x()); };
auto middle = std::partition(first, last, right)
```

---

## Sorting in Python

```python
lst1 = sorted(lst1, key=lambda a: (a.y, a.x))
lst2 = sorted(lst2, key=lambda a: (a.y, a.x), reverse=True)
```

---

## Sorting in C++

```cpp
auto up = [](const auto& a, const auto& b) {
    return std::tie(a.y(), a.x()) < std::tie(b.y(), b.x());
};
auto down = [](const auto& a, const auto& b) {
    return std::tie(a.y(), a.x()) > std::tie(b.y(), b.x());
};
std::sort(first, middle, up);
std::sort(middle, last, down);
```

---

## Python

```python
def create_ymono_polygon(lst):
    topmost = max(lst, key=lambda a: (a.y, a.x))
    botmost = min(lst, key=lambda a: (a.y, a.x))
    d = topmost - botmost
    [lst1, lst2] = partition(lambda a: d.cross(a - botmost) <= 0, lst)
    lst1 = sorted(lst1, key=lambda a: (a.y, a.x))
    lst2 = sorted(lst2, key=lambda a: (a.y, a.x), reverse=True)
    return lst1 + lst2
```

---

## C++14

```cpp
template <typename FwIter>
inline void create_ymono_polygon(FwIter&& first, FwIter&& last) {
    auto up = [](const auto& a, const auto& b) {
        return std::tie(a.y(), a.x()) < std::tie(b.y(), b.x()); };
    auto down = [](const auto& a, const auto& b) {
        return std::tie(a.y(), a.x()) > std::tie(b.y(), b.x()); };
    auto topmost = *std::max_element(first, last, up);
    auto botmost = *std::min_element(first, last, up);
    auto d = topmost - botmost;
    auto r2l = [&](const auto& a) { return d.cross(a - botmost) <= 0; };
    auto middle = std::partition(first, last, std::move(r2l));
    std::sort(first, middle, std::move(up));
    std::sort(middle, last, std::move(down));
}
```

---

![img](ymono_polygon.svg)

---

## Unit Testing (Python)

```python
*from pytest import approx
...
def test_euclid():
    a1 = pg_point([3., -5., 2.])
    a2 = pg_point([6., 2., 2.])
    a3 = pg_point([5., -4., 3.])
    triangle = [a1, a2, a3]
    trilateral = tri_dual(triangle)
    l1, l2, l3 = trilateral
    t1, t2, t3 = tri_altitude(triangle)
*   assert spread(t1, l1) == approx(1, abs=0.01)
```

---

## Unit Testing (C++)

```cpp
*#include <doctest.h>
...
TEST_CASE("Euclid plane (floating point)") {
    auto a1 = pg_point {1., 3., 1.};
    auto a2 = pg_point {4., 2., 1.};
    auto a3 = pg_point {4., -3., 1.};
    auto triangle = std::tuple {a1, a2, a3};
    auto trilateral = tri_dual(triangle);
    const auto& [l1, l2, l3] = trilateral;
    auto [t1, t2, t3] = tri_altitude(triangle);
*   CHECK(spread(t1, l1) == doctest::Approx(1).epsilon(0.01));
}
```

---

## Environment Setup 🔧

- Lubuntu 20.04 LTS:
    - pip install pytest pytest-cov
    - sudo apt install libboost-dev libfmt-dev
    - sudo apt install cmake ninja git gh
- Android termux:
    - pip install pytest pytest-cov
    - pkg install boost fmt
    - pkg install cmake ninja git gh

---

## Setup (Python) 🔧

```bash
$ gh repo clone luk036/physdespy
$ cd physdespy
$ pip install -r requirements.txt
$ python setup.py develop
$ python setup.py test
```

---

## Setup (C++) 🔧

```bash
$ gh repo clone luk036/physdes
$ cd physdes/external
$ git submodule update --init # for doctest
$ cd ..
$ mkdir build; cd build
$ cmake .. -DCMAKE_BUILD_TYPE=Release
$ cmake --build .
$ ctest
```

---

class: nord-dark, center, middle

# Q & A 🗣️
