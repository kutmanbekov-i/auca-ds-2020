#include <bits/stdc++.h>

using namespace std;

struct Pair
{
    int ascii;
    int value;
};

bool compare(Pair a, Pair b)
{
    if (a.value == b.value)
    {
        return a.ascii > b.ascii;
    }
    return a.value < b.value;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (string s; getline(cin, s);)
    {
        vector<int> freq(96);
        for(int i = 0; i < s.length(); ++i)
        {
            freq[s[i] - ' ']++;         // possible range of the characters in the input string
        }                               // by the task statement is between 32 and 128 by the ascii
                                        // ' ' is the 32-th char in the ascii table
        int cnt = 0;
        for (int i = 0; i < 96; ++i)
        {
            if (freq[i] > 0)
            {
                ++cnt;
            }
        }
        
        vector<Pair> data(cnt);
        int ind = 0;
        
        for (int i = 0; i < 96; ++i)
        {
            if (freq[i] > 0)
            {
                data[ind].ascii = int(i + ' ');     //haha, genius, придумал за 5 сек
                data[ind].value = freq[i];
                ++ind;
            }
        }
        sort(data.begin(), data.end(), compare);
        
        for (Pair p : data)
        {
            cout << p.ascii << " " << p.value << '\n';
        }
        cout << '\n';
    }
}