//Victor Guerra <vguerra@gmail.com>
//2014-05-17

//HackerRank - IceCream Parlor
//https://www.hackerrank.com/challenges/icecream-parlor

#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <list>
using namespace std;

int main() {
  int T; 
  cin >> T;
  while (T--) {
    unsigned M, N;
    cin >> M >> N;

    map<int, list<unsigned> > hash;
    vector<int> prices(N, 0); 
    for (unsigned i = 0; i < N; ++i) {
      cin >> prices[i]; 
      hash[prices[i]].push_back(i);
    }
  
    for (unsigned i = 0; i < N; ++i) {
      int look_price = (int)M - prices[i];
      cout << "looking for:" << look_price << endl;
      if (hash.find(look_price) != hash.end()) {
        list<unsigned>::iterator runner = hash[look_price].begin();
        while (*runner == i) {
          ++runner;
        }
        if (runner != hash[look_price].end()) {
          cout << i + 1 << " " << *runner + 1 << "\n";
          break;
        }
      }
    } 
  }
  return EXIT_SUCCESS;
}

