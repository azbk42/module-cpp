#include "Dog.hpp"

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void Dog::makeSound() const
{
    std::cout << "Waouf! Waouf!" << std::endl;
}


// ######################################################
// #                 GET - SET                          #
// ######################################################



// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

Dog & Dog::operator=(const Dog & rhs)
{
    if (this != &rhs){
        type = rhs.type;
    }
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

Dog::Dog(const Dog & rhs): Animal()
{
   type = rhs.type; 
}

Dog::Dog(): Animal()
{
    type = "Dog";
    std::cout << CYN << "Dog Default Constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
    std::cout << RED << "Dog Destructor called" << RESET << std::endl;
}

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################