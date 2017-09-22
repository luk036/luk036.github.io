title: Python vs. Modern C++
class: animation-fade
layout: true

<!-- This slide will serve as the base layout for all your slides -->
.bottom-bar[
  {{title}}
]

---

class: impact

# {{title}}
## Wai-Shing Luk

---

#  Agenda

1. Introduction
2. Auto
3. Range-Based For Loop
4. Uniform Initialization
5. Tuples
6. Structure Binding
7. If constexpr
8. Yield and coroutine
9. Modules

---

# Introduction

- Modern C++ has become more Pythonic today.
- Python is a simple programming language, yet C++ is more powerful.

---

# Auto

Python has always been a dynamically typed language. You don’t need to declare variable types anywhere, since types are a property of the objects themselves. Whereas, C++11 uses `auto` keyword for automatic type deduction.

.col-4[

In Python:

```python
x = "Hello world!"
print x
```
]
.col-8[

In C++11:

```cpp
auto x = "Hello world!";
std::cout << x;
```
]

---

# Range-Based For Loops

In Python, a `for` loop always iterates over a Python object. Meanwhile, C++ starts to support range-based for loops in C++11.

.col-4[

In Python:

```python
V = [1, 3, 4, 6]
for x in V:
    print x
```
]
.col-8[

In C++11:

```cpp
std::vector<int> V = {1, 3, 4, 6};
for (auto x: V)
    std::cout << x;
```
]

---

# Uniform Initialization

In Python, you can also create a dictionary with a single expression:

```python
myDict = {5: "foo", 6: "bar"}
print(myDict[5])
```

Similarly, uniform initialization also works on C++’s `std::map` and `unordered_map`:

```cpp
auto myDict = std::unordered_map{ { 5, "foo" }, { 6, "bar" } };
std::cout << myDict[5];
```

---

# Tuple

Python has had tuples pretty much since the beginning. C++ added tuples to the standard library in C++11.

.col-4[

Python:

```python
triple = (5, 6, 7)
print triple[0]
x, y, z = triple
```
]
.col-8[

C++11:

```cpp
auto triple = std::make_tuple(5, 6, 7);
std::cout << std::get<0>(triple);
std::tie(x, y, z) = triple;
```
]


---

# Structure Binding

C++17 further added a language support to structure binding.

.small[
.col-6[

Python:

```python
def update(self, g):
    xc = self.xc
    P = self.P
    Pg = P.dot(g)
    tsq = g.dot(Pg)
    tau = np.sqrt(tsq)
    rho, delta = calc_ell()
    xc -= (rho/tau) * Pg
    P -= 2*rho*outer(Pg,Pg)
    P *= delta
    return 0, tau
```
]
.col-6[

C++17:

```cpp
auto update(const Vec& g) {
    auto& xc = this->_xc;
    auto& P = this->_P;
    Vec Pg = prod(P, g);
    auto tsq = inner_prod(g, Pg);
    auto tau = std::sqrt(tsq);
    auto [rho, delta] = calc_ell();
    xc -= (rho/tau)*Pg;
    P -= 2*rho*outer_prod(Pg, Pg);
    P *= delta;
    return std::make_tuple(0, tau);
}
```
]
]

---

# If constexpr

C++17 add `if constexpr` statement to simplify the partial templates

.small[
.col-6[

Python:

```python
def __init__(self, val, x):
  n = len(x)
  self.xc = np.array(x)
  if np.isscalar(val):
    self.P = val*np.identity(n)
  else:
    self.P = np.diag(val)
```
]
.col-6[

C++17:

```cpp
template <typename T>
ell(const T& val, const Vec& x)
  : n{x.size()}, _P(n,n), _xc{x} 
{
  for (auto i = 0U; i < n; ++i) {
    if constexpr (is_scalar_v<T>)
      _P(i,i) = val;
    else
      _P(i,i) = val(i);
  }
}
```
]
]

---

# Yield and Coroutine

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

# Yield and Coroutine (cont'd)

- Currently, C++17 does not support `yield` statement (not until C++20).
- The closest feature is `Boost.Coroutine2`.

---

## Modules (not yet in C++17)

.small[
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
]