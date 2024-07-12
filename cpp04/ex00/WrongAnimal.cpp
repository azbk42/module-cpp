#include "WrongAnimal.hpp"

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void WrongAnimal::makeSound(void) const
{
    std::cout << "Wrooooooong!" << std::endl;
}

// ######################################################
// #                 GET - SET                          #
// ######################################################

std::string WrongAnimal::getType() const
{
    return (type);
}

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & rhs)
{
    if (this != &rhs){
        type = rhs.type;
    }
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

WrongAnimal::WrongAnimal(const WrongAnimal & rhs): type(rhs.type)
{
    std::cout << GREEN << "WrongAnimal Copy Constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(): type("Default")
{
    std::cout << GREEN << "WrongAnimal Default Constructor called" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << RED << "WrongAnimal Destructor called" << RESET << std::endl;
}

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################