#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    while(cin >> s)
    {
        if (s == "END") break;
        
        int lena = s.length();
        int i = 1;
        
        while( lena != 1 )
        {
            string temp = to_string(lena);
            lena = temp.length();
            i++;
        }
        cout << ++i << "\n";
    }
    
}