#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    
    cin >> n;
    
    string family[n];
    string happy[] = {"Happy", "birthday", "to", "you"};
    
    int repetitions = ceil(n / 16.0);
    
    for (int i = 0; i < n; ++i)
    {
        cin >> family[i];
    }
    
    int cnt, ind = 0;
    
    for (int i = 0; i < repetitions; ++i)
    {
        cnt = 0;
        
        for (int j = 0; j < 16; ++j)
        {
            cout << family[ind % n] << ": ";
            
            if (j % 4 == 0)
            {
                ++cnt;
                cout << happy[j % 4];
                
            } else if (j % 4 == 3)
            {
                if (cnt == 3)
                    cout << "Rujia";
                else
                    cout << happy[j % 4];
                    
            } else {
                cout << happy[j % 4];
            }
            cout << "\n";
            ++ind;
        }
    }
    
}