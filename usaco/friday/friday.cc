/*
ID: vguerra1
PROG: friday
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

const static unsigned days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

#define START 1900
#define DAYS 7

unsigned isLeap(unsigned year) {
  return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

unsigned daysMonth(unsigned month, unsigned year) {
  if (month == 1) {
    return days[month] + isLeap(year);
  } 
  return days[month];
}

using namespace std;
int main() {
  ofstream out("friday.out");
  ifstream in("friday.in");

  if (out.is_open() && in.is_open()) {
    unsigned counts[DAYS] = {0};
    unsigned N;
    in >> N;
  
    unsigned dindex = 0;
    for (unsigned year = START; year < START + N; ++year) {
      for (unsigned m = 0; m < 12; ++m) {
        counts[dindex]++;
        dindex = (dindex + daysMonth(m, year)) % DAYS;
      }
    }

    for (unsigned i = 0; i < DAYS; ++i) {
      out << counts[i] << (i == DAYS - 1 ? "\n" : " ");
    }
    out.close();
    in.close();
  }

  return EXIT_SUCCESS;
}
