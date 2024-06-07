

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:08:16 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 18:26:41 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void ScavTrap::guardGate(void)
{
    if (_hitPoints > 0){
        std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
    }
    else{
        std::cout << "ScavTrap " << _name << " is dead so he cant be like Hodor..." << std::endl;
    }
}

void ScavTrap::attack(const std::string& target)
{
    if (_checkStatus()){
        std::cout << "Scavtrap " << _name << " attacks " << target
                    << ", causing " <<  _attackDammage << " points of damage!" 
                    << std::endl;
        _energyPoints -= 1;  
    }
}

// ######################################################
// #                 OVERLOAD OPERATOR                  #
// ######################################################

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
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
// #                 CONSTRUCTOR                        #
// ######################################################

ScavTrap::ScavTrap(): ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDammage = 20;
    std::cout << CYN << "ScavTrap default constructor has been called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & rhs): ClapTrap(rhs.getName())
{
    _hitPoints = rhs.getHitPoints();
    _energyPoints = rhs.getEnergyPoints();
    _attackDammage = rhs.getAttackDammage();
    std::cout << CYN << "ScavTrap constructor copy called "<< RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDammage = 20;
    std::cout << CYN << "ScavTrap constructor has been called "<< RESET << std::endl;
}
        
ScavTrap::~ScavTrap()
{
    std::cout << RED << "ScavTrap destructor called" << RESET << std::endl;
}