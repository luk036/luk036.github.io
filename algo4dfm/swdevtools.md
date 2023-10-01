title: Lecture 2b: Software Development Tools
layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# {{title}}

@luk036

2022-09-14

---

## Editor/IDE

- Past: vi+ctag, emacs+etag, sublime text

- Recommended: Visual Studio Code (vscode) + extensions

  - support git, python, markdown, C++, cmake...

- Alternatvie: CLion, Qt Creator

---

## Version Control

- Past: cvs, sccs, clearcase, svn (subversion control)

- Recommended: git
  - git status
  - git pull
  - git add .
  - git mv 'filefrom' 'fileto'
  - git commit -m "message"
  - git push
  - git clone --recursive <https://github.com/user/repository.git>
  - git submodule add <https://github.com/user/repository.git>

---

## Example - git status

.font-sm.mb-xs[

```terminal
ubuntu@ubuntu:~/github/ellpy$ git status
On branch master
Your branch is up to date with 'origin/master'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	<span style="color:red;">modified:   .pytest_cache/v/cache/lastfailed</span>
	<span style="color:red;">modified:   .pytest_cache/v/cache/nodeids</span>

Untracked files:
  (use "git add <file>..." to include in what will be committed)

	<span style="color:red;">ellpy/</span>
	<span style="color:red;">test.html</span>

no changes added to commit (use "git add" and/or "git commit -a")
```

]

---

## Example - git pull

.font-sm.mb-xs[

```terminal
lubuntu@lubuntu:~/github/luk036.github.io$ git pull
remote: Enumerating objects: 29, done.
remote: Counting objects: 100% (29/29), done.
remote: Compressing objects: 100% (8/8), done.
remote: Total 19 (delta 14), reused 16 (delta 11), pack-reused 0
Unpacking objects: 100% (19/19), done.
From ssh://github.com/luk036/luk036.github.io
   461191c..d335266  master     -> origin/master
Updating 461191c..d335266
Fast-forward
 algo4dfm/swdevtips.html  |  36 <span style="color:green;">++++++++</span><span style="color:red;">--</span>
 algo4dfm/swdevtips.md    |  27 <span style="color:green;">+++++++</span><span style="color:red;">-</span>
 algo4dfm/swdevtools.html |  22 <span style="color:green;">+++++</span><span style="color:red;">--</span>
 algo4dfm/swdevtools.md   |  89 <span style="color:green;">++++++++++++++++++++++++</span><span style="color:red;">-</span>
 markdown/remark.html     |  45 <span style="color:green;">++++++++</span><span style="color:red;">-----</span>
 5 files changed, 251 insertions(+), 198 deletions(-)
```

]

---

## Programming Language

- Past: Fortran, Pascal, C, Matlab, C#, Java

- Recommended: C++17, Python, Javascript

  - Python, then C++ (, then C)

---

## Build Tool

- Past: make, automake, qmake

- Recommended:
  - Python: setuptools
  - C++: cmake, ninja

---

## Static Analysis

- Recommended:

  - Python: flake8 (or pylint)

  - C++: clang-tidy

---

## Coding Style

- Recommended:

  - Python: yapf (or autopep8)

  - C++: clang-format
    - clang-format -i file.cpp

---

## Unit Testing

- Past: cppunit, cute, catch2
  [gtest](https://github.com/google/googletest.git)

- Recommended:
  - Python: pytest
  - C++: doctest

---

## Code Coverage

- Past: gcov

- Recommended: codecov.io

  - [Python](https://github.com/codecov/example-python)

    - python -m pytest --cov=./

  - [C++](https://github.com/codecov/example-cpp11-cmake)
    - lcov

---

## Profiling

- Past: gprof

- Recommended:

  - C++: valgrind --tool=cachegrind + KCachegrind

  - Python: cProfile (built-in module)

---

## 📊 Benchmarking

- Recommended:

  - C++: Google Benchmark ???

  - Python: pytest-benchmark

---

## 📊 Benchmarking Example (I)

.font-sm.mb-xs[

```terminal
ubuntu@ubuntu:~/github/ellpy$ pytest tests/test_lmi.py
<span style="font-weight:bold;">============================= test session starts ==============================</span>
platform linux -- Python 3.7.3, pytest-5.1.2, py-1.8.0, pluggy-0.13.0 -- /media/ubuntu/casper-rw/miniconda3/bin/python
cachedir: .pytest_cache
benchmark: 3.2.2 (defaults: timer=time.perf_counter disable_gc=False min_rounds=5 min_time=0.000005 max_time=1.0 calibration_precision=10 warmup=False warmup_iterations=100000)
rootdir: /media/ubuntu/casper-rw/github/ellpy, inifile: setup.cfg
plugins: benchmark-3.2.2, cov-2.7.1
<span style="font-weight:bold;">collecting ... </span>collected 2 items

tests/test_lmi.py::test_lmi_lazy <span style="color:green;">PASSED</span><span style="color:teal;">                                  [ 50%]</span>
tests/test_lmi.py::test_lmi_old <span style="color:green;">PASSED</span><span style="color:teal;">                                   [100%]</span><span style="color:red;"></span>
<span style="font-weight:bold;color:red;">WARNING: Failed to generate report: No data to report.</span>
```

]

---

## 📊 Benchmarking Example (II)

.font-sm.mb-xs[

```terminal
<span style="color:olive;">--------------------------------------------------------------------------------- benchmark: 2 tests --------------------------------------------------------------------------------</span>
Name (time in ms)         Min                Max               Mean            StdDev             Median               IQR            Outliers      OPS            Rounds  Iterations
<span style="color:olive;">-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------</span>
test_lmi_lazy       <span style="color:green;"></span><span style="font-weight:bold;color:green;">  13.0504 (1.0)    </span><span style="color:green;"></span><span style="font-weight:bold;color:green;">  13.2587 (1.0)    </span><span style="color:green;"></span><span style="font-weight:bold;color:green;">  13.1461 (1.0)    </span><span style="color:red;"></span><span style="font-weight:bold;color:red;">  0.0432 (1.91)   </span><span style="color:green;"></span><span style="font-weight:bold;color:green;">  13.1471 (1.0)    </span><span style="color:red;"></span><span style="font-weight:bold;color:red;">  0.0514 (1.66)   </span>      25;1<span style="color:green;"></span><span style="font-weight:bold;color:green;">  76.0682 (1.0)    </span>      75           1
test_lmi_old        <span style="color:red;"></span><span style="font-weight:bold;color:red;">  13.6855 (1.05)   </span><span style="color:red;"></span><span style="font-weight:bold;color:red;">  13.7888 (1.04)   </span><span style="color:red;"></span><span style="font-weight:bold;color:red;">  13.7279 (1.04)   </span><span style="color:green;"></span><span style="font-weight:bold;color:green;">  0.0225 (1.0)    </span><span style="color:red;"></span><span style="font-weight:bold;color:red;">  13.7271 (1.04)   </span><span style="color:green;"></span><span style="font-weight:bold;color:green;">  0.0310 (1.0)    </span>      24;1<span style="color:red;"></span><span style="font-weight:bold;color:red;">  72.8445 (0.96)   </span>      72           1
<span style="color:olive;">-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------</span>

Legend:
  Outliers: 1 Standard Deviation from Mean; 1.5 IQR (InterQuartile Range) from 1st Quartile and 3rd Quartile.
  OPS: Operations Per Second, computed as 1 / Mean
<span style="color:green;"></span><span style="font-weight:bold;color:green;">============================== 2 passed in 3.27s ===============================</span>
```

]

---

## Code Quality

- Recommended:

  - C++: clang-tidy, cppcheck, valgrind

  - Python: flakes, pre-commit, codecov

---

## 📝 Documentation

- Recommended:

  - Python: sphinx, Jupyter

  - C++: doxygen
    - doxygen -s -g; doxygen

---

## Team Communication

- Past: email

- Recommended: Slack

---

## Repositories

- Past: proprietary

- Recommended: GitHub

- Alternatives:
  - GitLab, Bitbucket

???

China

---

## Continous Integration

- Recommended: GitHub Action

- Alterative: Travis CI, Circle CI

---

## VSCode's extensions

- Recommended:
  - Code Runner
  - Gitconfig Syntax
  - C/C++, CMake, CMake Tools
  - Doxygen Documentation Generator
  - Python, autoDocstring
  - Markdown Preview Enhanced, markdownlint

---

## YouTube Channels

- [GitHub Training & Guides](https://www.youtube.com/channel/UCP7RrmoueENv9TZts3HXXtw)

- [Slack](https://www.youtube.com/channel/UCY3YECgeBcLCzIrFLP4gblw)

- [Enthought](https://www.youtube.com/channel/UCkhm72fuzkS9fYGlGpEmj7A)

---

## Libraries

- Recommended:

  - Python: networkx, cvxpy, tensorflow

  - C++: fmt, xtensor, range-v3, doctest,
    [JSON](https://github.com/nlohmann/json)

---

## 📚 Further Reading

- [KCachegrind](https://kcachegrind.github.io/html/Home.html)

---

class: nord-dark, middle, center

# Q & A 🙋
