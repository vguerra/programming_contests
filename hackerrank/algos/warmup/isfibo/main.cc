// Victor Guerra <vguerra@gmail.com>
// 2014-03-05
//
// You are given an integer N, can you check if the number is an element of
// fibonacci series? The first few elements of fibonacci series are
// 0,1,1,2,3,5,8,13…. A fibonacci series is one where every element is a sum of
// the previous two elements in the series. The first two elements are 0 and 1.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdint> 

using namespace std;

bool isPerfectSquare(long double num) {
  long double square = sqrt(num);
  return (fabs(square - rint(square)) < 0.00001); 
}

int main() {
  unsigned testcases;
  cin >> testcases; 
  
  while (testcases--) {
    uint64_t N; 
    cin >> N;
    long double power = pow(N,2);
    cout << ( (isPerfectSquare(5*power + 4) || isPerfectSquare(5*power - 4)) ? "IsFibo\n" : "IsNotFibo\n");
  }
  return EXIT_SUCCESS;
}
