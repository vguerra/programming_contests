/*
ID: vguerra1
PROG: ride
LANG: C++11
*/

typedef unsigned long int UINT;

#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>

UINT toNum(const std::string &s1) {
  UINT value = 1;
  for (auto c : s1) {
    value *= c - 'A' + 1;
  }
  return value % 47;
}

int main() {
  std::ofstream fout ("ride.out");
  std::ifstream fin ("ride.in");
  
  if (fin.is_open() && fout.is_open()) {
    std::string s1, s2;
    fin >> s1 >> s2;
    fout << ((toNum(s1) == toNum(s2)) ? "GO" : "STAY") << "\n";
    fin.close();
    fout.close();
  } else {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
