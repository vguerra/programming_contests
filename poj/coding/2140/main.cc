//Victor Guerra <vguerra@gmail.com>
//2014-05-03

//http://poj.org/problem?id=2140
//POJ 2140

#include <iostream>

using namespace std;

int main() {
  unsigned long N;
  cin >> N;
  unsigned count = 1;
  unsigned top = 0;

  unsigned j = 1; 
  while ((top += j) < N) {
    ++j;
  }
  for (unsigned i = 2; i <= j; ++i) {
    unsigned mid = N/i;
    if (2*N == i*(2*mid + (i%2 == 0))) {
      ++count;
    }
  }
  cout << count << "\n";
}
