Software Development Setup for Android's Termux

# Gemini/iflow
Fix the problems specifically for Termux

# Rust development
pkg install rust
pkg install rust-analysis
cargo build
cargo install cargo-llvm ???

# python development

pip install tpip
tpip set
pkg install rust
cargo install maturin
export ANDROID_API_LEVEL=28
pip install numpy

pkg install libopenblas
pkg install freetype libpng
pkg install libzmq

pip install numpy
pip install scipy
pip install cvxpy # warnings
pip install jupyter
jupyter notebook --ip=10.217.73.15 --port=8888

pip install spinxcontrib-svgbob # failed

# C++
pkg innstall clang

## xmake
pkg install xmake
pkg install binutils-is-llvm

## cmake + CPM
pkg install cmake ninja
cmake -Sall -Bbuild -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -Wno-dev
