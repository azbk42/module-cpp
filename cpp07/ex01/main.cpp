#include <iostream>
#include "iter.hpp"

int main() 
{
    int intArr[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArr) / sizeof(intArr[0]);

    iter(intArr, intLength, add<int>);

    for (size_t i = 0; i < intLength; ++i) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "--------------------------------------------------------------\n" << std::endl;

    float floatArr[] = {1.12f, 2.12f, 3.13f, 4.45f, 5.55f};

    size_t floatLength = sizeof(floatArr) / sizeof(floatArr[0]);

    iter(floatArr, floatLength, add<float>);

    iter(floatArr, floatLength, print<float>);
    
    std::cout << std::endl;


    std::cout << "--------------------------------------------------------------\n" << std::endl;
    const char* tab[] = {"Kevin", "Mat", "Jess", "Lea"};

    iter(tab, 4, print<const char*>);

    return 0;
}

