#include <bits/stdc++.h>

using namespace std;

void countRoman(int n);

int main() {
    
    int n;
    
    while (cin >> n)
    {
        if (n == 0) break;
        
        countRoman(n);
    }
        
}

void countRoman(int n)
{
    int numbers[] = {1, 4, 5, 9, 10, 40, 50, 90, 100};
    string symbols[] = {"i","iv","v","ix","x","xl","l","xc","c"};
    
    int i = 0, v = 0, x = 0, l = 0, c = 0;
    string s = "";
    
    for (int j = 1; j <= n; ++j)
    {
        int index = 8;
        int tmp = j;
        
        while (tmp > 0)
        {
            int d = tmp / numbers[index];
            tmp %= numbers[index];
            
            while (d--)
            {
                s += symbols[index];
            }
            --index;
        }
    }
    
    for (auto ch : s)
    {
        if (ch == 'i') ++i;
        if (ch == 'v') ++v;
        if (ch == 'x') ++x;
        if (ch == 'l') ++l;
        if (ch == 'c') ++c;
    }
    printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, i, v, x, l, c);
}