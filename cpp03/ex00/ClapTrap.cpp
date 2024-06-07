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
    if (_checkStatus()){
        std::cout << "ClapTrap " << _name << " attacks " << target
                    << ", causing " <<  _attackDammage << " points of damage!" 
                    << std::endl;
        _energyPoints -= 1;  
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0){
        std::cout << "ClapTrap " << _name << " is already dead !" << std::endl;
    }
    else{
            std::cout << "ClapTrap " << _name << " take " << amount << " points of damage" << std::endl;
            if (_hitPoints < amount){
                _hitPoints = 0;
                std::cout << "ClapTrap " << _name << " has " << _hitPoints << " PV, so he is dead!" << std::endl;
            }
            else{
                std::cout << "ClapTrap " << _name << " had " << _hitPoints << " Pv, now he has: ";
                _hitPoints = _hitPoints - amount;
                std::cout << _hitPoints << " pv" << std::endl;
            }
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(_energyPoints == 0){
        std::cout << "ClapTrap " << _name << " is exhausted, he can't repair itself!" << std::endl;
    }
    else if (_hitPoints == 0){
        std::cout << "ClapTrap " << _name << " is already dead and can't repair itself!" << std::endl;
    }
    else{
        std::cout << "ClapTrap " << _name << " repair itself for " << amount << " pv!" << std::endl;
        _hitPoints += amount;
        std::cout << "He has now: " << _hitPoints << " pv!" << std::endl;
    }
}
        
// ######################################################
// #                    GET SET                         #
// ######################################################

// ######################################################
// #                 OVERLOARD OPERATOR                 #
// ######################################################

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
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

ClapTrap::ClapTrap():_name("randomclap"), _hitPoints(10), _energyPoints(10), _attackDammage(0)
{
    std::cout << BLUE << "ClapTrap Default Constructor called for: " << _name << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs): _name(rhs._name), _hitPoints(rhs._hitPoints), 
        _energyPoints(rhs._energyPoints), _attackDammage(rhs._attackDammage)
{
    std::cout << "Copy constructor called for: " << _name << std::endl;
}
ClapTrap::ClapTrap(const std::string Name): 
    _name(Name), _hitPoints(10), _energyPoints(10), _attackDammage(0)
{
    std::cout << BLUE << "Constructor called for: " << _name << RESET << std::endl;
}
ClapTrap::~ClapTrap() 
{
    std::cout << RED << "Destructor called for: " << _name << RESET << std::endl;
}

// ######################################################
// #                 PRIVATE FUNCTION MEMBER            #
// ######################################################

bool ClapTrap::_checkStatus(void)
{
    if (_hitPoints == 0){
        std::cout << "ClapTrap " << _name << " is dead, he can't attack!" << std::endl;
        return (false);
    }
    else if(_energyPoints == 0){
        std::cout << "ClapTrap " << _name << " is exhausted, he can't attack!" << std::endl;
        return (false); 
    }
    return (true);
}
