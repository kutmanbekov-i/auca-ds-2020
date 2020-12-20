#include <stdio.h>
#include <stdlib.h>
#include "VecInt.h"

void reverseArray(int *p, int n)
{
    for (int *q = p + n - 1; p < q; ++p, --q)
    {
        int t = *p;
        *p = *q;
        *q = t;
    }
}
void printArray(int *p, int n)
{
    for (int *q = p + n; p < q; ++p)
        printf("%d ", *p);
    printf("\n");
}

void problem04()
{
    struct VecInt v;

    int x, n;

    scanf("%d", &n);

    VecInt_createOfSize(&v, n, 0);
    for (int i = 0; i < v.sz; ++i)
    {
        scanf("%d", &v.p[i]);
    }

    printArray(v.p, v.sz);
    reverseArray(v.p, v.sz);
    printArray(v.p, v.sz);

    // free(v.p);
    VecInt_destroy(&v);
}

void problem05()
{
    struct VecInt v;

    VecInt_createEmpty(&v);

    int x;
    while (scanf("%d", &x) == 1)
    {
        VecInt_pushBack(&v, x);
    }

    printArray(v.p, v.sz);
    reverseArray(v.p, v.sz);
    printArray(v.p, v.sz);

    // free(v.p);
    VecInt_destroy(&v);
}

int main(void)
{
    problem04();
}