#include "PresidentialPardonForm.hpp"

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void PresidentialPardonForm::executeAction(void) const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

// ######################################################
// #                 GET - SET                          #
// ######################################################

std::string const PresidentialPardonForm::getTarget() const
{
    return (_target);
}

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs)
{
    (void)rhs;
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & rhs): AForm(rhs.getName(), rhs.getSignIt(), rhs.getExecuteIt()), _target(rhs.getTarget()){};

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target){};

PresidentialPardonForm::PresidentialPardonForm(): _target("Default"){};

PresidentialPardonForm::~PresidentialPardonForm(){};

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################