// Write a method to replace all spaces in a string with ‘%20’.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceSpaces(char str[]) 
{
  // count spaces 
  int len = strlen(str);
  int count_spaces = 0;

  for (int i = 0; i < len; ++i) {
    if (str[i] == ' ') ++count_spaces;
  }

  if (count_spaces == 0) return;


  int new_length = len + count_spaces*2;
  str = realloc(str, new_length*sizeof(char));
  str[new_length] = '\0';

  for (int i = len - 1; i >= 0; --i) {
    if (str[i] == ' ') {
      str[new_length - 1] = '0';
      str[new_length - 2] = '2';
      str[new_length - 3] = '%';
      new_length -= 3;
    } else {
      str[new_length - 1] = str[i];
      new_length -= 1;
    }
  }

}

int main(void)
{
  char *str = malloc(20*sizeof(char));
  strcpy(str, "this is the line");
  //scanf("%s", str);

  replaceSpaces(str);

  printf("Replaced str: %s\n", str);
}