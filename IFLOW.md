# IFLOW.md - 项目上下文文件

## 项目概述

`luk036.github.io` 是一个个人技术知识库和学习资源集合，由 @luk036 维护。该项目以静态网页形式呈现，使用 remark.js 作为幻灯片引擎，内容涵盖了多个技术领域的学习笔记、教程和研究。

该项目主要包含以下技术主题：

- 可制造性设计算法 (Algorithm for Design for Manufacturing)
- 远程工作生存指南 (Remote Working Survival Guide)
- 从 Python 到 Rust 的学习路径 (From Python To Rust)
- 编程语言相关知识 (Programming Language)
- 基础重建 (Fundamental Rebuild)
- 网络优化 (Network Optimization)
- N-球体 (N-Sphere)
- 数学算法 (Mathematical Algorithms)
- 统计学与机器学习 (Statistics and Machine Learning)
- 射影几何/理性三角学 (Projective Geometry/Rational Trigonometry)
- 物理设计 (Physical Design)
- 近似计算 (Approximate Computing)
- 硬件加速 (Hardware Acceleration)

## 项目结构

该项目是一个静态网站集合，使用 remark.js 作为幻灯片引擎。主要目录包括：

- `algo4dfm`: 可制造性设计算法课程内容
- `flows`: 远程工作生存指南
- `rust_by_examples`: 从 Python 到 Rust 的学习资料
- `proglang`: 编程语言相关主题
- `fun`: 基础重建相关
- `net_optim`: 网络优化
- `n_sphere`: N-球体相关研究
- `cvx`: 数学算法，特别是凸优化
- `statistics`: 统计学与机器学习
- `projgeom`: 射影几何/理性三角学
- `phys_des`: 物理设计
- `AxC`: 近似计算
- `cgra`: 硬件加速
- `css`, `js`, `katex`, `mermaid`, `static`: 网站样式、脚本、数学公式渲染和图表工具
- `node_modules`: npm 依赖包

## 技术栈

- HTML/CSS/JavaScript - 用于网页结构和样式
- remark.js - 幻灯片引擎，由 `js/remark.min.js` 提供
- Markdown - 内容编写格式
- Prettier - 代码格式化工具 (在 `package.json` 中定义)
- LaTex - 部分数学内容可能使用
- MathJax - 数学公式渲染 (可能在某些页面中使用)

## 开发和构建命令

由于这是一个静态网站项目，不需要复杂的构建过程。可以简单地通过 web 服务器提供内容或直接在浏览器中打开 HTML 文件。如果要格式化代码，可以使用 Prettier：

```bash
npx prettier --write .
```

## 内容特点

该项目内容非常丰富，覆盖了从软件开发、算法设计到物理设计和硬件加速等多个领域。所有内容都以幻灯片形式呈现，便于学习和展示。项目中包含大量链接到外部资源，如视频、播客、论文和应用程序。

## 使用方式

该项目主要用于个人知识管理和分享，可以作为学习笔记和教程资源库。用户可以直接访问托管在 GitHub Pages 上的网站来查看内容，或者克隆项目到本地进行查看。
