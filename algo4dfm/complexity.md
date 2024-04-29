layout: true
class: typo, typo-selection

---

class: nord-dark, middle, center

# Lecture 2d: Complexity Theory

@luk036

2022-09-21

---

## 🗺️ Overview

- Complexity theory

- NP-completeness.

- Approximation classes

- Books and online resources.

---

## Complexity Theory

- Big O-notation: O($N$), O($N\log N$), O($N^2$), O($N!$) ...

- Interest in discrete problems in which $N$ is large.

- Indeed, $N$ could be very large (multi-million) in EDA problems,
  except:

  - Pins of a signal net (usually < 200)
  - Vertices of polygon shapes (usually < 100)
  - Number of routing layers (usually < 10)

- Many Physical Design problems are geometrically related. Complexity
  (either time or space) could be reduced by exploiting properties
  such as locality, symmetry, planarity, or triangle inequality.

---

## NP-completeness

- Many EDA problems are in fact NP-hard.

- Whereas, some NP-complete problems admit good approximations with
  guarantee performance ratio (_pseudo-polynomial_). E.g. bin-packing
  problem and knapsack problem.

- Whereas, some NP-complete problems (e.g. SAT) are intrinsically not
  "approximatable" unless P=NP.

- See the book "Complexity and Approximation: Combinatorial
  Optimization Problems and Their Approximability Properties" for more
  details.

---

## Approximation Classes

- NPO-hard

- APX-hard

- PTAS: polynomial-time approximation scheme

- FPTAS: Fully PTAS (pseudo-polynomial)

  P < FPTAS < PTAS < APX < NPO

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

- Garey and Johnson: GT

---

## Minimum Maximal Matching

- Instance: Graph $G$ = ($V$, $E$).

- Solution: A maximal matching $E'$, i.e., a subset $E'$ such that no
  two edges in $E'$ shares a common endpoint and every edge in
  $E - E'$ shares a common endpoint with some edge in $E'$.

- Measure: Cardinality of the matching, i.e. $|E'|$.

- Bad News: APX-complete \[Yannakakis and Gavril, 1980\]

- Comment: Transformation from Minimum Vertex Cover (HW: Implement the
  algorithm)

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

## Traveling Salesman 🧳🕴

- Instance: Set $C$ of $m$ cities, distances $d(c_i, c_j) \in N$ for
  each pair of cities $c_i, c_j \in C$.

- Solution: A tour of $C$, i.e., a permutation
  $\pi : [1..m] \mapsto [1..m]$.

- Measure: The length of the tour.

![TSP](lec02.files/TSP.jpg)

---

## Traveling Salesman 🧳🕴

- Bad News: NPO-complete

- Comment: The corresponding maximization problem (finding the tour of
  maximum length) is approximable within 7/5 if the distance function
  is _symmetric_ and 63/38 if it is asymmetric \[Kosaraju, Park, and
  Stein, 1994\]

- Garey and Johnson: ND22

---

## Minimum _Metric_ TSP

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

## Minimum Geometric TSP

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

![TSP](lec02.files/TSP2.jpg)

---

## Summary

- Some problems are intrinsically hard -- even good approximation does
  not exist unless P=NP (NPO-complete). In such cases, heuristic
  methods are used (see the \[next lecture\]).

- "Better" algorithm could be obtained by exploiting more problem's
  properties: locality, symmetry, sparsity, planarity, convexity,
  monotonity, ... etc.

---

## 📚 Books and Online Resources

- G. Ausiello et al. Complexity and Approximation: Combinatorial
  Optimization Problems and Their Approximability Properties.
  Springer, 1999. (O224 C737)

- M. R. Garey and D. S. Johnson. Computers and Intractability: A Guide
  to the Theory of NP-completeness. Freeman, 1979.

---

class: nord-dark, middle, center

# 🙋 Q & A
