//Victor Guerra <vguerra@gmail.com>
//2014-05-17

//HackerRank - Find Point
//https://www.hackerrank.com/challenges/find-point

#include <iostream>
#include <cstdlib>


using namespace std;

int main() {
  int T; 
  cin >> T;
  while (T--) {
    int Px, Py, Qx, Qy;
    cin >> Px >> Py >> Qx >> Qy;
    cout << -Px + 2*Qx << " " << -Py + 2*Qy << "\n";
  }
  return EXIT_SUCCESS;
}
