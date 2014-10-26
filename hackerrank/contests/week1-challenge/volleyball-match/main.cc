//Victor Guerra <vguerra@gmail.com>
//2014-04-22

//https://www.hackerrank.com/contests/w1/challenges/volleyball-match

#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

uint64_t mod_pow(unsigned base, unsigned exp, unsigned modulo) {
  if (!exp) return 1;
  if (exp == 1) return base;

  uint64_t result = mod_pow(base, exp / 2, modulo);
  result = (result * result) % modulo;
  if (exp % 2) {
    result = (base * result) % modulo; 
  }
  return result;
}

// Got it from http://stackoverflow.com/a/9331125/938205
uint64_t nChoosek(uint64_t n, uint64_t k)
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    uint64_t result = n;
    for(uint64_t i = 2; i <= k; ++i ) {
        result = ((n-i+1)*(result % 1000000007)) % 1000000007;
        result /= i;
    }
    return result;
}

uint64_t scoreSequences(uint32_t A, uint32_t B) {
  if (A < B) {
    A ^= B; 
    B ^= A; 
    A ^= B;
  } 

  // we treat A as the winner
  if (A < 25) return 0;
  if (A > 25 && (A - B) != 2) return 0;
  if (A == 25 && B > 23) return 0;
  uint64_t sequences = 1;
  if (A == 25) {
    sequences = nChoosek(A + B - 1,B);
  } else {
    //sequences = 32247603683100;
    sequences = nChoosek(48, 24);
    cout << sequences << "\n";
    sequences = (1LL*sequences * mod_pow(2, B - 24, 1000000007)) % 1000000007;
  }
  return sequences;
}

int main() {
  uint32_t A, B;
  cin >> A >> B;
 
  cout << scoreSequences(A, B) % 1000000007 << "\n";
}
