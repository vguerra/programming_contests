// Victor Guerra <vguerra@gmail.com>
// 20150309

// https://www.hackerrank.com/contests/w14/challenges/worst-permutation

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iterator>

int main() {
  uint64_t N, K;
  std::cin >> N >> K;
  std::vector<uint64_t> nums(N, 0);

  std::copy_n(std::istream_iterator<uint64_t>(std::cin), N, nums.begin());

  auto final_runner = nums.end();
  for (auto runner = nums.begin(); K != 0 && runner != final_runner; ++runner) {
    auto max_el = std::max_element(std::next(runner), nums.end());
    if (max_el != nums.end() && *max_el > *runner) {
      --K;
      std::iter_swap(max_el, runner);
    }
  }

  std::copy_n(nums.begin(), N, std::ostream_iterator<uint64_t>(std::cout, " "));
  std::cout << "\n";

  return EXIT_SUCCESS;
}
