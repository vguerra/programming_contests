//Victor Guerra <vguerra@gmail.com>
//2014-05-20

//Hacker Rank - The Love-Letter Mystery
//https://www.hackerrank.com/contests/w3/challenges/the-love-letter-mystery

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

uint64_t moves(const char* str, size_t len) {
  uint64_t count = 0; 
  
  size_t start = 0; 
  size_t end = len - 1;

  while (start < end) {
    count += abs(str[start] - str[end]);
    ++start; 
    --end;
  }
  return count;
}

int main() {
  unsigned T; 
  cin >> T; 

  while (T--) {
    string str; 
    cin >> str; 
    cout << moves(str.c_str(), str.length()) << endl;
  }
  return EXIT_SUCCESS;
}
