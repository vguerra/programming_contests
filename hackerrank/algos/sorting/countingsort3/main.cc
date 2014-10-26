// Victor Guerra <vguerra@gmail.com>
// 2014-03-18
//
// https://www.hackerrank.com/challenges/countingsort3
//

#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

int main() {
  uint32_t N;
  cin >> N;

  uint32_t ar_[100] = {0};

  while (N--) {
    int value;
    string str;
    cin >> value >> str;
    ar_[value] += 1;
  }

  uint64_t acum = 0; 
  for (int i = 0; i < 100; ++i) {
    acum += ar_[i];
    cout << acum << " ";
  }
  
  cout << "\n";
  return 0;
}
