// Victor Guerra <vguerra@gmail.com>
// 2014-03-11

// https://www.hackerrank.com/challenges/tutorial-intro
//

#include <cstdlib>
#include <iostream>

using namespace std;

int findPosition(int *arr, unsigned size, int num) {
  int low = 0; 
  int high = size - 1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (num < arr[mid]) {
      high = mid - 1;
    } else if ( num > arr[mid]) {
      low = mid + 1; 
    } else {
      return mid;
    }
  }
  return -1; 
}

int main() {
  int num; 
  unsigned size; 
  cin >> num >> size; 

  int arr[size];

  for (int i = 0; i < size ; ++i) {
    cin >> arr[i];

  }

  cout << findPosition(arr, size, num) << "\n";

  return EXIT_SUCCESS; 

}
