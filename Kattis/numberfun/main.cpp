#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if ( a + b == c or abs(a - b) == c or (a * b == c) or ((double)a / b == c) or ((double)b / a) == c)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}