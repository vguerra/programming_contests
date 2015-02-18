//Victor Guerra <vguerra@gmail.com>
//20150203

//https://www.hackerrank.com/challenges/alternating-characters

#include <iostream>
#include <cstdlib>
#include <string>

std::size_t countDeletes(std::string& word) {
  std::size_t deletes = 0;
  for (std::size_t i = 0; i < word.size() - 1;) {
    while (word[i] == word[i+1]) {
      ++i;
      ++deletes;
    }
    ++i;
  }
  return deletes; 
}

int main() {
  unsigned T;
  std::cin >> T;

  while (T--) {
    std::string word; 
    std::cin >> word; 
    std::cout << countDeletes(word) << "\n";
  }
  return EXIT_SUCCESS;
}
