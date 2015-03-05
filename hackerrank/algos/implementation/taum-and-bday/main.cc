//Victor Guerra <vguerra@gmail.com>
//20150305

//https://www.hackerrank.com/challenges/taum-and-bday

#include <iostream>
#include <cstdlib>

int main() {
  unsigned T;
  std::cin >> T; 
  while (T--) {
    uint64_t X, Y, Z, B, W;
    std::cin >> B >> W >> X >> Y >> Z;

    if (Y + Z < X) {
      std::cout << (B + W)*Y + B*Z;
    } else if (X + Z < Y) {
      std::cout << (B + W)*X + W*Z;
    } else {
      std::cout << B*X + W*Y;
    }
    std::cout << "\n";
  }
  return EXIT_SUCCESS;
}
