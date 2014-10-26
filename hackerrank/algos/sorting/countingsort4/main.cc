// Victor Guerra <vguerra@gmail.com>
// 2014-03-18
//
// https://www.hackerrank.com/challenges/countingsort4
//

#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

int main() {
  uint32_t N;
  cin >> N;

  uint32_t freq[100] = {0};
  uint32_t indexes[100] = {0};
  string *strs = new string[N];
  uint32_t *nums = new uint32_t[N];
  string *sorted_strs = new string[N];

  for (uint32_t index = 0; index < N; ++index) {
    int value;
    string str;

    cin >> value >> str;
    freq[value] += 1;
    nums[index] = value;
    strs[index] = str;
  }

  uint32_t accum = 0;
  for (int i = 0; i < 100; ++i) {
    indexes[i] = accum;
    accum += freq[i];
  }

  for (uint32_t index = 0; index < N; ++index) {
    uint32_t num = nums[index];
    uint32_t sorted_index = indexes[num];
    ++indexes[num];
    if (index < N / 2) {
      sorted_strs[sorted_index] = "-";
    } else {
      sorted_strs[sorted_index] = strs[index];
    }
  }

  for (uint32_t index = 0; index < N; ++index) {
    cout << sorted_strs[index] << " ";
  }

  cout << "\n";
  return 0;
}
