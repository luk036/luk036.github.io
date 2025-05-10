layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Bayesian Optimization: Theory and Practice in Python 🐍

@luk036 👨🏻‍🏫

2025-05-08 📅

---

## Credit 🙏

*   **Title:** Bayesian Optimization: Theory and Practice Using Python 🐍
*   **Based on:** Excerpts from the book by Peng Liu 📖
*   **Subtitle:** A Sample-Efficient Approach to Global Optimization 🎯

---

## What is Bayesian Optimization (BO)?

*   A **class of methodology** for sample-efficient global optimization. 🔄
*   Seeks the **optimal solution as fast as possible** ⚡.
*   Aims to find the global maximum (or minimum) of an unknown **black-box function** 📦.
*   Provides a **unified framework** for sequential decision-making under uncertainty. 🧩
*   Involves iteratively probing the unknown function to guide the search. 🔍

---

## Why Use Bayesian Optimization?

*   **Sample Efficiency:** Finds optimal solutions with significantly fewer function evaluations compared to methods like grid search or random search. 📉
*   **Handles Black-Box Functions:** Effective when the objective function is expensive to evaluate, lacks derivatives, or its structure is unknown. 🤖
*   **Quantifies Uncertainty:** Provides probabilistic estimates of the objective function, crucial for guiding the search. 🎲
*   **Sequential Decision Making:** Builds upon Bayesian Decision Theory principles. ⚖️
*   Applicable to various problems, like hyperparameter tuning in machine learning. 🤖🔧

---

## Core Components of BO

*   **Surrogate Model:** Approximates the unknown objective function. 🏗️
    *   Provides mean prediction and uncertainty estimates. 📊
    *   **Gaussian Processes (GP)** are a powerful and common choice. 🌟
*   **Acquisition Function:** A utility function that guides the sequential search. 🧭
    *   Decides the **next best location to sample** 📍.
    *   Balances **exploration** (sampling where uncertainty is high) 🗺️ and **exploitation** (sampling near current best values) 💎.
    *   Examples: Expected Improvement (EI), Knowledge Gradient (KG). 📈

---

## Quick Detour: Bayesian Statistics Basics for BO

*   **Bayesian Inference:** Updating prior beliefs with observed data to obtain a **posterior distribution**. 🔄
    *   Prior + Likelihood → Posterior. ➕➡️📊
    *   Posterior distribution reflects belief *after* seeing data. Approaches normal distribution with more data. 📉
*   **Prior and Posterior Predictive Distributions:** Distributions for *new* observations. 🔮
    *   Prior Predictive: Expected distribution of new data based on prior belief. 🔮
    *   Posterior Predictive: Expected distribution of new data based on updated (posterior) belief. Crucial for reasoning about sampling choices. 🎯

---

## The Bayesian Optimization Workflow

*   An iterative process. 🔄
*   **Starts with:** Initial dataset (can be small, sometimes generated randomly or with space-filling designs like Sobol sequences). 🎲
*   **Main Loop:
    1.  **Update Surrogate Model:** Fit or update the GP model based on all collected data. 🔄
    2.  **Optimize Acquisition Function:** Find the location(s) that maximize the acquisition function. This proposes the next sampling point(s). 📍
    3.  **Probe Environment:** Evaluate the true black-box function at the proposed location(s). 🔍
    4.  **Augment Dataset:** Add the new observation(s) to the dataset. ➕
*   Repeats until budget exhausted (e.g., number of iterations). ⏳

---

## Component 1: The Surrogate Model - Gaussian Processes (GP)

*   Models the objective function as a **sample from a distribution of functions**. 🎲
*   A **nonparametric model** with high expressive capacity.
*   Naturally quantifies **uncertainty**. ❓
*   Defined by a **mean function** and a **covariance (kernel) function**. 📊
*   The **kernel function** encodes prior assumptions about the function (e.g., smoothness). 🌀
    *   Examples: Squared Exponential (RBF), Matern, Linear, Periodic. 🔄

---

## GP Theory: Mean & Covariance

*   A Gaussian process is an infinite collection of random variables, where any finite subset follows a **multivariate Gaussian distribution**. 📊
*   The mean function specifies the expected value of the function at each point. 📍
*   The covariance (kernel) function `k(x_i, x_j)` defines the covariance between function values at any two points `x_i` and `x_j`. ↔️
    *   It measures their similarity based on distance in the input space. Larger distance usually means smaller covariance/similarity. 📏

---

## GP Prior and Posterior

*   **GP Prior:** Represents initial belief about the function before seeing data. Defined by the chosen mean and kernel functions. Can sample functions from this prior. 🎲
*   **GP Posterior:** The updated belief after observing data. 🔄
    *   Conditioned on observed data points. 📌
    *   Provides a posterior mean function (often passing through or near observed points) and a posterior covariance function (uncertainty is reduced near observed points). 📉
    *   Uncertainty is typically visualized with **credible intervals** (e.g., 95%). 📊

---

## GP in Practice: Implementing with GPyTorch

*   **GPyTorch:** A state-of-the-art GP library built on **PyTorch**. 🏗️
*   Leverages PyTorch features: **GPU acceleration** 🚀 and **auto-differentiation** (`autograd`). 🔄
*   Allows for efficient **exact or approximate GP inference**. 📊
*   Serves as the **backbone for BoTorch**. 🦴

---

## GPyTorch: Model Building & Inference

*   Building a GP model involves defining mean, kernel functions, and a likelihood. 🏗️
    *   Classes like `gpytorch.means.ConstantMean()` and `gpytorch.kernels.RBFKernel()`. 🛠️
    *   Likelihood (`gpytorch.likelihoods.GaussianLikelihood()`) models observation noise. 🔊
*   An `ExactGP` model can be defined by inheriting from `gpytorch.models.ExactGP`. 🧬
*   Fitting the model (`train` mode) and making predictions (`eval` mode). 🔄
*   Obtain mean, lower, and upper confidence bounds for plotting. 📊

---

## GPyTorch: Kernels & Hyperparameter Optimization

*   Different kernel functions capture different function properties (smoothness, periodicity, etc.). 🌀
*   Kernels can be **combined** via addition and multiplication for more complex functions. ➕✖️
*   Kernel and noise parameters (hyperparameters) are crucial for a good fit. 🔧
*   These can be optimized by maximizing the **marginal log likelihood (MLL)** of the observed data. 📈
*   GPyTorch and BoTorch provide utilities (`ExactMarginalLogLikelihood`, `fit_gpytorch_model`) to automate this optimization using PyTorch's `autograd`. 🤖

---

## Component 2: The Acquisition Function (AF)

*   Calculates the **utility** of sampling at a particular location `x`. 💰
*   Higher AF value suggests a more promising location. 📈
*   Balancing Exploration vs. Exploitation:
    *   **Exploration:** Sample in areas with high uncertainty (large credible interval). 🗺️
    *   **Exploitation:** Sample near current best observed value. 💎
*   Maximizing the AF determines the **next sampling point**. This is the "inner loop" optimization. 🔄
*   Policies can be myopic (one-step lookahead) or nonmyopic (multi-step lookahead). 👁️

---

## Acquisition Function: Expected Improvement (EI)

*   A widely used and effective acquisition function. 🏆
*   Measures the **expected gain** in the objective value compared to the **current best observed value**. 📈
*   Has an **analytic, closed-form expression** in the noiseless setting. ✍️
*   Calculates the expectation of `max(f(x) - f_best, 0)` under the GP posterior. 🧮

---

## Implementing EI with Libraries

*   Can be implemented from scratch using NumPy/SciPy. 🛠️
*   Libraries like `scikit-optimize` offer built-in `gp_minimize` function that uses EI. 📦
*   **BoTorch** provides the `ExpectedImprovement` class for analytic EI and `qExpectedImprovement` for Monte Carlo (MC) EI. 🎲
*   Optimizing the acquisition function in BoTorch is done using `optimize_acqf`. 🔄

---

## Monte Carlo (MC) Acquisition Functions

*   Used when acquisition function expectation **lacks a closed-form solution**. ❌
*   Approximates the expectation operator (an integral) via **Monte Carlo simulation**. 🎲
*   Draws samples from the GP posterior predictive distribution and averages a function of these samples. 📊
*   Example: **Monte Carlo Expected Improvement (MC EI)** or `qExpectedImprovement` in BoTorch. 📈

---

## BoTorch: Efficient Optimization Tools

*   Finding the maximum of the acquisition function is a non-convex optimization problem. 🏔️
*   BoTorch's `optimize_acqf` uses **multi-start optimization**. 🔄
    *   Starts gradient ascent from multiple initial conditions. 📍
*   Initial conditions for multi-start can be generated using **Sobol sequences**. 🎲
    *   Provide a **space-filling design** for better coverage than uniform random sampling. 🗺️
*   Leverages PyTorch's `autograd` for gradient calculation. 📊

---

## Acquisition Function: Knowledge Gradient (KG)

*   A **nonmyopic** acquisition function. 👁️
*   Quantifies the **expected increase in the maximum posterior mean** after taking a new observation. Represents the **value of information**. 💡
*   Original formulation involves **nested optimization**. 🏗️
    *   Requires optimizing over future ("fantasy") values. Computationally expensive. ⏳
*   Can be estimated using Monte Carlo simulations and gradient ascent. 🎲

---

## Knowledge Gradient: One-Shot KG (OKG)

*   Addresses the computational burden of nested KG. ⚡
*   Uses **Sample Average Approximation (SAA)** to convert the nested problem into a single, higher-dimensional deterministic optimization. 🔄
*   Approximates KG using a **fixed set of base samples** (fantasy points). 🎲
*   Formulated as a single optimization problem over current and future ("fantasy") locations. 📍
*   Implemented as `qKnowledgeGradient` in BoTorch. 📦

---

## Case Study 1: Global Optimization of Hartmann Function

*   Problem: Seek the global maximum of the 6-dimensional Hartmann function. 🎯
*   Demonstrates the **full BO loop** in practice. 🔄
*   Steps: Generate initial data, initialize/update GP posterior, create MC acquisition functions (qEI, qKG), run the iterative BO loop. 📊
*   Compare performance of qEI, qKG, and Random Search. 📉
*   Shows how BO policies effectively find the optimum compared to random search. (Source suggests qKG is better than qEI for Hartmann). 🏆

---

## Case Study 2: Tuning CNN Learning Rate

*   Problem: Find the optimal learning rate for a CNN classifying MNIST digits. 🤖
*   Hyperparameter tuning treated as a global optimization problem. 🎯
*   Involves: Loading data (MNIST with torchvision), defining CNN model (PyTorch), defining training/testing procedures.
*   Applies the **full BO loop** using qEI, qKG, and Random Search to the learning rate search space (typically log-scaled). 📊
*   Demonstrates practical application of BO to a common ML task. (Source suggests qEI performed best for this task, but variability is high). 📈

---

## Summary and Key Takeaways

*   Bayesian Optimization is a powerful **sample-efficient** approach for expensive black-box global optimization. 🎯
*   Core idea: Build a **probabilistic surrogate model** (like GP) and use an **acquisition function** (like EI or KG) to guide the search sequentially. 🧭
*   Libraries like **GPyTorch** and **BoTorch** provide the necessary tools for practical implementation in Python. 🛠️
*   Advanced techniques (MC, OKG, multi-start optimization with Sobol sequences) improve computational efficiency and performance. ⚡
*   BO is versatile, applicable to synthetic problems and real-world tasks like hyperparameter tuning. 🌍

---

count: false
class: nord-dark, middle, center

.pull-left[

# Q & A 🎤

] .pull-right[

![Discussion](figs/questions-and-answers.svg)

]