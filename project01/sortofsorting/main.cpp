#include <bits/stdc++.h>

using namespace std;

int main() {
    
    bool line = false;
    for (int n; cin >> n and n != 0; )
    {
        if (line) cout << '\n';
        line = !line;;
        
        vector<string> names(n);
        
        for (int i = 0; i < n; ++i)
            cin >> names[i];
        
        stable_sort(names.begin(), names.end(), [](string a, string b)
        {
            if (a[0] == b[0])
            {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        for (string word : names)
        {
            cout << word << '\n';
        }
    }
}