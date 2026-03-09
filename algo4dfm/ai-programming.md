layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Lecture 2b: Programming in the Age of AI 🤖

@luk036 👨‍💻

2025-9-17 📅

---

![The Earth Is Flat?](figs/the-earth-is-flat.png)

---

### Essential Coding Tips 💡

.pull-left[

- **Test rigorously** 🧪
- **Write clean, maintainable code** ✨
- **Refactor repetitive code** 🔄
- **Use object-oriented principles** 🧩
- **Apply generic programming** 🧠
- **Leverage design patterns** 🏗️
- **Utilize coroutines** 🔄
- **Study high-quality code** 📚
- **Search online as a last resort** 🔍

]

.pull-right[

![AI and Programming](figs/programming-in-the-age-of-ai.svg)

]

---

![Test, Test, Test!](figs/testtest.png)

---

### AI-Powered Code Generation Tools 🤖

- **AWS CodeWhisperer**
  - Automated test generation
- **Cody AI** (by Sourcegraph)
- **Gemini CLI** (by Google)

---

### Naming Best Practices:

- **Avoid single-letter names** ❌
  Example: `a, i, p, n`
- **Use meaningful names**:
  `x: unknown, x_axis`
- **Standard coordinate variables**:
  `x, y, z`

---

### Improved Naming Conventions 📛

- **p**: point, polygon, polynomial, previous
- **t**: time, target, temporary
- **c**: cost, cycle, coefficient
- **d**: distance, distribution
- **e**: edge
- **v**: vertex
- **u, v, w**: vertex1, vertex2, vertex3
- **i**: index
- **i, j**: row, column
- **i, j, k**: indices
- **l, m**: line1, line2
- **n**: dimension, node, next
- **n, m**: ndim, mdim
- **w**: weight, frequency (omega)

---

### Performance Optimization Tips 🚀

- **Avoid string comparisons** 🚫
- **Use sentinel values** 🛡️
- **Prefer cheaper computations** (avoid `sqrt()`, `sin()`, `cos()`) ⚡
- **Apply lazy evaluation** 🦥
- **Use table lookups** 📚
- **Avoid linear searches**:
  - Use backward pointers 🔙
  - Use hash tables, dictionaries, or maps

---

### Avoid String Comparisons 🚫

.pull-left[

**Inefficient Approach** 👎

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

**Optimized Approach** ⚡

```python
pin_type = {
    "input": 0,
    "output": 1,
    "in_out": 2,
    "dont_care": 3
}
id = pin_type.get(pin, -1)

if id == 0:
    # ...
elif id == 1:
    # ...
else:
    # ... (handle other cases)
```

]

---

### Sentinel Pattern 🛡️

.pull-left[

**Less Efficient** 👎

.font-sm.mb-xs[

```python
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

]

.pull-right[

**Optimized with Sentinel** ⚡

.font-sm.mb-xs[

```python
max = 0
sentinel = Dllink()
bckt = [Dllist() for _ in range(high+1)]
bckt[0].append(sentinel)  # Sentinel

def popleft():
    res = bckt[max].popleft()
    while bckt[max].empty():
        max -= 1
    return res
# No boundary check needed
```

]

]

---

### Optimize Computations ⚡

.pull-left[

**Inefficient** 👎

```python
mind = 10000
maxd = 0
for u, v in G.edges():
    t = vec[u] - vec[v]
    d = sqrt(t.dot(t))
    if mind > d: mind = d
    if maxd < d: maxd = d
return maxd - mind
```

]

.pull-right[

**Optimized** ⚡

```python
minq = 10000
maxq = 0
for u, v in G.edges():
    t = vec[u] - vec[v]
    q = t.dot(t)  # Cheaper operation
    if minq > q: minq = q
    if maxq < q: maxq = q
return sqrt(maxq) - sqrt(minq)
```

]

---

### Another Optimization Example ⚡

.pull-left[

**Inefficient** 👎

```python
mind = 10000
maxd = 0
for u, v in G.edges():
    t = 1 - vec[u].dot(vec[v])
    d = arcsin(sqrt(t))
    if mind > d: mind = d
    if maxd < d: maxd = d
return maxd - mind
```

]

.pull-right[

**Optimized** ⚡

```python
minq = 10000
maxq = 0
for u, v in G.edges():
    q = 1 - vec[u].dot(vec[v])
    if minq > q: minq = q
    if maxq < q: maxq = q
return arcsin(sqrt(maxq)) \
       - arcsin(sqrt(minq))
```

]

---

### Advanced Optimization Techniques 🧮

- **Convex optimization** 🥚
- **Network optimization** 🖧
- **Primal-dual methods** ☯

---

class: nord-dark, middle, center

.pull-left[

# Q&A 🎤

]

.pull-right[

![Q&A](figs/questions-and-answers.svg)

]
