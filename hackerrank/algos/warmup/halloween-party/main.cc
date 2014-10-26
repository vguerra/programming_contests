// Victor Guerra <vguerra@gmail.com>
// 2014-03-04
//
// https://www.hackerrank.com/challenges/halloween-party 

#include <iostream>
#include <cstdlib>

using namespace std;

unsigned long long cakePieces(unsigned long long cuts) {
  unsigned r = cuts % 2;
  unsigned long long ret = ((cuts/2 + r) * (unsigned long long)(cuts/2));
  return ret;
}

int main() {
  unsigned testcases; 
  cin >> testcases; 

  while (testcases--) {
    unsigned long long cuts; 
    cin >> cuts; 
    cout << cakePieces(cuts) << "\n";
  }

  return EXIT_SUCCESS;
}
