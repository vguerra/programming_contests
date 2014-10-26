//Victor Guerra <vguerra@gmail.com>
//2014-04-23

//https://www.hackerrank.com/contests/w1/challenges/p-sequences

#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>
using namespace std;


int main() {
  unsigned N;
  uint32_t P;

  uint64_t prv_series[2] = {0, 0};
  cin >> N >> P;

  uint64_t pseries = 0;
  uint64_t factor = 1;

  // for level n = 2
  for (uint32_t i = 1; i <= P; ++i) {
    pseries += (P/i);
  }

  if (N - 2 == 0) {
    cout << pseries % 1000000007 << "\n";
    return 0;
  }

  prv_series[0] = pseries;
  pseries = 0;
  // for level n = 3

  factor = P; 
  for (uint32_t i = 1; i <= P; i++) {
    pseries += (P/i)*(P/i);
  }

  if (N - 3 == 0) {
    cout << pseries % 1000000007 << "\n";
    return 0;
  }

  prv_series[1] = pseries;
  
  //for (unsigned level = 2; level < N - 2; ++level) {
    //pseries = 0;
    //factor = prv_series[level - 2];
    //for (uint32_t i = 1; i <= P; i++) {
      //pseries += factor*(P/i);
      //if (P - i > 1) {
      //if (factor != 1) {
        //factor -= 2;
        //if (factor == 0)
          //factor = 1;
        //}   
      //}
    //}
  
  //}

  cout << pseries % 1000000007 << "\n";


  return 0;
}
