---
title: From Python to C++
aurthor: Wai-Shing Luk
...

## Hello world (Python)

```python
# hello.py
a = 12 + 4
print('The answer is {}'.format(a))

b = 12.3 + 4.8
print('The answer is {}'.format(b))
```

```bash
$ python hello.py
```

---

## Minimum Environment Setup

  - Lubuntu 20.04 LTS:
    - build-in python3
    - sudo apt install g++
    - sudo apt install libfmt-dev
  - Android:
    - Install termux app
    - pkg install python
    - pkg install clang
    - pkg install fmt

---


## Hello {fmt} (C++)

```cpp
// hello.cpp
#include <fmt/core.h>

int main()
{
    auto a = 12 + 4; // int
    fmt::print("The answer is {}\n", a);

    auto b = 12.3 + 4.8; // double
    fmt::print("The answer is {}\n", b);
}
```

```bash
$ g++ hello.cp -lfmt
$ ./a.out
```

---

## Hello world (Python)

```python
# hello.py
a = 12 + 4
print('The answer is {}'.format(a))

L = [2, 3, 5, 7, 11, 'hello']
print('The answer is {}'.format(L))
```

---

## Hello {fmt} (C++)

```cpp
// hello.cpp
#include <vector>
#include <fmt/ranges.h>

int main()
{
    auto a = 12 + 4;
    fmt::print("The answer is {}\n", a);

    auto L = std::vector{2, 3, 5, 7, 11};
    fmt::print("The answer is {}\n", L);
}
```

---

- Installation
  - Windows: scoop -> miniconda3 -> pip
  - Ubuntu: apt -> miniconda3 -> pip
  - Android: termux -> pkg -> pip

- example: find_roots
  - None vs. std::optional
- template 
- Essential containers
  - list vs. std::vector
  - set vs. std::unordered_set
  -
- range base for-loop and range-v3
  - zip, enumerate
- numpy vs. xtensor xtensor-blas 
- pytest vs. doctest

