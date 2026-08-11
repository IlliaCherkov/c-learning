#include <stdio.h>

int main(void)
{
    int x; 

    printf("What is your age?");
    scanf("%i",&x);

    if(x<1 || x>120)
    {
        printf("Invalid age\n");
    }
    else if(x<13)
    {
        printf("Child\n");
    }
    else if(x>=13 && x<=19)
    {
        printf("Teenager\n");
    }
    else if(x<=64)
    {
        printf("Adult\n");
    }
    else if (x>=65)
    {
        printf("Senior\n");
    }
    
}