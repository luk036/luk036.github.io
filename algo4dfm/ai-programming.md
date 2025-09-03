layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Lecture 2b: Programming in the Age of AI 🤖

@luk036 👨‍💻

2025-9-17 📅

---

![image](figs/the-earth-is-flat.png)

---

### Coding Tips 💡💻

.pull-left[

- Test, test, test!!! 🧪
- Write cleaner code ✨
- Refactor repeat codes 🔄
- Object-oriented programming 🧩
- Generic programming 🧠
- Design Patterns 🏗️
- Coroutines are your friends 🔄
- Learn from good code, not bad ones 📚
- The last resort: Google search 🔍

] .pull-right[

![image](figs/programming-in-the-age-of-ai.svg)

]

---

![image](figs/testtest.png)

---

### AI Code Generation Tools 🤖

- **AWS CodeWhisperer**
  - Automated test generation
- **Cody AI** (Sourcegraph)
- **Gemini CLI** (Google)

---

### Documentation Generation 📝

- **Cody AI** (Sourcegraph)

### Naming Best Practices:
- Avoid single-letter names ❌
  `a, i, p, n`
- Example equation: 📚
  `A x = b`
- Good names:
  `x: unknown, x_axis`
- Coordinate variables:
  `x, y, z`

---

### Better Naming Conventions 📛

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

### Performance Optimization Tips 🚀

- Avoid string comparisons 🚫
- Use sentinel values 🛡️
- Use cheaper computations (avoid `sqrt()`, `sin()`, `cos()`) ⚡
- Lazy evaluation 🦥
- Table lookups 📚
- Avoid sequence searches: 🔍
  - Backward pointers 🔙
  - Hash Tables/Dictionaries/Maps

---

### Avoid String Comparisons 🚫

.pull-left[

Bad Practice 👎

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

Better Practice ⚡

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
    # ... (rest of conditions)
```

]

---

### Sentinel Pattern 🛡️

.pull-left[

Suboptimal 👎

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

] .pull-right[

Optimized ⚡

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
# Eliminated boundary check
```
]

]

---

### Cheaper Computations ⚡

.pull-left[

Inefficient 👎

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

Optimized ⚡

```python
minq = 10000
maxq = 0
for u, v in G.edges():
    t = vec[u] - vec[v]
    q = t.dot(t)  # Cheaper
    if minq > q: minq = q
    if maxq < q: maxq = q
return sqrt(maxq) - sqrt(minq)
```

]

---

### Another Optimization Example ⚡

.pull-left[

Inefficient 👎

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

Optimized ⚡

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

- Convex optimization 🥚
- Network optimization 🖧
- Primal-dual paradigm ☯

---

class: nord-dark, middle, center

.pull-left[

# Q & A️ 🙋

] .pull-right[

![image](figs/questions-and-answers.svg)

]
