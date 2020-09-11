#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, a, b, c, d, n;
    double dif = 0, max_dif = 0, piece = 0, piece2 = 0, curr_max = 0;
    scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);

    for (int k = 1; k <= n - 1; k++)
    {
        piece = p * (sin(a * k + b) + cos(c * k + d) + 2);
        piece2 = p * (sin(a * (k + 1) + b) + cos(c * (k + 1) + d) + 2);
        
        curr_max = max(piece, curr_max);
        
        dif = curr_max - piece2;
        max_dif = max(dif, max_dif);
    }
    printf("%.9f\n", max_dif);
}