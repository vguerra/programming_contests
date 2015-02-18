// Victor Guerra <vguerra@gmail.com>
// 20150204

// https://www.hackerrank.com/challenges/sherlock-and-queries

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <algorithm>

#define MOD 1000000007

int main() {
  unsigned N, M;
  std::cin >> N >> M;
  std::vector<std::size_t> A(N);
  std::vector<unsigned> B(M);
  std::vector<unsigned> C(M);
  std::vector<std::size_t> factors(N, 1);

  std::copy_n(std::istream_iterator<std::size_t>(std::cin), N, A.begin());
  std::copy_n(std::istream_iterator<unsigned>(std::cin), M, B.begin());
  std::copy_n(std::istream_iterator<unsigned>(std::cin), M, C.begin());

  for (unsigned i = 0; i < M; ++i) {
    factors[B[i] - 1] = ((factors[B[i] - 1]%MOD)*C[i])%MOD; 
  }

  for (unsigned k = 0; k < N; ++k) {
    if (factors[k] != 1) {
      for (unsigned index = k; index < N; index += k + 1) {
        A[index] = ((factors[k]%MOD)*(A[index]%MOD))%MOD;
      }
    }
  }

  for (auto const& n : A) {
    std::cout << n << " ";
  }
  
  return EXIT_SUCCESS;
}
