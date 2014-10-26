//Victor Guerra <vguerra@gmail.com>
//2014-05-11

//Google Code Jam - Round 1C
//Part Elf Problem.


#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

bool hasElfParents(int64_t P, int64_t Q) {
  if (P - Q == 0 || P - Q == 1) return true;
  while (P/Q < 1 && Q % 2 == 0) {
    Q /= 2;
  }
  if (Q % 2) return false;
  if (P - Q == 1 || P - Q == 0) {
    return true;
  } else {
    return hasElfParents(P - Q, Q);
  }
}

int main() {
  int T; 
  cin >> T; 
  for (int i = 1; i <= T; ++i) {
    int64_t P,Q; 
    scanf("%lld/%lld", &P, &Q);
    
    uint32_t generations = 0;
    while (P/Q < 1 && Q % 2 == 0) {
      Q /= 2;
      ++generations;
    }

    cout << "Case #" << i << ": ";
    if (hasElfParents(P, Q)  && generations > 0) {
      cout << generations; 
    } else {
      cout << "impossible";
    }
    cout << "\n";
  }
  return 0;
}
