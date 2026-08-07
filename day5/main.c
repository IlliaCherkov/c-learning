#include <stdio.h>

int incorrect(char prompt[]);

int main(void)
{
    int number[100];
    int count;
    int sum =0;

    count = incorrect("How many numbers? ");
    
    
    for (int i=0;i<count;i++)
    {

        number[i] = incorrect("Number: ");
        sum += number[i];
    }

    float aver =(float)sum /count;

    printf("Sum: %i\n",sum);
    printf("Average: %.2f\n",aver);
   

}

int incorrect(char prompt[])
{
    int value;
    int result;

    printf("%s",prompt);
    result= scanf("%i",&value);

    while(result!=1)
    {
        printf("Please Enter a valid number.\n");
        while(getchar() !='\n');
        printf("%s",prompt);
        result = scanf("%i",&value);
    }
    return value;
}





 

