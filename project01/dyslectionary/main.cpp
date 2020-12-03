#include <bits/stdc++.h>

using namespace std;

int main() {
    
    vector<string> group;
    
    int mx = 0, len;
    bool line = false;
    for (string s; getline(cin, s); )
    {
        if (s == "")
        {
            sort(group.begin(), group.end());
            
            for (string word : group)
            {
                reverse(word.begin(), word.end());
                cout << setw(mx) << word << '\n';
            }
            cout << '\n';
            
            group.clear();
            mx = 0;
            
            continue;
        }
        len = s.length();
        mx = max(mx, len);
            
        reverse(s.begin(), s.end());
        group.emplace_back(s);
    }
    
    sort(group.begin(), group.end());
            
    for (string word : group)
    {
        reverse(word.begin(), word.end());
        cout << setw(mx) << word << '\n';
    }
}