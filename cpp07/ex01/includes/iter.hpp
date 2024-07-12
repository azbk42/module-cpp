#pragma once
#include <iostream>
#include <string>

template< typename T, typename F>
void iter(T* address, size_t len, F f)
{
    for (size_t i = 0; i < len; i++){
        f(address[i]);
    }
}

template< typename T>
void add(T& value)
{
    value += 10;
}

template <typename P>
void print(const P& value)
{
    std::cout << value << std::endl;
}
