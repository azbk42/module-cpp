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

#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{

    public:

        void guardGate(void);
        void attack(const std::string& target);

        ScavTrap(const ScavTrap & rhs);
        ScavTrap(const std::string name);
        ScavTrap();
        ~ScavTrap();

        ScavTrap & operator = (const ScavTrap & rhs);

    private:
        
};