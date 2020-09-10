#include <bits/stdc++.h>

using namespace std;

int main()
{
    int g, s, c, points = 0;
    cin >> g >> s >> c;

    points = 3 * g + 2 * s + c;
    string victory, treasure;

    if (points >= 8) victory = "Province";
    else if (points >= 5) victory = "Duchy";
    else if (points >= 2) victory = "Estate";
    
    if (points >= 6) treasure = "Gold";
    else if (points >= 3) treasure = "Silver";
    else if (points >= 0) treasure = "Copper";

    if (not victory.empty() )
        cout << victory << " or ";
    cout << treasure << "\n";
}