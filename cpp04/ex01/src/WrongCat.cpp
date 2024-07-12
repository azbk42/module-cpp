/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrongcat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:11:01 by marvin            #+#    #+#             */
/*   Updated: 2024/06/08 19:11:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void WrongCat::makeSound() const
{
    std::cout << "Wrong! Miaou!" << std::endl;
}


// ######################################################
// #                 GET - SET                          #
// ######################################################



// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

WrongCat & WrongCat::operator=(const WrongCat & rhs)
{
    if (this != &rhs){
        type = rhs.type;
    }
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

WrongCat::WrongCat(const WrongCat & rhs): WrongAnimal()
{
   type = rhs.type; 
}

WrongCat::WrongCat(): WrongAnimal()
{
    type = "WrongCat";
    std::cout << CYN << "WrongCat Default Constructor called" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << RED << "WrongCat Destructor called" << RESET << std::endl;
}

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################