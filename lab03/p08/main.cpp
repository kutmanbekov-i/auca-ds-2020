#include <bits/stdc++.h>

using namespace std;

int main()
{  
    bool new_line = false;
    int n;
    while (cin >> n)
    {
        map<string, int> info;
        vector<string> names;
        for (int i = 0; i < n; ++i)
        {
            string name;
            cin >> name;
            
            info[name] = 0;
            names.push_back(name);
        }
        for (int i = 0; i < n; ++i)
        {
            string name;
            int spent, x, aver;
            cin >> name >> spent >> x;
            
            // Command line terminated by signal 8...
            if (x == 0)
                continue;

            aver = spent / x;
            info[name] -= (aver * x);
            for (int j = 0; j < x; ++j)
            {
                cin >> name;
                info[name] += aver;
            }
        }

        if (new_line)
            cout << endl;
        for (int i = 0; i < n; ++i)
            cout << names[i] << " " << info[names[i]] << "\n";
                 
        new_line = true;
    }

}