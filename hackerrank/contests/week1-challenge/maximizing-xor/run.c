#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char str[150];
  unsigned left, right;

  if (argc < 3) {
    printf("Wrong # of parameters\n");
    exit(1);
  }
  left = (unsigned)strtol(argv[1], NULL, 0);
  right = (unsigned)strtol(argv[2], NULL, 0);
  
  while (right > left) {  
    sprintf(str, "echo '%u %u' | ./main", left, right);
    ++left; 
    --right;
    int r = system(str);
  }
 return 0; 
}
