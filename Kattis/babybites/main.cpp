#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    bool b = true;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;

        if (s[0] == 'm') continue;

        int tmp = stoi(s);

        if (tmp != i) {
            b = false;
            break;
        }
    }
    cout << (b ? "makes sense\n" : "something is fishy\n");
}