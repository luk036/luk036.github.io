layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Approximate Arithmetic Circuits: A Survey 🔍, Characterization 🧮, and Recent Applications 🚀

*Presented based on the survey paper published in Proceedings of the IEEE publication information 📚 2020.*

@luk036 👨‍💻

2025-05-21 📅

---

### 🚀 Introduction: The Need for Approximate Computing ⚡

*   Approximate computing (AxC) has emerged as a **new paradigm** 🌱 for high-performance 🏎️ and energy-efficient 🔋 circuit and system design.
*   **Motivation 💡:** Challenges from massive data 📊 and complex computations in modern applications like AI 🤖.
*   Conventional technologies face increasing challenges to improve circuit performance ⚡ and power efficiency ♻️.
*   At the nanometer scale 📏, supply voltage reduction is limited, leading to significant **power density increases** 📈.
*   This results in "dark silicon" ⚫ where parts of the chip must be powered off. Studies show dark silicon area can exceed 50% for 8-nm technology.

---

### 🤔 Why AxC ? 🧠

*   Many applications like multimedia 🎬, recognition 👀, classification 🏷️, and machine learning 🧠 can **tolerate some errors** ❌.
*   Humans have perceptual limitations 👂👁️, meaning errors might not be noticeable in output quality for image 🖼️, audio 🎵, or video 📹 processing.
*   Input data is often noisy 📡 or quantized ⚖️, already limiting precision.
*   Probability-based computing 🎲 (like stochastic computing) tolerates trivial errors.
*   Iterative refinement processes 🔄 (like in machine learning) can attenuate or compensate for insignificant errors.
*   AxC offers a potentially promising technique 💎 for various error-tolerant applications.

---

### 📜 Development History

*   Early approaches since the 1960s 🕰️:
    *   Newton–Raphson algorithm for approximate quotient calculation ➗ (speeding up division).
    *   Functional iteration-based algorithms 🔁 (e.g., Goldschmidt).
    *   Mitchell's logarithm-based algorithm for multiplication and division.
*   Gradual adoption of straightforward approximation/rounding techniques 🔄, e.g., **truncation-based fixed-width multipliers** ✂️.
*   Early 2000s 🎆: Concept of approximation applied to adders ➕ and Booth multipliers to increase clock frequency ⏱️.
    *   Approximate adder idea 💡: Effective carry chain ⛓️ shorter than full chain; critical path reduced by using previous k bits (k < n) for carry prediction 🔮.
*   Since ~2008 📅: **Significant attention** 👀 to approximate adders ➕ and multipliers ✖️, leading to various designs (ACA, ETM, UDM, LOA, ESA, etc.).
*   Development of logic synthesis methods 🛠️ and automated processes 🤖 for AxC designs.
*   Recent approximate designs include dividers ➗, MAC units 🧮, squaring circuits ², square root circuits √, and CORDIC 🔄.

---

### 🛠️ Design Methodologies 🧰

*   An approximate arithmetic circuit can be obtained via:
    1.  **Voltage Overscaling (VOS) ⚡**:
        *   Lower supply voltage 🔋 to reduce power.
        *   Increases critical path delay ⏳, potentially causing timing errors.
        *   Error characteristics are **nondeterministic** 🎲 and affected by variations. Large errors possible if MSBs are affected.
    2.  **Redesigning Logic Circuits 🖥️**:
        *   Modifying, removing, or adding elements to an accurate circuit.
        *   Simplifying truth tables 📊 or Karnaugh maps 🗺️.
        *   Results in circuits with **deterministic error characteristics** ✅.
    3.  **Simplification Algorithms ➗➖**:
        *   Converting complex operations (multiplication ✖️, division ➗, square root √) into simpler ones (addition ➕, subtraction ➖) using algorithms like Mitchell's.
        *   Can significantly improve performance ⚡ and energy efficiency 🔋 due to simpler basic structure.
        *   Accuracy tends to be **relatively low** 📉.
*   **Hybrid Approximate Circuits 🔀:** Combine several approx. techniques.

---

### 📏 Evaluation Metrics 📐

*   Both **error characteristics ❌** and **circuit measurements 🛠️** must be considered.

1. 📊 Error Characteristics ❌
    *   Various metrics and analytical approaches are used [18, 49, 66–73]. Monte Carlo simulation 🎲 is common.
    *   **Error Rate (ER) 📉:** Probability of producing an erroneous result.
    *   **Error Distance (ED) 📏:** Arithmetic difference between approximate (M') and accurate (M) results: |M' - M|.
    *   **Relative Error Distance (RED) ⚖️:** Relative difference w.r.t. accurate result: |ED / M|.
        *   For same ED, smaller M results in larger RED.
    *   **Mean ED (MED) 📊** and **Mean RED (MRED) 📈:** Average values used to assess overall accuracy.

---

2. ⏱️ Circuit Measurements ⚙️

    *   Basic metrics: **critical path delay ⏳, power dissipation 🔌, and area 📏**.
    *   Compound metrics: Power-Delay Product (PDP) ⚡⏱️, Area-Delay Product (ADP) 📏⏳, Energy-Delay Product (EDP) 🔋⏱️.
    *   Measurements depend on process technologies (e.g., 28-nm CMOS) 🏭, component libraries 📚, supply voltage ⚡,     temperature 🌡️, and optimization options. Fair comparison requires same configuration.
    *   Design goals: **maximizing performance** ⚡ (minimizing delay) or **minimizing power** 🔋 (minimizing area).
    *   Synthesis tools 🛠️ (e.g., Synopsys Design Compiler) and power estimation tools (e.g., PrimeTime-PX) are used.

3. ⚖️ Comprehensive Measurements 📊

    *   Combine error ❌ and circuit characteristics ⚙️.
    *   Figures of Merit (FOMs) exist but are heuristic-based.
    *   This article **directly compares delay ⏳, power 🔌, and PDP ⚡⏱️** against ER 📉, NMED, and MRED 📈.

---

### ➕ Approximate Adders ➕

*   Conventional adders accelerate operation at the cost of area 📏 and power 🔋. Approximate adders **trade accuracy 🎯 for hardware efficiency** ⚙️.
*   Classified into four categories based on approximation schemes to reduce critical path/hardware complexity:
    1.  **Speculative Adders 🔮:** Leverage that effective carry chain ⛓️ is short. Predict carry using previous k bits (k < n) to reduce delay ⏳. Examples: ACA.
    2.  **Segmented Adders 🧩:** Divide adder into segments, process segments in parallel. Inputs may overlap. Examples: ESA, ETAII, ACAA.
    3.  **Carry-Select Adders 🔀:** Use multiplexers to select sum/carry based on predicted carry. Examples: SCSA, CCA, CSA, GCSA, BCSA, CSPA.
    4.  **Approximate Full Adders (AFAs) ➕:** Approximate the FA cell itself. Use AFAs for LSBs and accurate adders for MSBs. Examples: LOA (uses OR gate as AFA). Other AFA designs exist [29, 20, 104–106].
*   Truncated Adder (TruA) ✂️: Simple baseline, works with lower precision.

---

### 📈 Evaluation of Approximate Adders (16-bit) 📊

*   Evaluated using MATLAB simulations 💻 (ten million random inputs) for error characteristics (MRED).
*   Synthesized in HDLs (Synopsys DC, 28-nm CMOS) for circuit measurements (delay ⏳, power 🔌). Clock: 1 ns.
*   **Performance vs. Accuracy (MRED/ER) ⚡🎯:** [31, 32, Fig. 6]
    *   Most designs have ERs between 0.5% and 35%.
    *   CSA can be very accurate 🎯 (low ERs).
    *   CCBA, LOA, and TruA can have small MREDs but very high ERs.
    *   LOA, CCBA, and GeAr show balanced tradeoff in performance ⚡ and MRED.
    *   ESA and CSPA are fastest 🏎️ at large errors.

---

*   **Power vs. Accuracy (MRED/ER) 🔋🎯:** [31, 32, Fig. 7]
    *   CCBA, LOA, and TruA offer best power-MRED tradeoffs.
    *   GeAr, BCSA, and CCBA are on the Pareto set for power and ER.
*   **Energy vs. Accuracy (MRED/PDP) 🔋⚡:** [33, Fig. 8]
    *   Similar trends for delay- and area-optimized syntheses.
    *   CCBA, LOA, and TruA achieve best PDP-MRED tradeoffs, despite highest ERs. Suitable where large error magnitude is worse than high ER.
*   **Summary:** Truncation ✂️ is hardware-efficient but high ER. Carry select (CSA) is effective for high accuracy 🎯. Speculative adders (ACA) can have high power 🔋 and large errors. ESA is hardware-efficient for high error tolerance.

---

### ✖️ Approximate Unsigned Multipliers (AxUMs)

*   **Preliminaries 📚:**
    *   Typically three stages: Partial Product (PP) generation, PP accumulation, final carry propagate addition.
    *   PP accumulation structures: Carry-Save Adder array (regular, O(n) delay ⏳), Wallace tree 🌳 (faster, O(log(n)) delay, more complex wiring), Dadda tree (similar to Wallace, minimizes adders).
*   Five methodologies for approximation:
    1.  Approximation in generating PPs. Example: UDM.
    2.  Approximation (including truncation ✂️) in the PP tree. Examples: BAM, TruM, PPAM, ETM, SSM, DRUM, AWTM.
    3.  Using approximate adders ➕, counters 🧮, or compressors in PP reduction. Examples: ICM (uses approximate counter), designs with approximate compressors [49, 50, 123–126].
    4.  Using Logarithmic Approximation (LMs) 📊. Based on Mitchell's algorithm: log(A*B) = log(A) + log(B), then antilog. Examples: ALM-SOA, ILM-EA/ILM-AA.
    5.  Using Automated Processes 🤖 (e.g., genetic programming). Automatically generated designs. Examples: CGPM1-CGPM6.

---

### 📈 Evaluation of AxUMs (16x16) 📊

*   Evaluated similarly to adders, clock period 4 ns for power 🔌.
*   Most designs have high ERs (~100%), except ICM (~5.45%). Comparison focuses on MRED and NMED.
*   **Performance vs. Accuracy (MRED/NMED) ⚡🎯:** [55, 57, Fig. 11]
    *   CGPM1 is most accurate 🎯 with reasonable performance.
    *   LMs (ALM-SOA, ILM-AA) are fast 🏎️ but poor accuracy.
    *   HOCM, TAM1, ILM-AA, and ALM-SOA show best performance-accuracy tradeoffs.
    *   PPAM can have shortest delay ⏳ but largest error.
*   **Power vs. Accuracy (MRED/NMED) 🔋🎯:** [58, 59, Fig. 12]
    *   LMs are power-efficient 🔋 but low accuracy.
    *   CGPM1 is accurate but relatively power-hungry.
    *   BAM consumes low power at medium accuracy.
    *   HOCM (1StepTrunc) shows best power-accuracy tradeoff.

---

*   **Energy vs. Accuracy (MRED/PDP) 🔋⚡:** [59, Fig. 13]
    *   Trends slightly differ between delay/area optimized synthesis.
    *   HOCM (1StepFull), TAM1, CGPM1, and CGPM3 show good tradeoffs.
    *   ALM-SOA and PPAM are most hardware-efficient (lowest PDP) at very low accuracy.
*   **Summary:** Truncation ✂️ is effective for delay/energy reduction. LMs are hardware-efficient but low accuracy. Automated designs (CGPMs) can be highly accurate with moderate hardware. Fixed-width Booth multipliers (signed) often better due to error compensation.

---

### ✖️ Approximate Booth Multipliers (Signed)

*   Commonly use the modified (radix-4) Booth algorithm [61, 118, 136–140].
*   **Fixed-width multipliers:** Truncate ✂️ lower half of PPs to match output width to input width. Saves accumulation circuits but introduces large error.
*   Many **error compensation schemes** proposed to increase accuracy 🎯.
*   Examples:
    *   BBM: Omits adder cells.
    *   TBM-k: Truncates k LSBs of inputs. (Baseline).
    *   BM04: Uses exact carry from TPmajor and approximate from TPminor.
    *   BM11: Uses simplified sorting network for error compensation carries. Makes errors symmetrical, reduces bias/MSE.
    *   BM15: Error compensated by Booth encoders and multiplicand outputs.
    *   BM07: Adaptively variable PP columns in TPmajor for compensation.
    *   PEBM: Probabilistic estimation-based bias compensation formula.
    *   ABM2: Approximate radix-8 Booth multiplier with truncation.
    *   Approximate radix-4 Booth encoders: Simplify K-Map for k LSB PP columns.

---

### 📈 Evaluation of Approximate Booth Multipliers (16x16) 📊

*   Evaluated similar to unsigned multipliers, clock period 4 ns for power 🔌.
*   **Performance/Power vs. Accuracy (MRED/NMED) ⚡:** [65, Fig. 15, Fig. 16]
    *   Most fixed-width designs similar NMEDs, except BBM and BM15 (larger).
    *   TBM can have similar MRED, higher NMED, higher speed 🏎️, and power than fixed-width Booth designs.
    *   ABM2 is fastest and most power-efficient at moderate accuracy.
    *   BM07 is slowest and higher power at very high accuracy.
    *   PEBM shows moderate speed/power with relatively high accuracy.
*   **Energy vs. Accuracy (MRED/PDP) 🔋⚡:** [66, 67, Fig. 17]
    *   BM07, BM11, and PEBM show best accuracy-PDP tradeoffs.
    *   ABM2 and BBM also stand out for power-optimized synthesis.
*   **Summary:** BM07 and BM11 are accurate 🎯 but slow. PEBM has small NMED/PDP and high speed 🏎️. ABM2 is efficient in power/performance with moderate accuracy. Most fixed-width designs are better than TBMs due to compensation.

---

### ➗ Approximate Dividers ➗

*   Less frequently used than adders/multipliers, but crucial for performance ⚡. Hard to reduce latency without area overhead.
*   **Preliminaries 📚:**
    *   **Restoring/Nonrestoring Array Dividers:** Iteratively subtract multiples of divisor from partial remainder. Array requires O(n^2) subtractor cells for 2n/n division, critical path O(n). Speed improved with carry-save/carry-lookahead, increasing area/power.
    *   **SRT Dividers:** Speculate quotient bit based on few MSBs [69, 145–147]. Smaller subtractors, faster operation. High-radix versions generate multiple bits per iteration. Performance gain trades area/power.

---

*   Approximate divider design methodologies:
    1.  **Approximation in Subtractor/Adder Cells ➖➕:** Approximate restoring dividers (AXDr) replace subtractors with approximate ones. Accuracy varies with the approximate cell.
    2.  **Adaptive Approximation 🔄:** Determine inputs for a reduced-width exact divider based on leading "1" positions. Examples: DAXD (dynamic, truncates LSBs), AAXD (adaptive, prunes based on leading "1"s, error correction unit).
    3.  **Functional Approximation 🔧:** Convert division to simpler operations.
        *   Logarithmic: Antilog of difference of logs (Mitchell's algorithm). Examples: INZeD (integer, error correction, truncated subtractors).
        *   Rounding/Multiplication: Round divisor to 2^K+L/D, use multiplication/shifter/lookup tables. Examples: SEERAD.
        *   Piecewise Linear: Directly approximate antilog. Examples: HSD (lookup tables, multiplications).
        *   Hybrid: Combine array structure (MSBs) and logarithmic approximation (LSBs). Examples: AXHD.

---

### 📈 Evaluation of Approximate Dividers (16/8 Unsigned Integer) 📊

*   Evaluated with exhaustive simulation for error (MRED).
*   Synthesized in HDLs (Synopsys DC, 28-nm CMOS) for circuit measurements (delay ⏳, power 🔌). Clock: 5 ns.
*   Compared against MRED [75, Fig. 19, Fig. 20].
*   **Hardware vs. Accuracy (MRED) ⚙️🎯:** [76, Fig. 19]
    *   AXDr1/AXDr3 can be very accurate, but slow and moderate power.
    *   DAXD is generally least accurate.
    *   AAXD and INZeD show highest performance and lowest power for medium-low MRED. Best accuracy-hardware tradeoff.
    *   SEERAD is fastest at low accuracy.
*   **Energy vs. Accuracy (MRED/PDP) 🔋⚡:** [76, Fig. 20]
    *   SEERAD is lowest PDP for delay-optimized synthesis at low accuracy.
    *   INZeD is most efficient for moderate accuracy.
*   **Summary:** AAXD is efficient for high accuracy/performance. AXDr accurate but slow/high energy. INZeD efficient for moderate accuracy. SEERAD suitable for high inaccuracy tolerance.

---

### 🖼️ Applications: Image Processing 🎨

*   Assessing approximate designs in real applications.
*   Three applications considered: Image Sharpening 🔪, Image Compression (JPEG) 📸, Change Detection 🔍.

---

###  🖼️ Image Sharpening 🔪

*   Enhances edges using calculation: R = 2I - S, where S is convolution.
*   Requires multiplications ✖️, additions ➕, and a division ➗ (by constant).
*   Implemented using 16x16 unsigned multipliers and 16-bit adders.
*   Selected designs evaluated (based on accuracy-energy tradeoff).
*   **Results (PSNR) 📊:** [80, 81, Fig. 21]
    *   ICM (very low ER) and UDM (lower ER than many) perform as well as accurate multiplier. Designs with low ER are advantageous here.
    *   DRUM-7 and DRUM-6 (despite larger MRED/NMED) lead to higher PSNRs due to **unbiased errors**.
    *   HOCM performs well.
    *   Inaccurate adders/multipliers limit quality regardless of paired circuit.
*   **Circuit Measurements (Area-optimized synthesis) ⚙️:** [83, 84, Fig. 22]
    *   Multipliers dominate area and power dissipation.
    *   Adder plays significant role in critical path delay due to tree structure.
    *   ALM-SOA and TAM1-16 are very energy-efficient (PDP).
*   **PDP Reduction ⚡⏱️:** Significant savings possible (>50%) for PSNR > 35 dB [85, Fig. 23]. DRUM-6 best for high quality (PSNR > 40 dB), ALM-SOA best for relatively low quality (PSNR < 35 dB).

---

### 🖼️ Image Compression (JPEG) 📸

*   Lossy compression involving Discrete Cosine Transform (DCT) and Inverse DCT (IDCT). Uses signed multiplications ✖️.
*   Implemented with 16x16 approximate Booth multipliers and 16-bit adders.
*   **Results (PSNR) 📊:** [87, Fig. 24]
    *   Designs with large **single-sided error biases** (ACA, GeAr, ETAII, BBM) are **not suitable**. Errors accumulate in matrix multiplications.
    *   Among adders, LOA-3 performs best.
    *   Among multipliers, BM07, PEBM, TBM-2 outperform others.
    *   Some combinations (e.g., PEBM and TruA-1/2) higher quality.
    *   Generally, quality increases as multiplier MRED decreases.
    *   More complex computation (multiple matrix multiplications) is **more sensitive to addition errors** than multiplication errors (for same bit width). Larger approximation tolerable in multiplication.
*   **PDP Reduction (DCT implementation) ⚡⏱️:** [89, Fig. 25]
    *   Mix of AccuA & PEBM shows best tradeoff (20% reduction, ~30 dB PSNR).
    *   Using approximate adder with PEBM degrades quality significantly.
    *   PEBM, TBM-3, and ABM2 are more energy-efficient among Booth multipliers.

---

### 🧠 Deep Neural Networks (DNNs) 🤖

*   Face detection and alignment using a Multitask CNN (MTCNN). Convolution is a basic operation (multiplications ✖️ and additions ➕).
*   Integrated 16x16 approximate Booth multipliers and 16-bit adders into MTCNN architecture.
*   **Results (Face Detection - TPR) 👤:** [92, Table 6]
    *   Approximate Booth multipliers (except BBM) with LOA-3, LOA-4, TruA-1 perform well, close to accurate implementation.
    *   Designs with large error biases (ETAII-7, TruA-2, BBM) lead to low TPRs.
    *   Some combinations (ABM2/TBM-4 with AccuA) show higher TPRs than accurate design.
*   **Results (Face Detection - MACs) 🧮:** [93, Table 7]
    *   Number of MACs indicates energy efficiency.
    *   Combinations like ABM2/LOA-3, AccuM/TruA-1, BM07/TruA-1, PEBM/TruA-1/2 achieve high TPRs and require fewer MACs (higher energy efficiency) than accurate design.
    *   Approximate arithmetic circuits can improve DNN energy efficiency while maintaining or improving accuracy.

---

*   **Results (Face Alignment - NMEs) 📏:** [95, Table 8]
    *   MTCNNs using LOA-3 and LOA-4 consistently smaller NMEs than AccuA.
    *   TruA-1 good for detection but large NMEs for alignment. LOA-3 best among approximate adders.
    *   BM07 and PEBM are effective multipliers, smaller NMEs than accurate design.
    *   Designs with single-sided errors (BBM, ETAII-7, TruA-1/2) have low accuracy in detection/alignment.
    *   Face detection/alignment more sensitive to addition errors than multiplication errors (same bit width). Deeper approximation tolerable in multipliers.

---

### 📝 Characterization Summary 📋

*   **Approximate Adders ➕:**
    *   Most designed for high performance ⚡/low ER by reducing critical path.
    *   Speculative, segmented, carry-select adders show low ERs but often have single-sided errors leading to large biases, detrimental in iterative additions.
    *   Designs using approximate FAs (LOA, CCBA) or truncation (TruA) have high ERs but low MRED and low power.
    *   **Best accuracy-energy (MRED-PDP) tradeoffs:** LOA, CCBA, TruAs.
*   **Approximate Multipliers (AxMs) ✖️:**
    *   **Unsigned:** Truncating PPs/LSBs (BAM, TAM1, TruMs) effective for reducing area and preserving moderate accuracy. LMs are inaccurate but performance/power efficient. HOCM, TAM1, ALM-SOA show best energy-accuracy tradeoffs.
    *   **Signed (Booth):** Most fixed-width designs offer better tradeoffs than TBMs due to effective error compensation.

---

### 📝 Characterization Summary (Cont.) 🔄

*   **Approximate Dividers ➗:**
    *   Fewer designs compared to adders/multipliers.
    *   Approximation in subtractor/adder cells results in slow designs, accuracy depends on cell.
    *   Functional approximation designs are relatively faster.
    *   **Balanced tradeoffs (low PDP/MRED):** Logarithmic INZeD and input-adaptive AAXD.
*   **General Observations 👀:**
    *   More complex computations (multiple matrix multiplications) are **more vulnerable to errors in addition** than multiplication.
    *   A larger approximation can be tolerated in multipliers than adders for acceptable results. In such applications, multiplier dominates area/power, while adder is critical path.
    *   Approximate designs with large error biases significantly degrade accuracy in applications like DNNs.
    *   MRED is a good indicator of multiplier quality for DNNs.
    *   Approximate circuits can reduce power and improve energy efficiency in DNNs.

---

### ✅ Conclusion, Challenges, and Prospects 🎯

*   Reviewed, characterized, and evaluated approximate arithmetic circuits using functional simulation, circuit synthesis, and image processing/DNN applications.
*   Evaluation covered approximate adders, multipliers, and dividers under different design constraints (delay, area).
*   Showed how approximate circuits can provide performance and energy advantages with minimal accuracy loss for specific applications.
*   Highlighted the tradeoffs between hardware efficiency and accuracy for various designs.
*   Demonstrated application benefits in image processing and deep learning.

---

### 🙏 Thank You! Questions? ❓

*   This survey provided a comprehensive evaluation and comparison of recently proposed approximate arithmetic circuits.
*   The findings can guide the selection of appropriate designs for application-specific requirements (e.g., high performance or low power).
*   Future work involves addressing current challenges like developing more comprehensive error metrics, exploring new approximation techniques, and developing design automation tools for complex systems.
*   Thank you for your attention!

---

count: false
class: nord-dark, middle, center

# Q&A 🎤
