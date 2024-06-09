/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:10:41 by emauduit          #+#    #+#             */
/*   Updated: 2024/06/09 16:47:27 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    public:
        
        void whoAmI();
        
        DiamondTrap(const DiamondTrap & rhs);
        DiamondTrap(const std::string name);
        DiamondTrap();
        ~DiamondTrap();
        
        DiamondTrap & operator = (const DiamondTrap & rhs);
    private:

        std::string _name;
};
