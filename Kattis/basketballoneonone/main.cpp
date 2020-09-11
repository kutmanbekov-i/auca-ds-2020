#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int a = 0, b = 0;
    cin >> s;

    for(int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == 'A')
        {
            a += s[i + 1] - '0';
        } else if (s[i] == 'B')
        {
            b += s[i + 1] - '0';
        }
    }
    cout << (a > b ? "A\n" : "B\n");
}