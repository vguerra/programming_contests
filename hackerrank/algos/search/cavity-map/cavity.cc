//Victor Guerra <vguerra@gmail.com>
//20141110

//https://www.hackerrank.com/challenges/cavity-map

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using matrix_t = std::vector<std::vector<int>>;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void mark_cavities(matrix_t m) {
  std::size_t n = m.size();
  if (n == 1) {
    std::cout << m[0][0] << "\n";
    return;
  } 
  std::copy(m[0].begin(), m[0].end(), std::ostream_iterator<int>(std::cout, ""));
  std::cout << "\n";
  for (std::size_t row = 1; row < n - 1; ++row) {
    std::cout << m[row][0];
    for (std::size_t col = 1; col < n - 1; ++col) {
      bool depthest = true;
      for (auto d : {0, 1, 2, 3}) {
        if (m[row][col] <= m[row + dx[d]][col + dy[d]]) {
          depthest = false;
          break;
        }
      }
      if (depthest) {
        std::cout << "X";
        m[row][col] = 10;
      } else {
        std::cout << m[row][col];
      }
    }
    std::cout << m[row][n - 1];
    std::cout << "\n";
  }
  std::copy(m[n - 1].begin(), m[n - 1].end(), std::ostream_iterator<int>(std::cout, ""));
  std::cout << "\n";
}

int main() {
  unsigned n;
  std::cin >> n;

  matrix_t m = matrix_t(n, std::vector<int>(n, 0));

  for (unsigned i = 0; i < n; ++i) {
    for (unsigned j = 0; j < n; ++j) {
      char c; 
      std::cin >> c;
      m[i][j] = c - '0';
    }
  }
  
  mark_cavities(m);
  return EXIT_SUCCESS;
}
