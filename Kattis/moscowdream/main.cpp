#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    if (a > 0 and b > 0 and c > 0 and a +b +c >= n and n >= 3)
        cout << "YES\n";
    else
        cout << "NO\n";
}