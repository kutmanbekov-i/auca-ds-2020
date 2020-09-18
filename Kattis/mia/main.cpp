#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int a, b, c, d, game = 0;
    
    while(cin >> a >> b >> c >> d)
    {
        if (a == 0 and b == 0 and c == 0 and d == 0) break;
        
        string first = to_string(max(a, b)) + to_string(min(a, b));
        string second = to_string(max(c, d)) + to_string(min(c, d));
        
        if (first == second) cout << "Tie.\n";
        
        else if (first[0] == '2' and first[1] == '1')
            printf("Player 1 wins.\n");
        else if (second[0] == '2' and second[1] == '1')
            printf("Player 2 wins.\n");
        
        else if (first[0] == first[1] and second[0] == second[1])
        {
            printf("Player %d wins.\n", (1 ? first[0] > second[0] : 2));
        }
        else if (first[0] == first[1]) {
            printf("Player 1 wins.\n");
        }
        else if (second[0] == second[1]) {
            printf("Player 2 wins.\n");
        }
        else {
            printf("Player %d wins.\n", (1 ? first[0] > second[0] : 2));
        }
        
    }
}