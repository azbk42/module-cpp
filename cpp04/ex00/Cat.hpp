#pragma once
#include "Animal.hpp" 
#include <iostream>

class Cat: public Animal
{

    public:

        void makeSound(void) const;

        Cat(const Cat & rhs);
        Cat();
        ~Cat();

        Cat & operator = (const Cat & rhs);

    protected:


    private:

};