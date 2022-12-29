
- Rust 🦀
- cargo 📦
- Python 🐍 ➔ Rust 🦀
- `XMake` (vs `CMake`)
- API

```python
def suppress(vA: Vec2, vA1: Vec2, 
             vri: Vec2, vrj: Vec2):
    # modify vA, vA1
    vA = ...
    vA1 = ...
    ...
    return vA, vA1
```

```cpp
auto suppress(Vec2& vA, Vec2& vA1, 
              const Vec2& vri, 
              const Vec2& vrj) -> void {
    // modify vA, vA1
    vA = ...;
    vA1 = ...;
    ...
}
```

python: prototyping
EDA tools: python front end + C++ core engine

