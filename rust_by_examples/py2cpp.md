class: animation-fade
title: From Python To Modern C++ 
layout: true

<!-- This slide will serve as the base layout for all your slides -->
.bottom-bar[{{title}}]

---

class: impact

{{title}}
=========

Wai-Shing Luk
-------------

---

Agenda
------

.col-6[

-   Introduction
-   Conda installation
-   Auto
-   Template Guided Deduction
-   Range-Based For Loop
-   Uniform Initialization
-   Tuples
-   Structure Binding
-   If constexpr

]

.col-6[

-   Yield and coroutine
-   Spaceship operator
-   Modules
-   Python-like enumerate()
-   Python-like formating: {fmt}
-   Library: numpy vs. xtensor
-   Library: pytest vs. Catch2

]

---

Introduction
------------

-   Python is an easy-to-use programming language.
-   Python could be 10X slower than C++.
-   C++ is a strong type-checking language.
-   Modern C++ has become more Pythonic today.
-   Modern C++ is even faster than C.
-   Strategy: Python first, C++ follow.

---

Conda Installation
------------------

-   Assume install to a USB stick, in which the file system is mounted
    to `$USB`, and is read/write accessable.

-   Use Conda to install Python and Python-related C++'s libraries:

.small[

``` {.bash}
wget "http://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh" \
 -O miniconda.sh
export CONDA_PREFIX=$USB/miniconda3
bash miniconda.sh -b -p $CONDA_PREFIX
export PATH="$CONDA_PREFIX/bin:$PATH" # overwrite the system python
# export LDFLAGS="$LDFLAGS -lrt -pthread -lresolv"
# export LD_LIBRARY_PATH="$CONDA_PREFIX/lib"  # optional
```

]

---

Pip Mirror Site Configuration
-----------------------------

Create and edit `~/.pip/pip.conf` file:

```ini
[global]
index-url = https://pypi.tuna.tsinghua.edu.cn/simple
```

---

Conda-Python Installation
-------------------------

```bash
# For python 3.7
python --version # make sure which python is using
pip install \
  pytest pytest-cov pytest-benchmark \
  codecov coverage cpp-coveralls hypothesis \
  yapf flake8 mypy cppclean PyScaffold \
  sphinx sphinx-rtd-theme exhale
pip install -U rope --user
pip install \
  numpy scipy matplotlib sympy \
  networkx cvxpy PyQt5

# For older version of python (optional)
conda create -n py26 python=2.6 anaconda
source activate py26
# install the modules as above
```

---

Python-related C++ Libraries Installation
-----------------------------------------

```bash
conda install pkg-config
conda install -c conda-forge \
    cmake ninja bison flex \
    cppcheck valgrind doxygen \
    xtensor-fftw \
    xtensor-blas \
    xtensor \
    openblas boost \
    catch2 benchmark

# For python 3.7
export LD_LIBRARY_PATH=$CONDA_PREFIX/lib

# For python 2.6 (optional)
export LD_LIBRARY_PATH=$CONDA_PREFIX/envs/py26/lib
```

---

Other C++ Installation
----------------------

```bash
sudo apt install \
  lcov \
  gdb kcachegrind \
  clang-format clange-tidy \
  libfmt-dev libspdlog-dev
```

---

CMake Configuration
-------------------

.small[

```cmake
cmake_minimum_required (VERSION 3.3)
*set(CMAKE_PREFIX_PATH $ENV{CONDA_PREFIX})
...
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
...
find_package (Threads REQUIRED)
find_package (Boost REQUIRED COMPONENTS context coroutine)
if (Boost_FOUND)
    message(STATUS "Found boost: ${Boost_INCLUDE_DIRS}")
    set(LIBS ${LIBS} ${Boost_LIBRARIES})
endif (Boost_FOUND)
...
include_directories (${LIBRARY_INCLUDE_PATH} ${Boost_INCLUDE_DIRS})
target_link_libraries (${APP_NAME}
  Threads::Threads ${LIBS}
)
```

]

---

Data Access Type
----------------

A Python's variable have only one data access type, whereas C++ can have
reference (&), move reference (&&) and pointer (\*) type:

.small[ .col-6[

```python
class involution:
    def __init__(self, m, o):
        self.m = m
        self.o = o
        self.c = m.dot(o)
```

] .col-6[

```cpp
class involution {
  L& _m;
  P _o;
  K _c;

  involution(L &m, P o):
    _m{m},
    _o{std::move(o)},
    _c{m.dot(_o)} {}
};
```

] ]

---

Element type of Container
-------------------------

In C++, the element type of container (array, vector, etc.)
cannot be a reference (e.g. `vector<int&>`).
Use smart pointers if necessary.

Python:

```python
gainbucket = [bpqueue(pmax) for _ in range(K)]
```

C++17:

```cpp
auto gainbucket = std::vector<std::unique_ptr<bpqueue>>(
  K, std::make_unique<bpqueue>(pmax));
```

---

Data Trasfer
------------

Except basic data types (int, float, etc.), a Python's variable copies
only its reference to another object. Use `std::move` to avoid object
copying.

.small[ .col-6[

```python
def create_something_big():
    # ...
    N = ...
    s = list(...)
    Y = list(...)
    # ...
    return Y, s, N # local variables
```

] .col-6[

```cpp
auto create_something_big() {
  // ...
  auto N = ...
  auto s = std::vector{ ... };
  auto Y = std::vector{ ... };
  // ...
  return std::tuple{std::move(Y),
                    std::move(s), N};
}
```

] ]

---

Auto
----

Python has always been a dynamically typed language. You don't need to
declare variable types anywhere. Whereas, C++11 uses `auto` keyword for
automatic type deduction. (Almost Always Auto? 🤔)

Be aware of "template expression" in C++.

.small[ .col-4[

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

```cpp
auto tri(const std::tuple<P,P,P> &T) {
  const auto &[a1, a2, a3] = T;
  auto l1 = a2 * a3;
  auto l2 = a1 * a3;
  auto l3 = a1 * a2;
  return std::tuple{std::move(l1),
                    std::move(l2),
                    std::move(l3)};
}
```

] ]

---

Static Type Checking in Python
-------------------------------

In Python 3.7, you can add type information to the variables
and use `mypy` tool to perform static type checking.

.small[ .col-6[

In Python:

```python
def set_key(self, it,
            gain: int) -> None:
    it.key = gain - self.offset

def get_max(self) -> int:
    return self.max + self.offset

def is_empty(self) -> bool:
    return self.max == 0
```

]
.col-6[

In C++:

```cpp
auto set_key(dllink& it,
             int gain) -> void {
    it.key = gain - this->offset;
}
auto get_max() const -> int {
    return this->max + this->offset;
}
auto is_empty() const -> bool {
    return this->max == 0;
}
```

] ]

---

Class Template Argument Deduction (CTAD)
----------------------------------------

.small[ .col-6[

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

*// could be automatically deduced.
*template <typename T>
*interval(T, T)-> interval<T>;

int main() {
  auto a = interval{0, 10}; // int
  auto b = interval{1.0, 6.0}; // double
}
```

] ]

---

Type
----

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

.small[

```python
M = {1 : "hello", 8 : 5.6, 9 : 4}
assert len(M) == 3
assert M[8] == 5.6
```

]

In C++17, we may use `std::any` to simulate this:

.small[

```cpp
#include <any>
// ...
auto M = std::unordered_map<int, std::any>{
  {1, "hello"}, {8, 5.6}, {9, 4} };
assert(M.size() == 3);
assert(std::any_cast<double>(M[8]) == 5.6);
```

]

---

`std::optional`
---------------

.small[ .col-4[

In Python, a variable can be a null object:

```python
def my_oracle(x):
    fj = -x[0] + x[1] + 1.
    if fj > 0.:
        g = np.array([-1., 1.])
        return g, fj
    return None

def __call__(self, x, t):
    cut = my_oracle(x)
    if cut:
        return cut, t
    # ...
    return g, t
```

] .col-8[

In C++17, we may use `std::optional` to simulate this:

```cpp
auto my_oracle(const Arr& x) -> std::optional<Cut> {
  fj = -x[0] + x[1] + 1.;
  if (fj > 0.) {
    auto g = Arr{-1., 1.};
    return {std::move(g), fj}};
  }
  return {}; // null object
}

auto operator()(Arr& x, double t) -> std::tuple<Cut, double> {
  const auto cut = my_oracle(x);
  if (cut) {
      return {*cut, t};
  }
  // ...
  return { {std::move(g), fj}, t};
}
```

] ]

---

Range-Based For Loops
---------------------

In Python, a `for` loop always iterates over a Python object. Meanwhile,
C++ starts to support range-based for loops in C++11.

.small[ .col-6[

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

```cpp
bool coI(L &l, Sequence &seq) {
  for (const P &p : seq) {
    if (!l.incident(p))
      return false;
  }
  return true;
}
```

] ]

---

Difference Between Python and C++
----------------------------------

.col-6[

In Python:

```python
for i in range(100):
    # process for loop

print(i) # print 99
```

]

.col-6[

In C++:

```cpp
unsigned i;
for (i = 0; i != 100; ++i) {
    // process for loop
}
std::cout << i; // print 100!
```

]

---

Dynamic type vs. static type
----------------------------------

.col-6[

In Python:

```python
lower = 1
upper = 4
...
midpoint = lower
midpoint += 0.5 * (upper - lower)
print(midpoint) # print 2.5
```

]

.col-6[

In C++:

```cpp
auto lower = 1;
auto upper = 4;
...
auto midpoint = lower;
midpoint += 0.5 * (upper - lower);
std::cout << midpoint; // print 2!
```

]

---

Uniform Initialization
----------------------

.col-6[

In Python, you can create a dictionary with a single expression:

```python
myDict = {5: "foo", 6: "bar"}
print(myDict[5])
```

]

.col-6[

In C++, uniform initialization also works on `std::map` and
`unordered_map`:

```cpp
auto myDict = std::unordered_map{
  { 5, "foo"sv }, { 6, "bar"sv } };
std::cout << myDict[5];
```

]

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
auto triple = std::tuple{5, 6, 7};
std::cout << std::get<0>(triple);
auto& [x, y, z] = triple;
```

]

---

Structured Binding
------------------

C++17 further added a language support to structured binding.

.small[

.col-6[

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

```cpp
class ell {
public:
  auto calc_cc() {
    /* central cut */
    auto n = std::size(this->_xc);
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

] ]

---

Function Object
---------------

In Python, a function is also an object. Thus, you can pass in a function
as an argument, or define a local function. In Modern C++, you can use a
lambda function to simulate it.

.small[ .col-6[

```python
def do_case(G, k):
    def get_weight(e):
        u, v = e
        return G[u][v].get('weight', k)

    ...
    N = negCycleFinder(G, get_weight)
    cycle = N.find_neg_cycle(dist)
    return cycle != []
```

]

.col-6[

```cpp
bool do_case(const Graph &G, int k) {
  auto get_weight =
    [&](const auto &e) -> int {
      const auto& [u, v] = e;
      return G[u][v].get("weight", k);
    };

  ...
  auto N = negCycleFinder(G, get_weight);
  auto cycle = N.find_neg_cycle(dist);
  return !cycle.empty();
}
```

] ]

---

Abstract Method
---------------

.small[

.col-6[

Python:

```python
from abc import abstractmethod

class ck():
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

] ]

---

Abstract Method (II)
--------------------

.small[

.col-6[

Python:

```python
from abc import abstractmethod

class ck():
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

struct hyck : ck<hyck> {
  L _perp(const P &v) const
  { return L(v[0], v[1], -v[2]); }

  P _perp(const L &v) const
  { return P(v[0], v[1], -v[2]); }
};
```

]

]

---

Yield and Coroutine
-------------------

.small[ .col-4[

Python:

```python
def items(self):
  k = self.max
  while k > 0:
    for i in self.bucket[k]:
*     yield i
    k -= 1
```

] .col-8[

C++17 + Boost:

```cpp
#include <boost/coroutine2/all.hpp>

using coro_t = boost::coroutines2::coroutine<dllink<T>&>;
using pull_t = typename coro_t::pull_type;
auto items() -> pull_t {
  auto func = [&](typename coro_t::push_type & yield){
    auto k = this->max;
    while (k > 0) {
      for (auto& i : this->bucket[k].items()) {
          yield(i);
      }
      k -= 1;
    }
  };
  return pull_t(func);
}
```

]

]

---

Yield and Coroutine
-------------------

.small[ .col-4[

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

] .col-5[

C++2a (future):

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

A more complex example can be found
[here](https://wandbox.org/permlink/xD8jsT6luhOxPgUy).

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

Python-like enumerate()
-----------------------

In Python:

.small[

```python
for i, thing in enumerate(listOfThings):
    print("The %dth thing is %s" % (i, thing))
```

]

In C++17, we can implement a [similiar functionality](http://reedbeta.com/blog/python-like-enumerate-in-cpp17/)

.small[

```cpp
std::vector<Thing> things;
// ...
for (auto [i, thing] : enumerate(things))
{
    // i gets the index and thing gets the Thing in each iteration
}
```

]

---

Python-like formating: {fmt}
----------------------------

Python:

.small[

```python
yb1, fb, iter, flag, status =
    cutting_plane_dc(P, E, 0.0, 200, 1e-4)
print('{:f} {} {} {}'.format(fb, iter, flag, status))
```

]

C++17:

.small[

```cpp
#include <fmt/format.h>
// ...
std::tie(yb1, fb, iter, flag, status) =
    cutting_plane_dc(P, E, 0.0, 200, 1e-4);
fmt::print("{:f} {} {} {}\n", fb, iter, flag, status);
```

]

---

Numpy vs. Xtensor
-----------------

.small[

| Python 3 - numpy            | C++ 14 - xtensor                     |
| --------------------------- | ------------------------------------ |
| `np.linspace(1.0, 8.0, 50)` | `xt::linspace<double>(1.0, 8.0, 50)` |
| `np.logspace(2.0, 3.0, 4)`  | `xt::logspace<double>(2.0, 3.0, 4)`  |
| `np.arange(3, 7)`           | `xt::arange(3, 7)`                   |
| `np.eye(4)`                 | `xt::eye(4)`                         |
| `np.zeros([3, 4])`          | `xt::zeros<double>({3, 4})`          |
| `np.ones([3, 4])`           | `xt::ones<double>({3, 4})`           |
| `np.dot(a, b)`              | `xt::linalg::dot(a, b)`              |
| `np.vdot(a, b)`             | `xt::linalg::vdot(a, b)`             |
| `np.outer(a, b)`            | `xt::linalg::outer(a, b)`            |
| `np.matrix_power(a, 12)`    | `xt::linalg::matrix_power(a, 12)`    |
| `np.kron(a, b)`             | `xt::linalg::kron(a, b)`             |

]

---

Numpy vs. Xtensor (II)
-----------------------

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
for (auto k = 0U; k != N; ++k) {
  auto x = var*xt::random::randn<double>({n});
  auto v = xt::random::randn<double>({n});
  auto y = dot(A,x) + ym + tau*v;
  xt::view(Ys, xt::all(), k) = y;
}
```

] ]

---

Numpy vs. Xtensor (III)
-----------------------

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

] ]

---

pytest vs. Catch2
-----------------

.small[

.col-5[

Python:

```python
from pytest import approx

def test_float():
    a1 = pg_point([3., -5., 2.])
    a2 = pg_point([6., 2., 2.])
    l = join(a1, a2)
    assert l.dot(a1) == approx(0)
```

]

.col-7[

C++17:

```cpp
#include <catch2/catch.hpp>

TEST_CASE("test float", "[proj_plane]") {
    auto a1 = pg_point(3., -5., 2.);
    auto a2 = pg_point(6., 2., 2.);
    auto l = join(a1, a2);
    CHECK(l.dot(a2) == Approx(0));
}
```

] ]

---

Use CYTHON to speed up
----------------------

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

`cholutil.pyx`
--------------

.small[

```cython
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

How to write portable Python
----------------------------

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

🙏 Wish List
---------

-   cppitertools
-   pybind11
-   JSON
-   sphinx vs. doxygen
-   pytest-benchmark vs. google-benchmark
-   logger vs. libspdlog
-   argparse
-   Automatic translation.

---

📚 Further Reading
------------------

-   [Clean Python (2019)](https://link.springer.com/book/10.1007/978-1-4842-4878-2)

-   [Pro Python Best Practices (2017)](https://rd.springer.com/book/10.1007/978-1-4842-2241-6)

-   [C++17 Quick Syntax Reference (2018)](https://rd.springer.com/book/10.1007/978-1-4842-3600-0)

-   [C++17 Standard Library Quick Reference (2019)](https://rd.springer.com/book/10.1007/978-1-4842-4923-9)

-   [JSON Quick Syntax Reference (2016)](https://rd.springer.com/book/10.1007/978-1-4842-1863-1)

---

class: impact

Q & A 🗣️
=====
