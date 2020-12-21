#include <bits/stdc++.h>

using namespace std;

int main()
{
    string name;
    double gpa;
    vector<pair<string, double>> v;

    for (; cin >> name >> gpa;)
    {
        v.emplace_back(name, gpa);
    }

    cout << "Lexicographical sort:\n";
    sort(v.begin(), v.end(), [](const pair<string, double> &p1, const pair<string, double> &p2)
    {
        return p1.first < get<0>(p2);       // the same
    });

    for (auto p : v)
    {
        cout << p.first << " " << p.second << endl;
    }

    cout << "Sort by Gpa:\n";
    sort(v.begin(), v.end(), [](const pair<string, double> &p1, const pair<string, double> &p2)
    {
        return p1.second > get<1>(p2);       // the same
    });

    for (auto p : v)
    {
        cout << p.first << " " << p.second << endl;
    }

}