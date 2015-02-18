//Victor Guerra <vguerra@gmail.com>
//20150212

//https://www.hackerrank.com/challenges/even-tree

#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>
#include <random>

class RandUnsigned {
  public: 
    RandUnsigned(unsigned low, unsigned high) : dist{low, high} , re(rd()) {}
    unsigned operator()() {return dist(re);}
  private: 
    std::random_device rd;
    std::uniform_int_distribution<unsigned> dist;
    std::default_random_engine re;
};

struct _graph {
  unsigned _V = 0;
  unsigned _E = 0;
  bool _directed = false;
  using _adj_t = std::vector<std::list<unsigned>>;
  _adj_t _adj;

  _graph(unsigned V, bool d) : _V(V), _directed(d), _adj(_V, std::list<unsigned>()) {}
  void add_edge(unsigned v, unsigned w) {
    _adj[v].push_back(w);
    if (!_directed) {
      _adj[w].push_back(v);
    }
  }

  _graph(const _graph& g) = default;
};

using graph_t = struct _graph;

struct _dfs {
  using vbool_t = std::vector<bool>;
  vbool_t _processed;
  vbool_t _discovered;
  graph_t _g;
  unsigned _components = 0;

  _dfs(const graph_t& g) : _processed(g._V, false), _discovered(g._V, false), _g(g) {}

  unsigned components(unsigned v) {
    _processed[v] = true;
    unsigned count = 1; 
    for (auto const& w : _g._adj[v]) {
      if (!_discovered[w]) {
        _discovered[w] = true;
        count += components(w);
      }
    }
    if (count != 0 && count % 2 == 0) {
      ++_components;
      return 0;
    }
    return count;

  } 

  unsigned operator()() {
    RandUnsigned rnd {0, _g._V};
    unsigned rnd_v = rnd();
    _discovered[rnd_v] = true;
    unsigned final_c = components(rnd_v);
    if (_components > 0) return _components - 1;
    return 0;
  }
};

using dfs_t = struct _dfs;

int main() {
  unsigned N,M; 
  std::cin >> N >> M;
  
  graph_t g(N, false);
 
  while (M--) {
    unsigned v, w; 
    std::cin >> v >> w;
    g.add_edge(--v, --w);
  }
  
  dfs_t dfs(g);
  std::cout << dfs() << "\n";  

  return EXIT_SUCCESS;
}
