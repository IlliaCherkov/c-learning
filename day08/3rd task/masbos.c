#include <stdio.h>

int incorrect(char prompt[]);

int main(void)
{
    int arr[10];
    
    for (int i = 0; i <= 9; i++)
    {
        arr[i]=incorrect("What the number?");
        
    }

    for(int t = 0; t < 9; t++)
    {
        for (int k = 0; k <=8; k++)
        {
            if(arr[k]>arr[k+1])
            {
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;

            }
        }
    }

    for (int j = 0; j <= 9; j++)
    {
        printf("%i\n",arr[j]);
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