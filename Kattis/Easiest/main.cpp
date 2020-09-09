#include <bits/stdc++.h>

using namespace std;

int sum_of_digits(int n);

int main()
{
    int n, sum;
    
    while (cin >> n and n != 0)
    {
        sum = sum_of_digits(n);
        for(int i = 11; i <= 100; i++)
        {
            if (sum == sum_of_digits(n * i)){
                cout << i << endl;
                break;
            }
        }
    }
}

int sum_of_digits(int n)
{
    int r = 0;

    while (n != 0)
    {
        r += n % 10;
        n /= 10;
    }

    return r;
}