#include <bits/stdc++.h>

using namespace std;

// value semantics
bool isPalindrome(const string &line)
{
    string empty;
    for (auto c : line)
    {
        if (isalpha(c))
        {
            empty += tolower(c);
        }
    }
    string temp = empty;
    reverse(temp.begin(), temp.end());

    return empty == temp;
}

int main() {
    
    // main < inp.txt - redirection
    for (string line; getline(cin, line); )
    {
        cout << (isPalindrome(line) ? "palindrome\n" : "not a palindrome\n");
    }

}
