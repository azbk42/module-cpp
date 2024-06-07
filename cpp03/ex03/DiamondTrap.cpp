/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:10:39 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/07 19:48:19 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// ######################################################
// #                 PUBLIC METHOD MEMBER             #
// ######################################################

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
} 

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

DiamondTrap & DiamondTrap::operator = (const DiamondTrap & rhs)
{
    if (this != &rhs){
        _name = rhs._name;
        _energyPoints = rhs._energyPoints;
        _hitPoints = rhs._hitPoints;
        _attackDammage = rhs._attackDammage;
    }
    return (*this);
}
// ######################################################
// #                     CONSTRUCTOR                    #
// ######################################################

DiamondTrap::DiamondTrap(const DiamondTrap & rhs): 
        ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs), _name(rhs._name)
{
    
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap()
{
    _name = "random";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDammage = 30;

    std::cout << YELLOW << "DiamondTrap default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), 
                    ScavTrap(name + "_scav_name"), FragTrap(name + "_frag_name") 
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDammage = 30;
    
    std::cout << YELLOW << "DiamondTrap constructor called" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << RED << "Destructor from DiamondTrap called" << RESET << std::endl;
}
        

