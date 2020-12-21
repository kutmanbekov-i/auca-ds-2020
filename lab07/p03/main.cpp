#include <bits/stdc++.h>
#include "../../libs/utils.hpp"

using namespace std;

struct  GreaterThan
{
    int num;
    GreaterThan(int x)
        : num(x)
    {
    }
    bool operator()(int a)
    {
        return a > num;
    }
};

int main()
{
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    int x; cin >> x;


    cout << "Functor test:\n";

    auto it = auFind_if(v.begin(), v.end(), GreaterThan(x));

    if (it != v.end())
    {
        cout << "Index of first number greater than " << x << " is " << it - v.begin() << endl;
    }
    else
    {
        cout << "not found\n";
    }

    cout << "\nLambda test:\n";
    it = auFind_if(v.begin(), v.end(), [&x](int a) { return a > x; });

    if (it != v.end())
    {
        cout << "Index of first number greater than " << x << " is " << it - v.begin() << endl;
    }
    else
    {
        cout << "not found\n";
    }
    
}