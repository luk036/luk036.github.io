layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Canonical Signed Digit (CSD) Conversion in Python 🎯🔢

@luk036 👨‍💻 · 2026 📅

---

### What is CSD? 🧐❓

- **Special number representation** using only: `0`, `+`, and `-` 🔢
- **Benefits** 💎:
- Efficient in digital signal processing ⚡
- Reduced hardware complexity 🏗️
- Optimal for certain arithmetic operations 🏆
- **A Powerful Number Representation System ✨**

**Example** 📝:
`28.5` → `"+00-00.+"`

---

### CSD Conversion Flow

.mermaid[

<pre>
graph LR
  Decimal[Decimal<br/>Number] --> Powers[Powers of 2]
  Powers --> Encode[Encode as<br/>0 / + / -]
  Encode --> CSDStr[CSD String]
  style Decimal fill:#2196f3
  style Powers fill:#4caf50
  style Encode fill:#ff9800
  style CSDStr fill:#9c27b0
</pre>

]

---

### Core Functions Overview 🛠️📋

1. `to_csd()` - Decimal to CSD (floating-point) 📌
2. `to_csd_i()` - Decimal to CSD (integer) 🔢
3. `to_decimal()` - CSD to decimal 🔄
4. `to_csdnnz()` - CSD with limited non-zero digits ✨

---

### Core Functions

.mermaid[

<pre>
graph LR
  to_csd[to_csd<br/>float to CSD]
  to_csd_i[to_csd_i<br/>int to CSD]
  to_decimal[to_decimal<br/>CSD to float]
  to_csdnnz[to_csdnnz<br/>limited non-zero]
  to_csd --> Format[Expression<br/>Format]
  to_csd_i --> Format
  to_decimal --> Format
  to_csdnnz --> Format
  style to_csd fill:#4caf50
  style to_csd_i fill:#ff9800
  style to_decimal fill:#2196f3
  style to_csdnnz fill:#9c27b0
  style Format fill:#f44336
</pre>

]

---

### `to_csd()` - Decimal to CSD Conversion 🔢➡️

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

### `to_csd_i()` - Integer Conversion 🔢➡️

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

### `to_decimal()` - CSD to Decimal 🔄➡️

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

### Advanced: `to_csdnnz()` ✨🎛️

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

### Testing & Validation 🧪✅

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

### Key Takeaways 💡🎯

1. CSD provides efficient number representation 🚀
2. Python implementation handles:
   - Both integer and floating-point 🔢
   - Bidirectional conversion ↔️
   - Advanced constraints (non-zero digits) 🎛️
3. Applications in DSP and hardware design 🏗️

---

### Next Steps 🚀🔜

1. Explore hardware implementations 🔍
2. Benchmark against binary representations
3. Extend to complex numbers ➕

**GitHub** 🐙: [csdigit](https://github.com/luk036/csdigit) 🔗

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
