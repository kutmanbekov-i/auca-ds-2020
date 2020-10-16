#include <bits/stdc++.h>

using namespace std;

void decode(vector<int> &ram, vector<int> &reg)
{
    int cnt = 0, location = 0;
    
    while (true)
    {
        int h = ram[location] / 100;
        if (h == 1) break;
        
        int d = ram[location] % 100 / 10;
        int n = ram[location] % 10;
        
        ++cnt;
        ++location;
        
        switch(h)
        {
            case 2:
                reg[d] = n;
                break;
            case 3:
                reg[d] += n;
                reg[d] %= 1000;
                break;
            case 4:
                reg[d] *= n;
                reg[d] %= 1000;
                break;
            case 5:
                reg[d] = reg[n];
                break;
            case 6:
                reg[d] += reg[n];
                reg[d] %= 1000;
                break;
            case 7:
                reg[d] *= reg[n];
                reg[d] %= 1000;
                break;
            case 8:
                reg[d] = ram[reg[n]];
                break;
            case 9:
                ram[reg[n]] = reg[d];
                break;
            case 0:
                if (reg[n] != 0)
                    location = reg[d];
                break;
                
        }
        // ++cnt;
        // ++location;
    }
    cout << cnt + 1 << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t; bool first = true;
    
    while (t--)
    {
        int n;
        string s;
        vector<int> ram(1000);
        vector<int> reg(10);
        vector<string> instr(1000);
        
        if (first)
        {
            getline(cin, s);
            getline(cin, s);
        }
        
        for (int i = 0; getline(cin, instr[i]); ++i )
        {
            if (instr[i] == "\0") break;
            ram[i] = stoi(instr[i]);

        }

        // cout << ram[10] << "\n";
        
        decode(ram, reg);
        cout << "\n";
        first = false;
    }
    
}
