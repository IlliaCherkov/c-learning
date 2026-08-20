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

   char word1[20];
   char word2[20];
   int year;
   int counter = 1;

   FILE *f2 = fopen("books.txt","r");

   while(fscanf(f2,"%s %s (%d)",word1,word2,&year) == 3)
   {

    printf("book %d : %s by %s (%d)\n",counter,word1,word2,year);
    counter++;

    }
   fclose(f2);

   return 0; 
}
