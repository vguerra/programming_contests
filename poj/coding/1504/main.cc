//Victor Guerra <vguerra@gmail.com>
//2014-05-04

//http://poj.org/problem?id=1504
//POJ - 1504

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std; 

void reverseStr(char *str) {
  unsigned len = strlen(str);
  char *end = str + len - 1;
  while (str < end) {
    *str ^= *end;
    *end ^= *str;
    *str ^= *end;
    ++str; 
    --end;
  }
}

int main() {
  int N; 
  cin >> N; 
  
  while (N--) {
    char one[30], two[30], sumR[30];
    unsigned sum;
    scanf("%s %s\n", one, two);

    reverseStr(one); 
    reverseStr(two);
    sum = std::atoi(one) + std::atoi(two);
    sprintf(sumR, "%d", sum);
    reverseStr(sumR);
    cout << std::atoi(sumR) << "\n"; 
  }
  return 0;
}
