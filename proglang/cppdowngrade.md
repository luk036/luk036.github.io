layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Downgrading C++

@luk036

---

## Why?

- Old codes can't catch up with the new standard
- Old tools can't catch up with the new standard
- 🆕 New feature that I don't like

---

## Likely/Unlikely

.font-sm.mb-xs[

C++20

```cpp
if (d == 0.) [[unlikely]]
    start = i + 1;
```

C++98

```cpp
#if defined(__clang__) || defined(__GNUC__)
#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#define LIKELY(x) (!!(x))
#define UNLIKELY(x) (!!(x))
#endif

if UNLIKELY(d == 0.)
    start = i + 1;
```

]

---

## Default comparisons

.font-sm.mb-xs[ .pull-left[

C++20

```cpp
class point3 {
  int x, y, z;

  friend bool operator==(
    const point3&, const point3&)
      = default;
  friend bool operator<(
    const point3&, const point3&)
      = default;
};
```

]

.pull-right[

C++11

```cpp
#include <tuple>
class point3 {
  int x, y, z;

  friend bool operator==(
    const point3& lhs, const point3& rhs) {
    return std::tie(lhs.x, lhs.y, lhs.z)
        == std::tie(rhs.x, rhs.y, rhs.z);
  }
  friend bool operator<(
    const point3& lhs, const point3& rhs) {
    return std::tie(lhs.x, lhs.y, lhs.z)
        < std::tie(rhs.x, rhs.y, rhs.z);
  }
};
```

] ]

---

## Init-statements in range-for

C++20

```cpp
for (T thing = foo(); auto& x : thing.items())
{ /* ... */ }
```

C++11

```cpp
{
    T thing = foo();
    for (auto& x : thing.items())
    { /* ... */ }
}
// Note: foo().items() is dangerous!
```

---

## Abbreviated function template

.font-sm.mb-xs[ .pull-left[

C++20

```cpp
void f1(auto);
void f2(C1 auto);
```

]

.pull-right[

C++17

```cpp
template<class T> void f(T);
template<C1 T> void f2(T);
```

] ]

---

## `requires`

.font-sm.mb-xs[ .pull-left[

C++20

```cpp
template <typename _Mn>
requires std::is_integral<_Mn>::value
constexpr _Mn gcd(_Mn __m, _Mn __n)
{
    return __m == 0 ? abs(__n) : __n == 0
        ? abs(__m) : gcd(__n, __m % __n);
}
```

]

.pull-right[

C++11

```cpp
template <typename _Mn>
constexpr typename std::enable_if<
  std::is_integral<_Mn>::value, _Mn>::type
gcd(_Mn __m, _Mn __n)
{
    return __m == 0 ? abs(__n) : __n == 0
        ? abs(__m) : gcd(__n, __m % __n);
}
```

] ]

---

## `contains()`

.font-sm.mb-xs[ .pull-left[

C++20

```cpp
#include <iostream>
#include <map>

int main()
{
    std::map<int,char> example =
        { {1,'a'}, {2,'b'} };

    if (example.contains(2)) {
        std::cout << "Found\n";
    } else {
        std::cout << "Not found\n";
    }
}
```

]

.pull-right[

C++17

```cpp
#include <iostream>
#include <map>

int main()
{
    std::map<int,char> example =
        { {1,'a'}, {2,'b'} };

    if (example.find(2) != example.end()) {
        std::cout << "Found\n";
    } else {
        std::cout << "Not found\n";
    }
}
```

] ]

---

## Fold expression

.font-sm.mb-xs[ .pull-left[

C++17

```cpp
template<typename... Args>
bool all(Args... args) {
  return (... && args);
}

bool b = all(true, true, false);
bool c = all(false, true);
```

]

.pull-right[

C++11

```cpp
template<typename Arg1,
         typename Arg2, typename Arg3>
bool all(Arg1 arg1, Arg2 arg2, Arg3 arg3) {
  return arg1 && arg2 && arg3;
}

template<typename Arg1, typename Arg2>
bool all(Arg1 arg1, Arg2 arg2) {
  return arg1 && arg2;
}

bool b = all(true, true, false);
bool c = all(false, true);
```

] ]

---

## Class template argument deduction (CTAD)

.font-sm.mb-xs[ .pull-left[

C++17

```cpp
auto p = std::pair(2, 4.5);
auto t = std::tuple(4, 3, 2.5);
auto l = std::less;
```

]

.pull-right[

C++11

```cpp
auto p = std::pair<int, double>(2, 4.5);
auto t = std::make_tuple(4, 3, 2.5);
auto l = std::less<void>;
```

] ]

---

## Constexpr if

.font-sm.mb-xs[ .pull-left[

C++17

```cpp
template <typename N>
N half_nonnegative(N n)
{
  if constexpr(std::is_integral<N>::value)
  {
    using UN = typename
        std::make_unsigned<N>::type;
    return static_cast<N>(
        static_cast<UN>(n) / 2);
  }
  else
  {
    return std::move(n) / 2;
  }
}
```

]

.pull-right[

C++11

```cpp
template <typename N>
typename std::enable_if<
  std::is_integral<N>::value, N>::type
half_nonnegative(N n) {
  using UN = typename
      std::make_unsigned<N>::type;
  return static_cast<N>(
      static_cast<UN>(n) / 2);
}

template <typename N>
typename std::enable_if<
  !std::is_integral<N>::value, N>::type
half_nonnegative(N n) {
  return std::move(n) / 2;
}
```

] ]

---

## Structured binding

.font-sm.mb-xs[ .pull-left[

C++17

```cpp
std::set<std::string> S{"hello"};
auto [iter, ok] = S.insert("Hello");
```

]

.pull-right[

C++11

```cpp
#include <tuple>
std::set<std::string> S{"hello"};
auto rslt = S.insert("Hello");
auto iter = std::get<0>(rslt);
auto ok = std::get<1>(rslt);
```

] ]

---

## Initializer for `if` (I hate it!)

.font-sm.mb-xs[ .pull-left[

C++17

```cpp
std::map<int, std::string> m;
// ...
if (auto it = m.find(10); it != m.end())
{
  return it->second.size();
}
```

]

.pull-right[

C++11

```cpp
std::map<int, std::string> m;
// ...
auto it1 = m.find(10);
if (it1 != m.end())
{
  return it1->second.size();
}
```

] ]

---

## Standard library vs. Third party libraries

| C++20/C++17        | third-party            |
| ------------------ | ---------------------- |
| std::any           | boost::any             |
| std::optional      | boost::optional        |
| std::string_view   | boost::string_view     |
| std::variant       | boost::variant         |
| std::visit         | boost::visit           |
| std::gcd, std::lcm | boost::gcd, boost::lcm |
| std::pmr           | boost::container::pmr  |
| std::format        | fmt::format            |
| std::span          | gsl::span              |
