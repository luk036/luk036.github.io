layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Multiplierless Filter Design in Python ✨

@luk036 👨🏻‍🏫

2025-05-18 📅

---

## What is `multiplierless`? 🤔

*   It's a Python project focused on **multiplierless FIR filter design** 🔧.
*   **FIR filters** (Finite Impulse Response) are signal processing tools 📡.
*   A **lowpass filter** is a type of FIR filter that lets low-frequency signals pass while reducing high frequencies 🔊.
*   The **"multiplierless" aspect** means the filter is designed **without using multiplication operations** ❌✖️.
*   This is particularly **beneficial in certain hardware implementations** where multiplication is costly in terms of resources or power 💾⚡.

---

## Why Multiplierless? 💡

*   Designing digital filters without multiplication is a specialized task 🎯.
*   It's crucial for engineers and researchers working on digital signal processing (DSP) systems with **specific hardware constraints** 🖥️🔌.
*   Avoiding multipliers can lead to simpler, smaller, faster, or more power-efficient hardware [Information not in sources, but a common reason for multiplierless design. This is external information.] ⚡🚀.

---

## Core Components: Key Modules 📚

The project is structured into several modules, including:
*   `multiplierless.lowpass_oracle_q` 🎛️
*   `multiplierless.spectral_fact` 🌈
*   `multiplierless.skeleton` 💀

---

## `lowpass_oracle_q` Module 📉✨

*   Purpose: Designed to help with designing **multiplierless lowpass filters** 🛠️.
*   Contains the `LowpassOracleQ` class 🏗️.
*   `LowpassOracleQ` is a **Lowpass oracle** for the multiplierless lowpass filter design problem 🔮.

---

## `LowpassOracleQ` Class & `assess_optim_q` Method 📊✅

*   `LowpassOracleQ` takes two inputs during initialization: `nnz` (likely "number of non-zero elements") and `lowpass` (an object related to lowpass filter design) ⚙️.
*   The main method is `assess_optim_q`, which takes `r`, `Spsq`, and `retry` as inputs 🔄.
*   Its purpose is to **evaluate and optimize** the filter design through iterative steps 🔍.

---

**`assess_optim_q` Steps**

Here's what `assess_optim_q` does:
1.  **Feasibility Check:** If not a retry, it checks if the current design is feasible using the `assess_feas` method of the `lowpass` object ✔️.
2.  **Transformation:** If feasible, it converts input `r` into a filter response using **spectral factorization** ♻️.
3.  **CSD Conversion:** Converts the response to **CSD (Canonical Signed Digit) representation**, useful for multiplierless designs 🔢.
4.  **Further Optimization:** Calls the `assess_optim` method of the `lowpass` object for more optimization (either after the above steps or if it's a retry) ⚡.
5.  **Return:** Returns a tuple with optimized coefficients, CSD representation, updated frequency response, and a boolean for retries 📤.

*   Uses advanced concepts like spectral factorization and CSD representation 🧠.
*   The output is an **intermediate step** in an iterative optimization process 🔄.

---

## `spectral_fact` Module 📈🔢

*   Purpose: Implements **spectral factorization**, a mathematical technique in signal processing 🧮.
*   Goal: Computes a **minimum-phase impulse response** that satisfies a given auto-correlation 🎯.
*   Think of it as finding a sequence of numbers (impulse response) that matches a pattern of relationships between data points (auto-correlation) 🔍.

---

**`spectral_fact` & `inverse_spectral_fact`**

*   **`spectral_fact(r)`:**
    *   Takes `r`, the **top-half of the auto-correlation coefficients**, as input 📥.
    *   Returns `h`, the **impulse response** that gives the desired auto-correlation 📤.
    *   Uses steps like oversampling, logarithmic frequency domain representation, Hilbert transform, complex representation, and inverse Fourier transform 🔄.
    *   Implements the **Kolmogorov 1939 approach** 🏛️.

*   **`inverse_spectral_fact(h)`:**
    *   Takes the impulse response `h` as input 📥.
    *   Attempts to reconstruct the **original auto-correlation coefficients** ♻️.
    *   Uses a mathematical operation called **convolution** 🔄.

---

## Dependencies

The project depends on specific libraries:
*   `luk036/csdigit` 📚
*   `luk036/ginger` 📚
*   `luk036/ellalgo` 📚
*   The **core ellipsoid method** specifically depends on `ellalgo` and `numpy` 🧮.

---

## Conclusion 🎉

*   **`multiplierless`** is a Python project for designing FIR filters, specifically tailored to **avoid multiplication operations** ❌✖️.
*   It uses advanced signal processing techniques like spectral factorization and CSD representation 🛠️.
*   It's an **iterative optimization tool** for engineers and researchers dealing with hardware constraints 🔧.
*   Contributions are welcome! 🤝

**GitHub** 🐙: [multiplierless](https://github.com/luk036/multiplierless) 🔗

---

count: false
class: nord-dark, middle, center

.pull-left[

# Q & A 🎤

] .pull-right[

![Discussion](figs/questions-and-answers.svg)

]