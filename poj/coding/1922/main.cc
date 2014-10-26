// Victor Guerra <vguerra@gmail.com>
// 2014-05-09

// http://poj.org/problem?id=1922
// POJ - 1922

#define DIST 4.5

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cmath>

using namespace std;

int timeToY(int speed, int offset) {
  return offset + ceil(DIST/speed*3600);
}

int main() {
  int N;
  while (cin >> N) {
    if (N == 0) {
      break;
    }

    int time = INT_MAX;
    for (int i = 0; i < N; ++i) {
      int speed; 
      int offset;
      cin >> speed >> offset; 
      if (offset >= 0) {
        time = min(time, timeToY(speed, offset));
      }
    }
    cout << time << "\n";
  }
  return 0;
}
