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

- Clang++ 7.0 fully implemented C++17 standard.
- C++17 is pythonified, which is faster, safer, and easier to write.
- Clang++ has some langugage tools, such as clang-tidy

## Why not?

- No Concepts
- Run time performance is worser than g++

---

## Installation on Ubuntu System

- Currently Ubuntu 17.10 apt system does not have clang 6.0 by default.

- Thus, to install clang++ 7.0, first you need append the following two lines to `/etc/apt/sources.list`

.small[
```
deb http://apt.llvm.org/artful/ llvm-toolchain-artful main
deb-src http://apt.llvm.org/artful/ llvm-toolchain-artful main
```
]

- Then, type:

.small[
```terminal
> wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
> sudo apt update
> sudo apt install clang-7 lld-7
> sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-7 100
> sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-7 100
```
]

---

## Installation

.col-6[
- sudo apt install (Tools)
    - clang-tidy-7 clang-format-7
    - cmake gdb
    - cppcheck git
    - gnome-terminal (for vscode debugging)
    - python-yaml (for run-clang-tidy-7.py) 
- sudo update-alternatives --config c++
]
.col-6[
- sudo apt install (Libraries)
    - libboost-dev
    - libcppunit-dev
    - catch
- github.com/fmtlib/fmt
- range-v3 (header only)
]

---

## Extensions of Visual Studio Code

- C/C++
- CMake
- CMake Tools
- cppcheck
- Code Runner
- Clang-Format
- Gitconfig Syntax

---

## C++ Compiler Options

- clang (version >= 4.0)
  - `-std=c++1z`

```bash
clang++ -std=c++14 -Wc++1z-extensions profit_main.cpp
clang++ -std=c++1z profit_main.cpp -lstdc++ -lc -lm
```

---

## CMake Setup

- CMakeLists.txt (example)

.small[
.col-6[
```cmake
cmake_minimum_required( VERSION 2.6 )
set ( CMAKE_BUILD_TYPE Release )
add_definitions ( -Wall -std=c++1z )
add_subdirectory( src )
link_directories( lib )
```
]
.col-6[
```cmake
cmake_minimum_required (VERSION 2.8.11)
project (pgcpp)
set (CMAKE_BUILD_TYPE Debug )
add_definitions ( -Wall -fconcepts -std=c++1z )
add_executable (Main Main.cpp)
target_link_libraries (Main -lfmt )
```
]
]

---

## Out-of-the-Box Compile

```bash
cd ~/Cubstore/ellcpp
mkdir build
cd build
cmake ..
make
```

---

## C++ Formatter clang-format

```bash
clang-format-7 -i profit_main.cpp
clang-format-7 -i */*pp
```

- In vcode, press `ctrl-I`

---

## Static analysis with clang-tidy

- Check the issues:

```bash
clang-tidy-7 -header-filter=.* profit_main.cpp -- -std=c++1z
```

- Add `-fix` to automatically fix the issue

```bash
clang-tidy-7 -header-filter=.* -fix profit_main.cpp -- -std=c++1z
```

---

## Run clang-tidy with cmake

```bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ~/Cubstore/ellcpp
run-clang-tidy-7.py -header-filter='.*' -checks='*'
run-clang-tidy-7.py -header-filter='.*' -checks='*' -fix
```

- Note: the fix may not work with `concepts` codes.

---

## Modernize Code using clang-tidy I

- List available items

.small[
```terminal
ubuntu@ubuntu:~/w/b$ clang-tidy-7 --list-checks -checks='*' | grep "modernize"
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
run-clang-tidy-7.py -header-filter='.*' -checks='-*,modernize-deprecated-headers'
run-clang-tidy-7.py -header-filter='.*' -checks='-*,modernize-use-auto' -fix
```

- Note the following "fix" seems to have problems:

```bash
    modernize-use-default-member-init
    modernize-use-equals-default
```

---

### Usages

- ellcpp