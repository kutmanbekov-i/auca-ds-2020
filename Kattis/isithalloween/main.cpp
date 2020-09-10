#include <bits/stdc++.h>

using namespace std;

int main()
{
    string m;
    int d;

    cin >> m >> d;

    if ((m == "OCT" and d == 31) or (m == "DEC" and d == 25)) {
        cout << "yup\n";
    } else {
        cout << "nope\n";
    } 
}