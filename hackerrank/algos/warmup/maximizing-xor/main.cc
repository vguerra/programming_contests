//Victor Guerra <vguerra@gmail.com>
//20150203

//https://www.hackerrank.com/challenges/maximizing-xor

#include <iostream>
#include <cstdlib>
#include <cmath>

int main() {
  unsigned L, R; 
  std::cin >> L >> R;
  if (L != R) {
    std::cout << ~(~0L << static_cast<unsigned>(std::ceil(std::log2(L^R))));
  } else {
    std::cout << 0; 
  }
  std::cout << "\n";
  return EXIT_SUCCESS;
}
