#pragma once

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat: public WrongAnimal
{

    public:

        void makeSound(void) const ;

        WrongCat(const WrongCat & rhs);
        WrongCat();
        ~WrongCat();

        WrongCat & operator = (const WrongCat & rhs);
    protected:


    private:

};