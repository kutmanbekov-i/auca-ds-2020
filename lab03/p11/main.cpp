#include <bits/stdc++.h>

using namespace std;

vector<char> staq;
vector<char> dealer;
vector<char> player;

int cnt = 0;

void players_turn(char face = ' ');

void printt()
{
    int winner = 0;
    if (dealer.empty())
        winner = 2;
    else if (player.empty())
        winner = 1;
    
    printf("%d%3d\n", winner, winner == 1 ? dealer.size() : player.size());
}

void enemys_turn(char face = ' ')
{
    if (dealer.empty() or player.empty())
    {
        printt();
        exit(0);
    }
    int n = face == 'J' ? 1 : face == 'Q' ? 2 : face == 'K' ? 3 : face == 'A' ? 4 : 1;
    bool face_card = false;
    
    for (int i = 0; i < n; ++i) {
        staq.push_back( dealer.back() );
        dealer.pop_back();
        
        if (staq.back() == 'J' or staq.back() == 'Q' or staq.back() == 'K' or staq.back() == 'A')
        {
            face_card = true;
            break;   
        }
        
    }
    if (face_card)
        players_turn(staq.back());
    else
    {
        // забирает всю колоду()
        reverse(staq.begin(), staq.end());
        // стек перевернутый в начало карт противнкиа
        dealer.insert( dealer.begin(), staq.begin(), staq.end() );
        staq.clear();
        
        players_turn();
    }

}


void players_turn(char face)
{
    if (dealer.empty() or player.empty())
    {
        printt();
        exit(0);
    }
    int n = face == 'J' ? 1 : face == 'Q' ? 2 : face == 'K' ? 3 : face == 'A' ? 4 : 1;
    bool face_card = false;
    
    for (int i = 0; i < n; ++i) {
        staq.push_back( player.back() );
        player.pop_back();
        
        if (staq.back() == 'J' or staq.back() == 'Q' or staq.back() == 'K' or staq.back() == 'A')
        {
            face_card = true;
            break;   
        }
        
    }
    if (face_card)
        enemys_turn(staq.back());
    else
    {
        // забирает всю колоду(), lilo
        reverse(staq.begin(), staq.end());
        
        player.insert( player.begin(), staq.begin(), staq.end() );
        staq.clear();
        
        enemys_turn();
    }
    
}

void simulateGame()
{
    int winner = 0;
    int cnt = 0;
    
    while (!dealer.empty() and !player.empty())
    {
        players_turn();
        
    }
    printt();
}

int main() {
    
    bool end = false;
    while (!end)
    {
        string s;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 13; ++j)
            {
                cin >> s;
                if (s == "#")
                {
                    end = true;
                    return 0;
                }

                if (cnt % 2 == 0)
                    player.push_back(s[1]);
                else
                    dealer.push_back(s[1]);
                
                ++cnt;
            }
        }
        
        simulateGame();
        //printt();
        // for (auto c : player)
        //     cout << c << " ";
        // cout << "\n";    
    }
    
}
