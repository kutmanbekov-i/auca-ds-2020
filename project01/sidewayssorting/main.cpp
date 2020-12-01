#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int r, c;
    bool line = false;
    
    while(cin >> r >> c)
    {
        if (r == 0 and c == 0) break;
        
        if (line) cout << '\n';
        line = true;
        
        vector<string> data(c, "");
        string temp;
        
        for (int i = 0; i < r; ++i)
        {
            cin >> temp;
            for (int j = 0; j < c; ++j)
            {
                data[j] += temp[j];
            }
        }
        stable_sort(data.begin(), data.end(), [](string a, string b)
        {
            size_t sz = a.size();
    
            if (sz != b.size())
                return sz < b.size();
            
            string x, y;
            
            for (size_t i = 0; i < sz; ++i)
            {
                x += tolower(a[i]);
                y += tolower(b[i]);
            }
            return x < y;
        });
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                cout << data[j][i];
            }
            cout << '\n';
        }
    }
}