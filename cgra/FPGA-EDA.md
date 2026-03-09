layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# FPGA-EDA: Unlocking the Power of Programmable Logic 🔓

@luk036 👨‍💻

2025-05-12 📅

---

### Introduction - What is FPGA-EDA? 🤔

- **FPGA**: Field-Programmable Gate Array. 🧩
  - Think of them as electronic "lego". 🧱
  - Unlike fixed-function chips (ASICs), FPGAs can be reconfigured for different tasks. ♻️
- **EDA**: Electronic Design Automation. 💻
  - A category of software tools used to design and verify electronic systems, like FPGAs. 🛠️
  - Essential because tasks like "pre-design" and "assemble" for FPGAs are too complex without computer help. 🤯
- **FPGA-EDA** enables not only designing to and programming an FPGA but also architecting new FPGAs and automating implementation. 🏗️
- This presentation covers the holistic approach to FPGA-EDA, from architecture to programming. 🌐

---

### A Brief Look at FPGA Hardware 🏗️

- **First Commercial FPGA**: Xilinx XC2064, invented in 1985. 🏛️
  - Contained 64 programmable logic units. 🔢
  - Enabled true "field" programmability. 🌾
  - Recognized by IEEE. 🏆
- **Modern FPGAs**: Composed of "island-type" units and "ocean-like" interconnect resources. 🏝️🌊
  - The "tile" is the first-level sub-unit. 🧱
- **Programmable Memory Types**: Different types affect characteristics. 💾
  - **SRAM**: Volatile, repeatable programmability, low latency, medium power, large area, low cost. 🔄
  - **Antifuse**: Non-volatile (Once), very low latency, very low power, very small area, very high cost. ⚡
  - Other emerging technologies mentioned include RRAM and MRAM. 🆕

---

### The FPGA Application Design Flow ⚙️

- The process for end-users to design and program an FPGA. 🔄
- **Traditional Flow**:
  1.  High-Level Synthesis (HLS). 🔝
  2.  Logic Synthesis. 🧠
  3.  Physical Implementation. 🏗️
  4.  Bitstream Configuration. ⚡
  5.  Simulation/Debugging (carried out throughout). 🐞
- **Data Sources**:
  - FPGA Device Data (Device Library). 📚
  - Design Data (Design Checkpoint). 💾

---

### High-Level Synthesis (HLS) - From C/C++ to Hardware ✨

- **Role**: Converts user's high-level abstract description (like C++, Python, etc.) into a lower-level hardware description (HDL, e.g., Verilog, VHDL). 🔄
- **Goal**: Raise the level of abstraction for FPGA design. 📈
- **Intermediate Representation**: Often involves converting programs into representations like Control/Data Flow Graphs (CDFG).
- **Scheduling**: A key task, specifying the execution order of operations, crucial for performance. Techniques include iterative modulo scheduling and dynamically scheduled circuits. ⏱️
- **Modern HLS**: Supports complex features like memory arbitration for multi-threaded code and speculative execution. 🧵
- **Commercial Tools**: AMD's Vitis, Intel HLS Compiler Pro Edition. 💼
- **Open-Source Tools**: LegUp, Bambu. 🐼
- **Challenges**: Bridging the gap between software concepts and hardware implementation. Design space exploration is a significant challenge. 🌌

---

### Logic Synthesis - Building Blocks (Gate-Level Netlist)

- **Role**: Converts the HDL design (output from HLS) into a design database containing a netlist of FPGA design units (like Look-Up Tables - LUTs and Flip-Flops - FFs) and their interconnections. 🔄
- **Key Steps**:
  - **Logic Optimization**: Simplifying the logic while preserving functionality. Includes:
    - **Combinational Optimization**: Deals with logic gates. 🚪
    - **Sequential Optimization**: Deals with registers and memory, aiming to reduce elements or latency. ⏳
  - **Technology Mapping**: Fitting the optimized logic onto the specific FPGA's programmable logic blocks (like LUTs). 🗺️
- **Optimization Techniques**: Boolean logic simplification (e.g., Majority-Inverter Graphs), Retiming, Register minimization. ✂️
- **AI in Logic Synthesis**: Machine Learning is being applied for various tasks like predicting routing congestion or guiding optimization. 🤖

---

### Physical Implementation - Placing and Wiring Components 🗺️

- **Role**: Decides how the logic netlist is physically mapped onto the target FPGA device. 🎯
- **Main Stages**:
  1.  **Packing**: Grouping logical elements into physical FPGA blocks (e.g., clustering logic into CLBs). Input is a synthesized netlist, output is a clustered netlist. 📦
  2.  **Placement**: Assigning packed blocks to specific locations on the FPGA fabric. Input is a clustered netlist, output is a placed netlist. 📍
  3.  **Routing**: Connecting the placed blocks by finding paths through the FPGA's interconnect resources. Input is a placed netlist, output is a routed netlist. 🛣️

---

### Physical Implementation - Placement Details 📍

- **Goal**: Assign physical locations to the packed logic blocks. 🎯
- **Common Algorithms**:
  - **Simulated Annealing**: A meta-heuristic approach that explores the solution space by accepting moves that might worsen the solution temporarily to escape local optima. Key aspects include placement schedule (annealing strategy). 🔥
  - **Analytic Placement**: Often used for larger designs.
- **Optimization Objectives**: Minimizing wirelength, reducing congestion, meeting timing constraints. ⏱️
- **AI in Placement**: Reinforcement learning and deep learning are being explored to improve placement quality and speed. 🤖

---

### Physical Implementation - Routing Details 🛣️

- **Role**: Connecting the pins of placed logic blocks using the FPGA's routing channels and switches. 🔌
- **Goal**: Successfully connect all required nets while minimizing wire delays and avoiding congestion. 🚦
- **Approaches**:
  - **Search-based**: Like maze routing or variations of Dijkstra's algorithm. Often uses negotiation-based routing where nets iteratively contend for resources. 🧩
  - **Boolean Satisfiability (SAT)-based**: Formulating routing as a SAT problem. 🔍
- **Optimization Objectives**: Routing nets with decreasing fanout order is a common schedule to manage congestion. Timing-driven routing prioritizes critical paths. ⏱️
- **AI in Routing**: Reinforcement learning is being applied to improve routing efficiency and quality. 🤖

---

### Metrics - Evaluating Design Quality

- **Key Metrics**:
  - **Power**: ⚡
    - Analyzed using power analysis engines, which use device libraries (power models) and design checkpoints (signal activities) as inputs.
    - Signal activities can be obtained via simulation-based (accurate but slow) or probabilistic-based (faster but less accurate) techniques.
    - Power reports are a typical output. 📄
  - **Performance (Timing)**: ⏱️
    - Analyzed using timing analysis engines, which use device libraries (timing models) and design checkpoints (timing constraints, timing graph). ⏳
    - Static Timing Analysis (STA) is a key technique. 🔍
    - Timing reports and Standard Delay Format (SDF) files are outputs.
  - **Area**: 📏
    - Analyzed using area analysis engines, using device libraries (area models, resource info).
    - Methods include layout-based and MWTA-based.
    - Area reports are outputs. 📄

---

### Bitstream Configuration - The Final Step! ✨

- **Role**: Converts the final implemented design into a bitstream file of a specific format. 🔄
- **Bitstream**: The "bottom level machine code" that programs the FPGA to perform the desired function. 💾
- **Bitstream Generation**: Extracts info from the design database and outputs the bitstream according to the configuration protocol. Efficiency (time) is a main concern. ⏱️
- **Bitstream Programming**: Downloading the generated bitstream into the target FPGA device. Techniques like JTAG are used. ⚡
- **Challenges**: Increasing bitstream file size due to growing FPGA capacity. Security threats (copying, reverse engineering, attacks). 🛡️
- **Solutions**:
  - **Bitstream Compression**: Reduces file size for better memory usage and bandwidth. 🗜️
  - **Bitstream Encryption**: Protects the design from unauthorized access or reverse engineering. Authentication ensures integrity. 🔒

---

### Semi-Custom EDA - Architecting New FPGAs 🛠️

- This portion focuses on designing the FPGA chip itself. 🎯
- Fast prototyping techniques have emerged using semi-custom design flows. 🚀
- **Goal**: Speed up the process of designing, evaluating, and producing new FPGA fabrics. ⏩
- **Open-Source Tools**: OpenFPGA is an example framework for agile prototyping of customizable FPGAs. Other tools include Archipelago, PRGA, FABulous. 🐧
- **Semi-custom flows** often involve automatically generating netlists, bitstreams, and testbenches. 🔄
- **Testbench Generation**: Essential for verifying FPGA fabrics before manufacturing. Testbenches validate correctness by applying stimuli and checking outputs. Preconfigured testbenches accelerate verification. ✅

---

### AI in FPGA-EDA - A Growing Trend 🧠

- AI-aided EDA engines are being applied across the flow. 🔄
- **Areas of Application**:
  - Logic Synthesis (e.g., guiding optimization, predicting metrics). 🧠
  - Physical Implementation (e.g., placement guidance, routing efficiency). 🏗️
  - High-Level Synthesis (e.g., design space exploration). 🌌
- ML-aided engines are starting to show superior performance compared to traditional methods. 📈

---

### Summary & Outlook ✨🔮

- **Vanilla FPGA-EDA**: Covers designing and programming user applications on FPGAs. Commercial tools are mature, with growing AI integration. 🏭
- **Architecting New FPGAs**: Enabled by semi-custom flows and tools like OpenFPGA. 🏗️
- **Programming Model Unification**: Major vendors (AMD/Xilinx, Intel) are working to unify programming using HLS and multi-platform languages (C++, Python, DPC++). 🤝
- **Open-Source EDA**: Tools like VTR, Yosys, Project X-ray, Project IceStorm are democratizing FPGA technology for research and industry. 🐧
- The field is continuously evolving, driven by the increasing complexity of FPGAs and the need for higher productivity and performance. 🚀

---

### Thank You & Questions 🙏

- **References**: The information presented is drawn from the provided excerpts, including works by K. Tu et al. on FPGA-EDA, IEEE publications, and various research papers cited within the text [e.g., 18, 19, 21, 23, 38, 55, 59, 72, 105, 109, 110, 111, 115, 118, 121, 130, 133]. 📚
- Ask for any questions! ❓

---

count: false
class: nord-dark, middle, center

.pull-left[

# Q&A 🎤

] .pull-right[

![Discussion](figs/questions-and-answers.svg)

]
