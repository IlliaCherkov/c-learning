#include <stdio.h>

int main(void)
{
    int x = 10;
    int *p = &x;
    printf("%d\n",x);
    printf("%d\n",*p);
    printf("address X : %p\n",(void*)&x);
    printf("means of P :%p\n",(void*)p);
}