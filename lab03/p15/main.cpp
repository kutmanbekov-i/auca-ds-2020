#include <bits/stdc++.h>

using namespace std;

char board[12][12];

void parse(string s);
void printt(char board[12][12]);

bool square_attacked(int i, int j, int shift);

int main() {
    
    string s;
    while (cin >> s)
    {
        for (int i = 0; i < 12; ++i)
            for (int j = 0; j < 12; ++j)
                board[i][j] = '.';
        parse(s);
        // printt(board);
        int cnt = 0;
        
        for (int i = 2; i < 10; ++i)
            for (int j = 2; j < 10; ++j)
                if (board[i][j] == '.' and !square_attacked(i, j, 32) and !square_attacked(i, j, 0))
                    cnt++;
        cout << cnt << "\n";
    }   
}

void parse(string s)
{
    int i = 2, j = 2;
    for (auto c : s)
    {
        if (c == '/')
        {
            ++i; j = 2;
            continue;
        }
        if (isdigit(c))
        {
            for (int k = j; k < c - '0' + j; ++k)
            {
                board[i][k] = '.';
            }
            j += (c - '0') - 1;
        }
        else
            board[i][j] = c;
        ++j;
    }
}

void printt(char board[12][12])
{
    for (int i = 2; i < 10; ++i)
    {
        for (int j = 2; j < 10; ++j)
            cout << board[i][j];
        cout << "\n";
    }
    cout << "\n";
}

bool square_attacked(int i, int j, int shift)
{
    //enemy figures
    char pawn = char('P' + shift);
    char rook = char('R' + shift);
    char bishop = char('B' + shift);
    char queen = char('Q' + shift);
    char knight = char('N' + shift);
    char king = char('K' + shift);
    
    //up
    for (int k = i - 1; k >= 2; --k)
    {
        if (board[k][j] != '.')
        {
            if(board[k][j] == rook or board[k][j] == queen)
                return true;
            
            else break;
        }
    }
    
    //down
    for (int k = i + 1; k < 10; ++k)
    {
        if (board[k][j] != '.')
        {
            if(board[k][j] == rook or board[k][j] == queen)
                return true;
            
            else break;
        }
    }
    
    //left
    for (int k = j - 1; k >= 2; --k)
    {
        if (board[i][k] != '.')
        {
            if(board[i][k] == rook or board[i][k] == queen)
                return true;
            
            else break;
        }
    }
    
    //right
    for (int k = j + 1; k < 10; ++k)
    {
        if (board[i][k] != '.')
        {
            if(board[i][k] == rook or board[i][k] == queen)
                return true;
            
            else break;
        }
    }
    
    //up-left
    for (int ki = i - 1, kj = j - 1; ki >= 2 and kj >= 2; --ki, --kj)
    {
        if (board[ki][kj] != '.')
        {
            if (board[ki][kj] == bishop or board[ki][kj] == queen)
                return true;
                
            else break;
        }
    }
    
    //up-right
    for (int ki = i - 1, kj = j + 1; ki >= 2 and kj < 10; --ki, ++kj)
    {
        if (board[ki][kj] != '.')
        {
            if (board[ki][kj] == bishop or board[ki][kj] == queen)
                return true;
                
            else break;
        }
    }
    
    //down-left
    for (int ki = i + 1, kj = j - 1; kj < 10 and kj >= 2; ++ki, --kj)
    {
        if (board[ki][kj] != '.')
        {
            if (board[ki][kj] == bishop or board[ki][kj] == queen)
                return true;
                
            else break;
        }
    }
    
    //down-right
    for (int ki = i + 1, kj = j + 1; ki < 10 and kj < 10; ++ki, ++kj)
    {
        if (board[ki][kj] != '.')
        {
            if (board[ki][kj] == bishop or board[ki][kj] == queen)
                return true;
                
            else break;
        }
    }
    
    // int ki = i, kj = j;
    
    //pawns
    if (shift == 32)
        if (board[i - 1][j - 1] == pawn or board[i - 1][j + 1] == pawn)
            return true;
    if (shift == 0)
        if (board[i + 1][j + 1] == pawn or board[i + 1][j - 1] == pawn)
            return true;
    // if (shift == 32 and (board[i - 1][j + 1] == pawn or board[i - 1][j - 1] == pawn) )
    //     return true;
    // else if(shift == 0 and (board[i + 1][j + 1] == pawn or board[i + 1][j - 1] == pawn) )
    //     return true;
        
    //knights
    if (board[i - 2][j - 1] == knight or board[i - 1][j - 2] == knight or board[i + 1][j - 2] == knight or board[i + 2][j - 1] == knight or
        board[i + 2][j + 1] == knight or board[i + 1][j + 2] == knight or board[i - 1][j + 2] == knight or board[i - 2][j + 1] == knight)
        return true;
        
    return false;
}

