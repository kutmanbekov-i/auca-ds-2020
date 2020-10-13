#include <bits/stdc++.h>

using namespace std;

const string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
const string ranks[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    bool line = false;
    
    while(t--)
    {
        if (line) 
            cout << "\n";
            
        line = true;
        int n; cin >> n;
        
        vector<vector<int>> shuffles(n);
        vector<int> deck(52);
        vector<int> applied;
        
        for (int i = 1; i <= 52; ++i)
            deck[i] = i;
        
        int x;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 52; ++j)
            {
                cin >> x;
                shuffles[i].insert(shuffles[i].begin() + j, x);
            }
               
        string s;
        getline(cin, s);
        while(getline(cin, s))
        {
            if (s.length() == 0 ) break;

            int k = stoi(s);
            applied.push_back(k - 1);
        }
        
        vector<int> temp_deck(52);
            
        for (int i = 0; i < applied.size(); ++i)
        {
            int k = applied[i];
            
            for (int j = 0; j < 52; ++j)
                temp_deck[j] = deck[j];
            
            for (int j = 0; j < 52; ++j)
                deck[j] = temp_deck[ shuffles[ k ][j] - 1 ];  

        }
        
        
        int cnt = 0;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 13; ++j)
            {
                int x = deck[cnt];
                string rank = ranks[x % 13];
                string suit = suits[x / 13];
                
                cout << rank << " of " << suit << "\n";
                ++cnt;
            }            
            
        }
    }
}
