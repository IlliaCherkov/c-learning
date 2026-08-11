#include <stdio.h>

int incorrect(char prompt[]);

int main(void)
{
    int a[5];
    int b[5];
    int c[5];

    for (int i=0 ; i<=4;i++)
    {
        char prompta[50];
        char promptb[50];
        sprintf(prompta, "number for a[%i]?:",i);
        sprintf(promptb, "number for b[%i]?:",i);

        a[i]= incorrect(prompta);
        b[i]= incorrect(promptb);
    }

    for(int k= 0; k <=4 ; k++)
    {
        
        c[k]= a[k]+b[k];
        printf("Sum for c[%i] = %i\n",k,c[k]);
    }

}

int incorrect(char prompt[])
{
    int value;
    int result;

    printf("%s", prompt);
    result = scanf("%i", &value);
    char next = getchar();

    if(next != '\n')
    {
        result = 0;
        while(next != '\n')
        {
            next = getchar();
        }
    }

    while (result != 1)
    {
        printf("Please enter a valid number.\n");
        printf("%s", prompt);
        result = scanf("%i", &value);
        next = getchar();

        if(next != '\n')
        {
            result = 0;
            while(next != '\n')
            {
                next = getchar();
            }
        }
    }

    return value;
}