//Victor Guerra <vguerra@gmail.com>
//2014-06-09

//POJ - 2309
//http://poj.org/problem?id=2309

#include <iostream>
#include <cstdlib>
#include <cmath>

int main() {
  unsigned int X, N;
  std::cin >> N;
  while (N--) {
    std::cin >> X;
    unsigned level = static_cast<unsigned>(std::log((double)X)/log(2.0));
    unsigned top = 1U << level;
    if (level == 0) {
      std::cout << X << " " << X << std::endl;
      continue;
    }
    unsigned diff = 1U << (level - 1);
    while (top != X) {
      if (X < top) {
        top -= diff; 
      } else {
        top += diff;
      }
      diff >>= 1;
    }
    unsigned min = top;
    unsigned max = top;
    while (diff != 0) {
     min -= diff; 
     max += diff;
     diff >>= 1;
    }
    std::cout << min << " " << max << std::endl;
  }
  return EXIT_SUCCESS;
}
