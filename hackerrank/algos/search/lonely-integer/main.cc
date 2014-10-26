//Victor Guerra <vguerra@gmial.com>
//2014-03-24
//
//https://www.hackerrank.com/challenges/lonely-integer

#include <iostream>
#include <algorithm>

using namespace std; 

int main()
{
  int N; 
  cin >> N;
  int nums[N];

  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
  }

  sort(nums, nums + N);

  int index = 0; 
  while (index < (N - 1) && nums[index] == nums[index + 1]) {
    index += 2; 
  }

  cout << nums[index] << "\n";

  return 0;
}
