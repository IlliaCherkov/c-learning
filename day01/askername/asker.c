
#include <stdio.h>

int main(void)
{
    char name[50];                          // buffer for 50 characters
    printf("What is your name? ");          // ask user
    scanf("%49s",name);                    // read one word from keyboard
    printf("Hello, %s!\n", name);           // %s = insert string here
    return 0;
}

