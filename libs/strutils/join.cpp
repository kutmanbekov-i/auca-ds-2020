#include <string>
#include <vector>

using namespace std;

string join (const vector<string> &v)
{
    string empty;

    if (!v.empty())
    {
        empty += v[0];

        for (size_t i = 1; i < v.size(); ++i)
        {
            empty += " ";
            empty += v[i];
        }
    }

    return empty;
}