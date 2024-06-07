/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:08:35 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/03 18:30:25 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define CYN     "\e[0;36m"
#define ORANGE  "\033[38;5;214m"
#define YELLOW  "\033[33m"
#define PINK    "\033[38;5;213m"

class ClapTrap
{

    public:

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName(void) const;
        unsigned int getHitPoints(void) const;
        unsigned int getEnergyPoints(void) const;
        unsigned int getAttackDammage(void) const;
        
        ClapTrap(const std::string Name);    
        ClapTrap(const ClapTrap & rhs);
        ClapTrap();
        ~ClapTrap();

        ClapTrap& operator=(const ClapTrap& rhs);

    protected:

        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDammage;
        bool _checkStatus(void);
    
    private:
        
};