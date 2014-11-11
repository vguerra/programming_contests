//Victor Guerra <vguerra@gmail.com>
//20141111

//https://www.hackerrank.com/challenges/sherlock-and-watson

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

int main() {
  uint32_t N, K, Q, x;
  std::cin >> N >> K >> Q;
  
  std::vector<unsigned> vec(N);
  std::copy_n(std::istream_iterator<unsigned>(std::cin), N, vec.begin());
  std::cout << N << " " << K << " " << Q << "\n"; 
  std::cout << "size: " << vec.size() << "\n";
  std::rotate(vec.rbegin(), vec.rbegin() + (K % N), vec.rend());

  while (Q--) {
    std::cin >> x;
    std::cout << vec[x] << "\n";
  }
  return 0;
}
