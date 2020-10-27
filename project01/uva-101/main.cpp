#include <bits/stdc++.h>

using namespace std;

template <typename C>
int sz(const C &c) { return c.size(); }

class BlockWorld
{
    friend ostream &operator<<(ostream &out, const BlockWorld &w);

    vector<vector<int>> piles;

    int size;

    void find_block(int a, int &ia, int &ja)
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < sz(piles[i]); ++j)
            {
                if (piles[i][j] == a)
                {
                    ia = i;
                    ja = j;
                    return;
                }
            }
        }
    }

public:

    BlockWorld(int n) : piles(n)
    {
        size = n;

        for (int i = 0; i < size; ++i)
        {
            piles[i].push_back(i);
        }
    }

    void moveOnto(int a, int b)
    {
        int ia, ja;
        find_block(a, ia, ja);

        int ib, jb;
        find_block(b, ib, jb);

        // if blocks in the same pile
        if (ia == ib) return;

        replace_back(ia, a);
        replace_back(ib, b);

        piles[ib].push_back( a );
        piles[ia].pop_back();

    }
    void moveOver(int a, int b)
    {
        int ia, ja;
        find_block(a, ia, ja);

        int ib, jb;
        find_block(b, ib, jb);
        if (ia == ib) return;

        replace_back(ia, a);

        piles[ib].push_back( a );
        piles[ia].pop_back();
    }
    void pileOnto(int a, int b)
    {
        int ia, ja;
        find_block(a, ia, ja);

        int ib, jb;
        find_block(b, ib, jb);
        if (ia == ib) return;

        replace_back(ib, b);

        piles[ib].insert( piles[ib].end(), piles[ia].begin() + ja, piles[ia].end() );
        piles[ia].erase( piles[ia].begin() + ja, piles[ia].end() );
    }
    void pileOver(int a, int b)
    {
        int ia, ja;
        find_block(a, ia, ja);

        int ib, jb;
        find_block(b, ib, jb);
        if (ia == ib) return;

        piles[ib].insert( piles[ib].end(), piles[ia].begin() + ja, piles[ia].end() );
        piles[ia].erase( piles[ia].begin() + ja, piles[ia].end() );
    }
    void replace_back(int ia, int a)
    {
        while (!piles[ia].empty() and piles[ia].back() != a)
        {
            piles[ piles[ia].back() ].push_back(piles[ia].back());
            piles[ia].pop_back();
        }
    }

};

ostream &operator<<(ostream &out, const BlockWorld &w)
{
    for (int i = 0; i < sz(w.piles); ++i)
    {
        out << i << ":";
        for (auto e : w.piles[i])
        {
            out << " " << e;
        }
        out << '\n';
    }
    return out;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;

    BlockWorld w(n);

    string cmd, over_onto;
    
    int a, b;
    
    while (cin >> cmd and cmd != "quit")
    {
        cin >> a >> over_onto >> b;
        
        if (a == b)
            continue;

        if (cmd == "move")
        {
            if (over_onto == "onto")
                w.moveOnto(a, b);
            else if (over_onto == "over")
                w.moveOver(a, b);
        }
        else if (cmd == "pile")
        {
            if (over_onto == "onto")
                w.pileOnto(a, b);
            else if (over_onto == "over")
                w.pileOver(a, b);
        }   

    }
    cout << w << '\n';
}