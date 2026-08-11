#include <stdio.h>
#include <string.h>


int main(void)
{
    char firstword[100];
    char secondword[100];

    printf("Write first word:");
    fgets(firstword,sizeof(firstword),stdin);
    printf("Write second word:");
    fgets(secondword,sizeof(secondword),stdin);
    size_t flen = strlen(firstword);
    size_t slen = strlen(secondword);

    if(flen > 0 && firstword[flen-1] == '\n')
    firstword[flen-1] = '\0';
    if(slen > 0 && secondword[slen-1] == '\n')
    secondword[slen-1] = '\0';

    int result = strcmp(firstword,secondword);
    printf("%d\n",result);

    if(result > 0)
    {
        printf("First word is bigger\n");
    }
    else if(result < 0){
        printf("First word is smoller\n");
    }
    else
    {
        printf("words are the same\n");
    } 
}