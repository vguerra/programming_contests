//Victor Guerra <vguerra@gmail.com>
//2014-05-13

//http://poj.org/problem?id=1799
//POJ - 1799

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

#define PI 3.14159265

using namespace std;

int main() {
  int N; 
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    double R;
    int n;
    cin >> R >> n;

    double sin_val = sin(PI / n);
    cout << "Scenario #" << i << ":\n" << std::fixed << setprecision(3) << (R * sin_val)/(1 + sin_val) << "\n\n";

  }
  return EXIT_SUCCESS;
}
