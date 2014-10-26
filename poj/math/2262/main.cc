//Victor Guerra <vguerra@gmail.com>
//2014-05-30

//POJ - 2262
//http://poj.org/problem?id=2262

#include <cstdlib>
#include <iostream>

typedef unsigned long UL;

using namespace std;

// num will never be <= 2
bool isPrime (UL num) {
  if (num == 2) return true;
  if (num % 2 == 0) return false;
  for (UL i = 3; i*i <= num; i += 2) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  UL N; 
  while ((cin >> N)) {
    if (N == 0) break;
    UL left = 0; 
    UL right = 0; 
    for (UL i = 2; i <= N/2; i += 1) {
      if (isPrime(i) && isPrime(N - i)) {
        left = i; 
        right = N - i;
        break;
      }
    }
    if (left + right != 0) {
      cout << N << " = " << left << " + " << right << endl;
    } else {
      cout << "Goldbach's conjecture is wrong." << endl;
    }
  }
  return EXIT_SUCCESS;
}
