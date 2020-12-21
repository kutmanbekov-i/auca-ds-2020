#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> numbers = {3, 20, 100, -5, 4};

    int a[] = {3, 1, 20, 4, 7, 0, 5};
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    cout << "Array test:\n";
    for (int number : numbers)
    {
        auto it = find(begin(a), end(a), number);

        if (it != end(a))
        {
            cout << "Index of element " << number << " is " << it - begin(a) << endl;
        }
        else
        {
            cout << "Not found\n";
        }
    }
    cout << "\nVector test:\n";

    for (int number : numbers)
    {
        auto it = find(begin(v), end(v), number);

        if (it != end(v))
        {
            cout << "Index of element " << number << " is " << it - begin(v) << endl;
        }
        else
        {
            cout << "Not found\n";
        }
    }
}