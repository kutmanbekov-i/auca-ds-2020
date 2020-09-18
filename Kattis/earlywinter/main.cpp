#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d, k, cnt = 0;
    bool b = false;
    
    cin >> n >> d;
    
    while (n--)
    {
        cin >> k;
        
        if (k <= d) { b = true; break; }
        else cnt++;
        
    }
    
    if (b) {
        cout << "It hadn't snowed this early in " << cnt << " years!\n";
    } else {
        cout << "It had never snowed this early!\n";
    }
}