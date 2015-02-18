//Victor Guerra <vguerra@gmail.com>
//20150204

//https://www.hackerrank.com/challenges/sherlock-and-squares

#include <iostream>
#include <cstdlib>
#include <cmath>

int main() {
  unsigned T; 
  std::cin >> T; 
  while (T--) {
    uint32_t A, B; 
    uint32_t count = 0;
    std::cin >> A >> B;
    std::size_t k = std::ceil(std::sqrt(A));
    while (k*k <= B) {
      ++count;
      ++k;
    }
    std::cout << count << "\n";
  }
  return EXIT_SUCCESS;
}
