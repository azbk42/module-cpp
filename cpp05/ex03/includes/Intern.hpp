#pragma once
#include <iostream>
#include "AForm.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYN    "\033[36m"

class AForm;

class Intern
{
    public:

        AForm* makeForm(const std::string name, const std::string target);

        Intern(const Intern & rhs);
        Intern();
        ~Intern();

        Intern & operator = (const Intern & rhs);

        class NoFormNameMatches: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "No name matches";
                }
        };

    private:
        AForm* createPresidential(const std::string& target);
        AForm* createRobot(const std::string& target);
        AForm* createShrubbery(const std::string& target);

        struct Dictionnary {
            std::string name;
            AForm* (Intern::*function)(const std::string &target);
        };
        static const Dictionnary tab[3];

};