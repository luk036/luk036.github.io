title: Frome Python To Modern C++
class: animation-fade
layout: true

.bottom-bar[ {{title}}: Container, iterators, and Ranges]

---

## Containers (python)

```python
L = [2, 3, 5, 7, 2]
S = {2, 3, 5, 7, 2}
D = {"us": 1, "cn": 86, "hk": 852}
T = (2, 3, 5, 7, "hello", False)
```

---

## Containers (C++)

```cpp
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility> // pair
#include <tuple>
...
using namespace std;
auto L = vector{2, 3, 5, 7, 2};
auto S = unordered_set{2, 3, 5, 7, 2};
auto D = unordered_map{pair{"us", 1},
          pair{"cn", 86}, pair{"hk", 852}};
auto T = tuple{2, 3, 5, 2, "hello", false}; 
// Tuple is not a container.
```

---

## Iterator (python)

```python
class dlist_iterator:
```

---

## Iterator (C++)

```cpp
template <typename T>
class dllist_iterator {
};
```

---

## range (python)

```python
for i in range(100):
for a in L:
for iv, v in enumerate(L):
for a, b in zip(L1, L2):
```

---

## range-v3 (C++)

```cpp
#include <range/view/enumerate.hpp>
#include <range/view/zip.hpp>

for (auto i : views::iota(100))
for (auto a : L)
for (auto [iv, v] : ranges::enumerate(L))
for (auto [a, b] : ranges::zip(L1, L2))
```

---

## Testing (python)

```python
if __name__ == '__main__':
    p = point(3, 4)
```

---

## Testing (C++)

```cpp
int main() {
    auto p = point(3, 4);
    assert(!R.contains(hseg));
}
```

---

## Conclusion

- tbd
