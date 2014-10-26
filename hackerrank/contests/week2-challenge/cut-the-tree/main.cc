//Victor Guerra <vguerra@gmail.com>
//2014-05-06

//HackerRank - Cut the Tree
//https://www.hackerrank.com/contests/w2/challenges/cut-the-tree

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <list>
#include <utility>
#include <queue>

using namespace std;

class Graph {
  public: 
    Graph(unsigned nodes) : _nodes(nodes), _edges(nodes, list<unsigned>()), _node_values(nodes, 0) {}
    ~Graph() {}
    void set_value(unsigned node, unsigned value);
    void add_edge(unsigned source, unsigned tail);
    unsigned minimum_distance();
    unsigned minimum_distance2();
  private:
      void calculate_cost();
      unsigned _nodes;
      unsigned _cost; 
      vector<list<unsigned> > _edges;
      vector<int> _node_values;
      list<pair<unsigned, unsigned> > _copy_edges;
};

void Graph::set_value(unsigned node, unsigned value) {
  _node_values[node] = value;
}

void Graph::calculate_cost() {
  _cost = std::accumulate(_node_values.begin(), _node_values.end(), 0);
}

void Graph::add_edge(unsigned source, unsigned tail) {
  source -= 1;
  tail -= 1;
  _copy_edges.push_back(make_pair(source,tail));
  _edges[source].push_back(tail);
  _edges[tail].push_back(source);
}

unsigned Graph::minimum_distance2() {
  unsigned min = std::numeric_limits<unsigned>::max();
  this->calculate_cost();
 
  unsigned start_node = 0;

  for (unsigned i = 0; i < _nodes; ++i) {
    if (_edges[i].size() == 1) {
      start_node = i;
      break;
    }
  }

  queue<unsigned> to_visit;
  to_visit.push(start_node);

  unsigned acum;
  while (to_visit.empty()) {
  
  }


  return start_node;
}

unsigned Graph::minimum_distance() {
  unsigned min = std::numeric_limits<unsigned>::max();
  this->calculate_cost();
  cout << "total cost: " << _cost << "\n";
  for (auto edge : _copy_edges) {
    unsigned s = edge.first;
    unsigned t = edge.second;
    unsigned n, ignore;
    unsigned found_cost;
    cout << "trying removing edge: " << s + 1<< " , " << t + 1<< "\n";
    if (_edges[s].size() < _edges[t].size()) {
      n = s;
      ignore = t; 
    } else {
      n = t;
      ignore = s;
    }
    found_cost = 0; 
    cout << "working with node: " << n + 1 << "\n";
    queue<unsigned> to_visit;
    to_visit.push(n);
    vector<bool> visited(_nodes, false);
    while (!to_visit.empty()) {
      unsigned node = to_visit.front();
      to_visit.pop();
      visited[node] = true;
      found_cost += _node_values[node];
      for (auto tail : _edges[node]) {
        if (tail != ignore && !visited[tail]) {
          cout << "adding node " << tail + 1 << "\n";
          to_visit.push(tail);
        }
      }
    }
    cout << "working with node: " << n + 1 << " got cost : " << found_cost << "\n";
    unsigned diff = abs((long)2*found_cost - _cost);
    cout << "diff is : " << diff << "\n";
    if (diff < min) {
      min = diff;
    }
  }
  return min;
}

int main() {
  unsigned N;
  cin >> N;
  Graph *g = new Graph(N); 
  for (unsigned i = 0; i < N; ++i) {
    unsigned v;
    cin >> v;
    g->set_value(i, v);
  }
  while (N-- - 1) {
    unsigned source, tail;
    cin >> source >> tail;
    g->add_edge(source, tail); 
  }
  //cout << g->minimum_distance();
  cout << g->minimum_distance2();
  delete g;
  return 0;
}
