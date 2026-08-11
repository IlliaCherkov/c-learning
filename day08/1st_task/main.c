#include <stdio.h>
int max(int a, int b);
int incorrect(char prompt[]);

int main(void)
{
    int x = incorrect("1st number:");
    int y = incorrect("2nd number:");
    max(x,y);
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


int max(int a, int b)
{
    if (a>b)
    {
        printf("%i is bigger\n",a);
    }
    else
    {
        printf("%i is Bigger\n",b);
    }

}