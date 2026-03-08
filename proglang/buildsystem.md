# How to build and install

This repository contains algorithms and examples in Python and C++. The
instructions below show common build / install commands and platform notes.

### Platforms

- Ubuntu (tested on 18.04 and 20.04)
- Windows 10
- Android (Termux)
- macOS (CI-tested)

### Python

Use Python 3 (no Python 2).

Common commands:

```bash
python -m pip install -r requirements.txt
python setup.py develop    # or: pip install -e .
python setup.py test
pytest --cov=src
```

Use `conda` when appropriate:

```bash
conda config --add channels conda-forge
conda install --file requirements.txt
```

### C++

Use C++17 or newer. Supported compilers:

- g++ >= 9
- clang >= 10
- MSVC (Visual Studio) >= 16.9

Notes and tips:

- Termux: conda is not available on Termux; some Python features (e.g. `os.link`)
  may be missing.
- CI: consider using conda on Linux and Windows to reproduce dependencies.
- Package managers: use system packages on Linux (`apt`), `conda` on Windows,
  and Termux packages on Android where available.

Dependency matrix (typical availability)

| Library    | Ubuntu / apt | Windows / conda | Termux / pkg |
|------------|--------------|-----------------|--------------|
| fmt        | apt / system | conda           | pkg / source |
| boost      | apt          | conda           | pkg          |
| openblas   | apt          | conda           | pkg          |
| fftw       | conda        | conda           | pkg          |
| spdlog     | apt / header | conda           | header-only  |
| doctest    | apt / header | conda           | header-only  |
| range-v3   | apt / copy   | conda / copy    | header-only  |
| benchmark  | apt          | conda           | build+install|
| xtl        | conda        | conda           | build+install|
| xtensor    | conda        | conda           | build+install|
| xt-blas    | conda        | conda           | build+install|
| xt-fftw    | conda        | conda           | build+install|
| lcov       | apt          | —               | —            |

Packaging and build helpers:

- Consider `vcpkg` or `conan` for cross-platform C++ dependency management.
- Use CMake (with `CMAKE_CXX_STANDARD=17`) and a small top-level `CMakeLists.txt`.

Compatibility notes / warnings

- gsl: prefer `gsl::span` or `std::span` (C++20) where available.
- `fmt` functionality can be replaced by `std::format` (C++20) in newer compilers.
- `<memory_resource>` is part of C++17 but has varying support across compilers.
- `<concepts>` and other C++20 features require newer compiler toolchains.

If you want, I can add a minimal `CMakeLists.txt` and a GitHub Actions workflow.
