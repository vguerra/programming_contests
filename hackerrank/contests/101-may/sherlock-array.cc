// Victor Guerra <vguerra@gmail.com>
// 2014-05-31
// Hacker Rank May 101 Hack.
#include <iostream>
#include <vector>
#include <numeric>
#include <cstdint>

using namespace std;
int main() {
  int T;
  cin >> T; 
  while (T--) {
    unsigned N;
    cin >> N;
    vector<unsigned> nums(N, 0);
    for (unsigned i = 0; i < N; ++i) {
      cin >> nums[i]; 
    } 
    uint64_t total = std::accumulate(nums.begin(), nums.end(), 0);
    uint64_t left = 0; 
    bool found = false;
    for (unsigned i = 0; i < N; ++i ) {
      if (left == total - left - nums[i]) {
        found = true;
        break;
      }
      left += nums[i];
    }
    if (found) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    };
  }
  return 0;
}
