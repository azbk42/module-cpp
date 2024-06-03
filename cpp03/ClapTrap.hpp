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

#include <iostream>

class ClapTrap
{

    public:

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        

        const std::string getName() const;
        ClapTrap::ClapTrap(const std::string Name,unsigned int Health, unsigned int Energy, unsigned int Dammage);    
        ClapTrap(const ClapTrap & rhs);
        ~ClapTrap();

        ClapTrap& operator=(const ClapTrap& rhs);

    private:

        const std::string _name;
        unsigned int _health;
        unsigned int _energy;
        unsigned int _dammage;

};