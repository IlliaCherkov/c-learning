#include <stdio.h>
#include <string.h>

char *my_strtok(char *str, const char *delim, const char *quotes)
{
  static char *last_pos = NULL;
  if (str != NULL)
  {
    last_pos = str;
  }
  if (last_pos == NULL || *last_pos == '\0')
  {
    return NULL;
  }

  char *token_start = last_pos;

  while (*token_start != '\0')
  {
    int is_delim = 0;
    for (int i = 0; delim[i] != '\0'; i++)
    {
      if (*token_start == delim[i])
      {
        is_delim = 1;
        break;
      }
    }
    if (!is_delim)
    {
      break;
    }
    token_start++;
  }

  if (*token_start == '\0')
  {
    last_pos = token_start;
    return NULL;
  }

  int in_quotes = 0;
  char is_comp = '\0';
  for (int j = 0; quotes[j] != '\0'; j++)
  {

    if (*token_start == quotes[j])
    {
      in_quotes = !in_quotes;
      is_comp = *token_start;
      token_start++;
      continue;
    }
  }
  char *token_end = token_start;

  while (*token_end != '\0')
  {
    int is_delim = 0;
    for (int i = 0; delim[i] != '\0'; i++)
    {
      if (*token_end == is_comp)
      {
        is_delim = 1;
        break;
      }
      else if (*token_end == delim[i] && in_quotes == 0)
      {
        is_delim = 1;
        break;
      }
    }
    if (is_delim)
    {
      *token_end = '\0';
      last_pos = token_end + 1;
      return token_start;
    }
    token_end++;
  }

  last_pos = token_end;
  return token_start;
}

int main(void)
{

  char line[256];
  if (fgets(line, sizeof(line), stdin) == NULL)
  {
    printf("\n");
  }

  if (line[strlen(line) - 1] == '\n')
  {
    line[strlen(line) - 1] = '\0';
  }

  char *args[64];

  args[0] = my_strtok(line, " ", "\",\'");
  args[1] = my_strtok(NULL, " ", "\",\'");
  args[2] = my_strtok(NULL, " ", "\",\'");

  for (int i = 0; i < 3; i++)
    printf("This token returns:  %s\n", args[i]);
}
