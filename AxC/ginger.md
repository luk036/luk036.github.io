layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# `ginger` Package: Finding Polynomial Roots 🚀🔍

@luk036 👨‍💻

2025-05-18 📅

---

Introduction to `ginger`

- **What is `ginger`?** 🤔💡
  - A Python package for solving polynomial equations. 🐍➗
  - Focuses on **finding the roots of polynomials**. 🌱🔢
  - A common problem in various fields (engineering, physics, computer science). 🏗️⚛️💻
  - Handles both real and complex roots. 🔢🌀
- **Core Functionality:** 🧠⚙️
  - Takes polynomial coefficients as input. 📥
  - Takes initial guesses for the roots. 🎯
  - Outputs the calculated roots. 📤✔️

---

Finding Roots with Aberth's Method (`ginger.aberth`)

- **Purpose:** Finds polynomial roots using Aberth's method. 🎯🔍
- **How it Works (Simply):** 🔄
  - An **iterative process** that refines initial guesses. 🔄✨
  - Uses a mathematical formula based on the **current polynomial value** and its **derivative** at that point, considering other guesses. 📈📉
  - Continues until guesses are sufficiently close to the actual roots. 🎯✅

---

- **Key Inputs (`ginger.aberth.aberth` function):** ⌨️📥
  - `coeffs`: List of coefficients (float). Ordered from highest degree to lowest. 📜🔢
    - Example: `[1, -2, -5, 3]` represents `x^3 - 2x^2 - 5x + 3 = 0`. ➗📊
  - `zs`: List of initial guesses (complex numbers). 🔢🌀
  - `options`: Optional `Options` object to control algorithm behavior (e.g., tolerance). ⚙️🎛️
- **Key Outputs (`ginger.aberth.aberth` function):** 📤✔️
  - A tuple: `(zs, niter, found)`.
  - `zs`: List of complex roots found. 🌱🔍
  - `niter`: Number of iterations performed. 🔄🔢
  - `found`: Boolean indicating if roots were found within specified tolerance. ✅❌

---

Variations in `ginger.aberth`

- **Algorithm Variations:** `ginger.aberth` offers different versions of the Aberth algorithm. 🔄🔀
  - Basic version: `aberth`. 🏁
  - Multithreaded version: `aberth_autocorr_mt`. ⚡🧵
  - Autocorrelation versions: `aberth_autocorr`, `aberth_autocorr_orig`. These are designed for certain polynomial types. 🔄📊

---

Helpers in `ginger.aberth`

- **Initial Guess Functions:** Crucial for good performance. 🎯⚡
  - `initial_aberth(coeffs)`: Calculates initial guesses. Returns a list of complex numbers. 🔢🌀
  - `initial_aberth_autocorr(coeffs)`: Calculates initial values based on auto-correlation method. Returns a list of complex numbers. 🔄📊
  - Other variations exist for different auto-correlation approaches. 🔄🔀
- **Polynomial Evaluation Helpers:** Efficiently evaluate polynomials and derivatives. ⚡📈
  - `horner_eval`: Evaluates a polynomial using Horner's scheme. ➗🔍
  - `horner_backward`: Evaluates a polynomial's derivative using Horner's scheme. (Note: Source description slightly differs, mentioning Horner's backward evaluation of _a_ polynomial, while ties it to derivatives). 📉🔙

---

Finding Roots with Bairstow's Method (`ginger.rootfinding`)

- **Purpose:** Finds polynomial roots, primarily using **Bairstow's method**. 🎯🔍
- **How it Works (Simply):** 🔄
  - Another iterative method. 🔄
  - Uses a technique called "**sup-pression**" to improve root estimate accuracy. 🎯✨
  - Finds quadratic factors of the polynomial. ➗🔍
  - Process continues until desired accuracy or max iterations reached. 🎯⏱️

---

- **Key Inputs (`ginger.rootfinding.bairstow_even` function):** ⌨️📥
  - `coeffs`: List of coefficients (float). 📜🔢
  - `vrs`: List of initial guesses for quadratic factors (represented by `Vector2` objects). Each `Vector2` represents `r` and `q` for a factor `x^2 - rx + q`. 🔢📐
  - `options`: Optional `Options` object (instance of `ginger.rootfinding.Options`). ⚙️🎛️
- **Key Outputs (`ginger.rootfinding.bairstow_even` function):** 📤✔️
  - A tuple: `(vrs, niter, found)`.
  - `vrs`: List of calculated quadratic factors (`Vector2` objects). 📐🔍
  - `niter`: Number of iterations performed. 🔄🔢
  - `found`: Boolean indicating if the algorithm successfully converged. ✅❌

---

Helpers in `ginger.rootfinding`

- **Options:** ⚙️
  - The `ginger.rootfinding.Options` class allows customization. 🛠️
  - `max_iters`: Maximum number of iterations (default 2000). 🔄🔢
- **Initial Guessing:** 🎯
  - `initial_guess(coeffs)`: Calculates initial guesses for Bairstow's method. Returns a list of `Vector2` objects. 🔢📐
- **Quadratic Root Finding:** ➗🔍
  - `find_rootq(vr)`: Solves a quadratic equation of the form `x^2 - rx + q = 0`.
  - Input: `vr` (a `Vector2` where x=r, y=q). 📐
  - Output: A tuple of two complex roots. 🔢🌀

---

Tools in `ginger.rootfinding`

- **Horner's Method:** ➗🔍
  - `horner(coeffs, degree, vr)`: Evaluates a polynomial using Horner's scheme with a quadratic factor `x^2 - rx + q` represented by `vr`. Returns a `Vector2`. 📊📐
- **Sup-pression:** 🎯✨
  - Functions like `suppress`, `suppress2`, `suppress_old` are part of the "sup-pression" technique used in Bairstow's method. 🔄📉
  - These functions take `Vector2` objects as input and return `Vector2` objects. 📐➡️📐

---

Vectors (`ginger.vector2`)

- **Purpose:** Represents 2D vectors and provides basic operations. 📐⚙️
- **Class `Vector2(x, y)`:** 📐
  - Represents a vector with components `x` and `y`. 🔢
- **Functionality:** ⚙️
  - **Dot Product:** `dot(rhs)`. ✖️
    - Calculates the dot product of the vector instance with another `Vector2` (`rhs`).
    - Returns a float. 🔢
    - Example: `v1 = Vector2(1, 2)`, `v2 = Vector2(3, 4)`. `v1.dot(v2)` returns `(1*3 + 2*4) = 11`. ➗✔️
  - **Component Access:** `x` and `y` properties. 🔍
    - Return the respective component values. 🔢
    - Example: `v = Vector2(1, 2)`. `v.x` returns `1.0`, `v.y` returns `2.0`. ✔️

---

Other Modules & Structure

- **`ginger.matrix2`:** 🧮
  - Handles 2x2 matrix operations. ➗📊
  - Includes a `det()` function for the determinant. 🔍
  - Includes an `mdot()` function for matrix-vector multiplication. ✖️📐
- **`ginger.autocorr`:** 🔄
  - Includes a function `extract_autocorr(vr)`. 🔍
  - Takes a `Vector2` `vr` and extracts a quadratic `x^2 - (r+q)x + r*q` where `vr` components are `r` and `q`.
  - Returns a `Vector2`. 📐
- **`ginger.skeleton`:** 💀
  - Provides an example entry point for a Python console script. 🐍⌨️
  - Includes basic functions like `fib(n)` (Fibonacci), `main(args)`, `parse_args()`, `run()`, `setup_logging()`. 🔢⚙️
  - Shows how to structure a command-line interface. 🖥️

---

Summary & Conclusion

- The `ginger` package provides sophisticated tools for finding polynomial roots 🛠️🌱.
- It implements established methods like **Aberth's method** and **Bairstow's method**. 🔍📊
- Includes helper modules for linear algebra (`vector2`, `matrix2`) and polynomial evaluation (`horner`). ➗📐
- Designed to be **accurate and efficient**, useful for high-degree polynomials. 🎯⚡
- Explore the modules and functions covered (`ginger.aberth`, `ginger.rootfinding`, `ginger.vector2`) for your root-finding needs! ✨🔍

**GitHub** 🐙: [ginger](https://github.com/luk036/ginger) 🔗

---

FAQs 🤔

- Q: What is the purpose of the `ginger.rootfinding.bairstow_even` function?
- A: The `ginger.rootfinding.bairstow_even` function is a part of the root-finding algorithm that uses the Bairstow method to find the roots of a polynomial. It is particularly useful for finding the roots of even-degree polynomials.
- Q: How does the `ginger.rootfinding.bairstow_even` function work?
- A: The `ginger.rootfinding.bairstow_even` function uses the Bairstow method to find the roots of a polynomial. It starts with an initial guess for the quadratic factors and iteratively refines these guesses until the desired accuracy is reached or the maximum number of iterations is reached.
- Q: What is the role of the `ginger.rootfinding.Options` class?
- A: The `ginger.rootfinding.Options` class is used to customize the behavior of the root-finding algorithm. It allows you to set the maximum number of iterations and other parameters.

---

count: false
class: nord-dark, middle, center

# Q&A 🎤
