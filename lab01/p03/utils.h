template<typename T>
void templateSwap(T &a, T &b)
{
    T t = std::move(a);
    a = std::move(b);
    b = std::move(t);
}