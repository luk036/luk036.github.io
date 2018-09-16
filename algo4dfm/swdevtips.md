title: Lecture 2b: Software Development Tips
class: animation-fade
layout: true

---

class: center, middle

{{title}}
=========

Wai-Shing Luk

2018-09-20

---

## Messages

- Forget Matlab, embrace Python.
- Forget all C++ textbooks, embrace modern C++.
- Modern C++ has become more Pythonic today.
- Strategy 1: Python first, C++ follows.
- Embrace Markdown.
- Strategy 2: Markdown first, LaTeX follows.
- Learn from good codes, not bad ones.
- The last rescue: Google search.

---

## Coding Tips

- Unit Testing
- Write cleaner code
- Refactor repeat codes
- Object oriented programming
- Generic programming
- Design Pattern

---

## Performance Tips

- Avoid string comparison
- Use cheaper measure, avoid `sqrt()`, `sin()`, `cos()`
- Lazy evaluation
- Table lookup
- Avoid sequence search:
    - Backward pointers
    - Hash Table/Dictionary/Map

---

## Avoid string comparison

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

## Use cheaper measure

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
]
.pull-right[

Good 👍

```python
mind = 10000
maxd = 0
for u, v in G.edges:
    t = vec[u] - vec[v]
*   d = t.dot(t)
    if mind > d: mind = d
    if maxd < d: maxd = d
*return sqrt(maxd)-sqrt(mind)
```
]

---

## Another Example

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
]
.pull-right[

Good 👍

```python
mind = 10000
maxd = 0
for u, v in G.edges:

*   d = 1 - vec[u].dot(vec[v])
    if mind > d: mind = d
    if maxd < d: maxd = d

*return arcsin(sqrt(maxd)) \ 
*        - arcsin(sqrt(mind))
```
]

---

## Optimization Tips

- Convex optimization
- Network optimization
