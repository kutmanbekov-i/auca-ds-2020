#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cnt = 0;    // number of attributes
    string s, temp; // temp is used in istringstream
    getline(cin, s);
    
    istringstream check(s);
    vector<string> attributes;
    
    while (getline( check, temp, ' ' ))
    {
        attributes.emplace_back(temp);
        ++cnt;
    }
    
    int num_of_songs; cin >> num_of_songs;
    vector<vector<string>> songs(num_of_songs, vector<string>(cnt));

    for (int i = 0; i < num_of_songs; ++i)
    {
        for (int j = 0; j < cnt; ++j)
        {
            cin >> songs[i][j];
        }
    }
    
    int n; cin >> n;
    for (int k = 0; k < n; ++k)
    {
        if (k) cout << '\n';
        
        string str; cin >> str;
        
        auto it = find(attributes.begin(), attributes.end(), str);
        
        if (it != attributes.end())
        {
            int ind = it - attributes.begin();
            
            stable_sort(songs.begin(), songs.end(), [ind](const vector<string> &a, const vector<string> &b)
            {
                return a[ind] < b[ind];
            });
            
            for (int i = 0; i < cnt; ++i)
            {
                if (i) cout << ' ';
                cout << attributes[i];
            }
            cout << '\n';
            for (int i = 0; i < num_of_songs; ++i)
            {
                for (int j = 0; j < cnt; ++j)
                {
                    if (j) cout << ' ';
                    cout << songs[i][j];
                }
                cout << '\n';
            }
        }
    }
}