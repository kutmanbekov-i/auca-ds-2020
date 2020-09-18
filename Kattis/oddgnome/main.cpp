#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, g, x, temp, king = 0;
    
    cin >> n;
    
    while(n--)
    {
        temp = -1;
        cin >> g;
        
        for(int i = 1; i <= g; i++)
        {
            cin >> x;
            
            if (temp != -1 and temp + 1 != x) {
                king = i - 1;
            }
            temp = x;
        }
        cout << king << "\n";
    }
}