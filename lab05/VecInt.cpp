#include "VecInt.hpp"
#include "../libs/utils.hpp"

size_t VecInt::counter = 0;

VecInt::VecInt(size_t n)
    : p(new int[n]), sz(n), cp(n)
{
    for (size_t i = 0; i < n; ++i)
    {
        p[i] = 0;
    }
}

VecInt::VecInt(std::initializer_list<int> init)
    : p(new int[init.size()]), sz(init.size()), cp(init.size())
{
    // std::copy(init.begin(), init.end(), p);
    auCopy(init.begin(), init.end(), p);
}

// copy constructor
VecInt::VecInt(const VecInt &other)
    : p(new int[other.sz]), sz(other.sz), cp(other.sz)
{
    counter += other.size();
    // the same as std::copy or auCopy
    for (size_t i = 0; i < sz; ++i)
    {
        p[i] = other.p[i];
    }
}

// assignment operator (copy)
VecInt &VecInt::operator=(const VecInt &other)
{
    if (this != &other)
    {
        int *newP = new int[other.sz];
        counter += other.size();

        for (size_t i = 0; i < other.sz; ++i)
        {
            newP[i] = other.p[i];
        }
        delete[] p;
        p = newP;
        sz = other.sz;
        cp = other.cp;
    }
    return *this;
}


//


//

VecInt::~VecInt()
{ 
    std::cout << "~VecInt()" << std::endl;
    delete[] p;
}

void VecInt::pushBack(int x)
{
    if (sz == cp)
    {
        size_t newCp = sz == 0 ? 1 : cp * 2;

        int *q = new int[newCp];
        for (size_t i = 0; i < sz; ++i)
        {
            q[i] = p[i];
        }
        delete[] p;
        p = q;
        cp = newCp;
    }
    p[sz] = x;
    ++sz;
}

bool operator==(const VecInt &a, const VecInt &b)
{
    if (a.size() != b.size())
        return false;

    for (size_t i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
