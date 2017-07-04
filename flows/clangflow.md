title: Basic Clang++ Flow
class: animation-fade
layout: true

<!-- This slide will serve as the base layout for all your slides -->
.bottom-bar[
  {{title}}
]

---

class: impact

# {{title}}
## Wai-Shing Luk

---

## Why?

- Clang++ 4.0 fully implemented C++17 standard.

- C++17 is pythonified, which is faster, safer, and easier to write.

- Clang++ has some langugage tools, such as clang-tidy

---

## Installation on Ubuntu System

.col-6[
- sudo apt install (Tools)
    - clang clang-tidy clang-format
    - g++ cmake (still need g++ for standard library ???)
    - cppcheck, git
- sudo update-alternatives --config c++
]
.col-6[
- sudo apt install (Libraries)
    - libboost-dev
    - libcppunit-dev
    - catch
- range-v3 (???) (header only)
]

---

## Extensions of Visual Studio Code

- C/C++
- CMake
- cppcheck
- Code Runner
- clang-format

---

## C++ Compiler Options

- clang (version >= 4.0)
  - `-std=c++1z`

```bash
clang -std=c++14 -Wc++1z-extensions profit_main.cpp
clang -std=c++1z profit_main.cpp -lstdc++ -lc -lm
```

---

## CMake Setup

- CMakeLists.txt (example)

```cmake
cmake_minimum_required( VERSION 2.6 )
set ( CMAKE_BUILD_TYPE Release )
add_definitions ( -Wall -std=c++1z ??? )
add_subdirectory( src )
link_directories( lib )
```

---

## Out-of-the-Box Compile

```bash
cd ~/workspace
mkdir build_ellcpp
cd build_ellcpp
cmake ~/Cubstore/ellcpp
make
```

---

## C++ Formatter clang-format

```bash
clang-format -i profit_main.cpp
clang-format -i */*pp
```

- In vcode, press `ctrl-I`

- Note: not work with structured binding.

---

## Static analysis with clang-tidy

- Check the issues:

```bash
clang-tidy-4.0 -header-filter=.* profit_main.cpp -- -std=c++1z
```

- Add `-fix` to automatically fix the issue

```bash
clang-tidy-4.0 -header-filter=.* -fix profit_main.cpp -- -std=c++1z
```

---

## Run clang-tidy with cmake

```bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ~/Cubstore/ellcpp
run-clang-tidy-4.0.py -header-filter='.*' -checks='*'
run-clang-tidy-4.0.py -header-filter='.*' -checks='*' -fix
```

- Note: the fix may not work with `concepts` codes.

---

## Modernize Code using clang-tidy I

- List available items

.small[
```terminal
ubuntu@ubuntu:~/w/b$ clang-tidy-4.0 --list-checks -checks='*' | grep "modernize"
    modernize-avoid-bind
    modernize-deprecated-headers
    modernize-loop-convert
    modernize-make-shared
    modernize-make-unique
    modernize-pass-by-value
    modernize-raw-string-literal
    modernize-redundant-void-arg
    modernize-replace-auto-ptr
    modernize-shrink-to-fit
    modernize-use-auto
    modernize-use-bool-literals
    modernize-use-default-member-init
    modernize-use-emplace
    modernize-use-equals-default
    modernize-use-equals-delete
    modernize-use-nullptr
    modernize-use-override
    modernize-use-transparent-functors
    modernize-use-using
```
]

---

## Modernize Code using clang-tidy II

- Check and fix:

```bash
run-clang-tidy-4.0.py -header-filter='.*' -checks='-*,modernize-deprecated-headers'
run-clang-tidy-4.0.py -header-filter='.*' -checks='-*,modernize-use-auto' -fix
```

- Note the following "fix" seems to have problems:

```bash
    modernize-use-default-member-init
    modernize-use-equals-default
```

---

### Usages

- ellcpp