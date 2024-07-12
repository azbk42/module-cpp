/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:50:04 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/10 13:36:06 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// ######################################################
// #                 PUBLIC FUNCTION MEMBER             #
// ######################################################

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap : " << _name << " please high fives me ! " << std::endl;
}

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

FragTrap & FragTrap::operator=(const FragTrap & rhs)
{
    if (this != &rhs){
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDammage = rhs._attackDammage;
    }
    return (*this);
}

// ######################################################
// #                     CONSTRUCTOR                    #
// ######################################################

FragTrap::FragTrap(): ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDammage = 30;
    std::cout << PINK << "FragTrap Default Constructor has been called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap & rhs): ClapTrap(rhs.getName())
{
    _hitPoints = rhs.getHitPoints();
    _energyPoints = rhs.getEnergyPoints();
    _attackDammage = rhs.getAttackDammage();
    std::cout << PINK << "FragTrap copy Constructor has been called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDammage = 30;
    std::cout << PINK << "FragTrap Constructor has been called" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << RED << "FragTrap Destructor has been called" << RESET << std::endl;
}
