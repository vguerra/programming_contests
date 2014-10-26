// Victor Guerra <vguerra@gmail.com>
// 2014-03-10

// https://www.hackerrank.com/challenges/insertionsort2

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

void insertionSort(int ar_size, int* ar) {
  for (int index = 1; index < ar_size; ++index) {
    int V = ar[index];
    int j = index - 1;
    while (j >= 0 && V < ar[j]) {
      ar[j + 1] = ar[j];
      --j;
    }
    if (j != index + 1) {
      ar[j + 1] = V;
      for (int i = 0; i < ar_size; ++i) {
        cout << ar[i] << " ";
      }
      cout << "\n";
    }
  }
}
int main(void) {

  int _ar_size;
  cin >> _ar_size;
  // scanf("%d", &_ar_size);
  int _ar[_ar_size], _ar_i;
  for (_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
    cin >> _ar[_ar_i];
    // scanf("%d", &_ar[_ar_i]);
  }

  insertionSort(_ar_size, _ar);

  return 0;
}
