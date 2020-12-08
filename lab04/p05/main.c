#include <stdio.h>
#include <stdlib.h>

void reverseArray(int *p, int n)
{
    for (int *q = p + n - 1; p < q; ++p, --q)
    {
        int t = *p;
        *p = *q;
        *q = t;
    }
}
void printArray(int* p, int n)
{
    for (int *q = p + n; p < q; ++p)
        printf("%d ", *p);
    printf("\n");
}

int main()
{
    int x;
    size_t sz = 0;

    // dynamic array
    int *a = (int *)malloc(sizeof(int) * sz);
    while (scanf("%d", &x) == 1)
    {
        a = realloc(a, ++sz * sizeof(int));
        a[sz - 1] = x;
    }

    printArray(a, sz);
    reverseArray(a, sz);
    printArray(a, sz);
}