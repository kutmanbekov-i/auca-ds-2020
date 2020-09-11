#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, a, b, c, d, n;
    double best = 0, dif = 0, piece1 = 0, piece2=0;
    scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);

    /* price(k)=p⋅(sin(a⋅k+b)+cos(c⋅k+d)+2) */
    for (int i = 1; i <= n; i++)
    {
        piece1 = p * (sin(a * i + b) + cos(c * i + d) + 2);
        for (int j = i + 1; j <= n; j++)
        {
            piece2 = p * (sin(a * j + b) + cos(c * j + d) + 2);

            dif = piece1 - piece2;
            if (dif > best)
                best = dif;
        }
    }
    printf("%.9f\n", best);
}