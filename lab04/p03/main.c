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

    int a[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &a[i]);
    
    int M;
    scanf("%d", &M);

    int b[M];
    for (int i = 0; i < M; ++i)
        scanf("%d", &b[i]);

    printArray(a, N);
    printArray(b, M);
}