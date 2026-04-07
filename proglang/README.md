layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Programming Language

@luk036 👨‍💻

---

## 📚 Overview

This section covers programming language topics with a focus on modern C++. Topics include design patterns, performance optimization, C++17/20 features, software development tools, and combinatorial algorithms. The content bridges theoretical concepts with practical implementations.

---


### 1. Modern C++ Features

| Topic                                     | Description                           |
| ----------------------------------------- | ------------------------------------- |
| [Modern C++ Make Life Easier](cpp17.html) | C++17/20 features for productivity    |
| [C++ Concepts](concepts.html)             | Template constraints and requirements |
| [C++ Performance Tips](cpptips.html)      | Performance optimization techniques   |

> 📖 See: [cpp17.md](cpp17.md), [cpptips.md](cpptips.md), [concepts.md](concepts.md)

---

### 2. Design Patterns in C++

| Topic                                  | Description                     |
| -------------------------------------- | ------------------------------- |
| [Design Patterns](design_pattern.html) | Object-oriented design patterns |

**Principles:**

- Favor composition over inheritance
- Program to interfaces, not implementations

> 📖 See: [design_pattern.md](design_pattern.md)

---

### 3. Algorithms & Combinatorics

| Topic                                           | Description                              |
| ----------------------------------------------- | ---------------------------------------- |
| [Coroutine & Enumerative Generator](ecgen.html) | Coroutine-based combinatorial generation |
| [Primal-Dual Algorithms](pldl.html)             | Optimization algorithms                  |

**Key Concepts:**

- **Coroutine-based generators**: Yield values without allocation
- **Enumeration combinators**: Compose generation logic
- **Primal-dual methods**: Iterative optimization with guarantees

> 📖 See: [ecgen.md](ecgen.md), [pldl.md](pldl.md)

---

### 4. Software Development Tools

| Topic                                    | Description                     |
| ---------------------------------------- | ------------------------------- |
| [Software Development Tools](swdev.html) | Build systems, package managers |
| [Build Systems](buildsystem.md)          | CMake, make, bazel              |
| [Dependency Management](dependency.md)   | Library management              |

**Tool Categories:**

- **Build**: CMake, make, ninja
- **Testing**: Google Test, Catch2
- **Profiling**: gprof, perf, valgrind
- **Linting**: clang-tidy, cppcheck

> 📖 See: [swdev.md](swdev.md), [buildsystem.md](buildsystem.md)

---

### 5. Python to C++ Migration

| Topic                                   | Description                         |
| --------------------------------------- | ----------------------------------- |
| [Python to C++](py2cpp.html)            | Migration strategies                |
| [Modern C++ Downgrade](cppdowngrade.md) | Modern features for older standards |

**Key Topics:**

- Memory management differences
- Type system differences
- Performance considerations

---

## 🗂️ File Structure

```
proglang/
├── README.md                 # This file
├── pldl.html                 # Primal-Dual Algorithms
├── pldl.md                   # Notes
├── ecgen.html                # Coroutine Generator
├── ec-gen.md                 # Generator notes
├── design_pattern.html       # Design Patterns
├── design_pattern.md        # Documentation
├── cpptips.html             # Performance Tips
├── cpptips.md               # Notes
├── cpp17.html               # Modern C++
├── cpp17.md                 # Notes
├── concepts.html            # C++ Concepts
├── concepts.md             # Documentation
├── swdev.html              # Development Tools
├── swdev.md                # Notes
├── buildsystem.md          # Build Systems
├── dependency.md           # Dependencies
├── modules.md              # C++ Modules
├── py2cpp.md               # Python → C++
├── cppdowngrade.md         # Feature Downgrade
├── CppNote.md              # C++ Notes
└── ecgen.md                # More generator notes
```

---

## 📖 Key References

### Books

- _Design Patterns: Elements of Reusable Object-Oriented Software_ (Gang of Four)
- _Effective Modern C++_ by Scott Meyers
- _C++ Concurrency in Action_ by Anthony Williams

### Online Resources

- cppreference.com
- isocpp.org
- Modern C++ guidelines (github.com/isocpp/CppCoreGuidelines)

---

## 🛠️ Code Examples

### Performance: std::move

```cpp
// Before: copies data
return {1, BigData};

// After: moves data (no copy)
return {1, std::move(BigData)};
```

### Modern C++17 Template

```cpp
// C++98: verbose type aliases
typedef typename graph_traits<Graph>::vertex_descriptor Vertex;

// C++17: auto in templates
void operator()(const auto &v) const { ... }
```

---

### Design Pattern: Strategy

```cpp
// Define interface
struct DelayCalc {
    virtual double calc() = 0;
    virtual ~DelayCalc() = default;
};

// Implementations
struct LinearCalc : DelayCalc {
    double calc() override;
};

struct ElmoreCalc : DelayCalc {
    double calc() override;
};
```

---

count: false
class: nord-dark, middle, center

# Q&A 🎤
