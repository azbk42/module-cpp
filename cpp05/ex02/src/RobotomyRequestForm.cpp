#include "RobotomyRequestForm.hpp"


// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void RobotomyRequestForm::executeAction(void) const
{
    std::srand(static_cast<unsigned>(std::time(0)));
    if ((rand() % 2) == 0){
        std::cout << RED << "Robotomy has failed !" << RESET << std::endl;
    }
    else{
        std::cout << GREEN << getTarget() << " has been robotomized!" << RESET << std::endl;
    }
}



// ######################################################
// #                 GET - SET                          #
// ######################################################

std::string const RobotomyRequestForm::getTarget() const
{
    return (_target);
}

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs)
{
    (void)rhs;
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & rhs): AForm(rhs.getName(), rhs.getSignIt(), rhs.getExecuteIt()), _target(rhs.getTarget()){};

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target){};

RobotomyRequestForm::RobotomyRequestForm(): _target("Default") {};

RobotomyRequestForm::~RobotomyRequestForm(){};

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################