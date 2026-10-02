# Alternating Minimization 🎯
### A Simple Yet Powerful Optimization Technique

---

## Slide 1: Title Slide

# Alternating Minimization 🔄

### From EM to Kalman Filters to Matrix Completion

**A 30-Minute Journey Through a Universal Optimization Pattern**

📅 Today's Agenda:
- 🧠 Core Concept
- 📊 EM Algorithm
- 🎛️ Kalman Filter
- 🧩 Low-Rank Matrix Completion
- 🔗 Nearest Correlation Matrix

---

## Slide 2: The Big Picture 🗺️

## What is Alternating Minimization?

> **"When you can't solve a hard joint problem, solve easy conditional problems — one variable at a time."**

$$ \min_{x, y} \; f(x, y) \quad \longrightarrow \quad \begin{cases} x^{(t+1)} = \arg\min_x f(x, y^{(t)}) \\ y^{(t+1)} = \arg\min_y f(x^{(t+1)}, y) \end{cases} $$

✅ **Very common technique** across ML, signal processing, statistics

⚠️ **Simple, but could be slow** — convergence can be sublinear

---

## Slide 3: Why Does It Work? 🤔

## The Intuition

At each step, we **decrease** the objective:

$$ f(x^{(t+1)}, y^{(t+1)}) \leq f(x^{(t+1)}, y^{(t)}) \leq f(x^{(t)}, y^{(t)}) $$

🔑 **Key properties:**
- 🎯 Each subproblem is often **convex** and **closed-form**
- 📉 Monotonic decrease of objective
- 🧱 Block coordinate descent — a special case
- 🛑 Converges to stationary points (under mild conditions)

⚠️ **Caveats:**
- Can get stuck in local minima (non-convex case)
- Slow convergence (linear rate, often small steps)
- Sensitive to initialization

---

## Slide 4: The General Framework 🏗️

## Alternating Minimization Template

```
Initialize: x⁽⁰⁾, y⁽⁰⁾
for t = 0, 1, 2, ... do
    x⁽ᵗ⁺¹⁾ ← argmin_x  f(x, y⁽ᵗ⁾)     # Fix y, optimize x
    y⁽ᵗ⁺¹⁾ ← argmin_y  f(x⁽ᵗ⁺¹⁾, y)   # Fix x, optimize y
end for
```

🎨 **Variants:**
- 🧮 **Exact minimization** — closed-form solutions
- 📏 **Proximal variants** — add regularization
- 🎲 **Stochastic versions** — sample subsets
- ⚡ **Accelerated** — Nesterov-style momentum

---

## Slide 5: EM Algorithm — Overview 📈

## Expectation-Maximization (EM)

**Problem:** Maximum likelihood with **latent variables** $z$

$$ \theta^\star = \arg\max_\theta \; \log p(x \mid \theta) = \arg\max_\theta \; \log \sum_z p(x, z \mid \theta) $$

😱 The log of a sum is **hard** to optimize directly!

💡 **EM's trick:** Alternate between two steps
- **E-step:** Compute posterior over $z$ given current $\theta$
- **M-step:** Maximize expected complete-data log-likelihood

---

## Slide 6: EM — The Two Steps 🔁

## Expectation (E) Step

Compute the **Q-function**:

$$ Q(\theta \mid \theta^{(t)}) = \mathbb{E}_{z \sim p(z \mid x, \theta^{(t)})}\big[ \log p(x, z \mid \theta) \big] $$

🧮 This is the **expected** complete-data log-likelihood under the current posterior.

---

## Maximization (M) Step

Update parameters:

$$ \theta^{(t+1)} = \arg\max_\theta \; Q(\theta \mid \theta^{(t)}) $$

🎯 Often has a **closed-form solution** (e.g., Gaussian mixtures).

---

## Slide 7: EM — Why It Works ✅

## Guaranteed Monotonic Improvement

$$ \log p(x \mid \theta^{(t+1)}) \geq \log p(x \mid \theta^{(t)}) $$

**Proof sketch** via ELBO (Evidence Lower Bound):

$$ \log p(x \mid \theta) = \underbrace{\mathcal{L}(q, \theta)}_{\text{ELBO}} + \underbrace{\mathrm{KL}(q(z) \,\|\, p(z \mid x, \theta))}_{\geq 0} $$

- **E-step:** Set $q(z) = p(z \mid x, \theta^{(t)})$ → KL $= 0$, ELBO tight
- **M-step:** Maximize ELBO over $\theta$ → improves likelihood

📊 **Convergence:** to local maxima (or saddle points)

---

## Slide 8: EM — Classic Example 🎨

## Gaussian Mixture Model (GMM)

**Model:** $p(x) = \sum_{k=1}^K \pi_k \, \mathcal{N}(x \mid \mu_k, \Sigma_k)$

**E-step:** Responsibilities

$$ \gamma_{ik} = \frac{\pi_k \, \mathcal{N}(x_i \mid \mu_k, \Sigma_k)}{\sum_{j=1}^K \pi_j \, \mathcal{N}(x_i \mid \mu_j, \Sigma_j)} $$

**M-step:** Weighted updates

$$ \mu_k = \frac{\sum_i \gamma_{ik} x_i}{\sum_i \gamma_{ik}}, \quad \Sigma_k = \frac{\sum_i \gamma_{ik} (x_i - \mu_k)(x_i - \mu_k)^\top}{\sum_i \gamma_{ik}} $$

$$ \pi_k = \frac{1}{N} \sum_i \gamma_{ik} $$

---

## Slide 9: Kalman Filter — Overview 🎛️

## State Estimation in Dynamic Systems

**Linear Gaussian state-space model:**

$$ \begin{aligned} x_t &= F_t x_{t-1} + B_t u_t + w_t, & w_t &\sim \mathcal{N}(0, Q_t) \\ z_t &= H_t x_t + v_t, & v_t &\sim \mathcal{N}(0, R_t) \end{aligned} $$

🎯 **Goal:** Estimate hidden state $x_t$ from noisy observations $z_t$

💡 **Alternating structure:**
- **Prediction phase** — propagate belief forward
- **Update phase** — correct with new observation

---

## Slide 10: Kalman Filter — The Two Phases 🔁

## Prediction Phase (Time Update) ⏩

$$ \begin{aligned} \hat{x}_{t \mid t-1} &= F_t \hat{x}_{t-1 \mid t-1} + B_t u_t \\ P_{t \mid t-1} &= F_t P_{t-1 \mid t-1} F_t^\top + Q_t \end{aligned} $$

## Update Phase (Measurement Update) 🔄

$$ \begin{aligned} K_t &= P_{t \mid t-1} H_t^\top \big( H_t P_{t \mid t-1} H_t^\top + R_t \big)^{-1} \\ \hat{x}_{t \mid t} &= \hat{x}_{t \mid t-1} + K_t \big( z_t - H_t \hat{x}_{t \mid t-1} \big) \\ P_{t \mid t} &= (I - K_t H_t) P_{t \mid t-1} \end{aligned} $$

🔁 **Predict → Update → Predict → Update → ...**

---

## Slide 11: Kalman Filter — Interpretation 🧠

## Why Is This Alternating Minimization?

🎯 **MAP interpretation:** At each step, solve

$$ \hat{x}_t = \arg\min_x \; \underbrace{\|x - F_t \hat{x}_{t-1}\|^2_{Q_t^{-1}}}_{\text{prediction prior}} + \underbrace{\|z_t - H_t x\|^2_{R_t^{-1}}}_{\text{measurement likelihood}} $$

📐 **Geometric view:**
- **Prediction:** project belief forward through dynamics
- **Update:** project onto measurement constraint

🔗 **Connections:**
- 🧩 Special case of **Gaussian message passing** on factor graphs
- 🎓 Equivalent to **recursive least squares**
- 🚀 Extended/Unscented KF handle nonlinearities

---

## Slide 12: Low-Rank Matrix Completion — Overview 🧩

## The Netflix Problem 🎬

**Given:** Partial observations $M_{ij}$ for $(i,j) \in \Omega$

**Goal:** Recover full matrix $M \in \mathbb{R}^{m \times n}$

**Assumption:** $M$ is **low-rank**: $M = U V^\top$ with $U \in \mathbb{R}^{m \times r}$, $V \in \mathbb{R}^{n \times r}$, $r \ll \min(m,n)$

$$ \min_{U, V} \; \sum_{(i,j) \in \Omega} \big( M_{ij} - (U V^\top)_{ij} \big)^2 + \lambda \big( \|U\|_F^2 + \|V\|_F^2 \big) $$

😱 **Bilinear** in $(U, V)$ → non-convex, but **bi-convex**! ✅

---

## Slide 13: Matrix Completion — ALS 🔁

## Alternating Least-Squares Minimization

**Fix $V$, solve for $U$:** For each row $i$:

$$ u_i = \Big( \sum_{j \in \Omega_i} v_j v_j^\top + \lambda I \Big)^{-1} \sum_{j \in \Omega_i} M_{ij} \, v_j $$

**Fix $U$, solve for $V$:** For each column $j$:

$$ v_j = \Big( \sum_{i \in \Omega^j} u_i u_i^\top + \lambda I \Big)^{-1} \sum_{i \in \Omega^j} M_{ij} \, u_i $$

✅ Each subproblem is a **small ridge regression** — closed form!
🔁 Alternate until convergence.

---

## Slide 14: Matrix Completion — Practical Notes ⚙️

## Why ALS Works Well

🎯 **Per-row/column parallelism** — embarrassingly parallel
📦 **Memory efficient** — only store observed entries
🚀 **Scales** to millions of users/items (Netflix, Amazon)

⚠️ **Challenges:**
- 🎲 **Non-convex** — local minima depend on init
- 🐢 **Slow convergence** near optimum (ill-conditioning)
- 🔧 **Regularization crucial** — $\lambda$ controls rank implicitly

💡 **Tips:**
- Initialize with SVD of filled matrix
- Use **weighted ALS** for implicit feedback
- Consider **stochastic gradient** alternatives (Funk-SVD)

---

## Slide 15: Nearest Correlation Matrix — Overview 🔗

## The Problem

**Given:** A symmetric matrix $A \in \mathbb{R}^{n \times n}$ (possibly noisy, non-PSD)

**Goal:** Find the closest **correlation matrix** $C$:

$$ \min_{C} \; \|A - C\|_F^2 \quad \text{s.t.} \quad \begin{cases} C_{ii} = 1 & \forall i \\ C \succeq 0 & \text{(PSD)} \end{cases} $$

🎯 **Applications:**
- 💹 Finance — covariance matrix repair
- 🧪 Chemometrics — spectroscopic data
- 🧠 Psychometrics — factor analysis
- 📊 Risk management — stress testing

---

## Slide 16: Nearest Correlation Matrix — Alternating Projection 🔁

## Alternating Projection Method (Dykstra / Higham)

**Two constraint sets:**
- $\mathcal{C}_1 = \{ C : \mathrm{diag}(C) = \mathbf{1} \}$ — unit diagonal
- $\mathcal{C}_2 = \{ C : C \succeq 0 \}$ — PSD cone

**Alternating projection:**

$$ C^{(t+1/2)} = \Pi_{\mathcal{C}_1}\big( C^{(t)} \big), \quad C^{(t+1)} = \Pi_{\mathcal{C}_2}\big( C^{(t+1/2)} \big) $$

**Projections:**
- Onto $\mathcal{C}_1$: set diagonal to 1 ✂️
- Onto $\mathcal{C}_2$: eigendecompose, clip negative eigenvalues to 0 🎛️

---

## Slide 17: Nearest Correlation Matrix — Details 🛠️

## Higham's Algorithm (Simplified)

```
Initialize: Y⁽⁰⁾ = A, S⁽⁰⁾ = 0
for t = 0, 1, 2, ... do
    R⁽ᵗ⁾ = Y⁽ᵗ⁾ - S⁽ᵗ⁾
    X⁽ᵗ⁾ = Π_{C₁}(R⁽ᵗ⁾)        # Set diagonal to 1
    S⁽ᵗ⁺¹⁾ = X⁽ᵗ⁾ - R⁽ᵗ⁾       # Update correction
    Y⁽ᵗ⁺¹⁾ = Π_{C₂}(X⁽ᵗ⁾)      # Project onto PSD cone
end for
```

🔑 **Dykstra's correction** ensures convergence to the **true projection** onto $\mathcal{C}_1 \cap \mathcal{C}_2$.

⚡ **Complexity:** $O(n^3)$ per iteration (eigendecomposition)

---

## Slide 18: Comparing the Four Methods 📊

| Method | Variables | Subproblem | Convergence |
|--------|-----------|------------|-------------|
| 🧠 **EM** | $\theta, q(z)$ | Closed-form (often) | Monotonic, local |
| 🎛️ **Kalman** | $x_t, P_t$ | Linear Gaussian | Optimal (LQG) |
| 🧩 **ALS** | $U, V$ | Ridge regression | Linear, local |
| 🔗 **APM** | $C_1, C_2$ | Projections | Global (convex!) |

🎯 **Common theme:** Fix one block, optimize the other, repeat.

---

## Slide 19: When to Use Alternating Minimization ✅

## Pros & Cons

### ✅ Advantages
- 🧩 **Simple to implement** — often just a few lines
- 🎯 **Closed-form subproblems** — no gradient tuning
- 📦 **Memory efficient** — process one block at a time
- 🔀 **Parallelizable** — across rows/columns/samples
- 📉 **Monotonic** objective decrease

### ⚠️ Disadvantages
- 🐢 **Slow convergence** — especially near optimum
- 🎲 **Local minima** — initialization matters
- 🔧 **Hyperparameter sensitivity** — regularization, rank
- 🧊 **Can stall** — saddle points, plateaus

---

## Slide 20: Acceleration & Modern Variants 🚀

## Making Alternating Minimization Faster

⚡ **Momentum / Acceleration:**
$$ x^{(t+1)} = \arg\min_x f(x, y^{(t)}) + \frac{\beta}{2} \|x - x^{(t)}\|^2 $$

🎲 **Stochastic block updates** — sample minibatches
🧮 **Proximal variants** — handle non-smooth terms
🔄 **Block coordinate descent** — general framework
🧠 **Learned initialization** — neural warm starts

📚 **Theory:** Beck & Tetruashvili (2013), Wright (2015)

---

## Slide 21: Key Takeaways 🎓

## What We Learned

1. 🔄 **Alternating minimization** = fix one block, optimize the other
2. 🧠 **EM** — latent variables via E-step / M-step
3. 🎛️ **Kalman** — prediction / update for state estimation
4. 🧩 **ALS** — matrix completion via ridge regressions
5. 🔗 **APM** — correlation matrix via alternating projections

💡 **Universal pattern:** Decompose hard joint problems into easy conditional ones.

⚠️ **Trade-off:** Simplicity vs. convergence speed.

---

## Slide 22: Further Reading 📚

## References

🧠 **EM:**
- Dempster, Laird, Rubin (1977) — *Maximum Likelihood from Incomplete Data*
- Bishop, *Pattern Recognition and Machine Learning*, Ch. 9

🎛️ **Kalman:**
- Kalman (1960) — *A New Approach to Linear Filtering*
- Thrun et al., *Probabilistic Robotics*, Ch. 3

🧩 **Matrix Completion:**
- Koren, Bell, Volinsky (2009) — *Matrix Factorization Techniques*
- Candès & Recht (2009) — *Exact Matrix Completion*

🔗 **Nearest Correlation:**
- Higham (2002) — *Computing the Nearest Correlation Matrix*

---

## Slide 23: Q&A 🙋

# Questions? 🤔

### Thank You! 🎉

**Slides available at:** [your-link-here]

📧 **Contact:** [your-email]

---

## Slide 24: Appendix — Convergence Rates 📐

## Theoretical Guarantees

**EM (Wu 1983, McLachlan & Krishnan 2008):**
- Monotonic likelihood increase
- Linear convergence near MLE

**ALS (Uschmajew 2012):**
- Linear convergence under **restricted isometry**
- Rate depends on conditioning

**Alternating Projections (von Neumann 1933, Bauschke & Borwein 1996):**
- **Convex** case: global convergence ✅
- **Non-convex** case: local convergence only

$$ \|C^{(t)} - C^\star\|_F \leq \rho^t \|C^{(0)} - C^\star\|_F, \quad \rho < 1 $$

---

## Slide 25: Appendix — Code Snippet 💻

## ALS in 10 Lines (PyTorch)

```python
def als(M, mask, r=10, lam=0.1, iters=50):
    m, n = M.shape
    U = torch.randn(m, r, requires_grad=False)
    V = torch.randn(n, r, requires_grad=False)
    for t in range(iters):
        # Fix V, solve for U
        for i in range(m):
            idx = mask[i].nonzero()
            A = V[idx] @ V[idx].T + lam * torch.eye(r)
            b = M[i, idx] @ V[idx]
            U[i] = torch.linalg.solve(A, b)
        # Fix U, solve for V
        for j in range(n):
            idx = mask[:, j].nonzero()
            A = U[idx] @ U[idx].T + lam * torch.eye(r)
            b = M[idx, j] @ U[idx]
            V[j] = torch.linalg.solve(A, b)
    return U, V
```

---

## Slide 26: Appendix — Summary Diagram 🗺️

## The Alternating Minimization Family Tree

```
                Alternating Minimization
                          │
        ┌─────────────────┼─────────────────┐
        │                 │                 │
    🧠 EM            🎛️ Kalman         🧩 ALS
   (latent z)      (state x_t)      (factors U,V)
        │                 │                 │
    E-step /          Predict /         Fix V /
    M-step            Update            Fix U
        │                 │                 │
        └─────────────────┼─────────────────┘
                          │
                    🔗 Alternating
                      Projections
                    (C₁ ∩ C₂)
```

🎯 **One pattern, many applications.**

---

# End of Presentation 🎬

### Thank You for Your Attention! 🙏