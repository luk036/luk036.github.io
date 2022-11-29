# Hardware Description Language

Logic/timing

Verilog/VHDL
VHDL-AMS 

- C-like language 
- IEEE standard libraries

SystemVerilog

SystemC

Matlab/Simulink

markdown + css "rendering" => html

---

# Chisel3 (Scala)

- Functional language!?
- Domain Specific Language
- originally developed at UC Berkeley

---

# myHDL

- pure Python program
- decorator
- yield statement (event driven)
- Self-running or convert to verilog 
- pip install myhdl
- tool support
- too slow

---

# High-Level Synthesis (HLS)

Xilinx
#define 
[C] --> clang --[llvm]--> HLS Schedular --> Verilog 
                               /
    Hardware description -----+

fib(6)
