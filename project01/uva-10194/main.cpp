#include <bits/stdc++.h>

using namespace std;

struct Team
{
    string name;
    int games_played;
    int points;
    int wins;
    int draws;
    int loses;
    int goals_scored;
    int goals_conceded;
};

bool compare(Team a, Team b)
{
    if (a.points != b.points)
        return a.points > b.points;
    if (a.wins != b.wins)
        return a.wins > b.wins;
    if (a.goals_scored - a.goals_conceded != b.goals_scored - b.goals_conceded)
        return a.goals_scored - a.goals_conceded > b.goals_scored - b.goals_conceded;
    if (a.games_played != b.games_played)
        return a.games_played < b.games_played;
    return a.name < b.name;
}

void result(const string &game_result, vector<Team> &teams)
{
    auto it = find(game_result.begin(), game_result.end(), '@');
    int ind = it - game_result.begin();
    
    string team_a = game_result.substr(0, ind - 2);
    string team_b = game_result.substr(ind + 3);
    
    int a_scored = game_result[ind - 1] - '0';
    int b_scored = game_result[ind + 1] - '0';
    
    int winner = (a_scored > b_scored ? 1 : (a_scored < b_scored ? 2 : 0));
    
    for (size_t i = 0; i < teams.size(); ++i)
    {
        if (teams[i].name == team_a)
        {
            teams[i].games_played++;
            teams[i].points += (winner == 1 ? 3 : (winner == 0 ? 1 : 0));
            teams[i].wins += (winner == 1 ? 1 : 0);
            teams[i].draws += (winner == 0 ? 1 : 0);
            teams[i].loses += (winner == 2 ? 1 : 0);
            teams[i].goals_scored += a_scored;
            teams[i].goals_conceded += b_scored;
        }
        else if (teams[i].name == team_b)
        {
            teams[i].games_played++;
            teams[i].points += (winner == 2 ? 3 : (winner == 0 ? 1 : 0));
            teams[i].wins += (winner == 2 ? 1 : 0);
            teams[i].draws += (winner == 0 ? 1 : 0);
            teams[i].loses += (winner == 1 ? 1 : 0);
            teams[i].goals_scored += b_scored;
            teams[i].goals_conceded += a_scored;
        }
    }
}

int main()
{

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    string s;
    getline(cin, s);
    
    int N = stoi(s);
    
    bool line = false;
    
    while (N--)
    {
        if (line) cout << '\n';
        line = true;
        
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
        }
        
        int g;
        cin >> g;
        
        string game_result;
        getline(cin, game_result);
        
        for (int i = 0; i < g; ++i)
        {
            getline(cin, game_result);
            
            result(game_result, teams);
        }
        
        sort(teams.begin(), teams.end(), compare);
        
        cout << tournament << '\n';
        for (int i = 0; i < n; ++i)
        {
            cout << i + 1 << ") " << teams[i].name << " ";      // printf is not type safe when using strings
            printf("%dp, %dg (%d-%d-%d), %dg (%d-%d)\n", teams[i].points, teams[i].games_played, teams[i].wins, teams[i].draws, teams[i].loses, teams[i].goals_scored - teams[i].goals_conceded, teams[i].goals_scored, teams[i].goals_conceded);
        }
    }
}