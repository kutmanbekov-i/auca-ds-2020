#include <bits/stdc++.h>

using namespace std;

struct Freq
{
    char letter;
    int count;
};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, r, c, m, n, test = 1;
    
    cin >> x;
    while(x--)
    {
        cin >> r >> c >> m >> n;
        
        vector<string> data(r);
        // vector<int> freq(26);
        vector<Freq> freq(26);
        int file_size;
        
        int maxim = -1;     // the most frequent pixel
        for (int i = 0; i < r; ++i)
        {
            cin >> data[i];
            
            for (int j = 0; j < c; ++j)
            {
                freq[ data[i][j] - 'A' ].letter = data[i][j];
                freq[ data[i][j] - 'A' ].count++;
                
                if (freq[data[i][j] - 'A'].count >= maxim)
                {
                    maxim = freq[data[i][j] - 'A'].count;
                }
            }
        }
        sort(freq.begin(), freq.end(), [](const Freq &f1, const Freq &f2)
        {
            return f1.count > f2.count;
        });
        
        int max_cnt = 26;    // how many pixels with the same max value of frequency
        
        for (int i = 0; i < 25; ++i)
        {
            if (freq[i].count > freq[i + 1].count)
            {
                max_cnt = i + 1;
                break;
            }
        }
        
        file_size = (max_cnt * maxim) * m + (r * c - (maxim * max_cnt)) * n;

        cout << "Case " << test++ << ": " << file_size << '\n';
    }
    
}