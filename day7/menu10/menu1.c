#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int incorrect(char prompt[]);
void menu(void);
void even(void);
void multiplication(void);
void fizzbuzz(void);
void sum(void);
void game(void);



int main(void)
{
    int choice=0;
    int operations = 0;
    while(1)
    {
        menu();
        choice =incorrect("Your choice:");
        if (choice>5 || choice<0)
        {
            printf("\n");
            printf("Choose ONE variant from menu below.\n\n");
        }

        if (choice==1)
        {
            operations++;
            even();
            printf("\n");
            
            
        }
        else if(choice==2)
        {
            operations++;
            multiplication();
            printf("\n");

        }
        else if(choice==3)
        {
            operations++;
            fizzbuzz();
            printf("\n");

        }
        else if (choice==4)
        {
            operations++;
            sum();
            printf("\n");
        }
        else if(choice==5)
        {
            operations++;
            game();
            printf("\n");

        }
        else if(choice ==0)
        {
            printf("\n");
            printf("Operations done: %i. Bye!\n",operations);
            break;
        }
    }

}




void even(void)
{
    int x;

    printf("Write the number:");
    x = incorrect("");

    printf("Number %i is ",x);
    if(x % 2 ==0)
    {
        printf("EVEN\n");
    }
    else 
    {
        printf("ODD\n");
    }
}

void multiplication(void)
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
    printf("Multiplication table for number :%i\n\n",x);


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

void fizzbuzz(void)
{
    int x = 0;
    int y = 0;
    x= incorrect("What the 1st number?");
    y = incorrect("What the 2st number?");
    

    while (x>y)
    {
        printf("Error: First number must be smaller.\n");
        x= incorrect("What the 1st number?");
        y= incorrect("What the 2st number?");

    }

    printf("\n\n");
    printf("Fizzbuzz from %i to %i\n",x,y);
    printf("\n");
    
        for (int i = x; i <= y; i++)
    {
        if(i % 3==0 && i % 5==0)
        {
            printf("fizzbuzz\n");

        }
        else if(i % 3==0)
        {
            printf("fizz\n");
        } 
        else if(i % 5==0)
        {
            printf("buzz\n");
        }
        else
        {
            printf("%i\n",i);
        }
    }  
}

void sum(void)

{
    int number[100];
    int count;
    int total =0;

    count = incorrect("How many numbers? ");
    
    
    for (int i=0;i<count;i++)
    {

        number[i] = incorrect("Number: ");
        total += number[i];
    }

   

    printf("Sum: %i\n",total);

   

}

void game(void)
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

void menu(void)
        {
         printf("=== MENU ===\n");
         printf("1 - Check even/odd\n");
         printf("2 - Multiplication table\n");
         printf("3 - FizzBuzz up to N\n");
         printf("4 - Sum from 1 to N\n");
         printf("5 - Game Secret Number from 1 to 100\n");
         printf("0 - Exit\n\n");
         }
