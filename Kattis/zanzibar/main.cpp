#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    
    cin >> n;
    
    while(n--)
    {
        int x, prev_x = -1, lower_bound = 0;
        while(cin >> x)
        {
            if (x == 0) break;
            
            if (prev_x != -1 and prev_x * 2 < x)
            {
                lower_bound += (x - prev_x * 2);
            }
            prev_x = x;
        }
        cout << lower_bound << "\n";
    }
    
}