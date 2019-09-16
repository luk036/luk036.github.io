title: Lecture 2a: Software Development Tips
class: animation-fade
layout: true

---

class: center, middle

{{title}}
=========

Wai-Shing Luk

2019-09-18

---

💬 Messages
--------

-   Forget Matlab, embrace Python 🤔
-   Forget Perl, embrace Python 🤔
-   Forget C, embrace modern C++.
    -   Modern C++ is faster, safer, and cleaner. ✨✨✨
-   Forget C++, embrace Python 🤔
    -   Strategy: Python first, C++ follows.
-   Forget XML, embrace JSON.
-   Forget HTML/LaTeX, embrace Markdown 🤔
    -   Strategy: Markdown first, LaTeX follows.
-   Learn from good codes, not bad ones.
-   The last rescue: Google search.

---

Coding Tips
-----------

-   Test, test, test!!!
-   Write cleaner code
-   Refactor repeat codes
-   Object oriented programming
-   Generic programming
-   Design Pattern

---

Performance Tips
----------------

-   Avoid string comparison
-   Use cheaper measure, avoid `sqrt()`, `sin()`, `cos()`
-   Lazy evaluation
-   Table lookup
-   Avoid sequence search:
    -   Backward pointers
    -   Hash Table/Dictionary/Map

---

Avoid string comparison
-----------------------

.pull-left[

Bad 👎

```python
if pin == "input":
    # ...
elif pin == "output":
    # ...
elif pin == "in_out":
    # ...
elif pin == "dont_care":
    # ...
else:
    # ...
```

]

.pull-right[

Good 👍

```python
pin_type = dict(
  {"input":0}, {"output":1},
  {"in_out":2}, {"dont_care":3}
)
...

id = pin_type.get(pin, -1)
if id == 0:
    # ...
elif id == 1:
    # ...
elif id == 2:
    # ...
elif id == 3:
    # ...
else:
    # ...
```

]

---

Use cheaper measure
-------------------

.pull-left[

Bad 👎

```python
mind = 10000
maxd = 0
for u, v in G.edges:
    t = vec[u] - vec[v]
*   d = sqrt(t.dot(t))
    if mind > d: mind = d
    if maxd < d: maxd = d
*return maxd - mind
```

] .pull-right[

Good 👍

```python
minq = 10000
maxq = 0
for u, v in G.edges:
    t = vec[u] - vec[v]
*   q = t.dot(t)
    if minq > q: minq = q
    if maxq < q: maxq = q
*return sqrt(maxq)-sqrt(minq)
```

]

---

Another Example
---------------

.pull-left[

Bad 👎

```python
mind = 10000
maxd = 0
for u, v in G.edges:
*   t = 1 - vec[u].dot(vec[v])
*   d = arcsin(sqrt(t))
    if mind > d: mind = d
    if maxd < d: maxd = d

*return maxd - mind
```

] .pull-right[

Good 👍

```python
minq = 10000
maxq = 0
for u, v in G.edges:

*   q = 1 - vec[u].dot(vec[v])
    if minq > q: minq = q
    if maxq < q: maxq = q

*return arcsin(sqrt(maxq)) \
*        - arcsin(sqrt(minq))
```

]

---

Optimization Tips
-----------------

-   Convex optimization

-   Network optimization

---

class: center, middle

Q & A 🗣️
==========
