#pragma once
#include <iostream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define CYN "\e[0;36m"

class Animal
{

    public:

        virtual void makeSound(void) const;

        std::string getType() const;
        Animal(const Animal & rhs);
        Animal();
        virtual ~Animal();

        Animal & operator = (const Animal & rhs);

    protected:
        std::string type;

    private:

};