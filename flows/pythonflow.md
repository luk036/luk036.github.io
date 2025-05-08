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

@luk036 👨🏻‍🏫

---

## 🛠️ Installation on Ubuntu System

-By default, Ubuntu already installed python and python3

- sudo apt install (Tools)
  - python-pip, python-tk
- `sudo pip install --upgrade pip`

- sudo pip install (Modules)
  - numpy scipy matplotlib (replace Matlab)
  - sympy (symbolic toolbox)
  - cvxpy, networkx
  - pylint pytest pytest-cov (software quality check)
  - scikit-learn tensorflow (machine learning 🤖)

---

## Install python via Scoop (on Windows 10)

- In order to install the latest version of pandoc on Windows 10, the
  easiest way is to install the scoop system (and add extra bucket)
- Install the pandoc package

```{.powershell}
PS E:\>  scoop install python
```

---

## 🧩 Extensions of Visual Studio Code

- Code Runner
- Python 🐍
- `ctrl-alt-n` to run a program

```{.terminal}
[Running] python "/home/ubuntu/Cubstore/proj_geom/pgpy/proj_geom.py"
True
False
0
0

[Done] exited with code=0 in 36.304 seconds
```

---

## Unit Test

```{.shell}
  pytest
  pytest --cov=./
```

---

class: impact

# Q & A 🎤
