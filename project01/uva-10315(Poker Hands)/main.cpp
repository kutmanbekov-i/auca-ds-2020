#include <bits/stdc++.h>

using namespace std;

class PokerHand
{
    // const int SIZE = 5;
    vector<pair<int, char>> hand;
    vector<int> count;

    void parse(const vector<string> &cards)
    {
        for (int i = 0; i < 5; ++i)
        {
            if (isdigit(cards[i][0]))
            {
                hand.emplace_back(cards[i][0] - '0', cards[i][1]);
            }
            else
            {
                int value = 14;
                char suit = cards[i][1];

                if (cards[i][0] == 'T')
                    value = 10;
                else if (cards[i][0] == 'J')
                    value = 11;
                else if (cards[i][0] == 'Q')
                    value = 12;
                else if (cards[i][0] == 'K')
                    value = 13;

                hand.emplace_back(value, suit);
            }
        }
    }
    void count_cards()
    {
        for (int i = 0; i < 5; ++i)
            count[hand[i].first]++;
            
    }
    bool is_straight_flush() const
    {
        return is_straight() and is_flush();
    }
    bool is_four_of_a_kind() const
    {
        for (int v = 2; v < 15; ++v)
            if (count[v] == 4)
                return true;
        return false;
    }
    bool is_full_house() const
    {
        if (hand[0].first == hand[1].first)
        {
            if (hand[1].first != hand[2].first)
            {
                if (hand[2].first == hand[3].first and hand[3].first == hand[4].first)
                    return true;
                return false;
            }
            if (hand[2].first != hand[3].first and hand[3].first == hand[4].first)
                return true;
        }
        return false;
    }
    bool is_flush() const
    {
        for (int i = 1; i < 5; ++i)
            if (hand[i].second != hand[i - 1].second)
                return false;
        return true;
    }
    bool is_straight() const
    {
        for (int i = 1; i < 5; ++i)
            if (hand[i].first != hand[i - 1].first - 1)
                return false;
        return true;
    }
    bool is_three_of_a_kind() const
    {
        if (!is_four_of_a_kind())
            for (int v = 2; v < 15; ++v)
                if (count[v] == 3)
                    return true;
        return false;
    }
    bool is_two_pairs() const
    {
        if (is_pair())
        {
            int cnt = 0;
            for (int v = 2; v < 15; ++v)
                if (count[v] == 2)
                    ++cnt;
            return cnt == 2;
        }
        return false;
    }
    bool is_pair() const
    {
        if (!is_three_of_a_kind())
            for (int v = 2; v < 15; ++v)
                if (count[v] == 2)
                    return true;
        return false;
    }
    int value_of_pair() const
    {
        if (is_pair())
            for (int v = 2; v < 15; ++v)
                if (count[v] == 2)
                    return v;
        return 0;
    }
    int value_of_non_pair() const
    {
        if (is_two_pairs())
            for (int v = 2; v < 15; ++v)
                if (count[v] == 1)
                    return v;
        return 0;
    }
    vector<int> kickers() const
    {
        vector<int> temp;
        if (is_pair())
            for (int v = 14; v >= 2; --v)
                if (count[v] == 1)
                    temp.push_back(v);
        return temp;
    }

public:
    PokerHand(vector<string> cards)
        : count(15, 0)
    {
        parse(cards);
        sort(hand.begin(), hand.end(), [](pair<int, char> &a, pair<int, char> &b) {
            return a.first > b.first;
        });
        count_cards();
    }
    static int compare(const PokerHand &a, const PokerHand &b)
    {
        if (a.is_straight_flush())
        {
            // cout << " WAAAT ";
            if (b.is_straight_flush())
            {
                if (a.hand[0].first > b.hand[0].first) return 1;
                if (a.hand[0].first < b.hand[0].first) return -1;
                return 0;
            }
            return 1;
        }
        if (b.is_straight_flush())
        {
            return -1;
        }
        // cout << "comparison skipped... ";

        if (a.is_four_of_a_kind())
        {
            if (b.is_four_of_a_kind())
            {
                if (a.hand[2].first > b.hand[2].first) return 1;
                return -1;
            }
            return 1;
        }
        if (b.is_four_of_a_kind())
            return -1;

        if (a.is_full_house())
        {
            if (b.is_full_house())
            {
                if (a.hand[2].first > b.hand[2].first) return 1;
                return -1;
            }
            return 1;
        }
        if (b.is_full_house())
            return -1;

        if (a.is_flush())
        {
            if (b.is_flush())
            {
                for (int i = 0; i < 5; ++i)
                {
                    if (a.hand[i].first > b.hand[i].first) return 1;
                    if (a.hand[i].first < b.hand[i].first) return -1;
                }
                return 0;
            }
            return 1;
        }
        if (b.is_flush()) return -1;

        if (a.is_straight())
        {
            if (b.is_straight())
            {
                if (a.hand[0].first > b.hand[0].first) return 1;
                return -1;
            }
            return 1;
        }
        if (b.is_straight()) return -1;

        if (a.is_three_of_a_kind())
        {
            if (b.is_three_of_a_kind())
            {
                if (a.hand[2].first > b.hand[2].first) return 1;
                return -1;
            }
            return 1;
        }
        if (b.is_three_of_a_kind())
            return -1;

        if (a.is_two_pairs())
        {
            if (b.is_two_pairs())
            {
                if (a.hand[1].first > b.hand[1].first) return 1;
                if (a.hand[1].first < b.hand[1].first) return -1;
                if (a.hand[1].first == b.hand[1].first)
                {
                    if (a.hand[3].first > b.hand[3].first) return 1;
                    if (a.hand[3].first < b.hand[3].first) return -1;
                    if (a.hand[3].first == b.hand[3].first)
                    {
                        if (a.value_of_non_pair() > b.value_of_non_pair()) return 1;
                        if (a.value_of_non_pair() < b.value_of_non_pair()) return -1;
                        return 0;
                    }
                }
            }
            return 1;
        }
        if (b.is_two_pairs()) return -1;

        if (a.is_pair())
        {
            if (b.is_pair())
            {
                if (a.value_of_pair() > b.value_of_pair()) return 1;
                if (a.value_of_pair() < b.value_of_pair()) return -1;
                if (a.value_of_pair() == b.value_of_pair())
                {
                    for (int i = 0; i < 3; ++i)
                    {
                        if (a.kickers()[i] > b.kickers()[i]) return 1;
                        if (a.kickers()[i] < b.kickers()[i]) return -1;
                    }
                }
                return 0;
            }
            return 1;
        }
        if (b.is_pair()) return -1;

        // checking for a highcard
        for (int i = 0; i < 5; ++i)
        {
            if (a.hand[i].first > b.hand[i].first) return 1;
            if (a.hand[i].first < b.hand[i].first) return -1;
        }
        return 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    for (string line; getline(cin, line);)
    {
        if (line == "") break;
        istringstream sinp(line);

        vector<string> white;
        vector<string> black;

        for (int i = 0; i < 10; ++i)
        {
            string card;
            sinp >> card;

            if (i >= 5)
            {
                white.emplace_back(card);
            }
            else
            {
                black.emplace_back(card);
            }
        }
        PokerHand w(white);
        PokerHand b(black);

        switch (PokerHand::compare(w, b))
        {
        case 1:
            cout << "White wins.\n";
            break;
        case 0:
            cout << "Tie.\n";
            break;
        case -1:
            cout << "Black wins.\n";
            break;
        }
    }
}