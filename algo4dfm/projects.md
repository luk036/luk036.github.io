title: Final Years Projects
class: animation-fade
layout: true

---

class: center, middle

# {{title}}

Wai-Shing Luk

2020-05-31

---

## 为什么选择 MyHDL?

- 数字滤波器的设计和硬件中的实现通常是两个阶段的过程，在 Python、Matlab 或 Java 等语言中进行算法开发，在 VHDL 或 Verilog 等硬件描述语言中进行 RTL 设计。这就需要在这两个环境之间来回走动多次，检查硬件设计是否符合要求的规范。让人兴奋的是 MyHDL 能在同一个 Python 环境中开发算法和 RTL 设计。
- MyHDL 的另一个方面是，设计可以自动转换为 Verilog 和 VHDL 中的等效代码，使语言中立的设计成为可能。

---

## 为什么选择 PyFDA?

进一步说，将 MyHDL 和 PyFDA 连接起来有更多的好处。这种组合可以填补算法开发和 HDL fixpoint 块之间的开源工具链的空白，这将消除对 Mathworks hdl-coder 等商业授权工具的需求。
