#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYN    "\033[36m"

class PresidentialPardonForm: public AForm
{
    public:

        void execute(Bureaucrat const & executor) const;

        std::string const getTarget() const;

        PresidentialPardonForm(const PresidentialPardonForm & rhs);
        PresidentialPardonForm(const std::string target);
        ~PresidentialPardonForm();

        PresidentialPardonForm & operator = (const PresidentialPardonForm & rhs);

    private:
        const std::string _target;
        
};