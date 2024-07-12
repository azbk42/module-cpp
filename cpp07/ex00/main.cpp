#include <iostream>
#include <string>
#include "include.hpp"

int main(void)
{
    int a = 5;
    int b = 452;

    std::cout << "a and b before:" << std::endl;
    std::cout << "a = " << a << " et b = " << b << std::endl;
    ::swap(a, b);

    std::cout << "after:" << std::endl;
    std::cout << "a = " << a << " et b = " << b << std::endl;

    int max = ::max(a, b);
    std::cout << "max = " << max << std::endl;

    std::cout << "--------------------------------------------------------------\n" << std::endl;
    
    std::cout << "Init e = 452.42f and f = 4.12f" << std::endl;
    float e = 452.42f;
    float f = 4.12f;

    float min = ::min(e, f);
    
    std::cout << "min = " << min << std::endl;
    std::cout << "max = " << ::max(e, f) << std::endl;


    std::cout << "--------------------------------------------------------------\n" << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "c before = " << c << ", d before = " << d << std::endl;
    
    ::swap(c, d);
    std::cout << "c after = " << c << ", d after = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    
    return (0);
}