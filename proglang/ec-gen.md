layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Exploring the `ec-gen` Package for Combinatorial Generation

@luk036 👨‍💻

2025-05-16 📅

---

### Introduction to `ec-gen` 📦📊

- Welcome! 👋 Today we'll look at the `ec-gen` Python package, a toolkit for working with combinatorial mathematics. 🐍
- Its main purpose is generating possible combinations, permutations, and other related structures from a given set of elements. 🔄
- It aims to be efficient and flexible, handling various inputs and producing different types of outputs as needed. ⚡

---

### `ec-gen.combin` Module - Combinations Generator 🎲

- This module focuses on generating combinations, where the order of selection does not matter. ❌🔀
- It takes two main inputs: `n` (total number of elements) and `k` (number of elements to choose). 📥
- It leverages recursion and memoization for calculations, and a special algorithm called the "homogeneous revolving-door" method for generating combinations by swapping pairs of elements. 🔄🚪
- Handling even and odd numbers of elements is noted as an important logic flow. ⚖️

---

### Key Functions in `ec-gen.combin`:

- `ec_gen.combin.comb(n, k)`: Calculates the number of combinations of `k` elements from a set of `n` elements. It returns the size of the combination. 📏
  - Example: `comb(6, 3)` returns `20`.
  - Example: `comb(6, 4)` returns `comb(6, 2)` which is `15`.
- `ec_gen.combin.comb_recur(n, k)`: Also calculates the number of combinations using recursion and memoization. Returns two values, `a` and `b`. 🔢

---

### `ec-gen.combin` - Generating Combinations 🚪🔄

- The `emk_comb_gen` function is the core generator in this module, using the homogeneous revolving-door algorithm. 🏗️
- `ec_gen.combin.emk_comb_gen(n, k, zero, one)`: Generates combinations by swapping pairs of integers. 🔄
  - `n`: Total number of elements.
  - `k`: Number of ones in each combination.
  - `zero`: Value representing "0", defaults to 0.
  - `one`: Value representing "1", defaults to 1.
  - Returns: A generator object that yields pairs of integers swapped.

---

### Example Usage:

```python
>>> for s in emk_comb_gen(6, 3, zero=" ", one="■"):
...     print("".join(s))
```

- This example shows generating combinations of 6 elements taking 3, represented by "■" and " ". The output visualizes these combinations. 🖥️

### Variants for Specific Swaps:

- `emk_comb_even(n, k)`: Generates combinations by swapping pairs of integers using the emk algorithm. 🔄
- `emk_comb_odd(n, k)`: Similar to `emk_comb_even`, uses the emk algorithm.
- `emk_comb_neg_even(n, k)`: Generates combinations by swapping pairs of integers in _reverse_ order using the emk algorithm. ⏪
- `emk_comb_neg_odd(n, k)`: Similar to `emk_comb_neg_even`, in reverse order.

---

### `ec-gen.ehr` Module - Permutations via EHR 🔄✨

- This module provides a function to generate permutations (arrangements) of a set of items where order _does_ matter. 🔢
- It implements a function `ehr_gen` using the Ehrlich-Hopcroft-Reingold (EHR) algorithm. 🏗️
- The purpose is to efficiently generate all possible permutations of a given length. ⚡
- The algorithm achieves this by swapping pairs of elements, using two lists (`a` and `b`) to track the state and updates.

---

### Key Function:

- `ec_gen.ehr.ehr_gen(n)`: Generates all permutations of a given length `n` using the EHR algorithm.
  - `n`: The number of elements in the permutation.
  - Returns: A generator object that yields the index of the element to be swapped with the first element.

### Example Usage:

```python
>>> for i in ehr_gen(4):
...     print("Swap 0 and {}".format(i))
```

- This example shows the sequence of swaps needed to generate permutations for 4 elements. The output indicates swapping the element at index 0 with element at index `i`. 🔄

---

### `ec-gen.sjt` Module - Permutations via Steinhaus-Johnson-Trotter 🚶‍♂️🚶‍♀️

- This module implements the Steinhaus-Johnson-Trotter algorithm for generating all possible permutations. 🔄
- It provides two main functions: `sjt_gen` and `sjt2` (or `plainChanges`), which generate a sequence of swaps or yield the permutations directly. 🏗️
- An important aspect of this algorithm is that it generates permutations such that each new permutation differs from the previous one by just a single swap of adjacent elements. This property is efficient for certain applications. ⚡

---

### Key Functions:

- `ec_gen.sjt.plainChanges(n)`: Generates the swaps for the Steinhaus-Johnson-Trotter algorithm (original method).
  - `n`: The number of elements in the permutation.
  - Returns: A generator object.
  - Example output shows pairs of indices being swapped.
- `ec_gen.sjt.sjt_gen(n)`: Generates permutations of length `n` using the Steinhaus-Johnson-Trotter algorithm.
  - `n`: The number of elements in the permutation.
  - Returns: A generator object. Note: returns the original permutations after all swaps.
- `ec_gen.sjt.sjt2(n)`: Generates permutations of length `n` using the Steinhaus-Johnson-Trotter algorithm. Yields values instead of returning the whole list. Each permutation is represented as a list of integers.

---

### `ec-gen.gray_code` Module - Binary Gray Codes ⚫⚪

- This module implements a Gray Code generator. 🔄
- A Gray code is a sequence of binary numbers where each successive number differs from the previous one by only one bit. 1️⃣
- The code uses a clever recursive algorithm to generate the sequence. It starts with `n-1` bits, then generates the `n-1` sequence again. This mirrored pattern ensures each successive number differs by only one bit. 🌀
- The main logic involves finding the next element to swap by iterating through a list and updating it, similar to how Gray code works. 🔄
- It includes doctrings showing how to represent Gray codes using black and white squares 🔳⬜.

---

### Key Function:

- `ec_gen.gray_code.brgc_gen(n)`: Generates a binary reflected gray code sequence of length `n`.
  - `n`: Represents the number of bits in the binary code.
  - Returns: A generator object.

### Example Usage (Visual):

```python
>>> s = " ■"
>>> for i in brgc_gen(4):
...     mylist = list(s[j] for j in i)
...     print("".join(mylist))
```

- This shows the visual representation of 4-bit Gray codes using black and white squares. 🖥️

---

### `ec-gen.set_bipart` Module - Set Partitions (Bipartite) 🧱↔️🧱

- This module deals with Set Partitions. A set partition of `[n]` ({1, 2, ..., n}) is a collection of disjoint subsets (blocks) whose union is `[n]`. 🔗
- Each partition block is listed in increasing order of its smallest element. 📈
- Restricted Growth Strings (RG strings) are often used to represent partitions. An RG string `s` of length `n` represents a partition of `{1, ..., n}`. The digit `s[i-1]` indicates which block the element `i` belongs to. 🔤

---

### Key Concepts & Functions:

- `ec_gen.set_bipart.stirling2nd(n, k)`: Calculates the Stirling number of the second kind for a given integer `n` and `k` using a recursive approach. The Stirling number of the second kind counts the number of ways to partition a set of `n` objects into `k` non-empty subsets. 🔢
  - Example: `stirling2nd(5, 2)` returns `15`.
- `ec_gen.set_bipart.bipart(n)`: Generates a sequence of moves that partition a set of size `n` into two subsets.
  - Example shows the sequence of moves between blocks B0 and B1.

---

### Generators based on conditions S(n, k) even/odd:

- `ec_gen.set_bipart.gen0_even(n, k)`
- `ec_gen.set_bipart.gen0_odd(n, k)`
- `ec_gen.set_bipart.gen1_even(n, k)`
- `ec_gen.set_bipart.gen1_odd(n, k)`
- `ec_gen.set_bipart.neg1_even(n, k)`
- `ec_gen.set_bipart.neg1_odd(n, k)`
- These functions generate sequences of numbers (likely RG strings or similar) satisfying certain conditions based on `n` and `k`.

---

### `ec-gen.set_partition` Module - Set Partitions (General) 🧱✨

- This module also deals with Set Partitions, described identically to the `set_bipart` module regarding definition and RG strings. 🔗
- It also contains the `stirling2nd` function for calculating Stirling numbers of the second kind. 🔢
- The structure and function names are very similar to the `set_bipart` module, perhaps representing different implementations or variations. 🔄

---

### Key Functions:

- `ec_gen.set_partition.set_partition(n, k)`: Generates all possible set partitions of a set of size `n` into `k` blocks.
  - `n`: Total number of elements.
  - `k`: Number of blocks in the set partition.
  - Returns: A generator.
  - Example shows generating partitions for n=5, k=2 and the sequence of moves.

---

### Generators based on conditions S(n, k) even/odd (similar to `set_bipart`):

- `ec_gen.set_partition.gen0_even(n, k)`
- `ec_gen.set_partition.gen0_odd(n, k)`
- `ec_gen.set_partition.gen1_even(n, k)`
- `ec_gen.set_partition.gen1_odd(n, k)`
- `ec_gen.set_partition.neg0_even(n, k)`
- `ec_gen.set_partition.neg0_odd(n, k)`
- `ec_gen.set_partition.neg1_even(n, k)`
- `ec_gen.set_partition.neg1_odd(n, k)`

---

### Summary and Use Cases ✨✅

- The `ec-gen` package provides specialized generators for various combinatorial objects:
  - **Combinations** using revolving-door algorithm. 🔄🚪
  - **Permutations** using EHR and Steinhaus-Johnson-Trotter algorithms. 🔄
  - **Gray Codes** using a recursive bit-flipping method. ⚫⚪
  - **Set Partitions** represented by RG strings and calculated via Stirling numbers of the second kind. 🧱
- It emphasizes efficiency, particularly for permutations and combinations. ⚡
- Useful in mathematics, computer science, and any field requiring systematic enumeration of possibilities 👩‍💻🔬.
- The use of generators 🔄 means it can handle large sets without storing all results in memory at once.

---

### References and Further Reading 📚

- The sources mention a reference for Simple Combinatorial Gray Codes constructed by reversing sublists:
  - Frank Ruskey, Simple Combinatorial Gray Codes constructed by reversing sublists, Lecture Notes in Computer Science, #762, 201-208. Also downloadable from: `http://webhome.cs.uvic.ca/~ruskey/Publications/SimpleGray/SimpleGray.html`.
- The skeleton module mentions references for setuptools entry points:
  - `https://setuptools.pypa.io/en/latest/userguide/entry_point.html`
  - `https://pypackaging.readthedocs.io/en/latest/command-line-scripts.html`

**GitHub** 🐙: [ec-gen](https://github.com/luk036/ec-gen) 🔗

---

count: false
class: nord-dark, middle, center

# Q&A 🎤
