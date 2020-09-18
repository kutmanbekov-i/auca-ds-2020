#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string a, b;
    
    cin >> a >> b;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    int m = max( stoi(a), stoi(b) );
    
    cout << m << "\n";
    
}