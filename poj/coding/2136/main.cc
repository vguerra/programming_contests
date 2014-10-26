//Victor Guerra <vguerra@gmail.com>
//2014-05-03

//http://poj.org/problem?id=2136
//POJ 2136

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main() {
  int counts[26] = {0};
  int maxlines = 0;
  for (int l = 0; l < 4; ++l) {
    string line; 
    getline(cin, line);

    for (unsigned i = 0; i < line.length(); ++i) {
      char c = line[i];
        if (isalpha(c)) {
          unsigned index = c - 'A'; 
          ++counts[index];
          if (counts[index] > maxlines) {
            maxlines = counts[index];
          }
        }
    }
  } 
  for (int i = maxlines; i > 0; --i) {
    stringstream sout;
    for (int j = 0; j < 26; ++j) {
      sout << (counts[j] >= i ? "*": " ");
      if (j != 26) {
        sout << " ";
      }
    }
    sout << "\n";
    cout << sout.str(); 
  }
  for (int i = 65; i < 91; ++i) {
    cout << char(i);
    if (i != 90) {
      cout << " ";
    }
  }
  cout << "\n";
  return 0;
}
