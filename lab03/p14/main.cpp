#include <bits/stdc++.h>

using namespace std;

char board[12][12];

bool check_king(pair<int, int> &king, int shift);

int main() {
    
    bool empty = false;
    
    pair<int, int> white, black;

    int t = 1;
    
    while (!empty)
    {
        empty = true;
        
        for (int i = 0; i < 12; ++i)
            for (int j = 0; j < 12; ++j)
                board[i][j] = '.';
        
        for (int i = 2; i < 10; ++i)
            for (int j = 2; j < 10; ++j)
            {
                scanf(" %c", &board[i][j]);
                // cin >> board[i][j];
                if (board[i][j] != '.')
                    empty = false;
                
                if (board[i][j] == 'k')
                {
                    black.first = i;
                    black.second = j;
                }
                else if (board[i][j] == 'K')
                {
                    white.first = i;
                    white.second = j;
                }
            }
        
        if (empty)
            break;
        
        bool white_shah = check_king(white, 32);
        bool black_shah = check_king(black, 0);
        

        if (black_shah and !white_shah)
            printf("Game #%d: black king is in check.\n", t++);
        else if (white_shah and !black_shah)
            printf("Game #%d: white king is in check.\n", t++);
        else 
            printf("Game #%d: no king is in check.\n", t++);

        // cin.ignore();  
    }
}


bool check_king(pair<int, int> &king, int shift)
{
    //enemy figures
    char pawn = char('P' + shift);
    char rook = char('R' + shift);
    char bishop = char('B' + shift);
    char queen = char('Q' + shift);
    char knight = char('N' + shift);
    char enemy_king = char('K' + shift);
    
    //up
    for (int i = king.first - 1, j = king.second; i >= 2; --i)
    {
        if (board[i][j] != '.')
        {
            if(board[i][j] == rook or board[i][j] == queen)
                return true;
            
            else break;
        }
    }
    
    //down
    for (int i = king.first + 1, j = king.second; i < 10; ++i)
    {
        if (board[i][j] != '.')
        {
            if(board[i][j] == rook or board[i][j] == queen)
                return true;
            
            else break;
        }
    }
    
    //left
    for (int i = king.first, j = king.second - 1; j >= 2; --j)
    {
        if (board[i][j] != '.')
        {
            if(board[i][j] == rook or board[i][j] == queen)
                return true;
            
            else break;
        }
    }
    
    //right
    for (int i = king.first, j = king.second + 1; j < 10; ++j)
    {
        if (board[i][j] != '.')
        {
            if(board[i][j] == rook or board[i][j] == queen)
                return true;
            
            else break;
        }
    }
    
    //up-left
    for (int i = king.first - 1, j = king.second - 1; i >= 2 and j >= 2; --i, --j)
    {
        if (board[i][j] != '.')
        {
            if (board[i][j] == bishop or board[i][j] == queen)
                return true;
                
            else break;
        }
    }
    
    //up-right
    for (int i = king.first - 1, j = king.second + 1; i >= 2 and j < 10; --i, ++j)
    {
        if (board[i][j] != '.')
        {
            if (board[i][j] == bishop or board[i][j] == queen)
                return true;
                
            else break;
        }
    }
    
    //down-left
    for (int i = king.first + 1, j = king.second - 1; i < 10 and j >= 2; ++i, --j)
    {
        if (board[i][j] != '.')
        {
            if (board[i][j] == bishop or board[i][j] == queen)
                return true;
                
            else break;
        }
    }
    
    //down-right
    for (int i = king.first + 1, j = king.second + 1; i < 10 and j < 10; ++i, ++j)
    {
        if (board[i][j] != '.')
        {
            if (board[i][j] == bishop or board[i][j] == queen)
                return true;
                
            else break;
        }
    }
    
    int i = king.first, j = king.second;
    
    //pawns
    if (shift == 32)
        if (board[i - 1][j - 1] == pawn or board[i - 1][j + 1] == pawn)
            return true;
    if (shift == 0)
        if (board[i + 1][j + 1] == pawn or board[i + 1][j - 1] == pawn)
            return true;

    //knights
    if (board[i - 2][j - 1] == knight or board[i - 1][j - 2] == knight or board[i + 1][j - 2] == knight or board[i + 2][j - 1] == knight or
        board[i + 2][j + 1] == knight or board[i + 1][j + 2] == knight or board[i - 1][j + 2] == knight or board[i - 2][j + 1] == knight)
        return true;
        
    return false;
}

