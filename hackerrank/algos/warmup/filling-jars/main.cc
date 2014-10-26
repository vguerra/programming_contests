// Victor Guerra <vguerra@gmail.com>
// 2014-03-05

// Animesh has N empty candy jars numbered from 1 to N with infinite capacity.
// He performs M operations. Each operation is described by 3 integers a, b and
// k where a and b are index of the jars and k is the number of candies to be
// added inside each jar with index between a and b (both inclusive). Can you
// tell the average number of candies after M operations?

#include <iostream>
#include <cstdint>

using namespace std;

int main() {
  unsigned N, M;
  cin >> N >> M;

  long double total = 0.0;
  while (M--) {
    unsigned a, b, k;
    cin >> a >> b >> k;
    total += (double)(b - a + 1) * k / N;
  }
  cout << (unsigned long)total << "\n";
}
