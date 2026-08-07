#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int incorrect(char prompt[]);

int main(void)
{
    srand(time(NULL));
    int guess=0;
    int secret=rand() % 100 + 1;
    int ettempts=0;

    //secret = incorrect("What the secret Number?");
    
    printf("Okeeey, Game is started already. Your task to find the number inside.\nPlease enter the Number:");
    guess = incorrect(" ");
    

    while (1)
    {
        if (guess < secret)
        {
            ettempts++;
            guess = incorrect("Too small! Try again:\n");
            
        }
        else if (guess>secret)
        {
            ettempts++;
            guess = incorrect("Too big! Try again:\n");
            
        }
        else
        {
            ettempts++;
            printf("CONGRATULATIONS!!! You are winner!!!\n");
            printf("\n");
            printf("ettempts counter: %i\n",ettempts);
            break;
        }
        
    }
    

}


int incorrect(char prompt[])

{
    int value;
    int result;

    printf("%s", prompt);
    result = scanf("%i", &value);

    while (result != 1)
    {
        printf("Please enter a valid number.\n");
        while (getchar() != '\n');
        printf("%s", prompt);
        result = scanf("%i", &value);
    }

    return value;
}

