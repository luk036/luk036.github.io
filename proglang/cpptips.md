title: Performance Tips for Modern C++
class: animation-fade
layout: true

<!-- This slide will serve as the base layout for all your slides -->

.bottom-bar[{{title}}]

---

class: impact

# {{title}}

👨🏻‍🏫 @luk036

---

## Use std::move() to avoid copying

.font-sm.mb-xs[ .col-6[

Original:

```cpp
auto createBigData(size_t n) ->
        std::tuple<int, std::vector<int> {
  auto BigData = std::vector<int>(n);
  // ...
  if (beta > tau) {
      return {1, BigData};
  }
  // ...
  return {0, BigData};
}
```

]

.col-6[

Better ⚡:

```cpp
auto createBigData(size_t n) ->
        std::tuple<int, std::vector<int> {
  auto BigData = std::vector<int>(n);
  // ...
  if (beta > tau) {
      return {1, std::move(BigData)};
  }
  // ...
  return {0, std::move(BigData)};
}
```

] ]

---

## Reserve memory allocation (C++)

.font-sm.mb-xs[ .col-6[

Original:

```cpp
auto nets = std::vector<node_t>{};

for (auto net : H.nets) {
    if (S.contains(net)) {
        // ...
    }
    else {
        nets.push_back(net);
    }
}
```

]

.col-6[

Better ⚡:

```cpp
auto nets = std::vector<node_t>{};
nets.reserve(H.nets.size() - S.size());
for (auto net : H.nets) {
    if (S.contains(net)) {
        // ...
    }
    else {
        nets.push_back(net);
    }
}
```

] ]

---

## Swap the contents without copying (C++)

.font-sm.mb-xs[ .col-6[

Original:

```cpp
if (restore) {
    part = snapshot; // copying
}
```

]

.col-6[

Better ⚡:

```cpp
if (restore) {
    part.swap(snapshot);
}
// snapshot will no more be used
```

] ]

---

## Using likely and/or unlikely

.font-sm.mb-xs[ .col-6[

Original:

```cpp
    if (beta > tau) {
        return 1;
    }
    if (beta == 0) {
        return 2;
    }
    if (tau + n*beta < 0) { // unlikely
        return 3;
    }
    return 0;
```

]

.col-6[

Better ⚡:

```cpp
    if (beta > tau) {
        return 1;
    }
    if (beta == 0) {
        return 2;
    }
    if (unlikely(tau + n*beta < 0)) {
        return 3;
    }
    return 0;
```

] ]

---

## Utilize invalid state (1)

.font-sm.mb-xs[ .col-6[

Original:

```cpp
std::vector visited(part.size(), false);
// ...
while (!Q.empty()) {
    auto v = Q.front();
    Q.pop_front();
    if (visited[v]) continue;
    part[v] = extern_module_ss[v];
    assert(part[v] < K);
    visited[v] = true;
```

]

.col-6[

Better ⚡:

```cpp
std::fill(part.begin(), part.end(), K);
// ...
while (!Q.empty()) {
    auto v = Q.front();
    Q.pop_front();
    if (part[v] < K) continue;
    part[v] = extern_module_ss[v];

// Saved a vector `visited`
```

] ]

---

## Utilize invalid state (2)

.font-sm.mb-xs[ .col-6[

Original:

```cpp
for (auto &v : vertexlist) {
    bucket.append(v);
    v.locked = false;
}
// Loop begin
// Select u from bucket each time:
bucket.detach(u);
u.locked = true;
// ...
for (auto &w : G.neigbours(u)) {
    if (w.locked) continue;
    assert(w.next != nullptr);
    bucket.modify_key(w);
}
```

]

.col-6[

Better ⚡:

```cpp
for (auto &v : vertexlist) {
    bucket.append(v);
    // automatically assign v.next
}
// Loop begin
// Select u from bucket each time:
bucket.detach(u);
u.next = nullptr;
// ...
for (auto &w : G.neigbours(u)) {
    if (w.next == nullptr) continue;
    bucket.modify_key(w);
}
// Saved a member variable `locked`
```

] ]

---

## Sentinel

.font-sm.mb-xs[ .col-6[

Original:

```cpp
std::vector<Dllink> bucket(100);
int max;


// ...
auto popleft() -> Dllink & {
    Dllink &res = bucket[max].popleft();
    while (max >= 0 // boundary check!!!
           && bucket[max].is_empty()) {
        max -= 1;
    }
    return res;
}
```

]

.col-6[

Better ⚡:

```cpp
std::vector<Dllink> bucket(100 + 1);
size_t max;
Dllink sentinel{0};
bucket[0].append(sentinel);
// ...
auto popleft() -> Dllink & {
    Dllink &res = bucket[max].popleft();
    while (bucket[max].is_empty()) {
        max -= 1;
    }
    return res;
}
// Saved a boundary check `max >= 0`
```

] ]

---

## Which one is better?

.font-sm.mb-xs[ .col-6[

A:

```cpp



for (auto w : H.G[net]) { // 10M nets
    for (auto k = 0u; k < K; ++k) {
        if (k == part[w]) continue;
        vertex_list[k][w].key -= 1;
    }
}
```

]

.col-6[

B:

```cpp
// pre-define a circularly linked list
// of size K.
// ...
for (auto w : H.G[net]) { // 10M nets
    auto stop = &cycle[part[w]];
    auto it = stop->next;
    for (; it != stop; it = it->next) {
        vertex_list[it->key][w].key -= 1;
    }
}
```

] ]
