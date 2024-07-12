#include "Cure.hpp"

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

AMateria* Cure::clone() const
{
    AMateria* newClass = new Cure(*this);

    return newClass;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heal " << target.getName() << "'s wounds *" << std::endl;
}

// ######################################################
// #                 GET - SET                          #
// ######################################################


// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

Cure & Cure::operator=(const Cure & rhs)
{  
    if (this != &rhs) {
        AMateria::operator=(rhs);
    }
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

Cure::Cure(const Cure & rhs): AMateria(rhs)
{
    std::cout << CYN << "Cure Copy Constructor called" << RESET << std::endl;
}

Cure::Cure(): AMateria("cure")
{
    std::cout << CYN << "Cure Default Constructor called" << RESET << std::endl;
}

Cure::~Cure()
{
    std::cout << RED << "Cure Destructor called" << RESET << std::endl;
}

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################