// Victor Guerra <vguerra@gmail.com>
// 2014-04-21
// https://www.hackerrank.com/contests/w1/challenges/maximizing-xor

#include <iostream>
#include <cmath>
#include <cstdint>
using namespace std;

uint32_t maxXor(uint32_t L, uint32_t R) {
  uint32_t mask = 0;
  uint32_t extra_bits = 0;

  uint32_t bitsL = floor(log2(L) + 1);
  uint32_t bitsR = floor(log2(R) + 1);

  if (bitsL == bitsR) {
    uint32_t bitsDiff = floor(log2(L ^ R) + 1);

    uint32_t filter =  ~(~0 << bitsDiff); 
    L &= filter;
    R &= filter;

    extra_bits = bitsL - bitsDiff;

  }

  for (int i = 0; i < floor(log2(R - L) + 1) + extra_bits; ++i) {
    mask = (mask << 1) | 1; 
  }
  return mask; 
}

int main() {
  uint32_t L, R; 

  cin >> L >> R;

  cout << maxXor(L, R) << "\n";
  return 0;
}
