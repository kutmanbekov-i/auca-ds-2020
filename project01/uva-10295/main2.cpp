#include <bits/stdc++.h>

using namespace std;

struct Skill
{
    string name;
    int points;
    Skill(const string &n, int p) : name(n), points(p)
    {
    }
};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n;
    
    cin >> m >> n;
    vector<Skill> skills;
    
    for (int i = 0; i < m; ++i)
    {
        string s; int p;
        cin >> s >> p;

        skills.emplace_back(s, p);
    }
    sort(skills.begin(), skills.end(), [](const Skill &s1, const Skill &s2){
        return s1.name < s2.name;
    });
    for (int i = 0; i < n; ++i)
    {
        int points = 0;
        for (string s; cin >> s and s != ".";)
        {
            auto p = lower_bound(skills.begin(), skills.end(), Skill(s, 0), [](const Skill &s1, const Skill &s2){
                return s1.name < s2.name;
            });

            if (p != skills.end() and p->name == s)
            {
                points += p->points;
            }
        }
        cout << points << '\n';
    }
}