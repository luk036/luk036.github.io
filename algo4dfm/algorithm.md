Lecture 1b: Algorithmic Paradigms
=================================

LUK Wai-Shing
-------------

School of Microelectronics
--------------------------

---

Agenda
------

-   Greedy approach

-   Local search

-   Mathematical programming

-   Primal-dual algorithm

-   Randomized method

-   Dynamic programming

-   Simulated annealing

-   Genetic algorithm

-   Books and online resource

---

Greedy Approach
---------------

-   Excellent for Minimum Spanning Tree (MST) and Channel Routing Problem
    -   Obtain optimal solution

-   Not bad for Knapsack problem
    -   At least half of optimal solution

-   Very bad for Feedback Arc Removal problem
    -   Even worse than a naïve method: randomly remove edges when traversing a graph, then reverses the set if \|E'\| is greater than 0.5\*\|E\|.

-   Question: Any theory to predict the performance?

---

Knapsack Problem
----------------

-   A thief considers taking *b* pounds of loot. The loot is in the form of *n* items, each with weight *a~i~* and value *p~i~*. Any amount of an item can be put in the knapsack as long as the weight limit *b* is not exceeded

---

Greedy Approach
---------------

-   Take as much of the item with the highest value per pound (*p~i~*/*a~i~*) as you can. If you run out of that item, take from the next highest (*p~i~*/*a~i~*) item. Continue until knapsack is full.

---

Program 1: Greedy Knapsack
--------------------------

-    **Input**: Set of *n* items, for each *x~i~* \\in *X*, values *p~i~*, *a~i~*, positive integer *b*;
-    **Output**: Subset *Y* \\subset *X* such that Σ *a~i~* \<= *b*;
-    **begin**
-    Sort *X* in non-increasing order with respect to the ratio *p~i~*/*a~i~*;
-    (\* Let (*x*~1~, *x*~2~, ..., *x~n~*) be the sorted sequence \*)
-    *Y* := *0*;
-    **for** *i*:=1 **to** *n* **do**
-    **if** *b* \>= *a~i~* {
-    *Y* := *Y* U { *x~i~* };
-    *b* := *b* -- *a~i~*;
-    }
-    **return** *Y*
-    **end**

---

Can the thief do better?
------------------------

-   Theorem 1. Let *m~H~*(*x*) = max(*p*~max~, *m~Gr~*(*x*)), where *p*~max~ is the maximum profit of an item in *x*. Then *m~H~*(*x*) satisfies the following inequality: *m*\*(*x*)/*m~H~*(*x*) \< 2. (p.42) (*m*\*(*x*) is the optimal solution)

-   As a consequence of the above theorem, a simple modification of Program 1 allows us to obtain a provably better algorithm.

-   HW: Implement the algorithm using C++ Template technique and iterators (generic programming style

---

Linear Programming Relaxation
-----------------------------

-   Formulate a problem as an integer linear program.

-   By relaxing the integrality constraints we obtain a new linear program, whose optimal solution can be found in polynomial time.

-   This solution, in some cases, can be used to obtain a feasible solution for the original integer linear program, by "rounding" the values of the variables that do not satisfy the integrality constraints.

---

Weighted Vertex Cover
---------------------

-   Given a weighted graph *G*=(*V*,*E*), Minimum Weighted Vertex Cover (MWVC) can be formulated as the following integer program ILP~VC~(*G*):

-   Minimize Σ~{*vi*\ \\in\ *V*}~ *c~i~* *x~i~*

-   Subject to *x~i~* + *x~j~* \>= 1 for all (*v~i~*,*v~j~*) \\in *E*

-   *x~i~* \\in {0, 1} for all *v~i~* \\in *V*

---

Program 2.6 Rounding WVC
------------------------

-    **Input** Graph *G*=(*V*,*E*) with non-negative vertex weights;

-    **Output** Vertex cover *V*' of *G*;

-    **begin**

-    Let ILP~VC~ be the linear integer programming formulation of the problem;

-    Let LP~VC~ be the problem obtained from ILP~VC~ by relaxing the integrality constraints;

-    Let *x*\*(*G*) be the optimal solution for LP~VC~;

-    *V*' = {*v~i~* \| *x~i~*\*(*G*) \>= 0.5};

-    **return** *V*'

-    **end**

---

Linear Programming
------------------

-   Theorem 2.15. Given a graph *G* with non-negative vertex weights, Program 2.6 finds a feasible solution of MWVC with value *m*~LP~(*G*) such that *m*~LP~(*G*)/*m*\*(*G*) \<= 2.

-   Problem: need to solve the LP optimally.

---

Primal-Dual WVC
---------------

-    **Input** Graph G= (V, E) with non-negative vertex weights;

-    **Output** Vertex cover V' of G;

-    **begin**

-    Let DLP~VC~ be the dual of the LP relaxation of ILP~VC~;

-    **for** each dual variable y~ij~ of DLP~VC~ do y~ij~ := 0;

-    V' := 0;

-    **while** V' is not a vertex cover **do**

-    **begin**

-    Let (v~i~, v~j~) be an edge not covered by V';

-    Increase y~ij~ until a constraint of DLP~VC~ becomes tight for either i or j;

-    **if** \\sum\_{j:(v~i~,v~j~) \\in E} y~ij~ = c~i~ **then**

-    V' := V' U {v~i~} (\* the i-th dual constraint is tight \*)

-    **else**

-    V' := V' U {v~j~} (\* the j-th dual constraint is tight \*)

-    **end**

-    **return** V'

-    **end**

---

Primal-Dual WVC
---------------

-   Theorem 2.16. Given a graph *G* with non-negative weights, Program 2.7 finds a feasible solution of MWVC with value *m*~PD~(*G*) such that *m*~PD~(*G*)/*m*\*(*G*) \<= 2. (p. 69)

-   Much faster than Program 2.6 (only take linear time) because we don't need to solve the LP optimality.

-   Bonus: Sum of dual variables *y~ij~* gives the lower bound of the optimal solution.

---

Program: Random WVC
-------------------

-    **Input** Graph G= (V, E), weight function w: V -\> N;

-    **Output** Vertex cover U;

-    **begin**

-    U := 0;

-    **while** E != 0 **do**

-    **begin**

-    Select an edge e = (v,t) \\in E;

-    Randomly choose x from {v,t} with Pr{x=v} = w(t) / (w(v) + w(t));

-    U := U \\U {x};

-    E := E -- {e \| x is an endpoint of e}

-    **end**;

-    **return** U

-    **end**

---

Randomized Algorithms
---------------------

-   In many cases, a randomized algorithm is either simpler or faster (or both) than a deterministic algorithm.

-   However, it does not guarantee that the algorithm always finds a good approximation solution.

-   Theorem 5.1. The expect measure of the solution returned by the previous algorithm satisfied the following inequality:

-   ### E\[mRWVC(x)\] \<= 2 m\*(x)

-   HW: Implement MWVC solvers using all the above methods. Also extend all the methods to handle hypergraph

---

Dynamic Programming (I)
-----------------------

-   One passenger wants to go from city A to city H through the *shortest path* according to the map on the right, where number of indicate distance between corresponding cities.

-   \[Reference:Pablo Pedregal, *Introduction to Optimization*, chapter 5.8, Springer, 2003

---

Dynamic Programming (II)
------------------------

-   Proposition 5.24 (Fundamental property of dynamic programming) If *S*(*t~j~*, *x*) denotes the optimal cost from (*t*~0~, *x*) to (*t~j~*, *x*), then we must have *S*(*t~j~*~+1~, *y*) = min*~j~* \[*S*(*t~j~*, *x*) + *c*(*j*,*x*,*y*)\]

---

Dynamic Programming (III)
-------------------------

-   According to Proposition 5.24, we must proceed successively to determine S(*t~j~*, *x*) for each *x* \\in A*~j~* to end with S(*t~n~*, *x~n~*). In the proposed example, we have four stages *t*~0~, *t*~1~, *t*~2~, *t*~3~ with associated sets of feasible states

-   ### A~0~ = {A}, A~1~ = {B, C, D}, A~2~ = {E,F,G}, A~3~ = {H}

-   For each city in A~1~, there is a unique path from A, so that it must be optimal, and

-   ### S(*t*~1~, B) = 7, S(*t*~1~, C) = 4, S(*t*~1~, D) = 1.

-   For each city in A~2~, we determine the optimal cost based on the fundamental property of dynamic programming,

-   ### S(*t~j~*~+1~, *y*) = min \[S(*t~j~*, *x*) + c(*j*,*x*,*y*)\]

---

Local Search
------------

-    **Input**: Instance x; **Output**: Solution s

-    **begin**

-    s := initial feasible solution s~0~;

-    (\* N denotes the neighborhood function \*)

-    **repeat**

-    Select any s' \\in N(x, s) not yet considered;

-    **if** m(x,s') \< m(x, s) **then**

-    s := s';

-    **until** all solutions in N(x, s) have been visited;

-    **return** s;

-    **end**

---

Simulated Annealing
-------------------

-   **Input**: Instance x; **Output**: Solution s

-   **begin**

-    τ := t;

-    s := initial feasible solution s~0~;

-    **repeat**

-    **for** l times **do** { 

-    (\* local search at temperature τ \*) 

-    Select any unvisited s' \\in N(s);

-    **if** (m(x, s') \< m(x, s)) s := s';

-    **else** {

-    δ := m(x, s') -- m(x, s);

-    s := s' with probability exp(-δ/t);

-    }

-    }

-    τ := r \* τ; (\* update of temperature \*)

-    **until** FROZEN;

-    **return** s;

-    **end**

---

Books and Online Resources
--------------------------

-   G. Ausiello et al. Complexity and Approximation: Combinatorial Optimization Problems and Their Approximability Properties. Springer, 1999. (O224 C737)

-   M. R. Garey and D. S. Johnson. Computers and Intractability: A Guide to the Theory of NP-completeness. Freeman, 1979.

-   Pablo Pedregal. Introduction to Optimization. Springer, 2003 (O224 P371)
