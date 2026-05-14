layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# 📦 Packing and Re-packing

@luk036 👨‍💻

---

## Design flow of FPGA

.mermaid[

<pre>
flowchart TD
    LS[Logic Synthesis] --> TM[Technology Mapping]
    TM --> PK[Packing]
    PK --> PL[Placement]
    PL --> RT[Routing]

    style LS fill:#4caf50
    style TM fill:#2196f3
    style PK fill:#ff9800
    style PL fill:#9c27b0
    style RT fill:#f44336
</pre>

]

---

### Toy Problem (1)

.mermaid[

<pre>
graph TD
    subgraph "Cells C"
        C1((C1))
        C2((C2))
        C3((C3))
    end
    subgraph "L Elements"
        L1[L1]
        L2[L2]
        L3[L3]
    end
    subgraph "F Elements"
        F1[F1]
        F2[F2]
        F3[F3]
    end
    C1 --> L1
    C1 --> F1
    C2 --> L2
    C2 --> F2
    C3 --> L3
    C3 --> F3

    style C1 fill:#2196f3
    style C2 fill:#2196f3
    style C3 fill:#2196f3
    style L1 fill:#ff9800
    style L2 fill:#ff9800
    style L3 fill:#ff9800
    style F1 fill:#4caf50
    style F2 fill:#4caf50
    style F3 fill:#4caf50
</pre>

]

Given:

- A netlist contains $n$ L's and $m$ F's.
- A grid of C's, each of them can pick exactly one L and one F.

---

### Problem Formulation

- Weighted bipartite matching
- Edge-weight models the importance, e.g.
- connectivity
- physical distance (repacking)

Choices:

- Exact solution using a network flow algorithm
- Approximate solution using greedy or primal-dual algorithm

---

### 📚 Example

```text
  F  F  F  F  F  F  o  o  o  o  o  o  o  o  o  o

  L  L  L  L  L  L  L  L  L  L  L  L  L  L  o  o
```

---

### Toy Problem (2)

.pull-left[
Given:

- A netlist contains $n$ L's, $m$ F's, and $p$ Q's.
- A grid of C's, each of them can pick exactly one L, one F, and one Q.

Possible solution:

- Two-stage approach: pack_toy1(Q, F) pack_toy1(QF, L)
]
.pull-right[
.mermaid[

<pre>
graph LR
    subgraph "Stage 1"
        Q1[Q] --> QF1[QF]
        F1[F] --> QF1
        Q2[Q] --> QF2[QF]
        F2[F] --> QF2
    end
    subgraph "Stage 2"
        QF1 --> C1[Cell]
        L1[L] --> C1
        QF2 --> C2[Cell]
        L2[L] --> C2
    end

    style Q1 fill:#ff9800
    style Q2 fill:#ff9800
    style F1 fill:#4caf50
    style F2 fill:#4caf50
    style L1 fill:#9c27b0
    style L2 fill:#9c27b0
    style QF1 fill:#2196f3
    style QF2 fill:#2196f3
    style C1 fill:#f44336
    style C2 fill:#f44336
</pre>

]
]

---

### Toy Problem (3)

Given:

- A netlist contains $n$ L's and $m$ F's.
- A grid of C's, each of them can pick exactly **two** L's and one F.

Possible solution:

- Two-stage approach: pack_toy1(F, L) pack_toy1(L, FL)

---

### 📚 Example

Step 1

```text
  F  F  F  F  F  F

  L  L  L  L  L  L  L  L  L  L  L  L  L  L
```

Step 2

```text
  FL  FL  FL  FL  FL  FL  o   o

  L   L   L   L   L   L   L   L
```

---

### Specialized C?

.mermaid[

<pre>
graph LR
    subgraph "Cell Types"
        C1["Cell Type 1\n L1 + F"]
        C2["Cell Type 2\n L2 + F"]
    end
    subgraph "Elements"
        L1[L1]
        L2[L2]
        F[F]
    end
    C1 --> L1
    C1 --> F
    C2 --> L2
    C2 --> F

    style C1 fill:#2196f3
    style C2 fill:#4caf50
    style L1 fill:#ff9800
    style L2 fill:#9c27b0
    style F fill:#f44336
</pre>

]

- What if there are two kinds of C's

- e.g. C1 = [L1, F], C2 = [L2, F]

- Set Cover problem?

---

class: nord-dark, middle, center

## Q&A️ 🎤
