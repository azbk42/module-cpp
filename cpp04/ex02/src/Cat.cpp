/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:58:48 by marvin            #+#    #+#             */
/*   Updated: 2024/06/08 16:58:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        Brain* newBrain = new Brain(*rhs.brain);
        delete brain;
        brain = newBrain;
    }
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

Cat::Cat(const Cat & rhs): AAnimal(), brain(new Brain(*rhs.brain))
{
   type = rhs.type; 
   std::cout << CYN << "Cat Copy Constructor called" << RESET << std::endl;
}

Cat::Cat(): AAnimal()
{
    type = "Cat";
    this->brain = new Brain();
    std::cout << CYN << "Cat Default Constructor called" << RESET << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << RED << "Cat Destructor called" << RESET << std::endl;
}

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################