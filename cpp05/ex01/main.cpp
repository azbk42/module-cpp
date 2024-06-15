#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << BLUE << "Init bad form:\nOne with: 0, 12\nOne with: 12, 155" << RESET << std::endl;
    try{
        Form test("TEST", 0, 12);
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    try{
        Form test("TEST", 12, 155);
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << BLUE << "\nInit CV to sign: 50, to exec: 50" << RESET << std::endl;
    Form CV("CV", 50, 50);
    std::cout << CV << std::endl;


    std::cout << BLUE << "\nInit Paul:" << RESET << std::endl;
    Bureaucrat Paul("Paul", 12);
    std::cout << Paul << std::endl;


    std::cout << BLUE << "\nInit Lucie:" << RESET << std::endl;
    Bureaucrat Lucie("Lucie", 51);
    std::cout << Lucie << std::endl;
    

    std::cout << BLUE << "Try to sign with Lucie:" << RESET << std::endl;
    

    // try{
    //     std::cout << BLUE << "Try to sign with Lucie:" << RESET << std::endl;
    //     CV.beSigned(Lucie);
    // }
    // catch(std::exception& e){
    //     std::cerr << e.what() << std::endl;
    // }

    Lucie.signForm(CV);

    try{
        std::cout << BLUE << "\nIncrement Lucie:" << RESET << std::endl;
        Lucie.increment();
        std::cout << Lucie << std::endl;
        std::cout << BLUE << "\nTry to sign with Lucie:" << RESET << std::endl;
        Lucie.signForm(CV);
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }


    // std::cout << BLUE << "Paul try to sign again:" << RESET << std::endl;
    // try{
    //     CV.beSigned(Paul);
    // }
    // catch(std::exception&e){
    //     std::cout << e.what() << std::endl;
    // }


    // std::cout << "\n" << CV << std::endl;
    return (0);
}