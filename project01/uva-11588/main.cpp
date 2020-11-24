#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, r, c, m, n, test = 1;
    
    cin >> x;
    while(x--)
    {
        cin >> r >> c >> m >> n;
        
        vector<string> data(r);
        vector<int> freq(26);
        int file_size;
        
        int maxim = -1;     // the most frequent pixel
        for (int i = 0; i < r; ++i)
        {
            cin >> data[i];
            for (int j = 0; j < c; ++j)
            {
                freq[data[i][j] - 'A']++;
                if (freq[data[i][j] - 'A'] >= maxim)
                {
                    maxim = freq[data[i][j] - 'A'];
                }
            }
        }
        sort(freq.begin(), freq.end(), greater<int>());
        
        int max_cnt = 26;    // how many pixels with the same max value of frequency
        
        for (int i = 0; i < 25; ++i)
        {
            if (freq[i] > freq[i + 1])
            {
                max_cnt = i + 1;
                break;
            }
        }
        file_size = (max_cnt * maxim) * m + (r * c - maxim) * n;

        cout << "Case " << test << ": " << file_size << '\n';
        
    }
    
}