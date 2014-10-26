#include <iostream>
#include <vector>
using namespace std;

unsigned maxXor(unsigned L, unsigned R) {
  unsigned max = 0;
  vector<unsigned> answer(2, 0);
  for (unsigned i = L; i <= R; ++i) {
    for (unsigned j = i; j <= R; ++j) {
      if (max < (i ^ j)) {
        max = i ^ j;
        answer[0] = i;
        answer[1] = j;
      }
    }
  }
  cout << "nums: " << answer[0] << ", " << answer[1] << "\n";
  return max;
}

int main() {
  unsigned L, R; 
  cin >> L >> R; 

  cout << maxXor(L, R) << "\n";
  return 0;
}
