#include <bits/stdc++.h>

using namespace std;

int main()
{
    // g++ main.cpp
    // main < input.txt
    cout << setfill('.') << fixed << setprecision(2);

    string student_name;
    while (cin >> student_name)
    {
        int grade;
        int cnt = 0;
        double sum = 0;
        while (cin >> grade)
        {
            sum += grade;
            ++cnt;
        }

        cout << left << setw(25) << student_name << "|" << right << setw(40);
        
        if (cnt > 0) 
            cout << sum / cnt << "\n";
        else
            cout << "no data\n";
        

        if (cin.fail())
            cin.clear();
    }
}