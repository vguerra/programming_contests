// Victor Guerra <vguerra@gmail.com>
// 2014-03-25
// https://www.hackerrank.com/challenges/missing-numbers

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  unsigned n, m;
  int counts[100] = {0};
  cin >> n;
  int listA[n];

  for (unsigned i = 0; i < n; ++i) {
    cin >> listA[i];
  }

  cin >> m;
  int listB[m];
  for (unsigned i = 0; i < m; ++i) {
    cin >> listB[i];
  }

  int min_val = *min_element(listB, listB + m);

  for (unsigned i = 0; i < m; ++i) {
    ++counts[listB[i] - min_val];
  }

  for (unsigned i = 0; i < n; ++i) {
    --counts[listA[i] - min_val];
  }

  for (unsigned i = 0; i < 100; ++i) {
    if (counts[i] > 0) {
      cout << min_val + i << " ";
    }
  }

  cout << "\n";

  return 0;
}
