-> # Network Optimization <-

-> ## @luk036 <-

---

## Why?

  - Network is everywhere
      - Circuit
      - Internet
      - Social network
      - Neural network
  - Numerical and discrete problems

---

## Discrete problems

  - Shortest path
      - Do not need to evaluation ALL possible paths
      - Bellman-Ford algorithm
      - polynomial time solvable
  - Negative cycle finding, NCF
      - side product of shortest path
      - Howard policy graph

---

## Parametric problems

  - Minimum/Maximum mean cycle
      - shortest path
      - NCF + zero-cancellation
      - NCF + binary search
  - Minimum cost-to-time-ratio
      - NCF-based
  - Multi-parameter
      - NCF + Ellipsoid method

---

## Min-cost flow problems

  - Max-flow
      - successive shortest path
      - negative cycle based + descent method
  - Min-cut
      - Solved by max-flow
  - Matching problems
      - maximum bipartite matching problem
      - minimum perfect matching problem
  - Assignment problems
      - Layer assignment problem

---

## Tools

  - Python: networkx, netoptim
  - C++:
      - LEMON
      - Boost Graph Library (BGL)
      - netoptimcpp

---

## Other thoughts 

  - Convex cost flow
  - Multicommodity flow



