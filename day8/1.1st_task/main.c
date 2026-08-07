#include <stdio.h>
int power(int a, int b);
int incorrect(char prompt[]);

int main(void)
{

    int base = incorrect("What`s the base?\n"); 
    int exp = incorrect("what `s the exp?\n");

    int x = power(base , exp);
    printf("%i in %i equal %i\n",base,exp,x);
}

int power(int a, int b)
{
    int result = 1;

    for (int i = 0 ; i< b ;i++)
    {
        result = result* a;
    }
    return result;
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