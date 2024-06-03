/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:08:33 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 18:34:47 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// ######################################################
// #                 PUBLIC FUNCTION MEMBER             #
// ######################################################

void ClapTrap::attack(const std::string& target)
{
    std::cout << _name << "attacks" << target.get
}

void ClapTrap::takeDamage(unsigned int amount)
{
    
}

void ClapTrap::beRepaired(unsigned int amount)
{
    
}
        
// ######################################################
// #                    GET SET                         #
// ######################################################


const std::string ClapTrap::getName() const
{
    return (_name);
}

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    return (*this);
}

// ######################################################
// #                 CONSTRUCTOR                        #
// ######################################################

ClapTrap::ClapTrap(const ClapTrap& rhs): _name(rhs._name), _health(rhs._health), 
        _energy(rhs._energy), _dammage(rhs._dammage)
{
    std::cout << "Copie constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string Name,unsigned int Health, unsigned int Energy, unsigned int Dammage):
    _name(Name), _health(Health), _energy(Energy), _dammage(Dammage)
{
    std::cout << "Constructor called" << std::endl;
}
ClapTrap::~ClapTrap() 
{
    std::cout << "Destructor called" << std::endl;
}