// Victor Guerra <vguerra@gmail.com>
// 20150206

// https://www.hackerrank.com/challenges/almost-sorted

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <vector>
#include <functional>

int main() {
  unsigned n;
  std::cin >> n;

  std::vector<unsigned> nums(n);
  std::copy_n(std::istream_iterator<unsigned>(std::cin), n, nums.begin());
  

  if (n == 2) {
    std::cout << "yes\n";
    if (nums[0] > nums[1]) {
      std::cout << "swap 1 2\n";
    } 
    return EXIT_SUCCESS;
  }

  auto left_bound = std::is_sorted_until(nums.begin(), nums.end());
  if (left_bound == nums.end()) {
    std::cout <<"yes\n";
    return EXIT_SUCCESS;
  }
  auto rright_bound = std::is_sorted_until(nums.rbegin(), nums.rend(), std::greater<unsigned>());

  auto right_bound = rright_bound.base() - 1;
  auto left_index = std::distance(nums.begin(), left_bound);
  auto right_index = std::distance(nums.begin(), right_bound + 1) + 1;

  if (left_bound >= right_bound) {
    auto l = *(left_bound - 1);
    auto r = *(left_bound + 1);
    auto m = *(left_bound);
 
    if ((m < r && r < l) || (r < l && l < m)) {
      std::cout << "no\n"; 
      return EXIT_SUCCESS;
    }
  }

  if (std::is_sorted(left_bound, right_bound + 1)) {
    std::cout << "yes\n" << "swap " << left_index  << " " << right_index;
  } else if (std::is_sorted(left_bound, right_bound + 1, std::greater<unsigned>())) {
    std::cout << "yes\n" << "reverse " << left_index << " " << right_index;
  } else {
    std::cout << "no";
  }
  std::cout << "\n";
  return EXIT_SUCCESS;
}

