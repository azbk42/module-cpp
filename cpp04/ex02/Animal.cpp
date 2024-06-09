/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
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

// ######################################################
// #                 GET - SET                          #
// ######################################################

std::string AAnimal::getType() const
{
    return (type);
}

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

AAnimal & AAnimal::operator=(const AAnimal & rhs)
{
    if (this != &rhs){
        type = rhs.type;
        std::cout << "AAnimal Operator = called" << std::endl;
    }
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

AAnimal::AAnimal(const AAnimal & rhs): type(rhs.type)
{

    std::cout << GREEN << "AAnimal Copy Constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(): type("Default")
{
    std::cout << GREEN << "AAnimal Default Constructor called" << RESET << std::endl;
}

AAnimal::~AAnimal()
{
    
    std::cout << RED << "AAnimal Destructor called" << RESET << std::endl;
}

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################