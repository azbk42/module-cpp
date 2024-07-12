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
#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap test("Wall-E");
    
    std::cout << "\nMethod:" << std::endl;
    std::cout << GREEN << "HIGH FIVE:" << RESET << std::endl;
    test.highFivesGuys();

    std::cout << GREEN << "Attack:" << RESET <<  std::endl;
    test.attack("YO");

    std::cout << GREEN << "Guard:" << RESET <<  std::endl;
    test.guardGate();

    std::cout << GREEN << "\nWho am i:" << RESET <<  std::endl;
    test.whoAmI();

    std::cout << "\nDestructor:" << std::endl; 
    return (0);
}
