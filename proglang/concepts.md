title: C++ Concepts
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

## Why?

- Better error message
- Write more generic code

## Why not?

- Currently only g++ supports this feature.
- Most tools do not support Concepts syntax yet.

---

## Travis Configuration (`.travis.yml`)

```yaml
language: cpp
dist: focal

matrix:
  include:
    # Linux C++20 GCC builds
    - os: linux
      compiler: gcc
      addons: &gcc10
        apt:
          sources: ["ubuntu-toolchain-r-test"]
          packages:
            - g++-10
            - ...
```

---

## `CMakeList.txt`

```cmake
cmake_minimum_required (VERSION 3.3)
project (Fun)
set_property (GLOBAL PROPERTY USE_FOLDERS ON)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (THREADS_PREFER_PTHREAD_FLAG ON)
find_package (Threads REQUIRED)
*add_definitions ( -fconcepts-ts )  # note
```

---

## C++ Concepts: Basic Syntax

- Example 1:

```cpp
template <typename T>
concept Equality_comparable =
  requires(T a, T b) {
    {a == b} -> std::convertible_to<bool>;
    {a != b} -> std::convertible_to<bool>;
  };

// ( T, == ) must be reflective, symmetric, and transitive.
```

- Specify template parameter's constraints.

- It is called _concept lite_ because it cannot specify "semantic".

---

## Concept II

- Concept can utilize user-defined typename, e.g.:

```cpp
template <typename T>
using Element_type =
    std::decay<decltype(back(std::declval<T>()))>::value;

template <typename T>
concept Sequence = requires(T t, Element_type<T> x)
{
    { t.size() }  -> std::convertible_to<std::size_t>;
    { t.empty() } -> std::convertible_to<bool>;
    { t.back() }  -> std::same_as<Element_type<T> >;
    { t.push_back(x) };
};
```

---

## Concept III

- Concept can conjunction with other concepts:

```cpp
template <class P, class L>
concept Projective_plane_h = Equality_comparable<P> &&
  requires(P& p, P& q, L& l)
{
    { incident(p, l) } -> std::convertible_to<bool>; // incidence
    { p * q } -> std::convertible_to<L>; // join or meet
    { p.aux() } -> std::convertible_to<L>; // line not incident with p
};

template <class P, class L = typename P::dual>
concept Projective_plane =
    Projective_plane_h<P, L>&& Projective_plane_h<L, P>;
```

---

## Concept IV

- Templates will be instaniated only when their parameters satisfy all
  concepts.

```cpp
template <class P, class L>
  requires Projective_plane<P, L>
auto altitude(const P &p, const L &l) -> L {
  return p * perp(l);
}

template <typename L, typename... Args>
  requires (Projective_plane<L, Args> && ...)
auto coincident(const L& l, const Args&... r) -> bool
{
    return (incident(r, l) && ...);
}
```

---

## Shorthand Notation I (not yet in C++20)

```cpp
template <class P, class L>
  requires Projective_plane<P, L>
auto altitude(const P &p, const L &l) -> L {
  return p * perp(l);
}
```

can be simplifed as:

```cpp
Projective_plane{ P, L }
auto altitude(const P &p, const L &l) -> L {
  return p * perp(l);
}
```

---

## Duplicate function templates are OK

```cpp
template <typename K>
  requires Integral<K>
auto ratio_ratio(K a, K b, K c, K d)
{ return Fraction(a, b) / Fraction(c, d); }  // "A"

template <typename K>
auto ratio_ratio(K a, K b, K c, K d)
{ return (a * d) / (b * c); }                // "B"

auto r1 = ratio_ratio(10, 20, 30, 40);  // pick "A"
auto r2 = ratio_ratio(1., 2., 3., 4.);  // pick "B"
```

---

## Duplicate function templates are OK (II)

Better yet, use `if constexpr` to combine two functions:

```cpp
template <typename K>
auto ratio_ratio(K a, K b, K c, K d) {
  if constexpr (Integral<K>) {
    return Fraction(a, b) / Fraction(c, d);  // "A"
  } else {
    return (a * d) / (b * c);                // "B"
  }
}

auto r1 = ratio_ratio(10, 20, 30, 40);  // pick "A"
auto r2 = ratio_ratio(1., 2., 3., 4.);  // pick "B"
```

---

class: impact

# Q & A 🗣️
