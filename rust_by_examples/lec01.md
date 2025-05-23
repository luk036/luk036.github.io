layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Lecture 1: Hello world!

---

## Hello Python 🐍

```python
# file: hello.py
# Run with:
# $ python hello.py

from math import sin

a = 12 + 4
print('The ans is {}.'.format(a))

b = sin(0.4)
print('The ans is {}.'.format(b))
```

How about in C++?

---

## Hello printf

```cpp
// file: hello2.cpp
// Compile with:
// $ g++ hello2.cpp -o hello2

#include <stdio.h>  // for printf
#include <cmath>    // for std::sin()

int main() {
    auto a = 12 + 4; // C++11
    printf("The ans is %d.\n", a); // %d for int

    auto b = std::sin(0.4);
    printf("The ans is %f.\n", b); // %f for double
}

```

---

## Hello iostream

```cpp
// file: hello1.cpp
#include <iostream> // for std::cout
#include <cmath>    // for std::sin()

int main() {
    auto a = 12 + 4;  // C++11
    std::cout << "The ans is " << a << ".\n";

    auto b = std::sin(0.4);
    std::cout << "The ans is " << b << ".\n";
}

```

---

## iostream, good or bad?

Good 👍:

- More generic code.

Bad 👎:

- The header file is too big.
- The run time is usually slower than _printf()_.
- The syntax is not readable.

---

## Hello to {fmt}

```cpp
// file: hello.cpp
// Compile with:
// $ g++ hello.cpp -o hello -lfmt

#include <fmt/core.h> // for fmt::print
#include <cmath>      // for std::sin()

int main() {
    auto a = 12 + 4;
    fmt::print("The ans is {}.\n", a);

    auto b = std::sin(0.4);
    fmt::print("The ans is {}.\n", b);
}
```

How about in Rust?

---

## Hello {fmt}

```rust
// file: hello.rs
// Compile with:
// $ rustc hello.rs

fn main() {
    let a = 12 + 4;
    println!("答案是 {}.", a);

    let b = (0.4 as f64).sin();
    println!("答案是 {}.", b);
}
```

---

## Hello array (Python 🐍)

```python
# file: hello.py

arr = [2, 3, 5, 7, 11, 'hello']
print('The answer is {}'.format(arr))
```

---

## Hello array (C++)

```cpp
// file: hello.cpp
// Compile with:
// $ g++ -std=c++17 hello.cpp -lfmt

#include <array>
#include <fmt/ranges.h>

int main() {
    auto arr = std::array{2, 3, 5}; // c++17
    fmt::print("The ans is {}.\n", arr);
}
```

---

## Hello array (Rust 🦀)

```rust
// file: hello.rs
// Compile with:
// $ rustc hello.rs

fn main() {
    let arr = [2, 3, 5];
    println!("The ans is {:?}.", arr);
}
```

---

## Tuple in Python 🐍

```python
def main():
    T = ("a", "u", "e", 7, 3.4)
    print(T)

    for i, e in enumerate(T):
        print("{}: {}, ".format(i, e))


if __name__ == '__main__':
    main()
```

---

## Tuple in Rust 🦀

```rust
fn main() {
    let tup = ("a", "u", "e", 7, 3.4);
    println!("{:?}", tup)

    let arr = [2, 3, 5, 7];
    for (i, e) in arr.iter().enumerate():
        println!("{}: {}", i, e)
}
```

---

## Tuple in C++ 😱😱😱😱

```cpp
#include <fmt/ranges.h>
#include <tuple> // tuple is not container

template <std::size_t I = 0, typename... Tp>
void print_test(const std::tuple<Tp...>& t) {
    if constexpr (I < sizeof...(Tp)) {
        fmt::print("{}: {}, \n", I, std::get<I>(t));
        print_test<I + 1, Tp...>(t);
    }
}
int main() {
    auto t = std::tuple{"a", "u", "e", 3, 4.5};
    fmt::print("{}\n", t);
    print_test(t);
}
```

---

## Minimum Environment Setup 🔧

- Lubuntu 20.04 LTS:
  - python3 built-in
  - sudo apt install g++
  - sudo apt install libfmt-dev
- Android termux:
  - pkg install python
  - pkg install clang
  - pkg install fmt
  - pkg install rust

---

## 🔚 Conclusion

- Almost Always Auto (AAA)
- Modern C++ is faster, safer, and easier to use.
- Modern C++ is more python-like
- Modern C++ is more Rust-like

---

## Coming up 🔜

- Type checking in python
- `None` vs. `std::optional<T>` vs. `Option<T>`
- Essential containers
  - list vs. `std::vector<T>` vs. `Vec<T>`
  - dict vs. `std::unordered_map<T>` vs. `HashMap<T>`
  - set vs. `std::unordered_set<T>` vs. `HashSet<T>`
- range base for-loop vs. range-v3
  - zip, enumerate
- numpy vs. xtensor
- pytest vs. doctest
- and more...

---

class: nord-dark, center, middle

# Q & A 🎤
