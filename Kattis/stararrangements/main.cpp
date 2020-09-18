#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int s, x = 2, y = 1;
    cin >> s;
    
    cout << s << ":\n";
    
    while(true)
    {
        int n = s / (x + y);
        
        if ( s % ((x + y) * n) == 0 or s % (((x + y) * n) + x) == 0)
        {
            cout << x << "," << y << "\n";
        }
        
        if (x >= s / 2) break;
        
        if (x > y) y++;
        else x++;

    }
    if (s % 2 == 1) cout << s / 2 + 1 << "," << s / 2 << "\n";
    else            cout << s / 2 + 0 << "," << s / 2 << "\n";
}