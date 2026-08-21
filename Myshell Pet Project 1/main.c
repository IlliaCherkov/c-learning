#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
  while (1)
  {

    char cwd[256];
    getcwd(cwd, sizeof(cwd));
    printf("%s>", cwd);

    char line[256];
    fgets(line, sizeof(line), stdin);

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

    if (i > 0 && strcmp(args[0], "exit") == 0)
      break;
    
    for (int j = 0; j < i; j++)
    {
      printf("%s\n", args[j]);
    }

    if(i>0 && strcmp(args[0], "Fork") == 0)
    {
        fflush(stdout);
        int PID = fork();

        if(PID == 0)
        {
            printf("Child PID:%d\n",PID);
            break;
        }
        else
        {
            printf("I am Father PID of my child:%d\n",PID);
            wait(NULL);
        }

    }

    

  }
}