#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

int main()
{

    std::cout << BLUE << "Init new Form 'Robot' Robotomy Request Form (72) (45)" << RESET << std::endl;
    std::cout << BLUE << "Init Bureaucrat:\n" << RESET << "- Teddy (5)\n- Toto (145)" << std::endl;
    AForm* Robot = new RobotomyRequestForm("Paul");
    Bureaucrat Teddy("Teddy", 5);
    Bureaucrat ToTo("Toto", 145);

    std::cout << BLUE << "\nTeddy try to execute Form without sign it" << RESET << std::endl;
    Teddy.executeForm(*Robot);
    Teddy.signForm(*Robot);
    
    try{
        Robot->execute(ToTo);
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }

//------------------------------------------------------------------------------------------------

    std::cout << BLUE << "\nInit new Form 'President' PresidentialPardonForm (25) (5)." << RESET << std::endl;
    AForm* President = new PresidentialPardonForm("Macron");

    std::cout << BLUE << "\nTry to sign with Toto 145, President to sign: 25 " << RESET << std::endl;   
    ToTo.signForm(*President);
    std::cout << BLUE << "Teddy sign it:" << RESET << std::endl;
    Teddy.signForm(*President);
    std::cout << BLUE << "ToTo 145 try to exec it, President need 5 to exec:" << RESET << std::endl;
    ToTo.executeForm(*President);
    std::cout << BLUE << "Teddy with 5 exec it:" << RESET << std::endl;
    Teddy.executeForm(*President);


//--------------------------------------------------------------------------------------------------------
    std::cout << BLUE << "\n\nInit new Form 'President' ShrubberyCreationForm (145) (137)." << RESET << std::endl;
    AForm* Shrubbery = new ShrubberyCreationForm("Graveyard");
    std::cout << BLUE << "Try to decrement ToTo:" << RESET << std::endl;
    try{
        for (int i = 0; i < 100; i++){
            ToTo.decrement();
            std::cout << ToTo << std::endl;
        }
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << ToTo << std::endl;
    std::cout << BLUE << "\nTry to exec with toto:" << RESET << std::endl;
    ToTo.executeForm(*Shrubbery);
    
    std::cout << BLUE << "\nIncrement Toto +10:" << RESET << std::endl;
    try{
        for (int i = 0; i < 10; i++){
            ToTo.increment();
        }
        std::cout << ToTo << std::endl;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << BLUE << "\nTry to exec with toto but Method from AForm:" << RESET << std::endl;
    try{
        Shrubbery->execute(ToTo);
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << BLUE << "Sign it and exec it:" << RESET << std::endl;
    ToTo.signForm(*Shrubbery);
    ToTo.executeForm(*Shrubbery);

    delete Shrubbery;
    delete President;
    delete Robot;
    return (0);
}