#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, c = 1;


    cin >> t;

    while(t--)
    {
        vector<string> indexes;
        indexes.clear();
        
        int max = 0;
        for (int i = 0; i < 10; i++)
        {
            string s;
            int r;
            cin >> s >> r;

            if (r > max)
            {
                max = r;
                indexes.clear();
                indexes.push_back(s);
            } else if (r == max) {
                max = r;
                indexes.push_back(s);
            }
        }

        cout << "Case #" << c++ << ":\n";
        for (auto s: indexes) {
            cout << s << "\n";
        }

    }
}