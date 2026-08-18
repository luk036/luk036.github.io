# Generating Fixed Density Bracelets of Arbitrary Base

## Title Slide 👋🎉

- **Generating fixed density bracelets of arbitrary base**
- S. Karim, Z. Alamgir & S. M. Husnine
- International Journal of Computer Mathematics, 2014 Vol. 91, No. 3, 434–446
- _Published online: 18 Jun 2013_ 📅

---

### What are Combinatorial Objects? 🤔🔢

- Discrete structures like permutations, combinations, graphs, strings.
- Generating lists of these objects is **immensely important** in mathematics and computer science.
- Widely used in:
- Computational biology 🧬
- Combinatorial chemistry 🧪
- Operations research 📈
- Data mining ⛏️
- Calibration of colour printers (specifically bracelets) 🖨️

---

### Necklaces, Lyndon Words, and Bracelets 📿

- These are specific types of k-ary strings (strings using an alphabet of size k).
- **Necklace:** A **lexicographically minimal** k-ary string equivalent under **rotation**.
- _Example:_ `0011` is a necklace from the rotation set `{0011, 0110, 1100, 1001}`.
- **Lyndon Word:** An **aperiodic necklace** (a necklace that is its own shortest Lyndon prefix).
- _Example:_ `0001` is a Lyndon word from the rotation set `{0001, 0010, 0100, 1000}`.
- **Bracelet:** A **lexicographically minimal** k-ary string **symmetric under rotation and reversal**.
- _Example (binary):_ `001100` is a bracelet because its rotations (`011000`, etc.) and reversals (`001100` reversed is `001100`) are considered, and `001100` is the smallest among them.

---

### 📿 Necklace vs Lyndon Word vs Bracelet

.mermaid[

<pre>
graph TD
    RO[Rotation Equivalence] --> NK[Necklaces]
    NK --> AP[Aperiodic]
    AP --> LW[Lyndon Words]
    NK --> RR[Rotation + Reversal]
    RR --> BR[Bracelets]
    style RO fill:#2196f3
    style NK fill:#4caf50
    style AP fill:#ff9800
    style LW fill:#9c27b0
    style RR fill:#f44336
    style BR fill:#2196f3
</pre>

]

---

### What is "Fixed Density"? 🎯📊

- A k-ary string is of **fixed density** if the **number of occurrences of symbol 0 is fixed**.
- The sources define density ${\color{coral}d}$ as the **number of non-zero symbols**.
- So, a string of length ${\color{coral}n}$ with ${\color{coral}d}$ non-zero symbols has ${\color{coral}n}-{\color{coral}d}$ zeros.
- We use notation like:
- ${\color{salmon}N_k}({\color{coral}n}, {\color{coral}d})$: set of k-ary necklaces length ${\color{coral}n}$, density ${\color{coral}d}$.
- ${\color{salmon}P_k}({\color{coral}n}, {\color{coral}d})$: set of k-ary prenecklaces length ${\color{coral}n}$, density ${\color{coral}d}$.
- ${\color{salmon}B_k}({\color{coral}n}, {\color{coral}d})$: set of k-ary bracelets length ${\color{coral}n}$, density ${\color{coral}d}$.
- Cardinality denoted $|{\color{salmon}N_k}({\color{coral}n}, {\color{coral}d})|$, $|{\color{salmon}P_k}({\color{coral}n}, {\color{coral}d})|$, $|{\color{salmon}B_k}({\color{coral}n}, {\color{coral}d})|$.

---

### Counting Fixed Density Objects 📊🧮

- The number of necklaces with specific counts of each symbol (${\color{coral}n_0}, {\color{coral}n_1}, \ldots, {\color{coral}n_{k-1} }$) is given by a formula involving Euler's totient function $\varphi$:
  ${\color{salmon}N_k}({\color{coral}n_0}, {\color{coral}n_1}, \ldots, {\color{coral}n_{k-1} }) = (1/{\color{coral}n}) * \sum[j \mid \gcd({\color{coral}n_0}, \ldots, {\color{coral}n_{k-1} })] \varphi(j) * ({\color{coral}n}/j)! / (({\color{coral}n_0}/j)! \ldots ({\color{coral}n_{k-1} }/j)!)$
- $|{\color{salmon}N_k}({\color{coral}n}, {\color{coral}d})|$ is the sum of ${\color{salmon}N_k}({\color{coral}n}-{\color{coral}d}, {\color{coral}n_1}, \ldots, {\color{coral}n_{k-1} })$ over all combinations where ${\color{coral}n_1} + \ldots + {\color{coral}n_{k-1} } = {\color{coral}d}$.
- For bracelets, the cardinality is related to necklaces: $|{\color{salmon}N_k}({\color{coral}n})| \le 2|{\color{salmon}B_k}({\color{coral}n})|$ and $|{\color{salmon}N_k}({\color{coral}n}, {\color{coral}d})| \le 2|{\color{salmon}B_k}({\color{coral}n}, {\color{coral}d})|$.

---

### Generating Combinatorial Objects - Background ⏳🔄

- Algorithms exist for generating necklaces, Lyndon words, and variants.
- Recursive frameworks like Cattell et al. are used.
- Algorithms for **necklaces with fixed density** exist.
- Algorithms for **necklaces with fixed content** (fixed counts of _each_ symbol) exist.
- Algorithms for generating **bracelets** exist.
- Lisonek modified necklace generation.
- Sawada developed a **Constant Amortized Time (CAT)** algorithm.

---

### What is a CAT Algorithm? ⚡⏱️

- **CAT (Constant Amortized Time):** An algorithm where the **total number of basic operations performed is proportional to the number of objects generated**.
- On average, **each successive object is generated in constant time**.
- This is **extremely desirable** in generation algorithms.
- The goal of the paper is to present a CAT algorithm for fixed density bracelets.

---

### The Problem: Generating Fixed Density Bracelets 🤔🔧

- "No significant work is done to list restricted classes of bracelets" like fixed density.
- Goal: Develop an **algorithm for lexicographic listing of bracelets with fixed density**.
- The algorithm should work for **arbitrarily large alphabet size** (k).
- The algorithm should generate each successive bracelet in **constant amortized time**.

---

### Basic Building Block: Generating Prenecklaces (Naive) 🏗️🔨

- Recursive algorithms for generating prenecklaces are based on the **Fundamental Theorem of Necklaces**.
- **Theorem 2.1:** Let $α = a_1...a_{n-1} \in {\color{salmon}P_k}({\color{coral}n}-1)$ and ${\color{firebrick}p} = lyn(α)$ (length of longest Lyndon prefix).
- The string $αb$ is in ${\color{salmon}P_k}({\color{coral}n})$ **iff** $a_{n-p} \le {\color{green}b} \le {\color{coral}k}-1$.
- $lyn(αb)$ is ${\color{firebrick}p}$ if $a_{n-p} = {\color{green}b}$, and ${\color{coral}n}$ if $a_{n-p} < {\color{green}b}$.
- This theorem tells us which character ${\color{green}b}$ can be appended to a prenecklace $α$ to get a new prenecklace $αb$.
- A simple recursive algorithm $Necklace({\color{green}t}, {\color{firebrick}p})$ can list prenecklaces (and necklaces/Lyndon words with a `Print` function check).

---

### Naive Fixed Density Bracelet Algorithm (SimpleBFD) 🚶‍♂️🐢

- A simple modification of the necklace algorithm ($SimpleBFD({\color{green}t}, {\color{firebrick}p}, {\color{firebrick}r})$) can list fixed density bracelets.
- It needs to ensure:
  1. All generated prenecklaces have density ${\color{coral}d}$. (Requires checking non-zero count).
  2. Only list bracelets.
- Checking if a string is a bracelet usually involves comparing it to the necklace of its reversed string. This is $O({\color{coral}n})$ and **prevents a CAT algorithm**.
- Instead, a lemma from Sawada is used:
- **Lemma 3.1:** A necklace $α = a_1...a_n$ is a bracelet **iff** $a_{r+1}...a_n \le a_n...a_{r+1}$ and $a_1...a_t > a_t...a_1$ for no ${\color{green}t}$, where ${\color{firebrick}r}$ is the length of the longest prefix equal to its reversal ($a_1...a_r = a_r...a_1$).
- This involves comparing the current prenecklace with its reversal using `CheckRev(t)`.

---

### `CheckRev(t)` Function 🤔🔁🔍

- The $CheckRev({\color{green}t})$ function compares the prefix $a_1...a_t$ with its reversal $a_t...a_1$.
- It returns:
- $1$ if $a_1...a_t < a_t...a_1$
- $0$ if $a_1...a_t = a_t...a_1$
- $-1$ if $a_1...a_t > a_t...a_1$
- If $CheckRev({\color{green}t})$ returns $-1$, further generation from this prenecklace is stopped because it cannot be the minimal representative of a bracelet.
- If $CheckRev({\color{green}t})$ returns $0$, the parameter ${\color{firebrick}r}$ (length of longest equal-to-reversal prefix) is updated.
- When length ${\color{coral}n}$ is reached, $a_{r+1}...a_n$ is compared to its reversal.
- _Issue:_ This naive comparison is still **not constant time**.

---

### 🏗️ Fixed Density Bracelet Generation Flow

.mermaid[

<pre>
graph TD
    IN[Initialize Variables] --> LP[Loop Positions]
    LP --> BF[BraceFD Recursive Call]
    BF --> CH{Density = d-1?}
    CH -->|Yes| HD[Handle Last Symbol]
    CH -->|No| NV[Next Valid Position/Value]
    NV --> CR[CheckRev Comparison]
    CR -->|Greater| TB[Terminate Branch]
    CR -->|Equal| UR[Update r, RS]
    CR -->|Less| US[Update RS]
    UR --> BF
    US --> BF
    HD --> OB[Output Bracelet]
    style IN fill:#2196f3
    style LP fill:#4caf50
    style BF fill:#ff9800
    style CH fill:#9c27b0
    style HD fill:#f44336
    style NV fill:#2196f3
    style CR fill:#4caf50
    style TB fill:#f44336
    style UR fill:#ff9800
    style US fill:#9c27b0
    style OB fill:#4caf50
</pre>

]

---

### Towards an Efficient Algorithm (CAT) 💪⚡

- The naive algorithm is inefficient.
- An efficient (CAT) algorithm is presented by merging **optimizations from two existing CAT algorithms**:
  1. Generating necklaces with fixed density.
  2. Generating bracelets.

---

### Fixed Density Optimizations (from) ⬆️📈

- **Optimization 1: Increase Density, Not Length:** Instead of appending one character, append characters to **increase the density by one**.
- Arrays ${\color{green}a}$ (positions of non-zero symbols) and ${\color{green}b}$ (values of non-zero symbols) are used.
- ${\color{green}t}$ = current density, ${\color{green}a_t}$ = length of current prenecklace.
- Determine valid position and value for the **next non-zero symbol**.
- Maximum position: ${\color{green}a_{t+1} } = {\color{green}a_{t+1-p} } + {\color{green}a_p}$.
- Minimum value: ${\color{green}b_{a_{t+1} }} = {\color{green}b_{a_{t+1-p} }}$. (Larger values also valid).
- **Optimization 2: Density Constraints:**
- First non-zero symbol between ${\color{coral}n}-{\color{coral}d}+1$ and $({\color{coral}n}-1)/{\color{coral}d}+1$.
- ${\color{green}i}$-th non-zero symbol at or before ${\color{coral}n}-{\color{coral}d}+{\color{green}i}$-th position.
- Last non-zero symbol must be at ${\color{coral}n}$-th position.
- Stop recursive generation when density ${\color{coral}d}-1$ is reached. The last symbol (at position ${\color{coral}n}$) is handled separately.
- Constant time test added to determine valid values for the last non-zero symbol at position ${\color{coral}n}$.

---

### Bracelet Optimizations (from) 🔄✨

- **Optimization 1: Limited Reverse Checks:** If a necklace $α$ is of the form $a...a_i a_{i+1}...a_n$ ($a \ne a_{i+1}$), only check reverse rotations starting with the same repeated symbol $a_i$.
- Doesn't require generating the entire necklace.
- Still requires $O({\color{green}t})$ work per check.
- **Optimization 2: Incremental Reversal Check:** The final test comparing $a_{r+1}...a_n$ to its reversal can be done incrementally.
- Start comparison once the "middle point" $\lfloor ({\color{coral}n}-{\color{firebrick}r})/2 \rfloor + {\color{firebrick}r}$ is reached.
- Use an additional parameter ${\color{green}RS}$ (Reverse Status) to store intermediate results.
- Update ${\color{green}RS}$ based on comparing the current character $a_{t-1}$ with its corresponding character in the reversed string $a_{n-t+2+r}$.
- This makes the comparison a **constant time test per recursive call**.

---

### Merging Optimizations 🤝🔀

- Combine the fixed density (increasing density, position/value arrays ${\color{green}a}$, ${\color{green}b}$) and bracelet (limited/incremental reversal checks) optimizations.
- Recursive scheme $BraceFD({\color{green}t}, {\color{firebrick}p}, {\color{firebrick}r}, {\color{green}RS})$.
- Use ${\color{green}a}$ for non-zero positions, ${\color{green}b}$ for values.
- Assume $0 < {\color{coral}d} < {\color{coral}n}$, so strings start with $0$.
- Fixed density optimization means prenecklaces **do not end with 0**.
- Apply limited reverse checking (Optimization 1) when the form $0^i...0^i {\color{green}b}{\color{green}a_t}$ is met. Update ${\color{firebrick}r}$ if equal, terminate if reversal is less.
- _Challenge:_ Direct merging of the incremental RS update (Optimization 2) and fixed density (increasing density by more than one) is tricky.
- The fixed density algorithm can append a block of zeros (${\color{green}a_t} - {\color{green}a_{t-1} } > 1$), making the incremental RS check non-constant.

---

### Merging Optimizations - Handling the RS Update 🤔💻🔄

- The incremental RS update needs to handle cases where multiple characters are appended at once (due to adding non-zero symbol at a specific position).
- The RS value is computed when ${\color{green}a_t} > ({\color{coral}n}-{\color{firebrick}r})/2 + {\color{firebrick}r}$.
- If ${\color{green}a_t} - {\color{green}a_{t-1} } > 1$, comparing all characters between ${\color{green}a_{t-1} }+1$ and ${\color{green}a_t}$ takes non-constant time.
- Only one non-zero symbol is in the block $0^{ {\color{green}a_t}-{\color{green}a_{t-1} }-1}{\color{green}b_{a_t} }$.
- RS can be computed in unit time if ${\color{green}b_{a_t} } \ne {\color{green}b_e}$, where ${\color{green}e} = {\color{coral}n} - {\color{green}a_t} + {\color{firebrick}r} + 1$.
- If ${\color{green}b_{a_t} } = {\color{green}b_e}$, need to check the substring of zeros starting at ${\color{coral}n} - {\color{green}a_t} + {\color{firebrick}r} + 2$. Use variables ${\color{green}s_i}$ (density up to pos ${\color{green}i}$) and ${\color{green}l_i}$ (length of zero substring starting at pos ${\color{green}i}$).
- ${\color{green}l_{e+1} } = {\color{green}a_{s_e+1} } - {\color{green}a_{s_e} } - 1$.
- RS update rule based on ${\color{green}b_{a_t} }$, ${\color{green}b_e}$, ${\color{green}a_t}-{\color{green}a_{t-1} }-1$, and ${\color{green}l_{e+1} }$.

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

- Algorithm is a recursive scheme $BraceFD({\color{green}t}, {\color{firebrick}p}, {\color{firebrick}r}, {\color{green}RS})$.
- Initialisation $InitFixed()$ sets up the calls by placing the first non-zero symbol in valid positions.
- Generates strings belonging to ${\color{salmon}N_k}({\color{coral}n}, {\color{coral}d})$ in lexicographic order.
- Eliminates necklaces whose reversed rotations are less than the necklace itself.
- **Theorem 3.1:** $InitFixed()$ lists all elements of ${\color{salmon}B_k}({\color{coral}n}, {\color{coral}d})$ exactly once in lexicographic order.

---

### Analysis: Proving CAT ⏱️📊

- Claim: The algorithm works in Constant Amortized Time (CAT).
- Computation tree represents recursive calls.
- Size of the computation tree is proportional to $|{\color{salmon}B_k}({\color{coral}n}, {\color{coral}d})|$. (Compared to fixed density necklace algorithm tree size proportional to $|{\color{salmon}N_k}({\color{coral}n}, {\color{coral}d})|$ and $|{\color{salmon}N_k}({\color{coral}n}, {\color{coral}d})| \le 2|{\color{salmon}B_k}({\color{coral}n}, {\color{coral}d})|$).
- The work done _per node_ (recursive call) is mostly constant.
- The non-constant part is the `CheckRev(t)` function.
- To prove CAT, show that **total symbol comparisons by $CheckRev({\color{green}t})$ is proportional to $|{\color{salmon}B_k}({\color{coral}n}, {\color{coral}d})|$**.
- The total number of prenecklaces generated by the scheme is proportional to $|{\color{salmon}B_k}({\color{coral}n}, {\color{coral}d})|$.
- Each comparison in `CheckRev(t)` is mapped to a unique prenecklace.

---

### Analysis: The Mapping Proof (Binary Case) 📊🔢

- Focus first on the binary case (k=2).
- $CheckRev({\color{green}t})$ compares $b_j$ with $b_{a_t-j}$ for ${\color{green}i}+1 \le {\color{green}j} \le {\color{green}a_t}/2$. Stop when ${\color{green}j} > {\color{green}a_t}/2$ or $b_j \ne b_{a_t-j}$.
- At most one _unequal_ comparison per prenecklace. Cost is constant.
- Need to bound the number of _equal_ comparisons.
- Define a mapping $f(β, {\color{green}j})$ for binary prenecklaces $β$ and indices ${\color{green}j}$ where $β[1...{\color{green}j}]$ equals its reversal.
- $f$ preserves length and content.
- **Lemma 4.1:** $f(β, {\color{green}j})$ is a valid prenecklace generated by the algorithm.
- **Lemma 4.2:** The mapping $f$ is **one-to-one** for valid $β$ and ${\color{green}j}$.
- This one-to-one mapping implies the number of equal comparisons is bounded by the number of prenecklaces generated for the binary case.

---

### Analysis: The Mapping Proof (General Case k > 2) 🌐🔢

- The binary mapping $f$ doesn't work for ${\color{coral}k} > 2$.
- A more complex mapping $g(β, {\color{green}j})$ is defined for general ${\color{coral}k}$.
- $g$ preserves length and content.
- **Lemma 4.3:** $g(β, {\color{green}j})$ is a valid prenecklace.
- **Lemma 4.4:** The mapping $g$ is **one-to-one** for valid $β$ and ${\color{green}j}$.
- This one-to-one mapping proves that the total equal comparisons across all prenecklaces is proportional to the number of prenecklaces generated.

---

### Analysis: Final Bound 📈✅

- Let ${\color{salmon}P'_k}({\color{coral}n}, {\color{coral}d})$ be the number of prenecklaces generated by the fixed density necklace algorithm.
- Let $C_k({\color{green}i})$ be the number of equal comparisons made by $CheckRev({\color{green}t})$ on prenecklaces of length ${\color{green}i}$.
- Total equal comparisons: $\sum C_k({\color{green}i})$ for ${\color{green}i}=1$ to ${\color{coral}n}$.
- Using Lemma 4.4, $\sum C_k({\color{green}i})$ for ${\color{green}i}=1$ to ${\color{coral}n}-1$ is bounded by ${\color{salmon}P'_k}({\color{coral}n}, {\color{coral}d})$.
- From, ${\color{salmon}P'_k}({\color{coral}n}, {\color{coral}d})$ is less than $2{\color{salmon}N_k}({\color{coral}n}, {\color{coral}d})$ for prenecklaces not ending in 0.
- Also $C_k({\color{coral}n}) \le 2{\color{salmon}N_k}({\color{coral}n}, {\color{coral}d})$.
- Total comparisons <= $({\color{coral}c'} + 2){\color{salmon}N_k}({\color{coral}n}, {\color{coral}d})$ where c' is a constant.
- Since ${\color{salmon}N_k}({\color{coral}n}, {\color{coral}d}) \le 2{\color{salmon}B_k}({\color{coral}n}, {\color{coral}d})$, Total comparisons <= $2({\color{coral}c'} + 2){\color{salmon}B_k}({\color{coral}n}, {\color{coral}d})$.
- This is ${\color{coral}c} * |{\color{salmon}B_k}({\color{coral}n}, {\color{coral}d})|$ for some constant ${\color{coral}c}$.
- **Theorem 4.1:** Total equal comparisons are proportional to $|{\color{salmon}B_k}({\color{coral}n}, {\color{coral}d})|$.
- Since all other work is constant per generated prenecklace (and total prenecklaces is proportional to $|{\color{salmon}B_k}({\color{coral}n}, {\color{coral}d})|$), the algorithm is **CAT**.

---

### 🌳 CAT Algorithm Recursion Tree

.mermaid[

<pre>
graph TD
    R[Root] --> L1_1[Level 1]
    R --> L1_2[Level 1]
    R --> L1_3[Level 1]
    L1_1 --> L2_1[Level 2]
    L1_1 --> L2_2[Level 2]
    L1_2 --> L2_3[Level 2]
    L1_3 --> L2_4[Level 2]
    L2_1 --> LN_1[Leaf<br/>Bracelet]
    L2_2 --> LN_2[Leaf<br/>Bracelet]
    L2_3 --> LN_3[Leaf<br/>Bracelet]
    L2_4 --> LN_4[Leaf<br/>Bracelet]
    style R fill:#2196f3
    style L1_1 fill:#4caf50
    style L1_2 fill:#4caf50
    style L1_3 fill:#4caf50
    style L2_1 fill:#ff9800
    style L2_2 fill:#ff9800
    style L2_3 fill:#ff9800
    style L2_4 fill:#ff9800
    style LN_1 fill:#9c27b0
    style LN_2 fill:#9c27b0
    style LN_3 fill:#9c27b0
    style LN_4 fill:#9c27b0
</pre>

]

---

### Conclusion 🎉✨

- Developed an **efficient scheme to generate bracelets with fixed density**.
- Algorithm works for **arbitrary alphabet size** (k).
- Uses sophisticated combinatorial techniques to prove it works in **Constant Amortized Time (CAT)**.
- Takes **asymptotic linear space**.
- Algorithm lists all elements of ${\color{salmon}B_k}({\color{coral}n}, {\color{coral}d})$ **exactly once in lexicographic order**.

---

### Future Work & Applications 🚀🔮

- **Applications:** Explore the applications of this fixed density bracelet generation algorithm.
- **Other restricted classes:** Develop schemes for listing other restricted classes of bracelets.
- Generating necklaces with fixed content for the k-ary case remains an open problem.
- Counting fixed-density prenecklaces is also an open problem.
- The scheme has been implemented in C and is available from the authors.

---

### References 📚🔍

- Cattell et al., Fast algorithms to generate necklaces..., J. Algorithms 37 (2000).
- Dias et al., On the generation of bicliques of a graph, Discrete Appl. Math. 155 (2007).
- Emmel and Hersch, Exploring ink spreading, Proc. 8th IS&T/SID Color Imaging Conf. (2000).
- Gilbert and Riordan, Symmetry types of periodic sequences, Illinois J. Math. 5 (1961).
- Karim et al., Generating bracelets with fixed content, Theor. Comput. Sci. 475 (2013).
- Ruskey and Sawada, An efficient algorithm for generating necklaces of fixed density, SIAM J. Comput. 29 (1999).
- Sawada, Generating bracelets in constant amortized time, SIAM J. Comput. 31 (2001).
