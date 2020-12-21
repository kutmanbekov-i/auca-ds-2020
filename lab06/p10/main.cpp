#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> v = {0, 4, 5, 10, 12, 20, 25, 40};

    for (int x; cin >> x;)
    {
        auto it = binary_search(v.begin(), v.end(), x);

        if (it)
        {
            cout << "Number " << x << " is found in the vector" << endl;
        }
        else
        {
            cout << "Not found\n";
        }
        
    }

}