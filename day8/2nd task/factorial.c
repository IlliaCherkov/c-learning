#include <stdio.h>

int incorrect (char prompt[]);
int factorial(int n);
int main(void)
{
    int x = incorrect("What the number?:");
    for(int i=1; i<=x;i++)
    {
        printf("%i! = %i\n",i,factorial(i));
    }
}

int factorial(int n)
{
    if(n<=1)
    return 1;
    
    return n * factorial(n-1);
    
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