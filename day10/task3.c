#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[100];

    printf("Write word:");
    fgets(word,sizeof(word),stdin);

    if(word[strlen(word)-1]== '\n')
    word[strlen(word)-1] = '\0';

    int len = strlen(word);
    int is_palindrome = 1; 

    for(int i = 0; i < len / 2 ;i++)
    {
        if (word[i]!=word[len-1-i])
        {
            is_palindrome = 0;
            break;
        }
    }

    if(is_palindrome)
    {
        printf("Polindrome\n");
    }
    else
    {
        printf("Not a Polindrome\n");
    }
    
    return 0;

}