layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Advanced Digital System Design: A Practical Guide 🚀

**Based on the book by Shirshendu Roy**
*(Approx. 90 minutes) ⏳*

@luk036 👨🏻‍🏫

2025-05-12 📅

---

## Introduction - Why Advanced Digital System Design?

*   **Technology is ubiquitous** 🌍.
*   Huge demand for implementing **signal, image, or video processing algorithms** in real-time systems 🎥.
*   These systems consist of both **analog and digital sub-systems** ⚡.
*   The analog part is mainly for **signal acquisition** 📡.
*   The digital sub-systems achieve the **processing** 🧠.
*   An **optimized implementation of a digital system** is crucial to improve the overall Integrated Circuit (IC) performance ⚙️.

---

## Optimization Objectives

*   Digital system implementations on hardware platforms achieve **faster execution speed** ⚡.
*   Implementations must be **optimized** in terms of:
    *   **Power** consumption (to save battery life) 🔋.
    *   **Area** (to save cost) 💰.
    *   **Performance** (speed) 🚀.
*   Optimization can happen at various levels of the design hierarchy.

---

## Hardware Description Languages (HDLs) - Verilog HDL

*   Verilog HDL is a **very powerful programming language to model digital systems** 💻.
*   Concepts about Verilog HDL are discussed with suitable examples in the book 📖.
*   Knowing **different operators and operands** is beneficial before learning Verilog HDL 🔧.
*   These expressions help in understanding complex Verilog codes.

---

## Verilog HDL - Modeling Styles

*   Different programming/modeling styles are discussed.
*   Examples often use a simple Multiplexer design.
*   Key styles include:
    *   **Data Flow Modelling** 📊.
    *   **Behavioural Modelling** 🧠.
    *   **Structural Modelling** (Gate-Level, Hierarchical) 🏗️.
    *   **Mixed Modelling** 🔄.
*   Test bench writing technique is also discussed.

---

## Verilog HDL - Behavioural Modelling Details

*   Behavioural modeling describes the **circuit's behavior** 🧠.
*   Uses constructs like `always` or `initial` statements.
*   `always @(sensitivity list)` defines when the block executes ⏲️.
*   `always @*` automatically considers inputs as the sensitivity list for combinational logic.
*   Control flow structures like `if-else`, `case`, `for`, `while` loops are used 🔄.
*   Statements within `always` or `initial` can be executed in **parallel** using `fork` and `join` ↔️.

---

## Verilog HDL - Auxiliary Concepts

*   Verilog descriptions are written under a **module** 📦.
*   Modules have a **declaration stage** (inputs, outputs, nets, constants) followed by **statements/expressions** ✍️.
*   Modules end with `endmodule`.
*   **File handling** allows reading/writing data to external files for verifying complex designs with large datasets 📂.
*   **Test Benches** contain input test vectors and clock information to verify the design code (Unit Under Test - UUT) 🧪.

---

## Basic Combinational Circuits - Adders

*   Combinational circuits: output depends only on **present input** ⚡.
*   Adders are the **most important basic logic element** in designing a digital system ➕.
*   Addition is used in computation of multiplication, division, or square root.
*   Speed of an adder is crucial for design performance ⚡.
*   Examples:
    *   **Half Adder (HA)**: computes sum (s) and carry-out (cout) for two bits. `s = a XOR b`, `cout = a AND b`.
    *   **Full Adder (FA)**: computes sum (s) and carry-out (cout) for three bits (two inputs and a carry-in).

---

## Basic Combinational Circuits - Comparators

*   Comparators compare operands **bit by bit** 🔍.
*   A 1-bit comparator checks if two bits are equal (EQ), less than (LT), or greater than (GT).
*   Equality can be checked with an **XNOR gate** ⚖️.
*   Design of multi-bit comparators (e.g., 16-bit, 18-bit) involves comparing bits starting from the MSB.
*   Comparators can be realized straightforwardly using a **behavioural model** in Verilog.

---

## Basic Sequential Circuits - Introduction

*   Sequential circuits: output depends on **present input AND past history (previous outputs)** ⏳.
*   Sometimes called **time-dependent circuits** as outputs update according to a time event.
*   Major sequential blocks are needed to implement complex digital systems.
*   Includes flip-flops, shift registers, counters, and frequency dividers.
*   Basic concepts might be avoided assuming prior knowledge.

---

## Basic Sequential Circuits - Flip-Flops

*   Operation of major sequential blocks is explained.
*   **Edge triggering** (positive or negative) is key; transition occurs only at the clock edge ⏱️.
*   **SR Flip-Flop**: Most basic, has set (S) and reset (R) inputs. Truth table shows present (Q) and next (Q\*) states. Output goes to an undefined state with S=1, R=1 input.
*   **D Flip-Flop**: Data (D) input, output (Q) follows D on the clock edge. Useful for storing a single bit. Often includes enable (ce) and reset signals.

---

## Basic Sequential Circuits - Clocking & Division

*   Sequential circuits propagate data with respect to a **clock** in synchronous designs ⏰.
*   The concept of **positive edge triggering** is fundamental.
*   **Clock Division**: Circuits to generate clocks with frequencies that are fractions of the main clock.
*   Example: Clock division by a power of two can be achieved with a cascade of flip-flops toggling on opposite edges or via T flip-flops. Clock division by N can also be implemented.

---

## Advanced Digital Arithmetic - Fast Adders 🚀

*   Speed of an adder is a very important parameter for performance ⚡
*   Ripple Carry Adder: Simple, but carry propagates bit by bit, leading to delay for large numbers 🐢
*   Carry Look-Ahead Adder (CLA): A common fast adder. Based on computing all carries in parallel 🌀. Uses "propagate" (P) and "generate" (G) terms

---

## Advanced Digital Arithmetic - Multiplication ✖️

*   Multiplication operation is discussed, including VEDIC multiplication techniques 🧮
*   Alternative methods like shift and add are common 🔄
*   In shift and add, the multiplicand is added to zero if the multiplier bit is 0, otherwise the multiplicand is added. The result is augmented in a register bank and shifted right after each addition ⬇️
*   Booth's Radix-4 algorithm is discussed for multiplying signed binary numbers 🔢. It aims to reduce the number of partial products

---

## Advanced Digital Arithmetic - Partial Product Accumulation 🌳

*   After generating partial products in multiplication, they must be added together ➕
*   Several techniques exist for partial product accumulation
*   Objectives include:
*   Reducing logic elements (hardware complexity) 🏗️
*   Reducing the number of levels in the tree of partial products (for high speed) ⚡
*   Wallace tree is a well-known technique for fast partial product accumulation 🌲

---

## Advanced Digital Arithmetic - Division ➗🔢

*   Various **division algorithms** are discussed, including restoring 🔄 and non-restoring algorithms 🔄, with examples 📊🧮
*   Implementation of these algorithms is covered 🛠️⚙️
*   Basic principle of **SRT division algorithm** is also given 🔍📐
*   Iterative algorithms for division operations are explained 🔁⏱️
*   Computation of **modulus operation without division** is also discussed 🧮🤯
*   Non-restoring division architecture involves repeated addition/subtraction ➕➖ and shifting ↔️🔄

---

## Advanced Digital Arithmetic - Floating Point 🌊🔢

*   **Floating Point Architectures** deal with representing and performing arithmetic on real numbers 📈🔢
*   Standards like **IEEE floating point data format** are discussed 📜🏷️
*   This format typically includes:
    *   **Sign Bit (S)** ➕➖
    *   **Biased Exponent (E)** ⬆️⬇️
    *   **Unsigned Mantissa (M)** ✏️📏
*   Architectures for floating point arithmetic operations are presented 🏗️💻

---

## Memory Design - Introduction 💾

*   Memory elements are required to **store data vectors or matrices** 📦🧩
*   Needed for initialization or storing **intermediate results** 🔄⏸️
*   Using memory elements can support **real-time execution** ⏱️⚡
*   Can help achieve **better execution time** by enabling more parallelism ↔️🧵
*   Play a crucial role in **efficient implementation** of digital systems 🎯💡

---

## Memory Design - Registers 📝🔢

*   Registers are basic memory elements used to store data 💾📥
*   A **controlled register** uses an enable signal (`ce`) to control writing ✏️🎚️
*   Timing diagram shows data loading when enable is high ⬆️⏱️
*   Holds value when enable is low ⬇️⏸️
*   Reset signal can clear the output 🧹🔄

---

## Memory Design - ROM 📜🔒

*   **Read Only Memory (ROM)** stores **constant data elements** 🏛️📌
*   Data is programmed during manufacturing 🏭🔧
*   Cannot be easily changed 🔒🚫
*   **Single Port ROM (SPROM)** has single address/data port 1️⃣🔌
*   Timing diagram shows data being read 📖⏱️

---

## Memory Design - RAM 📝🔄

*   **Random Access Memory (RAM)** allows both reading 📖 and writing ✏️
*   **Single Port RAM (SPRAM)**: One address/data port 1️⃣🔌
*   **Dual Port RAM (DPRAM)**: Two independent ports 2️⃣🔀
*   Enables **concurrent data acquisition and processing** ⚡🧠
*   DPRAMs are mostly used to implement algorithms 🛠️💡

---

## Finite State Machines (FSMs) - Basics 🚦🤖

*   FSMs design circuits with output depending on **present state and inputs** 🔄🎚️
*   Three sections:
    *   Output state decoder 🧩🔍
    *   State register 📝💾
    *   Output decoder 🖨️💡
*   Two types:
    *   **Mealy Machine**: Output depends on state+input ⚡🤸
    *   **Moore Machine**: Output depends only on state⏱️

---

## FSMs - Design Process 🎨

*   Design involves defining states and transitions 🗺️
*   Represented by a state diagram 📊
*   Translated into a state table showing present state, next state, and output based on inputs 📋
*   Requires sequential elements (like D flip-flops) to hold the state

---

## FSMs - State Minimization ✂️

*   State minimization aims to reduce the number of states in an FSM while preserving its behavior 🧮
*   Important for reducing hardware complexity 🏗️
*   Techniques discussed:
    *   Row equivalence method: Basic, may not always be optimal
    *   Implication chart method: Rigorous, supports machine implementation 🧮. Squares are filled with implied state pairs; incompatible pairs are crossed out ❌
    *   Partition-based technique: Simple and rigorous, machine realizable
    *   Heuristic methods based on K-maps also exist

---

## FSMs - Verilog Implementation 💻

*   Verilog provides an easy way to implement FSMs 🛠️
*   Design is primarily based on the state diagram 📊
*   Uses behavioral modeling with always blocks ⚙️
*   States are often defined using localparam or parameter 🏷️
*   One always block for state transitions (typically edge-triggered) and another for output/next state logic (combinational or edge-triggered depending on Mealy/Moore)

---

## Implementation Platforms - FPGA vs ASIC ⚡

*   Algorithms must be implemented on hardware platforms for faster execution 🚀
*   Dedicated ICs offer greater parallelism and speed compared to processors
*   ICs broadly classified as Custom, Semi-Custom, Standard Cell-Based, and Gate Array-based
*   FPGA (Field Programmable Gate Array): Contains arrays of reconfigurable logic blocks programmable to realize logic functions 🧩. Connectivity is programmable; can be reprogrammed ♻️
*   ASIC (Application-Specific Integrated Circuit): Dedicated IC designed for a specific application 🎯. Offers higher performance, lower power, and smaller area for high-volume production

---

## FPGA Implementation - Architecture 🏛️

*   FPGA contains arrays of reconfigurable logic blocks arranged as a matrix 🧱
*   Key blocks:
    *   Configurable Logic Blocks (CLBs): Programmed to implement logic functions 🧩
    *   Input/Output Blocks (IOBs): Interface with external pins 🔌
    *   Programmable Interconnect: Connects CLBs and IOBs 🕸️. Includes various types of lines (Long, Hex, Double, Direct) programmed via switches
    *   Most modern FPGAs are SRAM Based, using static memory cells for programming logic and connectivity
    *   Advanced FPGAs may also contain SRAM blocks (BRAMs), DSP Blocks, PLLs, Clock Managers, GPIOs, SERDES, Hard Processor Cores, Peripherals

---

## FPGA Implementation - Flow 🌊

*   The implementation process follows a specific flow:
*   Design Entry: Writing the design description (e.g., Verilog HDL) ⌨️. HDL-based entry is common and faster for complex designs
*   Synthesis: Translates HDL code into a netlist using actual hardware elements (gates, flip-flops) ⚙️. Checks syntax/hierarchy, performs logic optimization. Generates an NGC file. Provides an estimate of hardware utilization
*   Implementation: Consists of Translate, Map, and Place & Route 🗺️

---

## FPGA Implementation - Implementation Steps 📐

*   Translate: Combines input netlists and constraint files (hardware, timing - UCF/SDC) into a logic design file (NGD file) 🔄
*   Map: Subdivides logical elements to fit into FPGA logic blocks (CLB, IOB) 🗺️. Generates an NCD file representing the mapped design. Constraint info saved in PCF file. Optimization algorithms can trim/remove logic ✂️
*   Place and Route (PAR): Places mapped subblocks into logic blocks and routes connections between them 🔗. Aims to meet timing requirements. Generates a routed NCD file

---

## FPGA Implementation - Post-PAR & Tools 🛠️

*   After PAR, Static Timing Analysis (STA) is performed using timing reports to check if specifications are met ⏱️
*   If not, design or constraints are modified 🔄
*   Once timing is met, BitGen program generates the .bit file used to program the FPGA device 💾
*   FPGA Editor is a graphical tool to view, modify, and debug the implemented design 🐞, including placing/routing critical paths, adding probes, or even manual design

---

## ASIC Implementation - Flow 🏭

ASIC implementation involves several stages:
Simulation: Functional verification using simulation tools (e.g., Incisive Simulator) 🧪. Requires passing Linting checks
Synthesis: Translates validated HDL into a netlist using standard cells from a library ⚙️. Requires timing constraints (SDC) and library files (LIB). DFT (Design For Testability) analysis and scan cell insertion can occur 🔍

---

## ASIC Implementation - Place & Route (PnR) 🗺️

*   Performed after successful synthesis ✅
*   Requires input files: Post-synthesis Netlist, Liberty Timing Models (.lib), Synopsys Design Constraints (.sdc), Power Management files (CPF) for low power ⚡
*   Liberty files contain cell info, timing conditions, wire load models, operating conditions, and Design Rule Constraints (DRC) 📜
*   Multiple timing libraries (fast-fast, slow-slow, typical) and RC corners are considered for timing analysis views (MIN/MAX, setup/hold)

---

## ASIC Implementation - PnR Steps 📍

*   Design Initialization: Importing required files 📂
*   Create and Load Floor Plan: Defining the layout area; logic area can be automatically calculated or customized 📐
*   Placement: Placing standard cells and macro cells within the floor plan 🧩. Aims to minimize wire length and meet timing
*   Clock Tree Synthesis (CTS): Balances clock arrival times to sequential elements to minimize skew and jitter ⏰
*   Routing: Making physical connections between cells based on logical netlist 🔗. Includes Power Routing (Vdd, Gnd). Signal Integrity (SI) driven routing reduces noise; timing driven routing focuses on critical paths

---

## ASIC Implementation - Post-Route Checks ✅

*   After routing and optimization, final checks are performed:
*   Logic Equivalence Check (LEC): Again verifies logical similarity between the post-route netlist and the original design 🔄
*   Timing Checks: Confirms the design meets all timing constraints (setup, hold, transition) ⏱️
*   Physical Checks:
*   Layout Versus Schematic (LVS): Verifies the layout matches the schematic/netlist connectivity 🔍
*   Design Rule Checks (DRC): Ensures the layout adheres to manufacturing rules 📏

---

## Timing Analysis (STA) - Importance ⏱️

*   Digital system timing verification is crucial because logic simulations ignore practical aspects like routing delay and process variations 🚨
*   Designs that work in simulation may fail when implemented on hardware ❌
*   Static Timing Analysis (STA) is a popular technique for timing verification 🔍
*   It increases the yield of good ICs 📈
*   STA involves dividing the design into timing paths, calculating delays, and checking against constraints

---

## Timing Analysis - Definitions 📖

*   Relevant timing definitions are discussed:
*   Slew: Rise/fall time of a waveform 📈
*   Clock Jitter: Variation in clock period 🌀
*   Clock Latency: Delay from clock source to flip-flop clock pin ⏳
*   Clock Skew: Difference in clock arrival times at different points ↔️
*   Clock Uncertainty: Accounts for jitter, phase variations, etc. ❓
*   Clock-to-Q Delay (Tcc2q/Tpc2q): Delay from clock edge to data output of a flip-flop (contamination/propagation) ⏲️
*   Combinational Logic Timing (Tcd/Tpd): Delay through logic gates (contamination/propagation) ⏱️
*   Net Delay: Delay through wires 🔌

---

## Timing Analysis - Setup and Hold Times ⏱️

*   **Setup Time (Tsu)**: The minimum time data must be **stable and available *before*** the active clock edge at the flip-flop input. ⏳
*   **Hold Time (Th)**: The minimum time data must remain **stable and available *after*** the active clock edge at the flip-flop input. 🔒
*   These are critical requirements for sequential circuit reliability. ⚠️

---

## Timing Analysis - Required & Arrival Times 🕒

*   **Arrival Time**: The actual time data arrives at a specific point (e.g., flip-flop data pin). It includes launch flip-flop clock-to-Q delay, logic delay, and net delay. 🚀
*   **Required Time**: The time by which data **must arrive** at a specific point to meet timing requirements (setup/hold). It is constrained by the capture flip-flop's timing requirements and the clock period. ⏰

---

## Timing Analysis - Slack ⏳

*   **Slack** is the difference between the Required Time and the Arrival Time. ↔️
*   **Setup Slack = Required time - Arrival time**. Positive slack means setup requirement is met. ✅ Negative slack indicates a setup violation. ❌
*   **Hold Slack = Arrival time - Required time**. Positive slack means hold requirement is met. ✅ Negative slack indicates a hold violation. ❌

---

## Timing Analysis - Timing Checks 🔍

*   **Setup Timing Check**: Ensures data arrives early enough *before* the clock edge. ⏱️
*   **Hold Timing Check**: Ensures data remains stable long enough *after* the clock edge. 🔒
*   **Asynchronous Checks**: For signals not synchronous to the main clock, includes **Recovery Time Check** and **Removal Time Check**. Recovery is like setup for an asynchronous deassertion; Removal is like hold for an asynchronous assertion. ⚠️

---

## Timing Analysis - Timing Paths & Constraints 🛣️

*   STA analyzes different kinds of **timing paths**: Input-to-register, register-to-register, register-to-output, input-to-output. 🔄
*   Other path types: **False Paths** (paths that can never be activated by circuit logic, excluded from timing) 🚫 and **Half Cycle Paths** (between flip-flops triggered on opposite clock edges) ⏳.
*   **Timing Constraints** define performance requirements (e.g., clock period, I/O delays). Written in files like **SDC (Synopsys Design Constraint)**. 📜
*   **Worst Negative Slack (WNS)**: The smallest (most negative) slack in the design. Positive WNS means timing is met. ✅
*   **Total Negative Slack (TNS)**: Sum of all negative slacks. Zero TNS means all paths meet timing. 🎯 Targeting TNS addresses violations on all critical paths.

---

## Low-Power Design - Introduction 🔋

*   Designing for **low-power consumption** is as important as design for area and speed. ⚡
*   Power reduction techniques are a major area of research. 🔬
*   Two types of power consumption in an IC:
    *   **Peak power consumption**: Can cause immediate harm. ⚠️
    *   **Time average power consumption**: Critical for IC size and power source life. ⏳
*   Power consumption can be reduced at **various abstraction levels** in the design hierarchy. Higher levels (algorithmic/architectural) offer more reduction scope. 📊

---

## Low-Power Design - Sources of Power ⚡

*   Overall average power consumption has four components:
    *   **Pswitching**: Dynamic power due to charging/discharging load capacitance. 🔄
    *   **Pshort-circuit**: Power consumed when both PMOS and NMOS transistors are momentarily on during transitions. ⚡
    *   **Pleakage**: Power due to leakage currents (reverse-bias junction, sub-threshold). 💧
    *   **Pstatic**: Power consumed when the circuit is idle, mainly due to leakage. 🛑
*   **Switching power** is often the major issue in digital circuits. 🔌

---

## Low-Power Design - Reducing Switching Power 🔋

*   Switching power can be reduced by:
    *   Reducing **operating voltage** (quadratic effect). 📉
    *   Reducing **operating frequency**. 🐢
    *   Reducing **switching activity**. 🔄
*   Switching activity reduction can be achieved via **algorithmic** or **architectural** modifications. 🏗️

---

## Low-Power Design - Architectural Optimization 🏗️

*   Techniques include:
    *   Selection of **Data Representation Techniques** (e.g., Signed magnitude vs Two's complement can affect transitions). 🔢
    *   Ordering of **Input Signals** or operations to reduce transition activity. 🔄
    *   Reducing **Glitch Activity**: Extra transitions before settling. Can be reduced by choosing a balanced circuit **Topology** instead of chained structures. ⚡

---

## Low-Power Design - More Architectural Techniques 🏗️

*   **Logic Level Power Down**: Deactivating execution units that are not operating, saving power in synchronous circuits (requires extra logic). Easier in asynchronous designs. 🔌
*   **Loop Unrolling**: Can expose more parallelism but may increase hardware and power. 🔄
*   **Operation Reduction / Substitution**: Using dedicated units or optimized sequences to compute results with fewer total operations. May impact critical path. ✂️
*   **Re-timing**: Moving registers to optimize paths, can potentially reduce switching. ⏱️
*   **Wordlength Reduction**: Decreases hardware resources (capacitance), thus reducing power. Must balance power savings with accuracy requirements. 🔢
*   **Resource Sharing**: Reusing hardware for different operations. 🔄

---

## Low-Power Design - Clock Gating ⏰

*   A common technique to reduce dynamic power. ⚡
*   Disables the clock signal to idle parts of the circuit, preventing unnecessary switching. 🚫
*   Various techniques exist: Gate-based, Latch-based, Flip-flop-based, Synthesis-based, Data-driven, Auto-gated, Look-ahead-based. 🔧
*   **Latch-based clock gating** is shown as an example; avoids glitches better than simple gate gating. ⚡
*   Even clock gating circuits consume power; schemes exist to reduce this. 🔋

---

## Advanced Topics - System-on-Chip (SoC) 🖥️

*   Integration of processor (CPU) and FPGA onto a **single IC** 🖥️.
*   Reduces power and area compared to discrete components. 📉
*   The whole embedded system is fabricated on one IC. 🔌
*   FPGA typically handles **fast data processing and parallelism**. ⚡
*   Processor handles **interfacing devices and serial functions**. 🔄
*   Offers advantages in real-time operations compared to ASIC-based embedded systems. ⏱️
*   FPGA-based SoCs have the extra advantage of **reconfigurability**. 🔄

---

## Advanced Topics - Partial Reconfiguration (PR) 🔄

*   Also known as Dynamic Partial Reconfiguration (DPR).
*   Allows **reprogramming only a portion** of the FPGA while the rest of the design remains active. 🛠️
*   Enables changing functionality on-the-fly. 🔄
*   Complex process, supported by advanced EDA tools (Xilinx Vivado, Intel Quartus). Open-source alternatives also exist. 🛠️
*   DPR flow involves partitioning the design into static and reconfigurable regions, floorplanning, implementing static logic, implementing reconfigurable modules (PRMs), and merging bitstreams. 🔧

---

## Digital System Design Examples 📚

*   The book includes examples to help readers design their own systems. 🏗️
*   Examples cover important areas.
*   **Digital Filters**: Finite Impulse Response (FIR) and Infinite Impulse Response (IIR) filters. FIR filters are always stable and can produce linear phase. IIR filters have feedback. Implementation aspects and performance comparisons of different structures are discussed. 🔄

---

## Conclusion 🎯

*   Advanced Digital System Design involves creating optimized hardware implementations for complex algorithms. 🏗️
*   Verilog HDL is a key tool for modeling these systems. 🔧
*   Understanding basic building blocks (combinational, sequential) is foundational. ⚙️
*   Efficient arithmetic design is crucial for performance. 🔢
*   Memory and FSMs are essential components for data storage and control logic. 🧠
*   Implementation on FPGAs and ASICs involves detailed flows and requires careful timing and power analysis. ⏱️⚡
*   STA (Setup/Hold, Slack) ensures designs meet speed requirements. ✅
*   Low-power techniques (Algorithmic/Architectural, Clock Gating) are vital for modern designs. 🔋
*   Advanced concepts like SoCs and Partial Reconfiguration offer powerful capabilities. 🚀

---

count: false
class: nord-dark, middle, center

.pull-left[

# Q & A 🎤

] .pull-right[

![Discussion](figs/questions-and-answers.svg)

]