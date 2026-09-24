#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

char *my_strtok(char *str, const char *delim, const char *quotes);

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
  if (h->commands == NULL)
  {
    fprintf(stderr, "malloc failed in history_init\n");
    exit(1);
  }
}

void history_add(history *h, char *cmd)
{
  if (h->count == h->capacity)
  {
    h->capacity *= 2;
    char **tmp = realloc(h->commands, h->capacity * sizeof(char *));
    if (tmp == NULL)
    {
      fprintf(stderr, "realloc failed in history_add\n");
      return;
    }
    h->commands = tmp;
  }
  h->commands[h->count] = malloc(strlen(cmd) + 1);
  if (h->commands[h->count] == NULL)
  {
    fprintf(stderr, "malloc failed in history_add\n");
    return;
  }
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
void history_load(history *h)
{
  char history_path[512];
  snprintf(history_path, sizeof(history_path), "%s/.myshell_history",
           getenv("HOME"));

  FILE *f = fopen(history_path, "r");
  if (f == NULL)
  {
    printf("We donot have file\n");
  }
  else
  {
    char buf[256];
    printf("We have file\n");
    while (fgets(buf, sizeof(buf), f) != NULL)
    {
      if (buf[strlen(buf) - 1] == '\n')
        buf[strlen(buf) - 1] = '\0';

      history_add(h, buf);
    }
    fclose(f);
  }
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
  if (m->args == NULL)
  {
    fprintf(stderr, "malloc failed in arguments_init\n");
    exit(1);
  }
}

void arguments_add(arguments *c, char *token)
{
  if ((c->capacity - c->count) <= 1)
  {
    c->capacity *= 2;
    char **tmp = realloc(c->args, c->capacity * sizeof(char *));
    if (tmp == NULL)
    {
      fprintf(stderr, "realloc failed in arguments_add\n");
      return;
    }
    c->args = tmp;
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
  history_load(&hist);

  arguments cmd;
  arguments_init(&cmd);

  signal(SIGTTOU, SIG_IGN);

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
    if (strcmp(line, "\n") == 0)
      continue;

    if (line[strlen(line) - 1] == '\n')
      line[strlen(line) - 1] = '\0';

    history_add(&hist, line);

    char *token = my_strtok(line, " ", "\"\'");

    while (token != NULL)
    {
      arguments_add(&cmd, token);
      token = my_strtok(NULL, " ", "\"\'");
    }
    cmd.args[cmd.count] = NULL;

    if (cmd.count > 0 && strcmp(*cmd.args, "exit") == 0)
    {

      break;
    }
    if (cmd.count > 0 && strcmp(*cmd.args, "history") == 0)
    {
      for (int j = 0; j < hist.count; j++)
      {
        printf("%s\n", hist.commands[j]);
      }
      continue;
    }
    if (cmd.count > 0 && strcmp(*cmd.args, "history_clear") == 0)
    {
      history_free(&hist);
      history_init(&hist);
      continue;
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
          setpgid(pid, pid);
          execvp(cmd.args[0], cmd.args);
          perror("execvp");
          exit(1);
        }
        else
        {
          setpgid(pid, pid);
          tcsetpgrp(STDIN_FILENO, pid);
          waitpid(pid, NULL, 0);
          tcsetpgrp(STDIN_FILENO, getpgrp());
        }
      }
    }
  }

  char history_path[512];
  snprintf(history_path, sizeof(history_path), "%s/.myshell_history",
           getenv("HOME"));
  FILE *f = fopen(history_path, "w");
  if (f == NULL)
  {
    perror("Writing to the log");
    for (int z = 0; z < hist.count; z++)
    {
      printf("%s\n", hist.commands[z]);
    }
  }
  else
  {
    for (int z = 0; z < hist.count; z++)
    {
      printf("%s\n", hist.commands[z]);
      fprintf(f, "%s\n", hist.commands[z]);
    }
    fclose(f);
  }

  history_free(&hist);
  arguments_free(&cmd);
}

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
  char *token_write = token_end;

  while (*token_end != '\0')
  {

    if (*token_end == '\\')
    {
      token_end++;
      if (*token_end == '\0')
      {
        *token_write = *token_end;
        last_pos = token_end;
        return token_start;
      }
      else
      {
        *token_write = *token_end;
        token_end++;
        token_write++;
        continue;
      }
    }

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
      *token_write = '\0';
      last_pos = token_end + 1;
      return token_start;
    }
    *token_write = *token_end;
    token_write++;
    token_end++;
  }
  *token_write = *token_end;
  last_pos = token_end;
  return token_start;
}
