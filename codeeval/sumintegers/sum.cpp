//Victor Guerra <vguerra@gmail.com>
//20141113

//https://www.codeeval.com/open_challenges/24/

#include <cstdint>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) return 0;

  std::ifstream file(argv[1]);
  std::uint64_t num;
  std::uint64_t total = 0;
  if (file) {
    while (file >> num) total += num;
    std::cout << total << "\n";
  }
  return 0;
}
