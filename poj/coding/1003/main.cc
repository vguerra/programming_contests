//Victor Guerra <vguerra@gmail.com>
//2014-04-30

//http://poj.org/problem?id=1003
//POJ - 1003 

#include <iostream>

using namespace std;

int main() {
  double length;
  cin >> length;
  while (length > 0.0) {
    double seq = 0.0; 
    int cards = 0; 
    while (seq <= length) {
      ++cards;
      seq += 1.0/(cards + 1);
    }
    cout << cards << " card(s)\n";
    cin >> length;
  }
}
