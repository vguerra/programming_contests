#include <string>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

bool anagramComp(std::string s1, std::string s2) {
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());
  return (s1 < s2);
}

int main () {
  std::vector<std::string> strings;
  strings.push_back("orchestra");
  strings.push_back("carthorse");
  strings.push_back("break");
  strings.push_back("baker");

  std::sort(strings.begin(), strings.end(), anagramComp);

  for (auto str : strings) {
    std::cout << str << "\n";
  }
}
