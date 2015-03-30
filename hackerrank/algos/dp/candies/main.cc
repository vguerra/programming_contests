//Victor Guerra <vguerra@gmail.com>
//20150330

//https://www.hackerrank.com/challenges/candies

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using int_t = uint64_t;

int main() {
  int_t N; 
  std::cin >> N;

  std::vector<int_t> scores(N, 0);
  std::copy_n(std::istream_iterator<int_t>(std::cin), N, scores.begin());

  std::vector<int_t> candies(N, 1);

  for (unsigned i = 1; i < N; ++i) {
    if (scores[i] > scores[i - 1]) {
      candies[i] = candies[i - 1] + 1;
    }
  }

  for (int i = N - 2; i >= 0; i--) {
    if (scores[i] > scores[i + 1]) {
      candies[i] = std::max(candies[i], candies[i + 1] + 1);
    }
  }
  std::cout << std::accumulate(candies.begin(), candies.end(), 0) << "\n";
  return EXIT_SUCCESS;
}
