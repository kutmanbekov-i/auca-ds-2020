#include <iostream>
#include "VecInt.hpp"
#include "../libs/utils.hpp"
#include <vector>
#include <algorithm>

using namespace std;

template<typename Container>
void print(const Container &v)
{
    for (auto e : v)
        cout << e << " ";
    cout << "\n";
}

void problem0101()
{
    int n;
    cin >> n;

    VecInt v(n);

    for (size_t i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    if (n == 5)
    {
        throw 42;
    }

    v.pushBack(42);

    print(v);

    auReverse(v.begin(), v.end());

    print(v);
}

void problem0102()
{
    VecInt v;

    int x;
    while (cin >> x)
    {
        v.pushBack(x);
    }
    print(v);

    auReverse(v.begin(), v.end());

    print(v);
}

void problem0201()
{
    VecInt v;

    for (int x; cin >> x;)
    {
        v.pushBack(x);
    }

    // VecInt w = v;
    VecInt w;
    w.pushBack(1);
    w.pushBack(-1);

    // we destroy previous value of '   w'
    w = v;

    auReverse(w.begin(), w.end());

    cout << (v == w ? "It is a palindrome!\n" : "It is not a palindrome!\n");
}

void problem0202()
{
    VecInt a = {1, 2, 3, 4};
    VecInt b = {5, 6, 7, 8, 9, 10};

    VecInt::counter = 0;

    auSwap(a, b);

    cout << "Number of integer assignments: " << VecInt::counter << endl;

    print(a);
    print(b);
}

void problem0301()
{
    vector<int> v;
    for (int x; cin >> x;)
    {
        v.push_back(x);
    }

    print(v);

    for (auto p = v.begin(); p != v.end(); ++p)
    {
        if (*p % 2 == 0)
        {
            p = v.insert(p, 0);
            ++p;
        }
        // ++p;
    }
    print(v);

    // for (auto p = v.begin(); p != v.end();)
    // {
    //     if (*p % 2 == 0)
    //     {
    //         p = v.erase(p);
    //     }
    //     else
    //     {
    //         ++p;
    //     }
    // }
    // print(v);

    // the following code is the same, but more efficient

    auto newEnd = remove_if(v.begin(), v.end(), [](int e) { return e % 2 == 0; });

    v.erase(newEnd, v.end());

    print(v);


}

void problem0302()
{
    VecInt v;
    for (int x; cin >> x;)
    {
        v.pushBack(x);
    }

    print(v);

    for (auto p = v.begin(); p != v.end(); ++p)
    {
        if (*p % 2 == 0)
        {
            p = v.insert(p, 0);
            ++p;
        }
        // ++p;
    }
    print(v);

    // for (auto p = v.begin(); p != v.end();)
    // {
    //     if (*p % 2 == 0)
    //     {
    //         p = v.erase(p);
    //     }
    //     else
    //     {
    //         ++p;
    //     }
    // }
    // print(v);

    auto newEnd = remove_if(v.begin(), v.end(), [](int e) { return e % 2 == 0; });

    v.erase(newEnd, v.end());

    print(v);
}

int main()
try
{
    problem0302();

    //  g++ -o main *.cpp
}
catch (...)
{
    cout << "!!!\n";
}