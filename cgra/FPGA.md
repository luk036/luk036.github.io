layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# 🔌 FPGA Architecture: Principles and Progression

@luk036 👨‍💻

2025-05-26 📅

---

### 💡 What are FPGAs? 🤔

- Field-Programmable Gate Arrays (FPGAs) are **reconfigurable computer chips** 🧠💻.
- They can be programmed to implement **any digital hardware circuit** 🛠️.
- Consist of an array of different types of programmable blocks (logic, IO, others) 🧩.
- These blocks are **flexibly interconnected** using pre-fabricated routing tracks with programmable switches 🛤️.
- Functionality is controlled by millions of **SRAM cells programmed at runtime** 💾.
- User designs are typically described in HDL (Verilog, VHDL) or translated from high-level languages (C, OpenCL) using High-Level Synthesis (HLS) 📚.
- Designs are compiled into a **bitstream file** that programs the SRAM cells ⚙️.

---

### ✨ Why Use FPGAs? Advantages 🌟

- **Low-level hardware reconfigurability** allows for much faster design cycles and lower development costs compared to custom-designed chips (ASICs) ⚡💰.
- **Much lower non-recurring engineering (NRE) cost** and **shorter time-to-market** compared to building a custom ASIC 🚀⏱️.
- A pre-fabricated, off-the-shelf FPGA can implement a complete system in weeks 📅.
- **Skips physical design, layout, fabrication, and verification stages** required for ASICs 🏗️➡️🎯.
- Allows **continuous hardware upgrades** after deployment by loading a new bitstream ("field-programmable") 🔄💡.
- Compelling solution for **medium and small volume designs** 📊.

---

### 📈 FPGAs vs. Alternatives ⚖️

- **Bit-level reconfigurability** allows FPGAs to implement the exact hardware needed for an application (customizable datapath, pipeline, memory, etc.) 🎛️.
- This contrasts with the **fixed, one-size-fits-all architecture** of CPUs and GPUs 🔄.
- Consequently, FPGAs can achieve **higher efficiency** than CPUs or GPUs by implementing instruction-free streaming hardware or customized processor overlays 🏎️💨.
- **However, flexibility comes at an efficiency cost vs. ASICs** ⚠️.
- Circuits using only programmable logic average **35x larger and 4x slower** than ASIC implementations 📏⏱️.
- For designs using other blocks (RAMs, DSPs), the area gap reduces but is still **~9x** 📉.
- FPGA architects constantly seek to reduce this gap while maintaining programmability 🔍.

---

### 🗺️ FPGA Architecture Components - Progression 🚀

- FPGAs evolved from **simple arrays** of programmable logic and IO blocks 🧱.
- They are now **complex heterogeneous multi-die systems** 🏗️.
- Modern FPGAs include:
  - Embedded Block RAMs (BRAMs) 💾
  - Digital Signal Processing (DSP) blocks 🧮
  - Processor subsystems
  - Diverse high-performance external interfaces 🌐
  - System-level interconnect (Network-on-Chip) 🛣️
- All blocks are interconnected using **bit-level programmable routing** 🔌.

---

### 🧪 Evaluating FPGA Architectures

- Evaluating new FPGA architecture ideas involves a complex flow 🔄.
- Three main components:
  1.  **Benchmark applications**: Representative circuits to test the architecture 🧪 (e.g., VTR, Titan suites)
  2.  **Architecture model**: Captures design decisions from high-level organization to transistor-level details 📐. Includes architecture description file, area, timing, and power models.
  3.  **Computer-Aided Design (CAD) system**: Maps benchmark applications onto the architecture 🗺️. Involves synthesis, mapping, placement, and routing.
- Key metrics evaluated: **Total area, maximum frequency (timing), and power consumption** 📊.
- Metrics are averaged across benchmarks.
- Evaluation blends metrics based on architecture goals (e.g., high performance vs. low power) ⚖️.

---

count: false
class: nord-light, middle, center

# Programmable Logic

---

### 🧱 Programmable Logic - Evolution

- Earliest reconfigurable devices: **Programmable Array Logic (PALs)** 🏛️.
  - Array of AND gates feeding OR gates ➕.
  - Implement two-level sum-of-products.
  - Configurability via programmable switches selecting inputs 🔘.
  - **Did not scale well** due to increasing wire length and quadratic growth in switches 📈.
- **Complex Programmable Logic Devices (CPLDs)**: Integrated multiple PALs with crossbar interconnect 🔀. Solved some scalability but required more complex tools.
- **Lookup-Table-based (LUT-based) FPGAs**: Pioneered by Xilinx in 1984 🚀.
  - Array of SRAM-based LUTs with programmable interconnect 🧩.
  - **Scaled very well** and achieved much higher area efficiency than PAL/CPLD logic 📊.
  - **LUTs are now the fundamental logic element** in all commercial FPGAs.
- Alternative ideas like And-Inverter Cones (AICs) were investigated but found to have significantly larger area than LUTs ❌.

---

### 🧩 LUTs and BLEs 🧠

- A **K-LUT** implements any K-input Boolean function by storing its truth table in SRAM cells 💾.
- Inputs act as multiplexer select lines to choose an output from the 2^K truth table values 🔢.
- Circuit implementation uses **pass-transistor logic** with internal and output buffers to mitigate delay ⏱️.
- **Basic Logic Element (BLE)**: A K-LUT coupled with an output register (Flip-Flop) and bypassing multiplexers 🔄. Can implement just an FF or a LUT with registered/unregistered output.
- BLEs are typically clustered in **Logic Blocks (LBs)** 🏢.
  - An LB contains N BLEs and **local interconnect** (multiplexers) 🔌.
  - Local interconnect forms a local full or partial crossbar.

---

### 📏 Sizing LUTs and LBs 📐

- Over time, the size of LUTs (K) and LBs (N) has increased with device capacity 📈.
- Increasing K packs more functionality into a LUT, reducing LUT count and critical path logic levels, increasing performance ⚡.
- Increasing N captures more connections into fast local interconnect, decreasing demand for inter-LB routing 🛣️.
- **Trade-offs** ⚖️:
  - LUT area increases exponentially with K (due to 2^K SRAMs) 📊.
  - LUT speed degrades linearly with K ⏱️.
  - Crossbar local interconnect size increases quadratically and speed degrades linearly with N 📈.
- Empirical studies suggest **4-6 LUTs and 3-10 BLEs per LB** offer the best area-delay product ⚖️. 4-LUTs for better area, 6-LUTs for higher speed.
- Historically, early FPGAs had smaller LBs (e.g., Xilinx XC2000 had 2 3-LUTs, N=2, K=3) 🏛️. Size gradually increased (e.g., Virtex family: 4 4-LUTs, N=4, K=4; Apex 20K: 10 4-LUTs, N=10, K=4).

---

### Fracturable LUTs 🧩

- Introduced by Altera in 2003 (Stratix II) 🚀.
- Goal: Combine performance of larger LUTs with area efficiency of smaller ones ⚖️.
- Problem: Traditional 6-LUTs often under-utilized (64% use <6 inputs) ❗.
- A **fracturable {K, M}-LUT** can be configured as a single K-LUT or fractured into two LUTs up to size K-1, using ≤ K+M distinct inputs 🔀.
- Example: A 6-LUT internally composed of two 5-LUTs plus a 2:1 multiplexer 🔌.
  - Without extra ports, two 5-LUTs share all 5 inputs (limited packing) ⚠️.
  - Adding extra input ports and steering muxes (Fig 5(b)) makes it easier to pack two functions (e.g., Stratix II ALM: {6, 2}-LUT, 8 inputs, 2 outputs) ✅. Can implement 6-LUT or two 5-LUTs sharing 2 inputs (total 8 distinct inputs).

---

- Fracturable LUTs improved performance and reduced logic/routing area 📈.
- Xilinx adopted a similar approach (Virtex-5), minimizing extra circuitry for lower area but harder packing ⚖️.
- Recent studies suggest tightly coupled 4-LUTs can achieve performance near 6-LUTs with 4-LUT area/power benefits 💡.
- LB size continues to increase (e.g., Xilinx Versal: 32 BLEs) due to poor inter-LB wire delay scaling and to aid CAD tool runtime ⏱️.

---

### Registers (FFs) ⏱️

- Early FPGAs coupled a non-fracturable LUT with a single FF 🏛️.
- With fracturable LUTs, FPGAs added a second FF per BLE to register both outputs of a fractured LUT 🔄.
- Stratix V increased FFs to four per BLE to support deeply pipelined designs for higher performance ⚡. Shared inputs between LUTs and FFs using low-cost multiplexing.
- Stratix V also implemented FFs as **pulse latches** (Fig 6(b)) instead of edge-triggered FFs (Fig 6(a)) 🔄.
  - Removes one latch stage, reducing register delay and area 📉.
  - Acts as a cheaper FF with worse hold time ⚠️.
  - Pulse generators are shared within LBs; pulse width is programmable ⚙️.
  - Allows limited time borrowing. Hold violations can be solved by routing 🛣️.
- Xilinx also uses pulse latches in Ultrascale+.

---

### Arithmetic Hardening ➗

- Arithmetic operations (add, subtract) are very common (22% of logic elements in some designs) 🔢.
- Implementing arithmetic with LUTs is inefficient (e.g., ripple carry adder bit needs two LUTs) ❌. Leads to high logic utilization and slow critical paths due to series connections for carries.
- **All modern FPGAs include hardened arithmetic circuitry** in logic blocks ✅.
- Common principles for hardening arithmetic:
  - Re-use existing LUT routing ports 🔌.
  - Carry bits propagated on **special, dedicated interconnect** for speed ⚡.

---

- Hardening ripple carry structures yields large speed gains over LUTs (~3-4x for 32-bit adder) 📈. Hardening carry skip adders further improves speed.
- Xilinx Versal: Hardens carry logic for 8-bit look-ahead, implements sum/propagate/generate logic in LUTs [26, 29(a)]. 1-bit arithmetic per logic element 🔢.
- Intel Agilex: Hardens 2-bit carry-skip adders fed by 4-LUTs within a 6-LUT [26, 29(b)]. 2-bits arithmetic per logic element 🔢.
- Fracturable LUTs + 2 bits arithmetic is shown to be efficient. Dedicated arithmetic circuits increase average performance (75% for arithmetic microbenchmarks, 15% for general circuits) 📊.

---

### Hardening for DL 🧠

- Deep Learning (DL) workloads are increasingly important, with MAC operations as the core ⚙️.
- Low-precision MACs (8-bit or narrower) can be implemented efficiently in programmable logic 🎯. Uses LUTs for partial products and an adder tree for accumulation.
- Increasing density of hardened adders in logic fabric enhances performance for arithmetic-heavy apps like DL acceleration 🚀.
- Proposals incorporate **4 bits of arithmetic per logic element** 🔢.
- These proposals use existing routing ports, leveraging input sharing in multiplier arrays 🔌.
- Promising proposals increase MAC density by ~1.7x and improve speed, also reducing logic/routing area for general benchmarks (8%). **More arithmetic density benefits applications beyond DL** 🌟.

---

count: false
class: nord-light, middle, center

# Programmable Routing

---

### 🛣️ Programmable Routing - Overview 🗺️

- Programmable routing is **critical**, commonly accounting for **over 50%** of both fabric area and critical path delay ⚠️.
- Composed of **pre-fabricated wiring segments** and **programmable switches** 🔌.
- Allows connecting any function block output to any input by programming switches ⚙️.

---

- Two main classes of architecture:
  1.  **Hierarchical FPGAs**: Inspired by design hierarchy 🏗️. Use short wires for nearby connections, longer wires/multiple switches for distant ones (Fig 8). Popular in earlier FPGAs (Altera 7K, Apex 20K). Long wires at upper levels became problematic with process scaling (increasingly resistive) ⚠️. Less efficient for physically close blocks requiring multiple hops. Primarily used today for smaller FPGAs or embedded IP cores.
  2.  **Island-style FPGAs**: Pioneered by Xilinx 🏝️. Regular 2D layout of horizontal/vertical directed wire segments (Fig 9). Includes **routing wire segments, connection blocks** (block inputs to wires), and **switch blocks** (wires to wires). Most connections span small distances, implemented with few wires.

---

### Key Parameters & Switches ⚙️

- Good routing architecture balances connectivity for routability with minimizing wasted area ⚖️.
- Matches application needs: short wires for short connections (minimize capacitance/area), longer wires for long connections (avoid switch delay).
- Parameters include:
  - Connectivity from block pins to wires (Fc) 🔌
  - Connectivity from wire ends to other wires (Fs) 🔀
  - Wire segment lengths 📏
  - Routing switch pattern 🎛️
  - Electrical design of wires and switches ⚡
  - Number of wires per channel 🛣️

---

- **Switch Design (Fig 10)**:
  - Early FPGAs: **Pass gate transistors** controlled by SRAM. Smallest, but delay grows quadratically in series ⚠️.
  - Adding **tri-state buffers** improves speed at area cost ⚖️.
  - Most recent FPGAs: **Multiplexer built from pass gates followed by a buffer** (Fig 4(b)). Most efficient circuit design for most cases ✅. Called **direct drive switch**. Pass transistors are small, buffer drives wire capacitance. Wire can only be driven at one point. Direct drive improves area and speed.
  - Exceptions: Expensive/rare wires (long wires on wide metal, interposer wires) may use **multiple tri-state buffers** for more flexible usage 🔌.

---

### Wire Segmentation & Delay ⏱️

- Early island-style used only short wires (spanning 1 logic block) 🏛️.
- Later research showed longer segments improved efficiency (4 logic blocks segment reduced delay by 40%, routing area by 25%) 📈.
- Modern architectures include **multiple lengths**, but most plentiful are moderate length (e.g., 4 logic blocks) 📏.
- Longer segments (e.g., 16 logic blocks) achieve lower delay for long connections but require wide/thick metal on upper layers, which are limited ⚠️.
- Some architectures (Intel Stratix) connect long wires only to short wires, creating a routing hierarchy within island-style 🏗️.
- Local routing within logic blocks also acts as a small hierarchical cluster within the larger island-style network 🧩.

---

### Delay Challenges & Solutions ⚡

- **Major Challenge**: Delay of long wires is **not improving** with process scaling 📉. Chip-crossing delay is stagnating or increasing.
- Leads designers to **increase pipelining** to allow multiple clock cycles for long routes ⏱️.
- Solutions to make pipelining more effective:
  - **Integrating registers within the routing network** 🔌.
  - Intel Stratix 10: Routing drivers can be configured as pulse latches (Fig 6(b)), acting as registers with low delay but poor hold time ⚠️. Allows deep interconnect pipelining without expensive logic. Cannot use consecutive pulse latches.
  - Intel Agilex: Integrates actual registers (better hold time) on one-third of drivers (mitigates area cost) ⚖️.
  - Xilinx Versal: Adds bypassable, full-featured registers (with clock enable/clear) only on inputs to function blocks ✅.

---

count: false
class: nord-light, middle, center

# Programmable IO

---

### 🌐 Programmable IO - Overview & Challenges 🖥️

- FPGAs include **unique programmable IO structures** to communicate with a wide variety of devices 🌍. Make FPGAs the "communications hub".
- Single set of physical IOs must support many different IO interfaces and standards (voltage levels, electrical characteristics, timing, protocols) ⚙️. This is challenging.
- Programmable IO structures can take up a **large area** (e.g., Stratix II devoted 20-48% of die area to IO) 📏.
- Highest speed IOs implement **serial protocols** (PCIe, Ethernet) running at 28 Gb/s or more, embedding clock in data ⚡. Require separate differential-only IOs (serial transceivers) with less programmability.
- IO design is challenging due to **competing demands for speed and programmability** ⚖️.
- Distributing high IO bandwidth requires **wide soft buses** in the fabric, creating further challenges 🛣️.

---

### Techniques (Fig 11) 🛠️

- FPGAs use a combination of approaches for programmable IO:
  1.  **IO Buffers operating across a range of voltages** ⚡: Grouped into banks with separate Vddio rails. Different banks can operate at different voltages.
  2.  **Single-ended or Differential Standards** 🔄: Each IO can be used separately for single-ended, or pairs configured for differential.
  3.  **Programmable Drive Strengths & Termination** 🎛️: Multiple parallel pull-up/pull-down transistors allow adjusting drive strength. Programmable on-chip termination resistances minimize signal reflections.
  4.  **Programmable Delay Chains (PDC)** ⏱️: Allow fine delay adjustments for signal timing.
  5.  **Hardened Digital Circuitry on Input Path** 💾: Capture registers, double-to-single data rate (DDR) conversion registers, serial-to-parallel converters. This circuitry can often be bypassed.

---

- Most FPGAs also contain bypassable higher-level blocks connecting to groups of IOs, implementing protocols like DDR memory controllers 🧠.
- These approaches allow general-purpose IOs to service many protocols up to ~3.2 Gb/s. Serial IOs have their own hardened circuits for higher speeds (28+ Gb/s) ⚡.

---

count: false
class: nord-light, middle, center

# 💾 On-Chip Memory

---

### On-Chip Memory - The Need for Hard Blocks (BRAMs) 🧠

- Early FPGAs used FFs in logic blocks for memory 🏛️.
- As logic capacity grew, larger systems needing memory became common 📈.
- Building large RAMs out of registers and LUTs is **over 100x less dense** than ASIC-style SRAM blocks ❌.
- Application memory needs are diverse (small storage, large buffers, caches, FIFOs, etc.) 🗄️. No single RAM configuration is universal.
- Challenge: Deciding what kind(s) of RAM blocks to add for efficiency across diverse uses 🤔.
- First FPGA with hard memory blocks (**Block RAMs or BRAMs**): Altera Flex 10K in 1995 🚀. Included columns of small (2kb) BRAMs.
- Gradually incorporated larger/diverse BRAMs.
- Typical modern FPGA dedicates **~25% of area to BRAMs** 📊.

---

### 🏛️ BRAM Architecture & Decisions (Fig 12) 🏗️

- FPGA BRAMs consist of an **SRAM-based memory core** plus peripheral circuitry for configurability and routing interface ⚙️.
- SRAM core is a 2D array of cells. Peripheral circuitry orchestrates access (row/column decoders, write drivers, sense amplifiers) 🔍.
- All modern BRAMs **register all inputs** to simplify timing ⏱️.
- Main architectural decisions: **Capacity, data word width, number of read/write ports** 📊.
- Larger BRAMs: Lower area per bit (SRAM area grows linearly, periphery/ports sub-linearly) 📉. But capacity might be wasted for small RAM needs.
- Wider BRAMs: Higher data bandwidth, but cost more area due to more periphery (sense amps, write drivers) and routing ports ⚖️.
- More ports: Increases SRAM cell area and periphery area, but increases bandwidth and allows more diverse uses (e.g., FIFOs need 1r+1w) 🔄. Adding a second port to an SRAM cell can increase area by 33% 📈.

---

### Configurable BRAMs & Routing Interface ⚙️

- Extra configurability is added to BRAMs to adapt to diverse application needs 🔄.
- Configurable width and depth via **low-cost multiplexing circuitry** in peripherals 🔌.
  - Example: A 4x8-bit array can operate in 8x4, 16x2, 32x1 modes by adding muxes/decoding [53, Fig 12] 🔢.
  - Width configurability cost is small relative to SRAM array. Doesn't require additional routing ports.
- Interface to programmable routing fabric: Designed similarly to logic blocks 🏗️.
  - Connection block muxes (and local crossbars) form input ports 🔌.
  - Read outputs drive switch block muxes for output ports 🔀.
- Routing interfaces are **costly**, especially for smaller BRAMs (5%-35% of tile area) 💰. Motivates minimizing routing ports.

---

- Table I shows port requirements for different BRAM modes. True dual-port (2r/w) requires significantly more ports than simple dual-port (1r+1w) 📊.
- Common approach: True dual-port SRAM core, but only enough routing interfaces for simple-dual port at full width (W) and true dual-port at half width (W/2) ⚖️.
- Multi-pumping (operating BRAMs faster than logic) can implement logical multi-porting with single physical ports, but makes timing closure challenging ⏱️.

---

### 💡 LUT-RAMs 🧠

- FPGA vendors add circuitry to repurpose **LUTs in the logic fabric** as additional RAM blocks 🔄.
- LUTs are naturally read-only memories (truth tables written by bitstream).
- Adding **designer-controlled write circuitry** turns them into small, distributed **LUT-based RAMs (LUT-RAMs)** ✏️.
- Major concern: **Additional routing ports needed for write functionality**.
  - Example: Altera ALM (6-LUT fracturable into two 5-LUTs, 8 input ports). Can be 64x1 or 32x2 memory. Only 2-3 unused ports, not enough for simple dual-port write signals (8 total) ⚠️.
- Solution: Configure an **entire logic block** as LUT-RAM to amortize control circuitry and address bits across multiple ALMs/LUTs 🏗️.
  - Write address/enable signals are broadcast within the block 📢.
  - Limits: A single logic block cannot mix logic and LUT-RAM ❌.
- To reduce area cost, only **half of logic blocks** in recent architectures are LUT-RAM capable ⚖️.
- Avoids extra routing ports but still adds some area.

---

### Mapping Logical RAMs (Fig 13) 🗂️

- Designs require many different RAMs; must be implemented using fixed BRAM and LUT-RAM resources 🧩.
- Designers describe logical memories; **vendor CAD tools perform RAM mapping** 🗺️.
- RAM mapper chooses physical implementation (type, width, depth, ports) 🔍.
- Generates logic to combine multiple BRAMs or LUT-RAMs 🔗.
- Example (Fig 13): Mapping a 2048x32-bit 2r+1w logical RAM to 1024x8-bit 1r+1w physical BRAMs 🔢.
  - Four physical BRAMs in parallel for width ↔️.
  - Depth-wise stitching of two sets of BRAMs using soft logic 🧵.
  - Replicate structure or double-pump for extra read port 🔄.
- RAM mapping is a complex optimization problem 🤔.

---

### Trends & Efficiency 📈

- FPGA memory architecture has evolved significantly; ratio of memory to logic has grown 🔄.
- Trend of increasing **memory bits per logic element** (Fig 14) 📈.
- Modern BRAMs have larger capacities (20kb) than early ones (2kb) 🏗️.
- Some FPGAs have highly heterogeneous BRAM architectures (e.g., Stratix had 3 types: 512b, 4kb, 512kb) 🧩.
- LUT-RAM introduction reduced need for small BRAMs 📉.
- Recent Intel/Xilinx architectures converge on LUT-RAM + medium-sized BRAMs (20kb/18kb), sometimes with larger blocks (Xilinx UltraRAM 288kb). No general agreement on best architecture 🤷.

---

- **Efficiency Comparison (Table II)** for 2048x72-bit 1r+1w RAM on Stratix IV ⚖️.
  - Mapped to one 144kb BRAM: Best area (0.22 mm²), reasonable Freq (336 MHz) ✅.
  - Mapped to eighteen 9kb BRAMs: 1.9x larger area, but 1.5x faster (497 MHz) ⚡.
  - Mapped to LUT-RAM: 12.8x larger area, 40% frequency ⚠️.
  - Mapped to Registers: >300x larger area, 40% frequency ❌.
- Confirms importance of on-chip RAM. Diversity of RAM resources is needed for different design needs 🏝️.
- Future: Exploring emerging memory technologies (MTJs) for denser BRAMs (~2.95x capacity increase) 🔮.

---

count: false
class: nord-light, middle, center

# 🧮 DSP Blocks

---

### 🧮 DSP Blocks - Evolution & Multipliers 🔄

- Initially, only hard arithmetic was carry chains for adders ➕. Multipliers were in soft logic (LUTs + carry chains), incurring large area/delay penalty ⚠️.
- Signal processing/communications needed high multiplier density. Techniques like multiplier-less distributed arithmetic were used 🎛️.
- **Hardening multipliers** became necessary due to inefficiency in soft logic ✅.
- Xilinx Virtex-II (2000s): Introduced industry's first **18x18 bit hard multiplier blocks** 🚀. Arranged in columns next to BRAMs. Shared interconnect resources to reduce cost, limiting BRAM width.
- Multiple hard multipliers could be combined for bigger multipliers or FIR filters using soft logic 🔗.

---

### DSP Blocks for Communications/Signal Processing (Fig 15) 📡

- Altera Stratix (2002): Introduced **full-featured DSP blocks** targeting comms/signal processing 🎯.
- Philosophy: Minimize soft logic for DSP algorithms by hardening more functionality. Enhance flexibility 🛠️.
- Stratix DSP block was highly configurable: eight 9x9, four 18x18, or one 36x36 multiplier 🔢.
- Increasing configurability/utility by adding low-cost circuitry to existing structures (Fig 16 showing fracturing an 18x18 into two 9x9s) ✂️. Avoids adding costly routing interfaces.

---

- Stratix DSP also incorporated:
  - Adder/output block for summation/accumulation ➕.
  - Hardened input registers configurable as shift registers with dedicated cascade interconnect for FIR filters 🔄.
- Xilinx Virtex-4: Adopted full-featured approach with **DSP48 tiles** (two fixed 18x18 multipliers, input cascades, adder/subtractor/accumulator) 🏗️.
- Virtex-4 introduced cascading adders/accumulators with dedicated interconnect for high-speed **systolic FIR filters** (Fig 17) ⚡.

---

### Efficiency Gains (Table III) 📊

- Hard DSP blocks offer significant efficiency gains over soft logic implementations 📈.
- Example: 51-tap symmetric FIR filter on Stratix IV 🔍.
  - With DSPs: Area 0.49 mm², Freq 510 MHz ✅.
  - Without DSPs (fixed coeff): 3.0x larger area, 0.5x Freq ⚠️.
  - Without DSPs (input coeff): 6.2x larger area, 0.4x Freq ❌.
- Example: 51-tap asymmetric FIR filter 🔍.
  - With DSPs: Area 0.63 mm², Freq 510 MHz ✅.
  - Without DSPs (fixed coeff): 3.9x larger area, 0.5x Freq ⚠️.
  - Without DSPs (input coeff): 8.5x larger area, 0.4x Freq ❌.
- Gains are large but less than the 35x FPGA vs ASIC gap. Due to remaining soft logic, and the programmable routing interfaces/general interconnect in the DSP tile ⚖️.
- Using advanced DSP block features (accumulation, systolic registers) often requires manual instantiation, making designs less portable 🏗️.

---

### 📈 Recent DSP Block Evolution 🔄

- Subsequent generations saw minor changes, focus on fine-tuning for key domains without costly routing additions 🛠️.
- Stratix V simplified DSP block: Two 18x18 or one 27x27 multiplication. Added input pre-adders, embedded coefficient banks for FIR filters (allows implementing whole symmetric FIR filter in DSP) 🎛️.
- Xilinx shifted multiplier widths (18x18 to 25x18 in Virtex-5, 27x18 in Ultrascale). Added input pre-adders, enhanced ALU ➕.
- Evolution was initially driven by communications needs (wireless base stations) 📡.

---

### 🧠 DSP Blocks for Deep Learning & HPC 🧠

- Recent adoption in datacenters and the rise of DL drove DSP block evolution in two directions 🔄.
- **Direction 1: HPC**: Adding native support for **single-precision floating-point (fp32)** multiplication 🏗️.
  - Before this, fp32 used soft logic or IP cores on fixed-point DSPs + soft logic, a barrier vs CPUs/GPUs ⚠️.
  - Intel Arria 10: First native fp32, limited block area increase (10%) by reusing interfaces, maximizing fixed-point hardware reuse ✅.
  - Xilinx Versal: Will also support floating-point in DSP58 tiles 🔮.

---

- **Direction 2: DL Inference**: Increasing density of **low-precision integer multiplication** (8-bit and below) 🔢.
  - Low-precision arithmetic effective for DL with little accuracy loss 🎯.
  - FPGAs attractive for custom precision datapaths, energy efficiency, lower development cost 💰.
  - Academic work enhanced fracturability for int9/int4 MACs. Increased performance/reduced resource use for DL accelerators 🚀.
  - Intel Agilex: Added int9, fp16, bfloat16 support 🔢.
  - Xilinx Versal: Natively supports int8 multiplications 🔢.

---

### 🎯 Application-Specific DSP Block Architectures 🎯

- Divergence in requirements (high-precision FP for HPC, medium-precision fixed for comms, low-precision fixed for DL) makes universal DSP blocks harder 🤔.
- Leads to **AI-optimized FPGAs** 🧠.
- Intel Stratix 10 NX: Replaces conventional DSPs with **AI tensor blocks** 🚀. Drops legacy support for comms, adopts new modes for DL. Significantly increases int8/int4 MAC density (30/60 per block) 🔢.
- Feeding many multipliers without adding ports is key. NX tensor block introduces a **double-buffered data reuse register network** 🔄.
- Achronix Speedster7t: Includes **Machine Learning Processing (MLP) block** 🏗️. Supports wide range of precisions (int16-int3, fp24, fp16, bfloat16) 🔢.
- MLP block features tightly coupled BRAM and circular register file for data reuse. Reduces required routing ports 🔌.

---

### 🌐 System-Level Interconnect: Network-on-Chip (NoC) 🛣️

- FPGAs increased capacity and external IO bandwidth (DDR, PCIe, Ethernet) 📈.
- **Challenge**: Distributing data traffic between high-speed interfaces and the large soft fabric 🚦.
- Traditionally: **Soft buses** implemented in FPGA logic/routing (multiplexing, arbitration, pipelining, wiring) 🏗️.
- High-speed interfaces run faster than fabric, require **wide soft buses** to match bandwidth. (e.g., 128-bit HBM at 1 GHz needs 1024-bit bus at 250 MHz) ⚡.
- Wide, physically long soft buses use significant logic/routing resources 📏.
- Timing closure is challenging; requires **deep pipelining**, further increasing resource use ⏱️.
- Problem is worsening with advanced nodes due to poor wire parasitics scaling 📉.

---

### 🛣️ Hard NoC Design & Implementations (Fig 18) 🏗️

- Proposed solution: Embedding a **hard, packet-switched network-on-chip (NoC)** in the fabric 🚀.
- A hard NoC with hardened routers and links is **23x more area efficient, 6x faster, and consumes 11% less power** than a soft NoC 📊.
- Challenge: Hardening requires committing choices (routers, link width, topology) while maintaining FPGA flexibility ⚖️.
- Academic work suggests mesh topology, moderate routers (e.g., 16), wide links (128-bit). Keep area <2%, ease layout, carry DDR bandwidth 🏗️.
- **Fabric port**: Interfaces hard NoC routers to programmable fabric, handles width adaptation, clock domain crossing, voltage translation ⚙️. Decouples NoC from fabric speed.
- Hard NoCs well-suited for datacenter FPGAs (shell+role architecture). Significantly improve resource utilization, frequency, routing congestion ✅.
- Optimized soft NoCs exist but still trail hard NoCs in most respects (bandwidth, latency, area, congestion) ⚠️.

---

### 🚄 Next-Gen Hard NoCs 🚀💻

- Recent **Xilinx (Versal) and Achronix (Speedster7t) FPGAs integrate hard NoCs** ✅🔌 🆕
- **Xilinx Versal (Fig 18a)**: Uses hard NoC for system-level communication between various endpoints (transceivers, processor, AI subsys, fabric). Only way for external memory to communicate with rest of device 🧩
  - 128-bit links at 1 GHz (matches DDR) ⚡ 🔢
  - Topology related to mesh, horizontal links pushed to top/bottom for layout 📐
  - Multiple rows (horizontal) and columns (vertical) ➕
  - Programmable routing tables configured at boot. Provides standard AXI interfaces ⚙️

---

- **Achronix Speedster7t (Fig 18b)**: Optimized for external interface to fabric transfers 🔄
  - Peripheral ring around fabric with rows/columns over fabric 🔵
  - Peripheral ring can operate independently without configuring fabric 🌀
  - No direct row-column connectivity; packets pass through peripheral ring 🚫

---

### 🏗️ Interposers & Multi-Die Integration 🧩🔗

- FPGAs adopted **interposer technology** early for dense interconnection of multiple silicon dice 🎛️
- **Passive interposer**: Silicon die (often trailing process) with metal layers and microbumps connecting dice on top [87, Fig 19a] 🔩
- Motivations: 💡
  1.  **Higher logic capacity**: Large monolithic dice have poor yield. Combining smaller dice on interposer yields better 📈
  2.  **Heterogeneous Integration**: Integrate different specialized chiplets (different processes) into one system. FPGA fabric bridges functionality/protocols 🌐

---

- Xilinx Virtex-7/Ultrascale: Use passive silicon interposers to integrate 3-4 FPGA dice. Provide >2x logic elements of largest monolithic devices 🔧
- Challenge: Interposer microbumps are larger/slower than conventional routing. Do they limit routability? ⚠️
- Solutions: CAD tools place logic to minimize interposer crossings. Architecture changes increase switch flexibility to crossing tracks 🛠️
- Versal: Vertical NoC bandwidth crosses between dice, using limited interposer wires efficiently due to high frequency/packet switching 🔄

---

### 🤝 Interposers - EMIB & Chiplets 🔩🚀

- Intel FPGAs use smaller interposers called **embedded multi-die interconnect bridges (EMIB)** carved into package substrate [89, Fig 19b] 🧊
- Intel Stratix 10: Uses EMIB to integrate large FPGA fabric die with smaller IO transceiver or HBM chiplets. Decouples design/process choices 🔌
- Recent studies used EMIB to tightly couple FPGA fabric with specialized **ASIC accelerator chiplets for DL** 🧠
- Offloads computation kernels (matrix multiplication) to more efficient ASICs ⚡
- Leverages FPGA fabric for external interfacing and implementing rapidly changing DL model components 🤖

---

### ⚙️ Other Important Components 🛠️🔧

- **Configuration Circuitry**: Loads the bitstream into millions of SRAM cells controlling logic, routing, hard blocks. Controller loads serially (flash, PCIe), writes in parallel 🔄
  - Allows **partial re-configuration** of parts of the device while others run 🔄
  - **Security**: Bitstream encryption/decryption key programmed by manufacturer to protect IP 🔒
- **Clock Networks**: Handle dozens of clocks operating at different speeds. Generated by PLLs, DLLs, CDRs ⏰
  - Special interconnect networks for clocks 🌐
  - Use topologies for **low-skew networks** (H-trees) 🌳
  - Implemented with wider metal and shielding to reduce crosstalk/jitter 🛡️

---

### ⏭️ Conclusion - Progression & Future 🚀🔮

- FPGAs have progressed from simple programmable arrays to complex heterogeneous multi-die systems with embedded BRAMs, DSPs, IOs, NoCs, and more 📈
- Recent adoption in HPC/Datacenters and demand from applications like DL are driving new architecture design ☁️
- New applications and multi-user datacenter paradigms create opportunities for innovation 💡
- Process technology scaling changes are fundamental: 🔬
  - Poor wire delay scaling requires rethinking routing ⚡
  - Interposers & 3D integration enable new heterogeneous systems 🧩
  - Controlling power is key; likely leads to more power-gating and heterogeneous hard blocks 🔋
- The future of FPGA architecture will be interesting and different! 🌟

---

count: false
class: nord-dark, middle, center

.pull-left[

### Q&A 🎤

] .pull-right[
![Discussion](figs/questions-and-answers.svg)
]
