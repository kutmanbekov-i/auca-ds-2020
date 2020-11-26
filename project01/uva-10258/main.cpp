#include <bits/stdc++.h>

using namespace std;

struct Submission
{
    int contestant;
    int problem;
    int timer;
    string verdict;
};

struct User
{
    int num;
    int solved;
    int submissions;
    int penalty;
    vector<bool> solved_problems = vector<bool>(10, false);
    vector<int> problem_penalties = vector<int>(10, 0);
    
    User() : num(0), solved(0), submissions(0), penalty(0) {}
};

bool compare(User a, User b)
{
    if (a.solved != b.solved)
    {
        return a.solved > b.solved;
    }
    if (a.penalty != b.penalty)
    {
        return a.penalty < b.penalty;
    }
    return a.num < b.num;
}

void update_user(User &user, Submission &sub)
{
    user.num = sub.contestant;
    user.submissions++;
    
    if (sub.verdict == "C")
    {
        if (!(user.solved_problems[sub.problem - 1]))
        {
            user.solved++;
            user.solved_problems[sub.problem - 1] = true;
            
            user.penalty += user.problem_penalties[sub.problem - 1] + sub.timer;
        }
    }
    else if (sub.verdict == "I")
    {
        if ( !(user.solved_problems[sub.problem - 1]) )
        {
            user.problem_penalties[sub.problem - 1] += 20;
        }
    }
}

int main()
{

    string s;
    getline(cin, s);

    int N = stoi(s);
    
    bool first = true;

    while (N--)
    {
        vector<User> users;
        vector<int> contestants;
        
        string s;
        if (first)
            getline(cin, s);
        first = false;
        
        int n = 0;

        while (getline(cin, s) and s != "")
        {
            istringstream sinp(s);
            Submission sub;
            
            sinp >> sub.contestant >> sub.problem >> sub.timer >> sub.verdict;
            
            auto it = find(contestants.begin(), contestants.end(), sub.contestant);
            if (it == contestants.end())
            {
                contestants.push_back(sub.contestant);
                
                User user;
                update_user(user, sub);
                    
                users.push_back(user);
                ++n;
            }
            else {
                
                int ind = it - contestants.begin();
                // cout << contestants.size() << " ";
                update_user(users[ind], sub);
            }

        }
        sort(users.begin(), users.end(), compare);

        for (int i = 0; i < n; ++i)
        {
            cout << users[i].num << " " << users[i].solved << " " << users[i].penalty << '\n';
        }
        if (N)
            cout << '\n';
    }
    
}