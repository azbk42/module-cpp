#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const Intern::Dictionnary Intern::tab[3] ={

        {"PresidentialPardonForm", &Intern::createPresidential},
        {"RobotomyRequestForm", &Intern::createRobot},
        {"ShrubberyCreationForm", &Intern::createShrubbery},
};  

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

AForm* Intern::makeForm(const std::string name, const std::string target)
{
    for (size_t i = 0; i < 3; i++){
        if (tab[i].name == name){
            return (this->*tab[i].function)(target);
        }
    }
    std::cerr << "Sorry can't find for : " << name << " because: ";
    throw NoFormNameMatches();
}

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

Intern & Intern::operator=(const Intern & rhs)
{
    (void) rhs;
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

Intern::Intern(const Intern& rhs)
{
    (void)rhs;
}

Intern::Intern(){};

Intern::~Intern(){};

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################

AForm* Intern::createPresidential(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::createRobot(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}
AForm* Intern::createShrubbery(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}