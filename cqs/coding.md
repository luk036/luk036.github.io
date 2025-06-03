layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# **Finding Difference Covers** 🔍🧩✨

@luk036 👨‍💻

2025-06-03 📅

---

## Overview

*   Exploring Two Approaches:
    *   **Recursive Search** (diff_cover.cpp) 🔄🌲
    *   **Reinforcement Learning** (RL Implementation) 🤖🧠🎯

---

## What is a Difference Cover? 🤔🔢

*   It's a **mathematical arrangement** or a set of numbers with a unique property.
*   Think of it as finding a **special combination of numbers** where their spacing creates an optimal pattern. 🎯
*   Specifically, for numbers 0 to N-1, you need to pick D numbers.
*   The goal: When you look at all the **differences between any two picked numbers**, those differences cover a wide range of values (in the RL context: cover every possible remainder when divided by N).
*   These structures have **applications** in areas like coding theory, cryptography, and signal processing. 📡🔐💡

---

## Approach 1: Recursive Search (diff_cover.cpp) 🌲🔄⚙️

*   **Purpose:** Designed to find these special mathematical arrangements (difference covers or sets). It acts as a **puzzle solver**. 🧩
*   **How it works:** Uses a sophisticated **recursive search algorithm** combined with **parallel processing**.
*   The core logic is in the `DcGenerator` class.
*   It follows a **generate-and-test approach** with intelligent pruning. ✂️

---

## Recursive Search: The Process 📈🚫🔙🔄

*   Builds potential solutions **incrementally**, adding one number at a time. ➕
*   For each new number, it **calculates differences** between it and previously selected numbers. ➖
*   It maintains arrays to **track seen differences** and counts unique ones. 🎯
*   **Optimization:** Before exploring deeper, it checks if there are **enough unique differences** to potentially reach a valid solution; if not, it **abandons that path early** (pruning). ✂️
*   Uses **backtracking**: When a dead end is reached, it backs up and tries different choices. ↩️
*   The `step_forward` and `step_backward` functions manage updating/reverting difference counts during exploration and backtracking. 🔄

---

## Recursive Search: Speeding it Up ⚡️🤝🚀

*   To speed up computation, the program uses **parallel processing** through a **thread pool**.
*   It **divides the work** by having different threads start their searches from different initial values.
*   This allows **multiple CPU cores** to work simultaneously. 💻💻💻
*   The program coordinates these parallel workers and displays progress. 📊

---

## Recursive Search: Input, Output & Constraints ➡️🔢✅📜

*   **Input:** Takes two **command-line arguments**:
    *   **N:** The total range of numbers to work with (0 to N-1).
    *   **D:** How many numbers to include in each set.
*   **Constraints:** The program validates that:
    *   N is **at least 3**.
    *   D is **at least 3**.
    *   N doesn't exceed **D\*(D-1)+1**.
*   **Output:**
    *   Prints **valid difference covers** found as rows of numbers.
    *   Displays **progress information** (worker threads, work remaining). 📊

---

## Output: Example 📊🔢📝

```
130:  47  51  59  61  72  85  90  91 100 107 124 127 130
131:  56  58  70  77  85  88  97 105 108 121 125 130 131
132:  66  69  72  76  80  84  88  92  96 101 129 130 131 132
133:  48  57  58  65  78  90  93 104 109 127 131 133
134:  67  69  73  76  82  92 102 112 122 126 129 130 133 134
135:  68  71  72  76  79  89  99 109 119 121 128 133 134 135
136:  68  71  73  77  80  90 100 110 120 121 128 134 135 136
137:  69  72  74  78  81  91 101 111 121 122 129 135 136 137
138:  65  69  76  83  93 103 113 123 126 129 132 134 135 138
139:  65  72  73  79  80  90 100 110 120 123 132 134 136 139
140:  62  67  79  83  87  91  98 105 111 128 137 138 139 140
141:  68  75  79  86  96 106 116 126 129 132 135 138 140 141
142:  63  66  80  82  84  92  95 104 107 134 135 140 141 142
143:  57  72  77  78  91  95  99 103 107 131 133 140 142 143
144:  56  66  67  69  76  84  98 106 114 118 120 139 141 144
145:  59  68  69  79  86  90  94  98 102 126 139 140 142 145
146:  59  66  71  79  80  90  93  99 103 128 129 144 145 146
147:  64  66  78  85  93  96 104 113 121 124 137 141 146 147
148:  56  61  62  80  88  95 106 110 112 126 135 138 147 148
149:  56  61  63  77  90 101 107 113 116 126 136 144 148 149
150:  51  63  66  69  70  96  98 106 111 119 128 130 144 150
```

---

## Approach 2: Reinforcement Learning (RL Implementation) 🤖🧠🎮

*   **Purpose:** Uses **artificial intelligence** to solve the difference cover problem.
*   Think of it like **teaching a computer to play a strategic game** where it needs to pick the right numbers to win. 🏆
*   Uses a technique called **"reinforcement learning"**. This is like learning through trial and error, getting better over time by trying different strategies. 🔄🎯

---

## RL: The AI Brain - Policy Network 🧠💡🤖

*   At the heart is an artificial "brain" called a **PolicyNetwork**.
*   This brain has **three layers of artificial neurons** that process information.
*   **Layers:**
    *   **First layer:** Receives information about the current puzzle state.
    *   **Middle layers (Hidden):** Process this information.
    *   **Final layer (Output):** Decides which number to pick next.
*   The brain **starts with random decision-making** but learns and improves by remembering what worked well.
*   Uses techniques like **Xavier initialization** for weights and **ReLU activation** for hidden layers. ⚙️

---

## RL: The Learning Process 🎮🎯🏆

The program plays the "difference cover game" thousands of times. In each game:

1.  **State Representation:** The AI looks at the current situation (numbers picked, differences covered). This state is converted into a **state vector**.
2.  **Decision Making:** The neural network calculates **probabilities** for picking each *remaining* number; promising numbers get higher probabilities. 🎲
3.  **Action Selection:** The AI **randomly selects a number** based on these probabilities to explore different strategies.
4.  **Reward Calculation:** After picking, the AI gets a **"reward"** based on how many **new mathematical differences** the choice covers. More coverage = better reward. 💰
5.  **Learning:** After a game, the AI analyzes results. If a solution was found or moves led to good rewards, the network **adjusts its internal parameters** to make similar decisions more likely in the future. This involves calculating **gradients**. 📉📈

---

## RL: Speeding it Up 🏎️🤝🚀

*   To make the learning process faster, the program runs **multiple "worker threads" simultaneously**.
*   This is like having several AI agents all trying to solve the puzzle at the same time. 🤖🤖🤖
*   Crucially, they **share the same "brain"** (PolicyNetwork) and **learn from each other's experiences**.
*   This parallel approach **speeds up the discovery process** significantly. ⚡️

---

## RL: Key Data & Processes 📊🔄🔬

*   **State Transformation:** The mathematical problem state is converted into a numerical **state vector** (combining info about chosen numbers and covered differences) for the neural network.
*   **Decision Output:** The neural network processes the state vector and outputs **logits**, which are converted into **probabilities** for each possible next move using the **Softmax** function. Already chosen numbers are masked. 🎭
*   **Learning Mechanism:** The network learns by adjusting its internal weights and biases (`W1`, `b1`, etc.). This is done using **gradients** calculated from the game outcomes and **discounted returns** (accounting for future rewards). Updates are thread-safe using a mutex. 🔒

---

## RL: Input, Output & Constraints ➡️🔢✅📜

*   **Input:** Takes two **command-line arguments**:
    *   **N:** The total range of numbers to choose from (0 to N-1).
    *   **D:** How many numbers you're allowed to pick.
*   **Constraints:** The program validates that:
    *   N is **at least 3**.
    *   D is **at least 3**.
    *   N doesn't exceed **D\*(D-1)+1**.
*   **Output:**
    *   If a solution is found, it prints the **specific numbers** that form a valid difference cover.
    *   If no solution is found after trying many times (up to MAX_EPISODES), it **reports that**. ❌

---

## Output: Example 📊🔢📝

```
151:   0   3   7  34  48  59  60  80  82 103 121 122 126 132 134 141 150
152:   0   4   7  10  61  62  69  80  81  99 102 116 118 125 128 130 141
153:   0   1   5   6  12  40  60  62  80  88  95  98 109 112 128 131 140
154:   0  16  21  27  31  40  48  62  73  77  98 116 125 127 128 141 147
155:   0   6  24  40  41  53  64  80  83 101 115 120 126 131 146 151 153
156:   0  10  22  39  72  81  88  90 102 105 109 116 141 143 146 147 148
157:   0   2  14  15  19  30  52  67 102 103 109 110 112 132 133 153 155
158:   0  12  16  23  29  33  34  37  60  69  79  84  99 110 112 117 138
159:   0  25  53  58  65  77  80  84  97  98 100 106 108 118 147 148 154
```

---

## Comparing the Approaches ⚖️🛠️

*   **Recursive Search:**
    *   **Systematic:** Explores combinations in a structured way.
    *   **Guaranteed:** Will find solutions within the defined search space if they exist (and if search is exhaustive).
    *   Relies on explicit pruning rules derived from mathematical properties.
*   **Reinforcement Learning:**
    *   **Learned:** Develops a strategy through experience.
    *   **Not Guaranteed:** May not find a solution within the episode limit. Learns to find *a* solution, not necessarily all.
    *   Relies on the AI "discovering" good strategies based on reward signals.
*   **Both:** Utilize **parallel processing** (thread pools/worker threads) to significantly speed up their respective processes. ⚡️

**GitHub** 🐙: [cyclic_quorum](https://github.com/luk036/cyclic_quorum) 🔗

---

count: false
class: nord-dark, middle, center

# Q & A 🎤
