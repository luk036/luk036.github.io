# Graph/Hyper-graph Partitioning

## For complexity or parallelization

Graph decomposition

Undirected graph:
- Bi-connected Components (linear time)
- Tri-connected Components (linear time, SPQR-tree)

Directed graph:
- Strong and Weak components (linear time)

Directed Acyclic Graph:
- Topological Sort

## For Placement

## Hierarchical Design

## Balanced Partitioning

NP-hard problem

- Given graph is a mesh -> spectral bisection method
- Don't care about balance constraints too much -> Network-flow based method (based on Max-Flow Min-cut theorem)
- Given graph is small (say <= 25 modules) -> Middle Levels Gray code Exhaustive method
- Balance constraints are tight (say 0.49-0.51) -> Multi-level method
- Balance constraints are not tight (say 0.4-0.6) -> FM-only method

Simulated Annealing - meta heuristic
local search - N()

Support fixed modules