/*
ID: vguerra1
PROG: gift1
LANG: C++11
*/

#define INFILE "gift1.in"
#define OUTFILE "gift1.out"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
  ifstream in (INFILE); 
  ofstream out (OUTFILE);
  
  if (in.is_open() && out.is_open()) {
    unsigned NP;
    in >> NP;
    
    vector<string> names(NP, "");
    map<string, int> money;
    
    for (unsigned i = 0; i < NP; ++i) {
      string name; 
      in >> name; 
      names[i] = name;
      money[name] = 0;
    }

    string giver;
    while (in >> giver) {
      int initial_money; 
      int receivers;
      in >> initial_money >> receivers;
      money[giver] -= initial_money;
      if (receivers == 0) {
        continue; 
      }
      int gift = initial_money/receivers;
      for (int i = 0; i < receivers; ++i) {
        string receiver; 
        in >> receiver;
        money[receiver] += gift;
      }
      money[giver] += initial_money - receivers*gift;
    }

    for (unsigned i = 0; i < NP; ++i) {
      out << names[i] << " " << money[names[i]] << "\n";
    }
    in.close();
    out.close();
  }
  return EXIT_SUCCESS;
}
