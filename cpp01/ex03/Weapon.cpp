/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:48:02 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/24 14:03:36 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

const std::string& Weapon::getType(void) const
{
    return (_type);
}

void Weapon::setType(std::string str)
{
    _type = str;
}

Weapon::Weapon(std::string type) : _type(type)
{
    
}

Weapon::~Weapon()
{
    
}