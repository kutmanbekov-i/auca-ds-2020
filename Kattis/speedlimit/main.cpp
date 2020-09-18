#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, s, t;
    while (cin >> n)
    {
        if (n == -1) break;
        
        int dist = 0;
        int prev_t = 0;
        
        while(n--)
        {
            cin >> s >> t;
            
            dist += s * abs(t - prev_t);
            
            prev_t = t;
        }
        
        cout << dist << " miles\n";
    }
}