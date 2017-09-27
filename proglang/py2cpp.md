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

In C++17:

```cpp
std::vector V{1, 3, 4, 6}; // C++17
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
std::unordered_map myDict{ { 5, "foo" }, { 6, "bar" } };
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

C++17:

```cpp
std::tuple triple{5, 6, 7};
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

# If constexpr

C++17 add `if constexpr` statement to simplify the partial templates

.small[
.col-6[

Python:

```python
def dist(x1, z1, x2, z2):
  if isinstance(x1, int):
    return Fraction(x1,z1) - Fraction(x2,z2)
  else:
    return x1/z1 - x2/z2
```
]
.col-6[

C++17:

```cpp
template <typename P>
auto dist(P &x1, P &z1, P &x2, P &z2) {
  using K = typename P::value_type;
  if constexpr (std::is_integral<K>::value) {
    return rational{x1,z1} - rational{x2,z2};
  } else {
    return x1/z1 - x2/z2;
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