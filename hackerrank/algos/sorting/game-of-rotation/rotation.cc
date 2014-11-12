//Victor Guerra <vguerra@gmail.com>
//20141111

//https://www.hackerrank.com/challenges/game-of-rotation

#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
  int32_t N;

  std::cin >> N;

  std::vector<int32_t> vec(N);
  std::copy_n(std::istream_iterator<int32_t>(std::cin), N, vec.begin());

  int64_t max_PMEAN = 0;
  int64_t cur_PMEAN = 0;
  int64_t sum_elements = 0;
  int64_t index = 1;

  std::for_each(vec.begin(), vec.end(), [&cur_PMEAN, &sum_elements, &index](int32_t x) {
        cur_PMEAN += index*x;
        sum_elements += x;
        ++index;
      });
  max_PMEAN = cur_PMEAN;
  for (auto& num : vec) {
    cur_PMEAN = cur_PMEAN - sum_elements + N*num;
    if (max_PMEAN < cur_PMEAN) {
      max_PMEAN = cur_PMEAN;
    }
  } 
  std::cout << max_PMEAN << "\n";
  return 0;
}
