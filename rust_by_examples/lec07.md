layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Lecture 7: Numpy/Numexpr vs. Xtensor

---

Numpy vs. Xtensor
-----------------

.font-sm[

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

## Python:

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

---

## C++14:

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

---

## Python

```python
Pg = self.P.dot(g)
tsq = g.dot(Pg)
tau = np.sqrt(tsq)
alpha = beta / tau
status, rho, sigma, delta = calc_ell(alpha)
# ...
self._xc -= (rho / tau) * Pg
self.P -= (sigma / tsq) * np.outer(Pg, Pg)
self.P *= delta
```

---

## C++14:

```cpp
using xt::linalg::dot;
using xt::linalg::outer;
// ...
xt::xarray<double> Pg = dot(_P, g);
auto tsq = dot(g, Pg)();
auto tau = std::sqrt(tsq);
auto alpha = beta / tau;
auto [status, rho, sigma, delta] = calc_ell(alpha);
// ...
this->_xc -= (rho / tau) * Pg;
this->_P -= (sigma / tsq) * outer(Pg, Pg);
this->_P *= delta;
```

---

## Environment Setup 🔧

- Lubuntu 20.04 LTS:
    - pip install numpy, numexpr
    - conda install -c conda-forge xtensor xtensor-blas
- Android termux (see wiki.termux.com first!!!):
    - pkg install openblas
    - pip install numpy
    - pin install numexpr
    - Can't install conda on Android 😭 

---

## Environment Setup (2) 🔧

- Windows 10:
    - Install Visual Studio C++ (community version)
    - Install scoop
    - scoop install wget git gh vscode
    - scoop install miniconda3
    - pip install numpy numexpr
    - conda install cmake ninja
    - conda install -c conda-forge xtensor xtensor-blas

---

class: nord-dark, center, middle

# Q & A 🗣️
