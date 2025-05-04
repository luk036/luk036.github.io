layout: true
class: typo, typo-selection

---

class: nord-dark, middle, center

# 📚 Lecture 2d: Complexity Theory

@luk036

2022-09-21

---

## 📝 Abstract

Throughout this presentation, we'll examine how computational problems are classified based on their inherent difficulty, with special attention to NP-completeness and approximation algorithms.

We'll investigate why many Electronic Design Automation (EDA) problems are computationally challenging and explore strategies for addressing these complex problems. By the end, you'll understand the theoretical foundations that guide algorithm selection in practical applications.

---

## 🗺️ Overview

- Complexity theory

- NP-completeness.

- Approximation classes

- Books and online resources.

---

## Complexity Theory Fundamentals

- Big O-notation

  Classifies algorithms based on their growth rate: O($N$), O($N\log N$), O($N^2$), O($N!$) ...

- EDA Problem Scale

  $N$ can reach multi-millions in Electronic Design Automation problems.

- Practical Limits

  Most EDA problems have practical limits: signal nets (<200 pins), polygon shapes (<100 vertices), routing layers (<10)

- Geometric Properties

  Many physical design problems can exploit locality, symmetry, planarity, or triangle inequality to reduce complexity

---

## The Challenge of NP-Hard

- NP-Hard Problems

  Many Electronic Design Automation problems fall into the NP-hard category, making them computationally intensive to solve optimally.

  Some NP-hard problems allow for good approximations with guaranteed performance ratios (**pseudo-polynomial**), such as bin-packing and knapsack problems.

- Approximation Challenges

  Other NP-complete problems like Boolean Satisfiability (SAT) are intrinsically not "approximatable" unless P=NP.

For deeper insights, refer to "Complexity and Approximation: Combinatorial Optimization Problems and Their Approximability Properties."

---

## Approximation Classes Hierarchy

- NPO-hard: Hardest optimization problems

- APX-hard: Cannot be approximated within constant factor

- PTAS: Polynomial-time approximation scheme

- FPTAS: Fully polynomial-time approximation scheme

- P: Polynomial time solvable

This hierarchy represents the relationship between different approximation classes, with P being the easiest problems and NPO-hard being the most difficult. The relationship can be expressed as: P < FPTAS < PTAS < APX < NPO.

---

## E.g. Minimum Vertex Cover

- Instance: Graph $G$ = ($V$, $E$)

- Solution: A vertex cover for $G$, i.e., a subset $V'$ such that, for
  each edge $(u, v) \in E$, at least one of $u$ and $v$ belongs to
  $V'$

- Measure: Cardinality of the vertex cover, i.e. $|V'|$

- Bad News: APX-complete.

- Comment: Admits a PTAS for _planar_ graphs \[Baker, 1994\]. The
  generalization to $k$-hypergraphs, for $k>1$, is approximable within
  $k$ \[Bar-Yehuda and Even, 1981\] and \[Hochbaum, 1982a\]. (HW:
  Implement the algorithms.)

- Garey and Johnson: GT1

---

## Minimum Maximal Matching

- Instance: Graph $G$ = ($V$, $E$).

- Solution: A maximal matching $E'$, i.e., a subset $E'$ such that no
  two edges in $E'$ shares a common endpoint and every edge in
  $E - E'$ shares a common endpoint with some edge in $E'$.

- Measure: Cardinality of the matching, i.e. $|E'|$.

- Bad News: APX-complete \[Yannakakis and Gavril, 1980\]

- Comment: Transformation from Minimum Vertex Cover (HW: Implement the algorithm)

- Garey and Johnson: GT10

---

## Minimum Steiner Tree

- Instance: Complete graph $G$ = ($V$, $E$), a metric given by edge
  weights $s: E \mapsto N$ and a subset $S \subset V$ of required
  vertices.

- Solution: A Steiner tree, i.e., a sub-tree of $G$ that includes all
  the vertices in $S$.

- Measure: The sum of the weights of the edges in the sub-tree.

- Bad News: APX-complete.

- Garey and Johnson: ND12

---

## Minimum Geometric Steiner Tree

- Instance: Set $P \subset Z \times Z$ of points in the plane.

- Solution: A finite set of Steiner points, i.e.,
  $Q \subset Z \times Z$

- Good News: Admits a PTAS \[Arora, 1996\]

- Comment: Admits a PTAS for any _geometric space_ of constant
  dimension $d$, e.g. in the rectilinear metric \[Arora, 1997\].

- Garey and Johnson: ND13

---

## Traveling Salesperson Problem

- Instance: Set $C$ of $m$ cities, distances $d(c_i, c_j) \in N$ for
  each pair of cities $c_i, c_j \in C$.

- Solution: A tour of $C$, i.e., a permutation
  $\pi : [1..m] \mapsto [1..m]$.

- Measure: The length of the tour.

![TSP](lec02.files/TSP.jpg)

---

## General TSP

- Bad News: NPO-complete

- Comment: The corresponding maximization problem (finding the tour of
  maximum length) is approximable within 7/5 if the distance function
  is _symmetric_ and 63/38 if it is asymmetric \[Kosaraju, Park, and
  Stein, 1994\]

- Garey and Johnson: ND22

---

## Metric TSP

- Instance: Set $C$ of $m$ cities, distances $d(c_i, c_j) \in N$
  satisfying the _triangle inequality_
  (i.e. $d(a, b) + d(b, c) \geq d(a, c)$)

- Solution: A permutation $\pi : [1..m] \mapsto [1..m]$.

- Measure: The length of the tour.

- Good news: Approximable within 3/2 \[Christofides 76\]

- Bad News: APX-complete.

- Comment: A variation in which vertices can be revisited and the goal
  is to minimize the sum of the latencies of all vertices, where the
  latency of a vertex $c$ is the length of the tour from the starting
  point to $c$, is approximable within 29 and is APX-complete

---

## Geometric TSP

- Instance: Set $C \subset Z \times Z$ of $m$ points in the plane.

- Solution: A tour of $C$, i.e., a permutation
  $\pi : [1..m] \mapsto [1..m]$.

- Measure: The length of the tour, where the distance is the
  discretized Euclidean length.

- Good news: Admits a PTAS \[Arora, 1996\]

- Comment: In $\mathbb{R}^m$ the problem is APX-complete for any $l_p$
  metric \[Trevisan, 1997\].

- Garey and Johnson: ND23

---

## Application - Punching Machine

Used in manufacturing for optimizing punching machine operations and other industrial processes requiring efficient path planning.

![TSP](lec02.files/TSP2.jpg)

---

## Approximation Strategies for Hard Problems

- Heuristic Methods

  For NPO-complete problems where good approximations don't exist unless P=NP, heuristic methods provide practical solutions without guarantees.

- Exploiting Problem Properties

  Better algorithms can be developed by leveraging properties such as locality, symmetry, sparsity, planarity, convexity, and monotonicity.

- Problem-Specific Techniques

  Many EDA problems benefit from domain-specific knowledge that can dramatically reduce computational complexity in practice.

---

## 📚 Resources for Further Study

To deepen your understanding of complexity theory and approximation algorithms, consider these valuable resources:

- Key Textbooks

  G. Ausiello et al. "Complexity and Approximation: Combinatorial Optimization Problems and Their Approximability Properties." Springer, 1999. (O224 C737)

- Foundational Work

  M. R. Garey and D. S. Johnson. "Computers and Intractability: A Guide to the Theory of NP-completeness." Freeman, 1979.

- Online Learning

  Explore academic courses, research papers, and online tutorials that provide practical implementations of the theoretical concepts covered in this presentation.

---

class: nord-dark, middle, center

# 🙋 Q & A
