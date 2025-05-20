layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Canonical Signed Digit (CSD) Conversion in Python 🎯🔢 

@luk036 👨‍💻

2025-05-14 📅

---

## What is CSD? 🧐❓ 

- **Special number representation** using only: `0`, `+`, and `-` 🔢
- **Benefits** 💎:
  - Efficient in digital signal processing ⚡
  - Reduced hardware complexity 🏗️
  - Optimal for certain arithmetic operations 🏆
- **A Powerful Number Representation System ✨**

**Example** 📝:  
`28.5` → `"+00-00.+"`

---

## Core Functions Overview 🛠️📋 

1. `to_csd()` - Decimal to CSD (floating-point) 📌
2. `to_csd_i()` - Decimal to CSD (integer) 🔢
3. `to_decimal()` - CSD to decimal 🔄
4. `to_csdnnz()` - CSD with limited non-zero digits ✨

---

## `to_csd()` - Decimal to CSD Conversion 🔢➡️ 

```python
def to_csd(decimal_value: float, places: int) -> str:
    """
    Converts decimal to CSD with specified decimal places
    
    Examples:
    >>> to_csd(28.5, 2)
    '+00-00.+0'
    >>> to_csd(-0.5, 2)
    '0.-0'
    """
```

**Key Logic** 🔑:
- Uses powers of 2 for conversion ⚡
- Handles both integer and fractional parts 🎯
- Special case for numbers < 1.0 🎭

---

## `to_csd_i()` - Integer Conversion 🔢➡️ 

```python
def to_csd_i(decimal_value: int) -> str:
    """
    Converts integers to CSD
    
    Examples:
    >>> to_csd_i(28)
    '+00-00'
    >>> to_csd_i(-0)
    '0'
    """
```

**Difference from `to_csd()`** 🆚:
- No decimal point handling ❌
- Pure integer operations 🔢

---

## `to_decimal()` - CSD to Decimal 🔄➡️ 

```python
def to_decimal(csd: str) -> float:
    """
    Converts CSD string back to decimal
    
    Examples:
    >>> to_decimal("+00-00.+")
    28.5
    >>> to_decimal("0.-")
    -0.5
    """
```

**Two-Step Process** 🔢:
1. Handle integer part (left of decimal) ⏫
2. Handle fractional part (right of decimal) ⏬

---

## Advanced: `to_csdnnz()` ✨🎛️ 

```python
def to_csdnnz(decimal_value: float, nnz: int) -> str:
    """
    CSD with limited non-zero digits
    
    Examples:
    >>> to_csdnnz(28.5, 4)
    '+00-00.+'
    >>> to_csdnnz(0.5, 4)
    '0.+'
    """
```

**Use Case** 💡:  
When you need to control the number of active components in hardware implementations 🏗️⚙️

---

## Testing & Validation 🧪✅ 

```python
if __name__ == "__main__":
    import doctest
    doctest.testmod()
```

**Built-in Examples** 🧩:
- Comprehensive doctests
- Covers edge cases
- Zero handling 0️⃣
- Sign conversions ➕➖

---

## Key Takeaways 💡🎯 

1. CSD provides efficient number representation 🚀
2. Python implementation handles:
   - Both integer and floating-point 🔢
   - Bidirectional conversion ↔️
   - Advanced constraints (non-zero digits) 🎛️
3. Applications in DSP and hardware design 🏗️

---

## Next Steps 🚀🔜 

1. Explore hardware implementations 🔍
2. Benchmark against binary representations
3. Extend to complex numbers ➕

**GitHub** 🐙: [csdigit](https://github.com/luk036/csdigit) 🔗

---

count: false
class: nord-dark, middle, center

.pull-left[

# Q & A 🎤

] .pull-right[

![Discussion](figs/questions-and-answers.svg)

]
