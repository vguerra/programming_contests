//Victor Guerra <vguerra@gmail.com>
//2014-05-18

//Hacker Rank - Bday Gift
//https://www.hackerrank.com/challenges/bday-gift

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <numeric>
using namespace std;

int main() {
  unsigned N;
  cin >> N;

  vector<uint64_t> nums(N, 0);
  for (unsigned i = 0; i < N; ++i) {
    cin >> nums[i]; 
  }
  long double probability = std::pow(0.5, N);
  uint64_t factor = (pow(2,N) - 1)/2 + 1;

  long double p = probability*factor;
  long double price = 0.0; 
  
  for (unsigned i = 0; i < N; ++i) {
    price += p * nums[i]; 
  }
  printf("%.1Lf\n", price); 
  return EXIT_SUCCESS;
}
