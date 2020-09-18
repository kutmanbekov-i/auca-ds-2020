#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main() {
    
    ull t, p, r, f, cnt = 0;
    cin >> t;
    
    while(t--)
    {
        cin >> p >> r >> f;
        cnt = 0;
        
        while(p <= f) {
            p *= r;
            cnt++;
        }
        cout << cnt << "\n";
    }
}