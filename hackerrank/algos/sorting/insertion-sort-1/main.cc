// Victor Guerra <vguerra@gmail.com>
// 2014-03-10
//
// https://www.hackerrank.com/challenges/insertionsort1
//

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void insertionSort(vector<int> ar) {
  unsigned size = ar.size();
  int V = ar[size - 1];
  int index = size - 2;
  while (V < ar[index]) {
    ar[index + 1] = ar[index];
    index--;
    for (unsigned i = 0; i < size; ++i) {
      cout << ar[i] << " ";
    }
    cout << "\n";
  }
  ar[index + 1] = V;
  for (unsigned i = 0; i < size; ++i) {
    cout << ar[i] << " ";
  }
  cout << "\n";
}

int main(void) {
  vector<int> _ar;
  int _ar_size;
  cin >> _ar_size;
  for (int _ar_i = 0; _ar_i < _ar_size; _ar_i++) {
    int _ar_tmp;
    cin >> _ar_tmp;
    _ar.push_back(_ar_tmp);
  }

  insertionSort(_ar);

  return 0;
}
