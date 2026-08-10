#include <stdio.h>
#include <string.h>


int main(void)
{
    char msg[100];
    printf("Write word:");
    fgets(msg,sizeof(msg),stdin);

    if(msg[strlen(msg)-1] == '\n')
    msg[strlen(msg)-1] = '\0';

    for (int  i = strlen(msg)-1; i >= 0;i--)
    {
        printf("%c",msg[i]);
    }
    printf("\n");

}