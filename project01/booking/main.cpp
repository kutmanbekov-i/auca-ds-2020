#include <bits/stdc++.h>

using namespace std;

struct Date
{
    int y, m, d, h, mi;
    int type;
};

vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int comparator (const void *a, const void *b)
{
    Date d1 = *(Date*)a, d2 = *(Date*)b;
    
    if (d1.y != d2.y) return d1.y - d2.y;
    if (d1.m != d2.m) return d1.m - d2.m;
    if (d1.d != d2.d) return d1.d - d2.d;
    if (d1.h != d2.h) return d1.h - d2.h;
    if (d1.mi != d2.mi) return d1.mi - d2.mi;
    return d1.type - d2.type;
}

int rooms_needed(vector<Date> &dates, int size)
{
    int c = 0, most = 0;
    for (int i = 0; i < size; i++) {
        c += dates[i].type;
        if (c > most) 
            most = c;
    }
    return most;
}

void next_day(vector<Date> &dates, int i)
{
    // New year
    if (dates[i].d == 31 && dates[i].m == 12) {
        dates[i].y++;
        dates[i].m = 1;
        dates[i].d = 1;
        return;
    }

    // Leap year exception
    if (dates[i].y == 2016 && dates[i].m == 2 && dates[i].d >= 28)
    {
        if (dates[i].d == 28) {
            dates[i].d = 29;
        } else {
            dates[i].d = 1;
            dates[i].m++;
        }
        return;
    }

    // End of month
    if (dates[i].d == days_in_month[dates[i].m - 1]) {
        dates[i].d = 1;
        dates[i].m++;
        return;
    }

    // Any other day
    dates[i].d++;
}

void add_cleaning_time(vector<Date> &dates, int i, int c)
{
    if (!c) return;

    dates[i].mi += c;
    dates[i].h += dates[i].mi / 60;
    dates[i].mi %= 60;

    if (dates[i].h >= 24) {
        dates[i].h %= 24;
        next_day(dates, i);
    }
}

int main()
{
    int t; cin >> t;
    
    while(t--)
    {
        int b, c;
        cin >> b >> c;
        
        vector<Date> dates(b * 2);
        b *= 2;
        for (int i = 0; i < b; i += 2)
        {
            char code[21];
            dates[i].type = 1;
            dates[i + 1].type = -1;
            scanf("%s %d-%d-%d %d:%d %d-%d-%d %d:%d", code, &dates[i].y,&dates[i].m,&dates[i].d,&dates[i].h,&dates[i].mi, &dates[i+1].y,&dates[i+1].m,&dates[i+1].d,&dates[i+1].h,&dates[i+1].mi);
                
            add_cleaning_time(dates, i + 1, c);
        }

        qsort(&dates[0], b, sizeof(Date), comparator);
        
        // for (int i = 0; i < b; i += 2)
        // {
        //     cout << dates[i].y << "-" << dates[i].m << "-" << dates[i].d << " " << dates[i].h << ":" << dates[i].mi << ' ';
        //     cout << dates[i + 1].y << "-" << dates[i + 1].m << "-" << dates[i + 1].d << " " << dates[i + 1].h << ":" << dates[i + 1].mi << '\n';
        // }
        printf("%d\n", rooms_needed(dates, b));
    }
    return 0;
}