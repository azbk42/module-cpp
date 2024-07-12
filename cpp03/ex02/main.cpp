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
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
    FragTrap robot("Wall-E");

    std::cout << std::endl;
    robot.highFivesGuys();
    
    std::cout << std::endl;
    std::cout << "PV: " << robot.getHitPoints()
            << "\nEnergy: " << robot.getEnergyPoints()
            << "\nAttack: " << robot.getAttackDammage() << std::endl;
    std::cout << std::endl;
    
    return (0);
}
