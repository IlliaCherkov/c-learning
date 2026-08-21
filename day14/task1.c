#include <stdio.h>
#include <string.h>

typedef struct { 
    char title[100];
    char author[50];
    int year;
} book;


int main(void)
{
   

   book books[3];

   strcpy(books[0].title, "kozak");
   strcpy(books[0].author,"Shevchenko");
   books[0].year = 1985;

   strcpy(books[1].title, "Slivka");
   strcpy(books[1].author, "Roshen");
   books[1].year = 2001;

   strcpy(books[2].title, "LENIVKA");
   strcpy(books[2].author, "RoshenYCH");
   books[2].year = 2005;

   FILE *f = fopen("books.txt","w");

   for(int i = 0; i <= 2; i++)
   {
   fprintf(f,"%s %s (%d)\n", books[i].title,books[i].author, books[i].year);
   }
   fclose(f);

   book loaded[3];
   int counter = 1;

   FILE *f2 = fopen("books.txt","r");

   int i = 0;
   while(i < 3 && fscanf(f2,"%s %s (%d)",loaded[i].title,loaded[i].author,&loaded[i].year) == 3)
   {
    
    printf("book %d : %s by %s (%d)\n",counter,loaded[i].title,loaded[i].author,loaded[i].year);
    counter++;
    i++;

    }
   fclose(f2);

   return 0; 
}
