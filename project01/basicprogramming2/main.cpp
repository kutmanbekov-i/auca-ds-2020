#include <bits/stdc++.h>

using namespace std;

bool check_sum(const vector<int> &a, const int number = 7777)
{
    int n = a.size();
    
    if (a[n - 1] + a[n - 2] < number) return false;
    
    for (int i = 0; i < n; ++i)
    {
        int l = i, r = n - 1, x = number - a[i];
        while (l < r)
        {
            if (a[l] + a[r] == number)
                return true;
            int m = (l + r)/2;
            
            if (x > a[m])
                l = m + 1;
            else
                r = m;
        }
        if (x == a[l]) return true;
    }
    return false;
}
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
            if (check_sum(a, 7777))
                cout << "Yes\n";
            else
                cout << "No\n";
            break;
        case 2:
            if (unique(a))
                cout << "Unique";
            else
                cout << "Contains duplicate\n";
            break;
        case 3:
        {
            int maxim = 0, n = a.size();
            int cnt = 1, x = 0;
            
            for (int i = 0; i < n - 1; ++i)
            {
                if (a[i] != a[i + 1])
                {
                    maxim = max(maxim, cnt);
                    x = a[i];
                    cnt = 1;
                }
                ++cnt;
            }
            if (maxim > n/2)
            {
                cout << x << '\n';
            } else
            {
                cout << "-1\n";
            }
            break;
        }
        case 4:
            if (n % 2 == 1)
            {
                cout << a[n/2] << '\n';
            } else
            {
                cout << a[n/2 - 1] << " " << a[n / 2] << '\n';
            }
            break;
        case 5:
            bool b = false;
            for (int i = 0; i < n; ++i)
            {
                if (a[i] > 999) b = false;
                if (b) cout << " ";
                if (a[i] >= 100 and a[i] <= 999)
                {
                    cout << a[i];
                    b = true;
                }
            }
            break;
    }
    // спать хочу, максимально много костылей в коде
}