#include <stdio.h>

int my_strcmp(char *a, char *b)
{
    while (*a == *b && *a != '\0')
    {
        a++;
        b++;
    }
    return *a-*b;
}
int main(void)
{
    char word1[] = "cawqt";
    char word2[] = "car";
    
    printf("%d\n",my_strcmp(word1,word2));
    
    
}

