#include <bits/stdc++.h>

using namespace std;

bool unique(const vector<int> &a)
{
    int n = a.size();
    for (int i = 1; i < n; ++i)
    {
        if (a[i - 1] == a[i])
            return false;
    }
    return true;
}

int main()
{

    int n, t;
    
    cin >> n >> t;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    switch(t)
    {
        case 1:
        {
            bool b = false;
            for (int i = 0; i < n; ++i)
            {
                if (binary_search(a.begin(), a.end(), 7777 - a[i]))
                {
                    b = true;
                    break;
                }
            }
            cout << (b ? "Yes\n" : "No\n");
            break;
        }
        case 2:
        {
            if (unique(a))
                cout << "Unique";
            else
                cout << "Contains duplicate\n";
            break;
        }
        case 3:
        {
            int r = -1;
            for (int i = 0; i < n / 2; ++i)
            {
                if (a[i] == a[i + n / 2])
                {
                    r = a[i];
                    break;
                }
            }
            cout << r << '\n';
            break;
        }
        case 4:
        {
            if (n % 2 == 1)
            {
                cout << a[n/2] << '\n';
            } else
            {
                cout << a[n/2 - 1] << " " << a[n / 2] << '\n';
            }
            break;
        }
        case 5:
            auto p = lower_bound(a.begin(), a.end(), 100);
            auto q = upper_bound(a.begin(), a.end(), 999);
            bool space = false;
            for (auto it = p; it != q; ++it)
            {
                if (space) cout << ' ';
                space = true;
                cout << *it;
            }
            cout << '\n';
            break;
    }

}