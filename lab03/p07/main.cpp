#include <iostream>

using namespace std;

int main() {
    
    int n;
    
    cin >> n;
    
    while (n--)
    {
        int m = 0, f = 0;
        
        string s;
        
        getline(cin, s);
        
        while (s.length() ==0)
            getline(cin, s);
        
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'M')
                ++m;
            else if (s[i] == 'F')
                ++f;
        }

        if ( (f > 1 and m > 1) and f == m)
            cout << "LOOP\n";
        else
            cout << "NO LOOP\n";
        // привет
    }
}