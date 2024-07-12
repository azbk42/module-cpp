#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cerrno>
#include <cmath>

class ScalarConverter
{
    public:

       static void convert(const std::string& literal);

    private:
        ScalarConverter(const ScalarConverter& rhs);
        ScalarConverter();
        ~ScalarConverter();

        ScalarConverter& operator = (const ScalarConverter& rhs);

};