#include <stdio.h>

void increment(int *n);

int main(void)
{
  int x = 5;
  int *p = &x;

  increment(p);

  printf("%d\n", x);
}

void increment(int *n)
{
  *n = *n + 1;
}