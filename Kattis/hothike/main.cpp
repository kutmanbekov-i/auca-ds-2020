#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, ind = 0, max_t = 0, hike_t = 0;
    cin >> n;
    
    int a[n];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i < n - 2 and a[i] >= max_t)
        {
            max_t = a[i];
            ind = i;
        }
    }
    if (ind == 0)
        hike_t = max(a[ind], a[ind + 2] );
    else if (ind == n - 1)
        hike_t = max(a[ind], a[ind - 2]);
    else
        hike_t = max(a[ind - 1], a[ind + 1]);
    cout << (ind == 0 ? 1 : ind) << " " <<  hike_t; 
    
}