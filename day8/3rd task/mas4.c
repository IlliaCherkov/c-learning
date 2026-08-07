#include <stdio.h>

int main(void)
{


    int table[5][5];


    

    for (int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            table[i][j]= (i+1)*(j+1);
            
        }
    }

    for(int i=0;i<5;i++)
    {
        for(int j = 0; j<5; j++)
        {
        printf("%i\t",table[i][j]);
        }
        printf("\n");
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