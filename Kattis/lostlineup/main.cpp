#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d;
    cin >> n;

    vector<int> v(n);
    v[0] = 1;

    for(int i = 2; i <= n; i++) {
        cin >> d;
        v[d + 1] = i;
    }

    for(auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}