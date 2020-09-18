#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    int g, m;
    while(t--)
    {
        vector <int> godzilla;
        vector <int> mecha;
        cin >> g >> m;
        
        for(int i = 0; i < g; i++) {
            // Мои субмишуны не проходили потому что я
            // снова считывал здесь г вместо икса и в том цикле аналогично, вот я даун хахахх
            int x;
            cin >> x;
            godzilla.push_back(x);
        }
            
        for(int i = 0; i < m; i++) {
            int x;
            cin >> x;
            mecha.push_back(x);
        }
        
        sort(godzilla.begin(), godzilla.end());
        sort(mecha.begin(), mecha.end());
        
        while( !godzilla.empty() and !mecha.empty() )
        {
            
            if ( godzilla[0] < mecha[0] )
                godzilla.erase(godzilla.begin());
            else
                mecha.erase(mecha.begin());
            
        }
        if (godzilla.empty())
            cout << "MechaGodzilla\n";
        else if (mecha.empty())
            cout << "Godzilla\n";
        else
            cout << "uncertain\n";
    }
    
}