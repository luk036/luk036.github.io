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

.col-6[
-  Introduction
-  Conda installation
-  Auto
-  Template Guided Deduction
-  Range-Based For Loop
-  Uniform Initialization
-  Tuples
-  Structure Binding
-  If constexpr
]

.col-6[

-  Yield and coroutine
-  Spaceship operator
-  Modules
-  Library: xtensor
-  Library: fmt

]

---

Introduction
============

-   Python is a simple programming language, yet C++ is more powerful.
-   Python could be 10X slower than C++.
-   C++ is a strong type-checking language. 
-   Modern C++ has become more Pythonic today.
-   Strategy: Python first, C++ follow.

---

Conda Installation
------------------

Use Conda to install Python and Python-related C++'s libraries:

.small[

```bash
wget "http://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh" \
 -O miniconda.sh
export CONDA=$USB/miniconda2
bash miniconda.sh -b -p $CONDA
export PATH="$CONDA/bin:$PATH" # overwrite the system python
export LD_LIBRARY_PATH="$CONDA/lib:$CONDA/envs/py36/lib"
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
  pylint autopep8 cython
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

# For python 2.7
export LD_LIBRARY_PATH=$CONDA/lib

# For python 3.6
export LD_LIBRARY_PATH=$CONDA/envs/py36/lib

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

.small[
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
auto tri(const std::tuple<P,P,P> &T) {
  auto [a1, a2, a3] = T;
  auto l1 = a2 * a3;
  auto l2 = a1 * a3;
  auto l3 = a1 * a2;
  return std::tuple{l1, l2, l3};
}
```

]
]
---

Template Guided Deduction
-------------------------

.small[
.col-6[

In Python:

```python
class interval:
    def __init(self, lower, upper):
        self.lower = lower
        self.upper = upper
    # ...

if __name__ == "__main__":
    a = interval(0, 10)
    b = interval(1.0, 6.0)
```

]

.col-6[

In C++17:

```cpp
template <typename T>
struct interval {
  T _lower;
  T _upper;
  // ...
};

*template <typename T>
*interval(T, T)-> interval<T>;

int main() {
  auto a = interval{0, 10}; // int
  auto b = interval{1.0, 6.0}; // double
}
```

]
]

---

Type
------

In Python, a type can also be a value of a variable:

.small[
```python
nodeFactory = dict
# ...
factory = nodeFactory()
factory[5] = "foo"
print(factory[5])
```
]

In C++, we may use `using` to simulate this:

.small[
```cpp
using nodeFactory = std::unordered_map<int, const char*>;
// ...
auto factory = nodeFactory();
factory[5] = "foo";
std::cout << factory[5];
```
]

---

`std::any`
----------

In Python, a variable can store a value of any types:

```python
M = {1 : "hello", 8 : 5.6, 9 : 4}
assert len(M) == 3
assert M[8] == 5.6
```

In C++17, we may use `std::any` to simulate this:

```cpp
#include <any>
// ...
auto M = std::unordered_map<int, std::any>{
  {1, "hello"}, {8, 5.6}, {9, 4}};
assert(M.size() == 3);    
assert(std::any_cast<double>(M[8]) == 5.6);
```

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

# ...
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
std::unordered_map<int, const char*> myDict{ 
  { 5, "foo" }, { 6, "bar" } };
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
    return rho, sigma, delta


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
    return std::tuple{rho, sigma, delta};
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

# ...
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

Abstract Method
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

C++17 (dynamic/virtual method):

```cpp

struct ck {
  virtual L _perp(const _P &) const = 0;
  virtual P _perp(const _L &) const = 0;

  L altitude(const P &p, const L &l) const 
  { return p * _perp(l); }
};

struct hyck : ck {
  L _perp(const P &v) const final
  { return L(v[0], v[1], -v[2]); }

  P _perp(const L &v) const final
  { return P(v[0], v[1], -v[2]); }
};
```
]
]

---

Abstract Method
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

C++17 (static/template method):

```cpp
template <class Derived>
struct ck {
  using cDer = const Derived;
  cDer& self = *static_cast<cDer*>(this);

  L altitude(const P &p, const L &l) const
  { return p * self._perp(l); }
};

*struct hyck : ck<hyck> {
  L _perp(const P &v) const 
  { return L(v[0], v[1], -v[2]); }

  P _perp(const L &v) const 
  { return P(v[0], v[1], -v[2]); }
};
```

]

]

---

Spaceship operator
-------------------

.small[
.col-5[

Python:

```python
class Fraction:
  # ...
    def __cmp__(self, f):
        return self.num * f.den - 
               self.den * f.num


if __name__ == "__main__": 
    p = Fraction(3, 4)
    q = Fraction(5, 6)
    assert q != p
    assert q > p
    assert p <= q
```

]

.col-7[

C++2a:

```cpp
class Fraction {
  // ...
    auto operator<=>(const Fraction &f) const {
        return this->num * f.den - 
               this->den * f.num;
    }
};

int main() {
    auto p = Fraction(3, 4);
    auto q = Fraction(5, 6);
    assert(q != p);
    assert(q > p);
    assert(p <= q);
}
```
]
]

---

Yield and Coroutine
-------------------

.small[

.col-6[

C++2a:

```cpp
#include <cppcoro/generator.hpp>
#include <experimental/coroutine>
using cppcoro::generator;

template <typename T> generator<T> 
myrange(T first, T last) {
    while (first != last) {
        co_yield first++;
    }
}

int main() {
    for (int i : myrange(0, 10)) {
        printf("%d\n", i);
    }
    printf("Done.\n")
}
```
]

.col-5[

Python:

```python
def myrange(first, last):
    while first != last:
        yield first
        first += 1

if __name__ == "__main__":
    for i in myrange(0, 10):
        print(i)
    print("Done.")
```

A more complex example can be found [here](https://wandbox.org/permlink/xD8jsT6luhOxPgUy).

]

]

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
# ...
```

]

.col-8[

C++14:

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

C++14:

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

{fmt} (not yet in C++17 standard)
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

{fmt} installation
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

---

## Use CYTHON to speed up

.small[
```python
class cholutil:
    def __init__(self, n):
        self.R = np.zeros((n, n))
        self.p = 0

    def factor(self, getA):
        self.p = 0
        R = self.R
        n = len(R)
        for i in range(n):
            for j in range(i):
                d = getA(i, j) - np.dot(R[:j, i], R[:j, j])
                R[j, i] = 1. / R[j, j] * d
            d = getA(i, i) - np.dot(R[:i, i], R[:i, i])
            if d <= 0.:  # strictly positive???
                self.p = i + 1
                R[i, i] = np.sqrt(-d)
                break
            R[i, i] = np.sqrt(d)
```
]

---

## `cholutil.pyx`

.small[
```Cython
import numpy as np
cimport numpy as np
cimport cython
from cpython cimport array
import array

cdef extern from "math.h":
    cpdef double sqrt(double x)

DTYPE = np.float
ctypedef np.float_t DTYPE_t

class cholutil:
    def __init__(self, int n):
        self.R = np.zeros((n, n))

    @cython.boundscheck(False) # turn off bounds-checking
    @cython.wraparound(False)  # turn off negative index wrapping
    def factor(self, getA):
        cdef int n = len(self.R)
        cdef DTYPE_t[:, ::1] R = self.R
```
]

---

## How to write portable Python

```python
# Comment should start at the beginning of line
a = 4  # or leave at least two spaces after 
       # the end of a statement.

""" This raw string is usually treated as a comment,
and it is really hard to convert. The opening mark
should avoid at the end of a line. The closing mark
should alway at the end of a line.
"""

s = """because it can also be assigned to a variable,
which should be converted into s = R"(...)"; in C++."""
```

---

## Wish List

- Automatic translation.