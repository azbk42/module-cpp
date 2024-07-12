#pragma once
#include <iostream>
#include "ICharacter.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define CYN     "\033[36m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"

class AMateria
{
    protected:
        const std::string type;

    public:
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

        AMateria(const AMateria & rhs);
        AMateria(std::string const & type);
        virtual ~AMateria();
        
        AMateria & operator=(const AMateria & rhs);
};
