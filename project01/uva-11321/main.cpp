#include <bits/stdc++.h>

using namespace std;

bool compare(const int a, const int b);

int m = 1;

int main() {
    
    int n;
    
    while(1)
    {
        cin >> n >> m;
        
        cout << n << " " << m << '\n';
        
        if (n == 0 and m == 0) break;

        vector<int> data(n);
        
        for (int i = 0; i < n; ++i)
            cin >> data[i];
        
        sort(data.begin(), data.end(), compare);
        
        for (int x : data)
            cout << x << '\n';
    }
}

bool compare(const int a, const int b)
{
    if (a % m != b % m)
        return a % m < b % m;
        
    if (a % 2 != 0)
    {
        if(b % 2 != 0)
            return a > b;
        return true;
    }
    if (b % 2 != 0)
        return false;
    return a < b;
}