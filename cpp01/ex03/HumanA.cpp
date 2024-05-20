/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:35:31 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/20 15:45:03 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

void HumanA::attack() const
{
    std::cout << _name << " attacks with their " << _weapon.getType();
    std::cout << std::endl;
}

HumanA::HumanA(const std::string name, Weapon& weapon):  _weapon(weapon), _name(name)
{
    
}

HumanA::~HumanA()
{
    std::cout << _name << " is destroy" << std::endl;
}