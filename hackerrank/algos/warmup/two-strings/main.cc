//Victor Guerra <vguerra@gmail.com>
//20150302

//https://www.hackerrank.com/challenges/two-strings

#include <iostream>
#include <cstdlib>
#include <string>
int main() {
  unsigned T; 
  std::cin >> T;
  std::cin.ignore(10, '\n');
  while (T--) {
    int line1_counts[28] = {0};
    std::string line1;
    std::getline(std::cin, line1);
    for (const auto& c : line1) {
      line1_counts[int(c) - 97]++;
    }
    std::string line2; 
    std::getline(std::cin, line2);
    unsigned index = 0;
    for (; index < line2.size() && line1_counts[int(line2[index]) - 97] == 0; ++index) {
    }
    if (index != line2.size()) {
      std::cout << "YES";
    } else {
      std::cout << "NO";
    }
    std::cout << "\n";
  }
  return EXIT_SUCCESS;
}
