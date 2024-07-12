#include "Ice.hpp"

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

AMateria* Ice::clone() const
{
    AMateria* newClass = new Ice(*this);

    return newClass;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

// ######################################################
// #                 GET - SET                          #
// ######################################################


// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

Ice & Ice::operator=(const Ice & rhs)
{  
    if (this != &rhs) {
        AMateria::operator=(rhs);
    }
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

Ice::Ice(const Ice & rhs): AMateria(rhs)
{
    std::cout << BLUE << "Ice Copy Constructor called" << RESET << std::endl;
}

Ice::Ice(): AMateria("ice")
{
    std::cout << BLUE << "Ice Default Constructor called" << RESET << std::endl;
}

Ice::~Ice()
{
    std::cout << RED << "Ice Destructor called" << RESET << std::endl;
}

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################