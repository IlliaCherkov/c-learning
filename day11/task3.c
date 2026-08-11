#include <stdio.h>

void swap(int *a,int *b);

int main(void)
{ 
    int x = 5;
    int y = 10;
    int *p = &x;
    int *z = &y;

    swap(p,z);

    printf("X = %d\n",x);
    printf("Y = %d\n",y);
    
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}