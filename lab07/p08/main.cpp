#include <bits/stdc++.h>
#include "../../libs/utils.hpp"

using namespace std;

int main()
{
    vector <int> v = {0, 4, 5, 10, 12, 20, 25, 40};

    for (int x; cin >> x;)
    {
        auto it = auLower_bound(v.begin(), v.end(), x);

        if (it == v.end())
        {
            cout << "NO elements in vector, greater than " << x << endl;
        }
        else if (*it == x)
        {
            cout << "Index of first element, equal to " << x << " is " << it - v.begin() << "\n";
        }
        else if(*it > x)
        {
            cout << "Index of first element, greater than " << x << " is " << it - v.begin() << "\n";
        }
        
    }
}