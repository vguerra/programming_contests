//Victor Guerra <vguerra@gmail.com>
//20150203

//https://www.hackerrank.com/challenges/the-love-letter-mystery


#include <iostream>
#include <string>
#include <cstdlib>

unsigned countChanges(const std::string& w) {
  unsigned counter = 0; 
  std::size_t start = 0; 
  std::size_t end = w.size() - 1;
  
  while (end > start) {
    counter += std::abs(int(w[start]) - int(w[end]));
    --end;
    ++start;
  }
  return counter;
}

int main() {
  unsigned T; 
  std::cin >> T; 

  while (T--) {
    std::string word; 
    std::cin >> word; 
    std::cout << countChanges(word) << "\n";
  }
  return EXIT_SUCCESS;
}
