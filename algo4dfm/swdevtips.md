layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# Lecture 2a: Software Development Tips 💡

@luk036 👨‍💻

2022-09-14 📅

---

## 🐉 Myths of Software Development

- Computers are smart
- C is fast; C++ is slow
- I love programming

---

## 💬 Messages (I)

- About 99% projects fail.
- Software is "soft"; Hardware is "hard"
- Automation is hard
- Nightly build concept (Microsoft)
- Agile software development
- Pair programming
- Extreme programming
- Opensource projects - Continuous Integration

---

## 💬 Messages (II)

- Forget about Matlab, embrace Python 🤔
- Forget about Perl, embrace Python 🤔
- Forget about C, embrace modern C++.
  - Modern C++ is faster, safer, and cleaner. ✨✨✨
- Forget about C++, embrace Python 🤔
  - Strategy: Python first, C++ follows.
- Forget about XML, embrace [JSON](https://json.org/).
- Forget about HTML/LaTeX, embrace Markdown 🤔
  - Strategy: Markdown first, LaTeX follows.
- Forget about Verilog, embrace [MyHDL](http://www.myhdl.org/)

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

## 🚀 Performance Tips 💡

- Avoid string comparison
- Use sentinel
- Use cheaper measure, avoid `sqrt()`, `sin()`, `cos()`
- 🦥 Lazy evaluation
- Table lookup
- Avoid sequence search:
  - Backward pointers
  - Hash Table/Dictionary/Map

---

## Avoid string comparison

.pull-left[

Bad 👎:

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

Better ⚡:

```python
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

Better ⚡:

.font-sm.mb-xs[

```python
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

] .pull-right[

Better ⚡:

```python
minq = 10000
maxq = 0
for u, v in G.edges():
    t = vec[u] - vec[v]
    q = t.dot(t)
    if minq > q: minq = q
    if maxq < q: maxq = q
return sqrt(maxq) - sqrt(minq)
```

]

---

## Another Example

.pull-left[

Bad 👎:

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

] .pull-right[

Better ⚡:

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

## Optimization Tips 💡

- Convex optimization

- Network optimization

- Primal-dual

---

class: nord-dark, middle, center

# Q&A 🎤
