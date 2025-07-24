layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Quasi-convex Programming

@luk036 👨‍💻

2024-08-06 📅

---

## 📝 Abstract

Quasi-convex programming is a powerful optimization technique with diverse applications in electronic design automation. It enables solving complex problems by leveraging the properties of quasi-convex functions - a class of functions that generalize the well-known convex functions.
This presentation provides a comprehensive overview of quasi-convex programming and its applications in Electronic Design Automation, covering key concepts, methodologies, applications, challenges, and future directions in this field.

---

## What is Quasi-convex Programming?

- An extension of convex optimization
- Deals with quasi-convex functions and sets
- Bridges the gap between convex and non-convex optimization

---

## Definitions and Properties

- **Quasi-convex Functions**

A function is quasi-convex if its sublevel sets are convex. This allows for more flexibility compared to traditional convex optimization.

- **Key Properties**

Quasi-convex functions preserve many desirable properties of convex functions, such as local optimality implying global optimality.

- **Practical Significance**

Quasi-convex formulations enable solving a wide range of non-convex problems in EDA efficiently.

---

## Quasi-convex Functions

Definition: A function $f$ is quasi-convex if its sublevel sets are convex.

Mathematically: $f(\lambda x + (1-\lambda)y) \leq \max\\{f(x), f(y)\\}$ for all $x, y$ and $\lambda \in [0,1]$

Key property: Every local minimum is a global minimum

---

## Quasi-convex Programming Problem

General form:
- Minimize $f_0(x)$
- Subject to
  - $f_i(x) \leq 0$, $i = 1,\ldots,m$
  - $h_j(x) = 0$, $j = 1,\ldots,p$

Where $f_0$ is quasi-convex, $f_i$ are convex, and $h_j$ are affine.

---

## Solving Quasi-convex Problems

1. Bisection method
2. Convex feasibility problems
3. Iterative methods (e.g., cutting-plane algorithms)

---

## Quasi-convex Functions in EDA

Common quasi-convex functions in circuit design:
1. Ratios of convex functions (e.g., gain, efficiency)
2. Maximum of convex functions
3. Certain posynomial functions

---

## Applications in Analog Circuit Design 🤔

1. Amplifier design
   - Maximize gain-bandwidth product
   - Minimize power-delay product

2. Filter design
   - Optimize cutoff frequency to bandwidth ratio

3. Oscillator design
   - Maximize figure of merit (FOM)

---

## 📚 Example: Amplifier Design

Objective: Maximize gain-bandwidth product (GBW)

$GBW = \frac{g_m}{C_L}$

Where:
- $g_m$ is transconductance (convex in design variables)
- $C_L$ is load capacitance (affine in design variables)

This ratio forms a quasi-convex function.

---

## Applications in Digital Circuit Design

1. Gate sizing
   - Minimize area under delay constraints

2. Clock tree synthesis
   - Minimize skew-to-delay ratio

3. Power optimization
   - Minimize energy-delay product

---

## 📚 Example: Gate Sizing

Objective: Minimize area subject to delay constraints

Quasi-convex formulation:
- Minimize $\sum_i A_i(x_i)$
- Subject to $D(x) \leq D_{\max}$

Where $A_i$ is the area of gate $i$, and $D$ is the path delay.

---

## Applications in Layout Design 🤔

1. Floorplanning
   - Minimize aspect ratio of chip layout

2. Placement optimization
   - Minimize maximum wire length

3. Routing
   - Optimize wire width for delay-area trade-off

---

## 📚 Example: Floorplanning

Objective: Minimize the aspect ratio of the chip layout

Quasi-convex formulation:
- Minimize $\max\{\frac{W}{H}, \frac{H}{W}\}$
- Subject to area and positioning constraints

Where $W$ and $H$ are the width and height of the chip.

---

## Advantages of Quasi-convex Programming in EDA

1. Captures a wider range of problems than convex optimization
2. Guarantees global optimality
3. Efficient solution methods available
4. Handles trade-offs naturally (e.g., area vs. performance)

---

## Challenges and Limitations

1. More complex to solve than convex problems
2. May require problem-specific solution methods
3. Limited availability of general-purpose solvers
4. Difficulty in identifying quasi-convexity in complex functions

---

## Recent Advances

1. Integration with geometric programming
2. Development of specialized algorithms for EDA problems
3. Incorporation of machine learning techniques
4. Extension to multi-objective quasi-convex optimization

---

## Tools and Software

1. CVX (MATLAB-based modeling system)
2. CVXPY (Python-based modeling system)
3. MOSEK (Commercial optimizer with quasi-convex capabilities)
4. Custom EDA tools incorporating quasi-convex solvers

---

## 🔮 Future Directions

1. Improved algorithms for large-scale quasi-convex problems
2. Integration with other optimization techniques (e.g., mixed-integer programming)
3. Application to emerging EDA challenges (e.g., 3D IC design)
4. Development of more user-friendly modeling tools for quasi-convex problems in EDA

---

## Conclusion

- Quasi-convex programming: powerful tool for complex EDA problems
- Bridges gap between convex and non-convex optimization
- Wide range of applications in analog, digital, and layout design
- Promising area for future research and development in EDA

---

## 📑 References

- Boyd, S., & Vandenberghe, L. (2004). Convex Optimization. Cambridge University Press.
- Hershenson, M. D., Boyd, S. P., & Lee, T. H. (2001). Optimal design of a CMOS op-amp via geometric programming. IEEE TCAD.
- Relevant papers on quasi-convex optimization in EDA.

---

class: nord-dark, middle, center

# Q & A 🎤
