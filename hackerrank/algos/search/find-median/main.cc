// Victor Guerra <vguerra@gmail.com>
// 2014-03-21
//

#include <iostream>
#include <cstdint>

using namespace std; 

uint32_t partition(int32_t *ar, uint32_t low, uint32_t high) {
  int32_t pivot = ar[high];
  uint32_t j = low; 
  for (uint32_t i = low; i < high; ++i) {
    if (ar[i] < pivot) {
      uint32_t tmp = ar[j];
      ar[j] = ar[i];
      ar[i] = tmp;
      ++j;
    } 
  }
  ar[high] = ar[j];
  ar[j] = pivot;
  return j;
} 

int32_t findOnPosition(int32_t *ar, uint32_t low, uint32_t high, uint32_t pos) {
  if (low >= high) return -1 ; 
  uint32_t foundPos; 
  while ( (foundPos =  partition(ar, low, high)) != pos) {
    if (foundPos < pos) {
      low = foundPos + 1;
    } else {
      high = foundPos - 1;
    }
  }
  //for (uint32_t i = low; i <= high; ++i) {
  //  cout << ar[i] << " ";
  //}
  //cout << "\n";

  return ar[foundPos];
}

int main() {
  uint32_t n;
  cin >> n;
  int32_t ar_[n];
  
  for (uint32_t index = 0; index < n; ++index) {
    cin >> ar_[index];
  }
  cout << findOnPosition(ar_, 0, n - 1, n / 2) << "\n";
  return 0;
}
