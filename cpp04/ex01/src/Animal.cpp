/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:36:57 by marvin            #+#    #+#             */
/*   Updated: 2024/06/08 09:36:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void Animal::makeSound(void) const
{
    std::cout << "Grrrrrrr!" << std::endl;
}

// ######################################################
// #                 GET - SET                          #
// ######################################################

std::string Animal::getType() const
{
    return (type);
}

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

Animal & Animal::operator=(const Animal & rhs)
{
    if (this != &rhs){
        type = rhs.type;
        std::cout << "Animal Operator = called" << std::endl;
    }
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

Animal::Animal(const Animal & rhs): type(rhs.type)
{

    std::cout << GREEN << "Animal Copy Constructor called" << RESET << std::endl;
}

Animal::Animal(): type("Default")
{
    std::cout << GREEN << "Animal Default Constructor called" << RESET << std::endl;
}

Animal::~Animal()
{
    
    std::cout << RED << "Animal Destructor called" << RESET << std::endl;
}

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################