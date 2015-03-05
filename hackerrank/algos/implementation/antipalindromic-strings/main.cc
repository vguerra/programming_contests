// Victor Guerra <vguerra@gmail.com>
// 20150302

// https://www.hackerrank.com/challenges/antipalindromic-strings

#include <iostream>
#include <cstdlib>
#include <cmath>

#define MOD 1000000007

uint64_t pow_mod(uint64_t base, uint64_t exp, uint64_t mod) {
  uint64_t r = 1; 
  while (exp) {
    if (exp % 2 == 1) r = (r * (base % mod)) % mod;
    base = (base*(base % mod))%mod;
    exp /= 2;
  }
  return r % mod;
}

int main() {
  unsigned T;
  std::cin >> T;
  while (T--) {
    uint64_t M, N;
    std::cin >> N >> M;
    if (N == 1) std::cout << M; 
    else if (N == 2) std::cout << (M*(M - 1))%MOD;
    else {
      uint64_t p = pow_mod(M - 2, N - 2, MOD);
      uint64_t m = (M * (M - 1)%MOD)%MOD;
      std::cout << (m*p)%MOD;
    }
    std::cout << "\n";
  }
  return EXIT_SUCCESS;
}
