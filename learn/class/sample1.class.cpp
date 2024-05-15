#include "sample1.class.hpp"


#include <iostream>
#include "sample1.class.hpp"

Sample1::Sample1(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3)
{

    return ;
}

Sample1::~Sample1(void ){

    std::cout << "destructor call" << std::endl;
    return ;
}