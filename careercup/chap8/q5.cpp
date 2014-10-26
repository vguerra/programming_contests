#include <iostream>
#include <string>


void printPar(int left, int right, char str[], int index) {
  if (left < 0 || right < left) return;
  if (left == 0 && right == 0) {
    std::cout << "got one right " << str << "\n";
  } else {
    if (left > 0) {
      str[index] = '(';
      printPar(left - 1, right, str, index + 1);
    }
    if (right > left) {
      str[index] = ')';
      printPar(left, right - 1, str, index + 1);
    }
  }
}

int main() {
  char *str = new char[7]; 
  printPar(3, 3, str, 0);
  int arry[3][5];
  std::cout << "size of " << sizeof(arry[0])/sizeof(arry[0][0]);
  return 0;
}
