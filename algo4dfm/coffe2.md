layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# COFFE 2: Automatic Modelling and Optimization of Complex and Heterogeneous FPGA Architectures 🔬✨

@luk036 👨🏻‍🏫

2025-05-12 📅

---

### Credit
*   **Title:** COFFE 2: Automatic Modelling and Optimization of Complex and Heterogeneous FPGA Architectures 🔬✨
*   **Authors:** Sadegh Yazdanshenas and Vaughn Betz, University of Toronto 🎓
*   **Source:** ACM Transactions on Reconfigurable Technology and Systems, Vol. 12, No. 1, Article 3 (January 2019) 📄

---

### Introduction - The Evolution of FPGAs 🚀
*   Over the past two decades, FPGAs have evolved significantly. 📈
*   They started as homogeneous compute platforms with simple logic blocks and memory. 🧱
*   Modern FPGAs are sophisticated systems-on-chip featuring: 💎
    *   Complex logic blocks with hard arithmetic. ➕
    *   Digital Signal Processing (DSP) blocks. 🔊
    *   Embedded hard processors. 🧠
    *   Hard PCIe interfaces. 🔌
    *   Hard memory controllers. 💾
    *   ...and much more. ✨
*   This evolution has made FPGAs increasingly **heterogeneous**. 🌈

---

### Why Increasing Heterogeneity? 📈
*   FPGAs are becoming more heterogeneous to better adapt to different markets. 🌐
*   Emerging markets demanding this evolution include: 🚀
    *   Machine learning 🤖
    *   Datacenter accelerators 🖥️
    *   5G wireless 📶
    *   The Internet of things 🌐
    *   ...and more. ✨
*   Examples of recent hard blocks:
    *   Hard forward error correction blocks (Xilinx). 🔄
    *   Hard floating point DSPs (Intel Stratix 10). 🔢
    *   Hard I2C controller (Lattice CrossLink). 🎛️
    *   Power management unit (Lattice CrossLink). ⚡
    *   Hard Networks-on-Chip (proposed/integrated). 🌐

---

### The Need for Architecture Exploration 🤔
*   With many emerging markets, researchers have ample opportunity to explore various architectural ideas to improve FPGAs. 🔍
*   To evaluate an architectural idea, FPGA architecture researchers need three sets of tools: 🛠️
    1.  **Benchmark circuit suite:** Application-specific or existing suites like MCNC, VTR, Titan.
    2.  **CAD flow:** Tools like VTR supporting synthesis, placement, and routing. ⚙️
    3.  **Accurate physical description:** A description of the FPGA, enhanced with the architectural idea. 📐
*   The last requirement is the most time-consuming. ⏳

---

### The Modelling Gap 🛠️🚫
*   Contemporary FPGA blocks are designed using a mix of full custom and standard cell flows. 🔄
*   **Manual design and optimization** of such blocks can take **months**. This significantly limits the number of architectural ideas that can be explored. ⏳
*   Existing FPGA circuit design tools can only model **simple, homogeneous** FPGA architectures with basic logic blocks. 🧱
*   They **lack support** for DSP and other heterogeneous blocks. ❌
*   Modern FPGAs are composed of many different tiles, designed using a mix of full custom and standard cell styles.

---

### Introducing COFFE 2 🎉✨
*   To fill this modelling gap, we introduce **COFFE 2**. 🎯
*   COFFE 2 is an **open-source FPGA design toolset** for automatic FPGA circuit design. 🔓
*   It uses a **mix of full custom and standard cell flows**. 🔄
*   COFFE 2 supports not only complex logic blocks but also **arbitrary heterogeneous blocks**. 🌈
*   Complex logic blocks supported include those with **fracturable lookup tables** and **hard arithmetic**. ➕
*   COFFE 2 provides an interface to **VTR** allowing full evaluation of block-routing interfaces and various fracturable 6-LUT architectures. ↔️

---

### COFFE 2 Key Capabilities & Contributions ✅
*   Facilitating **automatic and accurate generation and optimization** of FPGA heterogeneous blocks from arbitrary HDL. 🤖
    *   Provides area, delay, and power consumption estimates.
    *   Generates architecture files for the VTR CAD flow. 📂
*   Adding support for **advanced logic blocks** with industrial-style floorplanning. 🏗
    *   Includes **fracturable LUTs** and **hard arithmetic**. ➕
*   Enables evaluation of **multi-mode heterogeneous blocks** and their connectivity. 🔄
*   Allows architecture exploration of **fracturable logic tiles enhanced with hard arithmetic**. 🔍
*   More detailed **wire load modeling** via automatic floorplanning. 🧵
*   Accurate **power consumption estimation** for multi-mode heterogeneous blocks. ⚡

---

### Overview of COFFE 2's Flow 🏗️🔄
*   COFFE 2 uses a combination of **full custom and standard cell circuit design flows**. 🔄
*   **Logic tile modelling** uses the **full custom** flow. 🧱
*   **Heterogeneous block modelling** uses **both** flows. ↔️
*   **Full Custom Flow:** 🛠️
    *   Generates parameterized HSPICE netlists. 📜
    *   Estimates component area and creates a tile floorplan. 📐
    *   Determines wire lengths based on floorplan and calculates R/C using wire load models. 🧵
    *   Iteratively sizes transistors to optimize a **user-defined objective function** (weighted area/delay). 🔄
    *   Floorplan and wire load determination are repeated in sizing iterations. 🔁

---

### Overview of COFFE 2's Flow (Cont.) 🏗️⚙️
*   **Heterogeneous Block Modelling (Hybrid Flow):** 🔄
    *   The **core** of the block is synthesized, placed, and routed using a **standard cell (ASIC) flow**. ⚙️
    *   Information (like wire data) is passed from the standard cell flow to the full custom flow. ↔️
    *   The **interfaces** to the global routing fabric are optimized and modelled using the **full custom flow**. 🛠️
*   **Power Estimation:** ⚡
    *   Supports power estimates for any tile. 🔋
    *   Can use a switching activity factor or a user-provided testbench for more accurate estimates.
    *   Important for **multi-mode heterogeneous blocks** where power consumption varies. 🔄

---

### Modelling Logic Tiles 🧠🔌
*   A logic tile typically includes: 🧩
    *   Switch block muxes (connect to global routing, inter-tile switching). ↔️
    *   Connection block muxes (global routing to tile). 🔌
    *   Input crossbar muxes (global signals to logic elements, intra-tile routing). 🎛️
    *   Logic elements. 🧠
*   COFFE 2 supports **advanced logic blocks**. 💎
    *   **Fracturable LUTs:** Split into two smaller LUTs, supporting shared and independent inputs. ✂️
    *   **Hard arithmetic:** 1 or 2 bits of arithmetic per fracturable LUT. Supports carry ripple or carry skip schemes. Uses a custom-designed full adder. ➕

---

### Logic Tile Floorplanning & Wire Load 🗺️📏
*   **Wire load modelling is essential** for accurate transistor sizing, delay modelling, and architectural conclusions. 🧵
*   COFFE 2 adds a new algorithm for **realistic floorplans** for full custom logic and routing tiles. 🏗️
*   This floorplanning provides **physical awareness** (coarse placement) enabling more detailed wire load modelling. 📐
*   COFFE 2 uses a **constrained, stripe-based floorplan**, similar to industrial FPGAs (Figure 5 example). 🧱
*   Determines intra-stripe wire lengths based on area *and* component aspect ratio. Wires cross the longer dimension. ↔️
*   Accurately determines inter-stripe wire lengths based on stripe position, width, and port location parameters. 📏
*   COFFE 2 optimizes the height of the logic tile and width of stripes to minimize the user's objective function (area^a * delay^d).

---

### Modelling Heterogeneous Blocks (e.g., DSPs)
*   Heterogeneous blocks often use a mix of standard cell and full custom design flows. 🔄
*   COFFE 2 supports automatic optimization and modelling of such blocks. 🤖
*   **Core:** Synthesized, placed, and routed using a standard cell flow. ⚙️
*   **Routing Interfaces:** Optimized and modelled using the full custom flow. 🛠️
*   **Flexible User Interface:** Allows modelling and optimization of arbitrary heterogeneous blocks described in supported HDL (Verilog, VHDL, System Verilog). 🎛️
    *   Settings for general, synthesis, place & route, final analysis, scaling, and architecture parameters. ⚙️
    *   Supports exploring multiple settings (clock period, core utilization, wire load tables, metal layers) to find the optimum. 🔍
    *   Allows specifying aspect ratio, target core utilization, and number of metal layers. 📐
    *   Crucially, users can specify **modes of operation** for timing and power analysis. ⏱️⚡
    *   Supports technology scaling factors for area, delay, and power. 🔄

---

### DSP Block Example in COFFE 2 🔢✨
*   To demonstrate heterogeneous block capabilities, a simplified **Stratix III-like DSP block** with three modes was modelled. 🧮
    *   Mode 1: Four independent 18-bit multiplications. ✖️
    *   Mode 2: Eight independent 9-bit multiplications. ✖️
    *   Mode 3: Multiply and accumulate (sum of eight products). ∑
*   The complexities of this multi-mode block validate COFFE 2's capabilities. ✅
*   Experiments used TSMC 65nm standard cells. 🔬
*   Limited metal layers used for the DSP core (4 layers). 🧱
*   Explored target frequencies, core utilizations, and wire load models. 🔍
*   The optimal design points occurred at 550 and 600MHz using aggressive wire load, aligning with Stratix III's 550MHz maximum frequency. This provides **indirect validation**. ✅

---

### Importance of Place & Route for Heterogeneous Blocks ⚙️✅
*   Experiments show that **predicting the best optimization settings or final area/delay after synthesis alone is not reliable**. ❌
*   Post-synthesis results differ significantly from post-place-and-route results, especially at higher frequencies.
*   Figure 14 shows little correlation between post-synthesis and post-place-and-route optimal design points. 📈
*   **Therefore, running the entire standard cell flow (including place and route) is important to obtain accurate results for heterogeneous FPGA blocks**. ✅

---

### DSP Block - Area Breakdown & Validation 📊📏
*   Figure 15 shows area breakdown for different DSP block variations.
*   Adding a large input crossbar increases area by 35%. 📈
*   Adding multiple smaller crossbars (like LB-like) increases area by 9%, offering less routability enhancement. ↔️
*   Modifying the block to support eight independent 18-bit multiplications increases block area by only 5%. However, system-level impacts need evaluation. 🔍
*   **Area Validation:** The DSP/logic tile area ratio in Stratix III is 11.9. Our LB-like crossbar DSP block has a ratio of 7.7, which is in good agreement considering Stratix III DSPs have more features and optimization for delay. ✅

---

### DSP Block - Power Validation ⚡🔋
*   COFFE 2's power flow was validated by investigating power trends across operating modes. 🔍
*   Comparison was made against Intel/Altera's early power estimator (EPE) for Stratix III. ⚖️
*   Figure 16 shows power normalized to the 4x18-bit multiplication mode.
*   **COFFE 2 is indeed capable of properly estimating the power consumed in different modes of operation** for the 8x9-bit independent multiplication and multiply and accumulate modes. ✅
*   Absolute power estimates are also relatively close (COFFE 2 ~28% below Stratix III EPE for one mode), considered reasonable agreement given architectural differences. 👍

---

### Importance of Physical Awareness - Experimental Results 🗺️📉
*   A major feature of COFFE 2 is its more detailed wire load modelling driven by an automated floorplanner. 🧵
*   Experiments compare sizing with and without wire load modelling. ⚖️
*   **Neglecting wire loads causes significant underestimation of FPGA area and delay**. ❌
    *   Delay underestimation ranges from 9% to 82% across different components and cost functions (Table 3).
    *   Area underestimation also varies significantly (Table 3).
*   This means neglecting wire loads causes both large absolute errors and **poor fidelity** across components. Comparisons without physical awareness are not accurate. ❌
*   Floorplanning tends to **increase inter-tile routing delays** (27% for switch blocks, 17% for connection blocks) compared to original COFFE estimates, due to longer wires. 📈
*   LUT delays can be reduced (2% to 9%) as internal wiring can be kept compact.

---

### COFFE 2 Runtime ⏱️⚡
*   Table 4 shows example runtimes for various architectures. ⌛
*   Runtimes range from 5.6 hours (4-LUT + Stratix III-like DSP) to 17.1 hours (6-FLUT-5 + 256kb MTJ BRAM). ⏳
*   Logic tile floorplanning adds 2% to 7% of runtime, dominated by SPICE sweeps. 🔬
*   For the DSP architecture, the standard cell flow (synthesis, place, route) takes about half an hour; the rest is sizing logic blocks and routing interfaces. ⚙️

---

### Architecture Exploration - Fracturable LUT (FLUT) Case Study (1/2) 🧠📊
*   FLUTs are used in many modern FPGAs (Altera/Intel since Stratix II, Xilinx since Virtex-5). 🧩
*   Prior studies had conflicting conclusions on FLUT benefits. One found 18% area-delay product improvement, another found 75% increase. Microsemi study found 4% area savings. 🤔
*   These differences highlight the need for tools supporting a wide range of logic elements and providing detailed models. COFFE 2 supports parameterized FLUTs and hard arithmetic. 🛠️
*   **Methodology:** Used the full VTR benchmark suite and CAD flow (ODIN II, ABC, VPR). Included hard arithmetic. Explored cluster input counts (found 28 optimal). 🔍

---

### Architecture Exploration - Fracturable LUT (FLUT) Case Study (2/2) 📊📈
*   **Logic Tile Count:** FLUTs significantly reduce the number of logic blocks required.
    *   Approximately **20% reduction** for 6-FLUT-0 (no independent inputs).
    *   Up to **25% reduction** for 6-FLUT-5 (5 independent inputs).
*   Hard arithmetic is important; lack of it reduces logic tile reductions by ~5%. ⚠️
*   **System-Level Results (Figure 19):**
    *   Most FLUT architectures (except 6-FLUT-5) yield an improvement in the **geometric mean of area-delay product**. ✅
    *   Highest average improvements with 6-FLUT-0 and 6-FLUT-1. 🏆
    *   Geometric mean area reduced by 11% (FLUT-0) and 12% (6-FLUT-1).
    *   Slight performance improvement (<1%) due to packing more logic per tile, reducing global routing hops. ↔️
*   Best architecture varies per circuit, but most prefer FLUT-0 or FLUT-1 (Table 5).

---

### Architecture Exploration - DSP Case Study 🔢📊
*   Evaluated the impact of different routing interfaces and variations of the Stratix III-like DSP block at the system level using VPR. 🔍
*   Used DSP-intensive VTR benchmark circuits. 🧮
*   **Results (Figure 20):** 📈
    *   Using one large crossbar increases area (DSP block is larger) but improves delay for most circuits due to enhanced routability. ↔️
    *   Using **multiple smaller crossbars** improves both delay and used area, as routing track requirements might decrease and the area penalty is moderate. ✅
    *   The variation supporting eight independent 18-bit multiplications showed mixed results depending on the circuit. On average, both area and delay increased due to **local routing congestion** from increased output signals, potentially leading to longer routing paths and wider routing channels. ⚠️

---

### Conclusion - COFFE 2's Impact ✅🔬
*   We presented **COFFE 2**, an open-source FPGA architecture evaluation tool. 🎯
*   It can automatically optimize and model circuitry for state-of-the-art **heterogeneous FPGAs**. 🌈
*   **Capabilities:** Models memory blocks, advanced logic tiles (fracturability, hard arithmetic), and arbitrary heterogeneous blocks. 🧩
*   **Key Feature:** Physically aware modelling - full custom components floorplanned, standard cells placed and routed. 🗺️
*   **Validation:** High level of detailed modelling resulted in **good agreement with publicly available commercial FPGA data** (Stratix III DSP frequency and area ratio, power trends). ✅
*   **Demonstrated Capabilities:** Performed system-level architecture explorations for FLUTs and DSP routing interfaces using COFFE 2's interface to VTR. 🔍
*   **Future:** COFFE 2's broad architectural support and detailed modelling will enable future research into general and domain-specific FPGAs. 🚀

---

count: false
class: nord-dark, middle, center

.pull-left[

# Q & A 🎤

] .pull-right[

![Discussion](figs/questions-and-answers.svg)

]