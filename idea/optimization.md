# Multi-objective optimization in Electronic Design Automation (EDA)

Beyond PPA (performance, power, area):
- yield
- robustness
- design-for-test (DFT)
- design-for-CAD
- design-for-manufacturability

c.f. Algorithms
Beyond run-time performance, memory storage:
- energy effectiency
- simiplicity

Example: Global Placement

Objectives
- Total Wirelength
- Congestion
- Timing

## Multi-to-Single Objective Optimization

1. Weighted sum

   minimize alpha_1 obj_1 + alpha_2 obj_2 + ...
    
2. Ratio

   minimize obj1 / obj2 (Quasi-convex)
   
## Pareto Front