#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <stack>
#include "RPN.cpp"



int main(int ac, char **av)
{
    if (ac != 2){
        std::cerr << "Bad arg! You need 1 string like this -> "
                << "\"1 2 * 2 +\"" << std::endl;
        return (1);
    }
    std::string str = av[1];
    
    try {
        parsing_space(str);
        parsing_logic_rpn(str);

        reverse_polish(str);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::logic_error& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}