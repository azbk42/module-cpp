#pragma once
#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria
{
    public:

        AMateria* clone() const;
        void use(ICharacter& target);

        Ice(const Ice & rhs);
        Ice();
        ~Ice();
    
        Ice & operator = (const Ice & rhs);
    private:

};
