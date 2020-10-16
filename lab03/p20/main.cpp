#include <bits/stdc++.h>

using namespace std;

void printt(vector<vector<char>> &screen)
{
    cout << "+----------+\n";   
    for (int i = 0; i < 10; ++i)
    {
        cout << "|";
        for (int j = 0; j < 10; ++j)
        {
            cout << screen[i][j];
        }
        cout << "|\n";
    }
    cout << "+----------+\n";  
}

void write(char c, vector<vector<char>> &screen, int row, int col, int mode)
{
    if (mode == 1)
    {
        screen[row][col] = c;
    }
    else if (mode == 2)
    {
        screen[row].insert( screen[row].begin() + col, c );
        // screen[row].erase( screen[row].end() );
    }
}

void interpret(const vector<string> &input, vector<vector<char>> &screen)
{
    int row = 0, col = 0;
    int mode = 1;
    
    for (int i = 0; i < input.size(); ++i)
    {
        for (int j = 0; j < input[i].length(); ++j)
        {
            // if (input[i][j] == '\\')
            // {
            //     write('\\', screen, row, col, mode);
            // }
            if (input[i][j] == '^')
            {
                if (j < input[i].size() - 2 and isdigit( input[i][j + 1] ) and isdigit( input[i][j + 2] ) )
                {
                    // move cursor
                    row = input[i][j + 1] - '0';
                    col = input[i][j + 2] - '0';
                    
                    j += 2;
                } else {
                    switch (input[i][j + 1])
                    {
                        case 'b':
                            col = 0; break;
                        case 'c':
                            // screen.clear(); break;
                            fill(screen.begin(), screen.end(), vector<char>(10, ' '));
                            break;
                        case 'e':
                            screen[row].erase( screen[row].begin() + col, screen[row].end() );
                            break;
                        case 'h':
                            row = 0; col = 0;
                            break;
                        case 'i':
                            // TODO: insert mode
                            mode = 2;
                            break;
                        case 'o':
                            // TODO: overwrite mode
                            mode = 1;
                            break;
                        case 'd':
                            if (row < 9)
                                ++row;
                            break;
                        case 'l':
                            if (col > 0)
                                --col;
                            break;
                        case 'r':
                            if (col < 9)
                                ++col;
                            break;
                        case 'u':
                            if (row > 0)
                                --row;
                            break;
                        case '^':
                            //TODO
                            write('^', screen, row, col, mode);
                            if (col < 9)
                                 ++col;
                            break;
                    }
                    j -= -1;
                }
                
            } else {
                // TODO:
                write( input[i][j], screen, row, col, mode );
                if (col < 9)
                    ++col;
            }
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, cases = 1;
    string t;
    
    while (true)
    {
        getline(cin, t);
        n = stoi(t);
        if (n == 0) break;
        
        vector<vector<char>> screen(10, vector<char>(10, ' ') );
        
        vector<string> input(n);
        string s;
        
        for (int i = 0; i < n; ++i)
        {
            getline(cin, s);

            input[i] = s;
        }
        
        interpret(input, screen);
        cout << "Case " << cases++ << "\n";
        printt(screen);
        
        // cin >> n;
        // cin.ignore();
    }
    
}
