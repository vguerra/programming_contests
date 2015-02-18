//Victor Guerra <vguerra@gmail.com>
//20150204

//https://www.hackerrank.com/challenges/manasa-and-stones

#include <iostream>
#include <cstdlib>
#include <set>

int main() {
  unsigned T; 
  std::cin >> T; 
  while (T--) {
    unsigned n, a, b; 
    std::set<unsigned> values; 
    std::cin >> n >> a >> b; 
    for (unsigned i = 0; i < n; ++i) {
      values.insert((n - 1 -i)*a + i*b); 
    }
    for (auto const& v : values) {
      std::cout << v << " ";
    }
    std::cout << "\n";
  }
  return EXIT_SUCCESS;
}
