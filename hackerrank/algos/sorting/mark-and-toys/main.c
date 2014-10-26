// Victor Guerra <vguerra@gmail.com>
// 2014-03-19
//
// https://www.hackerrank.com/challenges/mark-and-toys

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int comp(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int main() {
  uint32_t N; 
  int32_t K;
  
  scanf("%"SCNu32 , &N);
  scanf("%"SCNi32, &K);

  uint32_t prices_[N];

  for (uint32_t i = 0; i < N; ++i) {
    scanf("%"SCNu32, &prices_[i]);
  }

  qsort(prices_, N, sizeof(prices_[0]), comp);

  uint32_t presents = 0;
  uint32_t index = 0; 
  while (index < N && (K -= prices_[index++]) > 0) {
    ++presents;
  }

  printf("%"PRIu32"\n", presents);
  return 0;
}
