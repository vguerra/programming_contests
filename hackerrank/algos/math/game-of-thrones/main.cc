//Victor Guerra <vguerra@gmail.com>
//2014-05-18

//HackerRank - Game of Thrones
//https://www.hackerrank.com/challenges/game-of-thrones

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
  int counts[26] = {0};

  string word;
  cin >> word;

  for (auto c : word) {
    ++counts[c - 'a'];
  }

  bool found_odd = false;
  for (int i = 0; i < 27; ++i) {
    if ((counts[i] % 26) == 1) {
      if (!found_odd) {
        found_odd = true;
      } else {
        cout << "NO\n";
        return EXIT_SUCCESS;
      }
    }
  }
  cout << "YES\n";
  return EXIT_SUCCESS;
}
