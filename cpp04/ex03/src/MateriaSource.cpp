#include "MateriaSource.hpp"
#include "AMateria.hpp"

// ######################################################
// #                 PUBLIC METHOD                      #
// 
void MateriaSource::learnMateria(AMateria* m)
{
    if (_nbItem >= 4){
        std::cout << "Inventory is full!" << std::endl;
    }
    else{
        for (int i = 0; i < 4; i++){
            if (_item[i] == NULL){
                _item[i] = m;
                _nbItem += 1;
                std::cout << "Spell: " << m->getType() << " add at emplacement: [" << i << "]" << std::endl;
                break;
            }
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    if (_nbItem > 0){
        for (int i = 0; i < 4; i++){
            std::cout << _item[i]->getType() << std::endl;
            if (_item[i]->getType() == type){
                return (_item[i]->clone());
            }
        }
    }
    else{
        std::cout << "No spell in the bank sorry." << std::endl;
    }
    return (NULL);
}

// ######################################################
// #                 GET - SET                          #
// ######################################################


// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

MateriaSource & MateriaSource::operator = (const MateriaSource & rhs)
{
     if (this != &rhs){
        for (int i = 0; i < 4; ++i){
            if (_item[i] != NULL){
                delete _item[i];
                _item[i] = NULL;
            }
        }
        for (int i = 0; i < 4; ++i){
            if (rhs._item[i] != NULL){
                _item[i] = rhs._item[i]->clone();
            }
            else{
                _item[i] = NULL;
            }
        }
        _nbItem = rhs._nbItem;
    }
    return (*this);
}


// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

MateriaSource::MateriaSource(const MateriaSource & rhs)
{
    *this = rhs;
    std::cout << YELLOW << "Constructor Copy MateriaSource called" << RESET << std::endl;
}

MateriaSource::MateriaSource(): _nbItem(0)
{
    for (int i = 0; i < 4; i++){
        _item[i] = NULL;
    }
    std::cout << YELLOW << "Constructor MateriaSource called" << RESET << std::endl;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++){
        delete _item[i];
    }
    std::cout << YELLOW << "Destructor MateriaSource called" << RESET << std::endl;
}
    

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################