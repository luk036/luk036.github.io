title: Design Patterns in Modern C++
class: animation-fade
layout: true

<!-- This slide will serve as the base layout for all your slides -->
.bottom-bar[
  {{title}}
]

---

class: impact

{{title}}
=========

Wai-Shing Luk
-------------

---

Agenda
======

1.  Introduction
2.  Strategy
3.  Template Method
4.  Decorator
5.  Factory
6.  Façade
7.  Factory
8.  Adapter

---

# Strategy

- Defines a family of algorithms, encapsulates each one, 
  and makes them interchangeable.
- Strategy lets the algorithm vary indepedently from clients
  that use it.
- Principle: Favor composition over inheritance.

---

Strategy Example
----------------

.small[

.col-6[
Dynamic/virtual method:

```cpp

struct DMEHlpr {
  DelayCalc& _c;
  DMEHlpr(DelayCalc& c) : _c{c} {}
  void embed() { 
    // ...
    _c.calc();
    // ...
  }
};

struct LinearCalc : DelayCalc {
  double calc() final;  // virtual 
};
struct ElmoreCalc : DelayCalc {
  double calc() final;  // virtual
};
```
]

.col-6[
Static/template method:

```cpp
template <class DelayCalc>
struct DMEHlpr {
  DelayCalc _c;
  void embed() { 
    // ...
    _c.calc();
    // ...
  }
};

struct LinearCalc {
  double calc();
};
struct ElmoreCalc {
  double calc();
};
```

]

]

---

Template Method
----------------

- While Strategy uses composition, Template Method uses inheritance.

---

Template Method Example
-----------------------

.small[

.col-6[

Dynamic/virtual method:

```cpp

struct DMEHlpr {
  virtual build_segment() = 0; 
  void embed() { 
    this->build_segment();
    // ...
  }
};

struct MMMHlpr : DMEHlpr {
  void build_segment() final;
};

struct LRFHlpr : DMEHlpr {
  void build_segment() final;
};
```
]

.col-6[

Static/template method:

```cpp
template <class Derived>
struct DMEHlpr {
  using cDer = const Derived;
  cDer& self = *static_cast<cDer*>(this);
  void embed() { 
    self.build_segment();
    // ...
  }
};

struct MMMHlpr : DMEHlpr<MMMHlpr> {
  void build_segment();
};

struct LRFHlpr : DMEHlpr<LRFHlpr> {
  void build_segment();
};
```

]

]


---

Decorator ???
----------------

.small[

.col-6[

Dynamic/virtual method:

```cpp
struct ck {
  virtual L _perp(const _P &) const = 0;
  virtual P _perp(const _L &) const = 0;

  L altitude(const P &p, const L &l) const 
  { return p * _perp(l); }
};

struct hyck : ck {
  L _perp(const P &v) const final
  { return L(v[0], v[1], -v[2]); }

  P _perp(const L &v) const final
  { return P(v[0], v[1], -v[2]); }
};
```
]

.col-6[

Static/template method:

```cpp
template <class Derived>
struct ck {
  using cDer = const Derived;
  cDer& self = *static_cast<cDer*>(this);

  L altitude(const P &p, const L &l) const
  { return p * self._perp(l); }
};

*struct hyck : ck<hyck> {
  L _perp(const P &v) const 
  { return L(v[0], v[1], -v[2]); }

  P _perp(const L &v) const 
  { return P(v[0], v[1], -v[2]); }
};
```

]

]

