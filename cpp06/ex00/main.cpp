#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main()
{
    ScalarConverter::convert("0");
    ScalarConverter::convert("str");
    ScalarConverter::convert("c");
    ScalarConverter::convert("42");
    ScalarConverter::convert("-42");
    ScalarConverter::convert("42.42f");
    ScalarConverter::convert("42.42");
    ScalarConverter::convert("inf");
    ScalarConverter::convert("inff");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("nan");

    ScalarConverter::convert("1.0e40");

    return 0;
}
