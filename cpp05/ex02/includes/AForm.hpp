#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYN    "\033[36m"

class Bureaucrat;

class AForm
{
    public:

        void execute(Bureaucrat const & executor) const;
        virtual void executeAction(void) const = 0;
        void beSigned(const Bureaucrat& bur);

        const std::string getName() const;
        size_t getSignIt() const;
        size_t getExecuteIt() const;
        bool getSigned() const; 

        AForm(const AForm & rhs);
        AForm(const std::string name, size_t gradeToSign, size_t gradeToExec);
        AForm();
        virtual ~AForm();

        AForm & operator = (const AForm & rhs);

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Grade is to high!");
                }
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Grade is to low!");
                }
        };

        class AlreadySigned: public std::exception
        {
            public:
               virtual const char* what() const throw()
                {
                    return ("The AForm is already signed!");
                }
        };

        class NotSigned: public std::exception
        {
            public:
               virtual const char* what() const throw()
                {
                    return ("The AForm is not signed sorry!");
                }
        };

    private:

        const std::string _name;
        const size_t _requiredSignIt;
        const size_t _requiredExecuteIt;
        bool _signed;

};

std::ostream& operator << (std::ostream& o, const AForm & rhs);