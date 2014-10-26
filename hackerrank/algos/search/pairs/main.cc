// Victor Guerra <vguerra@gmail.com>
// 2014-03-27
// https://www.hackerrank.com/challenges/pairs

#include <iostream>
#include <map>

using namespace std;

int main() {
  unsigned long N; 
  unsigned long K; 
  map<unsigned long, bool> hash_table; 

  cin >> N >> K;

  while (N--) {
    unsigned long key;
    cin >> key; 
    hash_table[key] = true;
  }

  unsigned long pairs = 0; 
  for (map<unsigned long, bool>::iterator it = hash_table.begin(); it != hash_table.end(); ++it) {
    if (hash_table.find(it->first + K) != hash_table.end()) {
      ++pairs;
    }
  }

  cout << pairs << "\n";
  return 0;
}
