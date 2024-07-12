#include <iostream>
#include <string>
#include <cstdlib>
#include "ScalarConverter.hpp"


int main(int ac, char **av)
{
    if (ac != 2){
        return (1);
    }
    ScalarConverter::convert(av[1]);

    return (0);
}

// int main()
// {
//     ScalarConverter::convert("0");
//     std::cout << std::endl;
//     ScalarConverter::convert("str");
//     std::cout << std::endl;
//     ScalarConverter::convert("c");
//     std::cout << std::endl;
//     ScalarConverter::convert("42");
//     std::cout << std::endl;
//     ScalarConverter::convert("-42");
//     std::cout << std::endl;
//     ScalarConverter::convert("42.0f");
//     std::cout << std::endl;
//     ScalarConverter::convert("42.42");
//     std::cout << std::endl;
//     ScalarConverter::convert("inf");
//     std::cout << std::endl;
//     ScalarConverter::convert("inff");
//     std::cout << std::endl;
//     ScalarConverter::convert("-inf");
//     std::cout << std::endl;
//     ScalarConverter::convert("-inff");
//     std::cout << std::endl;
//     ScalarConverter::convert("nanf");
//     std::cout << std::endl;
//     ScalarConverter::convert("nan");
//     std::cout << std::endl;

//     return 0;
// }