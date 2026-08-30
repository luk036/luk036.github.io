layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Software Development

@luk036 👨‍💻 · 2026 📅

---

### 📋 Agenda

.pull-left[

**Git & CI** 🔄
- Git + gh + CI
- Advanced Workflows

**AI-Era Dev** 🤖
- Dev Flow with AI
- AI Validation

]

.pull-right[

**Code Quality** 🧹
- Mistakes
- Remove Duplicate

**Video & Verification** 🎬
- Video Processing
- HDL Verification

]

---

## 📚 Overview

This section covers software development workflows and tooling: version control and CI automation, AI-era development practices, code quality, video processing pipelines, and verification tools like Cocotb.

---

### 1. Git & CI Workflows

| Topic                                              | Description                     |
| -------------------------------------------------- | ------------------------------- |
| [Git & GitHub CI](git-gh-ci-remark.html)           | Version control and CI basics   |
| [Advanced Git & CI](git-gh-ci-advanced-remark.html) | Advanced workflows and tooling  |

---

### 2. AI-Era Development

| Topic                                              | Description                     |
| -------------------------------------------------- | ------------------------------- |
| [Software Development Flow in AI Era](swdev-flow-ai-remark.html) | Development workflow with AI tools |
| [Validation in AI Era](ai-validate-remark.html)    | AI-assisted code validation     |

---

### 3. Code Quality & Best Practices

| Topic                                              | Description                     |
| -------------------------------------------------- | ------------------------------- |
| [Common Mistakes](mistakes-remark.html)            | Lessons learned in coding       |
| [Remove Duplicate Code](remove-duplicate-remark.html) | DRY principles and refactoring |
| [Refactoring Part 1](refactor-remark.html)  | Factory · Builder · Template Method (physdes & LDS) |
| [Refactoring Part 2](refactor2-remark.html) | Strategy · Factory · Template Method (netlistx & ckpttn) |
| [Refactoring Part 3](refactor3-remark.html) | Strategy/Bridge · State · Facade (ellalgo & lmi-solver) |
| [Refactoring Part 4](refactor4-remark.html) | Execution policies · facades · dedup (ginger & multiplierless) |
| [Refactoring Part 5](refactor5-remark.html) | Howard skeleton · adapters · releases (digraphx & netoptim) |
| [Design is a Trade-off (Part 6)](design-tradeoff-remark.html) | Retrospective across Parts 1–5: the trade-off of every pattern — and the flag that was reverted |

---

### 4. Video Processing & Verification

| Topic                                              | Description                     |
| -------------------------------------------------- | ------------------------------- |
| [Video Processing](video-processing-remark.html)   | FFmpeg-based video processing   |
| [Video Processing (中文)](video-processing-zh-remark.html) | 视频处理技术             |
| [Cocotb HDL Verification](cocotb-hdl-remark.html)  | Python-based HDL verification   |
| [Hyperframes](hyerframes-remark.html)             | Hyperframe data structure       |
| [xTensor Library](xtensor-remark.html)             | Multi-dimensional arrays in C++ |

---

## 🗂️ File Structure

```text
swdev/
├── README.md                              # Course overview (this file)
├── index.html                             # Slide viewer (loads README.md)
│
├── ### Remark.js HTML Slides
├── ai-validate-remark.html                # Validation in AI Era
├── cocotb-hdl-remark.html                 # Cocotb HDL Verification
├── design-tradeoff-remark.html            # Design is a Trade-off (Part 6)
├── ec-gen-remark.html                     # EC Generator
├── git-gh-ci-remark.html                  # Git & GitHub CI
├── git-gh-ci-advanced-remark.html         # Advanced Git & CI
├── hyerframes-remark.html                 # Hyperframe Data Structure
├── mistakes-remark.html                   # Common Coding Mistakes
├── pldl.html                              # Primal-Dual Algorithms
├── refactor-remark.html                   # Refactoring Part 1 (physdes & LDS)
├── refactor2-remark.html                  # Refactoring Part 2 (netlistx & ckpttn)
├── refactor3-remark.html                  # Refactoring Part 3 (ellalgo & lmi-solver)
├── refactor4-remark.html                  # Refactoring Part 4 (ginger & multiplierless)
├── refactor5-remark.html                  # Refactoring Part 5 (digraphx & netoptim)
├── remove-duplicate-remark.html           # Remove Duplicate Code
├── swdev.html                             # Development Tools
├── swdev-flow-ai-remark.html              # Software Development Flow in AI Era
├── video-processing-remark.html           # Video Processing
├── video-processing-zh-remark.html        # Video Processing (中文)
├── xtensor-remark.html                    # xTensor Library
│
├── ### Content Notes & Reference
├── dependency.md                          # Dependencies
├── ec-gen.md                              # EC generator notes
├── modules.md                             # C++ modules
├── pldl.md                                # PD notes
├── swdev.md                               # Dev tools notes
│
└── ### Assets
    ├── slides.css                         # Slide styles
    └── mvc/                               # MVC examples
```

---

## 📖 Key References

### Books

- _Effective Modern C++_ by Scott Meyers
- _C++ Concurrency in Action_ by Anthony Williams

### Online Resources

- cppreference.com
- isocpp.org
- Modern C++ guidelines (github.com/isocpp/CppCoreGuidelines)

---

count: false
class: nord-dark, middle, center

# Q&A 🎤
