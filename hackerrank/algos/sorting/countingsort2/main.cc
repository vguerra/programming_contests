// Victor Guerra <vguerra@gmail.com>
// 2014-03-18
//
// https://www.hackerrank.com/challenges/countingsort2
//

#include <iostream>
#include <cstdint>

using namespace std;

int main() {
  uint32_t N;
  cin >> N;

  uint32_t ar_[100] = {0};

  while (N--) {
    int value;
    cin >> value;
    ar_[value] += 1;
  }

  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < ar_[i]; ++j) {
      cout << i << " ";
    }
  }
  
  cout << "\n";
  return 0;
}
