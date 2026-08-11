#include <stdio.h>

int main(void)
{
    int x = 0;
    int y = 0;
    printf("What the 1st number?");
    scanf("%i",&x);
    printf("What the 2st number?");
    scanf("%i",&y);

    while (x>y)
    {
        printf("Error: First number must be smaller.\n");
        printf("What the 1st number?");
        scanf("%i",&x);
        printf("What the 2st number?");
        scanf("%i",&y);

    }
    
        for (int i = x; i <= y; i++)
    {
        if(i % 3==0 && i % 5==0)
        {
            printf("fizzbuzz\n");

        }
        else if(i % 3==0)
        {
            printf("fizz\n");
        } 
        else if(i % 5==0)
        {
            printf("buzz\n");
        }
        else
        {
            printf("%i\n",i);
        }
    }  
}