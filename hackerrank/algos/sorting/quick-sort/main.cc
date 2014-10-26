// Victor Guerra <vguerra@gmail.com>
// 2014-03-12
//
// https://www.hackerrank.com/challenges/quicksort2

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int partition(vector<int>& ar, int low, int high) {
  int pivot = ar[low];
  queue<int> lessThan;
  queue<int> greatherThan;

  for (int i = low + 1; i <= high; i++) {
    if (ar[i] < pivot) {
      lessThan.push(ar[i]);
    } else {
      greatherThan.push(ar[i]);
    }
  }

  int index = low;
  while (!lessThan.empty()) {
    ar[index++] = lessThan.front();
    lessThan.pop();
  }

  int ret = index;
  ar[index++] = pivot;

  while (!greatherThan.empty()) {
    ar[index++] = greatherThan.front();
    greatherThan.pop();
  }
  return ret;
}

void quickSortHelper(vector<int>& ar, int low, int high) {
  if (low < high) {
    int pos = partition(ar, low, high);
    quickSortHelper(ar, low, pos - 1);
    quickSortHelper(ar, pos + 1, high);

    for (int i = low; i <= high; ++i) {
      cout << ar[i] << " ";
    }
    cout << "\n";
  }
}

void quickSort(vector<int> ar, int ar_size) {
  quickSortHelper(ar, 0, ar_size - 1);
}

int main() {
  vector<int> _ar;
  int _ar_size;
  cin >> _ar_size;
  for (int _ar_i = 0; _ar_i < _ar_size; _ar_i++) {
    int _ar_tmp;
    cin >> _ar_tmp;
    _ar.push_back(_ar_tmp);
  }

  quickSort(_ar, _ar_size);

  return EXIT_SUCCESS;
}
