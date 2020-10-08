#include <bits/stdc++.h>

using namespace std;

void represent(vector<vector<char>> &grid, vector<vector<char>> &out);
void printt(vector<vector<char>> &vec);

int y[] = { -1, -1, -1, 0, 1, 1, 1, 0 }; 
int x[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int main() {
    
    
    int t; bool line = false;
    
    scanf("%d", &t);
    
    while (t--)
    {
        if (line) printf("\n");
        line = true;
        int n;
        
        scanf("%d", &n);
        
        vector<vector<char>> mines (n + 2, vector<char> (n + 2));
        vector<vector<char>> grid (n + 2, vector<char> (n + 2));
        
        bool touched = false;
        
        for (int i = 1; i < n + 1; ++i)
            for (int j = 1; j < n + 1; ++j)
            {
                char c;
                scanf(" %c", &c);
                //mines[i].insert(mines[i].begin() + j, c);
                mines[i][j] = c;
            }
        for (int i = 1; i < n + 1; ++i)
            for (int j = 1; j < n + 1; ++j)
            {
                char c;
                scanf(" %c", &c);
                grid[i][j] = c;
            }
            
        represent(grid, mines);
        printt(grid);

    }
}

void represent(vector<vector<char>> &grid, vector<vector<char>> &mines)
{
    int cnt; bool touched = false;
    for (int i = 1; i < grid.size() - 1; ++i)
    {
        for (int j = 1; j < grid[i].size() - 1; ++j)
        {
            cnt = 0;
            if (grid[i][j] == 'x')
            {
                if (mines[i][j] == '*')
                {
                    touched = true;
                }
                else
                {
                    for (int dir = 0; dir < 8; ++dir)
                    {
                        if (mines[i + y[dir]][j + x[dir]] == '*')
                            ++cnt;
                    }
                    grid[i][j] = cnt + '0';
                }
                
            }
        }
    }
    if (touched)
        for (int i = 1; i < grid.size() - 1; ++i)
            for (int j = 1; j < grid[i].size() - 1; ++j)
                if (mines[i][j] == '*')
                    grid[i][j] = '*';
    // I spent 5 minutes of my live just because I assigned new value like that: grid[i][j] == '*'; 
    // 
}

void printt(vector<vector<char>> &vec)
{
    for (int i = 1; i < vec.size() - 1; ++i)
    {
        for (int j = 1; j < vec[i].size() - 1; ++j)
        {
            printf("%c", vec[i][j]);
        }
        printf("\n");
    }
}