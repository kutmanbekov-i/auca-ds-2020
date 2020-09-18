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
        
        int g_ind = 0, m_ind = 0;
        while( g_ind < g and m_ind < m )
        {
            
            if ( godzilla[g_ind] < mecha[m_ind] )
                ++g_ind;
            else
                ++m_ind;
            
        }
        if (g_ind == g)
            cout << "MechaGodzilla\n";
        else if (m_ind == m)
            cout << "Godzilla\n";
        else
            cout << "uncertain\n";
    }
    
}