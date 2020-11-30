#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n; cin >> n;
    vector<pair<int, string>> v(n);
    
    int r;
    string temp, color = "hii!";
    
    for (int i = 0; i < n; ++i)
    {
        cin >> temp >> color;
        
        if ( find_if(temp.begin(), temp.end(), [](char c) { return !isdigit(c); }) == temp.end() )
        {
            r = stoi( temp ) >> 1;
            v[i] = {r, color};
        }
        else
        {
            r = stoi( color );
            v[i] = {r, temp};
        }
    }
    sort(v.begin(), v.end());
    
    for (int i = 0; i < n; ++i)
        cout << v[i].second << '\n';
}