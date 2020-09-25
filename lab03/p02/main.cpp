#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    cin >> t;

    while(t--)
    {
        int n, x = 0;

        cin >> n;
        vector<string> v;

        for (int i = 0; i < n; i++)
        {
            string s;

            cin >> s;
            v.insert(v.begin() + i, s);

            if (s[0] == 'L')
                --x;
            else if (s[0] == 'R')
                ++x;
            else if (s[0] == 'S')
            {
                string as;
                int z;
            
                cin >> as >> z;

                v.insert(v.begin() + i,  v[z - 1] );

                if (v[z - 1] == "LEFT")
                    --x;
                else if(v[z - 1] == "RIGHT")
                    ++x;
            }
        }
        cout << x << "\n";
    }
}
