// Victor Guerra <vguerra@gmail.com>
// 20150214

// https://www.hackerrank.com/challenges/the-quickest-way-up

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <list>
#include <limits>
#include <algorithm>
#include <tuple>
#include <set>

static const unsigned board_size = 100;
static const unsigned limit_parent = std::numeric_limits<unsigned>::max();

using trio_t = std::tuple<unsigned, unsigned, unsigned>;

class Graph {
  public:
  Graph(unsigned V, bool directed)
      : _V(V), _adj(V, std::list<unsigned>()), _directed(directed) {}
  void add_edge(unsigned v, unsigned w) {
    _adj[v].push_back(w);
    if (!_directed) _adj[w].push_front(v);
  }

  using adj_t = std::vector<std::list<unsigned>>;
  unsigned _V;
  unsigned _E = 0;
  adj_t _adj;
  bool _directed;
};

struct trio_cmp {
  bool operator()(const trio_t& lhs, const trio_t& rhs) const {
    return std::get<2>(lhs) <= std::get<2>(rhs);
  }
};

struct Dijkstra {
  Dijkstra(Graph g)
      : _distance(std::vector<unsigned>(g._V, limit_parent)),
        _parent(std::vector<unsigned>(g._V, limit_parent)) {}

  void dijkstra(Graph g, unsigned s) {
    _distance[s] = 0;
    _parent[s] = s;
   
    std::set<trio_t,trio_cmp> pq; 

    pq.insert(std::make_tuple(0, 0, 0));

    while (!pq.empty()) {
      unsigned v, start, throws; 
      std::tie(v, start, throws) = *pq.begin();
      pq.erase(pq.begin());

      for (const auto& w : g._adj[v]) {
        unsigned new_start = start;
        unsigned w_cost = _distance[start];
        if (_distance[w] > w_cost) {
          if (w != board_size - 1 && ((w - v) > 1 || w - start == 6)) {
            new_start = w;
            ++w_cost;
          }
          _parent[w] = v;
          _distance[w] = w_cost;
          pq.insert(std::make_tuple(w, new_start, w_cost));
        }
      }
    }
  }
  
  unsigned path_to(unsigned w) const {
    return _distance[w] + 1;
  }

  std::vector<unsigned> _distance;
  std::vector<unsigned> _parent;
};

int main() {
  unsigned T;
  std::cin >> T;

  while (T--) {
    Graph board(board_size, true);

    for (unsigned i = 0; i < board_size - 1; ++i) {
      board.add_edge(i, i + 1);
    }

    unsigned l, s;
    std::scanf("%u,%u", &l, &s);

    for (unsigned i = 0; i < l + s; ++i) {
      unsigned f, e;
      std::scanf(" %u,%u", &f, &e);
      board.add_edge(--f, --e);
    }

    Dijkstra dijObj(board);
    dijObj.dijkstra(board, 0);
    std::cout << dijObj.path_to(board_size - 1) << "\n";
  }
  return EXIT_SUCCESS;
}
