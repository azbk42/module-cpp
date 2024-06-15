#pragma once
#include <iostream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define CYN "\e[0;36m"



class Bureaucrat
{
    public:

        std::string const getName() const;
        size_t getGrade() const;

        void increment(void);
        void decrement(void);
        
        Bureaucrat(const Bureaucrat & rhs);
        Bureaucrat(std::string name, size_t grade);
        Bureaucrat();
        ~Bureaucrat();

        Bureaucrat & operator = (const Bureaucrat & rhs);
        

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Grade is to high (max is 1)");
                }
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Grade is to low (max is 150)");
                }
        };

    private:
        const std::string _name;
        size_t _grade;

};

std::ostream& operator << (std::ostream& o, const Bureaucrat & rhs);