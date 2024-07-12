#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>


template <typename T>
typename T::const_iterator easyfind(const T& address, int c)
{

    typename T::const_iterator it = std::find(address.begin(), address.end(), c);
    if (it == address.end()){
        throw std::out_of_range("Element not found");
    }
    else{
        return (it);
    }
}