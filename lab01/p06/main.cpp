#include <iostream>
#include "../../libs/StrUtils.hpp"

using namespace std;

string join (const vector<string> &v);

int main()
{
    // g++ -c -O2 split.cpp             – Optimizatios level 2
    // g++ -c main.cpp
    // g++ main.o split.o -o main       – combine and compile
    // g++ main.cpp split.o -o main     – another version

    vector<vector<string>> data = {
        {"hello", "world", "!!!"},
        {"hello", "world"},
        {"hello"},
        {},
        {"He110", "W0r1d", "a9a1n", "!"}
    };

    for (auto v : data)
    {
        cout << join(v) << '\n';
    }
}
