#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x, y;
    cin >> x >> y;

    if (x == 0 and y == 1)
        cout << "ALL GOOD\n";
    else if (y == 1)
        cout << "IMPOSSIBLE\n";
    else
        printf ("%.9f", (double)(x / (1 - y)) );
}