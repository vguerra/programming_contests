// Victor Guerra <vguerra@gmail.com>
// 2014-03-11
//
// https://www.hackerrank.com/challenges/quicksort1
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void partition(vector<int> ar) {
  queue<int> smaller;
  queue<int> greater;

  for (vector<int>::iterator it = ar.begin() + 1; it < ar.end(); ++it) {
    if (*it <= ar[0]) {
      smaller.push(*it);
    } else {
      greater.push(*it);
    }
  }
  
  while (!smaller.empty()) {
    cout << smaller.front() << " ";
    smaller.pop();
  }
  cout << ar[0] << " ";
  while (!greater.empty()) {
    cout << greater.front() << " ";
    greater.pop();
  }
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

  partition(_ar);

  return 0;
}
