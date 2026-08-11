#include <stdio.h>
#include <string.h>

int my_strlen(char *s);

int main(void)
{
  char word[100];

  printf("Write word:");
  fgets(word, sizeof(word), stdin);

  size_t len = strlen(word);

  if (len > 0 && word[len - 1] == '\n')
    word[len - 1] = '\0';

  int result = my_strlen(word);

  printf("%d\n", result);
}

int my_strlen(char *s)
{
  int count = 0;
  while (*s != '\0')
  {
    count++;
    s++;
  }
  return count;
}