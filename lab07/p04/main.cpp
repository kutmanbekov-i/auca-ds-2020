#include <bits/stdc++.h>
#include "../../libs/utils.hpp"

using namespace std;

int main()
{
    vector<int> v;

    for (int x; cin >> x; )
    {
        v.push_back(x);
    }

    auto it = auMin_element(v.begin(), v.end());

    if (it != v.end())
    {
        cout << "Index of minimum value " << *it << " is " << it - v.begin() << endl;
    }
    else
    {
        cout << "Not found\n";
    }
       
}