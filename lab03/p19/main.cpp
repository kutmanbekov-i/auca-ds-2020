#include <bits/stdc++.h>

using namespace std;

vector<int> parse(string line)
{
    vector<int> temp;
    for (int i = 0; i < line.length(); ++i)
    {
        if (isdigit(line[i]))
        {
            temp.push_back(line[i] - '0');
        } else continue;
    }
    return temp;
}

int main()
{
    int t; cin >> t;
    bool new_line = false;

    while (t--) {

        int n; cin >> n;
        string s;
        vector<string> candidates(n + 1);
        vector<vector<int>> votes;

        if (!new_line)
        {
            getline(cin, s);
        }

        for(int i = 1; i <= n; ++i)
        {
            getline(cin, s);
            candidates[i] = s;
        }

        string line;

        while (getline(cin, line))
        {
            // pass
            if (line.length() == 0) break;

            votes.push_back( parse(line) );
        }

        vector <int> indexes(votes.size(), 0);
        vector <bool> kicked(21, false);
        
        while (true)
        {
            vector <int> points(21, 0);
            
            int x = 0;
            
            for (int i = 0; i < votes.size(); ++i)
            {
                while (indexes[i] < n and kicked[ votes[i][ indexes[i] ] ])
                {
                    indexes[i]++;
                }
                if (indexes[i] < n)
                {
                    points[ votes[i][indexes[i]] ]++;
                    ++x;
                }
                
            }
            
            int half = x / 2 + x % 2;
            int maxim = -1, minim = INT_MAX;
            
            for (int i = 1; i <= n; ++i)
            {
                if (!kicked[i])
                {
                    maxim = max(maxim, points[i]);
                    if (points[i] < minim)
                        minim = points[i];
                }
            }
            
            if (maxim == minim or maxim >= half)
            {
                for (int i = 1; i <= n; ++i)
                    if (points[i] == maxim)
                        cout << candidates[i] << '\n';
                break;
            }
            for (int i = 1; i <= n; ++i)
                if (points[i] == minim)
                    kicked[i] = true;
        }
        
        if (t)
            cout << "\n";
    }
}