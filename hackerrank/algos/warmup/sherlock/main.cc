// Victor Guerra <vguerra@gmail.com>
// 2014-03-09
//
// https://www.hackerrank.com/challenges/sherlock-and-the-beast
//

#include <iostream>
#include <cmath>
#include <string>

using namespace std; 

int main() {
  unsigned testcases; 
  cin >> testcases; 
  while (testcases--) {
    unsigned long N;
    cin >> N; 

    unsigned fives = 0, threes = 0; 
    int n; 

    while ( (n = N - 5*threes ) >= 0 ) {
      if ( n % 3 == 0) {
        fives = n / 3;
        break;
      }
      ++threes;     
    }
    if (n < 0 ) {
      cout << -1; 
    } else {
      string output = string(3*fives, '5') + string(5*threes, '3');
      cout << output;
    }
    cout << "\n";
  }
}
