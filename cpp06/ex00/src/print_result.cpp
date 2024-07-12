#include "includes.hpp"
#include <cmath>
#include <limits>
#include <iomanip>

void displayResults(char c, int i, float f, double d) 
{
    
    if (std::isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } 
    else if (std::isnan(d) || std::isinf(d) || i < 0 || i > 127) {
        std::cout << "char: impossible" << std::endl;
    } 
    else {
        std::cout << "char: Non displayable" << std::endl;
    }

    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } 
    else {
        std::cout << "int: " << i << std::endl;
    }

    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
