#include <bits/stdc++.h>

using namespace std;

vector<char> p1(52);
vector<char> p2(52);
vector<char> staq(52);

const int JACK = 1;
const int QUEEN = 2;
const int KING = 3;
const int ACE = 4;

void staqToDeck(vector<char> &v, vector<char> &staq, int &vSize, int &staq_size)
{
    for (int i = vSize - 1; i >= 0; i--)
    {
        v[i + staq_size] = v[i];
    }
    for (int i = 0, j = staq_size - 1; i < staq_size; i++, j--)
    {
        v[i] = staq[j];
    }
    // reverse(staq.begin(), staq.end());
    // v.insert( v.begin(), staq.begin(), staq.end() );
    vSize += staq_size;
    staq_size = 0;
}

void cover(vector<char> &p1, vector<char> &p2, vector<char> &staq, int &dealer_size, int &player_size, int &staq_size, bool &dealers_turn, int n)
{
    char c;
    
    for (int i = 0; i < n; i++)
    {
        if (dealer_size == 0)
        {
            dealer_size = -1;
            return;
        }
        c = p1[--dealer_size];
        staq[staq_size++] = c;
        
        switch (c)
        {
            case 'J' :
                dealers_turn = !dealers_turn;
                cover(p2, p1, staq, player_size, dealer_size, staq_size, dealers_turn, JACK);
                return;
            case 'Q' :
                dealers_turn = !dealers_turn;
                cover(p2, p1, staq, player_size, dealer_size, staq_size, dealers_turn, QUEEN);
                return;
            case 'K' :
                dealers_turn = !dealers_turn;
                cover(p2, p1, staq, player_size, dealer_size, staq_size, dealers_turn, KING);
                return;
            case 'A' :
                dealers_turn = !dealers_turn;
                cover(p2, p1, staq, player_size, dealer_size, staq_size, dealers_turn, ACE);
                return;
            
        }

    }
    dealers_turn = !dealers_turn;
    staqToDeck(p2, staq, player_size, staq_size);
}

void simulate_game(vector<char> &p1, vector<char> &p2, vector<char> &staq, int &dealer_size, int &player_size, int &staq_size, bool &dealers_turn)
{
    char c;
    if (player_size > 0)
    {
        c = p2[--player_size];
    }
    else
    {
        player_size = -1;
        return;
    }
    staq[staq_size++] = c;
    dealers_turn = !dealers_turn;
    
    switch (c)
    {
        case 'J':
            cover(p1, p2, staq, dealer_size, player_size, staq_size, dealers_turn, JACK);
                break;
        case 'Q':
            cover(p1, p2, staq, dealer_size, player_size, staq_size, dealers_turn, QUEEN);
                break;
        case 'K':
            cover(p1, p2, staq, dealer_size, player_size, staq_size, dealers_turn, KING);
                break;
        case 'A':
            cover(p1, p2, staq, dealer_size, player_size, staq_size, dealers_turn, ACE);
                break;
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, q;
    int staq_size, dealer_size, player_size;
    bool dealers_turn;
    while (true)
    {
        dealer_size = 26;
        player_size = 26;

        staq_size = 0;
        dealers_turn = false;

        for (int i = 0; i < 26; i++)
        {
            cin >> s >> q;
            if (s == "#") return 0;

            p2[i] = s[1];
            p1[i] = q[1];
        }
        while (dealer_size != -1 and player_size != -1)
        {
            if (!dealers_turn)
            {
                simulate_game(p1, p2, staq, dealer_size, player_size, staq_size, dealers_turn);
            }
            else
            {
                simulate_game(p2, p1, staq, player_size, dealer_size, staq_size, dealers_turn);
            }

        }
        if (dealer_size == -1)
        {
            cout << "2" << right << setw(3) << player_size << "\n";
        }
        else
        {
            cout << "1" << right << setw(3) << dealer_size << "\n";
        }

    }
}