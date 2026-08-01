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

This section covers programming language topics with a focus on modern C++. Topics include C++17/20 features, design patterns, performance optimization, build tooling (CMake/CPM), documentation generation, and cross-language migration (Python → C++ → Rust). The content bridges theoretical concepts with practical implementations.

---

### 1. Modern C++ Features

| Topic                                     | Description                           |
| ----------------------------------------- | ------------------------------------- |
| [Modern C++ Make Life Easier](cpp17.html) | C++17/20 features for productivity    |
| [C++ Concepts](concepts.html)             | Template constraints and requirements |
| [C++ Performance Tips](cpptips.html)      | Performance optimization techniques   |
| [Downgrading C++](cppdowngrade.html)      | Modern features for older standards   |
| [Design Patterns](design_pattern.html)    | Object-oriented design patterns      |

> 📖 See: [cpp17.md](cpp17.md), [cpptips.md](cpptips.md), [concepts.md](concepts.md), [cppdowngrade.md](cppdowngrade.md), [design_pattern.md](design_pattern.md)

---

### 2. C++ Idioms & Generators

| Topic                                           | Description                              |
| ----------------------------------------------- | ---------------------------------------- |
| [Coroutine Generators](generator-remark.html)   | C++ coroutine-based generators           |
| [Bug or Feature?](bug-or-feature-remark.html)   | MSVC C4702 and the generator pattern     |
| [Header-Only → Source-Based](hpp2cpp-remark.html) | Refactoring C++ libraries              |

---

### 3. Build Systems & Tooling

| Topic                                    | Description                     |
| ---------------------------------------- | ------------------------------- |
| [Build Systems](buildsystem.md)          | CMake, make, bazel              |
| [CMake CPM Optimization](cmake-cpm-remark.html)          | Stop recompiling everything          |
| [CMake CPM Target Conflict](cmake-conflict-remark.html)  | Debugging a CPM target conflict      |
| [CMake CPM Conflict 2](cmake-conflict2-remark.html)      | The shadow variable debugging journey |
| [CMake vs XMake](xmake-vs-cmake-remark.html)             | Build tools in the AI era            |
| [JSON SAX Parsing](json-reader-remark.html)              | SAX parsing for Yosys netlists       |
| [Rust SAX JSON Parsing](json-reader-rs-remark.html)      | Rust SAX parsing for Yosys netlists  |

**Tool Categories:**

- **Build**: CMake, make, ninja
- **Testing**: Google Test, Catch2
- **Profiling**: gprof, perf, valgrind
- **Linting**: clang-tidy, cppcheck

> 📖 See: [buildsystem.md](buildsystem.md)

---

### 4. Python to C++ Migration

| Topic                                   | Description                         |
| --------------------------------------- | ----------------------------------- |
| [Python to C++](py2cpp.html)            | Migration strategies                |
| [From Python, C++ to Rust](from-python-cpp-rust-remark.html) | Cross-language migration journey |
| [Rust vs C++ for EDA](rust-cpp-remark.html) | Rust vs C++ type system comparison |
| [Rust vs C++](rust-vs-cpp-remark.html)  | Multi-project polyglot performance  |
| [Rust Macros](rust-macro-remark.html)   | Zero-cost abstraction for type specialization |

**Key Topics:**

- Memory management differences
- Type system differences
- Performance considerations

---

### 5. Documentation & Code Generation

| Topic                                              | Description                        |
| -------------------------------------------------- | ---------------------------------- |
| [C++ Documentation](doc-cpp-remark.html)           | Documenting C++ code               |
| [Equation Docs (C++)](doc-eqn-cpp-remark.html)     | LaTeX equations in C++ docs        |
| [Equation Docs (Python)](doc-eqn-py-remark.html)   | LaTeX equations in Python docs     |
| [Equation Docs (Rust)](doc-eqn-remark.html)        | KaTeX equations in Rust docs       |
| [Equation Docs (Both)](doc-eqn-both-remark.html)   | Cross-language equation docs       |
| [Figure Docs (Python)](doc-fig-py-remark.html)     | Matplotlib figures in docs         |
| [Figure Docs v2](doc-fig-py-remark-v2.html)        | Embedding figures (Python & Rust)  |

---

### 6. Memory Usage & Performance

| Topic                                              | Description                        |
| -------------------------------------------------- | ---------------------------------- |
| [Memory Usage in C++](memory-usage-cpp-remark.html) | Reducing memory usage in C++     |
| [Memory Usage in C++ (v1)](memory-usage-remark.html) | Reducing memory usage in C++ (earlier) |
| [Memory Usage in Python](memory-usage-py-remark.html) | Reducing memory usage in Python |
| [Memory Usage in Rust](memory-usage-rs-remark.html) | Reducing memory usage in Rust     |
| [ST vs MT](st-vs-mt-remark.html)                   | Parallelizing polynomial root-finding |
| [Google Benchmark vs nanobench](google-vs-nano-bench-remark.html) | Benchmarking framework comparison |
| [DEDUP & GAP-FILL](dedup-cpp-tests-remark.html)     | Systematic C++ test suite maintenance |

---

## 🗂️ File Structure

```text
proglang/
├── README.md                              # Course overview (this file)
├── index.html                             # Slide viewer (loads README.md)
│
├── ### Remark.js HTML Slides
├── bug-or-feature-remark.html             # Bug or Feature?
├── cmake-conflict-remark.html             # CMake CPM Target Conflict
├── cmake-conflict2-remark.html            # CMake CPM Conflict 2
├── cmake-cpm-remark.html                  # CMake CPM Optimization
├── dedup-cpp-tests-remark.html            # DEDUP & GAP-FILL
├── doc-cpp-remark.html                    # C++ Documentation
├── doc-eqn-remark.html                    # Equation Documentation (Rust)
├── doc-eqn-both-remark.html               # Cross-Language Equation Docs
├── doc-eqn-cpp-remark.html                # C++ Equation Docs
├── doc-eqn-py-remark.html                 # Python Equation Docs
├── doc-fig-py-remark.html                 # Python Figure Docs
├── doc-fig-py-remark-v2.html              # Python Figure Docs v2
├── from-python-cpp-rust-remark.html       # From Python, C++ to Rust
├── generator-remark.html                  # Generator Patterns
├── google-vs-nano-bench-remark.html       # Google Benchmark vs nanobench
├── hpp2cpp-remark.html                    # Header to C++ Implementation
├── json-reader-remark.html                # JSON SAX Parsing
├── json-reader-rs-remark.html             # Rust SAX JSON Parsing
├── memory-usage-remark.html               # Memory Usage in C++ (v1)
├── memory-usage-cpp-remark.html           # Memory Usage in C++
├── memory-usage-py-remark.html            # Memory Usage in Python
├── memory-usage-rs-remark.html            # Memory Usage in Rust
├── mistakes-remark.html                   # Common Coding Mistakes
├── rust-cpp-remark.html                   # Rust vs C++ for EDA
├── rust-macro-remark.html                 # Rust Macros
├── rust-vs-cpp-remark.html                # Rust vs C++
├── st-vs-mt-remark.html                   # ST vs MT
├── xmake-vs-cmake-remark.html             # CMake vs XMake
│
├── ### Legacy/Standalone HTML Slides
├── cpp17.html                             # Modern C++
├── cppdowngrade.html                      # Downgrading C++
├── concepts.html                          # C++ Concepts
├── cpptips.html                           # Performance Tips
├── design_pattern.html                    # Design Patterns
├── py2cpp.html                            # Python → C++
│
├── ### Content Notes & Reference
├── buildsystem.md                         # Build systems
├── cpp17.md                               # Modern C++ notes
├── cppdowngrade.md                        # C++ downgrade
├── cpptips.md                             # Performance tips notes
├── concepts.md                            # Concepts docs
├── CppNote.md                             # C++ notes
├── design_pattern.md                      # Design patterns docs
├── memory_usage.md                        # Memory usage notes
├── memory-usage-py-slides.md              # Python memory usage slides source
├── modules.md                             # C++ modules
├── py2cpp.md                              # Python → C++
├── reduce_memory.md                       # Reduce memory notes
│
└── ### Assets
    └── slides.css                         # Slide styles
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
