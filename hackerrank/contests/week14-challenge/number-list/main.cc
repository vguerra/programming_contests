// Victor Guerra <vguerra@gmail.com>
// 20150310

// https://www.hackerrank.com/contests/w14/challenges

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <vector>

int main() {
  uint64_t T;
  std::cin >> T;
  while (T--) {
    uint64_t N, K;
    std::cin >> N >> K;
    std::vector<uint64_t> nums(N, 0);
    std::copy_n(std::istream_iterator<uint64_t>(std::cin), N, nums.begin());

    uint64_t runner = 0;
 
    while (nums[runner] <= K && runner < N) runner++;
    if (runner == N) {
      std::cout << "0\n";
      continue;
    }
    uint64_t prev_pos = runner;
    uint64_t count = runner + 1;
    runner++;
    uint64_t less_nums = 0;
    while (runner < N) {
      if (K < nums[runner]) {
        count += runner;
        count += runner - prev_pos;
        count += prev_pos*less_nums;
        prev_pos = runner;
        less_nums = 0;
      } else {
        less_nums++;
      }
      ++runner; 
    }
    if (runner - 1 != prev_pos) {
        count += runner - prev_pos - 1;
        count += prev_pos*less_nums;
    }
    std::cout << count << "\n";
  }
  return EXIT_SUCCESS;
}
