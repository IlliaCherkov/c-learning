#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct
{
  char **commands;
  int count;
  int capacity;
} history;

void history_init(history *h)
{
  h->capacity = 4;
  h->count = 0;
  h->commands = malloc(h->capacity * sizeof(char *));
}

void history_add(history *h, char *cmd)
{
  if (h->count == h->capacity)
  {
    h->capacity *= 2;
    h->commands = realloc(h->commands, h->capacity * sizeof(char *));
  }
  h->commands[h->count] = malloc(strlen(cmd) + 1);
  strcpy(h->commands[h->count], cmd);
  h->count++;
}

void history_free(history *k)
{
  for (int j = 0; j < k->count; j++)
  {
    free(k->commands[j]);
    k->commands[j] = NULL;
  }

  free(k->commands);
  k->commands = NULL;
}

typedef struct
{
  int capacity;
  int count;
  char **args;
} arguments;

void arguments_init(arguments *m)
{
  m->count = 0;
  m->capacity = 2;
  m->args = malloc(m->capacity * sizeof(char *));
}

void arguments_add(arguments *c, char *token)
{
  if ((c->capacity - c->count) <= 1)
  {
    c->capacity *= 2;
    c->args = realloc(c->args, c->capacity * sizeof(char *));
  }
  c->args[c->count] = token;
  c->count++;
}

void arguments_free(arguments *n)
{

  free(n->args);
  n->args = NULL;
}

int main(void)
{
  history hist;
  history_init(&hist);
  arguments cmd;
  arguments_init(&cmd);

  while (1)
  {
    cmd.count = 0;

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

    history_add(&hist, line);

    char *token = strtok(line, " ");

    while (token != NULL)
    {
      arguments_add(&cmd, token);
      token = strtok(NULL, " ");
    }
    cmd.args[cmd.count] = NULL;

    if (cmd.count > 0 && strcmp(*cmd.args, "exit") == 0)
    {
      FILE *f = fopen("log.txt", "w");

      for (int z = 0; z < hist.count; z++)
      {
        printf("%s\n", hist.commands[z]);
        fprintf(f, "%s\n", hist.commands[z]);
      }

      fclose(f);

      history_free(&hist);
      arguments_free(&cmd);
      break;
    }

    if (cmd.count > 0 && strcmp(*cmd.args, "cd") == 0)
    {
      if (cmd.args[1] == NULL)
      {
        char *home = getenv("HOME");
        if (home != NULL)
        {
          chdir(home);
        }
      }
      else if (cmd.args[1] != NULL)
      {
        int result = chdir(cmd.args[1]);
        if (result == -1)
        {
          perror("cd");
        }
        continue;
      }
    }
    else
    {
      if (cmd.count > 0)
      {
        int pid = fork();

        if (pid == 0)
        {
          execvp(cmd.args[0], cmd.args);
          perror("execvp");
          exit(1);
        }
        else
        {
          waitpid(pid, NULL, 0);
        }
      }
    }
  }
}