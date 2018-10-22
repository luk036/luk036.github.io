class: middle, center

# Basic Python Working Flow

Wai-Shing Luk

2017-06-16

---

## Installation on Ubuntu System

-By default, Ubuntu already installed python and python3

-   sudo apt install (Tools)
    -   python-pip, python-tk

-   `sudo pip install --upgrade pip`

-   sudo pip install (Modules)
    -   numpy scipy matplotlib (replace Matlab)
    -   sympy (symbolic toolbox)
    -   cvxpy, networkx
    -   pylint pytest pytest-cov (software quality check)
    -   scikit-learn tensorflow (machine learning)

---

## Extensions of Visual Studio Code

-   Code Runner
-   Python
-   `ctrl-alt-n` to run a program

```terminal
[Running] python "/home/ubuntu/Cubstore/proj_geom/pgpy/proj_geom.py"
True
False
0
0

[Done] exited with code=0 in 36.304 seconds
```

---

## Unit Test

```shell
  pytest
  pytest --cov=./
```

---

class: impact

Questions?
==========
