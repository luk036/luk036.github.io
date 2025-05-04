layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# 📦 Packing and Re-packing

@luk036

---

## Design flow of FPGA

```
┌───────────────┐
│Logic synthesis│
└┬──────────────┘
┌▽─────────────────┐        
│Technology Mapping│        
└┬─────────────────┘        
┌▽──────┐        
│Packing│        
└┬──────┘        
┌▽────────┐      
│Placement│      
└┬────────┘      
┌▽──────┐        
│Routing│        
└───────┘        
```

---

## Toy Problem (1) 

```
   L      L     L     L
    F    F    L   L  F
  L    L    L   F   L
    L    F   L    
       L         L  F

   C    C    C    C
   C    C    C    C
   C    C    C    C
   C    C    C    C
```

Given:
- A netlist contains $n$ L's and $m$ F's.
- A grid of C's, each of them can pick exactly one L and one F.

---

## Problem Formulation

- Weighted bipartite matching
- Edge-weight models the importance, e.g.
  - connectivity
  - physical distance (repacking)

Choices:
- Exact solution using a network flow algorithm 
- Approximate solution using greedy or primal-dual algorithm

---

## 📚 Example

```
  F  F  F  F  F  F  o  o  o  o  o  o  o  o  o  o

  L  L  L  L  L  L  L  L  L  L  L  L  L  L  o  o
```

---

## Toy Problem (2) 

Given:
- A netlist contains $n$ L's, $m$ F's, and $p$ Q's.
- A grid of C's, each of them can pick exactly one L, one F, and one Q.

Possible solution:
- Two-stage approach:
  pack_toy1(Q, F)
  pack_toy1(QF, L)

---

## Toy Problem (3) 

Given:
- A netlist contains $n$ L's and $m$ F's.
- A grid of C's, each of them can pick exactly **two** L's and one F.

Possible solution:
- Two-stage approach:
  pack_toy1(F, L)
  pack_toy1(L, FL)

---

## 📚 Example

Step 1
```
  F  F  F  F  F  F

  L  L  L  L  L  L  L  L  L  L  L  L  L  L
```

Step 2
```
  FL  FL  FL  FL  FL  FL  o   o

  L   L   L   L   L   L   L   L
```

---

## Specialized C?

- What if there are two kinds of C's
  - e.g. C1 = [L1, F], C2 = [L2, F]

- Set Cover problem?

---

class: nord-dark, middle, center

# 🙋 Q & A️

