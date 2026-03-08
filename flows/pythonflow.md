title: Basic Python Flow
class: animation-fade
layout: true

<!-- This slide will serve as the base layout for all your slides -->

.bottom-bar[
{{title}}
]

---

class: impact

# {{title}}

@luk036 👨‍💻

---

## 🛠️ Installation on Ubuntu System

- By default, Ubuntu already has Python and Python3 installed

### System Tools

- `sudo apt install` (Tools)
  - python-pip, python-tk
- `sudo pip install --upgrade pip`

### Python Modules

- `sudo pip install` (Modules)
  - **numpy, scipy, matplotlib** - Replace Matlab functionality
  - **sympy** - Symbolic mathematics toolbox
  - **cvxpy, networkx** - Optimization and graph analysis
  - **pylint, pytest, pytest-cov** - Software quality and code coverage
  - **scikit-learn, tensorflow** - Machine learning frameworks 🤖

---

## Install Python via Scoop (on Windows 10)

### Prerequisites

- Install the Scoop package manager (and add extra buckets if needed)
- Install Python and related packages

### Installation Commands

```powershell
PS E:\> scoop install python
```

### Additional Tools

- For the latest version of Pandoc: `scoop install pandoc`

---

## 🧩 Essential Visual Studio Code Extensions

### Required Extensions

- **Code Runner** - Execute code snippets with shortcuts
- **Python** 🐍 - Official Python extension with IntelliSense

### Usage

- Use `Ctrl+Alt+N` to run a Python program directly

### Example Output

```terminal
[Running] python "/home/ubuntu/Cubstore/proj_geom/pgpy/proj_geom.py"
True
False
0
0

[Done] exited with code=0 in 36.304 seconds
```

---

## Unit Testing

### Running Tests

```shell
pytest
```

### Code Coverage

```shell
pytest --cov=./
```

This command generates a coverage report showing which parts of your code are tested.

---

class: impact

# Q&A 🎤
