//Victor Guerra <vguerra@gmail.com>
//20141117

//https://www.hackerrank.com/challenges/cut-the-sticks

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
  unsigned N;
  std::cin >> N;
  std::vector<unsigned> vec(N, 0);

  std::copy_n(std::istream_iterator<unsigned>(std::cin), N, vec.begin());
  std::sort(vec.begin(), vec.end());

  unsigned cut_length = 0; 
  for (auto it = vec.begin(); it != vec.end();) {
    std::cout << N - (it - vec.begin()) << "\n";
    cut_length = *it;
    while (*it == cut_length) ++it;
  }

  return 0;
}
