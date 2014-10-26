// Q1: Implement an algorithm to determine if a string has all unique characters. 
// What if you can not use additional data structures?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// using an array indexed by the integer rep of each possible char
int has_all_unique(char s[]) {
  int counts[256];
  int val;

  memset(counts, 0, sizeof(counts));
  while( (val = *s++) != '\0') {
    if (counts[val]) 
      return 0;
    else
      ++counts[val];
  } 
  return 1;
}

// using just 2 integers of 32 bits, each bit represents weather 
// the char at this position has been found or not. 
// this works just for a-zA-Z
// 

int has_all_unique1(char s[]) {
  int32_t counts[2] = {0, 0};
  int value, index;

  while ( (value = *s++) != '\0' ) {
    index = islower(value) ? 0 : 1;
    value -= 'a';
    if (counts[index] & (1L << value))
      return 0;
    else 
      counts[index] |= (1L << value);
  }
  return 1;
}

int main() {
  char str[100];
  scanf("%s", str);
  printf("Has all unique chars?: %s\n", has_all_unique1(str) ? "Yes" : "No");

  return EXIT_SUCCESS;

}