layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Lecture 3: Template and Generic programming

@luk036

---

## Vector2 (Python 🐍)

```python
class Vector2:
    def __init__(self, x, y):
        self._x = x
        self._y = y

    def copy(self):
        return Vector2(self._x, self._y)

    @property
    def x(self):
        return self._x

    @property
    def y(self):
        return self._y
    ...
```

---

## Vector2 (C++)

```cpp
template <typename T = int>
class Vector2 {
  private:
    T _x, _y;

  public:
    Vector2(T x, T y) noexcept
    : _x {move(x)}, _y {move(y)} {}

    auto x() const noexcept -> const T& {
        return this->_x;
    }

    auto y() const noexcept -> const T& {
        return this->_y;
    }
    ...
};
```

---

## Point (Python 🐍)

```python
class Point:
    ...
    def __isub__(self, rs: Vector2):
        self._x -= rs.x
        self._y -= rs.y
        return self

    def __sub__(self, rs):
        if isinstance(rs, Vector2):
            tmp = self.copy()
            return tmp.__isub__(rs)
        elif isinstance(rs, Point):
            return Vector2(self.x - rhs.x, self.y - rhs.y)
        else:
            raise NotImplementedError()
```

---

## Point (C++)

```cpp
template <typename T1, typename T2 = T1>
class Point {
    ...
    Point& operator-=(const Vector2<T1>& rs) {
        this->_x -= rhs.x();
        this->_y -= rhs.y();
        return *this;
    }
    Point operator-(const Vector2<T1>& rs) const {
        auto tmp{*this};
        return tmp -= rs;
    }
    Vector2<T1> operator-(const Point& q) const {
        return {this->x() - q.x(),
                this->y() - q.y()};
     }
};
```

---

## Interval (Python 🐍)

```python
class Interval:
    def __init__(self, lr, ur):
        self._lr = lr  # lower
        self._ur = ur  # upper
    ...

    def __lt__(self, a) -> bool:
        if isinstance(a, Interval):
            return self.ur < a.lr
        return self.ur < a

    def contains(self, a) -> bool:
        if isinstance(a, Interval):
            return not (a.lr < self.lr or self.ur < a.ur)
        return not (a < self.lr or self.ur < a)
```

---

## Interval (C++)

```cpp
template <typename T = int>
class Interval {
    auto operator<(const T& a) const -> bool
    { return this->ur() < a; }

    template <typename U>
    bool operator<(const Interval<U>& a) const
    { return this->ur() < a.lr(); }

    auto contains(const T& a) const -> bool
    { return !(a < this->lr() || this->ur() < a); }

    template <typename U>
    bool contains(const Interval<U>& a) const
    { return !(a.lr() < this->lr() || this->ur() < a.ur()); }
};
```

---

## Rectangle (Python 🐍)

```python
class Rectangle(Point):
    def __init__(self, x, y):
        Point.__init__(self, x, y)

    @property
    def lr(self) -> Point:
        return Point(self.x.lr, self.y.lr)

    @property
    def ur(self) -> Point:
        return Point(self.x.ur, self.y.ur)

    # `a` can be Point or Rectangle
    def contains(self, a) -> bool:
        return self.x.contains(a.x) and self.y.contains(a.y)
```

---

## Rectangle (C++)

```cpp
template <typename T = int>
struct Rectangle : Point<Interval<T>> {
    Rectangle(Interval<T> x, Interval<T> y)
      : Point<Interval<T>>{move(x), move(y)} { }

    auto lr() const -> Point<T>
    { return {this->x().lr(), this->y().lr()} }

    auto ur() const -> Point<T>
    { return {this->x().ur(), this->y().ur()} }

    // `a` can be Point, Rectangle, or segemnt
    template <typename U1, typename U2>
    bool contains(const Point<U1, U2>& a) const
    { return this->x().contains(a.x()) && this->y().contains(a.y()); }
};
```

---

## VSegment (Python 🐍)

```python
class VSegment(Point):
    def __init__(self, x, y):
        Point.__init__(self, x, y)

    # `a` can be Point or VSegment
    def contains(self, a) -> bool:
        return self.x == a.x \
            and self.y.contains(a.y)
```

---

## VSegment (C++)

```cpp
template <typename T = int>
struct VSegment : Point<T, Interval<T>> {
    VSegment(T x, Interval<T> y)
      : Point<T, Interval<T>>{x, move(y)} { }

    template <typename U>
    bool contains(const Point<U>& a) const
    { return this->x() == a.x()
          && this->y().contains(a.y()); }
};
```

---

## Testing (Python 🐍)

```python
if __name__ == '__main__':
    p = Point(3, 4)
    intv1 = Interval(2, 8)
    intv3 = Interval(1, 10)
    R = Rectangle(intv1, intv3)
    vseg = VSegment(4, intv1)
    hseg = HSegment(intv3, 11)

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
    auto p = Point(3, 4);
    auto intv1 = Interval(2, 8);
    auto intv3 = Interval(1, 10);
    auto R = Rectangle(intv1, intv3);
    auto vseg = VSegment(4, intv1);
    auto hseg = HSegment(intv3, 11);

    assert(R.contains(p));
    assert(R.contains(R));
    assert(R.contains(vseg));
    assert(!R.contains(hseg));
}
```

---

## 🔚 Conclusion

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

# 🙋 Q & A
