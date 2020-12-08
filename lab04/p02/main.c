#include <stdio.h>
#include <stdlib.h>

#define N 10

void printArray(int* p, int n)
{
    for (int *q = p + n; p < q; ++p)
        printf("%d ", *p);
}

int main()
{
    int a[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &a[i]);
    
    for (int i = 0; i < N; ++i)
        printf("%d ", a[i]);
    printf("\n");

    int sum = 0;
    for (int i = 0; i < N; ++i)
        sum += a[i];
    printf("Sum of the array, using the subscript operator: %d\n", sum);

    sum = 0;
    for (int *p = a; p < a + N; ++p)
        sum += *p;
    printf("Sum of the array, using pointer arithmetics: %d\n", sum);
    printArray(a, N);

    free(a);
}