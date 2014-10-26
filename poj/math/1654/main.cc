//Victor Guerra <vguerra@gmail.com>
//2014-05-30

//POJ - 1654
//http://poj.org/problem?id=1654

#include <cstdlib>
#include <cstdio>
#include <iostream>

typedef long long int LL;

struct pt {
  LL x; 
  LL y;
};

using namespace std;

#define MOVES 9
static const int movesX[MOVES] = {-1,  0,  1, -1, 0, 1, -1, 0, 1};
static const int movesY[MOVES] = {-1, -1, -1,  0, 0, 0,  1, 1, 1};

int main() {
  int T;
  cin >> T;
  cin.ignore();
  while (T--) {
    char dir;
    pt p1, p2; 
    p1.x = p1.y = 0;
    p2.x = p2.y = 0;
    LL area = 0;
    while ((cin >> dir)) {
      if (dir == '5') break;
      int id = dir - '0' - 1;
      p2.x += movesX[id];
      p2.y += movesY[id];
      area += p1.x*p2.y - p2.x*p1.y; 
      p1 = p2;
    }
    cin.ignore();
    if (area < 0) area = -area;
    if (area & 1) {
      printf("%lld.5\n",area/2);
    }
    else {
      printf("%lld\n",area/2);
    }
    cin.ignore();
  }
  return EXIT_SUCCESS;
}
