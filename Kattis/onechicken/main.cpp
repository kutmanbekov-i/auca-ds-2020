#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    if (n < m) {
        cout << "Dr. Chaz will have " << m - n << " piece" << (m - n > 1 ? "s" : "") << " of chicken left over!\n";
    } else {
        cout << "Dr. Chaz needs " << n - m << " more piece" << (n - m > 1 ? "s" : "") << " of chicken!";
    }
}