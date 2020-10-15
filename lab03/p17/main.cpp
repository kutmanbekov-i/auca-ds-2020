#include <bits/stdc++.h>

using namespace std;

const char symbols[4] = {' ', '.', 'x' ,'W'};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    bool line = false;
    
    while (t--)
    {
        vector<int> DNA(10);
        
        for (int i = 0; i < 10; ++i)
            cin >> DNA[i];

        vector<vector<int>> sums(50, vector<int>(40, 0));
        vector<int> temp(40, 0);
        
        sums[0][19] = 1;
        temp[19] = 1;
        
        for (int i = 0; i < 50; ++i)
        {
            temp.clear();
            for (int j = 0; j < 40; ++j)
            {
                if (j == 0)
                    temp[j] = sums[i][j] + sums[i][j + 1];
                else if (j == 39)
                    temp[j] = sums[i][j] + sums[i][j - 1];
                else
                    temp[j] = sums[i][j - 1] + sums[i][j] + sums[i][j + 1];
                
                if (i < 49)
                    sums[i + 1][j] = DNA[temp[j]];
            }
            // sums[i] = temp;
        }
        if (line) cout << "\n";
        line = true;
        
        for (int i = 0; i < 50; ++i)
        {
            for (int j = 0; j < 40; ++j)
            {
                cout << symbols[ sums[i][j] ];
            }
            cout << "\n";
        }
    }
    
}
