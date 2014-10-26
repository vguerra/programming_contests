// The Utopian tree goes through 2 cycles of growth every year. The first growth
// cycle of the tree is during the monsoon season when it doubles in height. The
// second growth cycle is during the summer when it increases in height by 1
// meter. If a new Utopian tree sapling of height 1 meter is planted just before
// the onset of the monsoon season, can you find the height of the tree after N
// cycles?

// Victor Guerra <vguerra@gmail.com>
// 2014-03-03


#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

unsigned utopianHeight(unsigned cycles) {
  unsigned acumm = 0;
  unsigned mod2 = cycles % 2;
  for (int i = mod2; i <= (cycles + mod2) / 2; ++i) {
    acumm += 1L << i;
  }
  return acumm;
}

int main() {
  unsigned testcases;

  cin >> testcases;

  while (testcases--) {
    unsigned cycles;
    cin >> cycles;
    cout << utopianHeight(cycles) << "\n";
  }

  return EXIT_SUCCESS;
}
