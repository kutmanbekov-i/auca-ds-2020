#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int x, a, b, c, deg = 0;
    
    while (cin >> x >> a >> b >> c)
    {
        if (x == 0 and a == 0 and b == 0 and c == 0) break;
        
        // 360 / 40 = 9
        
        // dial: 0, 1, 2 ... , 39. (40 values)
        
        deg += 720;
        
        deg += ( (40 - abs(a - x) % 40) * 9 );
        
        deg += 360;
        
        deg += ( (40 - abs(b - a) % 40) * 9 );
        
        deg += ( (40 - abs(c - b) % 40) * 9 );
        
        cout << deg << "\n";
        deg = 0;
    }
}