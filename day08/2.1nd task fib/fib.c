#include <stdio.h>

int fib(int n);
int incorrect(char prompt[]);

int main(void)
{
    int x = incorrect("How many Fib numbers do you want?\n");

    for(int i=0;i<x+1; i++)
    {
        printf("%i ," ,fib(i));
    }
    printf("\n");
    
}

int fib(int n)
{
    if (n==0)
    return 0;
    if(n==1)
    return 1;

    return fib(n-1)+fib(n-2);
    
    
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