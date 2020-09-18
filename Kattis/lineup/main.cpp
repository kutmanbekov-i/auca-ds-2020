#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    string a[n], tmp[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        tmp[i] = a[i];
    }
    int order = 0;
    sort(tmp, tmp + n);
    
    if (equal( a, a + n, tmp )) {
        order = 1;
    } else {
        sort(tmp, tmp + n, greater<string>());
        if (equal(a, a + n, tmp)) {
            order = -1;
        } else {
            order = 0;
        }
    }
    
    if (order == -1) cout << "DECREASING\n";
    else if (order == 1) cout << "INCREASING\n";
    else cout << "NEITHER\n";
}