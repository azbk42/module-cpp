#include "sample.class.hpp"
#include "sample1.class.hpp"


int main(void)
{
    Sample1 var('a', 1, 2.2);

    std::cout << var.a1 << std::endl;
    std::cout << var.a2 << std::endl;
    std::cout << var.a3 << std::endl;
    return 1;
}