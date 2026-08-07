#include <stdio.h>

int incorrect(char prompt[]);
int is_prime(int n);

int main(void)
{
    int x = is_prime(incorrect("Number?\n"));
    
    if(x==1)
    {
        printf("This number is Prime\n");
    }
    else 
    {
        printf("This number is Not Prime\n");
    }

}


int is_prime(int n)
{
    if(n<=1)
    {
        return 0;
    }



    int result =0;

    for (int i = 2; i < n-1; i++)
    {
        result = n%i;
        if(result ==0)
        {
            return 0;
        }

    }
    return 1;
    
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



