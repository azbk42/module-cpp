#include "ScalarConverter.hpp"
#include "includes.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void ScalarConverter::convert(const std::string& literal) 
{
    if (isChar(literal)) {
        char c = literal[0];
        displayResults(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
    } 
    else if (isInt(literal)) {
        int i = std::atoi(literal.c_str());
        displayResults(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
    } 
    else if (isFloat(literal)) {

        float f;

        if (literal == "nanf") {
            f = std::numeric_limits<float>::quiet_NaN();
        } 
        else if (literal == "+inff" || literal == "inff") {
            f = std::numeric_limits<float>::infinity();
        } 
        else if (literal == "-inff") {
            f = -std::numeric_limits<float>::infinity();
        } 
        else {
            f = std::strtof(literal.c_str(), NULL);
        }
        displayResults(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
    } 
    else if (isDouble(literal)) {

        double d;

        if (literal == "nan") {
            d = std::numeric_limits<double>::quiet_NaN();
        } 
        else if (literal == "+inf" || literal == "inf") {
            d = std::numeric_limits<double>::infinity();
        }
        else if (literal == "-inf") {
            d = -std::numeric_limits<double>::infinity();
        } 
        else {
            d = std::strtod(literal.c_str(), NULL);
        }
        displayResults(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
    } 
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
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
// #                    BOOLEAN                         #
// ######################################################




// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################


    


