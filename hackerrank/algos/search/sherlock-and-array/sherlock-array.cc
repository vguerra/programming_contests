//Victor Guerra <vguerra@gmail.com>
//20141111

//https://www.hackerrank.com/challenges/sherlock-and-array

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using vec_t = std::vector<unsigned>;

bool exists_middle_sum_point(const vec_t& vec) {
  uint32_t tot = std::accumulate(vec.begin(), vec.end(), 0);
  uint32_t acu = 0;

  for (auto& num : vec) {
    if (acu == (tot - num - acu)) {
      return true;
    }
    acu += num;
  }
  return false;
}

int main() {
  unsigned int T; 
  unsigned int N;
  std::cin >> T;
  
  while (T--) {
    std::cin >> N;
    std::vector<unsigned> nums(N);
    std::copy_n(std::istream_iterator<unsigned>(std::cin), N, nums.begin());
    std::cout << ((exists_middle_sum_point(nums)) ? "YES" : "NO") << "\n";
  }
  return 0;
}
