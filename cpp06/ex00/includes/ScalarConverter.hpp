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

       static void convert(const std::string& litteral);

    private:
        ScalarConverter(const ScalarConverter& rhs);
        ScalarConverter();
        ~ScalarConverter();

        ScalarConverter& operator = (const ScalarConverter& rhs);

        static void _stringToChar(const std::string& litteral);
        static void _stringToInt(const std::string& litteral);
        static void _stringToFloat(const std::string& litteral);
        static void _stringToDouble(const std::string& litteral);
};
