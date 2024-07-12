/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:36:21 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/09 15:40:18 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


// ######################################################
// #                 PUBLIC METHOD                      #
// ######################################################

void Brain::setIdeas(size_t index, const std::string sentence)
{
    ideas[index] = sentence;
}

// ######################################################
// #                 GET - SET                          #
// ######################################################


// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

Brain & Brain::operator = (const Brain & rhs)
{
    if (this != &rhs){
        for (int i = 0; i < 100; i++){
            this->ideas[i] = rhs.ideas[i];
        }
    }
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

Brain::Brain(const Brain & rhs)
{
    for (int i = 0; i < 100; i++){
    this->ideas[i] = rhs.ideas[i]; 
    }
    std::cout << PINK << "Brain Copy constructor called" << RESET << std::endl;
}
Brain::Brain()
{
    for (int i = 0; i < 100; i++){
        ideas[i] = "Default";
    }
    std::cout << PINK << "Brain Default constructor called" << RESET << std::endl;
}
Brain::~Brain()
{
    std::cout << RED << "Brain Destructor called" << RESET << std::endl;
}



// ######################################################
// #                 PRIVATE METHOD                     #
// ######################################################