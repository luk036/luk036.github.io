
# Generating Fixed Density Bracelets of Arbitrary Base

### Title Slide 👋🎉

*   **Generating fixed density bracelets of arbitrary base**
*   S. Karim, Z. Alamgir & S. M. Husnine
*   International Journal of Computer Mathematics, 2014 Vol. 91, No. 3, 434–446
*   *Published online: 18 Jun 2013* 📅

---

### What are Combinatorial Objects? 🤔🔢

*   Discrete structures like permutations, combinations, graphs, strings.
*   Generating lists of these objects is **immensely important** in mathematics and computer science.
*   Widely used in:
    *   Computational biology 🧬
    *   Combinatorial chemistry 🧪
    *   Operations research 📈
    *   Data mining ⛏️
    *   Calibration of colour printers (specifically bracelets) 🖨️

---

### Necklaces, Lyndon Words, and Bracelets 📿

*   These are specific types of k-ary strings (strings using an alphabet of size k).
*   **Necklace:** A **lexicographically minimal** k-ary string equivalent under **rotation**.
    *   *Example:* `0011` is a necklace from the rotation set `{0011, 0110, 1100, 1001}`.
*   **Lyndon Word:** An **aperiodic necklace** (a necklace that is its own shortest Lyndon prefix).
    *   *Example:* `0001` is a Lyndon word from the rotation set `{0001, 0010, 0100, 1000}`.
*   **Bracelet:** A **lexicographically minimal** k-ary string **symmetric under rotation and reversal**.
    *   *Example (binary):* `001100` is a bracelet because its rotations (`011000`, etc.) and reversals (`001100` reversed is `001100`) are considered, and `001100` is the smallest among them.

---

### What is "Fixed Density"? 🎯📊

*   A k-ary string is of **fixed density** if the **number of occurrences of symbol 0 is fixed**.
*   The sources define density `d` as the **number of non-zero symbols**.
    *   So, a string of length `n` with `d` non-zero symbols has `n-d` zeros.
*   We use notation like:
    *   `Nk(n, d)`: set of k-ary necklaces length `n`, density `d`.
    *   `Pk(n, d)`: set of k-ary prenecklaces length `n`, density `d`.
    *   `Bk(n, d)`: set of k-ary bracelets length `n`, density `d`.
*   Cardinality denoted `|Nk(n, d)|`, `|Pk(n, d)|`, `|Bk(n, d)|`.

---

### Counting Fixed Density Objects 📊🧮

*   The number of necklaces with specific counts of each symbol (`n0, n1, ..., nk-1`) is given by a formula involving Euler's totient function `φ`:
    `Nk(n0, n1, ..., nk-1) = (1/n) * Σ[j | gcd(n0,...,nk-1)] φ(j) * (n/j)! / ((n0/j)! ... (nk-1/j)!)`
*   `|Nk(n, d)|` is the sum of `Nk(n-d, n1, ..., nk-1)` over all combinations where `n1 + ... + nk-1 = d`.
*   For bracelets, the cardinality is related to necklaces: `|Nk(n)| <= 2|Bk(n)|` and `|Nk(n, d)| <= 2|Bk(n, d)|`.

---

### Generating Combinatorial Objects - Background ⏳🔄

*   Algorithms exist for generating necklaces, Lyndon words, and variants.
*   Recursive frameworks like Cattell et al. are used.
*   Algorithms for **necklaces with fixed density** exist.
*   Algorithms for **necklaces with fixed content** (fixed counts of *each* symbol) exist.
*   Algorithms for generating **bracelets** exist.
    *   Lisonek modified necklace generation.
    *   Sawada developed a **Constant Amortized Time (CAT)** algorithm.

---

### What is a CAT Algorithm? ⚡⏱️

*   **CAT (Constant Amortized Time):** An algorithm where the **total number of basic operations performed is proportional to the number of objects generated**.
*   On average, **each successive object is generated in constant time**.
*   This is **extremely desirable** in generation algorithms.
*   The goal of the paper is to present a CAT algorithm for fixed density bracelets.

---

### The Problem: Generating Fixed Density Bracelets 🤔🔧

*   "No significant work is done to list restricted classes of bracelets" like fixed density.
*   Goal: Develop an **algorithm for lexicographic listing of bracelets with fixed density**.
*   The algorithm should work for **arbitrarily large alphabet size** (k).
*   The algorithm should generate each successive bracelet in **constant amortized time**.

---

### Basic Building Block: Generating Prenecklaces (Naive) 🏗️🔨

*   Recursive algorithms for generating prenecklaces are based on the **Fundamental Theorem of Necklaces**.
*   **Theorem 2.1:** Let `α = a1...an-1 ∈ Pk(n-1)` and `p = lyn(α)` (length of longest Lyndon prefix).
    *   The string `αb` is in `Pk(n)` **iff** `an-p <= b <= k-1`.
    *   `lyn(αb)` is `p` if `an-p = b`, and `n` if `an-p < b`.
*   This theorem tells us which character `b` can be appended to a prenecklace `α` to get a new prenecklace `αb`.
*   A simple recursive algorithm `Necklace(t, p)` can list prenecklaces (and necklaces/Lyndon words with a `Print` function check).

---

### Naive Fixed Density Bracelet Algorithm (SimpleBFD) 🚶‍♂️🐢

*   A simple modification of the necklace algorithm (`SimpleBFD(t, p, r)`) can list fixed density bracelets.
*   It needs to ensure:
    1.  All generated prenecklaces have density `d`. (Requires checking non-zero count).
    2.  Only list bracelets.
*   Checking if a string is a bracelet usually involves comparing it to the necklace of its reversed string. This is O(n) and **prevents a CAT algorithm**.
*   Instead, a lemma from Sawada is used:
    *   **Lemma 3.1:** A necklace `α = a1...an` is a bracelet **iff** `ar+1...an <= an...ar+1` and `a1...at > at...a1` for no `t`, where `r` is the length of the longest prefix equal to its reversal (`a1...ar = ar...a1`).
*   This involves comparing the current prenecklace with its reversal using `CheckRev(t)`.

---

### `CheckRev(t)` Function 🤔🔁🔍

*   The `CheckRev(t)` function compares the prefix `a1...at` with its reversal `at...a1`.
*   It returns:
    *   `1` if `a1...at < at...a1`
    *   `0` if `a1...at = at...a1`
    *   `-1` if `a1...at > at...a1`
*   If `CheckRev(t)` returns `-1`, further generation from this prenecklace is stopped because it cannot be the minimal representative of a bracelet.
*   If `CheckRev(t)` returns `0`, the parameter `r` (length of longest equal-to-reversal prefix) is updated.
*   When length `n` is reached, `ar+1...an` is compared to its reversal.
*   *Issue:* This naive comparison is still **not constant time**.

---

### Towards an Efficient Algorithm (CAT) 💪⚡

*   The naive algorithm is inefficient.
*   An efficient (CAT) algorithm is presented by merging **optimizations from two existing CAT algorithms**:
    1.  Generating necklaces with fixed density.
    2.  Generating bracelets.

---

### Fixed Density Optimizations (from) ⬆️📈

*   **Optimization 1: Increase Density, Not Length:** Instead of appending one character, append characters to **increase the density by one**.
    *   Arrays `a` (positions of non-zero symbols) and `b` (values of non-zero symbols) are used.
    *   `t` = current density, `at` = length of current prenecklace.
    *   Determine valid position and value for the **next non-zero symbol**.
    *   Maximum position: `at+1 = at+1-p + ap`.
    *   Minimum value: `bat+1 = bat+1-p`. (Larger values also valid).
*   **Optimization 2: Density Constraints:**
    *   First non-zero symbol between `n-d+1` and `(n-1)/d+1`.
    *   `i`-th non-zero symbol at or before `n-d+i`-th position.
    *   Last non-zero symbol must be at `n`-th position.
    *   Stop recursive generation when density `d-1` is reached. The last symbol (at position `n`) is handled separately.
    *   Constant time test added to determine valid values for the last non-zero symbol at position `n`.

---

### Bracelet Optimizations (from) 🔄✨

*   **Optimization 1: Limited Reverse Checks:** If a necklace `α` is of the form `a...aii+1...an` (`a != ai+1`), only check reverse rotations starting with the same repeated symbol `ai`.
    *   Doesn't require generating the entire necklace.
    *   Still requires O(t) work per check.
*   **Optimization 2: Incremental Reversal Check:** The final test comparing `ar+1...an` to its reversal can be done incrementally.
    *   Start comparison once the "middle point" `floor((n-r)/2) + r` is reached.
    *   Use an additional parameter `RS` (Reverse Status) to store intermediate results.
    *   Update `RS` based on comparing the current character `at-1` with its corresponding character in the reversed string `an-t+2+r`.
    *   This makes the comparison a **constant time test per recursive call**.

---

### Merging Optimizations 🤝🔀

*   Combine the fixed density (increasing density, position/value arrays `a`, `b`) and bracelet (limited/incremental reversal checks) optimizations.
*   Recursive scheme `BraceFD(t, p, r, RS)`.
*   Use `a` for non-zero positions, `b` for values.
*   Assume `0 < d < n`, so strings start with `0`.
*   Fixed density optimization means prenecklaces **do not end with 0**.
*   Apply limited reverse checking (Optimization 1) when the form `0i...0ibat` is met. Update `r` if equal, terminate if reversal is less.
*   *Challenge:* Direct merging of the incremental RS update (Optimization 2) and fixed density (increasing density by more than one) is tricky.
    *   The fixed density algorithm can append a block of zeros (`at - at-1 > 1`), making the incremental RS check non-constant.

---

### Merging Optimizations - Handling the RS Update 🤔💻🔄

*   The incremental RS update needs to handle cases where multiple characters are appended at once (due to adding non-zero symbol at a specific position).
*   The RS value is computed when `at > (n-r)/2 + r`.
*   If `at - at-1 > 1`, comparing all characters between `at-1+1` and `at` takes non-constant time.
*   Only one non-zero symbol is in the block `0^(at-at-1-1)bat`.
*   RS can be computed in unit time if `bat != be`, where `e = n - at + r + 1`.
*   If `bat == be`, need to check the substring of zeros starting at `n - at + r + 2`. Use variables `si` (density up to pos `i`) and `li` (length of zero substring starting at pos `i`).
*   `le+1 = ase+1 - ase - 1`.
*   RS update rule based on `bat`, `be`, `at-at-1-1`, and `le+1`.

---

### The Algorithm Structure (High-Level) 🏗️✨📜

```mermaid
graph LR
    A[Start] --> B{Initialize Variables};
    B --> C[Iterate through valid positions for first non-zero symbol];
    C --> D[Call BraceFD(t, p, r, RS) for each position];
    D --> E{BraceFD(t, p, r, RS)};
    E --> F{t >= d-1?};
    F -- Yes --> G[Handle last non-zero symbol at position n];
    G --> H[Output Bracelet?];
    H --> I{More first positions to try?};
    F -- No --> J[Determine valid positions/values for next non-zero symbol];
    J --> K[CheckRev(t)];
    K --> L{CheckRev result?};
    L -- -1 (Greater) --> M[Terminate Branch];
    L -- 0 (Equal) --> N[Update r, Update RS];
    L -- 1 (Less) --> O[Update RS];
    N --> E;
    O --> E;
    K --> E; %% Recursive calls from J after CheckRev
    I -- Yes --> D;
    I -- No --> P[End];
    H --> I;
```

*   Algorithm is a recursive scheme `BraceFD(t, p, r, RS)`.
*   Initialisation `InitFixed()` sets up the calls by placing the first non-zero symbol in valid positions.
*   Generates strings belonging to `Nk(n, d)` in lexicographic order.
*   Eliminates necklaces whose reversed rotations are less than the necklace itself.
*   **Theorem 3.1:** `InitFixed()` lists all elements of `Bk(n, d)` exactly once in lexicographic order.

---

### Analysis: Proving CAT ⏱️📊

*   Claim: The algorithm works in Constant Amortized Time (CAT).
*   Computation tree represents recursive calls.
*   Size of the computation tree is proportional to `|Bk(n, d)|`. (Compared to fixed density necklace algorithm tree size proportional to `|Nk(n, d)|` and `|Nk(n, d)| <= 2|Bk(n, d)|`).
*   The work done *per node* (recursive call) is mostly constant.
*   The non-constant part is the `CheckRev(t)` function.
*   To prove CAT, show that **total symbol comparisons by CheckRev(t) is proportional to |Bk(n, d)|**.
*   The total number of prenecklaces generated by the scheme is proportional to `|Bk(n, d)|`.
*   Each comparison in `CheckRev(t)` is mapped to a unique prenecklace.

---

### Analysis: The Mapping Proof (Binary Case) 📊🔢

*   Focus first on the binary case (k=2).
*   `CheckRev(t)` compares `bj` with `bat-j` for `i+1 <= j <= at/2`. Stop when `j > at/2` or `bj != bat-j`.
*   At most one *unequal* comparison per prenecklace. Cost is constant.
*   Need to bound the number of *equal* comparisons.
*   Define a mapping `f(β, j)` for binary prenecklaces `β` and indices `j` where `β[1...j]` equals its reversal.
    *   `f` preserves length and content.
*   **Lemma 4.1:** `f(β, j)` is a valid prenecklace generated by the algorithm.
*   **Lemma 4.2:** The mapping `f` is **one-to-one** for valid `β` and `j`.
*   This one-to-one mapping implies the number of equal comparisons is bounded by the number of prenecklaces generated for the binary case.

---

### Analysis: The Mapping Proof (General Case k > 2) 🌐🔢

*   The binary mapping `f` doesn't work for `k > 2`.
*   A more complex mapping `g(β, j)` is defined for general `k`.
    *   `g` preserves length and content.
*   **Lemma 4.3:** `g(β, j)` is a valid prenecklace.
*   **Lemma 4.4:** The mapping `g` is **one-to-one** for valid `β` and `j`.
*   This one-to-one mapping proves that the total equal comparisons across all prenecklaces is proportional to the number of prenecklaces generated.

---

### Analysis: Final Bound 📈✅

*   Let `P'k(n, d)` be the number of prenecklaces generated by the fixed density necklace algorithm.
*   Let `Ck(i)` be the number of equal comparisons made by `CheckRev(t)` on prenecklaces of length `i`.
*   Total equal comparisons: `Sum(Ck(i))` for `i=1` to `n`.
*   Using Lemma 4.4, `Sum(Ck(i))` for `i=1` to `n-1` is bounded by `P'k(n, d)`.
*   From, `P'k(n, d)` is less than `2Nk(n, d)` for prenecklaces not ending in 0.
*   Also `Ck(n) <= 2Nk(n, d)`.
*   Total comparisons <= `(c' + 2)Nk(n, d)` where c' is a constant.
*   Since `Nk(n, d) <= 2Bk(n, d)`, Total comparisons <= `2(c' + 2)Bk(n, d)`.
*   This is `c * |Bk(n, d)|` for some constant `c`.
*   **Theorem 4.1:** Total equal comparisons are proportional to `|Bk(n, d)|`.
*   Since all other work is constant per generated prenecklace (and total prenecklaces is proportional to |Bk(n,d)|), the algorithm is **CAT**.

---

### Conclusion 🎉✨

*   Developed an **efficient scheme to generate bracelets with fixed density**.
*   Algorithm works for **arbitrary alphabet size** (k).
*   Uses sophisticated combinatorial techniques to prove it works in **Constant Amortized Time (CAT)**.
*   Takes **asymptotic linear space**.
*   Algorithm lists all elements of `Bk(n, d)` **exactly once in lexicographic order**.

---

### Future Work & Applications 🚀🔮

*   **Applications:** Explore the applications of this fixed density bracelet generation algorithm.
*   **Other restricted classes:** Develop schemes for listing other restricted classes of bracelets.
*   Generating necklaces with fixed content for the k-ary case remains an open problem.
*   Counting fixed-density prenecklaces is also an open problem.
*   The scheme has been implemented in C and is available from the authors.

---

### References 📚🔍

*   Cattell et al., Fast algorithms to generate necklaces..., J. Algorithms 37 (2000).
*   Dias et al., On the generation of bicliques of a graph, Discrete Appl. Math. 155 (2007).
*   Emmel and Hersch, Exploring ink spreading, Proc. 8th IS&T/SID Color Imaging Conf. (2000).
*   Gilbert and Riordan, Symmetry types of periodic sequences, Illinois J. Math. 5 (1961).
*   Karim et al., Generating bracelets with fixed content, Theor. Comput. Sci. 475 (2013).
*   Ruskey and Sawada, An efficient algorithm for generating necklaces of fixed density, SIAM J. Comput. 29 (1999).
*   Sawada, Generating bracelets in constant amortized time, SIAM J. Comput. 31 (2001).

