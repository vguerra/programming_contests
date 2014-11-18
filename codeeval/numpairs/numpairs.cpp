// Victor Guerra <vguerra@gmail.com>
// 20141113

// https://www.codeeval.com/open_challenges/34/

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <iterator>

int main(int argc, char *argv[]) {
  if (argc != 2) return 0;
  std::ifstream file(argv[1]);
  if (file) {
    std::string line;
    while (std::getline(file, line)) {
      //std::cerr << "'" << line << "'\n";
      if (line.size() == 0) continue;
      std::size_t semi_colon_pos = line.find(";");
      if (semi_colon_pos == std::string::npos) continue;
      std::vector<unsigned> numbers;
      //numbers.resize(semi_colon_pos / 3);

      unsigned int total_sum = std::stoul(line.substr(semi_colon_pos + 1));
      char *line_copy = new char[semi_colon_pos];
      std::strcpy(line_copy, line.substr(0, semi_colon_pos).c_str());
      for (char *num = std::strtok(line_copy, ","); num != nullptr;
           num = strtok(nullptr, ",")) {
        numbers.push_back(std::strtoul(num, nullptr, 10));
      }
      //delete line_copy;

      bool first = true;
      for (auto it = numbers.begin(); it != numbers.end();) {
        if (std::binary_search(std::next(it), numbers.end(), total_sum - *it)) {
          if (!first) {
            std::cout << ";";
          } else {
            first = false;
          }
          std::cout << *it << "," << total_sum - *it;
        }
        while (std::next(it) != numbers.end() && *std::next(it) == *it) {
          ++it;
        }
        ++it;
      }
      if (first) std::cout << "NULL";
      std::cout << "\n";
    }
  }

  return 0;
}
