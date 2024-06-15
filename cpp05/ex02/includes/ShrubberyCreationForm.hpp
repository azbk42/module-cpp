#pragma once
#include "AForm.hpp"
#include <string>
#include <iostream>
#include <fstream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYN    "\033[36m"

class ShrubberyCreationForm: public AForm
{
    public:

        void executeAction(void) const;

        std::string const getTarget() const;

        ShrubberyCreationForm(const ShrubberyCreationForm & rhs);
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();

        ShrubberyCreationForm & operator = (const ShrubberyCreationForm & rhs);

        class Openfail: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error open file");
                }
        };
    
    private:
        
        void _createFileAndPrint(const std::string &target) const;
        void _printTree(std::ofstream& file) const;
        
        const std::string _target;
};