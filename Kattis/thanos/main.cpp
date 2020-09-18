#include <bits/stdc++.h>

typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    
    ull t, p, r, f;
    ld res;
    
    cin >> t;
    
    while(t--)
    {
        cin >> p >> r >> f;
        
        res = (ld)f / (p * r);
        cout << (res < 1 ? f >= p ? 1 : 0 : ceil(res)) << "\n";
    }
}