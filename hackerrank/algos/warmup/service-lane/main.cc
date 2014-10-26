// Victor Guerra <vguerra@gmail.com>
// 2014-03-06
//
// https://www.hackerrank.com/challenges/service-lane

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  unsigned N, T;
  cin >> N >> T;
  vector<int> widths(N);
  for (int k = 0; k < N; ++k) {
    cin >> widths[k];
  }

  while (T--) {
    int i, j;
    cin >> i >> j;
    int allowed_width = widths[i];
    for (int k = i + 1; k <= j; ++k) {
      allowed_width = min(allowed_width, widths[k]);
    }
    cout << allowed_width << "\n";
  }
  return 0;
}
