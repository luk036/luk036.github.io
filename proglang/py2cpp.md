title: Python vs. Modern C++
class: animation-fade
layout: true

<!-- This slide will serve as the base layout for all your slides -->
.bottom-bar[
  {{title}}
]

---

class: impact

{{title}}
=========

Wai-Shing Luk
-------------

---

Agenda
======

1.  Introduction
2.  Auto
3.  Range-Based For Loop
4.  Uniform Initialization
5.  Tuples
6.  Structure Binding
7.  If constexpr
8.  Yield and coroutine
9.  Modules
10. Library: fmt

---

Introduction
============

-   Modern C++ has become more Pythonic today.
-   Python is a simple programming language, yet C++ is more powerful.

---

Auto
====

Python has always been a dynamically typed language. You don't need to
declare variable types anywhere. Whereas, C++11 uses `auto` keyword for automatic
type deduction.

.col-4[

In Python:

```python
def tri(T):
    a1, a2, a3 = T
    l1 = a2 * a3
    l2 = a1 * a3
    l3 = a1 * a2
    return l1, l2, l3
```

]

.col-8[

In C++11:

```cpp
constexpr auto tri(const std::tuple<P,P,P> &T) {
  auto [a1, a2, a3] = T;
  auto l1 = a2 * a3;
  auto l2 = a1 * a3;
  auto l3 = a1 * a2;
  return std::tuple{l1, l2, l3};
}
```

]

---

Range-Based For Loops
=====================

In Python, a `for` loop always iterates over a Python object. Meanwhile,
C++ starts to support range-based for loops in C++11.

.col-6[

In Python:

``` {.python}
def coI(l, seq):
    for p in seq:
        if not l.incident(p):
            return False
    return True
```

]

.col-6[

In C++17:

``` {.cpp}
bool coI(L &l, Sequence &seq) {
  for (const P &p : seq) {
    if (!l.incident(p))
      return false;
  }
  return true;
}
```

]

---

Uniform Initialization
======================

In Python, you can also create a dictionary with a single expression:

``` {.python}
myDict = {5: "foo", 6: "bar"}
print(myDict[5])
```

Similarly, uniform initialization also works on C++'s `std::map` and
`unordered_map`:

``` {.cpp}
std::unordered_map myDict{ { 5, "foo" }, { 6, "bar" } };
std::cout << myDict[5];
```

---

Tuple
=====

Python has had tuples pretty much since the beginning. C++ added tuples
to the standard library in C++11.

.col-4[

Python:

``` {.python}
triple = (5, 6, 7)
print triple[0]
x, y, z = triple
```

]

.col-8[

C++17:

``` {.cpp}
std::tuple triple{5, 6, 7};
std::cout << std::get<0>(triple);
std::tie(x, y, z) = triple;
auto [x, y, z] = triple;
```

]

---

Structure Binding
=================

C++17 further added a language support to structure binding.

.small[

.col-6[

Python:

``` {.python}
class ell:
  def calc_cc(self):
    '''central cut'''
    n = len(self.xc)
    rho = 1.0/(n+1)
    sigma = 2.0*rho
    delta = self.c1
    return 0, rho, sigma, delta
  # ...
```

]

.col-6[

C++17:

``` {.cpp}
class ell {
public:
  auto calc_cc() {
    /* central cut */
    auto n = this->_xc.size();
    auto rho = 1.0 / (n + 1);
    auto sigma = 2.0 * rho;
    auto delta = this->_c1;
    return std::tuple{0, rho, sigma, delta};
  }
  // ...
};
```

]

]

---

If constexpr
============

C++17 add `if constexpr` statement to simplify the partial templates

.small[

.col-6[

Python:

``` {.python}

def ratio_ratio(a, b, c, d):
  if isinstance(a, (int, np.int64)):
    return Fraction(a,b) / Fraction(c,d)
  else:
    return (a * d) / (b * c)
```

]

.col-6[

C++17:

``` {.cpp}
template <typename K>
auto ratio_ratio(K &a, K &b, K &c, K &d) {
  if constexpr (std::is_integral_v<K>) {
    return Fraction(a,b) / Fraction(c,d);
  } else {
    return (a * d) / (b * c);
  }
}
```

]

]

---

Virtual Function
----------------

.small[

.col-6[

Python:

``` {.python}
from abc import ABCMeta, abstractmethod

class ck():
  __meta_class = ABCMeta
  @abstractmethod
  def perp(self, v):
    """abstract method"""

  def altitude(self, p, l):
    return p * self.perp(l)

class hyck(ck):
  def perp(self, v):
    [x, y, z] = v
    return v.dual()([x, y, -z])
```

]

.col-6[

C++17:

``` {.cpp}
class ck {
public:
  virtual L perp(const _P &) const = 0;
  virtual P perp(const _L &) const = 0;

  auto altitude(P p, L l) const {
     return p * perp(l); }
};

class hyck : public ck {
public:
  L perp(const P &v) const final {
    return L(v[0], v[1], -v[2]); }
  P perp(const L &v) const final { 
    return P(v[0], v[1], -v[2]); }
};
```

]

]


---

Yield and Coroutine
===================

In Python, you can write coroutine code using `yield` statement:

.small[

``` {.python}
def set_partition(n, k):
    if k%2 == 0:
        for x, y in GEN0_even( n, k ):
            yield x, y
    else:
        for x, y in GEN0_odd( n, k):
            yield x, y

if __name__ == "__main__":
    n, k = 5, 3
    b = [0 for i in range(n-k+1)] + list(range(k))
    for x, y in set_partition(n,k):
        old = b[x]
        b[x] = y
        print(b[1:], ": Move {} from block {} to {}".format(x, old, y))
    print("Done.")
```

]

---

Yield and Coroutine (cont'd)
============================

-   Currently, C++17 does not support `yield` statement (not until
    C++20).
-   The closest feature is `Boost.Coroutine2`.

---

Modules (not yet in C++17)
--------------------------

``` {.cpp}
import std.vector; // like #include <vector>
import std.string; // like #include <string>
import std.iostream; // like #include <iostream>
import std.iterator; // like #include <iterator>

int main() {
    using namespace std;
    vector<string> v = {
        "Socrates","Plato","Descartes","Kant","Bacon"
    };
    copy(begin(v),end(v),ostream_iterator<string>(cout,"\n"));
}
```

---

fmt (not yet in C++17 standard)
---------------------------------------

Python:

``` {.python}
yb1, fb, iter, flag, status =
    cutting_plane_dc(P, E, 0.0, 200, 1e-4)
print('{:f} {} {} {}'.format(fb, iter, flag, status))
```

C++17:

``` {.cpp}
#include <fmt/format.h>
// ...
std::tie(yb1, fb, iter, flag, status) =
    cutting_plane_dc(P, E, 0.0, 200, 1e-4);
fmt::print("{:f} {} {} {}\n", fb, iter, flag, status);
```

---

fmt installation
------------------------

``` {.terminal}
> git clone https://github.com/fmtlib/fmt.git
> cd fmt/
> sudo cp -r fmt /usr/include
> cmake .
> make
> sudo cp fmt/libfmt.a /usr/lib
> cd bin
> ./assert-test
> ./header-only-test
> ./util-test
```
