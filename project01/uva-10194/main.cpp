#include <bits/stdc++.h>

using namespace std;

struct Team
{
    string name;
    string name_ignoreCase;
    int games_played;
    int points;
    int wins;
    int draws;
    int loses;
    int goals_scored;
    int goals_conceded;
    int difference;
    
    Team(): games_played(0), points(0), wins(0), draws(0), loses(0), goals_scored(0), goals_conceded(0), difference(0) {}
};

bool compare(Team a, Team b)
{
    if (a.points != b.points)
        return a.points > b.points;
    if (a.wins != b.wins)
        return a.wins > b.wins;
    if (a.difference != b.difference)
        return a.difference > b.difference;
    if (a.goals_scored != b.goals_scored)
        return a.goals_scored > b.goals_scored;
    if (a.games_played != b.games_played)
        return a.games_played < b.games_played;
    return a.name_ignoreCase < b.name_ignoreCase;
}

void update_results(vector<Team> &teams, const string &team_name, const int a, const int b)
{
    int ind;
    for (size_t i = 0; i < teams.size(); ++i)
        if (teams[i].name == team_name)
            ind = i;
    
    teams[ind].games_played++;
    teams[ind].points += (a > b ? 3 : (a == b ? 1 : 0));
    teams[ind].wins += (a > b ? 1 : 0);
    teams[ind].draws += (a == b ? 1 : 0);
    teams[ind].loses += (a < b ? 1 : 0);
    teams[ind].goals_scored += a;
    teams[ind].goals_conceded += b;
    teams[ind].difference += (a - b);

}

int main()
{

    string s;
    getline(cin, s);

    int N = stoi(s);

    while (N--)
    {
        string tournament;
        getline(cin, tournament);

        int n;
        cin >> n;

        vector<Team> teams(n);

        string team;
        getline(cin, team);

        for (int i = 0; i < n; ++i)
        {
            getline(cin, team);
            teams[i].name = team;

            transform(team.begin(), team.end(), team.begin(), ::toupper);
            teams[i].name_ignoreCase = team;
        }

        int g;
        cin >> g;

        string team_a, team_b;
        int a, b;
        
        getline(cin, team_a);

        for (int i = 0; i < g; ++i)
        {
            getline(cin, team_a, '#');
            cin >> a;
            cin.ignore(10, '@');
            
            cin >> b;
            cin.ignore(10, '#');
            
            getline(cin, team_b);
            

            update_results(teams, team_a, a, b);
            update_results(teams, team_b, b, a);
        }

        sort(teams.begin(), teams.end(), compare);

        cout << tournament << '\n';
        for (int i = 0; i < n; ++i)
        {
            cout << i + 1 << ") " << teams[i].name << " " << teams[i].points << "p, " << teams[i].games_played << "g (" << teams[i].wins << "-" << teams[i].draws << "-" << teams[i].loses << "), " << teams[i].difference << "gd (" << teams[i].goals_scored << "-" << teams[i].goals_conceded << ")\n";
        }
        if (N)
            cout << '\n';
    }
}