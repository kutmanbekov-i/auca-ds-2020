#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    string s;
    
    cin >> n;
    
    while (n--)
    {
        int m = 0, f = 0, cnt = 0;
    
        getline(cin, s);

        while (s.length() ==0)
            getline(cin, s);
        
        istringstream sin(s);

        for (string w; sin >> w; )
        {
            ++cnt;
            m += w[0] == 'M';
            m += w[1] == 'M';
            f += w[0] == 'F';
            f += w[1] == 'F'; 
        }

        cout << (cnt > 1 and f == m ? "LOOP" : "NO LOOP") << "\n";
        // привет
    }
}