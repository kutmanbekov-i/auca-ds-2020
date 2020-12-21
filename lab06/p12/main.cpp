#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> data = {0, 0, 4, 5, 10, 10, 10, 12, 20, 25, 25, 25, 25, 40};

    for (int x; cin >> x; )
    {
        // pair of pointers
        // useful when finding number of some elements int he vector
        // in the sorted vector, of course
        auto p = equal_range(data.begin(), data.end(), x);
        
        cout << "Number of elements equal to " << x << " is " << p.second - p.first << '\n';
    }
}