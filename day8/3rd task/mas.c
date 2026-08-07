#include <stdio.h>

int incorrect(char prompt[]);

int main(void)
{
    int read[10];
   

    for (int i=0; i<=9; i++)
    {
        read[i] = incorrect("Number?");
    }
    int max = read[0];
    int min = read[0];
    int sum = 0;
    for (int k=9; k>=0;k--)
    {
        printf("%i ,",read[k]);
        if (read[k]> max)
        max = read[k];
        if (read[k]<min)
        min = read[k];
        sum =sum + read[k];
    }
   
    printf("\n");
    printf("The maximum is %i \n",max);
    printf("The minimum is %i \n",min);
    printf("The Sum is %i \n",sum);

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