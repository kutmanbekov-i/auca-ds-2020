#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, ind = 0, min = INT_MAX;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        
        if (x < min) { 
            min = x;
            ind = i;
        }
    }
    cout << ind;
}