//Victor Guerra <vguerra@gmail.com>
//20141118

//https://www.hackerrank.com/challenges/sherlock-and-pairs

#include <iostream>
#include <iterator>
#include <algorithm>
#include <unordered_map>
#include <cstdint>

int main() {
  unsigned T; 
  std::cin >> T;
  
  while (T--) {
    unsigned N;
    std::cin >> N;

    std::unordered_map<unsigned, unsigned> vec;
    uint64_t num_pairs = 0;
    for (unsigned i = 0; i < N; ++i) {
      unsigned num; 
      std::cin >> num;
      if (vec[num] > 0) {
        num_pairs += 2*vec[num];
      }
      ++vec[num];
    }
    std::cout << num_pairs << "\n";
  }

  return 0;
}
