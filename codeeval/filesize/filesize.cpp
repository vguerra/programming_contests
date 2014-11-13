//Victor Guerra <vguerra@gmail.com>
//20141113

//https://www.codeeval.com/open_challenges/26/

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
  if (argc != 2) return 0;

  std::ifstream file(argv[1], std::ios::binary|std::ios::ate);
  if (file) {
    std::cout << file.seekg(0, std::ios::end).tellg() << "\n";
  }
  return 0;
}
