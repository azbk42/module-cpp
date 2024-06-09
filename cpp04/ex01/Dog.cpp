/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:39:42 by marvin            #+#    #+#             */
/*   Updated: 2024/06/08 09:39:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"


// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void Dog::makeSound() const
{
    std::cout << "Waouf! Waouf!" << std::endl;
}

void Dog::setBrainIdea(size_t index, const std::string& sentence)
{
        brain->setIdeas(index, sentence);
}

std::string Dog::getBrainIdea(size_t index) const
{
    return (brain->ideas[index]);
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
        Brain* newBrain = new Brain(*rhs.brain);
        delete brain;
        brain = newBrain;
    }
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

Dog::Dog(const Dog & rhs): Animal(), brain(new Brain(*rhs.brain))
{
   type = rhs.type;

   std::cout << CYN << "Dog Copy Constructor called" << RESET << std::endl;
}

Dog::Dog(): Animal()
{
    type = "Dog";
    brain = new Brain();
    std::cout << CYN << "Dog Default Constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << RED << "Dog Destructor called" << RESET << std::endl;
}

// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################