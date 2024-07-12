#include <iostream>
#include <string>

template< typename T>
T const& max(const T& x, const T& y)
{
    return ( x >= y ? x : y);
}

template< typename T>
T const& min(const T& x, const T& y)
{
    return ( x < y ? x : y);
}

template< typename S>
void swap( S& x, S& y)
{
    S z = x;
    x = y;
    y = z;
}