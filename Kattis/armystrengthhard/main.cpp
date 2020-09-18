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
        
        int g_ind = 0;
        int m_ind = 0;
        
        // пришлось отказаться от удаления элементов вектора пока он не опустеет
        // о чем я думал это же медленно AS ****
        // крч замутил систему индексования

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