layout: true
class: typo, typo-selection

---

class: nord-dark, center, middle

# g++-11 flow

@luk036

---

## Why?

- To test C++23 new feature (modules), together with structured binding.

- C++23 is pythonified, which is faster, safer, and easier to write.

---

## Installation on Ubuntu

- To compile C++23 with Concepts and Coroutine, you need g++ version >= 11
  - `-std=c++2b`
  - `-fmodules-ts`
  - `-fcoroutines -fno-exceptions`
- However, currently, the default g++ on Ubuntu 18.04 LTS is only 7.3.
- Thus, to install g++-11, you need to type:

.font-sm.mb-xs[

```terminal
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install g++-11 gcc-11
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 90
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 90

# Don't use conda's libstdc++.so
export LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu/
```

]

---

## Installation

- sudo apt install (tools)
  - cmake
  - gdb
  - git
- sudo apt install (libraries)
  - catch
- github.com/fmtlib/fmt
- range-v3 (header only)

---

## CMake Setup

- CMakeLists.txt (example)

```cmake
cmake_minimum_required (VERSION 2.8.11)
project (pgcpp)
set (CMAKE_BUILD_TYPE Debug )
add_definitions ( -Wall -Wextra -Wpedantic -fmodules-ts -std=c++2b )
add_executable (Main Main.cpp)
target_link_libraries (Main -lfmt )
```

---

## Out-of-the-Box Compile

```bash
cd ~/workspace
mkdir build_pgcpp
cd build_pgcpp
cmake ~/github/pgcpp
make
```

---

## Visual Studio Code Extensions

- C/C++
- CMake Tools
- Git History
- Git History Diff

---

![img](scrot2_gcc.png)

---

## Online References

- [cppreference.com](http://en.cppreference.com/w/)
- [Boost](http://www.boost.org)

---

class: nord-dark, center, middle

# 🙋 Q & A
