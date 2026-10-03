# Multi-objective optimization in Electronic Design Automation (EDA)

Beyond PPA (performance, power, area):
- yield
- robustness
- design-for-test (DFT)
- design-for-CAD
- design-for-manufacturability

c.f. Algorithms
Beyond run-time performance, memory storage:
- energy efficiency
- simplicity

Example: Global Placement

Objectives
- Total Wirelength
- Congestion
- Timing

## Multi-to-Single Objective Optimization

1. Weighted sum

   minimize $\alpha_1 \text{obj}_1 + \alpha_2 \text{obj}_2 + \dots$

2. Ratio

   minimize $\text{obj}_1 / \text{obj}_2$ (quasi-convex)

## Pareto Front