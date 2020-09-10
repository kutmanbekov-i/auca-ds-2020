#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long side = 2, points;

    for(int i = 1; i <= n; i++)
    {
        side += side - 1;
    }

    points = side * side;

    cout << points << "\n";
}