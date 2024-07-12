#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Intern Jose;
    std::cout << BLUE << "Init Testeur (40):" << RESET << std::endl;
    Bureaucrat Testeur("Testeur", 40);
    AForm* cv = NULL;
    AForm* tool = NULL;


    std::cout << BLUE << "Init cv = robotomy\nAnd tool = unknow" << std::endl;
    std:: cout << "Try to get name cv and tool:" << RESET << std::endl;
    try{
        cv = Jose.makeForm("RobotomyRequestForm", "YO");
        tool = Jose.makeForm("Unknow", "YO");
        std::cout << cv->getName() << std::endl;
        std::cout << tool->getName() << std::endl;

    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << BLUE << "\nPrint Name of AForm CV: " << RESET << std::endl;
    std::cout << cv->getName() << std::endl;

    std::cout << BLUE << "\nTesteur sign and exec CV:" << RESET << std::endl;
    Testeur.signForm(*cv);
    Testeur.executeForm(*cv);


    delete cv;
    delete tool;
    return (0);
}