# Network Optimization mind map

network (path/cycle)

- parametric (potential)

  - single parameter
    - monotonic
      - linear
        - minimum mean cycle
          - Young's algorithm (path-based)
        - minimum cycle ratio
          - Howard's algorithm
      - non-linear
        - Howard's algorithm
    - non-monotonic
      - convex
        - linear or subgradient available
          - Bisection method + NegCycle as separation oracle
        - subgradient not available
          - Lawler's algorithm (binary search)
  - multiple parameter
    - convex
      - linear or subgradient available
        - Ellipsoid method + NegCycle as separation oracle

- min-cost (flow)
  - continous
    - linear
      - Network simplex method (special pivot)
    - max-flow
  - discrete
  - matching problem
