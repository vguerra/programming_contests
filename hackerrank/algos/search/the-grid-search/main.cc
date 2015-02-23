//Victor Guerra <vguerra@gmail.com>
//20150222

//https://www.hackerrank.com/challenges/the-grid-search

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
  unsigned T; 
  std::cin >> T; 
  while (T--) {
    unsigned rG1, cG1, rG2, cG2; 
    std::cin >> rG1 >> cG1; 
    std::vector<std::string> g1(rG1);
    std::copy_n(std::istream_iterator<std::string>(std::cin), rG1, g1.begin());
    std::cin >> rG2 >> cG2; 
    std::vector<std::string> g2(rG2);
    std::copy_n(std::istream_iterator<std::string>(std::cin), rG2, g2.begin());
    unsigned r1 = 0; 
    unsigned r2 = 0;
    long prev_dist = 0; 
    while (r2 < rG2 && r1 < rG1) {
      auto pos = std::search(g1[r1].begin(), g1[r1].end(), g2[r2].begin(), g2[r2].end());
      auto dist = std::distance(g1[r1].begin(), pos);
      if (pos != g1[r1].end() && (prev_dist == 0 || prev_dist == dist)) {
        ++r2; 
        prev_dist = dist;
      } else {
        r2 = 0;
        prev_dist = 0;
      }
      ++r1; 
    }
    if (r2 == rG2) std::cout << "YES";
    else std::cout << "NO";
    std::cout << "\n";
  }
  return EXIT_SUCCESS;
}
