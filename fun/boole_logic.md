%title: Boole's Logic and Circuit Analysis

# MF151 A brief history of logic: Aristotle and deduction

## A brief foray into 'philosophy' 

**logic** ~= the study of valid techniques of inference,
or drawing conclusions from premises

Early schools of Indian & Chinese
logic In ancient Greece, Zeno (490-430 B.C.E)
& Parmenides used 'reduc absurdum' arguments,
and  'de; involing

---

## Plato (428-348 B.C.E.)

- student of Socrates, teacher of Aristotle, and
the founder of modern philosophy &

---

## Aristotle (384-322 B.C.E.)

- tutor of Alexander the Greate
- wrote on biology, physics, metaphysics,
  poetry, ethics, psychology, linguistics,
  economics, ... and **logic**
The Organon - 6 books on logic.
 mature influential works from the
 initiator of the subject.

---

Modern statment: (sets)
'If every B is and A, and every
C is a B, then every C is an A.'
 A a B; B a C => A a C

Aristotle's statement: (types)
' If A belongs to all B, and
     B belongs to all C, then
     A belongs to all C.'
     
---

## Four logical forms [Propositions]

A a B: 'A belongs to all B' or
          'Every B is an A'
A e B: 'A belongs to no B' or
           'No B is an A'
A i B: 'A belongs to some B' or
           'Some B is an A'
A o B: 'A does not belong to some B' or
           'Some B is not an A'

---

Syllogism: "discourse in which certain
things being stated, something else follows"
        Premise 1 + Premise 2 => Conclusion
 A a B, B a C |- A a C     B

---

A e B, A a C |- B e C      Cesare
A a B, A e C |- B e C      Camestres
A e B, A i C |- B o C      Festino
A a B, A o C |- B o C      Baroco

Ex. All informative things are useful. Some
   books are not useful

---

Aristotle did not write on maths.
But he discussed 'infinity': distinguished
between 'potential' & 'actual' infinity.
Wrote  that mathenaticians 'do not
  need infinity or use it.'

Plato: there are 2 worlds, real & ideal
Aristotle: there is only 1 world, with
matter & form

---

# MF252: A brief history of logic:

---

Zeno's logic was influenced by the
Megarians: perception => assent =>

---

Aristotle's logic: All A ("subject') are B ("predicate")
    A B terms: 
  Stoic logic: If p then q [implication]
                Both p and q [conjunction]
              Either p or q [disjunction]
         p, q propositions  (logical connectives)
 * Exclusive "or": night or day
							    red or flat ??? 
---

## The five indemonstrable forms

- If p then q; p; therefore q (Modus Ponens)
- If p then q; p; not q; \therfore not p (Modus Tollens)
- not (p and q); p; \therefore not q
- **Either p or q; p; \therefore not q**
- Either p or q; not p; \therefore q

---

## The "law of excluded middle"

Q. Is the statement 'p or not p' necessarily true?
A. It depends who you ask!

Aristotle: p: A sea battle will take place tomorrow
          not p: A sea battle will not take place tomorrow
Is 'p or not p' true today?

---

The Stoics leaned towards dterminism [limited "free will"]

p  | not p
---|------
T  |  F
F  |  T

p | q | 
--|---|
T | T |
T | F |
F | T |
F | F |

---

## The temporal aspect of 'truth'

If the statement 'It is warm today'
is true, will it retain its truth for ever (i.e. in 6 months)?
We tend to new statements as
' , so truth is maintained.
Stotic

p | q | If p then q
--|---|-------------
T | T |      T
T | F |      F
F | T |      T
F | F |      T

The Stoic & modern interpretations agree.

---

## The Megarian school of philosophy

Founded by Euclides of Megara,
followed by Ichthyas & Stilpo [4th
 century B.C.E.] -> influenced Stoics
 Diodorus: what is possible is limited
 to what is, or will be true in the future
 the nature of 'truth'?
Sadly the Stoics/Megarian way
  decline till recently.

---

## The nature of implication

'If p then q'



---

# MF255: The Algebra of Boole is not Boolean Algebra!

Georage Boole (1815 - 1864) 'The Mathe

Ex. Consider a (small) popuation of Humans, Gods, Athletes, some of whom
are noble and/or keen

Humans  Y Y Y Y N
Gods       N N Y N Y
Athletes  Y N Y N N
                o o o o o
noble      N Y N N Y
keen       N Y N N N

---

Instead of subjects & predicates, we only consider a (universal) population and
attributes/properties

human   1 1 1 1 0
god        N N Y N Y
athletes  Y N Y N N
noble      N Y N N Y
keen       N Y N N N

The Bifield B2 \equiv {0, 1} 0 + x = x, 1y = y

addition
+ 0 1
0 0 1    
1 1 0

---

multiplication
x 0 1
0 0 0
1 0 1

x + y &=& y + x
x y &=& y x
(x + y) + z = x + (y + z)
(x y) z = x (y z)
x + x = 0 (so not a field-also no x-y or x/y)

Additive inverses: For any x, there is y with
 x + y = y + x = 0
 Multiplicative inverses: For any x != 0, there is y with
  
---

The algebra B(5, 2) (or B(n, 2), n = 1, 2, \cdots)
 B(5, 2) = {(b1, b2, b3, b4, b5): bi \in B2, i=1,2,3,4,5}
Point-wise operations
(b1, b2, b3, b4, b5) + (c1, c2, c3, c4, c5) \equiv (b1+c1, b2+c2, b3+c3, b4+c4, b5+c5)
(b1, b2, b3, b4, b5) x (c1, c2, c3, c4, c5) \equiv (b1 c1, b2 c2, b3 c3, b4 c4, b5 c5)
???
Ex. If h=(1,1,1,1,0), g=(0,0,1,0,1) then
h + g = (1,1,0,1,1) [h xor g] - 'exclusive or' ['Stoic or']
h g = (0,0,1,0,0) [h and g]

---

Properties of the bifield algebra B(5, 2)
-----------------------------------------------

If p, q, r \in B(5, 2) then 
	p + q = q + p
	p q = q p
	(p + q) + r = p + (q + r)
	p (q + r) = pq + pr
	(p + q)r = pr + qr
With
   0 ≡ (0,0,0,0,0)
  1 ≡ (1,1,1,1,1)
\lambda ......

---

1. Every p is a q <=> p q = p (Leibniz!)
Ex. If h = (1,1,1,1,0) and a = (1,0,1,0,0)
then every athlete is a human, i.e.
whenever a(i) = 1, h(i)=1. So
   a h = (1,0,1,0,0) x (1,1,1,1,0) = (1,0,1,0,0) = a
    
2. No p is a q <=> p q = 0
Ex. If n = (0,1,0,0,1)
then no athlete is noble, i.e.
whenever a(i) = 1, n(i)=0. So
   a n = (1,0,1,0,0) x (0,1,0,0,1) = (0,0,0,0,0) = 0 

---
   
3. Some p is a q <=> p q != 0
Ex. If h = (1,1,1,1,0) and n = (0,1,0,0,1)
then some human is noble, i.e. for some i,
h(i) = a(i) = 1, h(i)=1, namely i=2. So
   h n = (1,1,1,1,0) x (0,1,0,0,1) = (0,1,0,0,0) != 0

4. Some p is not a q <=> p (1 + q) != 0
Ex. Some human is not noble since
   h (1 + n) = (1,1,1,1,0) x (1,0,1,1,0) = (1,0,1,1,0) != 0 


---

MF278: A systematic approach to logic deduction, & the Boole-Mobius transform

(A v B) -> (C <-> A)
(A <-> B) -> (~A v B) ^ C
[(A ^ B) v (~C)] ^ ( B -> C)
 ----------------------------
C -> B

1 + A + AC + BC + ABC
A + B + C + AC
 ----------------------------

---

Today we present an alternative technology for deriving deductions -
using the **Boole-Mobius transform**.
Thish provides a direct link between Boole

---

Ex. Truth table for Y=(A<->B)->(~A v B) ^ C


C  B  A    |  (A <-> B)    ->     (~A v B)   ^   C
-----------|--------------------------------------
0  0  0    |      1         0         1      0   0
0  0  1    |      0         1         0      0   0
0  1  0    |      0         1         1      0   0
0  1  1    |      1         0         1      0   0
1  0  0    |      1         1         1      1   1
1  0  1    |      0         1         0      0   1
1  1  0    |      0         1         1      1   1
1  1  1    |      1         1         1      1   1

---

Now converting:
Y = A + B + C + AC + BC

> Written with [StackEdit](https://stackedit.io/).
