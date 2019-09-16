title: Lecture 2b: Software Development Tools
class: animation-fade
layout: true

---

class: center, middle

{{title}}
=========

Wai-Shing Luk

2019-09-18

---

Editor/IDE
----------

-   Past: vi+ctag, emacs+etag, sublime text

-   Recommended: Visual Studio Code (vscode) + extensions
    -   support git, python, markdown, C++, cmake...

-   Alternatvie: CLion, Qt Creator

---

Version Control
---------------

-   Past: cvs, sccs, clearcase, svn (subversion control)

-   Recommended: git
    -   git status
    -   git pull
    -   git add .
    -   git mv 'filefrom' 'fileto'
    -   git commit -m "message"
    -   git push
    -   git clone --recursive <https://github.com/user/repository.git>
    -   git submodule add <https://github.com/user/repository.git>

---

Programming Language
--------------------

-   Past: Fortran, Pascal, C, Matlab, C#, Java

-   Recommended: C++17, Python, Javascript

    -   Python, then C++ (, then C)

---

Build Tool
----------

-   Past: make, automake, qmake

-   Recommended:
    -   Python: setuptools
    -   C++: cmake, ninja

---

Static Analysis
---------------

-   Recommended:

    -   Python: flake8 (or pylint)

    -   C++: clang-tidy

---

Coding Style
------------

-   Recommended:

    -   Python: yapf (or autopep8)

    -   C++: clang-format
        -   clang-format -i file.cpp


---

Unit Testing
------------

-   Past: cppunit, cute,
    [gtest](https://github.com/google/googletest.git)

-   Recommended:
    -   Python: pytest
    -   C++: catch2

---

Code Coverage
-------------

-   Past: gcov

-   Recommended: codecov.io

    -   [Python](https://github.com/codecov/example-python)
        -   python -m pytest --cov=./

    -   [C++](https://github.com/codecov/example-cpp11-cmake)
        -   lcov

---

Profiling
---------

-   Past: gprof

-   Recommended:

    -   C++: valgrind --tool=cachegrind + KCachegrind

    -   Python: cProfile (built-in module)

---

Benchmarking
------------

-   Recommended:

    -   C++: Google Benchmark ???

    -   Python: pytest-benchmark

---

Code Quality
------------

-   Recommended:

    -   C++: clang-tidy, cppcheck, valgrind

    -   Python: flakes, pre-commit, codefactor.io

---

Documentation
-------------

-   Recommended:

    -   Python: sphinx, Jupyter

    -   C++: doxygen
        -   doxygen -s -g; doxygen

---

Team Communication
------------------

-   Past: email

-   Recommended: Slack

---

Repositories
------------

-   Past: proprietary

-   Recommended: GitHub

-   Alternatives:
    -   GitLab, Bitbucket

???

China

---

Continous Integration
---------------------

-   Recommended: Travis CI

-   Alterative: Circle CI

---

VSCode's extensions
-------------------

-   Recommended:
    -   Code Runner
    -   Gitconfig Syntax
    -   Travis CI Status
    -   C/C++, CMake, CMake Tools
    -   Doxygen Documentation Generator
    -   Python, autoDocstring
    -   Markdown Preview Enhanced, markdownlint

---

YouTube Channels
----------------

-   [GitHub Training & Guides](https://www.youtube.com/channel/UCP7RrmoueENv9TZts3HXXtw)

-   [Slack](https://www.youtube.com/channel/UCY3YECgeBcLCzIrFLP4gblw)

-   [Enthought](https://www.youtube.com/channel/UCkhm72fuzkS9fYGlGpEmj7A)

---

Libraries
---------

-   Recommended:

    -   Python: networkx, tensorflow

    -   C++: fmt, xtensor, range-v3, catch,
        [JSON](https://github.com/nlohmann/json)

---

📚 Further Reading
------------------

-   
-   [KCachegrind](https://kcachegrind.github.io/html/Home.html)

---

class: center, middle

Q & A 🗣️
==========
