#include <stdio.h>
#include <stdlib.h>

void printArray(int* p, int n)
{
    for (int *q = p + n; p < q; ++p)
        printf("%d ", *p);
    printf("\n");
}

int main()
{
    int N;
    scanf("%d", &N);

    int *a = (int *)malloc(sizeof(int) * N);
    
    for (int i = 0; i < N; ++i)
        scanf("%d", &a[i]);

    printArray(a, N);
}