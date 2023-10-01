layout: true
class: typo, typo-selection

---

class: nord-dark, center, middle

# Basic Clang++ Flow

@luk036

---

## Why?

-   Clang++ 11 implemented (partially) C++20 standard.
-   C++20 is pythonified, which is faster, safer, and easier to write.
-   Clang++ has some language tools, such as clang-tidy

## Why not?

-   Run time performance is worse than g++

---

## Installation on Ubuntu System

-   Currently, Ubuntu 20.04 LTS apt system does not have clang 11 by default.

-   Thus, to install clang++ 11, first you need to append the following
    two lines to `/etc/apt/sources.list`

.font-sm.mb-xs[

``` terminal
deb http://apt.llvm.org/focal/ llvm-toolchain-focal-11 main
deb-src http://apt.llvm.org/focal/ llvm-toolchain-focal-11 main
```

]

-   Then, type:

.font-sm.mb-xs[

``` terminal
> wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
> sudo apt update
> sudo apt install clang-11 lld-11 lldb-11
> sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-11 100
> sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-11 100
```

]

---

## Installation

-   sudo apt install (Tools)
    -   clang-tidy-11 clang-format-11
    -   cmake gdb
    -   cppcheck git
    -   gnome-terminal (for vscode debugging)
    -   python-yaml (for run-clang-tidy-11.py)
-   sudo apt install (Libraries)
    -   libboost-graph-dev
    -   catch
-   github.com/fmtlib/fmt
-   range-v3 (header only)

---

## Extensions of Visual Studio Code

-   C/C++
-   CMake
-   CMake Tools
-   Code Runner

---

## C++ Compiler Options

-   clang (version \>= 11)
    -   `-std=c++2a`
    -   `-fcoroutines-ts -stdlib=libc++`

---

## CMake Setup

-   CMakeLists.txt (example)

```cmake
cmake_minimum_required( VERSION 2.6 )
set ( CMAKE_BUILD_TYPE Release )
add_definitions ( -Wall -std=c++2a )
add_subdirectory( src )
link_directories( lib )
```

```cmake
cmake_minimum_required (VERSION 2.8.11)
project (pgcpp)
set (CMAKE_BUILD_TYPE Debug )
add_definitions ( -Wall -fconcepts -std=c++2a )
add_executable (Main Main.cpp)
target_link_libraries (Main -lfmt )
```

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
clang-format-11 -style="{IndentWidth: 4}" -i profit_main.cpp
clang-format-11 -style="{IndentWidth: 4}" -i */*pp
```

-   In vcode, press `ctrl-shift-I`

---

## Static analysis with clang-tidy

-   Check the issues:

``` bash
clang-tidy-11 -header-filter=.* profit_main.cpp -- -std=c++2a
```

-   Add `-fix` to automatically fix the issue

``` bash
clang-tidy-11 -header-filter=.* -fix profit_main.cpp -- -std=c++2a
```

---

## Run clang-tidy with Cmake

``` bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ~/Cubstore/ellcpp
run-clang-tidy-11.py -header-filter='.*' -checks='*'
run-clang-tidy-11.py -header-filter='.*' -checks='*' -fix
```

-   Note: the fix may not work with `concepts` codes.

---

## Modernize Code using clang-tidy I

.font-sm.mb-xs[

```terminal
ubuntu@ubuntu:~/w/b$ clang-tidy-11 --list-checks -checks='*' | grep "modernize"
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

-   Check and fix:

.font-sm.mb-xs[

``` bash
run-clang-tidy-11.py -header-filter='.*' -checks='-*,modernize-deprecated-headers'
run-clang-tidy-11.py -header-filter='.*' -checks='-*,modernize-use-auto' -fix
```

]

-   Note the following "fix" seems to have problems:

``` bash
modernize-use-default-member-init
modernize-use-equals-default
```

---

### Usages

-   ellcpp

---

class: nord-dark, center, middle

# Q & A 🙋
