#include "AMateria.hpp"
#include "ICharacter.hpp"

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void AMateria::use(ICharacter& target) {
    
    std::cout << "* uses " << type << " on " << target.getName() << " *" << std::endl;
}

// ######################################################
// #                 GET - SET                          #
// ######################################################

std::string const & AMateria::getType() const
{
    return (type);
}

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

AMateria & AMateria::operator=(const AMateria & rhs)
{
    (void)rhs;
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

AMateria::AMateria(const AMateria & rhs): type(rhs.type)
{
    std::cout << GREEN << "AMateria Copy Constructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const & type): type(type)
{
    std::cout << GREEN << "AMateria Constructor called" << RESET << std::endl;
}

AMateria::~AMateria()
{
    std::cout << RED << "AMateria Destructor called" << RESET << std::endl;
}

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################