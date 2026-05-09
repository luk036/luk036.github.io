# Introduction to Physical Design Automation

## Electronic Design Automation (EDA)

Key components:

- Algorithms, software engineering (computer science)
- Modeling, simulation (electronics)
- Design flow issues: chicken and egg 

---

## Versus Logic Synthesis

- Humans are not good at logic, but human eyes are good at pictures.
- Not much appreciation.

---
## Computer Languages

- C++ is hard, unfortunately.
- Try Python first, then translate to C++ (using AI).

---

## Domain Specific Rules

- Coordinates are assumed to be big integers. Don't use floating point. Be careful of overflow.
- Geometry is assumed to be rectilinear unless specifically mentioned.
- Rectilinear: vertical and horizontal physical lines + 45-degree abstract lines.
- The number of physical objects is on the scale of thousands of millions, except:
  - Polygons vertices <= 100.
  - Metal layers <= 20.
  - Keepouts <= 10.
  - Nets usually contain a few pins, except for the so-called high fan-out nets.
- Keep algorithms simple (simple != easy).
- Don't use virtual functions unless specifically mentioned (C++).
- Use unique_ptr instead of shared_ptr as possible.

---

## Advanced Topics in Physical Design Automation (mainly ASIC)

- Multilevel hypergraph partitioning (clustering)
- Rectilinear shapes, Manhattan metric
- Rectilinear polygon
- Rectilinear Voronoi diagram
- Global routing with keepouts and 3D extension
- Steiner forest via union-find and primal-dual
- Prescribed-skew DME algorithm in clock tree synthesis
- Useful skew design flow
  - Clock skew scheduling
  - Delay padding
- Global placement
