//Victor Guerra <vguerra@gmail.com>
//2014-05-31
//Hacker Rank May 101 Hack.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <limits>
#include <utility>
#include <cstdlib>

using namespace std;

int main() {
  unsigned N;
  cin >> N;

  vector<uint32_t> nums(N, 0);
  uint32_t P, Q;
  for (unsigned i = 0; i < N; ++i) {
    cin >> nums[i];    
  }
  cin >> P >> Q;

  sort(nums.begin(), nums.end());

  auto res = std::minmax_element(nums.begin(), nums.end());
  uint32_t ans = 0;

  if (*res.second <= P ) {
    ans = Q; 
  } else if (Q <= *res.first) {
    ans = P;
  } else {
    uint32_t max = 0;
    uint32_t max_val = 0;
    for (uint32_t x = P; x <= Q; ++x) {
      uint32_t min = numeric_limits<uint32_t>::max(); 
      for (unsigned i = 0; i < N; ++i) {
        uint32_t diff = abs((int)(nums[i] - x));
        if (diff < min ) min = diff;
      }
      if (min > max) {
        max = min;
        max_val = x;
      }
    }
    ans = max_val;
  }
  cout << ans << endl;
  return 0;
}
