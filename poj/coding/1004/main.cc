//Victor Guerra <vguerra@gmail.com>
//2013-04-30

//POJ - 1004
//http://poj.org/problem?id=1004

#define RNG(I, A, B) for (int I = (A); I < (B); ++I )

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double sum = 0;
  double input = 0;
  RNG(i, 0, 12) {
    cin >> input;
    sum += input;
  }
  cout << "$" << sum/12 << "\n";
  return 0;
}
