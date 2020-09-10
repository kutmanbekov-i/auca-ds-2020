#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    if (a == 0 or b == 0 or c == 0) {
        cout << "NO\n";
    } else if (n >= 3 and a + b + c >= n)
    {
        cout << "YES\n";
    }
}