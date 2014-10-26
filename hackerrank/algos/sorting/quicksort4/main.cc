// Victor Guerra <vguerra@gmail.com>
// 2014-03-19
//
// https://www.hackerrank.com/challenges/quicksort4

#include <iostream>
#include <cstdint>

using namespace std;

unsigned insertionSort(int* ar, int ar_size) {
  unsigned shifts = 0;
  for (int index = 1; index < ar_size; ++index) {
    int V = ar[index];
    int j = index - 1;
    while (j >= 0 && V < ar[j]) {
      ar[j + 1] = ar[j];
      --j;
      ++shifts;
    }
    if (j != index - 1 && ar[j + 1] != V) {
      ar[j + 1] = V;
    }
  }
  return shifts;
}

unsigned partition(int* ar, int low, int high, unsigned* pivot_pos) {
  int pivot = ar[high];
  int swaps = 0;
  int j = low;
  for (unsigned i = low; i < high; ++i) {
    if (ar[i] < pivot) {
      int tmp = ar[i];
      ar[i] = ar[j];
      ar[j] = tmp;
      j++;
      ++swaps;
    }
  }
  int tmp = ar[high];
  ar[high] = ar[j];
  ar[j] = tmp; 
  *pivot_pos = j;
  return swaps + 1;
}

unsigned quickSortShifts(int* ar, int low, int high) {
  unsigned count = 0; 
  if (low < high) {
    unsigned pivot; 
    count += partition(ar, low, high, &pivot);
    count += quickSortShifts(ar, low, pivot - 1);
    count += quickSortShifts(ar, pivot + 1, high);
  }
  return count;
}

int main() {
  unsigned N;
  cin >> N; 
  int arr1_[N];
  int arr2_[N];

  for (unsigned i = 0; i < N; ++i) {
    cin >> arr1_[i];
    arr2_[i] = arr1_[i];
  }

  cout << (int)(insertionSort(arr1_, N)  - quickSortShifts(arr2_, 0, N - 1)) << "\n";

  return 0;
}
