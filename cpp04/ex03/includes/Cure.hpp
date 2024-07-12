#pragma once
#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria
{
    public:

        AMateria* clone() const;
        void use(ICharacter& target);

        Cure(const Cure & rhs);
        Cure();
        ~Cure();
    
        Cure & operator = (const Cure & rhs);
    private:

};
