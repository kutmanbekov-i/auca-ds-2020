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
        
        double temp = 0;
        
        for (int i = 0; i < month; ++i)
        {
            
            if (percents[i] != 0)
            {
                new_amount = new_amount - (new_amount * percents[i]);
                temp = percents[i];
            }
            else
            {
                new_amount = new_amount - (new_amount * temp);
            }
            
            amount -= 500;
            cnt++;

            if(amount < new_amount) 
                break;
        }
        
        cout << cnt << " month" << (cnt == 1 ? "\n" : "s\n");
    }

}