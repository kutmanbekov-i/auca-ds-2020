#include <bits/stdc++.h>

using namespace std;

const string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
const string ranks[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

void shuffle(vector<int> &deck, const vector<int> &shuffle);
void printt(vector<int> &deck);

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
        
        vector<vector<int>> shuffles(n, vector<int>(52));
        vector<int> deck(52);
        
        for (int i = 0; i < 52; ++i)
            deck[i] = i;
        
        int x;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 52; ++j)
            {
                cin >> x;
                shuffles[i][j] = x - 1;
            }
               
        string s;
        getline(cin, s);
        while(getline(cin, s))
        {
            if (s.length() == 0 ) break;

            int k = stoi(s);
            shuffle(deck, shuffles[k - 1]);
        }
        printt(deck);
        
    }
}
void shuffle(vector<int> &deck, const vector<int> &shuffle)
{
    vector<int> temp_deck(52);
        
    for (int j = 0; j < 52; ++j)
        temp_deck[j] = deck[ shuffle[j] ];
            
    deck = temp_deck;

}
void printt(vector<int> &deck)
{
    for (int i = 0; i < 52; ++i)
    {
        int x = deck[i];
        cout << ranks[x % 13] << " of " << suits[x / 13] << "\n";
    }
}