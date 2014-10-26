//Victor Guerra <vguerra@gmail.com>
//2014-05-30

//POJ - 1401
//http://poj.org/problem?id=1401

#include <iostream>

typedef unsigned long UL;

using namespace std;

UL multiplicity(UL n, UL p) {
  if (p > n) return 0;
  if (p > n/2) return 1;
  UL m = 0;
  while (n >= p) {
    n /= p;
    m += n;
  }
  return m;
}

int main() {
  unsigned int T;
  cin >> T;
  while (T--) {
    UL N;
    cin >> N;
    cout << multiplicity(N, 5) << endl;
  }
  return EXIT_SUCCESS;
}
