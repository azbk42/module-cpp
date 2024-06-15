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
    AForm* cv = NULL;
    AForm* tool = NULL;
    try{
        cv = Jose.makeForm("RobotomyRequestForm", "YO");
        tool = Jose.makeForm("Unknow", "YO");
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    
    delete cv;
    delete tool;

    return (0);
}