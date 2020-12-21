#pragma once

#include <cstddef>
#include <iostream>
#include <initializer_list>

class VecInt
{
    int *p;
    size_t sz;
    size_t cp;

public:

    static size_t counter;

    VecInt()
        : p(nullptr), sz(0), cp(0)
    {
    }

    VecInt(size_t n);

    // constructor with initialization list
    VecInt(std::initializer_list<int> init);

    // copy constructor
    VecInt(const VecInt &other);

    // assignment operator (copy)
    VecInt &operator=(const VecInt &other);

    // move constructor
    VecInt(VecInt &&other) noexcept
        : p(other.p), sz(other.sz), cp(other.cp)
    {
        other.p = nullptr;
        other.sz = 0;
        other.cp = 0;
    }

    // move assignment
    VecInt &operator=(VecInt &&other) noexcept
    {
        if (this != &other)
        {
            delete[] p;
            p = other.p;
            sz = other.sz;
            cp = other.cp;

            other.p = nullptr;
            other.sz = 0;
            other.cp = 0;
        }
        return *this;
    }

    ~VecInt();

    int *begin() const
    {
        return p;
    }

    int *end() const
    {
        return p + sz;
    }

    size_t size() const
    {
        return sz;
    }

    int &operator[](size_t index)
    {
        return p[index];
    }

    const int &operator[](size_t index) const
    {
        return p[index];
    }

    void pushBack(int x);
};

bool operator==(const VecInt &a, const VecInt &b);

inline bool operator!=(const VecInt &a, const VecInt &b)
{
    return !(a == b);
}
