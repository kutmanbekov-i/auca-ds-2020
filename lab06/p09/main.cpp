#include <bits/stdc++.h>

using namespace std;

int main()
{
    string name;
    int age;
    double salary;
    vector<tuple<string, int, double>> employees;

    for (; cin >> name >> age >> salary;)
    {
        employees.emplace_back(name, age, salary);
    }

    cout << "Sort by age:\n";
    sort(employees.begin(), employees.end(), [](auto &e1, auto &e2)
    {
        return get<1>(e1) > get<1>(e2);
    });

    for (auto p : employees)
    {
        cout << get<0>(p) << " " << get<1>(p) << " " << get<2>(p) << endl;
    }

}