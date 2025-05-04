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

@luk036

---

## Why?

- Better error message
- Write more generic code

## Why not?

- Currently only g++ supports this feature.
- Most tools do not support Concepts syntax yet.

---

## C++ Concepts: Basic Syntax

- 📚 Example 1:

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

- It is called _concept lite_ because it cannot specify "semantic".

---

## Concept II

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

## Concept III

- Concept can conjunction with other concepts:

```cpp
template <class P, class L>
concept bool Projective_plane_h =
  Equality_comparable<P> && requires(P p, P q, L l) {
  { P(p) } -> P; // copyable
  { p.incident(l) } -> bool; // incidence
  { L(p, q) } -> L; // join or meet
};

template <class P, class L = typename P::dual>
concept bool Projective_plane =
  Projective_plane_h<P, L> && Projective_plane_h<L, P>;
```

---

## Concepts: IV

- Templates will be instaniated only when their parameters satisfy all concepts.

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

## Shorthand Notation I

```cpp
template <class P, class L>
requires Cayley_Klein_plane<P, L>
auto altitude(const P &p, const L &l) {
  return L{p, ~l};
}
```

can be simplifed as:

```cpp
Cayley_Klein_plane{P, L}
auto altitude(const P &p, const L &l) {
  return L{p, ~l};
}
```

---

## Shorthand Notation II

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
