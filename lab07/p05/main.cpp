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

    auto it = auMin_element(v.begin(), v.end(), [](const Student &s1, const Student &s2)
    {
        return s1.mGpa < s2.mGpa;
    });

    if (it != v.end())
    {
        cout << "Index of Student with minimum gpa is " << it - v.begin() << endl;
    }
    else
    {
        cout << "not found\n";
    }

    it = auMin_element(v.begin(), v.end(), [](const Student &s1, const Student &s2)
    {
        return s1.mName < s2.mName;
    });

    if (it != v.end())
    {
        cout << "Index of Student with minimum name (lexicographically) is " << it - v.begin() << endl;
    }
    else
    {
        cout << "not found\n";
    }

}