#include <bits/stdc++.h>

using namespace std;

void parse(const string &rank, string &parsed)
{
    int len = rank.length();
    
    for (int i = 0; i < len; ++i)
    {
        if (rank[i] == 'u')
        {
            parsed += 'a';
            i += 5;
        }
        if (rank[i] == 'm')
        {
            parsed += 'b';
            i += 6;
        }
        if (rank[i] == 'l')
        {
            parsed += 'c';
            i += 5;
        }
    }
    
    reverse(parsed.begin(), parsed.end());
    len = parsed.length();
    
    for (int i = len - 1; i < 10; ++i)
    {
        parsed += 'b';
    }
}

int main() {
    
    int t; cin >> t;
    
    while (t--)
    {
        
        int n; cin >> n;
        
        vector<pair<string, string>> data;
        
        for (int i = 0; i < n; ++i)
        {
            string name, rank, kolbasa, parsed = "";
            
            cin >> name >> rank >> kolbasa;
            
            parse(rank, parsed);
            
            data.emplace_back(name, parsed);
        }
        
        sort(data.begin(), data.end(), []( pair<string, string> a, pair<string, string> b )
        {
            if (a.second == b.second)
            {
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        
        for (int i = 0; i < n; ++i)
        {
            int len = data[i].first.length();
            cout << data[i].first.substr(0, len - 1) << '\n';
        }
        
        cout << "==============================\n";
    }
}