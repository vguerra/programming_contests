// Write a method to decide if two strings are anagrams or not.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_SIZE 50

void 
merge(char str[], int low, int middle, int high)
{
  char aux[high-low + 1];

  strcpy(aux, str);

  int i = low; 
  int j = middle + 1;
  for (int k = low; k <= high; ++k) {
    if (i > middle)
      str[k] = aux[j++];
    else if (j > high)
      str[k] = aux[i++];
    else if (aux[i] < aux[j])
      str[k] = aux[i++];
    else
      str[k] = aux[j++];
  }
}

void 
sort(char str[], int low, int high) 
{
  if (high <= low )
    return;
  int middle = low + (high - low)/2;
  sort(str, low, middle);
  sort(str, middle + 1, high);
  merge(str, low, middle, high);
}

int 
areAnagrams(char str1[], char str2[])
{
  if (str1 == NULL || str2 == NULL || strlen(str1) != strlen(str2))
    return 0;
  sort(str1, 0, strlen(str1) - 1);
  sort(str2, 0, strlen(str2) - 1);
  while (*str1 != '\0') {
    if (*str1++ != *str2++)
      return 0;
  }
  return 1;
}

int 
main(void)
{
  char str1[STRING_SIZE];
  char str2[STRING_SIZE];
  scanf("%s %s", str1, str2);

  printf("are '%s' '%s' anagrams?: ", str1, str2);
  printf("%s\n", areAnagrams(str1, str2) ? "Yes" : "No");

  return EXIT_SUCCESS;
}

