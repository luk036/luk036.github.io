layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Lecture 5: : Lambda function and algorithms

---

## Python:

```python
from itertools import filterfalse, tee

def partition(pred, iterable):
    # partition(is_odd, range(10)) --> 0 2 4 6 8  and  1 3 5 7 9
    t1, t2 = tee(iterable)
    return filterfalse(pred, t1), filter(pred, t2)

class rpolygon(list):
    def __new__(cls, *args, **kwargs):
        return list.__new__(cls, *args, **kwargs)

def create_xmono_rpolygon(lst): ...

def create_ymono_rpolygon(lst): ...

```

---

## C++

```cpp
#include "recti.hpp"
#include <vector>
using std::vector;

template <typename T>
class rpolygon : public vector<point<T>> {
  private: // not directly construct
    explicit rpolygon(vector<point<T>> pointset) noexcept
        : vector<point<T>> {std::move(pointset)} { }
  public:
    static auto create_xmono(vector<point<T>>&& pointset)
        -> rpolygon<T>;

    static auto create_ymono(vector<point<T>>&& pointset)
        -> rpolygon<T>;
};
```

---

## Python

```python
def create_ymono_rpolygon(lst):
*   min_pt = min(lst, key=lambda a: (a.y, a.x))
*   max_pt = max(lst, key=lambda a: (a.y, a.x))
    d = max_pt - min_pt

    def r2l(a): return d.x*(a.y - min_pt.y) < (a.x - min_pt.x)*d.y

    def l2r(a): return d.x*(a.y - min_pt.y) > (a.x - min_pt.x)*d.y

*   [lst1, lst2] = partition(l2r, lst) if d.x < 0 else \
        partition(r2l, lst)
    lst1 = sorted(lst1, key=lambda a: (a.y, a.x))
    lst2 = sorted(lst2, key=lambda a: (a.y, a.x), reverse=True)
    return rpolygon(lst1 + lst2)
```

---

## C++14

```cpp
template <typename T, typename FwIter>
void rpolygon<T>::create_ymono(FwIter&& first, FwIter&& last) {
*   auto upward = [](const auto& a, const auto& b) {
        return tie(a.y(), a.x()) < tie(b.y(), b.x()); };
*   auto [min, max] = minmax_element(first, last, upward);
    auto min_pt = *min; auto d = *max - min_pt;
    auto l2r = [&](auto a) { return d.x()*(a.y() - min_pt.y())
                            > (a.x() - min_pt.x())*d.y(); };
    auto r2l = [&](auto a) { return d.x()*(a.y() - min_pt.y())
                            < (a.x() - min_pt.x())*d.y(); };
    auto middle = d.x() < 0 ? partition(first, last, move(l2r))
                            : partition(first, last, move(r2l));
    auto downward = [](const auto& a, const auto& b) {
        return tie(a.y(), a.x()) > tie(b.y(), b.x()); };
    sort(first, middle, upward); sort(middle, last, downward);
}
```

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
