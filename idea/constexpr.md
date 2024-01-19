# constexpr everywhere?

---

## What is constexpr?

Before:

```cpp
static const auto M = 250 * 250;
```

After:

```cpp
constexpr auto sq(const auto& x) { return x * x; }
// ...
static const auto M = sq(250);
```

---

## Meta-programming

```cpp
template <size_t N> constexpr auto Factorial() {
    if constexpr (N <= 1) {
        return std::integral_constant<size_t, 1U>{};
    } else {
        return std::integral_constant<size_t,
            N * Factorial<N - 1>()>{};
    }
}

static const auto M = Factorial<5>();
```

---

## Meta-programming (2)

```cpp
template <size_t N, size_t K> constexpr auto Combination() {
    if constexpr (K >= N || K == 0) {
        return std::integral_constant<size_t, 1U>{};
    } else {
        return std::integral_constant<size_t,
            Combination<N - 1, K - 1>() + Combination<N - 1, K>()>{};
    }
}
```

---

## Standard Library

- math library: `sqrt()`, `log()`, `pow()`, `sin()`, `cos()` etc.
- `std::array`, but not `std::vector`
- `std::string_view`, but not `std::string`
- not `std::map` and `std::set`
- not `std::unordered_map` and `std::unordered_set`

---

## Perfect minimal hashing

- Frozen: constexpr replacement of `gperf`

```cpp
#include <frozen/unordered_map.h>
#include <frozen/string.h>

constexpr frozen::unordered_map<frozen::string, int, 4> pin_type = {
    {"input", 0}, {"output", 1}, {"inout", 2}, {"dont_care", 3},
};

read_netlist();
// ...
auto val = pin_type.at(token);
```

---

## Compiler-time Parser?

- regex parser
- JSON parser
