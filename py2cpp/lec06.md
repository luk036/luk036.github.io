layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, center, middle

# Lecture 6: : Networkx vs. Boost graph library

---

## Python:

```python
def min_vertex_cover(G, cover, weight):
    total_dual_cost = 0  # for assertion
    total_primal_cost = 0
    gap = weight.copy()
    for u, v in G.edges():
        if cover[u] or cover[v]: continue
*       if gap[u] < gap[v]: u, v = v, u  # swap
        cover[v] = True
        total_dual_cost += gap[v]
        total_primal_cost += weight[v]
        gap[u] -= gap[v]
        gap[v] = 0
    assert total_dual_cost <= total_primal_cost
    assert total_primal_cost <= 2 * total_dual_cost
    return total_primal_cost
```

---

## C++14:

```cpp
auto min_vertex_cover(const Graph& G, const C1& weight, C2& cover) {
    using T = typename C1::mapped_type;
    auto total_primal_cost = T(0);
    auto gap = weight;
    for (auto&& e : G.edges()) {
        auto [u, v] = e.end_points();
        if (cover[u] || cover[v]) continue;
*       if (gap[u] < gap[v]) std::swap(u, v);
        cover[v] = true;
        total_primal_cost += weight[v];
        gap[u] -= gap[v];
        gap[v] = T(0);
    }
    return total_primal_cost;
}
```

---

## Environment Setup 🔧

- Lubuntu 20.04 LTS:
    - pip install networkx
    - sudo apt install libboost-dev libfmt-dev
    - sudo apt install cmake ninja git gh
- Android termux:
    - pip install networkx
    - pkg install boost fmt
    - pkg install cmake ninja git gh

---

## Setup (Python) 🔧

```bash
$ gh repo clone luk036/primal-dual-approx-py
$ cd primal-dual-approx-py
$ pip install -r requirements.txt
$ python setup.py develop
$ python setup.py test
```

---

## Setup (C++) 🔧

```bash
$ gh repo clone luk036/primal-dual-approx-cpp
$ cd primal-dual-approx-cpp/external
$ git submodule update --init # for doctest
$ cd ..
$ mkdir build; cd build
$ cmake .. -DCMAKE_BUILD_TYPE=Release
$ cmake --build .
$ ctest
```

---

class: nord-dark, center, middle

# Q & A 🗣️
