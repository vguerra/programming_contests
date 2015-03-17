//Victor Guerra <vguerra@gmail.com>
//20150317

//https://www.hackerrank.com/challenges/unbounded-knapsack

#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <vector>
#include <set>

int main() {
  unsigned T; 
  std::cin >> T; 
  while (T--) {
    unsigned n, k;
    std::cin >> n >> k;
    std::set<unsigned> num_set;

    std::copy_n(std::istream_iterator<unsigned>(std::cin), n, std::inserter(num_set, num_set.begin()));
    std::vector<unsigned> nums;
    std::copy_if(num_set.begin(), num_set.end(), std::back_inserter(nums), [k](unsigned x) {
        return x <= k;
      });

    std::size_t diff_nums = nums.size();
    std::vector<bool> dp(k + 1, false);
    dp[0] = true;
    unsigned closest_possible = k;
    for(std::size_t i = 0; i < diff_nums; ++i) {
      closest_possible = std::min(closest_possible, k % nums[i]);
      dp[nums[i]] = true;
    }

    auto get_dp_val = [&dp](int i) {
      return (i < 0 ? false : dp[i]);
    };
    for(std::size_t i = 1; i <= k ; ++i) {
      for (std::size_t j = 0; j < diff_nums; ++j ) {
        dp[i] = dp[i] | get_dp_val(i - nums[j]);
      }
    }
    std::cout << k - (dp[k] ? 0 : closest_possible) << "\n";
  }
  return EXIT_SUCCESS;  
}
