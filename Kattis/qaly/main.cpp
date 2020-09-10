#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double q, y, qaly = 0;
    scanf("%d", &n);
    while(n--)
    {
        cin >> q >> y;
        qaly += (q * y);
    }

    printf("%.3f\n", qaly);
}