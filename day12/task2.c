#include <stdio.h>
#include <string.h>

char *my_strcpy(char *dest, char *src);

int main(void)
{
    char src[] = "kayak";
    char dest[100];

    my_strcpy(dest, src);
    printf("%s\n",dest);
}

    char *my_strcpy(char *dest, char *src)
    {
        char *start = dest;

        while(*src != '\0')
        {
            *dest = *src; 
            dest++;
            src++;
        }
        *dest = '\0';

        return start; 

    }
