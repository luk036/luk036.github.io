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

- Clang++ 10 implemented (partially) C++20 standard.
- C++20 is pythonified, which is faster, safer, and easier to write.
- Clang++ has some langugage tools, such as clang-tidy

## Why not?

- Run time performance is worser than g++

---

## Installation on Ubuntu System

- Currently Ubuntu 18.04 LTS apt system does not have clang 10 by default.

- Thus, to install clang++ 10, first you need append the following two lines to `/etc/apt/sources.list`

.small[
```
deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-10 main
deb-src http://apt.llvm.org/bionic/ llvm-toolchain-bionic-10 main
```
]

- Then, type:

.small[
```terminal
> wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
> sudo apt update
> sudo apt install clang-10 lld-10 lldb-10 
> sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-10 100
> sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-10 100
```
]

---

## Installation

.col-6[

- sudo apt install (Tools)
    - clang-tidy-10 clang-format-10
    - cmake gdb
    - cppcheck git
    - gnome-terminal (for vscode debugging)
    - python-yaml (for run-clang-tidy-10.py) 
]
.col-6[
- sudo apt install (Libraries)
    - libboost-graph-dev
    - catch
- github.com/fmtlib/fmt
- range-v3 (header only)

]

---

## Extensions of Visual Studio Code

- C/C++
- CMake
- CMake Tools
- Code Runner

---

## C++ Compiler Options

- clang (version >= 10)
  - `-std=c++2q`
  - `-fcoroutines-ts -stdlib=libc++`

---

## CMake Setup

- CMakeLists.txt (example)

.small[
.col-6[

```cmake
cmake_minimum_required( VERSION 2.6 )
set ( CMAKE_BUILD_TYPE Release )
add_definitions ( -Wall -std=c++2a )
add_subdirectory( src )
link_directories( lib )
```

]
.col-6[

```cmake
cmake_minimum_required (VERSION 2.8.11)
project (pgcpp)
set (CMAKE_BUILD_TYPE Debug )
add_definitions ( -Wall -fconcepts -std=c++2a )
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
cmake --build .
```

---

## C++ Formatter clang-format

```bash
clang-format-10 -style="{IndentWidth: 4}" -i profit_main.cpp
clang-format-10 -style="{IndentWidth: 4}" -i */*pp
```

- In vcode, press `ctrl-shift-I`

---

## Static analysis with clang-tidy

- Check the issues:

```bash
clang-tidy-10 -header-filter=.* profit_main.cpp -- -std=c++2a
```

- Add `-fix` to automatically fix the issue

```bash
clang-tidy-10 -header-filter=.* -fix profit_main.cpp -- -std=c++2a
```

---

## Run clang-tidy with cmake

```bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ~/Cubstore/ellcpp
run-clang-tidy-10.py -header-filter='.*' -checks='*'
run-clang-tidy-10.py -header-filter='.*' -checks='*' -fix
```

- Note: the fix may not work with `concepts` codes.

---

## Modernize Code using clang-tidy I

- List available items

.small[
```terminal
ubuntu@ubuntu:~/w/b$ clang-tidy-10 --list-checks -checks='*' | grep "modernize"
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
run-clang-tidy-10.py -header-filter='.*' -checks='-*,modernize-deprecated-headers'
run-clang-tidy-10.py -header-filter='.*' -checks='-*,modernize-use-auto' -fix
```

- Note the following "fix" seems to have problems:

```bash
    modernize-use-default-member-init
    modernize-use-equals-default
```

---

### Usages

- ellcpp

---

class: impact

Q & A 🗣️
==========
