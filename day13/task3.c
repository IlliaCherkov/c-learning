#include <stdio.h>

int main(void)
{
    FILE *f = fopen("books.txt","r");

    if (f == NULL)
    {
        printf("Cannot open file\n");
        return 1;
    }
    
    char word1[20];
    char word2[20];

    //fprintf(f, "Hello world\n");
    
    
    while(fscanf(f, "%s %s\n",word1,word2)== 2)
    {
        printf("word 1 : %s\n",word1);
        printf("word 2 : %s\n",word2);
    }

    fclose(f);

    return 0;
}