#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int k, q, m, c = 1;
    
    while (cin >> k >> q >> m)
    {
        //cout << c++ << ": " << k << " " << q << " " << m << " – ";
        if (k == q)
        {
            cout << "Illegal state\n";
            continue;
        }
        
        pair<int, int> king( k / 8, k % 8 );
        pair<int, int> queen( q /8, q % 8 );
        pair<int, int> move( m / 8, m % 8 );
        
        if (king == move or queen == move or (move.first != queen.first and move.second != queen.second) or
            (king.first == queen.first and king.first == move.first and ((move.second < king.second and king.second < queen.second) or (queen.second < king.second and king.second < move.second))) or
            (king.second == queen.second and king.second == move.second and ((move.first < king.first and king.first < queen.first) or (queen.first < king.first and king.first < move.first))) )
        {
            // Here we must check if kign's and queen's position are the same, queen's and new queen's position are the same, 
            // if queen moves diagonally, if queen "jumps" over the king, i.e if king is in between the queen and queen's new position. Respectively
            cout << "Illegal move\n";
            continue;
        }
        
        if ((king.first - 1 == move.first and king.second == move.second) or (king.first + 1 == move.first and king.second == move.second) or
            (king.first == move.first and king.second - 1 == move.second) or (king.first == move.first and king.second + 1 == move.second))
            {
                // Simply, if queen is сlose to the king
                cout << "Move not allowed\n";
                continue;
            }
        if ((king.first == 0 and king.second == 0 and move.first - 1 == king.first and move.second - 1 == king.second) or 
            (king.first == 0 and king.second == 7 and move.first - 1 == king.first and move.second + 1 == king.second) or
            (king.first == 7 and king.second == 0 and move.first + 1 == king.first and move.second - 1 == king.second) or
            (king.first == 7 and king.second == 7 and move.first + 1 == king.first and move.second + 1 == king.second))
            {
                // Если короля загнали в угол
                cout << "Stop\n";
                continue;
            }
        cout << "Continue\n";
    }
    
}