#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l, r;

    cin >> l >> r;

    if (l == 0 and r == 0) {
        cout << "Not a moose\n";
    } else if (l == r) {
        cout << "Even " << l + r << "\n";
    } else {
        cout << "Odd " << max(l, r) * 2 << "\n";
    }
}