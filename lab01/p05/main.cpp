#include <iostream>
#include "../../libs/StrUtils.hpp"

using namespace std;

int main()
{
    // g++ -c -O2 split.cpp             – Optimizatios level 2
    // g++ -c main.cpp
    // g++ main.o split.o -o main       – combine and compile
    // g++ main.cpp split.o -o main     – another version

    //ar rvs libstringutils.a split.o join.o         – create binary library(archive)
    //g++ main.cpp -o main -L../../libs -lstringutils   – specify the destination where linker has to search libs

    for (string line; getline(cin, line);)
    {
        vector<string> r = split(line);

        for (const auto &w : r)
        {
            cout << w << '\n';
        }
    }
}
