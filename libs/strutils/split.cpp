#include <cctype>
#include "StrUtils.hpp"

using namespace std;

vector<string> split(const string &line)
{
    vector<string> r;

    size_t beg = line.size();
    for (int i = 0; i < line.size(); ++i)
    {
        if (isspace(line[i]) and beg != line.size())
        {
            // r.push_back( line.substr(beg, i - beg) ); - creates a copy
            r.emplace_back(line, beg, i - beg);
            beg = line.size();
        }
        else if (!isspace(line[i]) and beg == line.size())
        {
            beg = i;
        }
    }
    if (beg != line.size())
    {
        // r.push_back(line.substr(beg));
        r.emplace_back(line, beg);
    }

    return r;
}