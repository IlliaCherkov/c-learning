#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
  while (1)
  {

    char cwd[256];
    getcwd(cwd, sizeof(cwd));
    printf("%s>", cwd);

    char line[256];
    if (fgets(line, sizeof(line), stdin) == NULL)
    {
      printf("\n");
      break;
    }

    if (line[strlen(line) - 1] == '\n')
      line[strlen(line) - 1] = '\0';

    char *args[64];
    char *token = strtok(line, " ");
    int i = 0;

    while (token != NULL)
    {

      args[i] = token;
      i++;
      token = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (i > 0 && strcmp(args[0], "exit") == 0)
      break;

    if (args[0] == NULL)
      continue;

    if (i > 0 && strcmp(args[0], "cd") == 0)
    {
      if (args[1] == NULL)
      {
        char *home = getenv("HOME");
        if (home != NULL)
        {
          chdir(home);
        }
      }
      else if (args[1] != NULL)
      {
        int result = chdir(args[1]);
        if (result == -1)
        {
          perror("cd");
        }
        continue;
      }
    }
    else
    {
      if (i > 0)
      {
        int PID = fork();

        if (PID == 0)
        {
          execvp(args[0], args);
          perror("execvp");
          exit(1);
        }
        else
        {
          waitpid(PID, NULL, 0);
        }
      }
    }
  }
}
