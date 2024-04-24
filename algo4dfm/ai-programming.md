layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Lecture 2b: Programming in the Age of AI 🤖

.pull-left[

## @luk036

2023-09-13

] .pull-right[

![image](figs/programming-in-the-age-of-ai.svg)

]

---

## Coding Tips 💡

- Test, test, test!!!
- Write cleaner code
- Refactor repeat codes
- Object oriented programming
- Generic programming
- Design Pattern
- Coroutine is your friend
- Learn from good codes, not bad ones.
- The last rescue: Google search.

---

## Code generation

- AWS CodeWhisperer (VSCode's extension)
  - generate testing code

---

## Documentation generation

Mintlify (VSCode's extension)

- Naming
- a, i, p, n ❌
- A x = b
- x: unknown, x_axis
- x, y, z

---

## Use better variable names

- p: point, polygon, polynomial, prev
- t: time, target, temp
- c: cost, cycle, coefficient
- d: distance, distribution
- e: edge
- v: vertex
- u, v, w: vertex1, vertex2
- i: index
- i, j: row, col
- i, j, k
- l, m: line1, line2
- n: dimension, node, next
- n, m: ndim, mdim
- w: weight, frequence (omega)

---

## 🚀 Performance Tips 💡

- Avoid string comparison
- Use sentinel
- Use cheaper measure, avoid `sqrt()`, `sin()`, `cos()`
- Lazy evaluation
- Table lookup
- Avoid sequence search:
  - Backward pointers
  - Hash Table/Dictionary/Map

---

## Avoid string comparison

.pull-left[

Bad 👎:

```{.python}
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

Better ⚡:

```{.python}
pin_type = dict({"input":0},
  {"output":1}, {"in_out":2},
  {"dont_care":3})
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

## Use Sentinel

.pull-left[

Bad 👎:

.font-sm.mb-xs[

```{.python}
max = 0
bckt = [Dllist() for _ in range(high)]
# ...
def popleft():
    res = bckt[max].popleft()
    while max >= 0 and bckt[max].empty():
        max -= 1
    return res
```

]

] .pull-right[

Better ⚡:

.font-sm.mb-xs[

```{.python}
max = 0
sentinel = Dllink()
bckt = [Dllist() for _ in range(high+1)]
bckt[0].append(sentinel)  # sentinel
# ...
def popleft():
    res = bckt[max].popleft()
    while bckt[max].empty():
        max -= 1
    return res
# Saved a boundary check `max >= 0`
```

]

]

---

## Use cheaper measure

.pull-left[

Bad 👎:

```{.python}
mind = 10000
maxd = 0
for u, v in G.edges():
    t = vec[u] - vec[v]
*   d = sqrt(t.dot(t))
    if mind > d: mind = d
    if maxd < d: maxd = d
*return maxd - mind
```

] .pull-right[

Better ⚡:

```{.python}
minq = 10000
maxq = 0
for u, v in G.edges():
    t = vec[u] - vec[v]
*   q = t.dot(t)
    if minq > q: minq = q
    if maxq < q: maxq = q
*return sqrt(maxq) - sqrt(minq)
```

]

---

## Another Example

.pull-left[

Bad 👎:

```{.python}
mind = 10000
maxd = 0
for u, v in G.edges():
*   t = 1 - vec[u].dot(vec[v])
*   d = arcsin(sqrt(t))
    if mind > d: mind = d
    if maxd < d: maxd = d

*return maxd - mind
```

] .pull-right[

Better ⚡:

```{.python}
minq = 10000
maxq = 0
for u, v in G.edges():
*   q = 1 - vec[u].dot(vec[v])
    if minq > q: minq = q
    if maxq < q: maxq = q

*return arcsin(sqrt(maxq)) \
*        - arcsin(sqrt(minq))
```

]

---

## Optimization Tips 💡

- Convex optimization

- Network optimization

- Primal-dual paradigm

---

class: nord-dark, middle, center

.pull-left[

# 🙋 Q & A️

] .pull-right[

![image](figs/questions-and-answers.svg)

]
