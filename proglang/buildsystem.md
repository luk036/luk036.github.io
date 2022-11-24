# How to build and install?

- Mainly algorithms
- Python -> C++
- pip + conda
- multiple platforms (portable)

## Platforms

- 🐧 Linux (Ubuntu 18.04 LTS, 20.04 LTS)
- Windows 10
- Android's Termux
- macOS (only tested on Travis-CI)

## Python 🐍

No more 2.X, start 3.X

- python setup.py develop (setup.cfg)
- python setup.py test
- python setup.py test --addopts --cov=src

- pip install -r requirements.txt
- pip install .
- pytest
- pytest --cov=src

## C++

No more C++14, start C++17
compilers: g++ (>= 9), clang (>= 10), msvc (16.9)

- Can't install conda in termux (python "from os import link)")
- reference Travis-CI - conda config --add channels conda-forge - conda install --file requirements.txt

            | lubuntu | windows | termux
  ----------|---------|---------|---------
  fmt | apt | conda | pkg
  boost | apt | conda | pkg
  oepnblas | apt??? | conda | pkg
  fftw | conda | conda | pkg
  spdlog | apt | conda | source copy (header only)
  doctest | apt | conda | source copy (header only)
  range-v3 | apt | copy | source copy (header only)
  benchmark | apt | conda | source make install
  xtl | conda | conda | source make install
  xtensor | conda | conda | source make install
  xt-blas | conda | conda | source make install
  xt-fftw | conda | conda | source make install
  lcov | apt | -- | --

conda -> boost no filesystem
ThreadPool???
JSON???

vcpkg???

[[unlikely]] (warning)
gsl -> gsl::span -> std::span (C++20)
fmt -> std::format
<memory_resource> (C++17, but Clang don't support)
<concepts> (C++20)
