#include <bits/stdc++.h>

using namespace std;

enum class Event
{
    Departure,
    Arrival,
};

struct Date
{
    int y;
    int m;
    int d;
    
};

const vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int compare(const string &departure, const string &arrival)
{
    if (departure > arrival)
    {
        return -1;
    }
    
    return 1;
}

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
        
        sort(data.begin(), data.end(), [](const pair<string, string> &a, const pair<string, string> &b)
        {
            return a.first < b.first;
        });
        
        int cnt = b;
        
        for (int j = 0; j < b; ++j)
        {
            int year0 = stoi(data[j].second.substr(0, 4));
            int month0 = stoi( data[j].second.substr(5, 7));
            int day0 = stoi(data[j].second.substr(8, 10));
            int hour0 = stoi(data[j].second.substr(11, 13));
            int minute0 = stoi(data[j].second.substr(14));
            
            minute0 += c;
            if (minute0 >= 60)
            {
                hour0 += minute0 / 60;
                minute0 %= 60;
            }

            if (hour0 >= 24)
            {
                day0 += hour0 / 24;
                hour0 %= 24;
            }
            
            if (year0 == 2016)
            {
                if (month0 == 2 and day0 > monthDays[month0 - 1] + 1)
                {
                    // cout << "Hello, bug is hereeeeeeeeeeeeeee: " << month0 << " " << day0 << '\n';
                    month0 += day0 / (monthDays[month0 - 1] + 1);
                    day0 %= (monthDays[(month0 - 2) % 12] + 1);
                }
                else if (month0 != 2 and day0 > monthDays[month0 - 1])
                {
                    // cout << "Hello, bug is here: " << month0 << " " << day0 << '\n';
                    month0 += day0 / monthDays[month0 - 1];
                    day0 %= monthDays[(month0 - 2) % 12];
                }
            }
            else
            {
               if (day0 > monthDays[month0 - 1])
                {
                    month0 += day0 / monthDays[month0 - 1];
                    day0 %= monthDays[(month0 - 2) % 12];
                    // cout << "H3llo, bug is here\n" << month0 << " " << day0 << '\n';
                } 
            }

            if (month0 > 12)
            {
                year0 += month0 / 12;
                month0 %= 12;
            }
            
            string new_year = to_string(year0);
            string new_month = (month0 < 10) ? "0" + to_string(month0) : to_string(month0);
            string new_day = (day0 < 10) ? "0" + to_string(day0) : to_string(day0);
            string new_hour = (hour0 < 10) ? "0" + to_string(hour0) : to_string(hour0);
            string new_minute = (minute0 < 10) ? "0" + to_string(minute0) : to_string(minute0);
            
            data[j].second = new_year + "-" + new_month + "-" + new_day + " " + new_hour + ":" + new_minute;
            
            if (j)
            {
                int num = compare(data[j - 1].second, data[j].first);
                if (num > 0)
                {
                    --cnt;
                }
            }
        }
        // cout << "========================================\n";
        // for (const auto &p : data)
        // {
        //     cout << p.first << " " << p.second << endl;
        // }
        cout << cnt << endl;
    }
}