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

int main(void)
{
    std::cout << GREEN << "Init ScavTrap Walle" << RESET << std::endl;
    ScavTrap Walle("Wall-E");
    std::cout << GREEN << "\nInit Claptrap Eve" << RESET << std::endl;
    ClapTrap Eve("Eve");
    
    std::cout << GREEN << "Display PV HEALTH ENERGY ATTACK:" << RESET << std::endl;
    std::cout << Walle.getName() << ":" << std::endl;
    std::cout << "Health: " << Walle.getHitPoints() << std::endl;
    std::cout << "Energy: " << Walle.getEnergyPoints() << std::endl;
    std::cout << "Attack: " << Walle.getAttackDammage() << "\n" << std::endl;
    std::cout << Eve.getName() << ":" << std::endl;
    std::cout << "Health: " << Eve.getHitPoints() << std::endl;
    std::cout << "Energy: " << Eve.getEnergyPoints() << std::endl;
    std::cout << "Attack: " << Eve.getAttackDammage() << std::endl;

    std::cout << GREEN << "\nWalle-E repair for 2 pv and attack an unknow:" << RESET << std::endl;
    Walle.beRepaired(2);
    Walle.attack("Unknow");

    std::cout << GREEN << "\nWalle-E Hodor:" << RESET << std::endl;
    Walle.guardGate();

    std::cout << GREEN << "\nWall-E gets Hit for 80 and a second time for 70 pts:" << RESET << std::endl;
    Walle.takeDamage(80);
    Walle.takeDamage(70);

    std::cout << GREEN << "\nWall-E try to heal himself but...." << RESET << std::endl;
    Walle.beRepaired(10);

    std::cout << GREEN << "\nA new guy comes and try to copy Wall-E and this happend:" << RESET << std::endl;
    ScavTrap Teddy = Walle;
    std::cout << Teddy.getName() << ":" << std::endl;
    std::cout << "Health: " << Teddy.getHitPoints() << std::endl;
    std::cout << "Energy: " << Teddy.getEnergyPoints() << std::endl;
    std::cout << "Attack: " << Teddy.getAttackDammage() << "\n" << std::endl;
    
    return (0);
}