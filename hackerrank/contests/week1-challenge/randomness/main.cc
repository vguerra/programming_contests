//Victor Guerra <vguerra@gmail.com>
//2014-04-24

//https://www.hackerrank.com/contests/w1/challenges/randomness

#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;

unsigned LCP(const std::string & str1, const std::string& str2) {
  unsigned count = 0;
  for (unsigned i = 0; i < std::min(str1.size(), str2.size()); ++i) {
    if (str1.at(i) != str2.at(i)) {
      return count;
    }
    ++count;
  }
  return count;
}

uint32_t countSubstrings(vector<string> suffixes) {
  uint32_t count = 0; 

  std::sort(suffixes.begin(), suffixes.end());
  
  count = suffixes[0].size();
  for (unsigned i = 0; i < suffixes.size() - 1; ++i) {
    count += suffixes[i + 1].size() - LCP(suffixes[i], suffixes[i + 1]);
  }
  return count;
}


int main() {
  unsigned N, Q;

  std::string str;

  cin >> N >> Q >> str;

  uint64_t subs = 0; 
  
  while (Q--) {
    unsigned pos; 
    char c;
    cin >> pos >> c; 
    vector<string> suffixes;
    str.replace(pos - 1, 1, 1, c);
    // building suffixes
    for (unsigned p = 0; p < N; ++p) {
      suffixes.push_back(str.substr(p, N - p));
    }
    subs = countSubstrings(suffixes);
    
    cout << subs << "\n";
  }

  return 0;
}
