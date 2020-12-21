#pragma once

template <typename T>
void auSwap(T &a, T &b) noexcept
{
    T t = (T&&)(a);     //re-assignment of pointers, not values.  Swap pointers
    a = std::move(b);
    b = std::move(t);
    // The same as
    // T t = (T&&)(a)
}

template <typename SourceIter, typename DestIter>
DestIter auCopy(SourceIter beg, SourceIter end, DestIter cur)
{
    while (beg != end)
    {
        *cur++ = *beg++;
    }
    return cur;
}

template <typename Iter, typename T>
Iter auFind(Iter beg, Iter end, const T &v)
{
    while (beg != end)
    {
        if (*beg == v)
        {
            return beg;
        }
        ++beg;
    }
    return end;
}

template <typename Iter, typename Predicate>
Iter auFind_if(Iter beg, Iter end, Predicate p)
{
    while (beg != end)
    {
        if (p(*beg))
        {
            return beg;
        }
        ++beg;
    }
    return end;
}

template <typename Iter>
Iter auMin_element(Iter beg, Iter end)
{
    if (beg == end)
    {
        return end;        
    }
    Iter res = beg++;

    while (beg != end)
    {
        if (*beg < *res)
        {
            res = beg;
        }
        ++beg;
    }
    return res;
}


template <typename Iter, typename Predicate>
Iter auMin_element(Iter beg, Iter end, Predicate p)
{
    if (beg == end)
    {
        return end;        
    }
    Iter res = beg++;

    while (beg != end)
    {
        if (p(*beg, *res))
        {
            res = beg;
        }
        ++beg;
    }
    return res;
}

template <typename Iter, typename Predicate>
void auSelection_sort(Iter beg, Iter end, Predicate p)
{
    for (Iter it = beg; it != end; ++it)
    {
        auSwap(*it, *auMin_element(beg, end, p));
    }
}

template <typename Iter>
void auInsertion_sort(Iter beg, Iter end)
{
    for (Iter cur = beg; cur != end; ++cur)
    {
        for (Iter it = cur, it2 = cur; it != beg && *it2 < *(--it); --it2)
        {
            auSwap(*it, *it2);
        }
    }
}

template <typename Iter, typename T>
Iter auLower_bound(Iter beg, Iter end, const T &k)
{
    while (beg != end)
    {
        auto mid = beg + (end - beg) / 2;
        if (*mid < k)
        {
            beg = ++mid;
        }
        else
        {
            end = mid;
        }
    }
    return beg;
}

template <typename Iter>
void auReverse(Iter beg, Iter end)
{
    for (;;)
    {
        if (beg == end--) break;
        if (beg == end) break;

        auSwap(*beg++, *end);
    }

    // while ((beg != end) && (beg != --end)) {
    //     auSwap(*(beg++), *end);
    // }
}


