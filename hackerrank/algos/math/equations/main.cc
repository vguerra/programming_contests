// Victor Guerra <vguerra@gmail.com>
// 2014,-05-19

// Hacker Rank - Equations
// https://www.hackerrank.com/challenges/equations

#include <iostream>
#include <cstdlib>
#include <cstdio>

bool isPrime(uint32_t n) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;

  for (uint32_t i = 3 ; i*i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

uint32_t multiplicity(uint32_t n, uint32_t p) {
  if (p > n) return 0;
  if (p > n/2) return 1;
  uint32_t m = 0;
  while (n >= p) {
    n /= p;
    m += n;
  }
  return m;
}

#define MOD 1000007 

using namespace std;

int main() {
  uint32_t N;
  cin >> N;

  uint64_t count = 1;
  for (uint32_t i = 2; i <= N; ++i) {
    if (isPrime(i)) {
      count *= (2*multiplicity(N, i)%MOD + 1)% MOD;
      count %= MOD;
    }
  }

  cout << count << endl;
  return EXIT_SUCCESS;
}
