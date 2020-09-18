#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int x = 0;
    int a[3];
    
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    
    sort(a, a + 3);
    
    if (a[2] - a[1] == a[1] - a[0]) {
        x = a[2] + (a[2] - a[1]);
    } else if ( (a[2] - a[1]) * 2 == a[1] - a[0] ) {
        x = a[0] + (a[2] - a[1]);
    } else if( (a[1] - a[0]) * 2 == a[2] - a[1] ) {
        x = a[2] - (a[1] - a[0]);
    }
    cout << x << "\n";
}