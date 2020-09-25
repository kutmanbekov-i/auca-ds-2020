#include <bits/stdc++.h>

using namespace std;

bool allCharactersSame(string s);

int main() {
    
    string s;
    int c = 1;
    
    while (cin >> s)
    {
        cout << "Case " << c++ << ":\n";
        int n;
        cin >> n;
        
        int i, j;
        while (n--)
        {
            cin >> i >> j;
            // substring(index, length)
            string temp = s.substr(min(i, j), max(i, j) - min(i, j) + 1);
            
            if (allCharactersSame(temp))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    // привет))
}

bool allCharactersSame(string s) 
{ 
    int n = s.length(); 
    for (int i = 1; i < n; i++) 
        if (s[i] != s[0]) 
            return false; 
  
    return true; 
} 