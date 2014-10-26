/*
ID: vguerra1
PROG: beads
LANG: C++11
*/

#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>

#define OP(a) ((a) == 'r' ? 'b':'r')

using namespace std;

int main() {
  std::ofstream fout ("beads.out");
  std::ifstream fin ("beads.in");
  
  if (fout.is_open() && fin.is_open()) {
    unsigned N;
    string beads_str, necklace; 
    fin >> N;
    fin.ignore();
    fin >> beads_str;
    necklace = beads_str + beads_str;
    unsigned max_beads = 0;
    unsigned i = 0;
    while (i < N && necklace.at(i) == 'w') {
      ++i;
    }
    if (i == N) max_beads = N;
    if (necklace.find_first_of('r', 0) < 2*N && necklace.find_first_of('b', 0) < 2*N) {
      unsigned left = i;
      unsigned mid = 0;
      unsigned right = 0;
      unsigned acum = i;
      while (i < 2*N) {
        char b = necklace.at(i); 
        left = i; 
        mid = necklace.find_first_of(OP(b), i);
        right = necklace.find_first_of(b, mid);
        if (right < 2*N) {
          max_beads = max(max_beads, static_cast<unsigned int>(acum + right - left));
        }
        ++i;
        acum = 0;
        while (i < 2*N && necklace.at(i) == 'w') {
          ++acum;
          ++i;
        }
      }
      if (max_beads > N) {
        max_beads = N;
      }
    } else {
      max_beads = N;
    }
    fout << max_beads << "\n";
    fout.close();
    fin.close();

  }
  return EXIT_SUCCESS;
}
