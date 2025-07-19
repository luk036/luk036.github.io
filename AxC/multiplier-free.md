layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Multiplierless Designs: Efficiency in Hardware and Beyond 🚀💻

@luk036 👨‍💻

2025-05-21 📅

---

### What are Multiplierless Designs? 🤔💭🔍

*   Digital Signal Processing (DSP) kernels like transforms 🔄 and filters 🧩 often involve multiplications by constants.
*   Instead of using dedicated hardware multipliers (which can be costly in terms of area 📏 and power ⚡), these constant multiplications can be implemented using only **additions ➕, subtractions ➖, and shifts ⏩**.
*   This implementation technique is called "**multiplierless**".
*   Example: `y = 5x` can be computed as `y = (x << 2) + x` (shift `x` left by 2 bits ⏩, then add `x` ➕). This uses one shift ⏩ and one addition ➕ instead of a full multiplier.
*   These designs are primarily of interest for **hardware implementations** (like FPGAs 🖥️ and VLSI 🔌) but can also benefit software 💾 for certain processors.

---

### Why Go Multiplierless? ✨🏆💡

*   **Hardware Efficiency** 🏗️⚡: Multiplierless implementations are used to avoid costly multipliers in hardware.
*   **Reduced Area** 📉🏠: Implemented using networks of additions ➕ and shifts ⏩, which can be smaller than dedicated multipliers.
*   **Lower Power Consumption** 🔋💡: Generally consume less power compared to multiplier-based designs.
*   **Potential for Higher Speed** ⚡🏎️: Can sometimes lead to higher operating frequencies depending on the specific design and optimization.

*   This approach is especially relevant for mobile 📱🏃‍♂️ and embedded applications with stringent area 📏 and power ⚡ requirements.

---

### How are Multiplierless Designs Achieved? 🛠️🔧⚙️

*   The core idea is replacing multiplication ✖️ with a combination of **shifts ⏩ and additions ➕/subtractions ➖**.
*   A collection of operations that multiply a single input by one or more constants is called a **multiplier block**.
*   For multiple constants, the problem becomes **Multiple Constant Multiplication (MCM)** 🔢.

---

### Multiple Constant Multiplication (MCM) & CSE 🌱🔍🧩

*   In MCM, the goal is to compute multiple constant multiplications simultaneously, sharing common intermediate results to minimize cost (number of additions ➕/subtractions ➖).
*   **Common Subexpression Elimination (CSE)** is a key technique used in multiplierless design.
*   CSE searches for 🔍 and eliminates redundant bit patterns common across several coefficients, sharing the computation of these patterns.
*   Different CSE approaches exist, including **horizontal ↔️, vertical ↕️, oblique ⬇️, and combinations** 🔀.
*   While CSE helps, it may not find *all* sharing opportunities due to its dependency on the number representation.
*   **Graph-based approaches** 📊🌐 are also commonly used in state-of-the-art MCM methods to overcome limitations of CSE.

---

### Multiplierless in Applications 🎯📱🔌

*   Multiplierless techniques are widely applied in **linear DSP kernels** 📈.
*   **Filters** 🧩: Finite Impulse Response (FIR) and Infinite Impulse Response (IIR) filters are common applications.
*   **Transforms** 🔄: Discrete Cosine Transform (DCT), Discrete Fourier Transform (DFT), and Discrete Wavelet Transform (DWT) utilize multiplierless implementations.
*   **Filter Banks** 🏦 and **Polyphase Filters** also benefit.
*   The choice of number representation (e.g., Canonical Signed Digit - CSD) can also facilitate sharing opportunities.

---

### Multiplierless FIR Filter Design 📉🎛️🔍

*   A key area of multiplierless design.
*   Design flow often starts with functional frequency domain specifications, number of coefficients, and word lengths.
*   Optimization procedures yield bounded integer coefficients and associated adder circuits for constant multiplications (MCM).
*   **Parameters and Interactions** 🔄⚙️: Filter coefficients, word lengths, number of filter coefficients (N), size of wordlength (b), adder cost (number of additions ➕/subtractions ➖), adder depth, filter order, gain.
*   Optimization aims to minimize adder cost subject to frequency response specifications.
*   The relationship between word length and cost is nonlinear, suggesting comprehensive design space exploration is beneficial.
*   Coefficient choice can be a criterion during filter design itself, not just implementation.

---

### Optimizing FIR Filters ⚙️🔍📊

*   Methods involve selecting integer coefficients and associated adder circuits.
*   Approaches include CSE and graph-based MCM algorithms.
*   More advanced methods use **Integer Linear Programming (ILP)** optimization based on a pre-specified or dynamically expanded set of sharable terms.
*   Fast **polynomial-time heuristics** are also used for low complexity designs.
*   Comprehensive exploration of design parameters like effective word length (B), filter type, and filter order (N) can lead to lower implementation costs. Allowing variable gain can also significantly influence results.
*   Some state-of-the-art methods can improve upon previous results by reducing the number of adders ➕ or adder depth. Higher sparsity in the design can sometimes lead to a 2-stage adder depth design with lower cost.

---

### Multiplierless Transforms 🖼️🎶🔄

*   Linear DSP transforms like DCT, DFT, and DWT consist of additions ➕ and multiplications ✖️ by constants.
*   Multiplierless implementations use adder/shift networks for these constant multiplications.
*   Cost is determined by the number of additions ➕, influenced by constant value and precision.
*   For DWT (e.g., 5/3 wavelet base), multiplierless schemes with integer data can result in significantly lower internal signal length compared to multiplier-based schemes. Hardware resources like slice registers and LUTs are used in FPGA implementations of multiplierless DWT.

---

### Automated Design & Optimization for Transforms 🤖⚡🔧

*   Designing multiplierless transforms involves choosing a numerically robust algorithm and configuring constant precisions to minimize additions ➕ while meeting error constraints.
*   These steps can be challenging due to the large number of configurations and the unpredictable impact of precision reduction on output error.
*   Automated methods have been developed for:
    *   **Automatic robust algorithm selection** 🤖📊.
    *   **Automatic configuration of constant precisions** ⚙️🔢.
*   These tools can explore a large number of design points and investigate the tradeoff between resource constraints and implementation quality. This offers a flexible alternative to static IP design reuse.

---

### Conclusion 🎉🏁✨

*   Multiplierless designs are essential for implementing linear DSP kernels efficiently, especially in hardware, by replacing multiplications ✖️ with additions ➕, subtractions ➖, and shifts ⏩.
*   MCM and CSE are core techniques for optimizing these implementations by sharing common subexpressions.
*   Future work includes developing integrated design methodologies and tools to better link application requirements to low-level circuit design choices.

Thank you! 🙏✨🚀

---

count: false
class: nord-dark, middle, center

# Q & A 🎤
