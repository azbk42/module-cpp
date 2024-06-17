#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cerrno>
#include <cmath>

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void ScalarConverter::convert(const std::string& litteral)
{
   // _stringToChar(litteral);
    //_stringToInt(litteral);
    _stringToFloat(litteral);
    //_stringToDouble(litteral);
}

// ######################################################
// #                    GET - SET                       #
// ######################################################

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

ScalarConverter& ScalarConverter::operator = (const ScalarConverter& rhs)
{
    if (this != &rhs){

    }
    return (*this);
}
// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
        *this = rhs;
}
ScalarConverter::ScalarConverter() {};
ScalarConverter::~ScalarConverter() {};

       
// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################

// void ScalarConverter::_stringToChar(const std::string& litteral)
// {


// }

// void ScalarConverter::_stringToInt(const std::string& litteral)
// {

// }

// void ScalarConverter::_stringToFloat(const std::string& litteral)
// {
    
// }

// void ScalarConverter::_stringToDouble(const std::string& litteral)
// {
   
// }