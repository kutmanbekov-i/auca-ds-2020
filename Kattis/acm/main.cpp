#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int m, i = 0, solved = 0, sum = 0;
    char c;
    string s;
    
    int penalty[101];
    memset(penalty, 0, sizeof(penalty));
    bool slvd[101];
    memset(slvd, false, sizeof(slvd));
    int minutes[101];
    memset(minutes, 0, sizeof(minutes));
    
    string line;
    while(cin >> m)
    {
        if (m == -1) break;
        
        else {
            cin >> c >> s;
            
            if (s == "right") {
                solved++;
                slvd[ c - 'A' ] = true;
                minutes[ c - 'A' ] += m;
            }
            
            else if (s == "wrong") 
                penalty[ c - 'A' ]++ ;
        }
    }
    for (i = 0; i < 101; i++)
    {
        if ( slvd[ i ] )
        {
            sum += minutes[ i ] + (20 * penalty[ i ]);
        }
    }
    cout << solved << " " << sum << "\n";
}