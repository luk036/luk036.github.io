# C++

## signed vs. unsigned integer

- Avoid signed-unsigned conversion (10% improvement)
  - clang-13, turn-on `-Wconversion` compiler flag
  - gitpod

```cpp
    using UInt = std::make_unsigned_t<Int>;
    process( static_cast<UInt>(h) )
```

- Use unsigned integers for indexing, e.g. a[index]

- Generally, use signed integers for arithmetics

  - no overflow detection

- But, be careful:
  - (b - a) / 2
  - `std::midpoint(a, b) /* C++20 */`
    `a + static_cast<Int>(static_cast<UInt>(b - a) / 2)`

## transrangers (C++20)
