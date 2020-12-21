#include <bits/stdc++.h>
#include "../../libs/utils.hpp"

using namespace std;

struct  isEven
{
    bool operator()(int x)
    {
        return x % 2 == 0;
    }
};

int main()
{
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    cout << "Functor test:\n";

    auto it = auFind_if(v.begin(), v.end(), isEven());

    if (it != v.end())
    {
        cout << "Index of first even number is " << it - v.begin() << endl;
    }
    else
    {
        cout << "Even numberrs not found\n";
    }

    cout << "\nLambda test:\n";
    it = auFind_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });

    if (it != v.end())
    {
        cout << "Index of first even number " << v[it-v.begin()] << " is " << it - v.begin() << endl;
    }
    else
    {
        cout << "Even numberrs not found\n";
    }
}