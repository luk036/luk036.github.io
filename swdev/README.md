layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Programming Language

@luk036 👨‍💻 · 2026 📅

---

### 📋 Agenda

.pull-left[

**C++ Features** 🧠
- Modern C++
- Concepts
- Perf

**Tools & Migration** 🛠
- Dev Tools
- Py2Cpp
- Rust vs C++

]
.pull-right[

**Documentation** 📝
- Docs Gen
- Best Practices

]

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
| [Rust to C++](rust-cpp-remark.html)     | Rust vs C++ type system comparison  |
| [Modern C++ Downgrade](cppdowngrade.md) | Modern features for older standards |

**Key Topics:**

- Memory management differences
- Type system differences
- Performance considerations

---

### 6. Git & CI Workflows

| Topic                                              | Description                     |
| -------------------------------------------------- | ------------------------------- |
| [Git & GitHub CI](git-gh-ci-remark.html)           | Version control and CI basics   |
| [Advanced Git & CI](git-gh-ci-advanced-remark.html) | Advanced workflows and tooling  |

---

### 7. Documentation & Code Generation

| Topic                                              | Description                        |
| -------------------------------------------------- | ---------------------------------- |
| [C++ Documentation](doc-cpp-remark.html)           | Documenting C++ code               |
| [Equation Docs (C++)](doc-eqn-cpp-remark.html)     | LaTeX equations in C++ docs        |
| [Equation Docs (Python)](doc-eqn-py-remark.html)   | LaTeX equations in Python docs     |
| [Equation Docs (Both)](doc-eqn-both-remark.html)   | Cross-language equation docs       |
| [Figure Docs (Python)](doc-fig-py-remark.html)     | Matplotlib figures in docs         |

---

### 8. Code Quality & Best Practices

| Topic                                              | Description                        |
| -------------------------------------------------- | ---------------------------------- |
| [Common Mistakes](mistakes-remark.html)            | Lessons learned in coding          |
| [Remove Duplicate Code](remove-duplicate-remark.html) | DRY principles and refactoring  |
| [AI Validation](ai-validate-remark.html)           | AI-assisted code validation        |

---

### 9. Video Processing & Tooling

| Topic                                              | Description                        |
| -------------------------------------------------- | ---------------------------------- |
| [Video Processing](video-processing-remark.html)   | FFmpeg-based video processing      |
| [Video Processing (中文)](video-processing-zh-remark.html) | 视频处理技术              |
| [xTensor Library](xtensor-remark.html)             | Multi-dimensional arrays in C++    |
| [Cocotb HDL Verification](cocotb-hdl-remark.html)  | Python-based HDL verification      |
| [Hyperframes](hyerframes-remark.html)             | Hyperframe data structure           |

---

## 🗂️ File Structure

```text
proglang/
├── README.md                              # Course overview (this file)
├── index.html                             # Slide viewer (loads README.md)
│
├── ### Remark.js HTML Slides
├── bug-or-feature-remark.html             # Bug or Feature?
├── ec-gen-remark.html                     # EC Generator
├── generator-remark.html                  # Generator Patterns
├── git-gh-ci-remark.html                  # Git & GitHub CI
├── git-gh-ci-advanced-remark.html         # Advanced Git & CI
├── hpp2cpp-remark.html                    # Header to C++ Implementation
├── doc-cpp-remark.html                    # C++ Documentation
├── doc-eqn-remark.html                    # Equation Documentation
├── doc-eqn-both-remark.html               # Cross-Language Equation Docs
├── doc-eqn-cpp-remark.html                # C++ Equation Docs
├── doc-eqn-py-remark.html                 # Python Equation Docs
├── doc-fig-py-remark.html                 # Python Figure Docs
├── doc-fig-py-remark-v2.html              # Python Figure Docs v2
├── mistakes-remark.html                   # Common Coding Mistakes
├── remove-duplicate-remark.html           # Remove Duplicate Code
├── ai-validate-remark.html                # AI-Assisted Validation
├── video-processing-remark.html           # Video Processing
├── video-processing-zh-remark.html        # Video Processing (中文)
├── xtensor-remark.html                    # xTensor Library
├── rust-cpp-remark.html                   # Rust vs C++
├── cocotb-hdl-remark.html                 # Cocotb HDL Verification
├── hyerframes-remark.html                 # Hyperframe Data Structure
│
├── ### Legacy/Standalone HTML Slides
├── pldl.html                              # Primal-Dual Algorithms
├── ecgen.html                             # Coroutine Generator
├── design_pattern.html                    # Design Patterns
├── cpptips.html                           # Performance Tips
├── cpp17.html                             # Modern C++
├── concepts.html                          # C++ Concepts
├── swdev.html                             # Development Tools
│
├── ### Content Notes & Reference
├── pldl.md                                # PD notes
├── design_pattern.md                      # Design patterns docs
├── cpptips.md                             # Performance tips notes
├── cpp17.md                               # Modern C++ notes
├── concepts.md                            # Concepts docs
├── swdev.md                               # Dev tools notes
├── buildsystem.md                         # Build systems
├── dependency.md                          # Dependencies
├── modules.md                             # C++ modules
├── py2cpp.md                              # Python → C++
├── cppdowngrade.md                        # C++ downgrade
├── CppNote.md                             # C++ notes
├── ec-gen.md                              # EC generator notes
├── ecgen.md                               # Generator notes
│
└── ### Assets
    ├── slides.css                         # Slide styles
    ├── mvc/                               # MVC examples
    ├── test_dist.cpp                      # Test distribution
    ├── test_intv.cpp                      # Test interval
    └── testratio.cpp                      # Test ratio
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
