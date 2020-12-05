#include <bits/stdc++.h>

using namespace std;

void example12()
{
    vector<pair<string, double>> students;

    string name;
    double gpa;

    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }

    sort(students.begin(), students.end());

    for (const auto &s : students)
    {
        cout << get<0>(s) << " " << get<1>(s) << '\n';
    }
}

void example13()
{
    vector<tuple<string, int, double>> employees;

    string name;
    int year;
    double gpa;

    while (cin >> name >> year >> gpa)
    {
        employees.emplace_back(name, year, gpa);
    }

    sort(employees.begin(), employees.end());

    for (const auto &s : employees)
    {
        cout << get<0>(s) << " " << get<1>(s) << " " << get<2>(s) << '\n';
    }
}

void example14()
{
    vector<int> data = {9, 5, -8, 99, 123, 2048, 2042, 1875, 1774, -42};
    sort(data.begin(), data.end());

    for (int x; cin >> x; )
    {
        cout << (binary_search(data.begin(), data.end(), x) ? "yes" : "no") << '\n';
    }
}

void example15()
{
    vector<int> data = {9, 5, -8, 99, 123, 2048, 2042, 1875, 1774, -42};
    sort(data.begin(), data.end());

    for (int x; cin >> x; )
    {
        auto p = lower_bound(data.begin(), data.end(), x);
        
        if (p == data.end())
        {
            cout << "No elements equal or greater than " << x << '\n';
        }
        else if (*p == x)
        {
            cout << "Index of element equal to " << x << " is " << p - data.begin() << '\n';
        }
        else
        {
            cout << "Index of element greater than " << x << " is " << p - data.begin() << '\n';
        }
        
    }
}
void example16()
{
    vector<int> data = {9, 5, -8, -8, -8, 99, 123, 2048, 99, 99, 2042, 1875, 1774, -42};
    sort(data.begin(), data.end());

    for (int x; cin >> x; )
    {
        // pair of pointers
        // useful when finding number of some elements int he vector
        auto p = equal_range(data.begin(), data.end(), x);
        
        cout << "Number of elements equal to " << x << " is " << p.second - p.first << '\n';
    }
}


int main()
{
    example16();
}