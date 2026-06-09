# Graph/Hyper-graph Partitioning

## Balanced Partitioning

NP-hard problem

- Given graph is a mesh -> spectral bisection method
- Don't care about balance constraints too much -> Network-flow based method (based on Max-Flow Min-cut theorem)
- Given graph is small (say <= 25 modules) -> Middle Levels Gray code Exhaustive method
- Balance constraints are tight (say 0.49-0.51) -> Multi-level method
- Balance constraints are not tight (say 0.4-0.6) -> FM-only method
