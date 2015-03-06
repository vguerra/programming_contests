//Victor Guerra <vguerra@gmail.com>
//20150306

//https://www.hackerrank.com/challenges/jim-and-the-jokes

#include <iostream>
#include <cstdlib>
#include <vector>

unsigned base_10(unsigned base, unsigned num) {
  if (base == 10) return num;
  unsigned r = 0;
  unsigned mul = 1;
  while (num) {
    unsigned low = num % 10; 
    if (low >= base) return 0;
    r += mul*low;
    mul *= base;
    num /= 10;
  }
  return r;
}

int main() {
  uint64_t N;
  std::cin >> N;
  std::vector<uint64_t> events(500, 0);
  uint64_t jokes = 0;
  while (N--) {
    unsigned base, num;
    std::cin >> base >> num;
    unsigned event10 = base_10(base, num);
    if (event10 != 0) {
      if (events[event10] != 0) {
        jokes += events[event10];
      } 
      ++events[event10];
    }
  }
  std::cout << jokes << "\n";
  return EXIT_SUCCESS;
}
