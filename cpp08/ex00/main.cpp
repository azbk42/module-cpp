#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>

#define BLUE "\033[34m"
#define RESET "\033[0m"

int main()
{
    try {
        std::vector<int> v;
        v.push_back(40);
        v.push_back(2);
        v.push_back(37);
        v.push_back(50);
        v.push_back(114);
        v.push_back(2);
        v.push_back(1);

        std::cout << BLUE << "Simple test, we try to find 114 in array: {40, 2, 37, 50, 114, 2, 1}" << RESET << std::endl;
        
        std::vector<int>::const_iterator itd = easyfind(v, 114);
        std::cout << *itd << std::endl;

        std::vector<int>::const_iterator it = easyfind(v, 2);

        std::cout << BLUE << "Try to find 2, and we print the value next to him" << RESET << std::endl;
        std::cout << *it << std::endl;
        it++;
        std::cout << *it << std::endl;

        std::cout << BLUE << "Try to find value: 1111" << RESET << std::endl;
        std::vector<int>::const_iterator result = easyfind(v, 1111);
        std::cout << *result << std::endl;
    }
    catch (const std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "Same test but with list (linked list)" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;

    try {
        std::list<int> lst;
        lst.push_back(40);
        lst.push_back(2);
        lst.push_back(37);
        lst.push_back(50);
        lst.push_back(114);
        lst.push_back(2);
        lst.push_back(1);

        std::cout << BLUE << "Simple test, we try to find 114 in linked list: {40, 2, 37, 50, 114, 2, 1}" << RESET << std::endl;
        
        std::list<int>::const_iterator itd = easyfind(lst, 114);
        std::cout << *itd << std::endl;

        std::list<int>::const_iterator it = easyfind(lst, 2);

        std::cout << BLUE << "Try to find 2, and we print the value next to him" << RESET << std::endl;
        std::cout << *it << std::endl;
        it++;
        std::cout << *it << std::endl;

        std::cout << BLUE << "Try to find value: 1111" << RESET << std::endl;
        std::list<int>::const_iterator result = easyfind(lst, 1111);
        std::cout << *result << std::endl;
    }
    catch (const std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}