#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try{
        std::cout << BLUE << "\nInit Paul 75:" << RESET << std::endl;
        Bureaucrat paul("Paul", 75);
        std::cout << paul << std::endl;
        std::cout << BLUE << "\nIncrement Paul:" << RESET << std::endl;
        paul.increment();
        std::cout << paul << std::endl;
        std::cout << BLUE << "\nDecrement Paul:" << RESET << std::endl;
        paul.decrement();
        std::cout << paul << std::endl;

        std::cout << BLUE << "\nInit Lucie 0:" << RESET << std::endl;
        Bureaucrat lucie("Lucie", 0);
        std::cout << lucie << std::endl;
    }
    catch (std::exception& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try{
        std::cout << BLUE << "\nInit Teddy 155:" << RESET << std::endl;
        Bureaucrat teddy("Teddy", 155);

        std::cout << teddy << std::endl;
    }
    catch (std::exception& e){
        std::cerr << "Execption: " << e.what() << std::endl;
    }

    try{
        std::cout << BLUE << "\nInit Al 1:" << RESET << std::endl;
        Bureaucrat al("al", 1);

        std::cout << BLUE << "\nIncrement Al:" << RESET << std::endl;
        al.increment();
    }
    catch (std::exception& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    
    try{
        std::cout << BLUE << "\nInit Lola 150:" << RESET << std::endl;
        Bureaucrat lola("Lola", 150);

        std::cout << BLUE << "\nDecrement Lola:" << RESET << std::endl;
        lola.decrement();
    }
    catch (std::exception& e){
        std::cerr << "Execption: " << e.what() << std::endl;
    }

    return (0);
}