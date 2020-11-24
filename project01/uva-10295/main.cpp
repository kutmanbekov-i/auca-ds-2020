#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n;
    
    cin >> m >> n;
    vector<string> s(m);
    vector<double> v(m);
    
    for (int i = 0; i < m; ++i)
    {
        cin >> s[i] >> v[i];
    }
    for (int i = 0; i < n; ++i)
    {
        vector<string> temp;
        double value = 0;
        
        string str;
        while(1)
        {
            cin >> str;
            if (str == ".") break;
            temp.push_back(str);
            
            for (int j = 0; j < m; ++j)
            {
                if (str == s[j])
                {
                    value += v[j];
                    break;
                }
            }
        }
        cout << value << '\n';
    }
}