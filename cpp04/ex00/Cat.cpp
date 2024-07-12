#include "Cat.hpp"




// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void Cat::makeSound() const
{
    std::cout << "Miaouuuu..." << std::endl;
}

// ######################################################
// #                 GET - SET                          #
// ######################################################



// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

Cat & Cat::operator=(const Cat & rhs)
{
    if (this != &rhs){
        type = rhs.type;
    }
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

Cat::Cat(const Cat & rhs): Animal()
{
   type = rhs.type; 
}

Cat::Cat(): Animal()
{
    type = "Cat";
    std::cout << CYN << "Cat Default Constructor called" << RESET << std::endl;
}

Cat::~Cat()
{
    std::cout << RED << "Cat Destructor called" << RESET << std::endl;
}

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################