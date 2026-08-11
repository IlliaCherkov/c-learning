#include <stdio.h>

int main(void)
{
    int x;
    int result;
    
    printf("Write the number from 1 till 10?\n\n");
    result = scanf("%i",&x);

    while(x>10 || result != 1)
    {
        printf("Please write valid number from 1 till 10.\n");
        while(getchar() != '\n');
        printf("write the number:");
        result = scanf("%i",&x);
    }

    printf("\n\n");

    for(int i = 1;i<=10;i++)
    {
        int n= x*i;
        printf("%i",x);
        printf(" X"); 
        printf(" %i",i);
        printf(" =");
        printf(" %i\n",n);
        printf("\n");
    }
}

