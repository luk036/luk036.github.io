# Reinforcement Learning 🤖

@luk036 👨‍💻

2025-05-16 📅

---

### Example Diagram

<div class="mermaid">
graph TD
    A[Start] --> B{Decision}
    B -->|Yes| C[Do Something]
    B -->|No| D[Do Something Else]
    C --> E[End]
    D --> E
</div>

---

### Introduction to Reinforcement Learning

*   Welcome! Today, we'll explore **Reinforcement Learning (RL)**. 👋
*   RL is fundamentally different from **supervised learning**. 🔄
*   In supervised learning, agents learn a mapping from inputs to outputs using *provided training data* with known input and output values. A "teacher" or database defines the desired mapping. 🎓
*   In RL, the situation is more difficult because **no such training data is available**. ❌📊

<div class="mermaid">
pie
    title Learning Types Comparison
    "Supervised Learning" : 45
    "Unsupervised Learning" : 30
    "Reinforcement Learning" : 25
</div>

---

### What is Reinforcement Learning?

*   The agent learns through **trial and error (or success)** which actions are good in a certain situation. 🔄🎯
*   It learns through **reinforcement**. 💪
*   Successful attempts are **rewarded**. 🏆
*   Unsuccessful attempts are **penalized**. ❌
*   This is similar to how humans learn, e.g., a child learning to walk or learning in sports. 👶🚶‍♂️⚽
*   Positive and negative reinforcement are key factors. ➕➖

<div class="mermaid">
graph LR
    A[Agent] -->|Action| B[Environment]
    B -->|Reward| A
    B -->|New State| A
    style A fill:#f9f,stroke:#333
    style B fill:#bbf,stroke:#333
</div>

---

### RL vs. Supervised Learning Summary

*   **Supervised Learning:**
    *   Mapping inputs to outputs. ↔️
    *   Requires *complete training data* (input + desired output). 📂
    *   Goal: Approximate the mapping and generalize. 🎯
*   **Reinforcement Learning:**
    *   Finding good actions in a situation. 🕵️‍♂️
    *   *No training data* is initially available. ❌📊
    *   Learns through *interaction* and *feedback* (rewards/penalties). 🔄💬
    *   Goal: Learn a **policy** that maximizes long-term reward. 🏆📈

<div class="mermaid">
flowchart TB
    subgraph SL[Supervised Learning]
        A[Input] --> B[Model] --> C[Output]
        D[Label] --> B
    end
    subgraph RL[Reinforcement Learning]
        E[State] --> F[Agent] --> G[Action]
        H[Environment] -->|Reward| F
        H -->|New State| F
    end
    style SL fill:#f9f,stroke:#333
    style RL fill:#bbf,stroke:#333
</div>

---

### A Robotics Example 🤖🚶‍♂️

*   An illustrative example comes from robotics.
*   Consider a robot with a rectangular block body and an arm with two joints (gy and gx).
*   Actions are discrete movements of the joints (e.g., up/down for gy, right/left for gx). ⬆️⬇️⬅️➡️
*   The task is to learn a **policy** to move **as quickly as possible to the right**. 🚀➡️
*   This robot works analogously to a walking robot in the same two-dimensional state space.
*   Movements to the right are **rewarded** positively, movements to the left are **punished** negatively. ➕➖

<div class="mermaid">
stateDiagram-v2
    [*] --> State1
    State1 --> State2: Right (+1)
    State1 --> State3: Left (-1)
    State2 --> State4: Right (+1)
    State2 --> State1: Left (-1)
    State3 --> State1: Right (+1)
    State3 --> State5: Left (-1)
    style State1 fill:#f9f
    style State2 fill:#9f9
    style State3 fill:#f99
</div>

---

### Modeling the Task Mathematically 📐

*   The robot's **state** is described by the position of its two joints, (gx, gy). Each joint has a finite number of discrete values. 🔢
*   The state is encoded as a vector (gx, gy).
*   The number of possible positions for gx is nx, and for gy is ny.
*   The **evaluation** of actions is based on the robot's horizontal ↔️ position. Positive changes to x (movement right) are rewarded, negative changes (movement left) are penalized. ➕➖
*   Figure 10.3 shows state spaces for 2x2 and 4x4 joint positions.

<div class="mermaid">
graph TD
    A[State Space] --> B[gx]
    A --> C[gy]
    B --> D[Position 1]
    B --> E[Position 2]
    C --> F[Position A]
    C --> G[Position B]
    style A fill:#f9f,stroke:#333
</div>

---

### Agent and Environment 🌍

*   We distinguish between the **agent** and its **environment**. 🤖🌿
*   At time t, the world (agent + environment) is in a **state** st ∈ S. ⏱️
*   S is an abstraction; the agent may have incomplete information due to measurement errors.
*   The agent performs an **action** at ∈ A at time t. ⚡
*   This action changes the world, resulting in state st+1 at time t+1. 🔄
*   The state transition is determined by the environment's function δ: st+1 = δ(st, at). This is outside the agent's influence. 🌐

<div class="mermaid">
sequenceDiagram
    participant Agent
    participant Environment
    Agent->>Environment: Action a_t
    Environment->>Agent: Reward r_t
    Environment->>Agent: New State s_t+1
    Note right of Environment: δ(s_t, a_t) = s_t+1
</div>

---

### Reward and Policy ⭐🗺️

*   After executing action at, the agent receives an **immediate reward** rt = r(st, at). 💰
*   The immediate reward depends on the current state st and executed action at.
*   rt > 0 means positive reinforcement; rt < 0 means negative reinforcement for action at in state st. rt = 0 means no immediate feedback. ➕➖🚫
*   A **policy π : S → A** is a mapping from states to actions. It tells the agent what action to take in each state. 🗺️
*   The **goal of RL** is for the agent to learn an **optimal policy** based on its experiences. 🏆

<div class="mermaid">
flowchart LR
    S1[State 1] -->|"π(S1)=A1"| A1[Action 1]
    S1 -->|"π(S1)=A2"| A2[Action 2]
    S2[State 2] -->|"π(S2)=A1"| A1
    S2 -->|"π(S2)=A3"| A3[Action 3]
    style S1 fill:#f9f
    style S2 fill:#bbf
</div>

---

### Maximizing Reward (Value Function) 📈

*   An optimal policy maximizes reward **in the long run**, over many steps. ⏳
*   We define the **value** or **discounted reward** V π(st) of a policy π starting in state st:
    *   V π(st) = rt + γrt+1 + γ²rt+2 + ... = ∑ γ^i * rt+i
    *   Here, **0 ≤ γ < 1** is a discount factor.
    *   **γ** ensures future rewards are discounted; immediate reward is weighted strongest. ⚖️
*   An alternative is the **average reward** (though discounted is more common).

<div class="mermaid">
pie
    title Reward Discounting (γ = 0.9)
    "Immediate Reward (r_t)" : 100
    "Next Step (γr_t+1)" : 90
    "Two Steps (γ²r_t+2)" : 81
    "Three Steps (γ³r_t+3)" : 73
</div>

---

### Optimal Policy and Markov Decision Processes (MDP) ✨

*   A policy π is **optimal** if V π(s) ≥ V π(s) for all states s. It's at least as good as all other policies. 🏆
*   The optimal value function is denoted V.
*   The agents discussed typically use only information about the **current state st** to determine the next action, not prior history. ⏱️
*   This is justified if reward depends only on the current state and action.
*   Processes with this property are called **Markov decision processes (MDP)**. 🔄
*   If the agent's actual state is not exactly known (e.g., due to noisy sensors), it's a **partially observable Markov decision process (POMDP)**. ❓

<div class="mermaid">
stateDiagram-v2
    [*] --> S0
    S0 --> S1: Action A
    S0 --> S2: Action B
    S1 --> S3: Action C
    S1 --> S4: Action D
    S2 --> S5: Action E
    note left of S0: Markov Property:\nNext state depends\nonly on current\nstate and action
</div>

---

### Solving RL: Combinatorial Search? 🤔

*   The simplest approach to finding a successful policy is **combinatorial enumeration of all policies**. 🔍
*   However, even in the simple robot example (Example 10.1), there are **very many policies**.
*   The number of policies grows **exponentially** with the number of states if there's more than one possible action per state. 📈
*   This makes combinatorial search associated with **extremely high computational cost** and impractical for practical applications. ⏳💻
*   Heuristic search is also difficult because immediate reward is often zero and cannot serve as a heuristic. ❌

<div class="mermaid">
graph TD
    A[Start] --> B[Policy 1]
    A --> C[Policy 2]
    A --> D[Policy 3]
    B --> E[Sub-policy 1]
    B --> F[Sub-policy 2]
    C --> G[Sub-policy 3]
    C --> H[Sub-policy 4]
    D --> I[Sub-policy 5]
    D --> J[Sub-policy 6]
    style A fill:#f9f
    note[Combinatorial Explosion!]:::noteclass
    classDef noteclass fill:#fff,stroke:#f66,stroke-width:4px
</div>

---

### Solving RL: Value Iteration (Dynamic Programming) 🧠

*   The naive approach performs redundant work; many policies are similar. 🔄
*   This suggests saving intermediate results for parts of policies and reusing them. 💾
*   This is the approach of **dynamic programming**, introduced by Richard Bellman.
*   Bellman's principle: For an optimal policy, **all subsequent decisions must be optimal**, independent of the starting state and first action. 🏆
*   This principle allows finding a globally optimal policy through **local optimization** of individual actions. �

<div class="mermaid">
flowchart TB
    subgraph DP[Dynamic Programming]
        A[Problem] --> B[Subproblem 1]
        A --> C[Subproblem 2]
        B --> D[Solution 1]
        C --> E[Solution 2]
        D --> F[Final Solution]
        E --> F
    end
    style DP fill:#bbf,stroke:#333
</div>

---

### The Bellman Equation for V 📜

*   We want an optimal policy π that satisfies the optimal value definition.
*   This leads to a recursive characterization of the optimal value function V:
    *   **V(s) = max_a [r(s, a) + γV(δ(s, a))]**
*   This is the **Bellman equation**.
*   It means that to calculate V(s), you add the immediate reward r(s, a) to the discounted optimal value of the successor state V(δ(s, a)) for the *best possible action* 'a' in state 's'. ➕💰

<div class="mermaid">
graph LR
    S[Current State] -->|max| A[Actions]
    A -->|a1| R1[Reward + γV(s1)]
    A -->|a2| R2[Reward + γV(s2)]
    A -->|a3| R3[Reward + γV(s3)]
    style S fill:#f9f
    style A fill:#bbf
</div>

---

### Value Iteration Algorithm ⚙️

*   The Bellman equation (10.6) leads to an iteration rule for approximating V:
    *   **V̂(s) = max_a [r(s, a) + γV̂(δ(s, a))]**
*   **Algorithm:**
    1.  Initialize approximate values V̂(s) for all states (e.g., to zero). 🏁
    2.  Repeatedly update V̂(s) for each state using the iteration rule, relying on the V̂ values of successor states. 🔄
*   This process is called **value iteration**.
*   Value iteration **converges to V**. ✅
*   Figure 10.7 shows the schematic algorithm.

<div class="mermaid">
flowchart TD
    A["Initialize V(s) = 0 ∀s"] --> B["Update V(s) for all s"]
    B --> C{Converged?}
    C -->|No| B
    C -->|Yes| D[Output Optimal V]
    style A fill:#f9f
    style D fill:#9f9
</div>

---

### Value Iteration Example ✨

*   Figure 10.8 shows value iteration applied to the robot example with γ = 0.9 and 3x3 states.
*   The sequence shows the progression of learning. 📈
*   The agent explores states, performs value iteration, and saves the policy via a tabulated V function.
*   To find the optimal action π(s) from V, you use:
    *   **π(s) = argmax_a [r(s, a) + γV(δ(s, a))]**
    *   You **must** add the immediate reward r(s, a), not just choose the action leading to the state with maximum V value. 💰
*   Value iteration requires a **model of the environment** (knowing r and δ functions). 🌐

<div class="mermaid">
gantt
    title Value Iteration Progression
    dateFormat  X
    axisFormat %s
    Iteration 1 : 0, 1
    Iteration 2 : 1, 2
    Iteration 3 : 2, 3
    Convergence : 3, 5
    style Iteration 1 fill:#f9f
    style Iteration 2 fill:#bbf
    style Iteration 3 fill:#9f9
    style Convergence fill:#0f0
</div>

---

### Robot Simulation & Real Robots 🤖🖥️

*   Simulators can be used to experiment with reinforcement learning.
*   A walking robot simulator allows observing learning, manually supplying feedback, and setting parameters. 🎮
*   Real crawling robots were also developed for teaching.
*   Learning can happen in simulation (faster) and then be transferred to the robot, or the robot can learn autonomously. 🔄
*   A 5x5 state space takes about 30s to learn autonomously on the real robot. ⏱️
*   **Differences exist between simulation and real robots**.
*   Real robots perceive subtle environmental effects (like grip on surface) through sensors, leading to different, often more efficient, learned policies. 🌍
*   Real robots can show **adaptivity**, learning despite defects or changing environments. 🔧

<div class="mermaid">
graph LR
    A[Simulation] -->|Fast Training| B[Policy]
    C[Real Robot] -->|Adaptive Learning| B
    B --> D[Improved Performance]
    style A fill:#bbf
    style C fill:#f9f
    style D fill:#9f9
</div>

---

### Q-Learning: Model-Free RL 🌱

*   What if the agent **doesn't have a model** of the world (doesn't know r and δ)? ❓
*   This is common in robotics; a robot might not know the exact outcome of an action.
*   We need to evaluate an action *without* knowing the successor state.
*   We use an evaluation function **Q(s, a)** for state-action pairs.
*   The optimal action in state 's' is chosen by **π(s) = argmax_a Q(s, a)** for an optimal function Q. 🏆

<div class="mermaid">
flowchart LR
    S[State] -->|a1| Q1[Q(s,a1)]
    S -->|a2| Q2[Q(s,a2)]
    S -->|a3| Q3[Q(s,a3)]
    Q1 --> M[Max Q]
    Q2 --> M
    Q3 --> M
    M --> A[Best Action]
    style S fill:#f9f
    style M fill:#9f9
</div>

---

### The Q-Function and Bellman Equation for Q 🧮

*   Similar to V, the value of action 'a' in state 's' is defined using discounted future rewards:
    *   **Q(st, at) = r(st, at) + γrt+1 + γ²rt+2 + ...**
*   The optimal Q function, Q, is defined recursively:
    *   **Q(s, a) = r(s, a) + γ max_a′ Q(δ(s, a), a′)**
*   This looks similar to the Bellman equation for V, but the key advantage is that Q directly evaluates state-action pairs.
*   Knowing Q allows the agent to choose actions **without a model** of δ and r, simply by picking the action with the highest Q value in the current state. 🏆

<div class="mermaid">
graph TD
    A[Current State] --> B[Action 1]
    A --> C[Action 2]
    A --> D[Action 3]
    B --> E[Q(s,a1) = r + γmaxQ(s')]
    C --> F[Q(s,a2) = r + γmaxQ(s')]
    D --> G[Q(s,a3) = r + γmaxQ(s')]
    style A fill:#f9f
    style E fill:#bbf
    style F fill:#bbf
    style G fill:#bbf
</div>

---

### Q-Learning Algorithm 🔄

*   An iterative algorithm for determining Q(s, a) is derived from its recursive form.
*   **Q̂(s, a) = r(s, a) + γ max_a′ Q̂(δ(s, a), a′)**
*   **Algorithm:**
    1.  Initialize a table Q̂(s, a) for all state-action pairs (e.g., with zeroes). 🏁
    2.  Let the agent execute action 'a' in state 's' in the environment.
    3.  Observe the successor state s' = δ(s, a) and the immediate reward r(s, a) from the environment. 👀
    4.  Update Q̂(s, a) using the observed r and the *current* Q̂ value of the best action in the successor state s'. 🔄
*   Figure 10.11 shows the schematic algorithm.

<div class="mermaid">
flowchart TD
    A[Initialize Q-table] --> B[Choose Action]
    B --> C[Execute Action]
    C --> D[Observe Reward and s']
    D --> E[Update Q(s,a)]
    E --> F{Converged?}
    F -->|No| B
    F -->|Yes| G[Optimal Q]
    style A fill:#f9f
    style G fill:#9f9
</div>

---

### Q-Learning Convergence (Deterministic) ✅

*   Theorem 10.1 states that for a **deterministic MDP** with bounded reward and 0 ≤ γ < 1, Q̂n(s, a) **converges to Q(s, a)** for all s and a as n → ∞.
*   This convergence is guaranteed **if each state-action pair is visited infinitely often**. 🔄
*   The proof shows that the maximum error in the Q̂ table is reduced by at least the factor γ in intervals where all state-action transitions occur at least once.
*   Thus, the error converges to zero.
*   Convergence is independent of the specific actions chosen *during learning*, as long as they are all visited infinitely often. The *speed* of convergence *does* depend on the paths taken. ⏱️

<div class="mermaid">
graph LR
    A[Initial Q] --> B[Update 1]
    B --> C[Update 2]
    C --> D[Update 3]
    D --> E[Optimal Q]
    style A fill:#f9f
    style E fill:#9f9
    classDef conv fill:#0f0,stroke:#333;
    class E conv
</div>

---

### Q-Learning in Nondeterministic Environments 🎲

*   Many robotics environments are **nondeterministic**. An action in a state can lead to different successor states or rewards at different times.
*   A nondeterministic Markov process has probabilistic transition P(s'|s, a) and reward r(s, a).
*   Equation (10.16) is generalized by using the **expected value** over successor states:
    *   Q(s, a) = E(r(s, a)) + γ ∑ s′ P(s′|s, a) max_a′ Q(s′, a′)
*   Directly using (10.17) in a nondeterministic environment does **not guarantee convergence**. Successive runs might give different rewards/successor states, causing values to jump. ❌

<div class="mermaid">
stateDiagram-v2
    [*] --> S
    S --> S1: Action A (70%)
    S --> S2: Action A (30%)
    note left of S: Nondeterministic Transition
    style S fill:#f9f
</div>

---

### Stabilized Q-Learning (TD-Learning)

*   To stabilize Q values in nondeterministic environments, the iteration rule adds the old Q value, weighted by (1 - αn).
*   The learning rule becomes:
    *   **Q̂n(s, a) = (1 − αn)Q̂n−1(s, a) + αn [ r(s, a) + γ max_a′ Q̂n−1(δ(s, a), a′) ]**
*   Here, αn is a time-varying weighting factor, e.g., αn = 1 / (1 + bn(s, a)), where bn(s, a) is how often action 'a' was executed in state 's'.
*   This stabilizes iteration, preventing excessive jumps in Q̂ values, especially later in learning when bn is large.
*   This equation can be rewritten as:
    *   Q̂n(s, a) = Q̂n−1(s, a) + α [ TD-error ]
*   The term [ r(s, a) + γ max_a′ Q̂n−1(δ(s, a), a′) − Q̂n−1(s, a) ] is the **TD-error** (temporal difference error).
*   This update rule is a special case of **TD-Learning**. α=1 is the basic Q-learning; α=0 means no learning. 🔄

<div class="mermaid">
flowchart LR
    A[Old Q] -->|1-α| B[New Q]
    C[TD Target] -->|α| B
    style A fill:#f9f
    style C fill:#bbf
    style B fill:#9f9
</div>

---

### Exploration vs. Exploitation 🧭💰

*   How should the agent choose actions during learning?
*   **Possibility 1: Exploration**
    *   Choose actions randomly. 🎲
    *   Results in uniform exploration of possibilities.
    *   **Slow convergence**. Guarantees visiting all state-action pairs infinitely often (required for convergence). ⏳
*   **Possibility 2: Exploitation**
    *   Always choose the action with the highest *current* Q̂ value. 🏆
    *   Results in relatively **fast convergence of a specific trajectory**.
    *   Other paths may remain unvisited, potentially leading to **non-optimal policies**. ❌
*   **Recommendation:** Use a **combination**, with high exploration initially, gradually reducing it over time. 🔄

<div class="mermaid">
pie
    title Exploration vs Exploitation
    "Exploration (Early)" : 70
    "Exploitation (Late)" : 30
</div>

---

### Approximation and Generalization 🧠✨

*   Q-learning (and value iteration) as described use tables to store Q or V values. This only works for **finite, discrete state-action spaces**.
*   If the state space is **infinite** (e.g., continuous variables), tables are impossible, and visiting all pairs is impossible.
*   Solution: Replace the Q(s, a) table with a **function approximator**.
*   A **neural network** (e.g., backpropagation network) is a common choice. Input is (s, a), target output is the Q value. 🧠
*   Training examples update the network. Since there are finitely many examples for infinitely many inputs, this provides **generalization**.
*   Other approximators like SVMs or Gaussian processes can also be used.

<div class="mermaid">
flowchart LR
    S[State] --> NN[Neural Network]
    A[Action] --> NN
    NN --> Q[Q-Value]
    style NN fill:#f9f,stroke:#333
</div>

---

### Challenges with Function Approximation & POMDPs 🚧

*   Q-learning with function approximation might **not converge**, as Theorem 10.1 requires visiting all state-action pairs infinitely often (which is impossible with continuous spaces). ❌
*   Convergence problems can also occur with **POMDPs** (Partially Observable MDPs).
*   In a POMDP, the agent perceives multiple states as one due to noisy sensors or intentional mapping to 'observations'.
*   This mapping can reduce state space and prevent overfitting, but the agent cannot differentiate actual states within an observation.
*   An action in an observation might lead to different successor states depending on the true underlying state, causing convergence issues for value iteration or Q-learning.

<div class="mermaid">
stateDiagram-v2
    [*] --> S1
    [*] --> S2
    S1 --> O: Observation
    S2 --> O
    O --> A[Action]
    note left of O: POMDP Multiple states<br/>map to same observation
    style O fill:#f9f
</div>

---

### Alternative Approaches: Policy Improvement 💪

*   **Policy improvement methods** and **policy gradient methods** are alternative approaches.
*   Instead of learning values (V or Q), they directly **change the policy**.
*   The goal is to find a policy in the space of all policies that maximizes the cumulative discounted reward (Eq. 10.1).
*   One way is to follow the **gradient of the cumulative reward** to a maximum. 📈
*   This can significantly **speed up learning** in applications with large state spaces, like humanoid robots.

<div class="mermaid">
graph TD
    A[Random Policy] --> B[Evaluate]
    B --> C[Improve]
    C --> D[Better Policy]
    D --> B
    style A fill:#f9f
    style D fill:#9f9
</div>

---

### Applications of Reinforcement Learning 🎮⚽✈️🚗

*   RL has demonstrated practical utility many times.
*   **TD-Gammon:** A backgammon program using TD-learning and a neural network. Trained against itself, it defeated world-class players. ♟️🏆
*   **Robotics:** Used successfully in RoboCup Soccer Simulation League. Balancing a pole. 🤖⚽
*   **Model Airplane Landing:** A model airplane learned to land precisely, handling turbulent air currents (which are hard to model mathematically). As the quote says, "Birds don't solve Navier–Stokes!" ✈️🐦
*   **Car Control:** Learning to control a real car in 20 minutes using Q-learning and function approximation. Applicable to real industrial tasks with few measurements. 🚗
*   **Challenges in Real Robots:** Learning is slower than in simulation due to real-world feedback speed. Millions of training cycles are time-consuming. Need methods for offline learning. ⏳

<div class="mermaid">
pie
    title RL Applications
    "Games" : 35
    "Robotics" : 30
    "Control Systems" : 20
    "Other" : 15
</div>

---

### AlphaGo: A Breakthrough in Go ♟️🤯

*   Go has a huge branching factor, making traditional search methods difficult.
*   **AlphaGo (Google DeepMind)** achieved a breakthrough.
*   It combines **Monte Carlo Tree Search (MCTS)** for generating data, **deep learning** for evaluating positions, and **reinforcement learning** for strategy improvement.
*   Learning goal: Learn a **policy p(a|s)** calculating the probability of winning for each move 'a' in position 's'. The best move is argmax_a p(a|s).
*   **Stage 1: Deep Learning** based on expert games (KGS Go Server). A CNN learns pσ(a|s), predicting expert moves. It predicted expert moves up to 57% of the time. A simpler rollout policy pπ(a|s) was also trained.

<div class="mermaid">
flowchart TD
    A[Expert Games] --> B[Supervised Learning]
    B --> C[Policy Network]
    style A fill:#f9f
    style C fill:#9f9
</div>

---

### AlphaGo: Stages 2 & 3 and Final Play 🏆

*   **Stage 2: Reinforcement Learning** to improve the policy pσ(a|s). AlphaGo plays against itself; the policy pρ(a|s) is improved using stochastic gradient descent. Plays against earlier versions to avoid overfitting.
*   **Stage 3: Learning Value Function**. The policy pρ(a|s) trains a board state evaluation function V(s) using value iteration.
*   **Final Play:** Uses a complex **MCTS algorithm**. Tree is expanded from the current position. Games are played to the end from leaf nodes using the fast rollout policy pπ(a|s). Position is evaluated using the game outcome + value function V(s).
*   Required massive computation (1202 CPUs, 176 GPUs) to defeat Lee Sedol.
*   AlphaGo was a major milestone, enabled by deep learning, RL, and engineering effort.

<div class="mermaid">
flowchart TD
    A[Self-Play] --> B[RL Improvement]
    B --> C[Value Network]
    C --> D[MCTS]
    D --> E[Move Selection]
    style A fill:#f9f
    style E fill:#9f9
</div>

---

### AlphaGoZero: Learning from Scratch 🚀

*   **AlphaGoZero** learns Go completely **independently**, without human knowledge or expert games.
*   It learns by playing against itself.
*   Uses deep learning, reinforcement learning, and MCTS.
*   A single deep network outputs both move probabilities and win probability.
*   This network is trained using a new RL algorithm performing MCTS searches in games against itself to improve move probabilities. Chosen moves become stronger over time.

<div class="mermaid">
graph LR
    A[Random Play] --> B[Self-Improvement]
    B --> C[Strong Policy]
    style A fill:#f9f
    style C fill:#9f9
</div>

---

### The Curse of Dimensionality

*   RL remains challenging, especially for **high-dimensional state and action spaces**.
*   The huge computation time needed is known as the **"curse of dimensionality"**.
*   How to address this? Look to nature. 🌿
*   Learning in nature happens on **multiple levels of abstraction** (hierarchical learning). Learned skills are encapsulated and used as higher-level actions, reducing the action space. States can also be abstracted.

<div class="mermaid">
graph TD
    A[High Dimension Problem] --> B[Abstraction]
    B --> C[Lower Dimension]
    C --> D[Faster Learning]
    style A fill:#f9f
    style D fill:#9f9
</div>

---

### Overcoming the Curse: Modular & Initial Policies 🧩🗺️

*   **Distributed Learning / Multi-Agent Learning:** Complex control tasks (like a robot with many motors) can be broken down. Individual parts (e.g., each motor) get individual control, ideally independent of others, reducing complexity. Seen in insects (millipede legs).
*   **Starting with a Good Initial Policy:** The task is easier if the agent starts with a somewhat good policy.
    *   **Classical Programming:** Programmer provides an initial policy (a program). The agent follows this, leading it to "interesting" state-action areas, dramatically reducing the search space.
    *   **Demonstration Learning:** A human "proscribes" (teaches) the actions, e.g., via remote control. The robot saves state-action pairs and generalizes using supervised learning (backpropagation, decision trees). This provides an initial policy for subsequent RL.

<div class="mermaid">
flowchart TD
    A[Complex Task] --> B[Modular Decomposition]
    B --> C[Simpler Sub-tasks]
    C --> D[Combined Solution]
    style A fill:#f9f
    style D fill:#9f9
</div>

---

### Summary and Outlook ✨🔮

*   Established learning algorithms like Value Iteration and Q-Learning exist.
*   Training for complex RL applications is still demanding, requiring experimentation. Tools like the Teaching-Box can help by integrating various learning algorithms, traditional programming, and demonstration learning.
*   RL is an **active and fascinating research area** with growing use.
*   Scaling to **high-dimensional state and action spaces** remains a significant challenge (curse of dimensionality).
*   Impressive results are achieved for small state/action spaces, but tasks with many degrees of freedom (like humanoid robots) are still very expensive to learn.
*   Many variations and new algorithms exist beyond those presented.
*   Further reading: Mitchell [Mit97], Sutton and Barto [SB98], Kaelbling, Littman, and Moore [KLM96].

<div class="mermaid">
pie
    title RL Challenges
    "Dimensionality" : 40
    "Computational Cost" : 30
    "Convergence" : 20
    "Other" : 10
</div>
