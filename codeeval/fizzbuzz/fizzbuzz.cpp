//Victor Guerra <vguerra@gmail.com>
//20141112

//https://www.codeeval.com/open_challenges/1/

#include <fstream>
#include <iostream>
#include <array>
#include <string>

int main(int argc, char *argv[]) {
  if (argc != 2) return 0;
  std::ifstream file(argv[1]);
  if (file.is_open()) {
    std::array<std::string, 3> labels = {{"F", "B", "FB"}};
    int x, y, n;
    while ((file >> x >> y >> n)) {
      for (int i = 1; i <= n; ++i) {
        unsigned index = 0; 
        index |= (i % y == 0) << 1;
        index |= (i % x == 0); 
        if (index != 0) {
          std::cout << labels[index - 1];
        } else {
          std::cout << i; 
        }
        if (i < n) std::cout << " ";
      }
      std::cout << "\n";
    }
  }
  return 0;
}
