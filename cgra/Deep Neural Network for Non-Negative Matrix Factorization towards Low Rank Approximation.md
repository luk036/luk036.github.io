# DN3MF: Deep Neural Network for Non-Negative Matrix Factorization towards Low Rank Approximation 🚀🤖

**Presenter:** [Your Name/Affiliation]  
**Date:** [Current Date]

---

## 1. The Challenge of High-Dimensional Data 📊🧩

*   **Problem:** Modern technologies generate enormous volumes of high-dimensional, complex datasets.
*   **Consequence:** This leads to the "curse of dimensionality" in machine learning, where the number of training samples required for model generalization increases exponentially with the number of dimensions.
*   **Solution:** **Low rank approximation** or **dimensionality reduction** is a highly sought-after methodology to deal with these complex datasets.
*   **Technique Categories:**
    *   **Linear Dimension Reduction:** Applicable when data lies on a linear subspace (e.g., Principal Component Analysis (PCA), Canonical Correlation Analysis (CCA), Locality Preserving Projections (LPP)). 🧮
    *   **Non-linear Dimension Reduction:** Used when data does not lie on a linear subspace (e.g., Self-organizing Map (SOM), Autoencoder (AE), t-Distributed Stochastic Neighbor Embedding (t-SNE)). 🌐

---

## 2. Non-Negative Matrix Factorization (NMF) Overview ✨🟩

*   **Definition:** NMF refers to a set of algorithms used for **feature extraction**.
*   **Core Process:** It decomposes a **non-negative input matrix** into two constituent non-negative parts, based on a required reduced dimension.
*   **Key Characteristics of NMF Features:**
    *   **Sparse and Meaningful:** Features extracted by NMF are inherently sparse and meaningful. 🌱
    *   **Interpretability:** Since output coefficients are positive, each data point can be represented as an additive sum of basis vectors multiplied by coefficients. This allows for **more efficacious interpretation** of results in various domains. 🧐
    *   **Reconstructive:** The decomposed parts can be combined to reconstruct the original data points. 🏗️
*   **NMF Variations:** Broadly categorized into basic NMF, constrained NMF, structured NMF, and generalized NMF. 🧑‍🔬

---

## 3. Why Choose NMF for Dimensionality Reduction? 🤔🔎

NMF offers distinct advantages, particularly due to its non-negativity constraint:

*   **Enforced Sparsity:**
    *   Non-negativity ensures that zero factors are generated when an attribute does not contribute to a signal. 🚫
    *   This is crucial for **uncovering distinct feature sets or sample relationships**. 🔍
*   **Non-Counterbalancing Factors:**
    *   Factors can only be positive or zero, meaning they cannot counteract each other. ➕
    *   This allows only additive signals to be explained, leading to a clearer representation where one factor doesn't "overcorrect" another. 💡
*   **Strong Theoretical Foundation in Clustering:**
    *   NMF has **theoretical connections to k-means clustering**. 📈
    *   It has been proven that NMF is equivalent to a **relaxed k-means clustering**, yielding a soft partitioning.
    *   **Orthogonal NMF** specifically amounts to k-means clustering.
    *   **Implication:** NMF can serve not only as a dimension reduction method but also as a powerful clustering algorithm. 🏆

---

## 4. The Need for Deep Learning in NMF 🧠🤓

*   **Limitations of Traditional Methods:** Traditional iterative NMF processes often require **manual interventions**, which can compromise the ultimate objective. 🛠️
*   **Deep Learning's Advantage:** Deep learning, a popular machine learning approach, learns and accumulates knowledge in a **hierarchical manner**, effectively bypassing the bottleneck of human intervention. 🏃‍♂️

*   **Existing Deep NMF Approaches (Examples):**
    *   **Deep Autoencoder-like NMF (DANMF):** Solves community detection problems by learning hierarchical mappings. 🕸️
    *   **Deep Semi-NMF (DS-NMF):** Automatically learns the hierarchy of dataset attributes and representations suited for clustering. 🏷️
    *   **Nonsmooth Nonnegative Matrix Factorization (nsNMF):** Learns part-based and hierarchical features, producing more localized representations. 🧩
    *   **Deep Grouped NMF (DGNMF):** Learns different level attributes while preserving local information using graph regularization. 🗺️
    *   **Applications:** Many of these works have applications on image datasets. Some extend to textual databases, networks, acoustic signals, and document classification. 🖼️📄🔊

---

## 5. Introducing DN3MF: A Novel Deep Learning Model 💡🆕

*   **Full Name:** Deep Neural Network for Non-negative Matrix Factorization (DN3MF).
*   **Core Idea:** Fuses the advantages of traditional iterative NMF with the hierarchical learning capabilities of deep learning. 🔗
*   **Objective:** Perform Non-negative Matrix Factorization targeted towards **low rank approximation** of high-dimensional data. 🎯
*   **Key Design Principles:**
    *   **Hierarchical Learning:** Data representation is learned in a layer-wise manner. 🪜
    *   **Two-Stage Model:**
        1.  **Pretraining Stage:** Implemented with a **shallow neural network** architecture. 🌱
        2.  **Stacking Stage:** Implemented with a **deep neural network** architecture. 🌲
    *   **Two Phases within Each Stage:**
        1.  **Deconstruction Phase:** Transforms input data into a latent space representation. 🧬
        2.  **Reconstruction Phase:** Reconstructs an approximation of the input matrix from the latent representation, ensuring the non-negativity requirement. 🏗️
*   **Novelty:** The stacking stage's architecture is referred to as **Multiple Deconstruction Multiple Reconstruction (MDMR)** framework, as it involves multiple deconstruction and reconstruction layers. 🔁

---

## 6. DN3MF Pretraining Stage: Architecture 🏗️🛤️

*   **Goal:** To determine optimal initial weight values for the subsequent stacking stage. 🎯
*   **Architecture:** Consists of a **shallow neural network** with three layers: input, hidden, and output. 🥪
*   **Data Preprocessing:**
    *   Original data matrix $\mathbf{U}_{m \times n'}$ (elements can be unrestricted) is processed to $\mathbf{X}_{m \times n}$ where all elements are non-negative.
    *   This uses a "folding data approach": Each column of $\mathbf{U}$ is represented by two columns in $\mathbf{X}$ (positive values in one, absolute negative values in the other). This makes $\mathbf{X}$ sparse and doubles the number of columns ($n = 2n'$). 🪞
*   **Layer Details:**
    *   **Input Layer:** Uses an **identity function** as the activation function. 🆔
    *   **Hidden Layer:** Acts as the "slender layer" with $r$ nodes ($r  0 \\ \epsilon, & \text{otherwise} \end{cases} \quad \text{where } \epsilon = 0.001 \text{}
    $$
    This modification ensures **non-negativity of factors** and solves the data loss problem faced by functions like ReLU. 🚦
*   **Weight Matrices:** $\mathbf{V}_{n \times r}$ (input to hidden) is unrestricted, while $\mathbf{W}_{r \times n}$ (hidden to output) **must be non-negative**. $\mathbf{B}$ and $\mathbf{W}$ form the non-negative factors of $\mathbf{\hat{X}}$. 🧮

---

## 7. DN3MF Pretraining Stage: Learning Rules 🧠📝

*   **Objective Function $\Phi$:** To minimize the Frobenius norm of the reconstruction error, $||\mathbf{X} - \mathbf{\hat{X}}||_F$.
    $$
    \Phi = \frac{1}{mn} \sum_{p=1}^m \sum_{j=1}^n \frac{1}{2} (x_{pj} - \hat{x}_{pj})^2 + \frac{\lambda}{n^2} \sum_{i=1}^n \sum_{j=1}^n \frac{1}{2} \left( \sum_{l=1}^r v_{il}w_{lj} - \delta_{ij} \right)^2 \text{}
    $$
    *   The **first term** measures average squared reconstruction error. 📉
    *   The **second term** is a **regularization term** designed to enforce $\mathbf{VW} = \mathbf{I}$ (Identity matrix). This helps DN3MF produce the best possible approximation of the input. 🛡️
    *   It uses L1/lasso regularization to reduce overfitting. The regularizing parameter $\lambda$ (e.g., **0.1**) controls its effect. ⚖️
*   **Optimization:** Achieved through an iterative **gradient descent technique**. ⏬
*   **Weight Initialization:** **Xavier initialization** technique is used for initializing weights $\mathbf{V}$ and $\mathbf{W}$ to tackle the exploding or vanishing gradient problem. 🎲
*   **Adaptive Learning Rate:** A novel adaptive learning mechanism is developed where the learning rate is weight-specific. 🏎️
    *   For $\mathbf{W}$: $\eta_W = (\text{mnW}) \oslash (\mathbf{B}^T(\mathbf{\hat{X}} \circ \mathbf{\hat{X}} + \mathbf{X} \circ \mathbf{\hat{X}} \circ \mathbf{\hat{X}}))$. This ensures non-negativity of $\mathbf{W}$ elements. Any negative $\mathbf{W}$ values are replaced with 0.001. 🟢
    *   For $\mathbf{V}$: Learning rate is set to **0.1**. 🚦
*   **Momentum Factor:** Used to speed up convergence of gradient-based optimization. For $\mathbf{V}$, a momentum factor of **0.9** is applied. 🏃‍♀️
    *   $\mathbf{V}(t+1) = \mathbf{V}(t) - \eta_{\mathbf{V}}(t) \circ \nabla_{\mathbf{V}(t)}\Phi + \alpha_{\mathbf{V}} \circ \nabla_{\mathbf{V}(t-1)}\Phi$.
*   **Hierarchical Pretraining:** The pretraining stage can consist of $s$ successive shallow models. The output of one shallow model's slender layer serves as the input for the next, progressively reducing dimension from $n$ to $r_s$ (the target reduced dimension). The learned weights from this stage initialize the stacking stage. 🧗

---

## 8. DN3MF Stacking Stage: Architecture 🏛️🧱 (Deep Learning)

*   **Goal:** To fine-tune the weight values learned during the pretraining stage. 🛠️
*   **Initialization:** The learned weights from the $s$ pretrained shallow models are used to initialize the weight values of this deep model. 🏗️
*   **Architecture Type:** **Multiple Deconstruction Multiple Reconstruction (MDMR) deep learning architecture**. 🧬
    *   It consists of an input layer, followed by $s$ deconstruction layers, and then $s$ reconstruction layers, culminating in an output layer. 🏁
    *   For demonstration, $s=2$ was considered, meaning 3 hidden layers (r1, r, r1) between input and output.
*   **Phases and Data Flow:**
    *   **Deconstruction Phase:** Input data $\mathbf{X}^{(0)}_{m \times r_0}$ (where $r_0 = n$) is progressively interpreted into lower-dimensional representations. 🪞
        *   For the $d$-th deconstruction layer (where $1 \le d \le s$):
            $$
            \mathbf{X}^{(d)} = \sigma(\mathbf{Y}^{(d)}) \quad \text{and} \quad \mathbf{Y}^{(d)} = \mathbf{X}^{(d-1)}\mathbf{V}^{(d)} \text{}
            $$
        *   $\mathbf{V}^{(d)}$ is initialized by the corresponding trained weight matrix from the pretraining stage. 🎯
        *   The **final deconstruction layer ($d=s$) is the slenderest**, generating $\mathbf{X}^{(s)}$ with $r_s$ nodes, which is the targeted reduced dimension. 🪶
    *   **Reconstruction Phase:** Aims to regenerate the input data from the latent representation step-by-step. 🔄
        *   For the $e$-th reconstruction layer (where $1 \le e \le s$):
            $$
            \mathbf{\hat{X}}^{(s-e)} = \sigma(\mathbf{Z}^{(s-e)}) \quad \text{where} \quad \mathbf{Z}^{(s-e)} = \text{input to layer} \times \mathbf{W}^{(s-e+1)} \text{}
            $$
        *   $\mathbf{W}^{(s-e+1)}$ is initialized by the corresponding trained weight matrix from the pretraining stage. 🏗️
*   **Weight Constraints:** Weight matrices $\mathbf{V}^{(1)}, \dots, \mathbf{V}^{(s)}$ are unrestricted, while $\mathbf{W}^{(s)}, \dots, \mathbf{W}^{(1)}$ must be non-negative. 🟩
*   **Final Output:** The model ultimately generates $\mathbf{\hat{X}}^{(0)}$, which is the regenerated approximation of the original input. $\mathbf{X}^{(s)}$ (slenderest layer output) is one non-negative factor, and the combination of $\mathbf{W}$ matrices with the activation function constitutes the other non-negative factor. 🏆

---

## 9. DN3MF Stacking Stage: Learning Rules 🧠📚 (Deep Learning)

*   **Objective Function $\Phi$:** Similar to pretraining, it minimizes the Frobenius norm $||\mathbf{X}^{(0)} - \mathbf{\hat{X}}^{(0)}||_F$.
    $$
    \Phi = \frac{1}{mn} \sum_{p=1}^m \sum_{j=1}^n \frac{1}{2} (x^{(0)}_{pj} - \hat{x}^{(0)}_{pj})^2 + \frac{\lambda}{n^2} \sum_{i=1}^n \sum_{j=1}^n \frac{1}{2} (a_{ij} - \delta_{ij})^2 \text{}
    $$
    *   **$\mathbf{A}$ Term:** $a_{ij}$ represents the complex product of all $\mathbf{V}^{(d)}$ and $\mathbf{W}^{(e)}$ matrices, which collectively should approximate the Identity matrix $\mathbf{I}$. 🧩
*   **Optimization:** Iterative gradient descent is used to minimize $\Phi$ with respect to all $\mathbf{V}^{(d)}$ and $\mathbf{W}^{(e)}$ matrices. ⬇️
*   **Update Equations (incorporating momentum for faster convergence):**
    *   For $\mathbf{V}^{(d)}$ (unrestricted weights):
        $$
        \mathbf{V}^{(d)}(t+1) = \mathbf{V}^{(d)}(t) - \eta_{\mathbf{V}^{(d)}} \circ \nabla_{\mathbf{V}^{(d)}}\Phi + \alpha_{\mathbf{V}^{(d)}} \circ \nabla_{\mathbf{V}^{(d)}(t-1)}\Phi \text{ [47, A10]}
        $$
    *   For $\mathbf{W}^{(e)}$ (non-negative weights):
        $$
        \mathbf{W}^{(e)}(t+1) = \mathbf{W}^{(e)}(t) - \eta_{\mathbf{W}^{(e)}} \circ \nabla_{\mathbf{W}^{(e)}}\Phi + \alpha_{\mathbf{W}^{(e)}} \circ \nabla_{\mathbf{W}^{(e)}(t-1)}\Phi \text{ [47, A11]}
        $$
*   **Hyperparameters:**
    *   Regularizing parameter $\lambda = \mathbf{0.1}$. ⚖️
    *   Learning rates $\eta_{\mathbf{V}^{(d)}}$ and $\eta_{\mathbf{W}^{(e)}}$ are set to **0.1**. 🏁
    *   Momentum factors $\alpha_{\mathbf{V}^{(d)}}$ and $\alpha_{\mathbf{W}^{(e)}}$ are set to **0.9** for fast convergence. 🚀
*   **Non-negativity Maintenance:** Similar to the pretraining stage, consistency with the non-negativity criterion for $\mathbf{W}^{(e)}$ is maintained by replacing any negative values with 0.001 during back-propagation. 🟩

---

## 10. Experimental Setup: Datasets & Comparisons 📊🧪

*   **Datasets Used:** (All from UCI Machine Learning Repository)
    1.  **Gastrointestinal Lesions in Regular Colonoscopy (GLRC)** 🩺
        *   152 samples $\times$ 699 features ($m  n$).
        *   Two classes: Parkinson's patients vs. healthy individuals. 👴🧑
    3.  **Online News Popularity (ONP)** 📰
        *   39644 samples $\times$ 59 features ($m > n$).
        *   Two classes based on article shares. 🔥
*   **Comparison Algorithms (Set $\mathbb{T}$):**
    *   Autoencoder (AE) 🤖
    *   Principal Component Analysis (PCA) 🧮
    *   Uniform Manifold Approximation and Projection (UMAP) 🌍
    *   Traditional NMF 🟩
    *   Semi-NMF 🟨
    *   Deep Semi-NMF (DS-NMF) 🟦
    *   **DN3MF** 🚀
*   **Experimental Procedure:**
    *   **Data Normalization:** Z-score normalization applied to all data matrices. 🧮
    *   **Reduced Dimension (r):** Determined by a reduction factor $f$ (0.1 to 0.6) such that $r = \lfloor n \times f \rfloor$. 📏
    *   **Evaluation:** Experiments performed for 5 randomly chosen $f$ values. Mean and standard deviation are presented. 📊
    *   **Statistical Significance:** Pairwise p-values (threshold < 0.05) are computed to demonstrate DN3MF's superiority. 🏅

---

## 11. Results: Local Structure Preservation (Trustworthiness) 👍🔒

*   **Metric:** **Trustworthiness Score** (values between 0 and 1).
    *   Quantifies how well the local structure of the original data is preserved in the low-dimensional embedding.
    *   A **higher score indicates a better dimension reduction strategy**.
    *   Formula:
        $$ T(k) = 1 - \frac{2}{nk(2n - 3k - 1)} \sum_{i=1}^n \sum_{j \in N_i^k} \max(0, (r(i, j) - k)) \text{} $$
        Where $N_i^k$ are the $k$ nearest neighbors in the output space for sample $i$, and $r(i,j)$ is the rank of $j$ as a nearest neighbor of $i$ in the input space.
*   **Key Findings (Table 1):**
    *   DN3MF consistently demonstrates **superior trustworthiness scores** across all three datasets compared to all other dimension reduction techniques.
    *   **GLRC Dataset:** **DN3MF: 0.7687** (e.g., AE: 0.7569, PCA: 0.5858).
    *   **PDC Dataset:** **DN3MF: 0.8293** (e.g., AE: 0.7759, NMF: 0.7978).
    *   **ONP Dataset:** **DN3MF: 0.7522** (e.g., AE: 0.7280, PCA: 0.7385).
*   **Conclusion:** This validates that DN3MF produces **higher quality low-dimensional embeddings** by better preserving the local structure of the data. This is visually represented by a larger area in spider plots (Fig. 3).

---

## 12. Results: Downstream Analysis - Classification 🎯

*   **Classification Algorithms Used:** K-Nearest Neighbor (KNN), Multilayer Perceptron (MLP), Naive Bayes (NB), and Quadratic Discriminant Analysis (QDA).
*   **Performance Metrics:**
    *   **Accuracy (ACC):** How frequently the model is correct.
    *   **F1 Score (FS):** Harmonic mean of precision and recall; effective for uneven class distribution.
    *   **Cohen-Kappa Score (CKS):** Measures inter-rater agreement; higher positive values indicate good agreement.
    *   **Matthew’s Correlation Coefficient (MCC):** Assesses classification quality by accounting for all true/false positives/negatives; higher score implies better agreement.
*   **Key Findings (Tables 2, 4, 6, 8 & Supplementary):**
    *   **Accuracy:** DN3MF achieved the best accuracy score for **PDC (4 out of 4 times)**, and **GLRC & ONP (3 out of 4 times)**.
    *   **F1 Score:** DN3MF consistently showed the highest F1 scores for **PDC and ONP (all 4 algorithms)**, and **GLRC (3 out of 4 algorithms)**.
    *   **Cohen-Kappa & MCC:** DN3MF generally demonstrated **better performance** for all three datasets using three out of four classification algorithms. Higher Cohen-Kappa and MCC scores indicate better preservation of inherent properties and class features.
*   **Statistical Significance (Tables 3, 5, 7, 9 & Supplementary):**
    *   The results obtained by DN3MF are **statistically significant (p-value < 0.05)** in a large majority of cases.
    *   For example, **GLRC dataset**: 82 out of 96 (85%) significant results across all classifiers and metrics.
    *   **PDC dataset**: 68 out of 96 (71%) significant results.
    *   **ONP dataset**: 71 out of 96 (74%) significant results.
*   **Conclusion:** This strong statistical evidence quantifies the **superiority of low-rank embedding produced by DN3MF** for classification tasks.

---

## 13. Results: Downstream Analysis - Clustering 🤝

*   **Clustering Algorithms Used:** Mini Batch k-Means (MBkM), Balanced Iterative Reducing and Clustering using Hierarchies (BIRCH), Gaussian Mixture Models (GMM), and Fuzzy c-Means (FcM).
*   **Cluster Validity Indices:**
    *   **Jaccard Index (JI):** Measures similarity between two sets.
    *   **Adjusted Rand Index (ARI):** Compares similarity of two clusterings, accounting for chance.
    *   **Normalized Mutual Information (NMI):** Normalizes Mutual Information to a range.
    *   **Adjusted Mutual Information (AMI):** Similar to NMI but adjusted for chance and invariant to label permutations.
*   **Key Findings (Tables 10, 12, 14, 16 & Supplementary):**
    *   **Jaccard Index:** DN3MF led to **better performance for all four clustering algorithms** across all three datasets.
    *   **Adjusted Rand Index:** DN3MF performed better in **almost all cases** (4/4 for GLRC & ONP, 3/4 for PDC).
    *   **NMI & AMI:** DN3MF secured the best performance score (4/4 algorithms) for all three datasets.
*   **Statistical Significance (Tables 11, 13, 15, 17 & Supplementary):**
    *   DN3MF's clustering results are **statistically significant** in the vast majority of cases.
    *   For example, **GLRC dataset**: 81 out of 96 (84%) significant findings.
    *   **PDC dataset**: 78 out of 96 (81%) significant findings.
    *   **ONP dataset**: 83 out of 96 (86%) significant findings.
*   **Conclusion:** This unequivocally demonstrates how **good low-rank embedding produced by DN3MF is compared to others** for clustering tasks, effectively maintaining the intrinsic properties of the original data.

---

## 14. Convergence Analysis 📈

*   **Objective:** Empirically establish the convergence of the proposed DN3MF model.
*   **Methodology:** Monitored the change in the cost function $\Phi$ over iterations for both pretraining and stacking stages.
*   **Observations (Fig. 4):**
    *   **Shallow Models (Pretraining):** An initial "spike" in the error curve was sometimes observed, possibly due to the fixed momentum factor slightly pushing up the error before it began a steady decline.
    *   **Deep Model (Stacking):** Small oscillations in the error value occurred throughout training, which could also be attributed to the fixed momentum factor.
*   **Overall Conclusion:** Despite minor initial fluctuations or oscillations, the **clear declining nature of the cost over time** demonstrates that both the shallow and deep models within DN3MF are **convergent** in nature.

---

## 15. Computational Complexity ⏱️

*   **Expressed in Big O Notation** for the upper bound of operations.
*   **DN3MF Complexity:**
    *   **Pretraining Stage:** For $s$ successive shallow models and $t_p$ epochs, the computational complexity is $\mathbf{O(st_p(mnr_1 + n^2r_1))}$.
        *   Here, $m$ is samples, $n$ is features, $r_1$ is the size of the slenderest layer.
    *   **Stacking Stage:** For $t_s$ epochs, the computational complexity is $\mathbf{O(t_s(mnr_1 + n^2r_1))}$.
    *   **Overall DN3MF:** The total computational complexity is $\mathbf{O((st_p + t_s)(m + n)nr_1)}$.
*   **Comparison with other algorithms:**
    *   **Autoencoder (single hidden layer):** $O(mnr)$.
    *   **Traditional NMF:** $O(mnr)$.
    *   **Semi-NMF:** $O(lt(mnk + nk^2 + km^2 + kn^2))$.
    *   **Deep Semi-NMF (DS-NMF):** Additional $O(t_f(nmk + mk^2 + nk^2))$ for stacking stage.
    *   **PCA:** $O(nm \times \min(m, n) + n^3)$.
    *   **UMAP:** Bounded by nearest neighbor search, often $O(m^2)$ (e.g., NN-Descent).
*   **Note on Comparison:** Direct comparison of computational complexities across these algorithms is challenging because they involve different parameters ($m, n, r, l, t, k$, etc.).

---

## 16. Conclusion: Why DN3MF Stands Out ✨

*   **Novelty:** DN3MF successfully **unifies the advantages of Non-negative Matrix Factorization and deep learning** for highly effective dimension reduction.
*   **Robust Architecture:** Its **two-stage (pretraining & stacking) and two-phase (deconstruction & reconstruction) MDMR design** ensures hierarchical learning and parameter optimization.
*   **Optimized Learning:** Features a novel objective function with tailored **regularization** and an **adaptive learning mechanism** to achieve the best possible approximation of the input matrix while maintaining non-negativity.
*   **Broad Applicability:**
    *   Demonstrated superior performance across diverse datasets, proving its **invariance to the number of samples ($m$) and features ($n$)**.
    *   Crucially, **unlike PCA ($r < \min(m, n)$) or Semi-NMF/DS-NMF ($2r < \min(m, n)$), DN3MF's reduced dimension ($r$) is NOT limited by the sample size or number of features**.
*   **Empirical Superiority:** Consistently outperformed six other state-of-the-art dimension reduction techniques in:
    *   **Preserving local data structure** (evidenced by higher trustworthiness scores).
    *   **Enhancing downstream analysis tasks** (superior classification and clustering performance metrics).
    *   The **statistical significance** of these results strongly validates DN3MF's performance.
*   **Proven Convergence:** Experimental results clearly demonstrate the convergence of both pretraining and stacking stages.

**DN3MF effectively learns the intrinsic properties of the input data and maps them to a meaningful low-rank representation.**

---

## 17. Q&A / Thank You! 🙏

*   Questions?
*   Contact: [Your Email / LinkedIn (Optional)]

