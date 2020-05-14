%title Algebra of Boole
%author Wai-Shing Luk

# XOR centric

- In fact, George Boole at first suggested to use ({`0`,`1`}, `&`, `+`) as his algebra system, but then gave up later for some unknown reason.
    - NOT a = ~a = 1 + a
    - a AND b = a & b = a b
    - a XOR b = a + b
- a OR B = a | b = ~(~a & ~b) = 1 + (1 + a)(1 + b) = a + b + a b
- Boolean algebra is more intuitive for humans, but computers are not humans.
- In fact ancient geeks also use Boole's algebra.

---

# Why XOR

- XOR gate can be implemented effectively using *Pass-Transistor Logic* (PTL)
- 5~6 transistors. Good for both power and delay.
- It has already successfully been used in for example full adder, encryption processor, Gray code encoder/decoder etc.
- Pass-Transistor Logic is relatively expensive for simple monotonic gates such as NAND and NOR (Zimmermann and Fichtner 1997).
- CMOS + PTL = CPL
- In fact, **all Boolean functions can be implemented using simply XOR-AND-NEG gates without OR gates**.

---

# Rules

- x + x = 0

---

# Conjunctive normal form

Ex. f = (A | B | C)(~A | ~B | C)(~A | B | ~C)

---

# Challenges

- Lack of supporting EDA tools. Almost need to redo everything.

---

# Q & A 🗣️

