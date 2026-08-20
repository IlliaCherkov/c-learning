#include <stdio.h>
#include <stdlib.h>

int incorrect(char prompt[]);

int main(void)
{
  int number = incorrect("How many numbers?:");
  
  int *arr = malloc(number * sizeof(int));

  for (int i = 0; i <number; i++)
  {
    arr[i] = i*i;
    printf("%d\n",arr[i]);
  }
  free(arr);
  arr = NULL;




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