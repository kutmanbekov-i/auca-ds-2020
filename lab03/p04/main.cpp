#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int month, dep;
    double payment, amount;
    
    while(true)
    {
        cin >> month >> payment >> amount >> dep;
        
        if (month < 0) break;
        
        vector<double> percents(month, 0);
        
        int num, cnt = 0;
        double percent, new_amount = amount + payment;
        
        for (int i = 0; i < dep; ++i)
        {
            cin >> num >> percent;

            percents[num] = percent;
        }
        
        double temp = percents[0];
        double aver = amount / month;
        new_amount -= (new_amount * percents[0]);
        
        while (amount > new_amount)
        {
            ++cnt;
            if (percents[cnt] != 0)
            {
                new_amount = new_amount - (new_amount * percents[cnt]);
                temp = percents[cnt];
            }
            else
            {
                new_amount = new_amount - (new_amount * temp);
                // new_amount = new_amount * (1 - percents[cnt]);
            }
            
            amount -= aver;
        }
        
        cout << cnt << " month" << (cnt == 1 ? "\n" : "s\n");
    }

}