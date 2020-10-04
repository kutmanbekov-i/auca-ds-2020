#include <bits/stdc++.h>

using namespace std;

char board[8][8];

bool check_HV(int team, int i, int j);

bool check_DIAGONALS(int team, int i, int j);

bool check_kon(int team, int i, int j);

int main() {
    
    bool empty = false;

    int t = 1;
    
    while (!empty)
    {
        empty = true;
        
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
            {
                // scanf(" %c", &board[i][j]);
                cin >> board[i][j];
                if (board[i][j] != '.' or !board[i][j])
                    empty = false;
            }
        
        if (empty)
            break;
            
        bool white = false;
        bool black = false;
        
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                // checking kings for lose
                if (board[i][j] == 'k')
                    black = check_HV(2, i, j) or check_DIAGONALS(2, i, j) or check_kon(2, i, j);
                else if (board[i][j] == 'K')
                    white = check_HV(1, i, j) or check_DIAGONALS(1, i, j) or check_kon(1, i, j);
                if (white or black)
                    break;
            }
            if (white or black) break;
        }

        if (black and !white)
            printf("Game #%d: black king is in check.\n", t++);
        else if (!black and white)
            printf("Game #%d: white king is in check.\n", t++);
        else 
            printf("Game #%d: no king is in check.\n", t++);

        cin.ignore();
    }
}

bool check_HV(int team, int i, int j)
{
    char p, r, b, q, my_k, n;

    // black lost?
    if (team == 2)
    {
        p = 'P';
        r = 'R';
        b = 'B';
        q = 'Q';
        my_k = 'k';
        n = 'N';
    } else {
        p = 'p';
        r = 'r';
        b = 'b';
        q = 'q';
        my_k = 'K';
        n = 'n';
    }
    
    // check verticals
    bool king_met = false;
    bool enemy_met = false;
    for (int k = 0; k < 8; ++k)
    {
        if (board[k][j] == my_k) 
        {
            if (enemy_met)
                return true;
            king_met = true;
        }
        
        else if (board[k][j] != '.')
        {
            if (board[k][j] == r or board[k][j] == q)
            {
                if (king_met)
                    return true;
                enemy_met = true;
            }
            else
            {
                if (king_met or enemy_met)
                    break;
            }
        }
    }
    
    king_met = false;
    enemy_met = false;
    
    //check horizontals
    for (int k = 0; k < 8; ++k)
    {
        if (board[i][k] == my_k) 
        {
            if (enemy_met)
                return true;
            king_met = true;
        }
        
        else if (board[i][k] != '.')
        {
            if (board[i][k] == r or board[i][k] == q)
            {
                if (king_met)
                    return true;
                enemy_met = true;
            }
            else
            {
                if (king_met or enemy_met)
                    break;
            }
        }
    }
    
    return false;
}

bool check_DIAGONALS(int team, int i, int j)
{
    bool king_met = false;
    bool enemy_met = false;

    char p, r, b, q, my_k, n;

    // black lost?
    if (team == 2)
    {
        p = 'P';
        r = 'R';
        b = 'B';
        q = 'Q';
        my_k = 'k';
        n = 'N';
        
        //checking for pawn
        if (i < 7 and j < 7 and j > 0 and board[i + 1][j + 1] == p or board[i + 1][j - 1] == p)
            return true;
        
    } else {
        p = 'p';
        r = 'r';
        b = 'b';
        q = 'q';
        my_k = 'K';
        n = 'n';
        
        //checking for pawn
        if ( i > 0 and j > 0 and j < 7 and board[i - 1][j + 1] == p or board[i - 1][j - 1] == p)
            return true;
    }

    int t = min(i, j);
    int ki = i - t;
    int kj = j - t;

    // down right
    for (; max(ki, kj) < 8; ++ki, ++kj)
    {
        if (board[ki][kj] == my_k) 
        {
            if (enemy_met)
                return true;
            king_met = true;
        }
        
        else if (board[ki][kj] != '.')
        {
            if (board[ki][kj] == b or board[ki][kj] == q)
            {
                if (king_met)
                    return true;
                enemy_met = true;
            }
            else
            {
                if (king_met or enemy_met)
                    break;
            }
        }
    }

    king_met = false;
    enemy_met = false;

    t = max(i, j);

    if (i + j <= 7) { // above the secondary
        ki = 0;
        kj = i + j - ki;
    } else {        // below
        kj = 7;     //the bug must be here!
        ki = i + j - kj; 
    }

    bool I = (ki != 0);

    // down left
    for (; ;)
    {
        if (board[ki][kj] == my_k) 
        {
            if (enemy_met)
                return true;
            king_met = true;
        }
        
        else if (board[ki][kj] != '.')
        {
            if (board[ki][kj] == b or board[ki][kj] == q)
            {
                if (king_met)
                    return true;
                enemy_met = true;
            }
            else
            {
                if (king_met or enemy_met)
                    break;
            }
        }
        if (I)
        {
            --ki;
            ++kj;
            if (ki == 0) break;
        } else {
            --kj;
            ++ki;
            if (kj == 0) break;
        }
    }

    return false;
}


bool check_kon(int team, int y, int x)
{
    char n = team == 2 ? 'N' : 'n';
    
    if (x - 2 >= 0)
    {
        if (y - 1 >= 0 && board[y - 1][x - 2] == n)
            return true;
        
        if (y + 1 < 8 && board[y + 1][x - 2] == n)
            return true;
    }
    
    if (x + 2 < 8)
    {
        if (y - 1 >= 0 && board[y - 1][x + 2] == n)
            return true;
            
        if (y + 1 < 8 && board[y + 1][x + 2] == n)
            return true;
    }
    
    if (y - 2 >= 0)
    {
        if (x - 1 >= 0 && board[y - 2][x - 1] == n)
            return true;
        
        if (x + 1 < 8 && board[y - 2][x + 1] == n)
            return true;
    }
    
    if (y + 2 < 8)
    {
        if (x - 1 >= 0 && board[y + 2][x - 1] == n)
            return true;
            
        if (x + 1 < 8 && board[y + 2][x + 1] == n)
            return true;
    }
    
    return false;
    
    // char my_k, n;
    
    // if (team == 2)
    // {
    //     my_k = 'k';
    //     n = 'N';
    // } else {
    //     my_k == 'K';
    //     n = 'n';
    // }
    
    // if (board[i - 1][j - 2] == n or board[i - 2][j - 1] == n or board[i - 2][j + 1] == n or board[i - 1][j + 2] == n or
    //     board[i + 1][j - 2] == n or board[i + 2][j - 1] == n or board[i + 2][j + 1] == n or board[i + 1][j + 2] == n)
    // {
    //     return true;
    // }
    // return false;
}