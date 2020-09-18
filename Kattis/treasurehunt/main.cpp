#include <bits/stdc++.h>

using namespace std;

int main() {

    int r, c;
    
    cin >> r >> c;
    
    char a[r][c];
    bool used[r][c];
    memset(used, false, sizeof(used));

    // sure that it can be solved in 50-sh lines
    
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            cin >> a[i][j];
    
    int steps = 0;
    bool leave = false;
    bool lost = false;
    bool treasure = false;
    
    for (int i = 0; i < r; )
    {
        if (leave or lost or treasure) break;
        
        for (int j = 0; j < c; )
        {
            if (a[i][j] == 'N')
            {
                if (i == 0) { 
                    leave = true;
                    break; 
                } else if (used[i - 1][j]) { 
                    lost = true;
                    break;
                } else {
                    used[i - 1][j] = true;
                    --i;
                    ++steps;
                }
            } else if (a[i][j] == 'S') {
                if (i == r - 1) { 
                    leave = true;
                    break; 
                } else if (used[i + 1][j]) { 
                    lost = true;
                    break;
                } else {
                    used[i + 1][j] = true;
                    ++i;
                    ++steps;
                }
            } else if (a[i][j] == 'W') {
                if (j == 0) { 
                    leave = true;
                    break; 
                } else if (used[i][j - 1]) { 
                    lost = true;
                    break;
                } else {
                    used[i][j - 1] = true;
                    --j;
                    ++steps;
                }
            } else if (a[i][j] == 'E') {
                if (j == c - 1) { 
                    leave = true;
                    break; 
                } else if (used[i][j + 1]) { 
                    lost = true;
                    break;
                } else {
                    used[i][j + 1] = true;
                    ++j;
                    ++steps;
                }
            } else if (a[i][j] == 'T') {
                treasure = true;
                break;
            } 
        }
    }
    if (treasure)
        cout << steps << "\n";
    else if (leave)
        cout << "Out\n";
    else if (lost)
        cout << "Lost\n";
}