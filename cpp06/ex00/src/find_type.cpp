#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include "includes.hpp"

bool isChar(const std::string& literal) 
{
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])){
        return (true);
    }
    else {
        return (false);
    }
}


bool isInt(const std::string& literal) 
{
    char* end;
    long result = std::strtol(literal.c_str(), &end, 10);

    if (result >= std::numeric_limits<int>::min() && result <= std::numeric_limits<int>::max() && *end == '\0'){
        return (true);
    }
    else{
        return (false);
    }
}


bool isFloat(const std::string& literal) 
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff") {
        return true;
    }

    char* end;
    std::strtof(literal.c_str(), &end);

    if (end[0] == 'f' && end[1] == '\0'){
        return (true);
    }

    return (false);
}


bool isDouble(const std::string& literal) 
{
    if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf") {
        return true;
    }

    char* end;
    std::strtod(literal.c_str(), &end);
    if (end[0] == '\0'){
        return (true);
    }
    return (false);

}