//Victor Guerra <vguerra@gmail.com>
//20150209

//https://www.hackerrank.com/challenges/circle-city

#include <iostream>
#include <cstdlib>
#include <cmath>

int main() {
  unsigned t; 
  std::cin >> t; 
  while (t--) {
    uint32_t r_2, k;
    std::cin >> r_2 >> k;

    uint32_t stations_needed = 0;
    for (uint32_t x = 0; x*x <= r_2; ++x) {
      double y = sqrt(r_2 - x*x);
      double intpart;
      if (std::modf(y, &intpart) == 0.0) {
        stations_needed += 4;
        if (x == 0 || x*x == r_2) stations_needed -= 2;
      }
    }
    if (stations_needed <= k) {
      std::cout << "possible";
    } else {
      std::cout << "impossible";
    }
    std::cout << "\n";
  }
  return EXIT_SUCCESS;
}
