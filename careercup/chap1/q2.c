// Write code to reverse a C-Style String. 
// (C-String means that “abcd” is represented as five characters, 
// including the null character.)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str) 
{
  char *end;
  if (str) {
    end = str + strlen(str) - 1;
    for (; str < end ; ++str, --end) {
      *str ^= *end;
      *end ^= *str;
      *str ^= *end;
    }
  }
}

int main(void)
{
  char *string = malloc(100*sizeof(char));
  scanf("%s", string);

  reverse(string);

  printf("Reversed: %s\n", string);

  return EXIT_SUCCESS;

}