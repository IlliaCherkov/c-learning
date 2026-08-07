#include <stdio.h>

int main(void)
{
    int x;
    
    printf("What the number?");
    int result = scanf("%i",&x);
    
    while(x>10 || result !=1)
    {
        printf("Please enter valid number less than 10, Thanks.\n");
        while(getchar() !='\n');
        printf("What the number?");
        result = scanf("%i",&x);
    }
    for (int i =1;i<=x;i++)
    {
        printf(" %i",i);
    }
    printf("\n");
    
    for (int i=x; i>=1 ;i--)
    {
        printf(" %i",i);

    }

    printf("\n");
}


    
    
    
    
