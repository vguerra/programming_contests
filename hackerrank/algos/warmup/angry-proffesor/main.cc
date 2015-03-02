//Victor Guerra <vguerra@gmail.com>
//20150302

//https://www.hackerrank.com/challenges/angry-professor

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <vector>

int main() {
  unsigned T;
  std::cin >> T;
  while (T--) {
    unsigned N, K;
    std::cin >> N >> K;
    std::vector<int> numbers(N);
    std::copy_n(std::istream_iterator<int>(std::cin), N, numbers.begin());
    if (K <= std::count_if(numbers.begin(), numbers.end(), [](int i) { return i < 1;})) {
      std::cout << "NO";
    } else {
      std::cout << "YES";
    }
    std::cout << "\n";
  }
  return EXIT_SUCCESS;
}
