#include <bits/stdc++.h>

using namespace std;

int main()
{
    /* g++ -std=c++17 main.cpp*/ 
    fstream file;
    file.open("output.txt", ios::out);

    streambuf* sb_file = file.rdbuf();

    // Redirect cout to a file
    cout.rdbuf(sb_file);

    cout << "Hello, C++ " << __cplusplus;

    file.close();
}