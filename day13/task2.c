#include <stdio.h>
#include <string.h>

typedef struct
{
  char author[100];
  char title[50];
  int year;
} book;

void set_year(book *b, int new_year)
{
  b->year = new_year;
}

int main(void)
{
  book library[2];

  strcpy(library[0].author, "Shevchenko");
  strcpy(library[0].title, "Synusynu");
  library[0].year = 1840;

  strcpy(library[1].author, "Shevchenko");
  strcpy(library[1].title, "Synusynu");
  library[1].year = 1840;

 // book *ptr = &library[0];
  for (int i = 0; i < 2; i++)
  {
    set_year(library + i, 2026);
  }

  for (size_t z = 0; z < 2; z++)
  {
    printf("%d\n", library[z].year);
  }

  return 0;
}
