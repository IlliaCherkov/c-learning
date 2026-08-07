#include <stdio.h>

int main(void)
{
    int x;

    printf("Write the number:");
    scanf("%i",&x);

    if(x % 2 ==0)
    {
        printf("EVEN\n");
    }
    else 
    {
        printf("ODD\n");
    }
}
