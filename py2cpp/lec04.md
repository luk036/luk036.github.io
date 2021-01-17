title: Frome Python To Modern C++
class: animation-fade
layout: true

.bottom-bar[ {{title}}: Lecture 4: Container, iterators, and Ranges]

---

class: center, middle

# Lecture 4: Container, iterators, and Ranges

---

## Containers (python)

```python
L = [2, 3, 5, 7, 2]
S = {2, 3, 5, 7, 2}
D = {"us": 1, "cn": 86, "hk": 852}
T = (2, 3, 5, 7, "hello", False)

for (a in C):
    process a
```

---

## Containers (C++)

```cpp
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility> // pair
#include <tuple>
...
using namespace std;
auto L = vector{2, 3, 5, 7, 2};
auto S = unordered_set{2, 3, 5, 7, 2};
auto D = unordered_map{pair{"us", 1}, pair{"cn", 86}, pair{"hk", 852}};
// auto T = tuple{2, 3, 5, 2, "hello", false}; 
// Tuple is not a container.

for (auto& a : C) {
    process(a);
} 
```

---

## unordered_map

👉 Note that:

```cpp
const auto L = std::vector{ ... }; // const object
const auto D = std::unordered_map{ ... };
auto a = L[1]; // OK
auto b = D["hk"]; // compilation error!!!
auto c = D.at("hk"); // OK
```

---

## Polymorphic memory resource (pmr)

- C++ allows users to use customize allocators since C++11
- C++17 adds polymorphic memory resource library
- But not all compilers support pmr for this moment.

```cpp
#include <memory_resource>
...
std::byte StackBuf[2048];
std::pmr::monotonic_buffer_resource rsrc(StackBuf, sizeof StackBuf);
auto L = std::pmr::vector<int>(K, 0, &rsrc);
```

---

## Iterator (python)

```python
class dllink:
    def __iter__(self):
        return dll_itr(self)

class dll_itr:
    def __init__(self, link):
        self.link = link
        self.cur = link.next

    def __next__(self):
        if self.cur != self.link:
            res = self.cur
            self.cur = self.cur.next
            return res
        else:
            raise StopIteration
```

---

## Iterator (C++)

```cpp
template <typename T>
class dllink {
    friend dll_itr<T>;
    ...
    auto begin() -> dll_itr<T>;
    auto end() -> dll_itr<T>;
};
// Define dll_itr (see next slide)

template <typename T>
inline auto dllink<T>::begin() -> dll_itr<T>
{ return dll_itr<T> {this->next}; }

template <typename T>
inline auto dllink<T>::end() -> dll_itr<T>
{ return dll_itr<T> {this}; }
```

---

## Iterator (C++)

```cpp
template <typename T>
struct dll_itr {
    dllink<T>* cur; /*!< pointer to the current item */
    explicit dll_itr(dllink<T>* cur) : cur {cur} { }

    auto operator*() -> dllink<T>& { return *this->cur; }

    auto operator++() -> dll_itr& 
    { this->cur = this->cur->next; return *this; }

    auto operator==(const dll_itr& rhs) const -> bool
    { return this->cur == rhs.cur; }

    auto operator!=(const dll_itr& rhs) const -> bool
    { return !(*this == rhs); }
};
```

---

## range (python)

```python
for i in range(100):
    ...
for iv, v in enumerate(L):
    ...
for a, b in zip(L1, L2):
    ...
```

---

## range-v3 (C++)

```cpp
#include <range/v3/view/iota.hpp>
#include <range/v3/view/enumerate.hpp>
#include <range/v3/view/zip.hpp>

for (auto i : ranges::views::iota(100)) { ... }
for (auto [iv, v] : ranges::views::enumerate(L)) { ... }
for (auto [a, b] : ranges::views::zip(L1, L2)) { ... }
```

---

## Minimum Environment Setup 🔧

👉 Note that range-v3 is a header-only library.

- Lubuntu 20.04 LTS:
    - sudo apt install librange-v3-dev
- Android termux:
    - gh repo clone ericniebler/range-v3
    - cd range-v3/include
    - cp -r * $PREFIX/include/

---

class: center, middle

# Q & A 🗣️
