title: Software Development Tools
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

## Editor/IDE

- Past: vi+ctag, emacs+etag, sublime text

- Recommended: vscode + extensions

  - support git, python, markdown, C++, cmake...

- Alternatvie: Qt Creator

---

## Version Control

- Past: cvs, sccs, clearcase, svn (subversion control)

- Recommended: git
  - git status
  - git pull
  - git add .
  - git mv filefrom fileto
  - git commit -m "message"
  - git push
  - git clone --recursive <https://github.com/user/repository.git>
  - git submodule add <https://github.com/user/repository.git>

---

## Programming Language

- Past: Fortran, Pascal, C, Matlab, C\#, Java

- Recommended: C++17, Python, Javascript

---

## Build Tool

- Past: make, automake, qmake

- Recommended:
  - C++: cmake
  - Python: N/A

---

## Static Analysis

- Recommended:
  - C++: clang-tidy
    - sudo apt install clang-tidy (Ubuntu)
  - Python: pylint
    - Windows:
      - python -m pip install pylint
    - Ubuntu:
      - sudo apt install pylint

---

## Coding Style

- Recommended:

  - C++: clang-format

    - sudo apt install clang-format (Ubuntu)
    - clang-format -i file.cpp

  - Python: autopep8
    - python -m pip install autopep8
    - python -m autopep8 -i file.py

---

## Unit Testing

- Past: cppunit, cute,
  [gtest](https://github.com/google/googletest.git)

- Recommended:

  - C++: catch2

  - Python: pytest
    - python -m pip install pytest
    - python -m pytest

---

## ☂️ Code Coverage

- Past: gcov

- Recommended: codecov.io

  - [C++](https://github.com/codecov/example-cpp11-cmake) ???

  - [Python](https://github.com/codecov/example-python):
    - python -m pip install pytest-cov
    - python -m pytest --cov=./

---

## Profiling

- Past: gprof

- Recommended:
  - C++: ???
  - Python: cProfile (built-in module)

---

## 📊 Benchmarking

- Recommended:

  - C++: Google Benchmark 📊 ???

  - Python: pytest-benchmark
    - python -m pip install pytest-benchmark

---

## Code Quality

- Recommended:

  - C++: ???

  - Python: code climate

---

## 📝 Documentation

- Recommended:

  - Python: sphinx???, Jupyter???

    - python -m pip install sphinx
    - python -m pip install jupyter

  - C++: doxygen
    - sudo apt install doxygen graphviz
    - doxygen -s -g; doxygen

---

## Team Communication

- Past: email
- Recommended: Slack

---

## Repositories

- Recommended: GitHub

- Alternatives:
  - GitLab，Bitbucket, china???

---

## Continous Integration

- Recommended: Travis CI
- Alterative: Circle CI, Docker🐋 ???

---

## vscode's extensions

- Recommended:
  - Code Runner
  - Gitconfig Syntax
  - Travis CI Status
  - C/C++, CMake, CMake Tools
  - Doxygen Documentation Generator
  - Clang-Format, cppcheck
  - Python, Python-autopep8, autoDocstring

---

## YouTube Channels

- [GitHub Training &
  Guides](https://www.youtube.com/channel/UCP7RrmoueENv9TZts3HXXtw)
- [Slack](https://www.youtube.com/channel/UCY3YECgeBcLCzIrFLP4gblw)
- [Enthought](https://www.youtube.com/channel/UCkhm72fuzkS9fYGlGpEmj7A)

---

## Libraries

- Recommended:

  - C++: fmt, xtensor, range-v3, catch,
    [JSON](https://github.com/nlohmann/json)

  - Python: networkx, tensorflow

---

## 📚 Further Reading

- [Pro Python Best Practices (2017)](https://rd.springer.com/book/10.1007/978-1-4842-2241-6)

---

class: impact

# Q & A 🙋
