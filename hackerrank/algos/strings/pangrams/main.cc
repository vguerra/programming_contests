//Victor Guerra <vguerra@gmail.com>
//20150326

//https://www.hackerrank.com/challenges/pangrams

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
int main() {
  uint32_t all_letters = 0;
  std::string str; 
  std::getline(std::cin, str);
  for (const auto letter : str) {
    char c = letter;
    if (std::isalpha(c)) {
      c = std::tolower(c); 
      all_letters |= 1L << (int(c) - 97);
    } 
  }
  if (all_letters != 67108863) {
    std::cout << "not ";
  }
  std::cout << "pangram\n";
  return EXIT_SUCCESS;
}
