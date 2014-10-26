// Victor Guerra <vguerra@gmail.com>
// 2013-03-03

// Little Bob loves chocolates and goes to the store with a $N bill with $C
// being the price of each chocolate. In addition, the store offers a discount:
// for every M wrappers he gives the store, he’ll get one chocolate for free.
// How many chocolates does Bob get to eat?

#include <iostream>

using namespace std;

unsigned eatenChocolates(unsigned dollars, unsigned price, unsigned wrappers) {
  unsigned eaten = dollars / price;
  unsigned wrappers_left = eaten;

  while (wrappers_left >= wrappers) {
    unsigned eaten_now = wrappers_left / wrappers;
    wrappers_left = eaten_now + (wrappers_left % wrappers);
    eaten += eaten_now;
  }

  return eaten;
}

int main() {
  unsigned testcases;

  cin >> testcases;

  while (testcases--) {
    unsigned N, C, M;
    cin >> N >> C >> M;
    cout << eatenChocolates(N, C, M) << "\n";
  }

  return 0;
}
