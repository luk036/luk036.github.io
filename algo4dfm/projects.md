title: Final Years Projects
class: animation-fade
layout: true

---

class: center, middle

{{title}}
=========

Wai-Shing Luk

2020-05-31

---

## 为什么选择MyHDL？

- 数字滤波器的设计和硬件中的实现通常是两个阶段的过程，在Python、Matlab或Java等语言中进行算法开发，在VHDL或Verilog等硬件描述语言中进行RTL设计。这就需要在这两个环境之间来回走动多次，检查硬件设计是否符合要求的规范。让人兴奋的是MyHDL能在同一个Python环境中开发算法和RTL设计。
- MyHDL的另一个方面是，设计可以自动转换为Verilog和VHDL中的等效代码，使语言中立的设计成为可能。

---

## 为什么选择PyFDA？

进一步说，将MyHDL和PyFDA连接起来有更多的好处。这种组合可以填补算法开发和HDL fixpoint块之间的开源工具链的空白，这将消除对Mathworks hdl-coder等商业授权工具的需求。







---

💬 Messages (I)
----------------

-   About 99% projects fail.
-   Software is "soft"; Hardware is "hard"
-   Automation is hard
-   Nightly build concept (Microsoft)
-   Agile software development
-   Pair programming
-   Extreme programming
-   Opensource projects - Continuous Integration

---

💬 Messages (II)
----------------

-   Forget about Matlab, embrace Python 🤔
-   Forget about Perl, embrace Python 🤔
-   Forget about C, embrace modern C++.
    -   Modern C++ is faster, safer, and cleaner. ✨✨✨
-   Forget about C++, embrace Python 🤔
    -   Strategy: Python first, C++ follows.
-   Forget about XML, embrace [JSON](https://json.org/).
-   Forget about HTML/LaTeX, embrace Markdown 🤔
    -   Strategy: Markdown first, LaTeX follows.
-   Forget about Verilog, embrace [MyHDL](http://www.myhdl.org/)

---

Coding Tips
-----------

-   Test, test, test!!!
-   Write cleaner code
-   Refactor repeat codes
-   Object oriented programming
-   Generic programming
-   Design Pattern
-   Coroutine is your friend
-   Learn from good codes, not bad ones.
-   The last rescue: Google search.

---

Performance Tips
----------------

-   Avoid string comparison
-   Use sentinel
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

Use Sentinel
------------

.small[ .pull-left[

Bad 👎

```python
max = 0
bucket = [dllink(0) for _ in range(high)]
# ...
def popleft():
    res = bucket[max].popleft()
    while max >= 0 and bucket[max].is_empty():
        max -= 1
    return res
```

] .pull-right[

Good 👍

```python
max = 0
sentinel = dllink(0)
bucket = [dllink(0) for _ in range(high + 1)]
bucket[0].append(sentinel)  # sentinel
# ...
def popleft():
    res = bucket[max].popleft()
    while bucket[max].is_empty():
        max -= 1
    return res
# Saved a boundary check `max >= 0`
```

] ]

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
