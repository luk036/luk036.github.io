%title Algebra of Boole
%author Wai-Shing Luk

# XOR centric

- In fact, George Boole at first suggested to use ({`0`,`1`}, `&`, `+`) as his algebra
    system, but then gave up later for some unknown reason.
- `f` = `1 + a + a & b + a & b & c`
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

# Challenges

- Lack of supporting EDA tools. Almost need to redo everything.

---

# Q & A 🗣️

