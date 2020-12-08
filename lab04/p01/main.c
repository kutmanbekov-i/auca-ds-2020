#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, *p;
    
    x = 1;
    p = &x;
    printf("The value of x: %d\n", x);
    printf("The address of x: %d\n", p);

    printf("The value of x, using pointer: %d\n", *p);
    *p = 2;
    printf("New value of x, using pointer: %d\n", *p);

    y = (*p) * (*p);
    printf("The value of y: %d\n", y);
}
