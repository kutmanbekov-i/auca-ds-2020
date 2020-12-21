#include <bits/stdc++.h>

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
        {"StudentB", 4.0}, 
        {"StudentC", 4.0}, 
        {"StudentC", 4.0}, 
        {"StudentD", 4.0}, 
        {"StudentE", 4.0}, 
        {"StudentF", 4.0}, 
        {"StudentG", 4.0}, 
        {"StudentA", 4.0}, 
    };

    sort(v.begin(), v.end(), [](const Student &s1, const Student &s2)
    {
        return s1.mName < s2.mName;
    });

    cout << "Sorting lexicographically:\n";
    for (Student s : v)
    {
        cout << s.mName << " " << s.mGpa << endl;
    }

    sort(v.begin(), v.end(), [](const Student &s1, const Student &s2)
    {
        return s1.mGpa > s2.mGpa;
    });

    cout << "Sorting by Gpa:\n";
    for (Student s : v)
    {
        cout << s.mName << " " << s.mGpa << endl;
    }


    cout << "============================================\n";

    stable_sort(v.begin(), v.end(), [](const Student &s1, const Student &s2)
    {
        return s1.mName < s2.mName;
    });

    cout << "Stable sorting lexicographically:\n";
    for (Student s : v)
    {
        cout << s.mName << " " << s.mGpa << endl;
    }

    stable_sort(v.begin(), v.end(), [](const Student &s1, const Student &s2)
    {
        return s1.mGpa > s2.mGpa;
    });

    cout << "Stable sorting by Gpa:\n";
    for (Student s : v)
    {
        cout << s.mName << " " << s.mGpa << endl;
    }
}