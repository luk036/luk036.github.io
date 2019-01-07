title: Performance Tips
class: animation-fade
layout: true

<!-- This slide will serve as the base layout for all your slides -->
.bottom-bar[
  {{title}}
]

---

class: impact

# {{title}}

## Wai-Shing Luk

---

## Utilize invalid state (1)

.small[
.col-6[

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

Better:

```cpp
std::fill(part.begin(), part.end(), K);
// ...
while (!Q.empty()) {
    auto v = Q.front();
    Q.pop_front();
    if (part[v] < K) continue;
    part[v] = extern_module_ss[v];
```

]
]

---

## Utilize invalid state (2)

.small[
.col-6[

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

Better:

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
// Saved a variable .locked
```

]
]

---

## Sentinel

.small[
.col-6[

Original:

```cpp
std::vector<dllink> bucket(100);
int max;


// ...
auto popleft() -> dllink & {
    dllink &res = bucket[max].popleft();
    while (max >= 0 // boundary check!!! 
           && bucket[max].is_empty()) {
        max -= 1;
    }
    return res;
}
```

]

.col-6[

Better:

```cpp
std::vector<dllink> bucket(100 + 1);
size_t max;
dllink sentinel{0};
bucket[0].append(sentinel);
// ...
auto popleft() -> dllink & {
    dllink &res = bucket[max].popleft();
    while (bucket[max].is_empty()) {
        max -= 1;
    }
    return res;
}
```

]
]

---

## Which one is better?

.small[
.col-6[

A:

```cpp



for (auto w : H.G[net]) { // 10M nets
    for (auto k = 0u; k < K; ++k) {
*       if (k == part[w]) continue; 
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

]
]

---

## Reserve memory allocation (C++)

.small[
.col-6[

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

Better:

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

]
]

---

## Swap the contents without copying (C++)

.small[
.col-6[

Original:

```cpp
if (restore) {
    part = snapshot; // copying
}
```

]

.col-6[

Better:

```cpp
if (restore) {
    part.swap(snapshot);
}
// snapshot will no more be used
```

]
]

