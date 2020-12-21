#include <iostream>
#include "VecInt.hpp"
#include "../libs/utils.hpp"

using namespace std;

void printVector(VecInt &v)
{
    for (int e : v)
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

    printVector(v);

    auReverse(v.begin(), v.end());

    printVector(v);
}

void problem0102()
{
    VecInt v;

    int x;
    while (cin >> x)
    {
        v.pushBack(x);
    }
    printVector(v);

    auReverse(v.begin(), v.end());

    printVector(v);
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

    printVector(a);
    printVector(b);
}

int main()
try
{
    problem0202();

    //  g++ -o main *.cpp
}
catch (...)
{
    cout << "!!!\n";
}