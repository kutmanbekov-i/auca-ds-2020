#include <bits/stdc++.h>

using namespace std;

struct SpecialString
{
    string DNA;
    int sortedness;
};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n, m;
    
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        
        vector<SpecialString> data(m);
        
        for (int i = 0; i < m; ++i)
        {
            cin >> data[i].DNA;
            int x = 0;
            
            for (int j = 0; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    if (data[i].DNA[j] > data[i].DNA[k])
                    {
                        ++x;
                    }
                }
            }
            data[i].sortedness = x;
        }
        stable_sort(data.begin(), data.end(), [](const SpecialString &a, const SpecialString &b)
        {
            return a.sortedness < b.sortedness;
        });
        
        for (int i = 0; i < m; ++i)
        {
            cout << data[i].DNA << '\n';
        }
        if (t) cout << '\n';
    }
    
}