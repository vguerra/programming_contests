//Victor Guerra <vguerra@gmail.com>
//20141108

//https://www.hackerrank.com/challenges/make-it-anagram

#include <iostream>
#include <string>
#include <algorithm>

unsigned int count_extra_anagram(std::string s1, std::string s2) {
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(). s2.end())

  unsigned int counter = 0;
}


int main() {
  std::string w1, w2;
  std::getline(std::cin, w1);
  std::getline(std::cin, w2);

  std::cout << count_extra_anagram(w1, w2) << "\n";
  return 0;
}
