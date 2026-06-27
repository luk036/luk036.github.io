layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# 📊 Exploring the `csdigit` Python Package

@luk036 👨‍💻 · 2026 📅

---

### 📋 Agenda

.pull-left[

**Part 1: Introduction** 🎯
- What is CSD?
- Package Overview
**Part 2: Features** 🛠
- CSD Conversion
- Substring Search

]
.pull-right[

**Part 3: Usage** 💻
- CLI Tools
- Examples

]

---

### ✨ Introduction to `csdigit`

- What is `csdigit`?
- A **Python package** 🐍.
- Provides functions for **converting decimal numbers to Canonical Signed Digit (CSD) format and vice versa** 🔄.
- Also includes other utilities like finding the **longest repeated substring** 🔍.
- What is CSD?

---

### Package Architecture

.mermaid[

<pre>
graph TD
  cli[cli<br/>Command Line] --> csd[csd<br/>Core Conversion]
  csd --> lcsre[lcsre<br/>Longest Repeated<br/>Substring]
  testing[Testing<br/>Doctest] --> csd
  style cli fill:#4caf50
  style csd fill:#ff9800
  style lcsre fill:#2196f3
  style testing fill:#9c27b0
</pre>

]

---

### 💻 `csdigit.cli` Module - CLI

- Purpose: Provides **console scripts** using setuptools 🛠️.
- Usage:
- Can be a **starting point for a Python console script** 🚀.
- Can also be used as a **template for Python modules** 📑.
- Installation often involves `pip install -e .` inside the package directory 📦.
- Key Components:
- `cli.main(args)`: A **wrapper function** 🎁.
- `cli.parse_args(args)`: **Parses command line parameters** 🗂️. Takes `args` (list of strings) and returns an `argparse.Namespace`.
- `cli.run()`: Function intended as an **entry point** using setuptools. It calls `cli.main` passing `sys.argv` ⚡.
- `cli.setup_logging(logLevel)`: Sets up **basic logging** 📝. Takes `logLevel` (int) as the minimum loglevel for emitting messages.

---

### ➕➖0️⃣ `csdigit.csd` Module - Core Conversion

- This module is the **main purpose of the code**.
- It provides functions that **convert decimal numbers to CSD strings** and **CSD strings back to decimal numbers** 🔢.
- CSD Representation:
- Uses the symbols `0`, `+`, and `-` ➕➖0️⃣.
- Can represent regular decimal numbers like **28.5** or **-0.5** 🔢.
- Converts them to CSD strings, e.g., "+00-00.+0" or "0.-0" 📜.

---

### ➡️ Converting to CSD (`to_csd`)

- The module contains several functions for conversion 🔄.
- `csdigit.csd.to_csd(decimal_value, places)`:
- Converts a **double precision floating-point number** to CSD 🎯.
- `decimal_value` (float): The number to convert 🔢.
- `places` (int): The **number of decimal places** in the CSD representation 🔢.
- Returns: A string representation of the CSD format 📜.
- Examples:
- `>>> to_csd(28.5, 2)`
- `'+00-00.+0'`
- `>>> to_csd(-0.5, 2)`
- `'0.-0'`

---

### ➡️ Converting to CSD (`to_csd_i`)

- `csdigit.csd.to_csd_i(decimal_value)`:
- Converts an **integer** into a CSD string 🔢.
- `decimal_value` (int): The integer to convert.
- Returns: A string containing the CSD representation 📜.
- Examples:
- `>>> to_csd_i(28)`
- `'+00-00'`
- `>>> to_csd_i(-0)`
- `'0'`

---

### Converting to CSD (`to_csdnnz`)

- `csdigit.csd.to_csdnnz(decimal_value, nnz)`:
- Converts a **decimal number** into a Canonical Signed Digit (CSD) representation 🔄.
- This is a variation that allows specifying the **maximum number of non-zero digits** 🔢.
- `decimal_value` (float): The number to convert.
- `nnz` (int): The desired **maximum number of non-zero bits** allowed in the output CSD string 🎯.
- Returns: A string in CSD format 📜.
- Examples:
- `>>> to_csdnnz(28.5, 4)`
- `'+00-00.+'`
- `>>> to_csdnnz(-0.5, 4)`
- `'0.-'`
- `>>> to_csdnnz(0.5, 4)`
- `'0.+'`

---

### Converting from CSD (`to_decimal`)

- `csdigit.csd.to_decimal(csd)`:
- Converts a **CSD string** to a decimal number 🔄.
- `csd` (str): The CSD string 📜.
- Returns: A float representing the decimal value 🔢.
- Examples:
- `>>> to_decimal("+00-00.+")`
- `28.5`
- `>>> to_decimal("0.-")`
- `-0.5`
- Additional functions handle parts or use different methods:
- `to_decimal_fractional`
- `to_decimal_integral`
- `to_decimal_using_pow(csd)`: Converts using the `pow` function. Example: `to_decimal_using_pow("+00-00.+0")` returns `28.5` ⚡.

---

### ⚙️ `csdigit.csd` Module - How it Works

- CSD conversion:
- Goes through each symbol in the CSD string 🔍.
- Applies operations based on the symbol: multiply by 2, **add 1 for '+'**, **subtract 1 for '-'**, **do nothing for '0'** ➕➖0️⃣.
- Handles the **decimal point separately** 🔢.
- Uses **separate logic** for the integral part and the fractional part 🧠.
- Includes **error checking** to ensure only valid CSD symbols are used ✅.
- Provides **documentation and examples** to help users understand how to use the functions 📚.
- Overall, provides a **comprehensive set of tools** for CSD conversion 🛠️.

---

### CSD vs Binary Representation

.mermaid[

<pre>
graph LR
  Binary[Binary<br/>0 and 1] -->|More non-zero| Switch1[Higher<br/>Switching Activity]
  CSD[Canonical SD<br/>0 + -] -->|Fewer non-zero| Switch2[Lower<br/>Switching Activity]
  style Binary fill:#f44336
  style Switch1 fill:#f44336
  style CSD fill:#4caf50
  style Switch2 fill:#4caf50
</pre>

]

---

### 🔄 `csdigit.lcsre` Module

- Purpose: Defines a function that finds the **longest repeated non-overlapping substring** within a given string 🔍.
- Function: `csdigit.lcsre.longest_repeated_substring(cs)`.
- `cs` (str): The **input string** 📜.
- Returns: The **longest repeated non-overlapping substring** 🔍.
- Method: Uses a **dynamic programming approach** (creating a 2D table) 🧮.
- Algorithm Logic:

1. Initialize a 2D table with zeros 0️⃣.
2. Iterate through the table, comparing characters of the input string 🔄.
3. When matching characters are found, **update the length of the repeated substring** in the table 📊.
4. Keep track of the **maximum length** found and its ending position 🎯.
5. After filling the table, **extract the longest repeated substring** using the recorded length and position 🔍.

---

- **Important Aspect:** Avoids overlapping substrings by checking the distance from the current position 🚫.
- Example:
- `>>> longest_repeated_substring("banana")`
- `'an'`
- `>>> longest_repeated_substring("0+-00+-0+-00+-0")`
- `'0+-00+-'`
- Potential Uses: **Text processing and analysis** 📝. Provides a computationally inexpensive approach ⚡.

---

### ✅ Summary and Conclusion

- The `csdigit` package offers modules for:
- `cli`: **Command-line interface** utilities 💻.
- `csd`: **Canonical Signed Digit (CSD) conversion** between decimal and CSD strings using `0`, `+`, and `-` ➕➖0️⃣.
- `lcsre`: Finding the **longest repeated non-overlapping substring** in a string using dynamic programming 🔍.
- It provides useful tools for CSD representation, relevant in areas like computer science and digital signal processing 💻📡.
- The conversion functions (`to_csd`, `to_decimal`, etc.) provide flexible ways to handle conversions based on decimal places or number of non-zero digits 🔄.
- The code includes examples, documentation, and error checking 📚✅.

**GitHub** 🐙: [csdigit](https://github.com/luk036/csdigit) 🔗

---

### FAQs 🤔

- Q: What is the purpose of the `csdigit` package?
- A: The `csdigit` package provides a set of tools for working with Canonical Signed Digit (CSD) representations and related operations. It includes functions for converting between decimal numbers and CSD strings, as well as finding the longest repeated non-overlapping substring in a given string.
- Q: How do I use the `csdigit` package?
- A: You can use the `csdigit` package by importing the relevant modules and functions. For example, to convert a decimal number to a CSD string, you can use the `to_csd` function. For more detailed usage instructions, refer to the package's documentation.
- Q: What is the purpose of the `lcsre` module?
- A: The `lcsre` module provides a function for finding the longest repeated non-overlapping substring in a given string. It uses a dynamic programming approach to efficiently solve this problem.
- Q: What is the purpose of the `cli` module?

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
