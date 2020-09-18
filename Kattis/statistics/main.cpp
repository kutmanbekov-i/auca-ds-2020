#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, x, cases = 1;
    
    while(cin >> n)
    {
        int mi = 1000001, ma = -1000001, range = 0;
        while(n--)
        {
            cin >> x;
            
            mi = min(mi, x);
            ma = max(ma, x);
            range = ma - mi;
        }
        printf("Case %d: %d %d %d\n", cases++, mi, ma, range);
    }
}