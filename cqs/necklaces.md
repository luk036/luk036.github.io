layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# 📿 Necklaces, Lyndon Words, and Combinatorial Structures

@luk036 👨‍💻

2025-06-05 📅

---

## Overview 🔍

Combinatorics often deals with counting and classifying objects, and strings over a given alphabet are fundamental among them. When these strings are arranged in a circle, allowing for different orientations to be considered the same, we enter the realm of necklaces and bracelets. 🔄

Example: The strings "🅰🅱🅲", "🅱🅲🅰", and "🅲🅰🅱" represent the same 3-bead necklace when arranged circularly.

Further constraints on these circular arrangements lead to specialized objects like Lyndon words. The study of these structures reveals deep connections to areas like abstract algebra, algorithms, and sequences used in computer science and even biology. 🧬💻

---

### Understanding Strings and Circular Arrangements 🔤

- Linear Strings 📏

  A string is a sequence of symbols from an alphabet. For length n and k colors, there are k^n possible linear strings. 🎨

  Example: For alphabet {◼,◻} and length 3, there are 8 strings: ◼◼◼, ◼◼◻, ◼◻◼, ◼◻◻, ◻◼◼, ◻◼◻, ◻◻◼, ◻◻◻.

- Circular Arrangements 🔵

  When arranged in a circle, multiple linear strings can represent the same necklace. For example, ◼◼◼◻, ◼◼◻◼, ◼◻◼◼, and ◻◼◼◼ all represent the same four-bead necklace. 🔄

- Equivalence Classes ⚖️

  A necklace is formally defined as an equivalence class of n-character strings over an alphabet of size k, where strings are considered equivalent if one can be obtained from the other by rotation. 🔄

---

### Necklaces and Symmetry ✨

- Rotation Equivalence 🔄

  Necklaces are defined by rotation equivalence, where strings that can be rotated into one another are considered the same necklace.

  Example: "🅰🅰🅱🅰🅱" and "🅰🅱🅰🅰🅱" are rotations of the same necklace.

- Counting Challenge 🧮

  Simply dividing k^n by n doesn't work because group sizes vary. Some necklaces have only one representation, while others have n. 🤔

  Example: "◼◼◼◼" has only one distinct rotation, while "◼◻◼◻" has two.

- Burnside's Lemma 🔥

  This powerful technique helps count objects considered the same "up to" some kind of symmetry. The number of k-ary necklaces of length n is denoted N_k(n). 🧮

  Example: For 4-bead necklaces with k colors: N_k(4) = (1/4)(k^4 + k^2 + 2k).
  For k=2: N_2(4) = (16+4+4)/4 = 6 necklaces.

---

### Bracelets: Adding Reflection Symmetry ✨

- Bracelets 💫

  Equivalence under both rotation AND reflection 🔄 ↔️

  Example: "🅰🅱🅲" and "🅲🅱🅰" are the same bracelet (mirror images).

- Necklaces 📿

  Equivalence under rotation only 🔄

  Example: "🅰🅱🅲" and "🅲🅱🅰" are different necklaces.

A bracelet, also known as a turnover or free necklace, considers strings equivalent under both rotation and reflection. Think of it this way: a necklace has a fixed direction, but a bracelet can be worn on either wrist, making its direction unimportant. 🤔

Example: For binary strings of length 4, there are 6 necklaces but only 4 bracelets.

---

### Lyndon Words: Special Representatives 🅰️

- Definition 📖

  A Lyndon word is a nonempty string that is strictly smaller in lexicographic order than all of its rotations. 🔄

  Example: "🅰🅰🅱" is Lyndon because "🅰🅰🅱" < "🅰🅱🅰" < "🅱🅰🅰".

- Alternative Definition 🔁

  A Lyndon word is lexicographically strictly smaller than any of its proper suffixes. ⬇️

  Example: "🅰🅰🅱🅰🅱" is not Lyndon because "🅰🅱" < "🅰🅰🅱🅰🅱".

- Key Property 🔑

  Lyndon words are inherently aperiodic - they cannot be formed by repeating a shorter string. 🔁

  Example: "🅰🅱🅰🅱" is periodic (repeats "🅰🅱") and not Lyndon.

---

### Lyndon Words: Historical Note 📜

Investigated by Roger Lyndon (who called them standard lexicographic sequences) and Anatoly Shirshov (regular words). 👨‍🎓

Within the set of necklaces, aperiodic necklaces are those where all n rotations of the string are distinct. Each aperiodic necklace contains exactly one string that is lexicographically smallest among all its rotations - this unique string is a Lyndon word. 🏆

Example: For length 3 binary strings, the Lyndon words are "◼◼◻", "◼◻◻", and "◻◻◻".

---

### Chen–Fox–Lyndon Theorem and Factorization

- Standard Factorization ✂️

  Any string can be uniquely factorized into a nonincreasing sequence of Lyndon words 📉

  Example: "🅰🅰🅱🅰🅱" = (🅰🅰🅱)(🅰🅱)

- Duval's Algorithm ⚡

  Linear-time, constant-space method for finding this factorization ⏱️

  Example: Processes "🅰🅰🅱🅰🅱" left-to-right to find the factors.

The Chen–Fox–Lyndon theorem states that any string can be uniquely formed by concatenating a nonincreasing sequence of Lyndon words. This process, known as standard factorization, provides a fundamental structure for strings. 🏗️

For example, the string "🅰🅰🅱🅰🅱🅲🅰🅱🅲🅿" might be factorized as (🅰🅰🅱)(🅰🅱)(🅲)(🅰🅱🅲🅿), where each component is a Lyndon word and they appear in nonincreasing lexicographic order. 📊

---

### Mathematical Relationships ➗

The relationship between Lyndon words and necklaces is fundamental: Lyndon words are the canonical representatives of aperiodic necklaces. The number of k-ary Lyndon words of length n, denoted L_k(n), is related to the number of necklaces N_k(n) and aperiodic necklaces M_k(n) through formulas involving the Möbius function (μ) and Euler's totient function (φ). 🔗

Example: For binary strings of length 4:

- N_2(4) = 6 necklaces
- L_2(4) = 2 Lyndon words ("◼◼◼◻" and "◼◼◻◻")

These mathematical relationships reveal the deep structure underlying these combinatorial objects, connecting them to number theory and abstract algebra. 🧮

---

### De Bruijn Sequences and Connections 🔗

- De Bruijn Sequences 🌀

  Circular sequences containing every possible string of a given length exactly once as a substring 🎯

  Example: "◼◼◼◻◼◻◻◻" contains all 3-bit binary strings when wrapped circularly.

- Lyndon Connection ⛓️

  Concatenating all Lyndon words whose lengths divide n in lexicographic order results in the lexicographically smallest de Bruijn sequence 🏆

  Example: For n=3, concatenating "◼" and "◼◼◼◻" and "◼◼◻◻" etc. forms the sequence.

- Ranking Algorithms 📊

  Algorithms for ranking and unranking strings within a de Bruijn sequence often rely on algorithms for ranking necklaces and Lyndon words ⚙️

---

A remarkable connection exists between Lyndon words and de Bruijn sequences, which have applications in cryptography, pseudo-random number generation, and DNA sequencing. This connection demonstrates how these combinatorial structures extend beyond theoretical interest into practical applications. 🔗

---

### Related Combinatorial Objects 🧩

- Unlabeled Necklaces 🏷️

  These consider strings equivalent not only under rotation but also under permutations of the alphabets, creating a different equivalence relation.

  Example: "🅰🅰🅱" and "🅱🅱🅰" might be equivalent under permutation.

- Charm Bracelets ✨

  A generalization of bracelets considering a broader group of affine transformations on the indices, expanding the symmetry concept. 🔄

- Chord Diagrams 🎼

  Represented by points on a circle connected by chords, these have their own enumeration formulas related to the combinatorial structures we've discussed. 🎵

The study of necklaces and Lyndon words has led to the exploration of many related combinatorial objects, each with their own properties and applications in mathematics and computer science. 🧮💻

---

### Algorithms and Applications ⚙️

- Generation Algorithms

  Efficiently generating lists of necklaces, bracelets, and Lyndon words 📋

  Example: FKM algorithm generates necklaces in amortized O(1) time per necklace.

- Ranking Algorithms 📈

  Finding the position of an object in a lexicographically sorted list 🔍

  Example: Determining that "◼◼◻◻" is the 3rd binary necklace of length 4.

- Unranking Algorithms 📉

  Finding the object at a given position in the sorted list 🎯

  Example: Generating the 5th binary bracelet of length 6 directly.

---

Efficient algorithms have been developed for tasks such as generating these combinatorial objects, finding their standard factorization, and determining their rank in a lexicographically sorted list. These algorithms often have polynomial time complexity, specifically noted as O(n²) for ranking necklaces/Lyndon words, O(n³ log k) for unranking, and O(n²) for ranking de Bruijn sequences. ⏱️

These algorithms have practical implementations in areas such as data compression, cryptography, computational biology, and computer graphics, demonstrating how these theoretical structures find real-world applications. 🌍

---

count: false
class: nord-dark, middle, center

## Q&A 🎤
