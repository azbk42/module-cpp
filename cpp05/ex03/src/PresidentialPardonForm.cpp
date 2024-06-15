#include "PresidentialPardonForm.hpp"

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getExecuteIt()){
        throw GradeTooLowException();
    }
    if (getSigned() == false){
        throw NotSigned();
    }

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

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 145, 137), _target(target){};

PresidentialPardonForm::~PresidentialPardonForm(){};

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################