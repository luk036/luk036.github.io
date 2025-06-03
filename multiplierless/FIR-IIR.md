layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# ✨ **Digital Filters: Design and Implementation** ✨

@luk036 👨‍💻

2025-05-31 📅

---

## 📄 **Introduction** 🎯

*   Welcome! 👋 🎉
*   **Topic:** Design and Implementation of Digital Filters. ⚙️
*   **Why it matters:** Digital filters are fundamental in signal processing and communication systems. 📡
*   They perform operations based on the impulse response, essentially a convolution process. 🔄
*   **Key Challenge:** Implementing these filters efficiently in hardware (VLSI, FPGAs) while meeting constraints like area, speed (delay), and power consumption. ⚡
*   **Focus:** Multiplierless techniques, optimization algorithms, and hardware implementation considerations. 🔍

---

## 🛠️ **The Need for Efficiency - Multiplierless Design** 💡

*   **Problem:** Multiplication is computationally expensive in hardware compared to addition/subtraction and shifts. ⏳
*   **Solution:** **Multiplierless Filter Design**. Replace multiplications by constants (filter coefficients) with sequences of shifts and adds/subtracts. 🔄
*   This forms the basis of **Shift-Adds Architectures**. 🏗️
*   **Key Concepts:**
    *   **Multiple Constant Multiplications (MCM):** Implementing multiplications by multiple constants (coefficients) efficiently. 🔢
    *   **Common Subexpression Elimination (CSE):** Finding and sharing common intermediate computations (bit patterns) among coefficient multiplications to reduce adders. 🔎
    *   **Graph-Based Approaches:** More powerful than CSE for finding sharing opportunities. 📊

---

## ⚙️ **Optimization in Multiplierless Design** 🎛️

*   Finding the *optimal* set of shift-add operations for multiplierless design is complex. 🧩
*   **Algorithms:**
    *   Exact methods (like those in) aim for minimal operations but might not optimize for hardware area directly. 🎯
    *   Algorithms targeting minimal gate-level area consider the cost of adders/subtractors. 🏗️
    *   For FPGAs, methods can target minimum 4-input Look-Up Tables (LUTs). 🔍
*   **Integer Linear Programming (ILP):** A powerful approach that can model the optimization problem to minimize adder count. 📉
    *   Can incorporate constraints like maximum adder depth. 📏
    *   ILP solvers (like Gurobi, CPLEX) can address relevant problem sizes. 🖥️
    *   ILP allows comprehensive exploration of design parameters (coefficient word length, filter type, order) to find tradeoffs. 🔄

---

## 📏 **FIR Filters: Forms and Design**

*   **FIR Filters:** A major class of digital filters, important in many applications. 🏆
*   **Forms:**
    *   **Direct Form:** Straightforward implementation of the convolution sum. ➡️
    *   **Transposed Form:** Re-arrangement of the direct form, often preferred for hardware implementation. 🔄
    *   **Hybrid Forms:** Combinations of direct and transposed structures. 🧩
*   **Coefficient Properties:** Can be Symmetric or Asymmetric. Symmetry can be exploited for efficiency. 🔄

---

*   **Design Methods:**
    *   Traditional methods like Weighted Least Squares (WLS). 📊
    *   **Genetic Algorithms (GA):** Used for designing FIR filters by optimizing coefficients based on error metrics. GAs explore the design space efficiently. 🧬
    *   **Hybrid GA/Quasi-Newton (QN):** Combines the exploration of GA with the local search of QN for potentially better results. 🚀
    *   **Tunable Fractional-Delay (FD) FIR Filters:** Often designed using the **Farrow Structure** (FDFS). GAs can be used to optimize coefficients for minimal phase delay error, ensuring quantization-error-free implementation when coefficients are encoded as binary strings. ⏱️

---

## 🎢 **IIR Filters: Forms and Design**

*   **IIR Filters:** Another key class, can often meet specifications with lower order than FIR. 📉
*   **Elliptic IIR Filters:** Chosen for comparisons due to requiring lower order and usually fewer multipliers to meet specs. 📊
*   **Forms:**
    *   **Cascade Realization:** Connecting first and second-order sections in series. ⛓️
    *   **Parallel Connection of Two Allpass Networks:** Structures based on allpass sections, potentially having a small number of adders. ➕
*   **Multiplierless IIR Design:**
    *   The multiplier block concept might be inapplicable to structures based on allpass sections. 🚫
    *   EMQF (Elliptic Minimal Q-Factors) analog prototype can lead to parallel structures with multiplication constants implemented with few shifters and adders. ⚙️

---

*   **Design Methods:**
    *   GAs can be used for IIR filter design. 🧬
    *   Hybrid GA/QN algorithms are developed for IIR filters, minimizing objective functions based on amplitude-response error. 📉
    *   A two-step approach: design a recursive filter for amplitude, then design a **delay equalizer** (an allpass filter) in cascade for group delay equalization. GAs can design these equalizers to satisfy prescribed specifications. ⏳
    *   **Tunable Fractional-Delay (FD) IIR Filters:** Can be based on the Allpass IIR Farrow Structure (AIFS). GAs optimize these by minimizing phase delay error, incorporating stability constraints. 🔧

---

## 🖥️ **Hardware Implementation** 💻

*   Digital filters are implemented in hardware using VLSI (Custom) or reconfigurable devices (FPGAs, PLDs). 🔌
*   **Synthesis Tools:** Software like Synopsys Design Compiler (custom) and Xilinx ISE Design Suite (reconfigurable) are used to translate designs into hardware. 🛠️
*   **Optimization Criteria:** Designs are optimized for:
    *   **Area:** Combinational Area (CA), Non-Combinational Area (NCA), Total Area (TA). On FPGAs: LUTs, Flip-Flops (FFs), Slices. 📏
    *   **Delay:** Critical path delay (D) in ns. ⏱️
    *   **Power:** Total dynamic power dissipation (P) in mW. ⚡
    *   **Number of Operations:** Total adders/subtractors (TO), Multiplier Block Operations (MBO). ➕
    *   **Adder Depth (AD):** Minimum number of adder-steps in the multiplier block. 📊

---

*   **Filter Form Impact (on FPGAs):**
    *   Transposed form filters often require significantly fewer slices, less delay, and lower power than direct form. This is due to better utilization of CLBs which contain both LUTs and FFs. 🔄
    *   Hybrid forms typically yield designs with characteristics between the transposed and direct forms. 🧩
    *   Reducing adder steps can decrease delay and power but may increase the number of slices. ⚖️
*   **Finite Wordlength Effects:** Coefficient wordlength, filter input bitwidth, and filter output bitwidth impact results. 📏
*   **Arithmetic Implementations:**
    *   **Booth Encoding:** Reduces the number of partial products in multiplication. ✖️
    *   **Redundant Ternary Signed-Digit (RTSD):** Number system that enables carry-propagation-free addition, potentially reducing addition time and power dissipation. ➕

---

## ⚖️ **Design Method Comparisons**

**Multiplierless FIR:**
*   Transposed form generally performs better than Direct form on Virtex 4 FPGAs in terms of slices, delay, and power. 🏆
*   Using minimum adder-step configurations (SA-D) decreases delay and power but often increases slices compared to area-optimized configurations (SA-A). ⚖️
*   ILP approaches can achieve significant improvements in adder count compared to state-of-the-art methods, allowing exploration of various tradeoffs (error, order, word length, adder depth, type). 📉
*   A technique aggressively reducing coefficient wordlength and non-zero bits can significantly reduce MBAs and multiplier block FAs. ✂️
*   RTSD adder + Booth multiplier implementation of FIR shows better power, area, and delay compared to implementations using Ripple Carry Adders (RCA) or Carry Lookahead Adders (CLA). 🚀

---

## ⚖️ **Design Method Comparisons**

**Multiplierless IIR:**
*   For lower filter orders, cascade realization might have lower adder cost but increased passband ripples. 📉
*   EMQF (parallel connection) reduces passband ripples. 📊
*   Cascade yields better stopband amplitude characteristics, but parallel connection can match this by increasing coefficient wordlength (though increasing adder cost). ⚖️
*   Parallel connection can result in significantly better normalized product round-off noise variance and adder cost compared to cascade for halfband filters. 🎯

---

## ⚖️ **Design Method Comparisons**

**Optimization Algorithms:**
*   GA for Tunable FD filters (FIR/IIR): Can lead to reduced errors compared to Least-Squares (LS) methods, but with significantly higher computation time. ⏳
*   GA for IIR Delay Equalizers: Can achieve flatter group delay characteristics compared to gradient-based methods. 📏
*   ENSGA for Asymmetric FIR (Multiobjective): Improves minimum stopband attenuation, reduces peak passband ripple, and achieves flatter group delay passband compared to initial WLS designs. 🎯
*   GAs generally require significant computation time compared to gradient-based algorithms, making them more suitable for non-real-time, off-line applications. 🖥️

---

## 🌱 **Summary** 🚀

*   **Recap:** Digital filter design involves balancing performance (amplitude/delay response) with implementation efficiency (area, delay, power). ⚖️
*   Multiplierless techniques are key to hardware efficiency, utilizing shift-adds architectures. 🔑
*   Sophisticated optimization algorithms (GA, ILP) are essential for finding optimal or near-optimal designs under various constraints. 🧠
*   Filter form and arithmetic implementation significantly impact hardware performance. ⚙️

---

## **Future Research Directions:**

*   Use of structured GAs for filters. 🧬
*   Design of filters using cascaded low-order subfilters, especially for PLDs/FPGAs. ⛓️
*   Minimum-order asymmetric FIR filter design. 📉
*   Design of Frequency-Response Masking filters. 🎭
*   Applying RTSD adders to other types of digital filters. ➕
*   Various software tools and techniques are used in the field for design and verification. 🛠️

---

count: false
class: nord-dark, middle, center

# Q & A 🎤
