#include <bits/stdc++.h>

using namespace std;

enum class Event
{
    Departure,
    Arrival,
};

int main() {
    
    int t; cin >> t;
    
    for (int i = 0; i < t; ++i)
    {
        int b, c;
        cin >> b >> c;
        
        vector<pair<string, string>> data;
        
        for (int j = 0; j < b; ++j)
        {
            string code, date1, time1, date2, time2;
            
            cin >> code >> date1 >> time1 >> date2 >> time2;
            
            
            
            data.emplace_back(date1 + " " + time1, date2 + " " + time2);
        }
        
        sort(data.begin(), data.end());
        
        int cnt = b;
        
        for (int j = 1; j < b; ++j)
        {
            bool leap = false;
            
            int year0 = stoi(data[j - 1].second.substr(0, 4));
            int month0 = stoi( data[j - 1].second.substr(5, 7));
            int day0 = stoi(data[j - 1].second.substr(8, 10));
            int hour0 = stoi(data[j - 1].second.substr(11, 13));
            int minute0 = stoi(data[j - 1].second.substr(14));
            
            int year1 = stoi(data[j].first.substr(0, 4)) - year0;
            int month1 = stoi( data[j].first.substr(5, 7)) - month0;
            int day1 = stoi(data[j].first.substr(8, 10))- day0;
            int hour1 = stoi(data[j].first.substr(11, 13)) - hour0;
            int minute1 = stoi(data[j].first.substr(14)) - minute0;
            
            double m = ( year1 * 365.25 * 24 * 60 ) + (month1 * 30.4375 * 24 * 60) + (day1 * 24 * 60) + (hour1 * 60) + minute1;
            // cout << m << endl;
            if (m - c >= 0)
                cnt--;
            
            // cout << data[j].first << " " << data[j].second << endl;
        }
        cout << cnt << endl;
    }
}