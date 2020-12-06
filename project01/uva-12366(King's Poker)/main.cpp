#include <bits/stdc++.h>

using namespace std;

class KingPokerHand
{
    friend ostream &operator<<(ostream &out, const KingPokerHand &h);
    friend bool operator==(const KingPokerHand &a, const KingPokerHand &b);
    friend bool operator<(const KingPokerHand &a, const KingPokerHand &b);

    int first;
    int second;
    int third;

    void sort()
    {
        if (second < first) 
            swap(first, second); 

        if (third < second) 
        { 
            swap(second, third); 
            if (second < first) 
                swap(second, first); 
        }
    }
    bool is_set() const
    {
        return first == second and first == third;
    }
    bool is_pair() const
    {
        return !is_set() and (first == second or first == third or second == third);
    }
    bool no_pair()
    {
        return !is_pair();
    }
    int value_of_pair() const
    {
        if (first == second or first == third)
            return first;
        if (second == third)
            return second;
        return first - first;
    }
    int value_of_non_pair() const
    {
        if (first == second)
            return third;
        if (first == third)
            return second;
        if (second == third)
            return first;
        return first - first;
    }
    
    public:

        KingPokerHand(int a, int b, int c)
        : first(a), second(b), third(c)
        {
            sort();
        }
};

ostream &operator<<(ostream &out, const KingPokerHand &h)
{
    return out << h.first << " " << h.second << " " << h.third;
}

bool operator==(const KingPokerHand &a, const KingPokerHand &b)
{
    return (a.first == b.first and a.second == b.second and a.third == b.third);
}

bool operator<(const KingPokerHand &a, const KingPokerHand &b)
{
    if (a.is_set())
    {
        if (b.is_set())
        {
            return a.first < b.first;
        }
        return false;       // if 'a' is a set and 'b' is not a set then a > b (false)
    }
    if (b.is_set())         // if 'a' is not a set and 'b' is a set then a < b (true)
        return true;

    if (a.is_pair())
    {
        if (b.is_pair())
        {
            if (a.value_of_pair() == b.value_of_pair())
            {
                return a.value_of_non_pair() < b.value_of_non_pair();
            }
            return a.value_of_pair() < b.value_of_pair();
        }
        return false;       // if 'a' is a pair and 'b' is not a pair then a > b (false)
    }
    if (b.is_pair())        // if 'a' is not a pair and 'b' is a pair then a < b (true)
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    vector<KingPokerHand> hands;

    for (int i = 0; i < 52; ++i)
        for (int j = i + 1; j < 52; ++j)
            for (int k = j + 1; k < 52; ++k)
            {
                int r1 = i % 13;
                int r2 = j % 13;
                int r3 = k % 13;
                if (r1 == r2 or r1 == r3 or r2 == r3)
                    hands.emplace_back(r1 + 1, r2 + 1, r3 + 1);
            }

    sort(hands.begin(), hands.end());

    for (int a, b, c; cin >> a >> b >> c and a + b + c > 0; )
    {
        KingPokerHand h(a, b, c);

        if (!binary_search(hands.begin(), hands.end(), h))
        {
            cout << hands.front() << '\n';
        }
        else if (h == hands.back())
        {
            cout << "*\n";
        }
        else
        {
            cout << *upper_bound(hands.begin(), hands.end(), h) << '\n';
        }
    }
}