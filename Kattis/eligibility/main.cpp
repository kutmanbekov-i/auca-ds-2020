#include <bits/stdc++.h>

using namespace std;

int main()
{
    string name, date_study, birth, status = "";
    int courses, n;

    cin >> n;
    while (n--)
    {
        cin >> name >> date_study >> birth >> courses;

        int year_study = stoi(date_study.substr(0, 4));
        int year_birth = stoi(birth.substr(0, 4));
        if ( year_study >= 2010 )
            status = "eligible";
        else if ( year_birth >= 1991 )
            status = "eligible";
        else if ( courses > 40 )
            status = "ineligible";
        else
            status = "coach petitions";
        
        cout << name << " " << status << "\n";
    }
}