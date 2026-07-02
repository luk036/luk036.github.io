#include <LEDA/graph/graph.h>
#include <LEDA/graph/graph_gen.h>
#include <iostream>

#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "vertex_cover.hpp"

//  g++ -I$LEDAROOT/incl mvc.cpp -lleda -lX11

using namespace leda;

int main() {
  graph G;
  srand(time(NULL));

  // random_graph(G,5,20);
  maximal_planar_graph(G, 1024);
  std::cout << G.number_of_nodes() << '\n';
  std::cout << G.number_of_edges() << '\n';
  node_array<double> weight(G);
  node v;
  forall_nodes(v, G) {
    weight[v] = double((rand() % 256) + 100) / 10.0;
    // weight[v] = 1;
    assert(weight[v] > 0);
  }

  list<node> C1;
  double cost1 = min_vc_pd(G, weight, C1);
  std::cout << "total cost = " << cost1 << '\n';

  list<node> C2;
  double cost2 = min_vc_greedy(G, weight, C2);
  std::cout << "total cost = " << cost2 << '\n';

  G.make_bidirected();
  G.make_map();
  G.compute_faces();

  return 0;
}
