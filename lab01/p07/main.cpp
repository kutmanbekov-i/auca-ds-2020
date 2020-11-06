// #include <boost/rational.hpp>
#include <bits/stdc++.h>
#include "Rational.hpp"

using Fraction = Rational<int64_t>;

using namespace std;

bool parseExpr(const string &line, Fraction &r1, char &op, Fraction &r2);
void computeAndShow(const Fraction &r1, char op, const Fraction &r2);

int main()
{

    for (string line; getline(cin, line); )
    {
        try
        {
            Fraction r1;
            char op;
            Fraction r2;

            if (!parseExpr(line, r1, op, r2))
            {
                cout << "Incorrect expression: " << line << endl;
            }
            else
            {
                computeAndShow(r1, op, r2);
            }
        }
        catch (const runtime_error &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

bool parseExpr(const string &line, Fraction &r1, char &op, Fraction &r2)
{
    const string operations = "+-*:<>=#";

    istringstream sinp(line);
    if (!(sinp >> r1))
    {
        return false;
    }
    if (!(sinp >> op) || operations.find(op) == string::npos)
    {
        return false;
    }

    char c;
    if (!(sinp >> r2) || sinp >> c)
    {
        return false;
    }

    return true;
}

void computeAndShow(const Fraction &r1, char op, const Fraction &r2)
{
    switch (op)
    {
    case '+':
        cout << r1 + r2 << endl;
        break;
    case '-':
        cout << r1 - r2 << endl;
        break;
    case '*':
        cout << r1 * r2 << endl;
        break;
    case ':':
    case '/':
        cout << r1 / r2 << endl;
        break;
    case '=':
        cout << (r1 == r2) << endl;
        break;
    case '#':
        cout << (r1 != r2) << endl;
        break;
    case '<':
        cout << (r1 < r2) << endl;
        break;
    case '>':
        cout << (r1 > r2) << endl;
        break;
    }
}
