#pragma once
#include "Animal.hpp"
#include <iostream>

class Dog: public Animal
{

    public:

        void makeSound(void) const;

        Dog(const Dog & rhs);
        Dog();
        ~Dog();

        Dog & operator = (const Dog & rhs);

    protected:

    private:

};