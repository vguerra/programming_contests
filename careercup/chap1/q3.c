// Design an algorithm and write code to remove the duplicate 
// characters in a string without using any additional buffer. 
// NOTE: One or two additional variables are fine. An extra copy of the array is not.
// FOLLOW UP
// Write the test cases for this method.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void removeDup(char *str) 
{
  if (str) {
    int len = strlen(str);
    int hits[256];
    hits[0] = 1; 
    if (len < 2) return;
    int tail = 1; 
    for (int i = 1; i < len; ++i) {
      if (hits[(int)str[i]] == 0) {
        str[tail++] = str[i]; 
        ++hits[(int)str[i]]; 
      } 
    }
    str[tail] = '\0';
  } 
}

int main(void)
{
  char str[100];
  int c, count = 0;

  while ( (c = getchar()) != '\n') {
    str[count++] = c;
  }
  str[count] = '\0';
  //scanf("%s", str);
  // we read line
  

  removeDup(str);

  printf("Spaces removed: %s\n", str);
}