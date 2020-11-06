#include <bits/stdc++.h>

using namespace std;

void eliminate(vector<vector<int>> &votes, int ind, int n)
{
    for (int i = 0; i < votes.size(); i++)
        for (int j = 0; j < n; j++)
            if (votes[i][j] == ind + 1)
                votes[i][j] = 0;

}
void rearrange(vector<vector<int>> &votes, int n)
{
    for (int i = 0; i < votes.size(); i++)
        if (votes[i][0] == 0)
            for (int j = 1; j < n; j++)
                if (votes[i][j] != 0)
                {
                    votes[i][0] = votes[i][j];
                    break;
                }
}

int main()
{
    int t;
    cin >> t;
    bool new_line = false;

    while (t--)
    {

        int n, voters = 0;
        cin >> n;
        string s;
        vector<string> candidates(n);
        vector<vector<int>> votes(1000, vector<int>(20, 0));

        // if (!new_line)
        // {
        getline(cin, s);
        // }

        for (int i = 0; i < n; ++i)
        {
            getline(cin, s);
            candidates[i] = s;
        }

        string line;

        while (getline(cin, line) and line != "")
        {
            istringstream sinp(line);
            for (int i = 0; i < n; i++)
            {
                sinp >> votes[voters][i];
            }
            voters++;
        }

        vector<bool> kicked(n, false);

        while (true)
        {
            vector<int> points(n, 0);

            for (int i = 0; i < voters; ++i)
            {
                points[ votes[i][0] - 1 ]++;
            }

            int half = voters / 2;
            int maxim = -1, minim = INT_MAX;

            for (int i = 0; i < n; ++i)
            {
                if (!kicked[i])
                {
                    maxim = max(maxim, points[i]);
                    minim = min(minim, points[i]);
                }
            }

            if (maxim > half or maxim == minim)
            {
                for (int i = 0; i < n; ++i)
                    if (points[i] == maxim)
                        cout << candidates[i] << '\n';
                break;
            } else
            {
                for (int i = 0; i < n; ++i)
                {
                    if (points[i] == minim)
                    {
                        eliminate(votes, i, n);
                        
                        kicked[i] = true;
                    }
                }
                rearrange(votes, n);
            }
        }

        if (t)
            cout << "\n";
    }
}