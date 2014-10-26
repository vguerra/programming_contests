//Victor Guerra <vguerra@gmail.com>
//2014-05-05

//HackerRank - weekly contest
//https://www.hackerrank.com/contests/w2/challenges/manasa-and-stones

#include <iostream>
#include <set>
using namespace std;

int main() {
  int T; 
  cin >> T;
  while (T--) {
    int n, a, b;
    set<int> nums;
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i ) {
      nums.insert((n - 1 - i)*a + i*b );
    }
    for (auto num : nums) {
      cout << num << " ";
    }
    cout << "\n";
  }
  return 0;
}
