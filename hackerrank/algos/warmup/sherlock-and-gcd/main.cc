#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>

unsigned gcd(unsigned a, unsigned b) {
  while (b) {
    unsigned r = a % b; 
    a = b; 
    b = r; 
  }
  return a;
}

int main() {
  unsigned T;
  std::cin >> T; 
  while (T--) {
    bool found_no_coprimes = false;
    unsigned N; 
    std::cin >> N;
    std::vector<unsigned> nums(N);
    std::copy_n(std::istream_iterator<unsigned>(std::cin), N, nums.begin());
    for (unsigned j = 0; j < N - 1; ++j) {
      for (unsigned i = j + 1; i < N; ++i) {
        if (gcd(nums[j], nums[i]) == 1) {
          found_no_coprimes = true;
        } 
      }
    }
    if (found_no_coprimes) std::cout << "YES"; 
    else std::cout << "NO";
    std::cout << "\n";
  }
  return EXIT_SUCCESS;
}
