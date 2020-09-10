#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, n, p;
    int left = 0;
    cin >> x >> n;

    for(int i = 1; i <= n; i++)
    {
        left += x;
        cin >> p;
        left -= p;
    }
    cout << left + x << "\n";
}