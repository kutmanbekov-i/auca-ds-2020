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
            cin >> g;
            godzilla.push_back(g);
        }
            
        for(int i = 0; i < m; i++) {
            cin >> m;
            mecha.push_back(m);
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
        cout << ( mecha.empty() ? "Godzilla" : "MechaGodzilla" ) << "\n";
    }
    
}