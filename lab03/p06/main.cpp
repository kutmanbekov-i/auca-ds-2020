#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int k, m;
    
    while (true)
    {
        cin >> k;
        
        if ( k == 0 ) break;
        
        cin >> m;
        
        string courses[k];
        bool b = true;
        
        // string categories[m];
        
        for (int i = 0; i < k; ++i)
            cin >> courses[i];
        
        int c, r = 0;
        
        string s;
        for (int i = 0; i < m; ++i)
        {
            int satisfied = 0;
            
            cin >> c >> r;
            
            for (int j = 0; j < c; ++j)
            {
                cin >> s;
                for (int m = 0; m < k; ++m)
                {
                    if (s == courses[m]){
                        ++satisfied;
                        break;
                    }
                }
            }
            if (satisfied < r) b = false;
            
        }
        
        cout << (b ? "yes\n" : "no\n");
    }
    
}