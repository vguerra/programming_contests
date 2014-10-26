//Victor Guerra <vguerra@gmail.com>
//2014-05-21

//Hacker Rank - Sam and Substrings
//https://www.hackerrank.com/contests/w3/challenges/sam-and-substrings

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#define MOD 1000000007 
#define toINT(x) (x - '0')

int main () {
  uint64_t total = 0;
  string N;
  cin >> N;
 
  size_t len = N.length();
  uint64_t factor = 1;
  
  for (unsigned i = 0; i < len; ++i) {
    int num = toINT(N[len - 1 - i]);
    total += (len - i)*num*factor;
    total %= MOD;
    factor = factor*10 + 1;
    factor %= MOD;
  }
  cout << total << "\n";
  return EXIT_SUCCESS;
}
