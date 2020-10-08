#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, m, c, t = 1;
    
    while (true)
    {
        cin >> n >> m >> c;
        
        if (n == 0 and m == 0 and c == 0) break;
        
        vector<int> devices;
        vector<bool> state;
        int x;
        
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            devices.push_back(x);
            state.push_back(false);
        }
        int cmd;
        int maxim = -1, sum = 0;
        bool blown = false;
        
        for (int i = 0; i < m; ++i)
        {
            cin >> cmd;
            state[cmd - 1] = !state[cmd - 1];
            
            if (state[cmd - 1])
            {
                sum += devices[cmd - 1];
                maxim = max(maxim, sum);
            }
            else
            {
                sum -= devices[cmd - 1];
            }
            
            if (sum > c)
                blown = true;
 
        }
        cout << "Sequence " << t++ << "\n";
        
        if (blown)
            cout << "Fuse was blown.\n";
        else
            cout << "Fuse was not blown.\n" << "Maximal power consumption was " << maxim << " amperes.\n";
        
        cout << "\n";
    }
    
}