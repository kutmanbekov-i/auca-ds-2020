#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    string a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int order = 0;
    for(int i = 0; i < n; i++)
    {
        if (i == 0) {
            if (a[i] > a[i + 1]) order = -1;
            else order = 1;
        }
        if (i < n - 1) {
            if (order == -1) {
                if (a[i] < a[i + 1]) {
                    order = 0; break;
                }
            } else if (order = 1) {
                if (a[i] > a[i + 1]) {
                    order = 0; break;
                }
            }
        }
    }
    if (order == -1) cout << "DECREASING\n";
    else if (order == 1) cout << "INCREASING\n";
    else cout << "NEITHER\n";
}