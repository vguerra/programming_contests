//Victor Guerra <vguerra@gmail.com>
//2014-05-03

//GCJ 2014 - Round 1B

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool matchStrings(string m, string s, unsigned& count) {
  if (m == s) return true;
  
  cout << "master is: " << m << "\n";
  cout << "working with: " << s << "\n";

  //unsigned slength = s.length();
  string::iterator it = std::unique(s.begin(), s.end());
  cout << s << "\n";
  cout << *it << "\n";
  string dups = s.substr(s.end() - it);
  cout << "found dups : " << dups << "\n";
  string::iterator it_dups = std::unique(dups.begin(), dups.end());
  unsigned unique_repeated = it_dups - dups.begin();
  s.erase(it, s.end());
  
  if (m != s) return false;

  count += unique_repeated;
  return true;
}

int main() {
  int T; 
  cin >> T;  
  
  for(int t = 1; t <= T; ++t) {
    unsigned moves = 0; 
    int N; 
    vector<string> strings;
    cin >> N;
    
    string word; 
    cin >> word; 
    string master(word);
    master.erase(std::unique(master.begin(), master.end()), master.end());
    matchStrings(master, word, moves);
    //cout << "master word is " << master << "\n";
    while (N-- - 1) {
      string str;
      cin >> str;
      sort(str.begin(), str.end());
      strings.push_back(str);
    }
    sort(strings.begin(), strings.end());
    for(auto str: strings) {
      cout << str << " ";
    }
    bool possible; 
    for (unsigned i = 1; i < strings.size() - 1; ++i) {
      possible = matchStrings(master, strings[i + 1], moves);
      if (!possible) break;
    }
    cout << "\n";
    cout << "Case #" << t << ": " << (possible ? to_string(moves).c_str() : "Fegla Won") << "\n";
  }
  return 0;
}
