# 🚀 Table Look-Up Algorithms: From CORDIC to EDA
## A Journey Through Compute-Once, Lookup-Forever Optimization

---

# 📋 Agenda

| ⏱️ Time | 🎯 Topic |
|:-------:|:---------|
| 0–5 min | 🧮 What is Table Look-Up? |
| 5–10 min | ⚡ TLU in Action: Arithmetic, Crypto & Search |
| 10–18 min | 🔧 TLU in Electronic Design Automation |
| 18–25 min | 💻 Modern C++: `constexpr` CORDIC Case Study |
| 25–30 min | 🎯 Key Takeaways & Q&A |

---

# 🧮 What is Table Look-Up?

> **"The fastest computation is the one you don't have to perform."**

**Table Look-Up (TLU)** replaces runtime computation with **precomputed results** stored in memory.

```mermaid
graph LR
    A[📝 Input x] --> B{ {"Hash / Index / Decode"} }
    B --> C[("📊 Lookup Table<br/>ROM / RAM / Cache")]
    C --> D["✅ Output f(x)"]
    
    style A fill:#e1f5fe,stroke:#01579b,stroke-width:3px
    style B fill:#fff9c4,stroke:#f57f17,stroke-width:2px
    style C fill:#c8e6c9,stroke:#2e7d32,stroke-width:3px
    style D fill:#ffccbc,stroke:#bf360c,stroke-width:3px
```

**Core Idea:** Amortize expensive computation over many fast memory accesses.

---

# ⚖️ The Speed–Memory Tradeoff

```mermaid
graph TD
    subgraph "⚡ Compute at Runtime"
        A1[🔢 Algorithm] --> A2["⏳ O(n) or O(log n)"]
        A2 --> A3[💾 Low Memory<br/>❌ High Latency]
    end
    
    subgraph "📊 Table Look-Up"
        B1[🔨 Precompute Once] --> B2[💾 Store in Table]
        B2 --> B3["🔍 O(1) Lookup"]
        B3 --> B4[⚡ Low Latency<br/>📈 Higher Memory]
    end
    
    style A1 fill:#ffcdd2,stroke:#b71c1c
    style B1 fill:#c8e6c9,stroke:#1b5e20
    style B4 fill:#b3e5fc,stroke:#01579b
```

| Pattern | Benefit | Example |
|:-------:|:-------:|:-------|
| 🎯 **Function Approximation** | Avoid slow convergence | Sine LUT, Gamma tables |
| 🔢 **Finite Field Arithmetic** | Replace poly ops with addition | AES S-box, Reed-Solomon |
| 🤖 **State Machine Acceleration** | Next-state in one cycle | DFA, Branch Predictors |
| 🧠 **Memoization** | Reuse subproblems | BDD cache, Transposition tables |

---

# 🧮 TLU in Arithmetic: The CORDIC Family

**CORDIC** (COordinate Rotation DIgital Computer) is the *archetypal* table-driven algorithm.

```mermaid
graph TD
    subgraph "🔄 CORDIC Rotation Mode"
        direction LR
        A1[📐 Target Angle θ] --> B1["Stage 0: rotate ±45°"]
        B1 --> C1["Stage 1: rotate ±26.565°"]
        C1 --> D1["Stage 2: rotate ±14.036°"]
        D1 --> E1["... Stage N ..."]
        E1 --> F1["✅ Final (x, y)"]
    end
    
    style A1 fill:#e3f2fd,stroke:#1565c0,stroke-width:3px
    style F1 fill:#e8f5e9,stroke:#2e7d32,stroke-width:3px
```

**What the table stores:** Precomputed arctangent angles

$$\alpha_i = \arctan(2^{-i})$$

**Why it matters:** No multipliers needed — only shifts, adds, and table lookups! 🎯

---

# 📐 CORDIC Mathematics

**Rotation equations** (simplified for iteration $i$):

$$x_{i+1} = x_i - d_i \cdot y_i \cdot 2^{-i}$$

$$y_{i+1} = y_i + d_i \cdot x_i \cdot 2^{-i}$$

$$z_{i+1} = z_i - d_i \cdot \alpha_i$$

Where:
- $d_i \in \{-1, +1\}$ is the **direction** (sign of remaining angle)
- $\alpha_i = \arctan(2^{-i})$ is looked up from the **constant table** 📊

**Gain compensation** (also table-driven or hardcoded):

$$K = \prod_{i=0}^{N-1} \cos(\alpha_i) \approx 0.60725$$

```mermaid
pie showData
    title CORDIC Hardware Cost Breakdown
    "Adders" : 40
    "Shifters" : 30
    "LUT (atan table)" : 20
    "Control Logic" : 10
```

---

# 🔐 TLU in Cryptography: AES S-Box

The AES **SubBytes** step is a pure 256-byte table look-up.

```mermaid
graph LR
    A[🔢 Input Byte<br/>0x53] --> B["📊 S-Box LUT<br/>256 entries"]
    B --> C[🔐 Output Byte<br/>0xED]
    
    style A fill:#fff3e0,stroke:#e65100,stroke-width:3px
    style B fill:#e8f5e9,stroke:#2e7d32,stroke-width:3px
    style C fill:#e3f2fd,stroke:#1565c0,stroke-width:3px
```

**What the table stores:** 
$$S(x) = \text{Affine}\left(\text{GF}(2^8)\text{-Inverse}(x)\right)$$

**Speed-up:** O(1) non-linear substitution vs. computing multiplicative inverse in $\text{GF}(2^8)$ on the fly.

> 💡 **Fun fact:** AES also uses **T-tables** (4× 256-word tables) to combine SubBytes, ShiftRows, and MixColumns into a single lookup round! 🚀

---

# 🔍 TLU in String Matching

| Algorithm | Table | Speed-Up |
|:---------:|:-----:|:--------:|
| **Boyer-Moore** | Bad-character shift table | Skip up to $m$ chars per mismatch |
| **KMP** | Prefix function $\pi$ table | O(n) guaranteed, no backtracking |
| **Aho-Corasick** | Goto + Failure + Output links | O(n + m + z) multi-pattern matching |

```mermaid
graph LR
    A[📄 Text Stream] --> B{"🤔 Match?"}
    B -->|❌ Mismatch| C["📊 Shift Table:<br/>skip = 7"]
    B -->|✅ Match| D["🎯 Output Pattern"]
    C --> E["⏩ Fast Forward"]
    E --> B
    
    style C fill:#ffccbc,stroke:#bf360c,stroke-width:3px
    style D fill:#c8e6c9,stroke:#1b5e20,stroke-width:3px
```

---

# 🏗️ TLU in Computer Architecture

```mermaid
graph TD
    subgraph "🖥️ Architecture Lookup Tables"
        TLB[📘 TLB<br/>Virtual → Physical]
        BTB[📗 BTB<br/>Branch Target]
        BHT[📙 BHT<br/>Branch History]
        IDR[📕 Decode ROM<br/>Opcode → Control]
    end
    
    CPU[🧠 CPU Core] --> TLB
    CPU --> BTB
    CPU --> BHT
    CPU --> IDR
    
    style TLB fill:#e3f2fd,stroke:#1565c0
    style BTB fill:#e8f5e9,stroke:#2e7d32
    style BHT fill:#fff3e0,stroke:#e65100
    style IDR fill:#f3e5f5,stroke:#7b1fa2
```

| Table | Latency | Benefit |
|:-----:|:-------:|:-------|
| **TLB** | ~1 cycle | Avoids 2–4 level page table walks (10–100× faster) |
| **BTB** | 0 cycles | Zero-penalty taken branches |
| **BHT** | 0 cycles | Predicts branch direction via 2-bit saturating counters |
| **Decode ROM** | 1 cycle | Single-cycle instruction decode |

---

# 🔧 TLU in EDA: An Overview

Electronic Design Automation is **obsessed** with tables — from logic synthesis to signoff.

```mermaid
mindmap
  root((🔧 EDA<br/>Table Look-Up))
    Logic Synthesis
      🧩 Boolean Matching
      🗺️ Technology Mapping
      🔢 k-LUT Mapping
    Formal Verification
      🌳 BDD Unique Table
      🧠 Computed Table
      ✅ SAT Clause DB
    Static Timing
      ⏱️ Liberty Delay LUTs
      📐 Slew Tables
      🌡️ POCV Derating
    Physical Design
      📏 FLUTE Wirelength
      🛤️ Pattern Routing
      📍 Legalization
    Simulation
      ⚡ Compiled Gate LUTs
      🔋 Power State Tables
```

---

# 🧩 EDA: Logic Synthesis & Technology Mapping

**Boolean Matching (NPN Classification):**

```mermaid
graph LR
    A[🎲 4-input Function<br/>Truth Table] --> B["🔍 Signature / Hash"]
    B --> C["📊 NPN Class Table<br/>~222 classes for 4-input"]
    C --> D["🎯 Match Library Cell"]
    
    style A fill:#fff3e0,stroke:#e65100
    style C fill:#e8f5e9,stroke:#2e7d32,stroke-width:3px
    style D fill:#e3f2fd,stroke:#1565c0
```

**FPGA k-LUT Mapping (ABC, CutMap):**
- Precompute all **k-feasible cuts** for each node
- Store in priority-cut table
- **O(1) cut selection** instead of dynamic enumeration

$$K = 4 \Rightarrow \text{At most } 2^{2^4} = 65,536 \text{ functions to classify}$$

---

# ⏱️ EDA: Static Timing Analysis (STA)

**Liberty `.lib` Delay Model:**

```mermaid
graph TD
    A[📐 Input Transition] --> C["📊 2D LUT<br/>Delay = f(slew, load)"]
    B[📦 Output Load] --> C
    C --> D[⚡ Cell Delay]
    
    style C fill:#c8e6c9,stroke:#2e7d32,stroke-width:3px
    style D fill:#ffccbc,stroke:#bf360c,stroke-width:3px
```

**What the table stores:**

$$\text{Delay} = \text{LUT}[\text{Input Transition Time}, \text{Output Load Capacitance}]$$

**Speed-up:** O(1) interpolation vs. running SPICE for every cell instance in a million-gate design! 🚀

**Other STA tables:**
- 📐 **Slew tables** — output transition vs. load
- 🌡️ **POCV/SOCV derating** — variation-aware delay distributions
- 🔌 **Power LUTs** — internal & leakage power vs. input state

---

# 📏 EDA: Physical Design — FLUTE

**FLUTE** (Fast Look-Up Table based Wirelength Estimation) is a *masterclass* in TLU.

```mermaid
graph LR
    A[📍 Net with 7 pins] --> B["📊 FLUTE Table<br/>Precomputed RSMTs"]
    B --> C["📏 Wirelength<br/>+ Topology"]
    
    style A fill:#fff3e0,stroke:#e65100
    style B fill:#e8f5e9,stroke:#2e7d32,stroke-width:3px
    style C fill:#e3f2fd,stroke:#1565c0,stroke-width:3px
```

**The magic:**
- For $\leq 9$ pins: **Optimal** Rectilinear Steiner Minimal Tree is precomputed and stored
- For $> 9$ pins: Net is partitioned and table is applied recursively

**Impact:** FLUTE replaces NP-hard geometric Steiner algorithms with **O(1) lookup**, making it the backbone of academic analytical placers. 🎯

---

# ✅ EDA: Formal Verification — BDDs

**Binary Decision Diagrams** rely on two critical tables:

```mermaid
graph LR
    subgraph "🌳 BDD Tables"
        UT["📘 Unique Table<br/>Hash: (var, low, high)"]
        CT[📗 Computed Table<br/>Cache: ITE/Apply results]
    end
    
    A[🔢 Boolean Operation] --> UT
    UT -->|"✅ Exists"| B["🎯 Return Existing Node"]
    UT -->|"❌ New"| C["🆕 Create Node"]
    C --> CT
    CT --> D["💾 Memoize Result"]
    
    style UT fill:#e3f2fd,stroke:#1565c0,stroke-width:3px
    style CT fill:#c8e6c9,stroke:#2e7d32,stroke-width:3px
```

| Table | Purpose | Speed-Up |
|:-----:|:-------:|:--------:|
| **Unique Table** | Canonical node sharing | O(1) canonicity check; prevents exponential blow-up |
| **Computed Table** | Memoization cache | Avoids recomputing identical ITE/Apply subproblems |

> Without these tables, BDDs would be **Decision Trees** — exponentially large! 😱

---

# 💻 Modern C++: The `constexpr` Revolution

C++11/14/17/20 introduced `constexpr` — compile-time computation with zero runtime cost.

```mermaid
graph LR
    A[📝 C++ Source] --> B{"🔨 Compiler<br/>constexpr evaluation"}
    B --> C["📊 ROM Table<br/>in .rodata / .text"]
    C --> D["⚡ Runtime: O(1) Lookup<br/>Zero initialization cost!"]
    
    style B fill:#fff9c4,stroke:#f57f17,stroke-width:3px
    style C fill:#c8e6c9,stroke:#2e7d32,stroke-width:3px
    style D fill:#b3e5fc,stroke:#01579b,stroke-width:3px
```

**Why `constexpr` TLU is powerful:**
- 🚫 No runtime initialization overhead
- 🚫 No dependency on build scripts (Python/CMake table generators)
- ✅ Guaranteed compile-time validation
- ✅ Perfect for embedded, HLS, and bare-metal targets

---

# 🎯 Case Study: `constexpr` CORDIC

**The Challenge:** CORDIC needs $\arctan(2^{-i})$ values.

Pre-C++23, `std::atan` is **not** `constexpr`! So how do we build the table at compile time?

```cpp
// 🎯 Custom constexpr arctan approximation
template<typename T>
constexpr T constexpr_atan(T x) {
    // 🧮 Taylor series or CORDIC-like iteration
    // evaluated entirely at compile time!
    T result = 0;
    for (int n = 0; n < 20; ++n) {
        T term = /* ... */;
        result += term;
    }
    return result;
}

// 📊 Generate CORDIC angle table at compile time
template<int N, typename T>
struct CordicTable {
    static constexpr std::array<T, N> angles = []{
        std::array<T, N> a{};
        for (int i = 0; i < N; ++i)
            a[i] = constexpr_atan(T(1) / (T(1) << i));
        return a;
    }();
};
```

---

# 🏗️ GitHub Spotlight: DrasLorus/CORDIC_Rotate_APFX

**The most explicit `constexpr` CORDIC implementation on GitHub.**

```mermaid
graph LR
    subgraph "📦 CORDIC_Rotate_APFX Architecture"
        CR[CCordicRotateRom<br/>CMake-generated headers]
        CC[CCordicRotateConstexpr<br/>🔥 Pure C++14 constexpr]
        UM[Unfinished:<br/>CCordicRotateSmart<br/>No ROM needed]
    end
    
    style CC fill:#c8e6c9,stroke:#2e7d32,stroke-width:3px
```

| Feature | Detail |
|:-------:|:-------|
| **Standard** | C++14 (`-std=c++14`) |
| **Target** | Xilinx HLS / Hardware Simulation |
| **Precision** | Bit-accurate fixed-point (template word length) |
| **Stages** | 2 to 7 (template parameter) |
| **ROM** | Control signals per stage, indexed by input angle |
| **Generators** | True `constexpr` + Monte-Carlo (runtime) |

**Repository:** [github.com/DrasLorus/CORDIC_Rotate_APFX](https://github.com/DrasLorus/CORDIC_Rotate_APFX) 🔗

---

# 🤔 Why Is `constexpr` CORDIC So Rare?

```mermaid
graph LR
    A[🎯 Need CORDIC] --> B{"🤔 Implementation Choice?"}
    B -->|🔧 HDL| C[Verilog/VHDL<br/>Industry Standard]
    B -->|💻 Software| D[Runtime Library<br/>gcem, std::sin]
    B -->|⚡ Embedded| E[Static const array<br/>Precomputed literals]
    B -->|🔨 Modern C++| F["constexpr Template<br/>⚠️ Niche!"]
    
    style C fill:#e3f2fd,stroke:#1565c0
    style F fill:#ffccbc,stroke:#bf360c,stroke-width:3px
```

| Barrier | Explanation |
|:-------:|:-----------:|
| 🚫 `std::atan` not `constexpr` (pre-C++23) | Requires custom constexpr approximation |
| 🔧 EDA targets HDL | CORDIC is usually silicon, not software |
| 🐍 Build scripts are "good enough" | Python/CMake table generation is standard |
| 📚 Niche audience | Only HLS + bare-metal C++ developers care |

> **Exception:** DrasLorus's project bridges HLS and clean C++ — no CMake table generation needed! 🎉

---

# 🎯 Key Takeaways

```mermaid
graph TD
    A[🧠 Table Look-Up] --> B["⚡ O(1) Performance"]
    A --> C[💾 Memory Tradeoff]
    A --> D[🔧 Ubiquitous in EDA]
    A --> E[💻 Modernized by constexpr]
    
    B --> B1["CORDIC, AES S-Box,<br/>Branch Predictors"]
    C --> C1["FLUTE, BDD Tables,<br/>Liberty LUTs"]
    D --> D1["Synthesis, STA, P&R,<br/>Verification"]
    E --> E1["Compile-time ROM<br/>Zero runtime init"]
    
    style A fill:#fff9c4,stroke:#f57f17,stroke-width:3px
    style E fill:#c8e6c9,stroke:#2e7d32,stroke-width:3px
```

| # | 💡 Insight |
|:-:|:----------|
| 1 | **TLU is the original "cache"** — compute once, lookup forever |
| 2 | **CORDIC** epitomizes TLU: shifts, adds, and an atan table replace multipliers |
| 3 | **EDA runs on tables** — from NPN Boolean matching to FLUTE wirelength |
| 4 | **`constexpr` elevates TLU** — compile-time generation eliminates build dependencies |
| 5 | **The best algorithm is often the one you don't run** — just look it up! 📊 |

---

# 🙏 Thank You!

## Questions? 🎤

> **"The fastest computation is the one you don't have to perform."**

📧 **Resources:**
- 🔗 [DrasLorus/CORDIC_Rotate_APFX](https://github.com/DrasLorus/CORDIC_Rotate_APFX)
- 🔗 [kthohr/gcem](https://github.com/kthohr/gcem) — General constexpr math
- 🔗 [FLUTE](http://vlsicad.ucsd.edu/GSRC/bookshelf/Slots/RSMT/) — Fast LUT-based wirelength

**Happy Optimizing!** 🚀✨