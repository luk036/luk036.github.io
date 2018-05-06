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

Conda Installation
------------------

Use Conda to install Python and Python-related C++'s libraries:

.small[

```bash
wget "http://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh" \
 -O miniconda.sh
export CONDA=$USB/miniconda
bash miniconda.sh -b -p $CONDA
export PATH="$CONDA/bin:$PATH" # overwrite the system python
```

]

---

Conda-Python Installation
-------------------------

```bash
# For python 2.7
python --version # make sure which python is using
conda install pip
python -m pip install \
  numpy scipy matplotlib \
  pytest pytest-cov pytest-benchmark \
  pylint autopep8
python -m pip install -U rope --user
conda install cvxpy -c cvxgrp

# For python 3.6
conda create -n py36 python=3.6 anaconda
source activate py36
# install the modules as above
```

---

Python-related C++ Libraries Installation
-----------------------------------------

```bash
conda install xtensor -c conda-forge
conda install xtensor-blas -c conda-forge
conda install openblas -c conda-forge
conda install lapack -c conda-forge
export LD_LIBRARY_PATH=$CONDA/lib
```

---

CMake Configuration
-------------------

.small[

```cmake
cmake_minimum_required (VERSION 3.3)
# ...
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
find_package (Threads REQUIRED)
find_package (xtensor REQUIRED)
set(LIBS ${LIBS} "-L${xtensor_INCLUDE_DIRS}/../lib") # any better way?
include_directories (${LIBRARY_INCLUDE_PATH} ${xtensor_INCLUDE_DIRS})
target_link_libraries (${APP_NAME} Threads::Threads ${LIBS} -llapack -lblas)
```
]

---

Auto
----

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
# ...
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
---------------------

In Python, a `for` loop always iterates over a Python object. Meanwhile,
C++ starts to support range-based for loops in C++11.

.col-6[

In Python:

```python
def coI(l, seq):
    for p in seq:
        if not l.incident(p):
            return False
    return True
```

]

.col-6[

In C++17:

```cpp
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
----------------------

In Python, you can also create a dictionary with a single expression:

```python
myDict = {5: "foo", 6: "bar"}
print(myDict[5])
```

Similarly, uniform initialization also works on C++'s `std::map` and
`unordered_map`:

```cpp
std::unordered_map myDict{ { 5, "foo" }, { 6, "bar" } };
std::cout << myDict[5];
```

---

Tuple
-----

Python has had tuples pretty much since the beginning. C++ added tuples
to the standard library in C++11.

.col-4[

Python:

```python
triple = (5, 6, 7)
print triple[0]
x, y, z = triple
```

]

.col-8[

C++17:

```cpp
std::tuple triple{5, 6, 7};
std::cout << std::get<0>(triple);
std::tie(x, y, z) = triple;
auto [x, y, z] = triple;
```

]

---

Structure Binding
-----------------

C++17 further added a language support to structure binding.

.small[

.col-6[

Python:

```python
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

```cpp
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
------------

C++17 add `if constexpr` statement to simplify the partial templates

.small[

.col-6[

Python:

```python

def ratio_ratio(a, b, c, d):
  if isinstance(a, (int, np.int64)):
    return Fraction(a,b) / Fraction(c,d)
  else:
    return (a * d) / (b * c)
```

]

.col-6[

C++17:

```cpp
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

```python
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

```cpp
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
-------------------

In Python, you can write coroutine code using `yield` statement:

.small[

```python
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
----------------------------

-   Currently, C++17 does not support `yield` statement (not until
    C++20).
-   The closest feature is `Boost.Coroutine2`.

---

Modules (not yet in C++17)
--------------------------

```cpp
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

Xtensor
-------

.small[

Python 3 - numpy  | C++ 14 - xtensor
------------------|-----------------
`np.linspace(1.0, 8.0, 50)`  | `xt::linspace<double>(1.0, 8.0, 50)`
`np.logspace(2.0, 3.0, 4)`  | `xt::logspace<double>(2.0, 3.0, 4)`
`np.arange(3, 7)`  | `xt::arange(3, 7)`
`np.eye(4)`  | `xt::eye(4)`
`np.zeros([3, 4])`  | `xt::zeros<double>({3, 4})`
`np.ones([3, 4])`  | `xt::ones<double>({3, 4})`
`np.dot(a, b)`  | `xt::linalg::dot(a, b)`
`np.vdot(a, b)`  | `xt::linalg::vdot(a, b)`
`np.outer(a, b)`  | `xt::linalg::outer(a, b)`
`np.matrix_power(a, 12)`  | `xt::linalg::matrix_power(a, 12)`
`np.kron(a, b)`  | `xt::linalg::kron(a, b)`

]

---

Xtensor (cont'd)
----------------

.small[

.col-4[

Python:

```python
import numpy as np
# ...

A = linalg.sqrtm(Sig)
Ys = np.zeros((n,N))
ym = np.random.randn(n)
for k in range(N):
  x = var*np.random.randn(n)
  v = np.random.randn(n)
  y = A.dot(x) + ym + tau*v
  Ys[:,k] = y
```

]

.col-8[

C++17:

```cpp
#include <xtensor-blas/xlinalg.hpp>
#include <xtensor/xarray.hpp>
// ...
auto A = xt::linalg::cholesky(Sig);
auto Ys = xt::zeros<double>({n, N});
auto ym = xt::random::randn<double>({n});
for (auto k = 0u; k < N; ++k) {
  auto x = var*xt::random::randn<double>({n});
  auto v = xt::random::randn<double>({n});
  auto y = dot(A,x) + ym + tau*v;
  xt::view(Ys, xt::all(), k) = y;
}
```
]
]

---

Xtensor (cont'd)
----------------

.small[

.col-6[

Python:

```python

# ...


Pg = self.P.dot(g)
tsq = g.dot(Pg)
tau = np.sqrt(tsq)
alpha = beta / tau
status, rho, sigma, delta = \
  calc_ell(alpha)
# ...
self._xc -= (rho / tau) * Pg
self.P -= (sigma / tsq) * np.outer(Pg, Pg)
self.P *= delta
```

]

.col-6[

C++17:

```cpp
using xt::linalg::dot;
using xt::linalg::outer;
// ...
xt::xarray<double> Pg = dot(_P, g);
auto tsq = dot(g, Pg)();
auto tau = std::sqrt(tsq);
auto alpha = beta / tau;
auto [status, rho, sigma, delta] = 
  calc_ell(alpha);
// ...
_xc -= (rho / tau) * Pg;
_P -= (sigma / tsq) * outer(Pg, Pg);
_P *= delta;
```
]
]

---

fmt (not yet in C++17 standard)
-------------------------------

Python:

```python
yb1, fb, iter, flag, status =
    cutting_plane_dc(P, E, 0.0, 200, 1e-4)
print('{:f} {} {} {}'.format(fb, iter, flag, status))
```

C++17:

```cpp
#include <fmt/format.h>
// ...
std::tie(yb1, fb, iter, flag, status) =
    cutting_plane_dc(P, E, 0.0, 200, 1e-4);
fmt::print("{:f} {} {} {}\n", fb, iter, flag, status);
```

---

fmt installation
----------------

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
