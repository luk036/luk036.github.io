title: C++ Concepts 
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

Why?
----

- Better error message
- Write more generic code

Why not?
--------

- Currently only g++ supports this feature.
- Most tools do not support Concepts syntax yet.

---

Travis Configuration (`.travis.yml`)
--------------------

```yaml
language: cpp

matrix:
  include:
    # Linux C++17 GCC builds
    - os: linux
      compiler: gcc
      addons: &gcc7
        apt:
          sources: ['ubuntu-toolchain-r-test']
          packages:
            - g++-7
            - catch
```

---

`CMakeList.txt`
-------------

```cmake
cmake_minimum_required (VERSION 3.3)
project (Fun)
set_property (GLOBAL PROPERTY USE_FOLDERS ON)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (THREADS_PREFER_PTHREAD_FLAG ON)
find_package (Threads REQUIRED)
add_definitions ( -fconcepts )  # note
```

---

C++ Concepts: Basic Syntax
--------------------------

- Example 1:

```cpp
template <typename T>
concept bool Equality_comparable =
  requires(T a, T b) {
    {a == b} -> bool;
    {a != b} -> bool;
  };

// ( T, == ) must be reflective, symmetric, and transitive.
```

- Specify template parameter's constraints.

- It is called *concept lite* because it cannot specify "semantic".

---

Concept II
----------

- Concept can utilize user-defined typename, e.g.:

```cpp
template <typename T>
using Element_type = decltype(back(std::declval<T>()));

template <typename T>
concept bool Sequence =
  requires(T t, Element_type<T> x) {
    { t.size() } -> int;
    { t.empty() } -> bool;
    { t.back() } -> Element_type<T>;
    { t.push_back(x) }
  };
```

---

Concept III
-----------

- Concept can conjunction with other concepts:

```cpp
template <class P, class L>
concept bool Projective_plane_h =
  Equality_comparable<P> && requires(P p, P q, L l) {
    { P(p) } -> P; // copyable
    { p.incident(l) } -> bool; // incidence
    { p * q } -> L; // join or meet
  };

template <class P, class L = typename P::dual>
concept bool Projective_plane =
  Projective_plane_h<P, L> && Projective_plane_h<L, P>;
```

---

Concept IV
------------

- Templates will be instaniated only when their parameters satisfy all
    concepts.

```cpp
template <class L, class C, class P = typename L::dual>
  requires Projective_plane<P, L> && Sequence<C>
constexpr bool coincident(const L &l, const C &seq) {
  for (const P &p : seq) {
    if (!l.incident(p))
      return false;
  }
  return true;
}
```

---

Shorthand Notation I
--------------------

```cpp
template <class P, class L>
  requires Projective_plane<P, L>
L altitude(const P &p, const L &l) {
  return p * perp(l);
}
```

can be simplifed as:

```cpp
Projective_plane{ P, L }
L altitude(const P &p, const L &l) {
  return p * perp(l);
}
```

---

Shorthand Notation II
---------------------

```cpp
template<class ForwardIt, class T>
  requires Iterator<ForwardIt> && Equality_comparable<T>
ForwardIt find( ForwardIt first, ForwardIt last, 
                const T& value ) {
    // ...
}
```

can be simplifed as:

```cpp
Iterator find( Iterator first, Iterator last, 
               const Equality_comparable& value ) {
    // ...
}
```
