// Victor Guerra <vguerra@gmail.com>
// 2014-03-25
// https://www.hackerrank.com/challenges/closest-numbers
//

#include <iostream>
#include <algorithm>
#include <list>
#include <limits>
#include <cmath>

using namespace std;

int main()
{
  unsigned N; 
  cin >> N;

  int32_t arr[N];
  list<int32_t> nums;
  int32_t min_distance = std::numeric_limits<int32_t>::max();

  for (unsigned i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  sort(arr, arr + N);

  for (unsigned i = 0; i < N - 1; ++i) {
    int diff = abs(arr[i] - arr[i + 1]);
    if (diff < min_distance) {
      nums.clear();
      nums.push_back(arr[i]);
      nums.push_back(arr[i + 1]);
      min_distance = diff;
    } else if (diff == min_distance) {
      nums.push_back(arr[i]);
      nums.push_back(arr[i + 1]);
    }
  }

  for (list<int32_t>::iterator it = nums.begin(); it != nums.end(); ++it) {
    cout << *it << " ";
  }

  cout << "\n";

  return 0;
}
