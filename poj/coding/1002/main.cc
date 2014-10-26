// Victor Guerra
// 2014-05-01

// http://poj.org/problem?id=1002
// POJ - 1002

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int lines;
  cin >> lines;
  map<string, int> table;
  list<string> duplicates;

  while (lines--) {
    string phone;
    string normalized = "";
    cin >> phone;

    for (unsigned i = 0; i < phone.size(); ++i) {
      char d = phone.at(i);
      if (isdigit(d)) {
        normalized += d;
      } else if (isalpha(d)) {
        if (65 <= d && d <= 90 && d != 'Q' && d != 'Z') {
          if (d > 'Q') d -= 1;
          d -= 65;
          normalized +=  d / 3 + 50;
        }
      }
    }
    if (table.find(normalized) != table.end()) {
      if (table[normalized] == 1) {
        duplicates.push_back(normalized);
      }
      table[normalized]++;
    } else {
      table[normalized] = 1;
    }
  }

  if (duplicates.size() != 0) {
    duplicates.sort();
    for (list<string>::iterator it = duplicates.begin(); it != duplicates.end();
         ++it) {
      string dup(*it);

      for (int i = 0; i < 3; ++i) {
        cout << dup[i];
      }
      cout << "-";
      for (int i = 3; i < 7; ++i) {
        cout << dup[i];
      }
      cout << " " << table[dup] << "\n";
    }
  } else {
    cout << "No duplicates.\n";
  }

  return 0;
}
