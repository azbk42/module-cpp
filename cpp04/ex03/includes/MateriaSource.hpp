#pragma once
#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    public:

        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);

        MateriaSource(const MateriaSource & rhs);
        MateriaSource();
        ~MateriaSource();
    
        MateriaSource & operator = (const MateriaSource & rhs);
    private:

        AMateria* _item[4];
        size_t _nbItem;

};