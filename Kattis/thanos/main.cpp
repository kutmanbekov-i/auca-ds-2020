#include <bits/stdc++.h>

typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    
    ull t, p, r, f;
    cin >> t;
    
    while(t--)
    {
        cin >> p >> r >> f;
        
        cout << ceil((ld)f / (p * r)) << "\n";
    }
}