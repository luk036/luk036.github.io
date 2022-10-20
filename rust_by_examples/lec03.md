layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Lecture 3: Template and Generic programming

---

## vector2 (python)

```python
class vector2:
    def __init__(self, x, y):
        self._x = x
        self._y = y

    def copy(self):
        return vector2(self._x, self._y)

    @property
    def x(self):
        return self._x

    @property
    def y(self):
        return self._y
    ...
```

---

## vector2 (C++)

```cpp
template <typename T = int>
class vector2 {
  private:
    T _x, _y;

  public:
    vector2(T x, T y) noexcept
    : _x {move(x)}, _y {move(y)} {}

    auto x() const noexcept -> const T& {
        return this->_x; }

    auto y() const noexcept -> const T& {
        return this->_y; }
    ...
};
```

---

## point (python)

```python
class point:
    ...
    def __isub__(self, rs: vector2):
        self._x -= rs.x
        self._y -= rs.y
        return self

    def __sub__(self, rs):
*       if isinstance(rs, vector2):
            tmp = self.copy()
            return tmp.__isub__(rs)
        elif isinstance(rs, point):
            return vector2(self.x - rhs.x, self.y - rhs.y)
        else:
            raise NotImplementedError()
```

---

## point (C++)

```cpp
template <typename T1, typename T2 = T1>
class point {
    ...
    point& operator-=(const vector2<T1>& rs)
    {   this->_x -= rhs.x();
        this->_y -= rhs.y();
        return *this; }

    point operator-(const vector2<T1>& rs) const
    {   auto tmp{*this};
        return tmp -= rs; }

    vector2<T1> operator-(const point& q) const
    {   return {this->x() - q.x(),
                this->y() - q.y()}; }
};
```

---

## interval (python)

```python
class interval:
    def __init__(self, lr, ur):
        self._lr = lr  # lower
        self._ur = ur  # upper
    ...

    def __lt__(self, a) -> bool:
        if isinstance(a, interval):
            return self.ur < a.lr
        return self.ur < a

    def contains(self, a) -> bool:
        if isinstance(a, interval):
            return not (a.lr < self.lr or self.ur < a.ur)
        return not (a < self.lr or self.ur < a)
```

---

## interval (C++)

```cpp
template <typename T = int>
class interval {
    auto operator<(const T& a) const -> bool
    { return this->ur() < a; }

    template <typename U>
    bool operator<(const interval<U>& a) const
    { return this->ur() < a.lr(); }

    auto contains(const T& a) const -> bool
    { return !(a < this->lr() || this->ur() < a); }

    template <typename U>
    bool contains(const interval<U>& a) const
    { return !(a.lr() < this->lr() || this->ur() < a.ur()); }
};
```

---

## rectangle (python)

```python
class rectangle(point):
    def __init__(self, x, y):
        point.__init__(self, x, y)

    @property
    def lr(self) -> point:
        return point(self.x.lr, self.y.lr)

    @property
    def ur(self) -> point:
        return point(self.x.ur, self.y.ur)

    # `a` can be point or rectangle
    def contains(self, a) -> bool:
        return self.x.contains(a.x) and self.y.contains(a.y)
```

---

## rectangle (C++)

```cpp
template <typename T = int>
struct rectangle : point<interval<T>> {
    rectangle(interval<T> x, interval<T> y)
      : point<interval<T>>{move(x), move(y)} { }

    auto lr() const -> point<T>
    { return {this->x().lr(), this->y().lr()} }

    auto ur() const -> point<T>
    { return {this->x().ur(), this->y().ur()} }

    // `a` can be point, rectangle, or segemnt
    template <typename U1, typename U2>
    bool contains(const point<U1, U2>& a) const
    { return this->x().contains(a.x()) && this->y().contains(a.y()); }
};
```

---

## vsegment (python)

```python
class vsegment(point):
    def __init__(self, x, y):
        point.__init__(self, x, y)

    # `a` can be point or vsegment
    def contains(self, a) -> bool:
        return self.x == a.x \
            and self.y.contains(a.y)
```

---

## vsegment (C++)

```cpp
template <typename T = int>
struct vsegment : point<T, interval<T>> {
    vsegment(T x, interval<T> y)
      : point<T, interval<T>>{x, move(y)} { }

    template <typename U>
    bool contains(const point<U>& a) const
    { return this->x() == a.x()
          && this->y().contains(a.y()); }
};
```

---

## Testing (python)

```python
if __name__ == '__main__':
    p = point(3, 4)
    intv1 = interval(2, 8)
    intv3 = interval(1, 10)
    R = rectangle(intv1, intv3)
    vseg = vsegment(4, intv1)
    hseg = hsegment(intv3, 11)

    assert R.contains(p)
    assert R.contains(R)
    assert R.contains(vseg)
    assert not R.contains(hseg)
```

---

## Testing (C++)

```cpp
int main()
{
    auto p = point(3, 4);
    auto intv1 = interval(2, 8);
    auto intv3 = interval(1, 10);
    auto R = rectangle(intv1, intv3);
    auto vseg = vsegment(4, intv1);
    auto hseg = hsegment(intv3, 11);

    assert(R.contains(p));
    assert(R.contains(R));
    assert(R.contains(vseg));
    assert(!R.contains(hseg));
}
```

---

## Conclusion

- Template, overloading and inheritance reduce code complexity
- Python cannot write generic code as C++
    - Built-in types (int, float, bool) are different from
      container types (list, dict and all class object) 
    - No operator/function overloading

---

## Source code

Python:

$ wget https://github.com/luk036/physdespy/blob/master/src/physdespy/recti.py

C++:

$ wget https://github.com/luk036/physdes/blob/master/lib/include/recti/recti.hpp

---

class: nord-dark, center, middle

# Q & A 🗣️
