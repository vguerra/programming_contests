#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int num, dem, start;

  cin >> num >> dem >> start; 

  double sum = 0;

  for (int i = start; i < (num/dem); ++i) {
    printf("%d / %d \n", num , 2 + i*dem);
    sum += (double)num / (2 + i*dem);
  
  }
  printf("%f\n", sum);
  return 0;
}
