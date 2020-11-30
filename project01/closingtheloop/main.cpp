#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n; cin >> n;
    
    for (int i = 1; i <= n; ++i)
    {
        int s; cin >> s;
        
        vector<int> red;
        vector<int> blue;
        
        while (s--)
        {
            string r; cin >> r;
            int len = r.length();
            
            if (r[len - 1] == 'R')
            {
                red.push_back( stoi(r.substr(0, len - 1)) );
            }
            else
            {
                blue.push_back( stoi(r.substr(0, len - 1)) );
            }
        }
        int r_len = red.size();
        int b_len = blue.size();
        
        sort(red.begin(), red.end(), greater<int>());
        sort(blue.begin(), blue.end(), greater<int>());
        
        int x = min(r_len, b_len);
        int sum = 0;
        
        sum = accumulate( red.begin(), red.begin() + x, sum );
        sum = accumulate( blue.begin(), blue.begin() + x, sum );
        
        if (r_len == 0 or b_len == 0)
        {
            cout << "Case #" << i << ": 0\n";
        }
        else
            cout << "Case #" << i << ": " << (sum - x * 2) << '\n';

    }
}