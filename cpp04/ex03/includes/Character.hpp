#pragma once
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
    public:

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

        Character(const Character & rhs);
        Character(const std::string name);
        ~Character();
    
        Character & operator = (const Character & rhs);
    private:

        AMateria* _item[4];
        AMateria* _drop[100];
        const std::string _name;
        size_t _nbItem;
        size_t _nbUnEquip;

};
