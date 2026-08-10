#include <stdio.h>
#include <string.h>


int main(void)
{
    char word[10];
    printf("Insert word: ");
    fgets(word, sizeof(word),stdin);

    if(word[strlen(word) - 1]=='\n')
        word[strlen(word)- 1] = '\0';


    int count = 0;
    while(word[count] != '\0')
    count++;


printf("my variant: %d\n",count);
printf("strlen(): %zu\n",strlen(word));


}
