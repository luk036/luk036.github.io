layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

```
🍉🍉🍉🥝🥝🍉🍉🍉🍇🍇🍇🥝🥝🍇🍇🍇🍌🍌🍌🥝🥝🍌🍌🍌🍉🍉🍉🥝🥝🍉🍉🍉🍇🍇🍇🥝🥝🍇🍇🍇🍌🍌🍌🥝🥝🍌🍌🍌
🍌🍌🥝🍉🍉🥝🍇🍇🍉🍉🥝🍇🍇🥝🍌🍌🍇🍇🥝🍌🍌🥝🍉🍉🍌🍌🥝🍉🍉🥝🍇🍇🍉🍉🥝🍇🍇🥝🍌🍌🍇🍇🥝🍌🍌🥝🍉🍉
🍇🥝🍌🍌🍇🍇🥝🍌🍌🥝🍉🍉🍌🍌🥝🍉🍉🥝🍇🍇🍉🍉🥝🍇🍇🥝🍌🍌🍇🍇🥝🍌🍌🥝🍉🍉🍌🍌🥝🍉🍉🥝🍇🍇🍉🍉🥝🍇
🥝🍇🍇🍇🍌🍌🍌🥝🥝🍌🍌🍌🍉🍉🍉🥝🥝🍉🍉🍉🍇🍇🍇🥝🥝🍇🍇🍇🍌🍌🍌🥝🥝🍌🍌🍌🍉🍉🍉🥝🥝🍉🍉🍉🍇🍇🍇🥝
```

Coroutine and Enumerative Combinatoric Generator 
================================================

@luk036
-------------

---

Why coroutine?
-------------

-   Enable recursive generators
-   Enable "iterator" from recursive generators

---

Why Gray code?
----------------

-   Do not need to return the whole list from the generator

---

Binary Reflected Gray Code (python)
--------------------------

```python
def BRGC_gen(n):
    if n == 1:
        yield 0
        return
    yield from BRGC_gen(n - 1)
    yield n - 1
    yield from BRGC_gen(n - 1)


def BRGC(n):
    lst = list(0 for _ in range(n))
    yield lst
    for i in BRGC_gen(len(lst)):
        lst[i] = 1 - lst[i]  # flip
        yield lst
```

---

Steinhaus-Johnson-Trotter (SJT, old)
-------------------------

```python
def SJT_old(n):
    if n == 2:
        yield [0, 1]
        yield [1, 0]  # tricky part: return to the origin
        return

    gen = SJT_old(n - 1)
    for pi in gen:
        for i in range(n - 1, -1, -1):  # downward
            yield pi[:i] + [n - 1] + pi[i:]
        pi = next(gen)
        for i in range(n):  # upward
            yield pi[:i] + [n - 1] + pi[i:]
```

---

Steinhaus-Johnson-Trotter (SJT, new)
-------------------------

```python
def SJT_gen(n):
    """Generate the swaps for the SJT algorithm."""
    if n == 2:
        yield 0
        yield 0  # tricky part: return to the origin
        return

    gen = SJT_gen(n - 1)
    for x in gen:
        for i in range(n - 2, -1, -1):  # downward
            yield i
        yield x + 1
        for i in range(n - 1):  # upward
            yield i
        yield next(gen)  # tricky part


def SJT(n):
    perm = list(range(n))
    for x in SJT_gen(n):
        yield perm
        perm[x], perm[x + 1] = perm[x + 1], perm[x]
```

