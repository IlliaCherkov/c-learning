#include <stdio.h>

int incorrect(char prompt[]);

int main(void)
{
    int x = 0;

    printf("what the number?\n");
    incorrect("");
    scanf("%i\n",&x);
    printf("%i",x);
}


int incorrect(char prompt[])
{
    int value;
    int result;

    printf("%s", prompt);
    result = scanf("%i", &value);

    while (result != 1)
    {
        printf("Please enter a valid number.\n");
        while (getchar() != '\n');
        printf("%s", prompt);
        result = scanf("%i", &value);
    }

    return value;
}