/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:25:06 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/19 14:37:40 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{

}
Zombie::Zombie(std::string name) : _name(name)
{

}

Zombie::~Zombie(void)
{
    std::cout << "Zombie: " << _name << " is definitely delete" << std::endl;
}