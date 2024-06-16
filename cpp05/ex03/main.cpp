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
    Bureaucrat Testeur("Testeur", 40);
    AForm* cv = NULL;
    AForm* tool = NULL;

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