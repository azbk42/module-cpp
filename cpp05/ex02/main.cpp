#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

int main()
{
    AForm* CV = new RobotomyRequestForm("Paul");
    Bureaucrat Teddy("Teddy", 5);
    Bureaucrat ToTo("Toto", 145);

    Teddy.signForm(*CV);
    Teddy.executeForm(*CV);
    //CV->execute(Teddy);

    delete CV;
    return (0);
}