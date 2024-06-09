

#pragma once
#include <iostream>

class ANteria
{
    protected:

        const std::string type;

    public:

        AMateria(std::string const & type);


        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;


        virtual void use(ICharacter& target);
}
