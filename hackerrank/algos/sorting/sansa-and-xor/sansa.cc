//Victor Guerra <vguerra@gmail.com>
//20141118

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
  unsigned T; 
  std::cin >> T; 
  
  while (T--) {
    unsigned N; 
    std::cin >> N;

    std::vector<unsigned> vec(N, 0);
    std::copy_n(std::istream_iterator<unsigned>(std::cin), N, vec.begin());
  
    unsigned total = 0;
    for (unsigned i = 1; i <=N; ++i) {
      if ((N*(i)) % 2 == 1) {
        total ^= vec.at(i - 1);
      }
    }
    std::cout << total << "\n";
  }
  return 0;
}
