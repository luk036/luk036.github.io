#ifndef VERTEX_COVERING
#define VERTEX_COVERING 1

#include <LEDA/core/list.h>
#include <LEDA/graph/graph.h>
#include <cassert>
#include <queue>


/**
 * Primal-dual algorithm for minimum vertex cover problem
 */
template <typename T>
T min_vc_pd(const leda::graph &G, const leda::node_array<T> &weight,
            leda::list<leda::node> &S) {
  leda::edge_array<bool> is_covered(G, false);
  leda::node_array<bool> is_vc(G, false);
  leda::node_array<T> gap(weight);

  T total_primal_cost = 0;
  T total_dual_cost = 0;

  leda::edge e;
  forall_edges(e, G) {
    if (is_covered[e])
      continue;

    leda::node s = G.source(e);
    leda::node t = G.target(e);
    if (gap[t] < gap[s])
      std::swap(s, t);
    is_vc[s] = true;
    S.append(s);
    gap[t] -= gap[s];
    assert(gap[t] >= T(0));
    // gap[s] = T(0);
    leda::edge e2;
    forall_adj_edges(e2, s) { is_covered[e2] = true; }
    total_primal_cost += weight[s];
    total_dual_cost += gap[s];
  }

  leda::list_item it;
  forall_items(it, S) {
    leda::node v = S.inf(it);
    leda::node w;
    bool found = false;
    forall_adj_nodes(w, v) {
      if (!is_vc[w]) {
        found = true;
        break;
      }
    }
    if (!found) {
      S.del_item(it);
      total_primal_cost -= weight[v];
      is_vc[v] = false;
    }
  }

  assert(total_primal_cost >= total_dual_cost);
  return total_primal_cost;
}

/**
 * Primal-dual algorithm for graph bipartization problem
 */
template <typename T>
T min_bipartization_pd(const leda::graph &G, const leda::node_array<T> &weight,
                       leda::list<leda::node> &S) {
  leda::face_map<bool> is_covered(G);
  leda::node_array<bool> is_vc(G, false);
  leda::node_array<T> gap(weight);

  std::queue<leda::face> Q;

  T total_primal_cost = 0;
  T total_dual_cost = 0;

  leda::face f;
  forall_faces(f, G) {
    size_t deg = 0;
    leda::edge e;
    forall_face_edges(e, f)++ deg;
    if ((deg & 1) == 1) { // odd
      Q.push(f);
      is_covered[f] = false;
    } else { // even
      is_covered[f] = true;
    }
  }

  while (!Q.empty()) {
    leda::face f = Q.top();
    Q.pop();
    if (is_covered[f])
      continue;

    leda::edge e = G.first_face_edge(f);
    leda::node s = G.source(e);
    T min_gap = gap[s];
    forall_face_edges(e, f) {
      leda::node v = G.source(e);
      if (min_gap > gap[v]) {
        s = v;
        min_gap = gap[v];
      }
    }

    is_vc[s] = true;
    S.append(s);
    forall_face_edges(e, f) {
      leda::node v = G.source(e);
      gap[v] -= min_gap;
    }
    assert(gap[s] == 0);

    leda::face f2;
    forall_adj_faces(f2, s) { // ???
      is_covered[f2] = true;
    }

    // add new odd-cycle face ???

    total_primal_cost += weight[s];
    total_dual_cost += min_gap;
  }

  leda::list_item it;
  forall_items(it, S) {
    leda::node v = S.inf(it);
    leda::node w;
    bool found = false;
    forall_adj_nodes(w, v) {
      if (!is_vc[w]) {
        found = true;
        break;
      }
    }
    if (!found) {
      S.del_item(it);
      total_primal_cost -= weight[v];
      is_vc[v] = false;
    }
  }

  assert(total_primal_cost >= total_dual_cost);
  return total_primal_cost;
}

#include <boost/heap/binomial_heap.hpp>

template <typename T>
class vc_order // for boost::heap
{
public:
  vc_order(const leda::node_array<T> &W, const leda::node_array<size_t> &D)
      : _W(&W), _D(&D) {}
  ~vc_order() {}

  bool operator()(leda::node v, leda::node w) const {
    return (*_W)[v] * (*_D)[w] > (*_W)[w] * (*_D)[v];
    // return (*_W)[v] > (*_W)[w];
    // return (*_D)[w] > (*_D)[v];
  }

private:
  const leda::node_array<T> *_W;
  const leda::node_array<size_t> *_D;
};

/**
 * Greedy algorithm for minimun vertex cover problem
 */
template <typename T>
T min_vc_greedy(const leda::graph &G, const leda::node_array<T> &weight,
                leda::list<leda::node> &S) {
  typedef typename boost::heap::binomial_heap<leda::node,
                                              boost::heap::compare<vc_order<T>>>
      bpq_t;
  typedef typename bpq_t::handle_type bh_t;

  leda::node_array<size_t> D(G); // number of uncovered edges

  leda::node v;
  forall_nodes(v, G) D[v] = G.degree(v);

  bpq_t Bpq(vc_order<T>(weight, D));
  leda::node_array<bh_t> bh_handlers(G);
  forall_nodes(v, G) {
    bh_t bh = Bpq.push(v);
    bh_handlers[v] = bh;
  }

  leda::edge_array<bool> is_covered(G, false);
  leda::node_array<bool> is_vc(G, false);

  T total_cost = 0;
  size_t num_edges = G.number_of_edges();

  while (num_edges > 0 && !Bpq.empty()) {
    leda::node s = Bpq.top();
    Bpq.pop();
    is_vc[s] = true;
    S.append(s);
    total_cost += weight[s];

    leda::edge e2;
    forall_adj_edges(e2, s) {
      if (is_covered[e2])
        continue;
      is_covered[e2] = true;
      leda::node t = G.opposite(e2, s);
      D[t] -= 1;
      Bpq.update(bh_handlers[t]);
      --num_edges;
    }
  }

  leda::list_item it;
  forall_items(it, S) {
    leda::node v = S.inf(it);
    leda::node w;
    bool found = false;
    forall_adj_nodes(w, v) {
      if (!is_vc[w]) {
        found = true;
        break;
      }
    }
    if (!found) {
      S.del_item(it);
      total_cost -= weight[v];
      is_vc[v] = false;
    }
  }

  return total_cost;
}

#endif
