#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void Character::equip(AMateria* m)
{
    if (m == NULL){
        std::cout << "Can't equipe this spell !" << std::endl;
    }
    else if (m != NULL && _nbItem != 4){
        for (int i = 0; i < 4; i++){
            if (_item[i] == NULL){
                _item[i] = m;
                _nbItem += 1;
                std::cout << "Equip a spell, emplacement: [" << i << "]" << std::endl;
                break;
            }
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 4 && _item[idx] != NULL){
        _drop[_nbUnEquip] = _item[idx];
        _item[idx] = NULL;
        _nbItem -= 1;
        _nbUnEquip += 1;
    }
    else{
        std::cout << "Nothing to unequip!" << std::endl;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _item[idx] != NULL) {
        _item[idx]->use(target);
    } else {
        std::cout << "No Materia at this emplacement." << std::endl;
    }
}

// ######################################################
// #                 GET - SET                          #
// ######################################################

std::string const & Character::getName() const
{
    return (_name);
}

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

Character& Character::operator=(const Character& rhs) 
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
    _nbUnEquip = 0;
    for (int i = 0; i < 100; i++){
        _drop[i] = NULL;
    }
    return (*this);

}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

Character::Character(const Character& rhs)
{
    *this = rhs;
    std::cout << MAGENTA << "Character Copy Constructor called" << RESET << std::endl;
}

Character::Character(const std::string name): _name(name), _nbItem(0), _nbUnEquip(0)
{
    for (int i = 0; i < 100; i++){
        _drop[i] = NULL;
    }
    for (int i = 0; i < 4; i++){
        _item[i] = NULL;
    }
    std::cout << MAGENTA << "Character Default Constructor called" << RESET << std::endl;
}

Character::~Character()
{
    for (int i = 0; i < 100; i++){
        delete _drop[i];
    }
    for (int i = 0; i < 4; i++){
       delete _item[i];
    }
    std::cout << RED << "Character Destructor called" << RESET << std::endl;
}

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################