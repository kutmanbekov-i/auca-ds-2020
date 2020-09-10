#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;

    cin >> n;
    while (n--)
    {
        cin >> s;

        if (s == "P=NP")
            cout << "skipped\n";
        else
        {
            int plus = s.find('+');
            int a = stoi(s.substr(0, plus));
            int b = stoi(s.substr(plus + 1, s.length() - 1));

            cout << a + b << "\n";
        }
    }
    // easy problems but require a lot of time! mfil
}