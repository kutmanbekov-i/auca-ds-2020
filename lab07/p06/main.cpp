#include <bits/stdc++.h>
#include "../../libs/utils.hpp"

using namespace std;

struct Student
{
    string mName;
    double mGpa;
    Student(const string &name, double gpa)
    : mName(name), mGpa(gpa)
    {
    }
};

int main()
{
    vector<Student> v;

    string name;
    double gpa;
    for (; cin >> name >> gpa;)
    {
        v.emplace_back(name, gpa);
    }

    auSelection_sort(v.begin(), v.end(), [](const Student &s1, const Student &s2)
    {
        return s1.mName < s2.mName;
    });

    cout << "Sorting lexicographically:\n";
    for (Student s : v)
    {
        cout << s.mName << " " << s.mGpa << endl;
    }

    auSelection_sort(v.begin(), v.end(), [](const Student &s1, const Student &s2)
    {
        return s1.mGpa > s2.mGpa;
    });

    cout << "Sorting by Gpa:\n";
    for (Student s : v)
    {
        cout << s.mName << " " << s.mGpa << endl;
    }

}