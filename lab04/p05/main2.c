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
    int sz = 0;
    int cp = 0;
    int *a = NULL;
    
    while (scanf("%d", &x) == 1)
    {
        if (sz == cp)
        {
            int newCp = sz == 0 ? 1 : cp * 2;

            int *q = (int *)malloc(sizeof(int) * newCp);
            for (int i = 0; i < sz; ++i)
            {
                q[i] = a[i];
            }
            free(a);
            a = q;
            cp = newCp;
        }
        a[sz++] = x;
    }

    printArray(a, a + sz);
    reverseArray(a, sz);
    printArray(a, sz);

    free(a);
}