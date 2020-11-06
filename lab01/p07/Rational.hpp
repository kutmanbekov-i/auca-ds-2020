#pragma once

#include <istream>
#include <ostream>

template <typename T>
class Rational
{
    T mNum;
    T mDen;

public:
    Rational(const T &num = 0, const T &den = 1)
        : mNum(num), mDen(den)
    {
        if (mDen == 0)
        {
            throw std::runtime_error("Rational: denominator cannot be zero.");
        }

        if (mDen < 0)
        {
            mNum *= -1;
            mDen *= -1;
        }

        T a = mNum;
        T b = mDen;
        while (b != 0)
        {
            T t = a % b;
            a = b;
            b = t;
        }

        mNum /= a;
        mDen /= a;
    }

    T num() const
    {
        return mNum;
    }
    T den() const
    {
        return mDen;
    }
};

template <typename T>
Rational<T> operator+(const Rational<T> &a, const Rational<T> &b)
{
    T tNum = a.num() * b.den() + a.den() * b.num();
    T tDen = a.den() * b.den();
    return Rational<T>(tNum, tDen);
}

template <typename T>
Rational<T> operator-(const Rational<T> &a, const Rational<T> &b)
{
    T tNum = a.num() * b.den() - a.den() * b.num();
    T tDen = a.den() * b.den();
    return Rational<T>(tNum, tDen);
}

template <typename T>
Rational<T> operator*(const Rational<T> &a, const Rational<T> &b)
{
    T tNum = a.num() * b.num();
    T tDen = a.den() * b.den();
    return Rational<T>(tNum, tDen);
}

template <typename T>
Rational<T> operator/(const Rational<T> &a, const Rational<T> &b)
{
    if (b.num() == 0)
    {
        throw std::runtime_error("Rational: division by zero");
    }
    T tNum = a.num() * b.den();
    T tDen = a.den() * b.num();
    return Rational<T>(tNum, tDen);
}

template <typename T>
bool operator==(const Rational<T> &a, const Rational<T> &b)
{
    return a.num() == b.num() and a.den() == b.den();
}
template <typename T>
bool operator!=(const Rational<T> &a, const Rational<T> &b)
{
    return !(a == b);
}
template <typename T>
bool operator>(const Rational<T> &a, const Rational<T> &b)
{
    return a.num() * b.den() > a.den() * b.num();
}
template <typename T>
bool operator<(const Rational<T> &a, const Rational<T> &b)
{
    return b > a;
}
template <typename T>
bool operator>=(const Rational<T> &a, const Rational<T> &b)
{
    return !(a < b);
}
template <typename T>
bool operator<=(const Rational<T> &a, const Rational<T> &b)
{
    return !(b < a);
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Rational<T> &r)
{
    return out << r.num() << "/" << r.den();
}
template <typename T>
std::istream &operator>>(std::istream &inp, Rational<T> &r)
{
    T num;
    if (!(inp >> num))
    {
        return inp;
    }

    char ch;
    if (!inp.get(ch))
    {
        return inp;
    }

    if (ch != '/')
    {
        inp.setstate(std::ios_base::failbit);
        return inp;
    }

    if (!(inp.get(ch)))
    {
        return inp;
    }

    if (ch == '+' || ch == '-' || isdigit(ch))
    {
        inp.putback(ch);
    }
    else
    {
        inp.setstate(std::ios_base::failbit);
        return inp;
    }

    T den;
    if (!(inp >> den))
    {
        return inp;
    }

    r = Rational<T>(num, den);

    return inp;
}