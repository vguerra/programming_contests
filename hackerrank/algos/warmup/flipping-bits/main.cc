//Victor Guerra <vguerra@gmail.com>
//20150203

//https://www.hackerrank.com/challenges/flipping-bits

#include <iostream>
#include <cstdlib>

int main() {
  unsigned T; 
  std::cin >> T; 
  while (T--) {
    uint32_t num; 
    std::cin >> num; 
    std::cout << ~num << "\n";
  }
  return EXIT_SUCCESS;
}
