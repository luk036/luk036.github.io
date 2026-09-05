# Global Placement

Billions of cells

Old story:
- min-sum (minimize the total wirelength)
- Non-convex Problem -> Convex Problem
- Gradient-based algorithms
- HPWL

Congestion problem -> timing problem
Add Density-constraint (Equality constraint)
不患寡而患不均

AI-assisted: RL

New story:
- Fairness Centric (不患寡而患不公)
  Enforcing fairness is easier than enforcing equality
- min-max (minimize the worst wirelength) (max-min fairness)
- Use a simple alternating minimization method to decouple the non-convex problem
  - Each subproblem is solved by a network parametric method 
- Simulated Annealing