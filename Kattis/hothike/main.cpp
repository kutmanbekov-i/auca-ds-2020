#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, ind = 0, max_t = 41, hike_t = 0;
    cin >> n;
    
    int a[n];
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
        
    for (int i = 0; i < n - 2; i++)
    {
        int temp = max(a[i], a[i + 2]);
        if (temp < max_t) {
            max_t = temp;
            ind = i;
        }
    }
    cout << ind + 1 << " " <<  max_t; 
    
}