//Victor Guerra <vguerra@gmail.com>
//20141108

//https://www.hackerrank.com/challenges/make-it-anagram

#include <iostream>
#include <string>
#include <algorithm>

unsigned int count_extra_anagram(std::string s1, std::string s2) {
  unsigned int counter = 0;
  
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());

  auto it1 = s1.begin();
  auto it2 = s2.begin();

  while (it1 != s1.end() && it2 != s2.end()) {
    if (*it1 < *it2) {
      ++it1;
    } else if (*it2 < *it1) {
      ++it2;
    } else {
      counter += 2;
      ++it1;
      ++it2;
    }
  }

  return s1.length() + s2.length() - counter;
}

int main() {
  std::string w1, w2;
  std::getline(std::cin, w1);
  std::getline(std::cin, w2);

  std::cout << count_extra_anagram(w1, w2) << "\n";
  return 0;
}
