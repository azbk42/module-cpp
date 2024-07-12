#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    Span tab(5);
    std::cout << BLUE << "try to print an empty array" << std::endl;
    std::cout << tab << std::endl;

    std::cout << BLUE << "tab.addNumber in order 52 - 2 - 45 - 13 - 22" << RESET << std::endl;
    tab.addNumber(52);
    tab.addNumber(2);
    tab.addNumber(47);
    tab.addNumber(13);
    tab.addNumber(22);

    try{
        std::cout << "------------------------------TEST 1------------------------------------------" << std::endl;
        std::cout << tab << std::endl;

        std::cout << BLUE << "\nTry to add a 6th element but array is 5 max" << RESET << std::endl;

        tab.addNumber(1);
    }
    catch(std::out_of_range &e){
        std::cerr << e.what() << std::endl;
    }
    catch(std::logic_error &e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << "------------------------------TEST 2------------------------------------------" << std::endl;

    try{

        std::cout << "Longest Span: "<< tab.longestSpan() << std::endl;
        std::cout << "shortest Span: " << tab.shortestSpan() << std::endl;

        Span fail(10);

        fail.addNumber(2);

        std::cout << BLUE << "\nTry to find span in array of 1 element." << RESET << std::endl;
        std::cout << fail.shortestSpan() << std::endl;

    }
    catch(std::out_of_range &e){
        std::cerr << e.what() << std::endl;
    }
    catch(std::logic_error &e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-------------------------------TEST 3----10 000 occurences ---------------------------------------" << std::endl;

    try{
        Span Test(10000);
        std::multiset<int> array;

        for (int i = 1; i <= 10000; i++){
            Test.addNumber(i);
        }
        array = Test.getArray();
        std::cout << "size = " << array.size() << std::endl;
        // Test to print 10 000 occurences
        //std::cout << Test << std::endl;
    }
    catch(std::out_of_range &e){
        std::cerr << e.what() << std::endl;
    }
    catch(std::logic_error &e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << "------------------------------TEST 4------------------------------------------" << std::endl;
    std::cout << "-----------------------------ADD RANGE----------------------------------------" << std::endl;
    try{
       
        Span Test(25);
        Test.addNumber(425);
        Test.addNumber(1);
        std::cout << Test << std::endl;

        std::cout << BLUE << "addRange with int 5 - 10" << RESET << std::endl;
        Test.addRange(5, 10);
        std::cout << Test << std::endl;

        std::cout << BLUE << "addRange with iterator 11 - 15" << RESET << std::endl;
        std::multiset<int> tab;
        for (int i = 11; i < 16; i++){
            tab.insert(i);
        }
        
        Test.addRange(tab.begin(), tab.end());
        std::cout << Test << std::endl;

        std::cout << BLUE << "Try to add range 1-100." << RESET << std::endl; 
        Test.addRange(1, 100);

    }
    catch(std::out_of_range &e){
        std::cerr << e.what() << std::endl;
    }
    catch(std::logic_error &e){
        std::cerr << e.what() << std::endl;
    }
    catch(std::invalid_argument &e){
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
