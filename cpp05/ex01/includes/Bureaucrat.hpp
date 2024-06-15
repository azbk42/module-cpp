#pragma once
#include <iostream>
#include "Form.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class Form;

class Bureaucrat
{
    public:

        void signForm(Form& form);
        std::string const getName() const;
        size_t getGrade() const;

        void increment(void);
        void decrement(void);
        
        Bureaucrat(const Bureaucrat & rhs);
        Bureaucrat(const std::string name, size_t grade);
        Bureaucrat();
        ~Bureaucrat();

        Bureaucrat & operator = (const Bureaucrat & rhs);
        
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

    private:
        const std::string _name;
        size_t _grade;

};

std::ostream& operator << (std::ostream& o, const Bureaucrat & rhs);