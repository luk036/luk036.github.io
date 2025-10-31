
## **Slide 1: Title Slide**

# Type Annotations in Python
### Writing Cleaner, Safer Code
*Presented by: [Your Name]*
*Date: [Date]*

---

## **Slide 2: What Are We Covering?**
- ✅ What are type annotations?
- ✅ Why should you use them?
- ✅ How to implement them
- ✅ Tools and best practices
- ✅ Future of Python typing

*(20 minutes total)*

---

## **Slide 3: What Are Type Annotations?**
```python
def round(number: float) -> int:
    # Takes a float, returns an integer
    ...
```

**Simple concept:** Adding type hints to your function parameters and return values

**Key point:** Python remains dynamically typed - these are *hints*, not enforcement

---

## **Slide 4: Basic Syntax Examples**
```python
# Variable annotations
name: str = "Alice"
age: int = 30
scores: list[float] = [95.5, 87.0, 92.5]

# Function annotations
def greet(name: str) -> str:
    return f"Hello, {name}"

def process_items(items: list[str]) -> int:
    return len(items)
```

---

## **Slide 5: Advanced Types - Generics**
```python
from typing import TYPE_CHECKING, Any, Generic, TypeVar

# Type variables for generic programming
T1 = TypeVar("T1", int, float)
T2 = TypeVar("T2", int, float)

class Vector2(Generic[T1, T2]):
    def __init__(self, x: T1, y: T2):
        self.x = x
        self.y = y
```

**Generic classes** work with multiple types while maintaining type safety

---

## **Slide 6: The Big Difference from Rust**
# **Type Annotations are Optional**

| Python | Rust |
|--------|------|
| **Optional hints** | **Mandatory** |
| Runtime ignores them | Compile-time enforced |
| Gradual adoption | Strict from start |

**Python philosophy:** "We're all consenting adults here"

---

## **Slide 7: Why Use Type Annotations?**
### **Three Key Benefits**

1. **Easier to find bugs**
2. **Better documentation**  
3. **Easier for AI to convert into other languages**

---

## **Slide 8: Benefit 1 - Catch Bugs Early**
```python
# Without type hints
def calculate_total(price, quantity):
    return price * quantity

# What if someone passes string "10" as quantity?
```

```python
# With type hints
def calculate_total(price: float, quantity: int) -> float:
    return price * quantity

# Type checker catches: calculate_total(99.99, "10")
```

**Static analysis tools catch errors before runtime!**

---

## **Slide 9: Benefit 2 - Better Documentation**
```python
# Which is clearer?
def process_data(data, config):
    ...

# VS
def process_data(data: dict[str, Any], config: Config) -> ProcessResult:
    ...
```

**Type hints are:**
- Always up-to-date
- Machine-readable
- IDE-friendly (autocomplete, hover docs)

---

## **Slide 10: Benefit 3 - AI & Code Conversion**
```python
def parse_user_data(user_data: dict[str, Any]) -> User:
    name: str = user_data["name"]
    email: str = user_data["email"]
    age: int = user_data.get("age", 0)
    return User(name, email, age)
```

**Clear types help AI:**
- Understand code intent
- Convert to other languages (TypeScript, Rust, etc.)
- Generate better documentation

---

## **Slide 11: How to Get Started - Tools**
### **MyPy: The Main Type Checker**

```bash
# Install mypy
pip install mypy

# Check your code
mypy src/
```

```bash
# Sample output
src/main.py:15: error: Argument 1 to "calculate_total" 
has incompatible type "str"; expected "int"
Found 1 error in 1 file (checked 15 source files)
```

---

## **Slide 12: Configuration - mypy.ini**
```ini
[mypy]
python_version = 3.11
warn_return_any = True
warn_unused_configs = True
disallow_untyped_defs = True

[mypy-tests.*]
ignore_missing_imports = True
```

**Configure strictness levels** to match your team's preferences

---

## **Slide 13: Package Distribution - py.typed**
**For libraries:** Add empty `py.typed` file to your package

```
mypackage/
├── __init__.py
├── py.typed      # ← This file!
└── modules.py
```

**Signals to type checkers:** "This package has type information"

---

## **Slide 14: Handling Tricky Cases**
```python
# When you know better than the type checker
result = some_complex_function()  # type: ignore

# Or be specific
result = some_function()  # type: ignore[arg-type]
```

**Use `# type: ignore` sparingly** - only when necessary!

---

## **Slide 15: Forward References (Before 3.14)**
```python
class Point:
    def translate(self, x: int, y: int) -> "Point":
        # Return type needs quotes - Point isn't defined yet!
        return Point(self.x + x, self.y + y)
```

**Problem:** Circular references and self-references

---

## **Slide 16: Python 3.14+ Improvements**
```python
class Point:
    def translate(self, x: int, y: int) -> Point:
        # No quotes needed!
        return Point(self.x + x, self.y + y)
```

**Python 3.14+:** Forward references work without quotes in most cases

---

## **Slide 17: Adoption Strategy**
### **Start Small & Gradual**

1. **New code:** Always add type hints
2. **Critical modules:** Add types first
3. **Legacy code:** Add types when you touch files
4. **Team agreement:** Decide on strictness level

**Remember:** You can mix typed and untyped code!

---

## **Slide 18: Common Pitfalls**
```python
# Don't overcomplicate!
from typing import Union, Optional, List, Dict

# Simple is better
def find_user(user_id: int) -> User | None:
    ...

# Use built-in types (Python 3.9+)
def process_items(items: list[str]) -> dict[str, int]:
    ...
```

---

## **Slide 19: Summary**
- ✅ **Type annotations** = optional type hints
- ✅ **Benefits:** Fewer bugs, better docs, AI-friendly
- ✅ **Tools:** MyPy for checking, config for control
- ✅ **Strategy:** Gradual adoption, team agreement

**The goal:** Write maintainable, understandable code

---

## **Slide 20: Questions & Next Steps**
### **Try It Today!**

```bash
pip install mypy
mypy your_script.py
```

