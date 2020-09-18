#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int a, b, c, d;
    
    while(cin >> a >> b >> c >> d)
    {
        if (a == 0 and b == 0 and c == 0 and d == 0) break;
        
        string first = to_string(max(a, b)) + to_string(min(a, b));
        string second = to_string(max(c, d)) + to_string(min(c, d));
        
        if (first == second) cout << "Tie.\n";
        
        else {
            int x = stoi(first);
            int y = stoi(second);
            int winner = x > y ? 1 : 2;
            
            if (x == 21 or y == 21)
                winner = ( x == 21 ? 1 : 2 );
            
            else if (first[0] == first[1] and second[0] == second[1])
                winner = x > y ? 1 : 2;
                
            else if (first[0] == first[1])
                winner = 1;
            
            else if (second[0] == second[1])
                winner = 2;
                
            cout << "Player " << winner << " wins.\n";
        }
    }
}