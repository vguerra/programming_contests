// Victor Guerra <vguerra@gmail.com>
// 2014-03-24
//
// https://www.hackerrank.com/challenges/encryption
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  char sentence[81];
  unsigned width;
  unsigned height;

  char c;

  int i = 0;
  while ((cin >> c)) {
    sentence[i] = c;
    ++i;
  }

  width = floor(sqrt(i));
  height = ceil(sqrt(i));

  if (width * height < i) {
    ++width;
  }

  if (height > width) {
    width ^= height;
    height ^= width;
    width ^= height;
  }

  sentence[i] = '\0';

  for (int col = 0; col < width; ++col) {
    for (int row = 0; row < height; ++row) {
      int index = col + width * row;
      if (index < i) {
        cout << sentence[col + width * row];
      }
    }
    cout << " ";
  }
  cout << "\n";
  return 0;
}
