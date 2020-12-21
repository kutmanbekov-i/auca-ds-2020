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
    vector<Student> v = {
        {"StudentA", 4.0}, 
        {"StudentA", 4.0}, 
        {"StudentB", 3.9}, 
        {"StudentB", 2.0}, 
        {"StudentC", 4.0}, 
        {"StudentC", 4.0}, 
        {"StudentD", 4.0}, 
        {"StudentE", 4.0}, 
        {"StudentF", 4.0}, 
        {"StudentG", 4.0}, 
        {"StudentA", 4.0}, 
    };

    auSelection_sort(v.begin(), v.end(), [](const Student &s1, const Student &s2)
    {
        return s1.mName < s2.mName;
    });

    cout << "Selection Sorting lexicographically:\n";
    for (const Student &s : v)
    {
        cout << s.mName << " " << s.mGpa << endl;
    }

    auSelection_sort(v.begin(), v.end(), [](const Student &s1, const Student &s2)
    {
        return s1.mGpa > s2.mGpa;
    });

    cout << "Selection Sorting by Gpa:\n";
    for (const Student &s : v)
    {
        cout << s.mName << " " << s.mGpa << endl;
    }


    cout << "============================================\n";

    auInsertion_sort(v.begin(), v.end(), [](const Student &s1, const Student &s2)
    {
        return s1.mName < s2.mName;
    });

    cout << "Stable version of Insertion sorting lexicographically:\n";
    for (const Student &s : v)
    {
        cout << s.mName << " " << s.mGpa << endl;
    }

    auInsertion_sort(v.begin(), v.end(), [](const Student &s1, const Student &s2)
    {
        return s1.mGpa > s2.mGpa;
    });

    cout << "Stable version of Insertion sorting by Gpa:\n";
    for (const Student &s : v)
    {
        cout << s.mName << " " << s.mGpa << endl;
    }
}