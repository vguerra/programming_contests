// Victor Guerra <vguerra@gmail.com>
// 20150313

// https://www.hackerrank.com/contests/w14/challenges/subtrees-and-paths

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <stack>

int main() {
  uint32_t N, Q;
  std::cin >> N;

  std::vector<int64_t> values(N + 1, 0);
  std::vector<std::vector<uint32_t>> adj_list(N + 1, std::vector<uint32_t>());
  std::vector<std::vector<uint32_t>> tree_adj_list(N + 1, std::vector<uint32_t>());

  std::vector<uint32_t> parents(N + 1, 0);
  std::vector<bool> visited(N + 1, false);

  while (N-- - 1) {
    uint32_t l, r;
    std::cin >> l >> r;
    adj_list[l].push_back(r);
    adj_list[r].push_back(l);
  }

  // get info about all possibe paths from root. 
  std::queue<uint32_t> q;
  parents[1] = 0;
  q.push(1);
  visited[1] = true;
  while (!q.empty()) {
    uint32_t v = q.front();
    q.pop();
    for (auto const& w : adj_list[v]) {
      if (!visited[w]) {
        q.push(w);
        visited[w] = true;
        parents[w] = v;
        tree_adj_list[v].push_back(w);
      }
    }
  }

  std::cin >> Q;
  while (Q--) {
    std::string action;
    std::cin >> action;
    int64_t l, r;
    std::cin >> l >> r;
    if (action == "add") {
      std::queue<uint32_t> pq;
      pq.push(l);
      while (!pq.empty()) {
        uint32_t n = pq.front();
        pq.pop();
        values[n] += r;
        for (const auto& m : tree_adj_list[n]) {
          pq.push(m);
        }
      }
    } else {
      std::stack<uint32_t> left_stack;
      std::stack<uint32_t> right_stack;
      while (l != 0) {
        left_stack.push(l);
        l = parents[l];
      }
      while (r != 0) {
        right_stack.push(r);
        r = parents[r];
      }
      uint32_t common_parent = 0; 
      while (!left_stack.empty() && !right_stack.empty() && left_stack.top() == right_stack.top()) {
        common_parent = left_stack.top();
        left_stack.pop();
        right_stack.pop();
      }
      int64_t max_value = values[common_parent];

      while (!left_stack.empty()) {
        max_value = std::max(max_value, values[left_stack.top()]);
        left_stack.pop();
      }

      while (!right_stack.empty()) {
        max_value = std::max(max_value, values[right_stack.top()]);
        right_stack.pop();
      }
      std::cout << max_value << "\n";
    }
  }
 
  return EXIT_SUCCESS;
}
