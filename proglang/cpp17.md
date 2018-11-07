title: Modern C++ Make Life Easier
class: animation-fade
layout: true

<!-- This slide will serve as the base layout for all your slides -->
.bottom-bar[
  {{title}}
]

---

class: impact

{{title}}
=========

Wai-Shing Luk
-------------

---

Boost Graph Library
-------------------

.small[
.col-6[

C++98

```cpp
template <class Graph>
struct exercise_vertex {
  //...
  typedef typename graph_traits<Graph>
    ::vertex_descriptor Vertex;

  void operator()(const Vertex& v) const
  {
    //...
  }
  //...
};
```

]

.col-6[

C++17:

```cpp
template <class Graph>
struct exercise_vertex {
  //...

  void operator()(const auto &v) const
  {
    //...
  }
  //...
};
```

]
]

---

.small[
.col-6[

C++98

```cpp
typedef graph_traits<Graph> GraphTraits;
typename property_map<Graph, vertex_index_t>::type
  index = get(vertex_index, g);

std::cout << "out-edges: ";
typename GraphTraits::out_edge_iterator out_i, out_end;
typename GraphTraits::edge_descriptor e;
for (boost::tie(out_i, out_end) = out_edges(v, g);
     out_i != out_end; ++out_i) {
  e = *out_i;
  Vertex src = source(e, g), targ = target(e, g);
  std::cout << "(" << index[src] << ","
            << index[targ] << ") ";
}
```

]

.col-6[

C++17:

```cpp


auto index = get(vertex_index, g);

std::cout << "out-edges: ";


for (auto e : g.neighbors(v)) {
  auto src = boost::source(e, g);
  auto targ = boost::target(e, g);
  std::cout << "(" << index[src] << ","
            << index[targ] << ") ";
}
```

]
]

---

class: impact

Q & A
========
