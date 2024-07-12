#include <iostream>
#include "Array.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

int main() 
{
    try {
        std::cout << GREEN << "Testing default constructor" << RESET << std::endl;
        Array<int> emptyArray;
        std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;
        std::cout << GREEN << "Try to acces no init value, (index 0)" << RESET << std::endl;
        emptyArray.getValue(0);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try{
        std::cout << GREEN << "\nTesting constructor with size parameter" << RESET << std::endl;
        std::cout << "Init n = 5" << std::endl;
        unsigned int n = 5;
        Array<int> array(n);
        std::cout << "Elements of array: " << array << std::endl;
        std::cout << "Size of array: " << array.size() << std::endl;
    } 
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try{
        unsigned int n = 5;
        Array<char> array(n);
        std::cout << GREEN << "\nTesting setIndex and getValue" << RESET << std::endl;
        array.setIndex(2, 'A');
        std::cout << "Value at index 1: " << array.getValue(1) << std::endl;
        std::cout << "Value at index 2: " << array.getValue(2) << std::endl;

        std::cout << GREEN << "\nTesting copy constructor" << RESET << std::endl;
        Array<char> arrayCopy(array);
        std::cout << "Elements of arrayCopy: " << arrayCopy << std::endl;
        std::cout << GREEN << "\nTesting Deep Copy:" << RESET << std::endl;
        std::cout << "Set index 0 with value 'B'" << std::endl;
        arrayCopy.setIndex(0, 'B');
        std::cout << "Print first array: " << array << std::endl;
        std::cout << "Print array copy: " << arrayCopy << std::endl;

        std::cout << GREEN << "\nTesting assignment operator '='" << RESET << std::endl;
        Array<char> assignedArray;
        assignedArray = array;
        std::cout << "Elements of assignedArray: " << assignedArray << std::endl;
        std::cout << "Set index 4 with value 'C'" << std::endl;
        assignedArray.setIndex(4, 'C');
        std::cout << "Print first array: " << array << std::endl;
        std::cout << "Print array copy: " << assignedArray << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    try{
        unsigned int n = 5;
        Array<char> array(n);
        std::cout << GREEN << "\nTesting out of bounds access" << RESET << std::endl;
        array.setIndex(0, 'A');
        std::cout << "Value at index 0: " << array[0] << std::endl;
        std::cout << GREEN << "Trying to access index 10" << RESET << std::endl;
        std::cout << "Value at index 10: " << array[10] << std::endl;  // This should throw an exception
    
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try{
        unsigned int n = 5;
        Array<char> array(n);
        std::cout << GREEN << "Testing writing []" << RESET << std::endl;
        array[0] = 'A';
        array[1] = 'B';
        array[2] = 'C';
        std::cout << "Print array: " << array << std::endl;
        std::cout << GREEN << "Out of boons index[10] = 'S'" << RESET << std::endl;
        array[10] = 'S';

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}