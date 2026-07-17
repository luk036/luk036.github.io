# 在 Android Termux 上安装 cvxpy 的踩坑记录 🐧

## 背景

[cvxpy](https://www.cvxpy.org/) 是一个用于凸优化的 Python 领域特定语言（DSL），广泛应用于机器学习、信号处理、金融工程等领域。最近需要在 Android 的 Termux 终端上使用 cvxpy 进行一些网络优化相关的实验，本以为 `pip install cvxpy` 就能搞定，没想到踩了一串坑……😅

## 环境

- **设备**: Android (aarch64)
- **Termux**: 最新
- **Python**: 3.14.6
- **pip**: 26.1.2
- **OpenBLAS**: 0.3.34

numpy 和 scipy 已通过 `pkg install python-numpy python-scipy` 安装好，版本分别为 2.4.4 和 1.18.0。

## 第一坑：pip 尝试从源码编译 numpy 2.5.1

直接执行 `pip install cvxpy`：

```text
× Preparing metadata (pyproject.toml) did not run successfully.
...
error: call to undeclared library function 'cpowf' ...
```

cvxpy 的 pyproject.toml 声明了构建依赖 `numpy>=2.0.0`，pip 发现本地已安装的 numpy 2.4.4 比 PyPI 上的最新版 2.5.1 旧，于是决定**从源码编译 numpy 2.5.1**。但在 Android 的 clang 编译器下，numpy 的 C 代码中 complex.h 的数学函数（如 `cpowf`、`cexpl` 等）声明不兼容，导致编译失败。💥

### 解决方法

使用 `--no-build-isolation` 让 pip 使用**已有的系统包**，避免重复编译 numpy/scipy：

```bash
pip install cvxpy --no-build-isolation
```

## 第二坑：sparsediffpy 与 scikit-build-core 版本不兼容

加上 `--no-build-isolation` 后，编译过程推进到 sparsediffpy 依赖时又挂了：

```text
ERROR: Use cmake.version instead of cmake.minimum-version with scikit-build-core >= 0.8
```

sparsediffpy 是一个稀疏差分引擎的 Python 封装，用 scikit-build-core 构建。它使用了旧的 `cmake.minimum-version` 配置项，而 Termux 上安装的 scikit-build-core 是 1.0.3，已移除了对旧语法的支持。

### 解决方法

降级 scikit-build-core 到 0.7.x：

```bash
pip install "scikit-build-core<0.8"
```

不过后来发现降级会导致其他依赖（如 osqp）出现新的兼容问题，所以更好的方案是——手动修补 sparsediffpy 的源码，或直接安装已编译好的 wheel。

## 第三坑：找不到 cblas.h

解决版本问题后，C 编译阶段又报错：

```text
fatal error: 'cblas.h' file not found
```

Termux 的 OpenBLAS 把头文件放在了 `/data/data/com.termux/files/usr/include/openblas/` 下（带子目录），而编译器的默认搜索路径找不到它。

### 解决方法

设置环境变量 `C_INCLUDE_PATH`：

```bash
export C_INCLUDE_PATH=/data/data/com.termux/files/usr/include/openblas
pip install sparsediffpy==0.2.0 --no-build-isolation
```

这次编译成功了，生成了 `sparsediffpy-0.2.0-cp314-cp314-android_24_arm64_v8a.whl`。🎉

## 第四坑：osqp 的 scikit-build-core 配置问题

安装完 sparsediffpy 后，继续安装 cvxpy 的完整依赖时，osqp 又报错了：

```text
TypeError: cannot create 'typing.Union' instances
Field tool.scikit-build.cmake.define
```

osqp 构建时对 scikit-build-core 的配置格式有特定要求，为了兼容所有依赖，需要**把 scikit-build-core 升级回最新版**，同时用预构建的 wheel 安装 sparsediffpy。

## 最终安装方案

经过多次尝试，发现 **cvxpy 1.8.2 有预编译的 wheel** 可以直接安装！流程如下：

### 第 1 步：升级 scikit-build-core

```bash
pip install "scikit-build-core>=0.8"
```

### 第 2 步：安装 sparsediffpy（从缓存 wheel）

之前编译好的 wheel 还在 pip 缓存中，直接安装：

```bash
pip install /data/data/com.termux/files/home/.cache/pip/wheels/.../sparsediffpy-0.2.0-cp314-cp314-android_24_arm64_v8a.whl
```

### 第 3 步：安装 cvxpy 本体（用 wheel，跳过依赖）

```bash
pip install cvxpy==1.8.2 --no-build-isolation --no-deps
```

### 第 4 步：逐个安装求解器依赖

```bash
pip install osqp clarabel scs highspy --no-build-isolation
```

其中 osqp 和 scs 有预编译 wheel 可以直接装，clarabel 需要用 Rust 编译（需要预先 `pkg install rust`）耗时约 4 分钟，highspy 编译也较久（大型 C++ 库）。

## 验证

```python
import cvxpy as cp

x = cp.Variable()
prob = cp.Problem(cp.Minimize(x**2), [x >= 1])
prob.solve()
print('Status:', prob.status)  # optimal
print('Value:', x.value)       # 1.0
```

求解成功！✅

## 最终安装结果

- **cvxpy** 1.8.2 — 预编译 wheel
- **numpy** 2.4.4 — Termux 包
- **scipy** 1.18.0 — Termux 包
- **osqp** 1.1.3 — 预编译 wheel
- **clarabel** 0.11.1 — Rust 源码编译
- **scs** 3.2.11 — 预编译 wheel
- **highspy** 1.15.1 — 源码编译

## 经验总结 💡

1. **先用 `--no-build-isolation`**：避免 pip 重复编译已有的 numpy/scipy，省时省力
2. **善用 pip 缓存**：编译成功的 wheel 会缓存下来，后续可以直接安装
3. **固定版本安装**：cvxpy 1.8.x 有 Termux 可用的 wheel，1.9.x 可能没有
4. **注意 scikit-build-core 的版本兼容性**：不同包对它的版本要求不同，需要灵活调整
5. **环境变量 `C_INCLUDE_PATH`**：Termux 下 OpenBLAS 的头文件路径特殊，编译时容易找不到

当然，最理想的情况是 Termux 官方或社区能直接提供 cvxpy 包，毕竟编译这些 C++/Rust 扩展在手机上确实耗时。不过话又说回来，能在一部手机上跑凸优化算法，本身也是一件很酷的事情不是吗？📱🔥
