/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:46:05 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/24 14:00:01 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

void HumanB::attack() const 
{
    if (_weapon) {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    } else {
        std::cout << _name << " has no weapon to attack with!" << std::endl;
    }
}

void HumanB::setWeapon(Weapon& weapon)
{
    _weapon = &weapon; 
}

HumanB::HumanB(std::string name):  _weapon(NULL), _name(name)
{
    
}

HumanB::~HumanB()
{
    std::cout << _name << " is destroy" << std::endl;
}