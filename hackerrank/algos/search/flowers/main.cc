;// Victor Guerra <vguerra@gmail.com>
// 2014-03-24
//
// https://www.hackerrank.com/challenges/flowers

#include <iostream>
#include <cstdint>
#include <algorithm>


using namespace std;

int main() {
  int N, K;

  cin >> N >> K;

  uint32_t prices[N];
  uint64_t budget = 0;
  int flowers[K];

  fill(flowers, flowers + K, 0);

  for (int i = 0; i < N; ++i) {
    cin >> prices[i];
  }

  //sort(prices, prices + N, greater<uint32_t>());
  sort(prices, prices + N);

  for (int i = 0; i < N; ++i) {
    budget += (flowers[i % K] + 1) * prices[i];
    ++flowers[i % K];
  }

  cout << budget << "\n";
}
