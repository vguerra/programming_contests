//Victor Guerra <vguerra@gmail.com>
//20150204

//https://www.hackerrank.com/challenges/find-digits

#include <iostream>
#include <cstdlib>

int main() {
  unsigned T; 
  std::cin >> T; 
  while (T--) {
    std::size_t num, cp_num; 
    unsigned count = 0;
    std::cin >> num; 
    cp_num = num;
    while (cp_num) {
      unsigned last_d = cp_num % 10;
      if (last_d != 0 && num % last_d == 0) ++count;
      cp_num /= 10;
    }
    std::cout << count << "\n";
  }
  return EXIT_SUCCESS;
}
